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
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam, SsbOpParamPositionMarker

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler


class SimpleSimpleOpWriteHandler(AbstractWriteHandler):
    """Handles writing regular opcodes."""

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)

    def write_content(self, inline_ctx: str | None = None) -> Vertex | None:
        op: SsbOperation = self.start_vertex["op"]

        # Build parameter string
        params = ", ".join([self._single_param_to_string(param) for param in op.params])

        # Build position mark source maps
        for param in op.params:
            if isinstance(param, SsbOpParamPositionMarker):
                self.decompiler.source_map_add_position_mark(len(self._single_param_to_string(param)), param)
        self.decompiler.source_map_add_opcode(op.offset)
        if inline_ctx:
            self.decompiler.write_stmnt(f"{op.op_code.name}<{inline_ctx}>({params});")
        else:
            self.decompiler.write_stmnt(f"{op.op_code.name}({params});")

        exits = self.start_vertex.out_edges()
        if len(exits) == 1:
            next_vertex = exits[0].target_vertex
        elif len(exits) == 0:
            next_vertex = None
        else:
            raise ValueError("After a simple opcode there must be exactly 0 or 1 immediate opcode.")
        return next_vertex

    def _single_param_to_string(self, param: SsbOpParam) -> str:
        if hasattr(param, "indent"):
            param.indent = self.decompiler.indent
        return str(param)
