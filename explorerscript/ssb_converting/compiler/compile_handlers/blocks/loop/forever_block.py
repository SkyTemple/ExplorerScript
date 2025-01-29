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

from typing import cast

from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractStatementCompileHandler,
    AbstractComplexStatementCompileHandler,
    AbstractLoopBlockCompileHandler,
    AnyLoopBlockCompileHandler,
)
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript_parser import ExplorerScriptParser, Antlr4ParserRuleContext


class ForeverBlockCompileHandler(AbstractLoopBlockCompileHandler[ExplorerScriptParser.Forever_blockContext]):
    """Handles an entire forever block."""

    def collect(self) -> list[SsbOperation]:
        with self.compiler_ctx.in_loop(cast(AnyLoopBlockCompileHandler, self)):
            retval = [self._start_label] + self._process_block(False) + [self.continue_loop(), self._end_label]
        return retval

    def add(self, obj: AbstractStatementCompileHandler[Antlr4ParserRuleContext]) -> None:
        if isinstance(obj, AbstractComplexStatementCompileHandler):
            # Sub statement for the block
            self._added_handlers.append(obj)
            return
        self._raise_add_error(obj)
