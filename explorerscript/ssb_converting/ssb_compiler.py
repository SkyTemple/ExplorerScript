#  MIT License
#
#  Copyright (c) 2020-2025 Capypara and the SkyTemple Contributors
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
#
from __future__ import annotations

import logging
import os
from pathlib import PurePosixPath, PurePath

from explorerscript.error import SsbCompilerError
from explorerscript.explorerscript_reader import ExplorerScriptReader
from explorerscript.macro import ExplorerScriptMacro
from explorerscript.source_map import SourceMap
from explorerscript.ssb_converting.compiler.compiler_visitor.has_routines_visitor import HasRoutinesVisitor
from explorerscript.ssb_converting.compiler.compiler_visitor.import_visitor import ImportVisitor
from explorerscript.ssb_converting.compiler.compiler_visitor.macro_resolution_order import MacroResolutionOrderVisitor
from explorerscript.ssb_converting.compiler.compiler_visitor.macro_visitor import MacroVisitor
from explorerscript.ssb_converting.compiler.compiler_visitor.routine_visitor import RoutineVisitor
from explorerscript.ssb_converting.compiler.compiler_visitor.user_constants_visitor import UserConstantsVisitor
from explorerscript.ssb_converting.compiler.label_finalizer import LabelFinalizer
from explorerscript.ssb_converting.compiler.label_jump_to_remover import OpsLabelJumpToRemover
from explorerscript.ssb_converting.compiler.meta_attributes import parse_exps_meta_attributes, ExpsMetaAttributes
from explorerscript.ssb_converting.compiler.utils import (
    routine_op_offsets_are_ordered,
    strip_last_label,
    UserDefinedConstants,
)
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbRoutineInfo
from explorerscript.ssb_script.ssb_converting.ssb_compiler import SsbScriptSsbCompiler
from explorerscript.util import open_utf8, f, _

logger = logging.getLogger(__name__)


