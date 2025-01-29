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

from typing import Any

from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractFuncdefCompileHandler
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbRoutineType
from explorerscript_parser import ExplorerScriptParser


class CoroDefCompileHandler(AbstractFuncdefCompileHandler[ExplorerScriptParser.Coro_defContext]):
    def collect(self) -> Any:
        """Collects name of the coroutine, routine info and operations."""
        name = str(self.ctx.IDENTIFIER())
        with self.compiler_ctx.in_funcdef(name):
            ops = self.collect_ops()
        return str(name), SsbRoutineInfo(SsbRoutineType.COROUTINE, 0), ops

    def get_new_routine_id(self, old_id: int) -> int:
        return old_id + 1
