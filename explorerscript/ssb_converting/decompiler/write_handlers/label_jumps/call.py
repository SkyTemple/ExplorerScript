#  MIT License
#
#  Copyright (c) 2020-2023 Capypara and the SkyTemple Contributors
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
import logging

from igraph import Vertex

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler
from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump
logger = logging.getLogger(__name__)


class CallWriteHandler(AbstractWriteHandler):
    """Handles writing call."""

    def __init__(self, start_vertex: Vertex, decompiler, parent):
        super().__init__(start_vertex, decompiler, parent)

    def write_content(self):
        logger.debug("Handling a call; (%s)...", self.start_vertex['op'])
        op: SsbLabelJump = self.start_vertex['op']
        self.decompiler.source_map_add_opcode(op.offset)
        self.decompiler.write_stmnt(f"call @label_{op.label.id};")
        exits = self.start_vertex.out_edges()
        assert 3 > len(exits) > 0, f"A call must have exactly one or two points to jump to, " \
                                   f"has {len(exits)}."
        return exits[0].target_vertex
