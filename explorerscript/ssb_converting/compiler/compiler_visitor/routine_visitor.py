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

from typing import cast

from explorerscript.macro import ExplorerScriptMacro
from explorerscript.source_map import SourceMapBuilder
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AnyCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.primitive import PrimitiveCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.coro_def import CoroDefCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.for_target_def import ForTargetDefCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.simple_def import SimpleDefCompileHandler
from explorerscript.ssb_converting.compiler.compiler_visitor.statement_visitor import StatementVisitor
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, Counter, UserDefinedConstants
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbOperation
from explorerscript_parser import ExplorerScriptParser, ExplorerScriptBaseVisitor


class RoutineVisitor(ExplorerScriptBaseVisitor):
    """Builds the SSB data structures while visiting the parsing tree."""

    # The information about routines stored in the ssb.
    routine_infos: list[SsbRoutineInfo]
    routine_ops: list[list[SsbOperation]]
    named_coroutines: list[str]
    # Source map
    source_map_builder: SourceMapBuilder

    # Global compilation context for the handlers
    compiler_ctx: CompilerCtx

    _active_routine_id: int
    _root_handler: (
        ForTargetDefCompileHandler | CoroDefCompileHandler | SimpleDefCompileHandler | PrimitiveCompileHandler | None
    )

    def __init__(
        self,
        performance_progress_list_var_name: str,
        macros: dict[str, ExplorerScriptMacro],
        user_constants: UserDefinedConstants,
    ):
        self.routine_infos = []
        self.routine_ops = []
        self.named_coroutines = []
        self.source_map_builder: SourceMapBuilder = SourceMapBuilder()

        self.compiler_ctx = CompilerCtx(
            Counter(),
            self.source_map_builder,
            {},
            Counter(),
            performance_progress_list_var_name,
            macros,
            user_constants,
        )

        self._active_routine_id = -1
        self._root_handler = None
        super().__init__()

    def visitImport_stmt(self, ctx: ExplorerScriptParser.Import_stmtContext) -> None:
        # Are not visited.
        return

    def visitMacrodef(self, ctx: ExplorerScriptParser.MacrodefContext) -> None:
        # Are not visited.
        return

    def visitConstant_assign(self, ctx: ExplorerScriptParser.Constant_assignContext) -> None:
        # Are not visited.
        return None

    def visitSimple_def(self, ctx: ExplorerScriptParser.Simple_defContext) -> None:
        self._root_handler = SimpleDefCompileHandler(ctx, self.compiler_ctx)
        self._active_routine_id = self._root_handler.get_new_routine_id(self._active_routine_id)
        self._enlarge_routine_info()

        self.visitChildren(ctx)
        self.routine_infos[self._active_routine_id], self.routine_ops[self._active_routine_id] = (
            self._root_handler.collect()
        )

    def visitCoro_def(self, ctx: ExplorerScriptParser.Coro_defContext) -> None:
        self._root_handler = CoroDefCompileHandler(ctx, self.compiler_ctx)
        self._active_routine_id = self._root_handler.get_new_routine_id(self._active_routine_id)
        self._enlarge_routine_info()

        self.visitChildren(ctx)
        (
            self.named_coroutines[self._active_routine_id],
            self.routine_infos[self._active_routine_id],
            self.routine_ops[self._active_routine_id],
        ) = self._root_handler.collect()

    def visitFor_target_def(self, ctx: ExplorerScriptParser.For_target_defContext) -> None:
        self._root_handler = ForTargetDefCompileHandler(ctx, self.compiler_ctx)
        self._active_routine_id = self._root_handler.get_new_routine_id(self._active_routine_id)
        self._enlarge_routine_info()

        self.visitChildren(ctx)
        self.routine_infos[self._active_routine_id], self.routine_ops[self._active_routine_id] = (
            self._root_handler.collect()
        )

    def visitFunc_alias(self, ctx: ExplorerScriptParser.Func_aliasContext) -> list[SsbOperation]:
        return []

    def visitFunc_suite(self, ctx: ExplorerScriptParser.Func_suiteContext) -> None:
        assert self._root_handler is not None
        for stmt_ctx in ctx.stmt():
            StatementVisitor(cast(AnyCompileHandler, self._root_handler), self.compiler_ctx).visit(stmt_ctx)

    def visitPrimitive(self, ctx: ExplorerScriptParser.PrimitiveContext) -> None:
        assert isinstance(self._root_handler, ForTargetDefCompileHandler)
        self._root_handler.add(PrimitiveCompileHandler(ctx, self.compiler_ctx))

    def _enlarge_routine_info(self) -> None:
        if len(self.routine_infos) - 1 < self._active_routine_id:
            needed = self._active_routine_id - len(self.routine_infos) + 1
            for i in range(0, needed):
                self.routine_infos.append(None)  # type: ignore
                self.routine_ops.append([])
                self.named_coroutines.append([])  # type: ignore
