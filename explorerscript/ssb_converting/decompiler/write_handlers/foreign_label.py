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
from explorerscript.ssb_converting.ssb_special_ops import SsbForeignLabel

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

logger = logging.getLogger(__name__)


class ForeignLabelWriteHandler(AbstractWriteHandler):
    """Handles writing foreign labels (references to labels in other routines)."""

    def __init__(
        self,
        start_vertex: Vertex,
        decompiler: ExplorerScriptSsbDecompiler,
        parent: AbstractWriteHandler | None,
        vertex_that_started_block: Vertex | None,
        is_first_vertex_of_block: bool,
    ):
        super().__init__(start_vertex, decompiler, parent)
        self.vertex_that_started_block = vertex_that_started_block
        self.is_first_vertex_of_block = is_first_vertex_of_block

    def write_content(self) -> None:
        op: SsbForeignLabel = self.start_vertex["op"]
        logger.debug("Handling a foreign label (%s)...", op)
        exits = self.start_vertex.out_edges()
        assert len(exits) == 0
        # See note in LabelWriteHandler.
        # TODO: Fix typing
        previous_vertex_op = self.vertex_that_started_block["op"] if self.is_first_vertex_of_block else None  # type: ignore
        # We definitely need to print that
        self.decompiler.write_label_jump(op.label.id, previous_vertex_op)  # type: ignore
        return None
