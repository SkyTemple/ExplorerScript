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
import logging
from typing import TYPE_CHECKING

from igraph import Vertex

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.block import BlockWriteHandler
from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, ForeverStart
from explorerscript.ssb_converting.util import Blk

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

logger = logging.getLogger(__name__)


class ForeverWriteHandler(AbstractWriteHandler):
    """Handles writing loops."""

    m: ForeverStart | None = None
    ended_on_jump: bool
    # Since the break_loop does NOT have to be on the exact next level, we use a stack system instead!
    _vertex_after_forever: Vertex | None

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)
        self.m = None
        self.ended_on_jump = True
        self._vertex_after_forever = None

    def write_content(self) -> Vertex | None:
        op: SsbLabelJump = self.start_vertex["op"]
        logger.debug("Writing a forever-block (%s)...", op)
        m: ForeverStart = [m for m in op.markers if isinstance(m, ForeverStart)][0]
        self.m = m

        exits = self.start_vertex.out_edges()

        self.decompiler.write_stmnt("forever")
        with Blk(self.decompiler):
            self.decompiler.forever_start_handler_stack.append(self)
            BlockWriteHandler(
                exits[0].target_vertex, self.decompiler, self, self.start_vertex, check_end_block=self.check_end_block
            ).write_content()
            self.decompiler.forever_start_handler_stack.pop()
            return self._vertex_after_forever

    def set_vertex_after(self, v: Vertex) -> None:
        self._vertex_after_forever = v

    def check_end_block(self, block: BlockWriteHandler, next_handler: AbstractWriteHandler) -> bool:
        """
        A loop should end either if there are no vertices left (duh!) or if the end-forever label is reached.
        """
        from explorerscript.ssb_converting.decompiler.write_handlers.label import LabelWriteHandler

        if isinstance(next_handler, LabelWriteHandler):
            lwh = next_handler

            if len(lwh.ended_loops) > 0:
                assert self.m is not None
                if self.m.loop_id in lwh.ended_loops:
                    return False
        return True
