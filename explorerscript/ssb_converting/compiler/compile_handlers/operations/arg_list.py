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

from explorerscript.source_map import SourceMapPositionMark
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.arg import ArgCompileHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOpParam, SsbOpParamPositionMarker
from explorerscript_parser import ExplorerScriptParser


class ArgListCompileHandler(AbstractCompileHandler[ExplorerScriptParser.ArglistContext, ArgCompileHandler]):
    def collect(self) -> list[SsbOpParam]:
        ret = []
        for i, h in enumerate(self._added_handlers):
            arg = h.collect()
            ret.append(arg)
            if isinstance(arg, SsbOpParamPositionMarker):
                # Collect position marker source map entries
                self.compiler_ctx.source_map_builder.add_position_mark(
                    SourceMapPositionMark(
                        # Antlr line ids are 1-indexed.
                        self.ctx.start.line - 1,
                        self.ctx.start.charPositionInLine,
                        self.ctx.stop.line - 1,
                        self.ctx.stop.charPositionInLine,
                        arg.name,
                        arg.x_offset,
                        arg.y_offset,
                        arg.x_relative,
                        arg.y_relative,
                    )
                )
        return ret

    def add(self, obj: ArgCompileHandler) -> None:
        if isinstance(obj, ArgCompileHandler):
            self._added_handlers.append(obj)
            return
        self._raise_add_error(obj)
