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
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import OP_RETURN, OP_END, OP_HOLD

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler


class KeywordSimpleOpWriteHandler(AbstractWriteHandler):
    """Handles writing simple opcodes that have special keyword representations in ExplorerScript."""

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)

    def write_content(self) -> Vertex | None:
        op: SsbOperation = self.start_vertex["op"]
        self.decompiler.source_map_add_opcode(op.offset)
        if op.op_code.name == OP_RETURN:
            self._write_return()
        elif op.op_code.name == OP_END:
            self._write_end()
        elif op.op_code.name == OP_HOLD:
            self._write_hold()
        else:
            raise ValueError(f"Unknown keyword opcode: {op}")
        exits = self.start_vertex.out_edges()
        if len(exits) == 1:
            next_vertex = exits[0].target_vertex
        elif len(exits) == 0:
            next_vertex = None
        else:
            raise ValueError("After a simple opcode there must be exactly 0 or 1 immediate opcode.")
        return next_vertex

    def _write_return(self) -> None:
        self.decompiler.write_return()

    def _write_end(self) -> None:
        self.decompiler.write_end()

    def _write_hold(self) -> None:
        self.decompiler.write_hold()
