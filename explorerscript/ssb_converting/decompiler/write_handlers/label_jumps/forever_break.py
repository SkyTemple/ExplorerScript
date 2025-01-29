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

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler, FallbackToJump

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

logger = logging.getLogger(__name__)


class ForeverBreakWriteHandler(AbstractWriteHandler):
    """Handles writing loop breaks."""

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)

    def write_content(self) -> Vertex | None:
        """Print a break and end"""
        logger.debug("Handling a break_loop; (%s)...", self.start_vertex["op"])
        self.decompiler.source_map_add_opcode(self.start_vertex["op"].offset)
        self.decompiler.write_stmnt("break_loop;")
        exits = self.start_vertex.out_edges()
        if len(exits) == 1:
            if len(self.decompiler.forever_start_handler_stack) < 1:
                # We REALLY shouldn't land here, if we are outside of a loop, but sometimes loop detection still
                # raises some "false positives" and builds loops that have break statements reachable from outside
                # the loop
                logger.warning("While decompiling, tried to generate break_loop; outside loop!")
                raise FallbackToJump()
            # Make sure the forever start block is aware of the next vertex!
            self.decompiler.forever_start_handler_stack[-1].set_vertex_after(exits[0].target_vertex)
            return None
        raise ValueError("After a break_loop there must be exactly 1 immediate opcode.")
