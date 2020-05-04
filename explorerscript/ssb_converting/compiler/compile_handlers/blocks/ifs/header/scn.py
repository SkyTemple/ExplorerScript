#  MIT License
#
#  Copyright (c) 2020 Parakoopa
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

from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.conditional_operator import \
    ConditionalOperatorCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.scn_var import ScnVarCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_data_types import SsbOpParam, SsbOperator
from explorerscript.ssb_converting.ssb_special_ops import OP_BRANCH_SCENARIO_NOW_BEFORE, OP_BRANCH_SCENARIO_BEFORE, \
    OP_BRANCH_SCENARIO_NOW_AFTER, OP_BRANCH_SCENARIO_AFTER, OP_BRANCH_SCENARIO_NOW


class IfHeaderScnCompileHandler(AbstractCompileHandler):
    def __init__(self, ctx, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self.scn_var_target: Optional[SsbOpParam] = None
        self.operator1: Optional[SsbOperator] = None
        self.operator2: Optional[SsbOperator] = None

    def collect(self) -> SsbLabelJumpBlueprint:
        if self.scn_var_target is None:
            raise SsbCompilerError("No variable for assignment.")
        if self.operator1 is None:
            raise SsbCompilerError("Not enough operator set for if condition.")
        if self.operator2 is None:
            raise SsbCompilerError("Not enough operator set for if condition.")

        if self.operator1 != SsbOperator.EQ:
            raise SsbCompilerError(f"The only supported operator for the first value of scn if "
                                   f"conditions is == (line {self.ctx.start.line})")
        if self.operator2 not in [SsbOperator.EQ, SsbOperator.LE, SsbOperator.LT, SsbOperator.GE, SsbOperator.GT]:
            raise SsbCompilerError(f"The only supported operators for the second value of scn if "
                                   f"conditions are ==,<,<=,>,>= (line {self.ctx.start.line})")

        scn_value = int(str(self.ctx.INTEGER(0)))
        level_value = int(str(self.ctx.INTEGER(1)))

        if self.operator2 == SsbOperator.LE:
            return SsbLabelJumpBlueprint(
                self.compiler_ctx, self.ctx,
                OP_BRANCH_SCENARIO_NOW_BEFORE, [self.scn_var_target, scn_value, level_value]
            )
        if self.operator2 == SsbOperator.LT:
            return SsbLabelJumpBlueprint(
                self.compiler_ctx, self.ctx,
                OP_BRANCH_SCENARIO_BEFORE, [self.scn_var_target, scn_value, level_value]
            )
        if self.operator2 == SsbOperator.GE:
            return SsbLabelJumpBlueprint(
                self.compiler_ctx, self.ctx,
                OP_BRANCH_SCENARIO_NOW_AFTER, [self.scn_var_target, scn_value, level_value]
            )
        if self.operator2 == SsbOperator.GT:
            return SsbLabelJumpBlueprint(
                self.compiler_ctx, self.ctx,
                OP_BRANCH_SCENARIO_AFTER, [self.scn_var_target, scn_value, level_value]
            )
        return SsbLabelJumpBlueprint(
            self.compiler_ctx, self.ctx,
            OP_BRANCH_SCENARIO_NOW, [self.scn_var_target, scn_value, level_value]
        )

    def add(self, obj: any):
        if isinstance(obj, ScnVarCompileHandler):
            self.scn_var_target = obj.collect()
            return
        if isinstance(obj, ConditionalOperatorCompileHandler):
            if self.operator1 is None:
                self.operator1 = obj.collect()
            else:
                self.operator2 = obj.collect()
            return

        self._raise_add_error(obj)
