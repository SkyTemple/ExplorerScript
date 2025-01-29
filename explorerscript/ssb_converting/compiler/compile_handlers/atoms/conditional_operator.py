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

from explorerscript_parser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperator


class ConditionalOperatorCompileHandler(AbstractCompileHandler[ExplorerScriptParser.Conditional_operatorContext, None]):
    def collect(self) -> SsbOperator:
        self.ctx: ExplorerScriptParser.Conditional_operatorContext
        if self.ctx.OP_FALSE():
            return SsbOperator.FALSE
        if self.ctx.OP_TRUE():
            return SsbOperator.TRUE
        if self.ctx.OP_EQ():
            return SsbOperator.EQ
        if self.ctx.OP_GE():
            return SsbOperator.GE
        if self.ctx.OP_LE():
            return SsbOperator.LE
        if self.ctx.CLOSE_SHARP():
            return SsbOperator.GT
        if self.ctx.OPEN_SHARP():
            return SsbOperator.LT
        if self.ctx.OP_NEQ():
            return SsbOperator.NOT
        if self.ctx.OP_AND():
            return SsbOperator.AND
        if self.ctx.OP_XOR():
            return SsbOperator.XOR
        if self.ctx.OP_BICH():
            return SsbOperator.BIT_SET
        raise SsbCompilerError("Unknown conditional operator.")

    def add(self, obj: None) -> None:
        # Doesn't accept anything.
        self._raise_add_error(obj)
