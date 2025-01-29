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

from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractComplexBlockCompileHandler,
    AbstractStatementCompileHandler,
    AbstractComplexStatementCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.if_header import IfHeaderCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript_parser import ExplorerScriptParser, Antlr4ParserRuleContext


class ElseIfBlockCompileHandler(
    AbstractComplexBlockCompileHandler[
        ExplorerScriptParser.Elseif_blockContext,
        "AbstractStatementCompileHandler[Antlr4ParserRuleContext] | IfHeaderCompileHandler",
    ]
):
    """Handles an elseif block."""

    def __init__(self, ctx: ExplorerScriptParser.Elseif_blockContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._if_header_handlers: list[IfHeaderCompileHandler] = []

    def create_header_jump_templates(self) -> list[SsbLabelJumpBlueprint]:
        self._header_jump_blueprints = []
        is_positive = self.ctx.NOT() is None
        for h in self._if_header_handlers:
            h.set_positive(is_positive)
            self._header_jump_blueprints.append(h.collect())
        return self._header_jump_blueprints

    def collect(self) -> list[SsbOperation]:
        # create_header_jump_templates has to be called before!
        return self._process_block()

    def collect_header_handlers(self) -> list[IfHeaderCompileHandler]:
        return self._if_header_handlers

    def add(self, obj: AbstractStatementCompileHandler[Antlr4ParserRuleContext] | IfHeaderCompileHandler) -> None:
        if isinstance(obj, AbstractComplexStatementCompileHandler):
            # Sub statement for the block
            self._added_handlers.append(obj)
            return
        if isinstance(obj, IfHeaderCompileHandler):
            self._if_header_handlers.append(obj)
            return
        self._raise_add_error(obj)
