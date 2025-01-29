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
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, OP_CALL


class CallCompileHandler(AbstractStatementCompileHandler[ExplorerScriptParser.CallContext]):
    def collect(self) -> list[SsbOperation]:
        """
        We generate a label jump (using call) now.
        """
        self.ctx: ExplorerScriptParser.CallContext
        label_name = str(self.ctx.IDENTIFIER())
        if label_name in self.compiler_ctx.collected_labels:
            label = self.compiler_ctx.collected_labels[label_name]
        else:
            label = SsbLabel(self.compiler_ctx.counter_labels(), -1, f"proper label, named {label_name}", label_name)
            self.compiler_ctx.collected_labels[label_name] = label
        return [self._generate_jump_operation(OP_CALL, [], label)]

    def add(self, obj: None) -> None:
        # supports no added handlers
        self._raise_add_error(obj)
