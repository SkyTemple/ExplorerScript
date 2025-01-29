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
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.scn_var import ScnVarCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOpParam, SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import OP_SWITCH_SCENARIO, OP_SWITCH_SCENARIO_LEVEL
from explorerscript.util import _, f
from explorerscript.util import exps_int


class SwitchHeaderScnCompileHandler(
    AbstractCompileHandler[ExplorerScriptParser.Switch_h_scnContext, ScnVarCompileHandler]
):
    def __init__(self, ctx: ExplorerScriptParser.Switch_h_scnContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self.scn_var_target: SsbOpParam | None = None

    def collect(self) -> SsbOperation:
        if self.scn_var_target is None:
            raise SsbCompilerError(_("No variable set for scn switch condition."))

        index = exps_int(str(self.ctx.INTEGER()))
        if index == 0:
            return self._generate_operation(OP_SWITCH_SCENARIO, [self.scn_var_target])
        elif index == 1:
            return self._generate_operation(OP_SWITCH_SCENARIO_LEVEL, [self.scn_var_target])
        raise SsbCompilerError(f(_("Index for scn() if condition must be 0 or 1 (line {self.ctx.start.line}).")))

    def add(self, obj: ScnVarCompileHandler) -> None:
        if isinstance(obj, ScnVarCompileHandler):
            self.scn_var_target = obj.collect()
            return

        self._raise_add_error(obj)
