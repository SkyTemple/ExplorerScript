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

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.simple_ops.message_switches import (
    MesageSwitchSimpleOpWriteHandler,
)
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import OP_CASE_TEXT, OP_DEFAULT_TEXT
from explorerscript.ssb_converting.util import Blk

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler


class MesageSwitchCasesSimpleOpWriteHandler(AbstractWriteHandler):
    """Handles writing cases for message_Switch* opcodes."""

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)

    def write_content(self) -> Vertex | None:
        op: SsbOperation = self.start_vertex["op"]
        self.decompiler.source_map_add_opcode(op.offset)

        # The parent handler MUST be a simple block handler -> block handler
        # and it's handler MUST be a message switch handler
        assert self.parent is not None and self.parent.parent is not None
        if not isinstance(self.parent.parent.parent, MesageSwitchSimpleOpWriteHandler):
            raise ValueError("Message switch cases are only allowed as children of message switches.")

        if op.op_code.name == OP_CASE_TEXT:
            self.decompiler.write_stmnt(f"case {op.params[0]}:")
            with Blk(self.decompiler, False):
                if hasattr(op.params[1], "indent"):
                    op.params[1].indent = self.decompiler.indent
                self.decompiler.write_stmnt(str(op.params[1]))
        elif op.op_code.name == OP_DEFAULT_TEXT:
            self.decompiler.write_stmnt("default:")
            with Blk(self.decompiler, False):
                if hasattr(op.params[0], "indent"):
                    op.params[0].indent = self.decompiler.indent
                self.decompiler.write_stmnt(str(op.params[0]))

        exits = self.start_vertex.out_edges()
        if len(exits) == 1:
            next_vertex = exits[0].target_vertex
        elif len(exits) == 0:
            next_vertex = None
        else:
            raise ValueError("After a simple opcode there must be exactly 0 or 1 immediate opcode.")
        return next_vertex
