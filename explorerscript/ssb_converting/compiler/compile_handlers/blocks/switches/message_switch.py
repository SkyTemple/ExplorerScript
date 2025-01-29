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

from typing import Union

from typing import TypeAlias

from explorerscript_parser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractComplexStatementCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.primitive import PrimitiveCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_block import CaseBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.default_case_block import (
    DefaultCaseBlockCompileHandler,
)
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam
from explorerscript.ssb_converting.ssb_special_ops import (
    OP_MESSAGE_SWITCH_MONOLOGUE,
    OP_MESSAGE_SWITCH_TALK,
    OP_CASE_TEXT,
    OP_DEFAULT_TEXT,
)
from explorerscript.util import _, f

_SupportedHandlers: TypeAlias = Union[CaseBlockCompileHandler, DefaultCaseBlockCompileHandler, PrimitiveCompileHandler]


class MessageSwitchCompileHandler(
    AbstractComplexStatementCompileHandler[ExplorerScriptParser.Message_switch_blockContext, _SupportedHandlers]
):
    """Handles a message switch."""

    def __init__(self, ctx: ExplorerScriptParser.Message_switch_blockContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._switch_header_handler: PrimitiveCompileHandler | None = None
        self._case_handlers: list[CaseBlockCompileHandler] = []
        self._default_handler: DefaultCaseBlockCompileHandler | None = None

    def collect(self) -> list[SsbOperation]:
        if self.ctx.MESSAGE_SWITCH_MONOLOGUE():
            switch_op = self._generate_operation(OP_MESSAGE_SWITCH_MONOLOGUE, [self._collect_header()])
        elif self.ctx.MESSAGE_SWITCH_TALK():
            switch_op = self._generate_operation(OP_MESSAGE_SWITCH_TALK, [self._collect_header()])
        else:
            raise SsbCompilerError(_("Invalid message switch."))
        case_ops = []
        for h in self._case_handlers:
            if not h.is_message_case:
                raise SsbCompilerError(
                    f(_("A message_ switch can only contain cases with strings (line {self.ctx.start.line})."))
                )
            header_handler = h.collect_header_handler()
            if header_handler.get_header_handler_type() != PrimitiveCompileHandler:
                raise SsbCompilerError(f(_("Invalid case type for message_ switch (line {self.ctx.start.line}).")))
            string = h.get_text()
            value_blueprint = header_handler.collect()
            # We obviously don't want the bluprint
            value = value_blueprint.params[0]
            case_ops.append(self._generate_operation(OP_CASE_TEXT, [value, string]))
        if self._default_handler:
            if not self._default_handler.is_message_case:
                raise SsbCompilerError(
                    f(_("A message_ switch can only contain cases with strings (line {self.ctx.start.line})."))
                )
            case_ops.append(self._generate_operation(OP_DEFAULT_TEXT, [self._default_handler.get_text()]))

        return [switch_op] + case_ops

    def _collect_header(self) -> SsbOpParam:
        assert self._switch_header_handler is not None
        if isinstance(self._switch_header_handler, PrimitiveCompileHandler):
            return self._switch_header_handler.collect(allow_string=False)
        else:
            return self._switch_header_handler.collect()

    def add(self, obj: _SupportedHandlers) -> None:
        if isinstance(obj, CaseBlockCompileHandler):
            self._case_handlers.append(obj)
            return
        if isinstance(obj, DefaultCaseBlockCompileHandler):
            if self._default_handler is not None:
                raise SsbCompilerError(
                    f(_("A switch block can only have a single default case (line {self.ctx.start.line}"))
                )
            self._default_handler = obj
            return
        if isinstance(obj, PrimitiveCompileHandler):
            self._switch_header_handler = obj
            return
        self._raise_add_error(obj)