class ExplorerScriptSsbCompiler:
    """
    Base class for compiling ExplorerScript to SSB. This will return the components, that make
    a SSB model. To turn this into an actual binary SSB model, see
    skytemple_files.script.ssb.script_compiler.ScriptCompiler and
    skytemple_files.script.ssb.handler.SsbHandler.serialize.
    """

    # The information about routines stored in the ssb.
    # linked_to may be -1. In this case linked_to_name is set to the named target.
    routine_infos: list[SsbRoutineInfo] | None

    # Only contains simple SSBOperations, directly representing ops.
    # The operations have no IDs (-1), because the Decompiler has no concept of the game's internal ids.
    # OpCode offsets are calculated by list index [globally unique across all routines]!
    # The list contains no labels.
    # Since the language allows any operations and doesn't do any checks directly, the OpCode names
    # and constants used might be invalid.
    routine_ops: list[list[SsbOperation]] | None

    # If this script contains coroutines, the value at the index corresponding to self.routine_ops
    # will contain it's name as string.
    named_coroutines: list[str] | None

    # Source map for the compiled ssb routine ops.
    source_map: SourceMap | None

    # The raw file paths in the import headers of the compiled ExplorerScript file.
    imports: list[str]

    # The macros of by this script
    macros: dict[str, ExplorerScriptMacro]

    # The order of which the macros in this file have to be processed, due to dependencies
    macro_resolution_order: list[str]

    # The user constants defined by this script
    user_constants: UserDefinedConstants

    ####

    # The name of the variable PERFORMANCE_PROGRESS_LIST in the script source.
    performance_progress_list_var_name: str

    # A list of directories to search for imports. The paths are searched in order and the first match is taken.
    # Unlike the import statement paths, this is expected to be a set of platform specific paths (Windows or Unix
    # style depending on the current platform)
    lookup_paths: list[str]

    # A list of absolute paths of files that were already 'import'ed. If the compiler tries to import one of these
    # files again, an SsbCompilerError is raised.
    recursion_check: list[str]

    def __init__(
        self,
        performance_progress_list_var_name: str,
        lookup_paths: list[str] | None = None,
        recursion_check: list[str] | None = None,
        user_constants: UserDefinedConstants | None = None,
    ):
        if lookup_paths is None:
            lookup_paths = []
        if recursion_check is None:
            recursion_check = []
        self.routine_infos = None
        self.routine_ops = None
        self.named_coroutines = None
        self.source_map = None
        self.imports: list[str] = []
        self.macros: dict[str, ExplorerScriptMacro] = {}
        self.macro_resolution_order: list[str] = []
        self.user_constants = user_constants if user_constants is not None else UserDefinedConstants({}, {}, {})

        self.performance_progress_list_var_name: str = performance_progress_list_var_name
        self.lookup_paths = lookup_paths
        self.recursion_check = recursion_check

    def compile(
        self, explorerscript_src: str, file_name: str, macros_only: bool = False, original_base_file: str | None = None
    ) -> ExplorerScriptSsbCompiler:
        """
        After compiling, the components are present in this object's attributes.

        file_name is the full path to the file that is being compiled.
        original_base_file is the full path to the file that originally started an import chain. If not given, file_name
        is used.
        If macros_only is True, then an exception is raised, if the script files contains any routines.

        :raises: ParseError: On parsing errors
        :raises: SsbCompilerError: On logical compiling errors
        :raises: ValueError: On misc. unexpected compilation errors
        """
        logger.debug(
            "<%d> Compiling ExplorerScript (-> %s)... - Macros only:%d, base:%s",
            id(self),
            file_name,
            macros_only,
            original_base_file,
        )
        self.routine_infos = None
        self.routine_ops = None
        self.named_coroutines = None
        self.source_map = None
        self.imports = []
        self.macros = {}
        if original_base_file is None:
            original_base_file = file_name

        # Parse attributes
        attributes = parse_exps_meta_attributes(explorerscript_src)
        if ExpsMetaAttributes.IsSsbScript in attributes.keys():
            value = attributes[ExpsMetaAttributes.IsSsbScript]
            if value == "true" or value == "1":
                # Parse as SsbScript instead
                subcompiler = SsbScriptSsbCompiler()
                subcompiler.compile(explorerscript_src)
                self.routine_infos = subcompiler.routine_infos
                self.routine_ops = subcompiler.routine_ops
                self.named_coroutines = subcompiler.named_coroutines
                self.source_map = subcompiler.source_map
                return self

        reader = ExplorerScriptReader(explorerscript_src)
        parser = reader.read()

        # Collect imports
        logger.debug("<%d> Collecting imports...", id(self))
        self.imports = parser.traverse(ImportVisitor())

        # Resolve imports and load macros in the imported files
        for subfile_path in self._resolve_imported_file(os.path.dirname(file_name)):
            logger.debug("<%d> Compiling sub-file %s...", id(self), subfile_path)
            if subfile_path in self.recursion_check:
                raise SsbCompilerError(
                    f(
                        _(
                            "Infinite recursion detected while trying to load "
                            "an ExplorerScript file from {subfile_path}.\n"
                            "Tried loading from: {file_name}."
                        )
                    )
                )
            subfile_compiler = self.__class__(
                self.performance_progress_list_var_name,
                self.lookup_paths,
                recursion_check=self.recursion_check + [file_name],
                user_constants=self.user_constants,
            )
            with open_utf8(subfile_path, "r") as file:
                subfile_compiler.compile(
                    file.read(), subfile_path, macros_only=True, original_base_file=original_base_file
                )
            self.user_constants = subfile_compiler.user_constants
            self.macros.update(self._macros_add_filenames(subfile_compiler.macros, original_base_file, subfile_path))

        # Sort the list of macros by how they are used
        logger.debug("<%d> Building macro resolution order...", id(self))
        self.macro_resolution_order = parser.traverse(MacroResolutionOrderVisitor(self.macros))

        logger.debug("<%d> Collecting constants...", id(self))
        self.user_constants = parser.traverse(UserConstantsVisitor(self.user_constants))

        # Loads and compiles modules in base file
        # (we write our absolute path there only for now, if this is an inclusion, the outer compiler will update it).
        logger.debug("<%d> Compiling macros...", id(self))
        self.macros.update(
            self._macros_add_filenames(
                parser.traverse(
                    MacroVisitor(
                        self.performance_progress_list_var_name,
                        self.macros,
                        self.macro_resolution_order,
                        self.user_constants,
                    )
                ),
                None,
                file_name,
            )
        )

        # Check if macros_only
        if macros_only:
            # Check if the file contains any routines
            if parser.traverse(HasRoutinesVisitor()):
                # noinspection PyUnusedLocal
                fn = os.path.basename(file_name)  # noqa
                raise SsbCompilerError(f(_("{fn}: Macro scripts must not contain any routines.")))
            return self

        # Start Compiling
        try:
            try:
                logger.debug("<%d> Compiling routines...", id(self))
                compiler_visitor = RoutineVisitor(
                    self.performance_progress_list_var_name, self.macros, self.user_constants
                )
                parser.traverse(compiler_visitor)
            except Exception as ex:
                # due to the stack nature of the decompile visitor, we get many stack exceptions after raising
                # the first. Raise the last exception in the context chain.
                while ex.__context__ is not None:
                    ex = ex.__context__  # type: ignore
                raise ex
        except AssertionError as e:
            raise ValueError(str(e)) from e

        assert routine_op_offsets_are_ordered(compiler_visitor.routine_ops)

        # Copy from listener / remove labels and label jumps
        label_finalizer = LabelFinalizer(strip_last_label(compiler_visitor.routine_ops))

        self.routine_ops = OpsLabelJumpToRemover(label_finalizer.routines, label_finalizer.label_offsets).routines
        self.routine_infos = compiler_visitor.routine_infos
        self.named_coroutines = compiler_visitor.named_coroutines
        self.source_map = compiler_visitor.source_map_builder.build()

        # Done!
        return self

    def _resolve_imported_file(self, dir_name: str) -> list[str]:
        """
        Returns the full paths to all imports specified in self.imports.
        If any file can not be found, raises an SsbCompilerError.
        """
        fs: list[str] = []
        for import_file in self.imports:
            if import_file.startswith(".") or import_file.startswith("/"):
                # Relative or absolute import
                abs_path = os.path.realpath(str(PurePath(PurePosixPath(dir_name).joinpath(PurePosixPath(import_file)))))
                if not os.path.exists(abs_path):
                    raise SsbCompilerError(f(_("The file to import ('{import_file}') was not found.")))
            else:
                # Relative to one of the lookup paths
                abs_path = None
                path_parts = import_file.split("/")
                if "." in path_parts or ".." in path_parts:
                    raise SsbCompilerError(
                        f(
                            _(
                                "Invalid import: '{import_file}'. Non absolute/relative "
                                "imports must not contain relative paths."
                            )
                        )
                    )
                for lp in self.lookup_paths:
                    abs_path_c = os.path.realpath(
                        str(PurePath(dir_name).joinpath(PurePosixPath(lp).joinpath(import_file)))
                    )
                    if os.path.exists(abs_path_c):
                        abs_path = abs_path_c
                        break
                if abs_path is None:
                    raise SsbCompilerError(f(_("The file to import ('{import_file}') was not found.")))
            assert abs_path is not None
            fs.append(abs_path)

        return fs

    def _macros_add_filenames(
        self, macros: dict[str, ExplorerScriptMacro], basefile_path: str | None, subfile_path: str
    ) -> dict[str, ExplorerScriptMacro]:
        """Updates path information of all of the macros. See the field descriptions for more details"""
        for macro in macros.values():
            macro.included__absolute_path = subfile_path
            if basefile_path is not None:
                macro.included__relative_path = os.path.relpath(subfile_path, os.path.dirname(basefile_path))
        return macros
