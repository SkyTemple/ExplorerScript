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
from typing import Optional

from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_data_types import SsbOperator, SsbOpParam
from explorerscript.ssb_converting.ssb_special_ops import OP_BRANCH_DEBUG, OP_BRANCH_EDIT, OP_BRANCH_VARIATION


class IfHeaderNegatableCompileHandler(AbstractCompileHandler):
    def __init__(self, ctx, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self.var_target: Optional[SsbOpParam] = None
        self.operator: Optional[SsbOperator] = None
        self.value: Optional[SsbOpParam] = None
        self.value_is_a_variable = False

    def collect(self) -> SsbLabelJumpBlueprint:
        is_simple_positive = self.ctx.NOT() is None
        if self.ctx.DEBUG():
            return SsbLabelJumpBlueprint(
                self.compiler_ctx, self.ctx,
                OP_BRANCH_DEBUG, [1 if is_simple_positive else 0]
            )
        if self.ctx.EDIT():
            return SsbLabelJumpBlueprint(
                self.compiler_ctx, self.ctx,
                OP_BRANCH_EDIT, [1 if is_simple_positive else 0]
            )
        if self.ctx.VARIATION():
            return SsbLabelJumpBlueprint(
                self.compiler_ctx, self.ctx,
                OP_BRANCH_VARIATION, [1 if is_simple_positive else 0]
            )

    def add(self, obj: any):
        self._raise_add_error(obj)
