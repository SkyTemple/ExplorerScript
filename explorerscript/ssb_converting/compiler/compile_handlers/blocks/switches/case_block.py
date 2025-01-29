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

from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractComplexBlockCompileHandler,
    AbstractComplexStatementCompileHandler,
    AbstractStatementCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.primitive import PrimitiveCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_header import CaseHeaderCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, OP_JUMP, SsbLabelJump
from explorerscript.util import _
from explorerscript_parser import ExplorerScriptParser, Antlr4ParserRuleContext


class CaseBlockCompileHandler(
    AbstractComplexBlockCompileHandler[
        ExplorerScriptParser.Single_case_blockContext,
        "AbstractStatementCompileHandler[Antlr4ParserRuleContext] | CaseHeaderCompileHandler | PrimitiveCompileHandler",
    ]
):
    """Handles a switch case block for a switch."""

    def __init__(self, ctx: ExplorerScriptParser.Single_case_blockContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._case_header_handler: CaseHeaderCompileHandler | None = None
        self._added_string_handler: PrimitiveCompileHandler | None = None
        self.is_message_case = False
        # The end of the switch
        self._end_label: SsbLabel | None = None

    def set_end_label(self, end_label: SsbLabel) -> None:
        self._end_label = end_label

    def get_header_jump_template(self) -> SsbLabelJumpBlueprint:
        assert self._case_header_handler is not None
        if len(self._header_jump_blueprints) == 0:
            self._header_jump_blueprints = [self._case_header_handler.collect()]
        return self._header_jump_blueprints[0]

    def collect(self) -> list[SsbOperation]:
        if self.is_message_case:
            raise SsbCompilerError(_("Invalid message switch case call."))
        # get_header_jump_template must be called first.
        with self.compiler_ctx.in_switch_case(self):
            retval = self._process_block(False)
        return retval

    def break_case(self) -> SsbLabelJump:
        return self._generate_jump_operation(OP_JUMP, [], self._end_label)

    def has_sub_block_handlers(self) -> bool:
        return len(self._added_handlers) > 0

    def get_text(self) -> SsbOpParam:
        assert self._added_string_handler is not None
        if not self.is_message_case:
            raise SsbCompilerError(_("Invalid message switch case call."))
        return self._added_string_handler.collect(allow_integer_like=False)

    def collect_header_handler(self) -> CaseHeaderCompileHandler:
        assert self._case_header_handler is not None
        return self._case_header_handler

    def add(
        self,
        obj: AbstractStatementCompileHandler[Antlr4ParserRuleContext]
        | CaseHeaderCompileHandler
        | PrimitiveCompileHandler,
    ) -> None:
        if isinstance(obj, AbstractComplexStatementCompileHandler):
            # Sub statement for the block
            # WARNING: Might not have any operations. In this case, it's part of the following cases!
            self._added_handlers.append(obj)
            return
        if isinstance(obj, CaseHeaderCompileHandler):
            self._case_header_handler = obj
            return
        if isinstance(obj, PrimitiveCompileHandler):
            # This is a case for a message switch.
            self.is_message_case = True
            self._added_string_handler = obj
            return
        self._raise_add_error(obj)
