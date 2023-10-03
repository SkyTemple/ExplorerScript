#  MIT License
#
#  Copyright (c) 2020-2023 Capypara and the SkyTemple Contributors
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
import logging
from typing import List, Optional

from antlr4 import InputStream, CommonTokenStream

from explorerscript.error import ParseError
from explorerscript.source_map import SourceMap
from explorerscript.ssb_converting.compiler.label_jump_to_remover import OpsLabelJumpToRemover
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbRoutineInfo
from explorerscript.antlr.SsbScriptLexer import SsbScriptLexer
from explorerscript.antlr.SsbScriptParser import SsbScriptParser
from explorerscript.ssb_script.ssb_converting.compiler.compiler_listener import SsbScriptCompilerListener
from explorerscript.syntax_error_listener import SyntaxErrorListener
logger = logging.getLogger(__name__)


class SsbScriptSsbCompiler:
    """
    Base class for compiling SSBScript to SSB. This will return the components, that make
    a SSB model. To turn this into an actual binary SSB model, see
    skytemple_files.script.ssb.script_compiler.ScriptCompiler and
    skytemple_files.script.ssb.handler.SsbHandler.serialize.
    """
    def __init__(self):
        # The information about routines stored in the ssb.
        # linked_to may be -1. In this case linked_to_name is set to the named target.
        self.routine_infos: Optional[list[SsbRoutineInfo]] = None

        # Only contains simple SSBOperations, directly representing ops.
        # The operations have no IDs (-1), because the Decompiler has no concept of the game's internal ids.
        # OpCode offsets are calculated by list index [globally unique across all routines]!
        # The list contains no labels.
        # Since the language allows any operations and doesn't do any checks directly, the OpCode names
        # and constants used might be invalid.
        self.routine_ops: Optional[list[list[SsbOperation]]] = None

        # If this script contains coroutines, the value at the index corresponding to self.routine_ops
        # will contain it's name as string.
        self.named_coroutines: Optional[list[str]] = None

        # Source map for the compiled ssb routine ops.
        self.source_map: Optional[SourceMap] = None

    def compile(self, ssb_script_src: str):
        """
        After compiling, the components are present in this object's attributes.

        :raises: ParseError: On parsing errors
        """
        logger.debug("Compiling SSBScript...")
        self.routine_infos = None
        self.routine_ops = None
        self.named_coroutines = None

        input_stream = InputStream(ssb_script_src)
        lexer = SsbScriptLexer(input_stream)
        stream = CommonTokenStream(lexer)
        parser = SsbScriptParser(stream)
        error_listener = SyntaxErrorListener()
        parser.addErrorListener(error_listener)
        compiler_listener = SsbScriptCompilerListener()
        parser.addParseListener(compiler_listener)

        # Start Parsing
        parser.start()

        # Look for errors
        if len(error_listener.syntax_errors) > 0:
            # We only return the first error, the rest is probably not relevant, since
            # the first screws everything over.
            raise ParseError(error_listener.syntax_errors[0])

        # Copy from listener / remove labels and label jumps
        self.routine_ops = OpsLabelJumpToRemover(compiler_listener.routine_ops, compiler_listener.label_offsets).routines
        self.routine_infos = compiler_listener.routine_infos
        self.named_coroutines = compiler_listener.named_coroutines
        self.source_map = compiler_listener.source_map_builder.build()

        # Done!
