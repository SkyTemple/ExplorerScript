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
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractStatementCompileHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import OP_HOLD, OP_END, OP_RETURN


class ControlStatementCompileHandler(AbstractStatementCompileHandler[ExplorerScriptParser.Cntrl_stmtContext]):
    def collect(self) -> list[SsbOperation]:
        ops = []
        if self.ctx.RETURN():
            ops.append(self._generate_operation(OP_RETURN, []))
        elif self.ctx.END():
            ops.append(self._generate_operation(OP_END, []))
        elif self.ctx.HOLD():
            ops.append(self._generate_operation(OP_HOLD, []))
        elif self.ctx.CONTINUE():
            ops.append(self._register_operation(self.compiler_ctx.continue_loop(self.ctx)))
        elif self.ctx.BREAK():
            ops.append(self._register_operation(self.compiler_ctx.break_case(self.ctx)))
        elif self.ctx.BREAK_LOOP():
            ops.append(self._register_operation(self.compiler_ctx.break_loop(self.ctx)))

        return ops

    def add(self, obj: None) -> None:
        # supports no added handlers
        self._raise_add_error(obj)
