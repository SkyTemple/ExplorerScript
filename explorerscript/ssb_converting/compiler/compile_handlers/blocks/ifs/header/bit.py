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
from typing import Optional, List

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.integer_like import IntegerLikeCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_data_types import SsbOpParam
from explorerscript.ssb_converting.ssb_special_ops import OP_BRANCH_BIT, OP_BRANCH_PERFORMANCE
from explorerscript.util import exps_int
from explorerscript.util import _, f


class IfHeaderBitCompileHandler(AbstractCompileHandler):
    def __init__(self, ctx, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self.var_target: Optional[SsbOpParam] = None

    def collect(self) -> SsbLabelJumpBlueprint:
        self.ctx: ExplorerScriptParser.If_h_bitContext
        if self.var_target is None:
            raise SsbCompilerError(_("No variable in if condition."))

        var_target_name = None
        if hasattr(self.var_target, 'name'):
            var_target_name = self.var_target.name

        index = exps_int(str(self.ctx.INTEGER()))
        is_simple_positive = self.ctx.NOT() is None

        if var_target_name == self.compiler_ctx.performance_progress_list_var_name:
            return SsbLabelJumpBlueprint(
                self.compiler_ctx, self.ctx,
                OP_BRANCH_PERFORMANCE, [index, 1 if is_simple_positive else 0]
            )
        elif not is_simple_positive:
            raise SsbCompilerError(f(_("The variable {var_target_name} can not be used with 'not' "
                                       "(line {self.ctx.start.line}).")))
        return SsbLabelJumpBlueprint(
            self.compiler_ctx, self.ctx,
            OP_BRANCH_BIT, [self.var_target, index]
        )

    def add(self, obj: any):
        if isinstance(obj, IntegerLikeCompileHandler):
            self.var_target = obj.collect()
            return

        self._raise_add_error(obj)
