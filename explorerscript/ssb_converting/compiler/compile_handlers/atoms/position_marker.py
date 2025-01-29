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

from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.position_marker_arg import (
    PositionMarkerArgCompileHandler,
)
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, singleline_string_literal
from explorerscript.ssb_converting.ssb_data_types import SsbOpParamPositionMarker
from explorerscript_parser import ExplorerScriptParser


class PositionMarkerCompileHandler(
    AbstractCompileHandler[ExplorerScriptParser.Position_markerContext, PositionMarkerArgCompileHandler]
):
    def __init__(self, ctx: ExplorerScriptParser.Position_markerContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        # position, offset
        self.x: tuple[int, int] | None = None
        self.y: tuple[int, int] | None = None

    def collect(self) -> SsbOpParamPositionMarker:
        name = singleline_string_literal(str(self.ctx.STRING_LITERAL()))
        assert self.x is not None and self.y is not None
        return SsbOpParamPositionMarker(
            name=name, x_offset=self.x[1], y_offset=self.y[1], x_relative=self.x[0], y_relative=self.y[0]
        )

    def add(self, obj: PositionMarkerArgCompileHandler) -> None:
        if isinstance(obj, PositionMarkerArgCompileHandler):
            if self.x is None:
                self.x = obj.collect()
            else:
                self.y = obj.collect()
            return
        self._raise_add_error(obj)
