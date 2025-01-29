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
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractAssignmentCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.assignment_operator import (
    AssignOperatorCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.primitive import PrimitiveCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.value_of import ValueOfCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam, SsbCalcOperator
from explorerscript.ssb_converting.ssb_special_ops import (
    OPS_FLAG__CALC_VARIABLE,
    OPS_FLAG__SET,
    OPS_FLAG__CALC_VALUE,
    OPS_FLAG__SET_PERFORMANCE,
    OPS_FLAG__CALC_BIT,
)
from explorerscript.util import exps_int, f, _


class AssignmentRegularCompileHandler(
    AbstractAssignmentCompileHandler[
        ExplorerScriptParser.Assignment_regularContext,
        "PrimitiveCompileHandler | AssignOperatorCompileHandler | ValueOfCompileHandler",
    ]
):
    def __init__(self, ctx: ExplorerScriptParser.Assignment_regularContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self.var_target: SsbOpParam | None = None
        self.operator: SsbCalcOperator | None = None
        self.value: SsbOpParam | None = None
        self.value_is_a_variable = False

    def collect(self) -> list[SsbOperation]:
        if self.var_target is None:
            raise SsbCompilerError(_("No variable for assignment."))
        if self.operator is None:
            raise SsbCompilerError(_("No operator set for assignment."))
        if self.value is None:
            raise SsbCompilerError(_("No value set for assignment."))

        if self.ctx.INTEGER():
            index = exps_int(str(self.ctx.INTEGER()))
            # CalcBit / SetPerformance
            if self.value_is_a_variable:
                raise SsbCompilerError(
                    f(_("value(X) can not be used with index based assignments (line {self.ctx.start.line})."))
                )
            if str(self.var_target) == self.compiler_ctx.performance_progress_list_var_name:
                return [self._generate_operation(OPS_FLAG__SET_PERFORMANCE, [index, self.value])]
            return [self._generate_operation(OPS_FLAG__CALC_BIT, [self.var_target, index, self.value])]

        # CalcValue / CalcVariable / Set
        if self.value_is_a_variable:
            return [
                self._generate_operation(OPS_FLAG__CALC_VARIABLE, [self.var_target, self.operator.value, self.value])
            ]
        if self.operator == SsbCalcOperator.ASSIGN:
            return [self._generate_operation(OPS_FLAG__SET, [self.var_target, self.value])]
        return [self._generate_operation(OPS_FLAG__CALC_VALUE, [self.var_target, self.operator.value, self.value])]

    def add(self, obj: PrimitiveCompileHandler | AssignOperatorCompileHandler | ValueOfCompileHandler) -> None:
        # assign_operator -> operator
        if isinstance(obj, PrimitiveCompileHandler):
            if self.var_target is None:
                # integer_like[0] -> variable
                self.var_target = obj.collect(allow_string=False)
                return
            if self.value is None:
                # (integer_like[1] | value_of) -> var to set to
                self.value = obj.collect(allow_string=False)
                self.value_is_a_variable = False
                return
            raise SsbCompilerError("Assignment: unexpected INTEGER_LIKE.")
        if isinstance(obj, AssignOperatorCompileHandler):
            self.operator = obj.collect()
            return
        if isinstance(obj, ValueOfCompileHandler):
            self.value = obj.collect()
            self.value_is_a_variable = True
            return

        self._raise_add_error(obj)
