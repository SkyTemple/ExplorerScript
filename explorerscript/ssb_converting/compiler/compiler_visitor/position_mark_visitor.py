#  MIT License
#
#  Copyright (c) 2020-2021 Parakoopa and the SkyTemple Contributors
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
from typing import Optional, List

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.antlr.ExplorerScriptVisitor import ExplorerScriptVisitor
from explorerscript.source_map import SourceMapBuilder, SourceMapPositionMark
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.position_marker import PositionMarkerCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.position_marker_arg import \
    PositionMarkerArgCompileHandler
from explorerscript.ssb_converting.compiler.utils import string_literal, CompilerCtx, Counter
from explorerscript.ssb_converting.ssb_data_types import SsbOpParamPositionMarker


class PositionMarkVisitor(ExplorerScriptVisitor):
    """Returns the list of position marks from an ExplorerScript parsing tree."""
    def __init__(self):
        self.compiler_ctx = CompilerCtx(
            Counter(), SourceMapBuilder(), {}, Counter(), 'n/a', {}
        )

    def visitStart(self, ctx : ExplorerScriptParser.StartContext) -> List[SourceMapPositionMark]:
        return self.visitChildren(ctx)

    def visitPosition_marker(self, ctx: ExplorerScriptParser.Position_markerContext):
        mark_handler = PositionMarkerCompileHandler(ctx, self.compiler_ctx)
        for arg_handler in self.visitChildren(ctx):
            mark_handler.add(arg_handler)
        pos_mark_param: SsbOpParamPositionMarker = mark_handler.collect()
        return SourceMapPositionMark(
            ctx.start.line - 1,
            ctx.start.column,
            ctx.stop.line - 1,
            ctx.stop.column,
            pos_mark_param.name,
            pos_mark_param.x_offset,
            pos_mark_param.y_offset,
            pos_mark_param.x_relative,
            pos_mark_param.y_relative,
        )

    def visitPosition_marker_arg(self, ctx: ExplorerScriptParser.Position_marker_argContext):
        return PositionMarkerArgCompileHandler(ctx, self.compiler_ctx)

    def defaultResult(self):
        return []

    def visitTerminal(self, node):
        return None

    def aggregateResult(self, aggregate, nextResult):
        if isinstance(nextResult, list):
            return aggregate + nextResult
        if nextResult is not None:
            aggregate.append(nextResult)
        return aggregate
