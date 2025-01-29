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

from explorerscript.source_map import SourceMapBuilder, SourceMapPositionMark
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.position_marker import PositionMarkerCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.position_marker_arg import (
    PositionMarkerArgCompileHandler,
)
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, Counter, UserDefinedConstants
from explorerscript.ssb_converting.ssb_data_types import SsbOpParamPositionMarker
from explorerscript_parser import ExplorerScriptParser, ExplorerScriptBaseVisitor


class PositionMarkVisitor(ExplorerScriptBaseVisitor):
    """Returns the list of position marks from an ExplorerScript parsing tree."""

    def __init__(self) -> None:
        self.compiler_ctx = CompilerCtx(
            Counter(), SourceMapBuilder(), {}, Counter(), "n/a", {}, UserDefinedConstants({}, {}, {})
        )
        super().__init__()

    def visitStart(self, ctx: ExplorerScriptParser.StartContext) -> list[SourceMapPositionMark]:
        return self.visitChildren(ctx)

    def visitPosition_marker(self, ctx: ExplorerScriptParser.Position_markerContext) -> SourceMapPositionMark:
        mark_handler = PositionMarkerCompileHandler(ctx, self.compiler_ctx)
        for arg_handler in self.visitChildren(ctx):
            mark_handler.add(arg_handler)
        pos_mark_param: SsbOpParamPositionMarker = mark_handler.collect()
        return SourceMapPositionMark(
            ctx.start.line - 1,
            ctx.start.charPositionInLine,
            ctx.stop.line - 1,
            ctx.stop.charPositionInLine,
            pos_mark_param.name,
            pos_mark_param.x_offset,
            pos_mark_param.y_offset,
            pos_mark_param.x_relative,
            pos_mark_param.y_relative,
        )

    def visitPosition_marker_arg(
        self, ctx: ExplorerScriptParser.Position_marker_argContext
    ) -> PositionMarkerArgCompileHandler:
        return PositionMarkerArgCompileHandler(ctx, self.compiler_ctx)

    def defaultResult(self) -> list[SourceMapPositionMark]:  # type: ignore
        return []

    def visitTerminal(self, node: Any) -> None:
        return None

    def aggregateResult(
        self, aggregate: list[SourceMapPositionMark], nextResult: list[SourceMapPositionMark] | SourceMapPositionMark
    ) -> list[SourceMapPositionMark]:
        if isinstance(nextResult, list):
            return aggregate + nextResult
        if nextResult is not None:
            aggregate.append(nextResult)
        return aggregate
