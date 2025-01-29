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

from typing import TYPE_CHECKING

from igraph import Vertex

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import (
    AbstractWriteHandler,
    NestedBlockDisallowedError,
)
from explorerscript.ssb_converting.decompiler.write_handlers.block import BlockWriteHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import (
    OP_MESSAGE_SWITCH_TALK,
    OP_MESSAGE_SWITCH_MONOLOGUE,
    OPS_SWITCH_TEXT_CASE_MAP,
)
from explorerscript.ssb_converting.util import Blk

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler


class MesageSwitchSimpleOpWriteHandler(AbstractWriteHandler):
    """Handles writing message_SwitchMonologue and message_SwitchTalk."""

    op_name: str | None
    have_written_at_least_one_child: bool

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)
        self.op_name = None
        self.have_written_at_least_one_child = False

    def write_content(self) -> Vertex | None:
        op: SsbOperation = self.start_vertex["op"]
        self.op_name = op.op_code.name

        self.decompiler.source_map_add_opcode(op.offset)
        if len(op.params) != 1:
            raise ValueError(f"Error reading operation for {self.op_name} ({op}). Must have exactly one argument.")
        if self.op_name == OP_MESSAGE_SWITCH_TALK:
            self.decompiler.write_stmnt(f"message_SwitchTalk ({op.params[0]})")
        elif self.op_name == OP_MESSAGE_SWITCH_MONOLOGUE:
            self.decompiler.write_stmnt(f"message_SwitchMonologue ({op.params[0]})")
        else:
            raise ValueError(f"Unknown message switch opcode: {op}")

        exits = self.start_vertex.out_edges()
        assert len(exits) == 1, "After a message_Switch* op, there must be exactly one op following."

        # Write the context opcode.
        with Blk(self.decompiler):
            try:
                next_vertex_after_blk = BlockWriteHandler(
                    exits[0].target_vertex,
                    self.decompiler,
                    self,
                    self.start_vertex,
                    check_end_block=self.check_end_block,
                    disallow_nested=True,
                ).write_content()
            except NestedBlockDisallowedError:
                raise ValueError(
                    "message_Switch* opcode blocks must not contain opcodes that start any branching code."
                )

        return next_vertex_after_blk

    def check_end_block(self, block: BlockWriteHandler, next_handler: AbstractWriteHandler) -> bool:
        next_op: SsbOperation = next_handler.start_vertex["op"]
        assert self.op_name is not None
        if next_op.op_code.name not in OPS_SWITCH_TEXT_CASE_MAP[self.op_name]:
            if not self.have_written_at_least_one_child:
                raise ValueError("A message_Switch* must have at least one case or default.")
            return False
        self.have_written_at_least_one_child = True
        return True
