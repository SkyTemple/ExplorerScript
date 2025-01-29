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
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.bit import IfHeaderBitCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.negatable import (
    IfHeaderNegatableCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.operator import (
    IfHeaderOperatorCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.scn import IfHeaderScnCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.operation import OperationCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_special_ops import OPS_BRANCH
from explorerscript.util import _, f

_SupportedHandlers: TypeAlias = Union[
    IfHeaderBitCompileHandler,
    IfHeaderOperatorCompileHandler,
    IfHeaderNegatableCompileHandler,
    IfHeaderScnCompileHandler,
    OperationCompileHandler,
]


class IfHeaderCompileHandler(AbstractCompileHandler[ExplorerScriptParser.If_headerContext, _SupportedHandlers]):
    def __init__(self, ctx: ExplorerScriptParser.If_headerContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._header_cmplx_handler: _SupportedHandlers | None = None
        self._is_positive = True

    def set_positive(self, positive: bool) -> None:
        self._is_positive = positive

    def collect(self) -> SsbLabelJumpBlueprint:
        is_positive = self._is_positive

        # Complex branches
        if self._header_cmplx_handler:
            if isinstance(self._header_cmplx_handler, OperationCompileHandler):
                # An operation as condition
                ops = self._header_cmplx_handler.collect()
                if len(ops) != 1:
                    raise SsbCompilerError(_("Invalid content for an if-header"))
                op = ops[0]
                if op.op_code.name not in OPS_BRANCH.keys():
                    raise SsbCompilerError(
                        f(_("Invalid operation for if condition: {op.op_code.name} (line {self.ctx.start.line})"))
                    )
                jmp = SsbLabelJumpBlueprint(self.compiler_ctx, self.ctx, op.op_code.name, op.params)
                jmp.set_jump_is_positive(is_positive)
                return jmp
            else:
                # A regular complex if condition
                tmpl: SsbLabelJumpBlueprint = self._header_cmplx_handler.collect()
                tmpl.set_jump_is_positive(is_positive)
                return tmpl

        raise SsbCompilerError(f(_("Unknown if operation in line {self.ctx.start.line}).")))

    def add(self, obj: _SupportedHandlers) -> None:
        if (
            isinstance(obj, IfHeaderBitCompileHandler)
            or isinstance(obj, IfHeaderOperatorCompileHandler)
            or isinstance(obj, IfHeaderNegatableCompileHandler)
            or isinstance(obj, IfHeaderScnCompileHandler)
            or isinstance(obj, OperationCompileHandler)
        ):
            self._header_cmplx_handler = obj
            return
        self._raise_add_error(obj)
