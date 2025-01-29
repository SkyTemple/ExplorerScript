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
from explorerscript.ssb_converting.decompiler.write_handlers.labels.forever_start import ForeverWriteHandler
from explorerscript.ssb_converting.ssb_special_ops import (
    SwitchFalltrough,
    SsbLabel,
    IfEnd,
    SwitchEnd,
    ForeverStart,
    ForeverEnd,
)

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

logger = logging.getLogger(__name__)


class LabelWriteHandler(AbstractWriteHandler):
    """Handles writing labels."""

    vertex_that_started_block: Vertex | None
    is_first_vertex_of_block: bool

    # Settings set by the markers
    # ID of the ended ifs
    ended_ifs: list[int]
    # ID of the ended switches
    ended_switches: list[int]
    # ID of the started loops
    started_loops: list[int]
    # ID of the ended loops
    ended_loops: list[int]
    # Whether or not this had a switch fallthrough
    switch_fell_through: bool

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

        self.ended_ifs = []
        self.ended_switches = []
        self.started_loops = []
        self.ended_loops = []
        self.switch_fell_through = False

        op: SsbLabel = self.start_vertex["op"]

        # Let's set the attributes of this handler based on the markers.
        for m in op.markers:
            if isinstance(m, IfEnd):
                self.ended_ifs.append(m.if_id)
            elif isinstance(m, SwitchEnd):
                self.ended_switches.append(m.switch_id)
            elif isinstance(m, SwitchFalltrough):
                self.switch_fell_through = True
            elif isinstance(m, ForeverStart):
                self.started_loops.append(m.loop_id)
            elif isinstance(m, ForeverEnd):
                self.ended_loops.append(m.loop_id)

    def write_content(self) -> Vertex | None:
        op: SsbLabel = self.start_vertex["op"]
        logger.debug("Handling a label (%s)...", op)
        needs_to_be_printed = op.needs_to_be_printed(
            self.start_vertex.index, len(self.start_vertex.in_edges()), self.start_vertex.graph
        )

        # EXCEPTION for Switch Fallthrough.
        # If this is a switch fallthrough and NOT the first vertex of this branch,
        # then we have to stop here, we continue printing this in the following switch branch.
        if self.switch_fell_through and not self.is_first_vertex_of_block:
            if needs_to_be_printed and op.id not in self.decompiler.labels_already_printed:
                self._write_label(op)
            self.ended_on_jump = True
            logger.debug("Label was switch fallthrough!")
            return None

        # Let's check if we need to print it
        if op.id in self.decompiler.labels_already_printed:
            # We are at the end, since we already printed this entire branch somewhere else.
            # If we aren't the first vertex in this block, then the operation before this was a simple
            # one, we can set previous_vertex to None then and just print a jump statement.
            # TODO: fix typing
            previous_vertex_op = self.vertex_that_started_block["op"] if self.is_first_vertex_of_block else None  # type: ignore
            self.decompiler.write_label_jump(op.id, previous_vertex_op)  # type: ignore
            self.ended_on_jump = True
            logger.debug("Wrote the label!")
            return None
        elif needs_to_be_printed:
            # Print the label
            self._write_label(op)

        exits = self.start_vertex.out_edges()
        if len(exits) == 1:
            if len(self.started_loops) > 0:
                # Delegate to loop handler
                # TODO: Handle multiple loop starts (oh dear god what a nightmare)
                assert len(self.started_loops) == 1
                logger.debug("Handing of to forever write handler!")
                return ForeverWriteHandler(self.start_vertex, self.decompiler, self.parent).write_content()

            return exits[0].target_vertex
        raise ValueError("After a label there must be exactly 1 opcode.")

    def _write_label(self, label: SsbLabel) -> None:
        self.decompiler.write_stmnt(f"@label_{label.id};")
        self.decompiler.labels_already_printed.append(label.id)
