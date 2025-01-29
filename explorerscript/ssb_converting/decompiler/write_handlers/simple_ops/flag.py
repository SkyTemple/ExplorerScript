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
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbCalcOperator
from explorerscript.ssb_converting.ssb_special_ops import (
    OPS_FLAG__CALC_BIT,
    OPS_FLAG__CALC_VALUE,
    OPS_FLAG__CALC_VARIABLE,
    OPS_FLAG__CLEAR,
    OPS_FLAG__INITIAL,
    OPS_FLAG__SET,
    OPS_FLAG__RESET_DUNGEON_RESULT,
    OPS_FLAG__RESET_SCENARIO,
    OPS_FLAG__SET_ADVENTURE_LOG,
    OPS_FLAG__SET_DUNGEON_MODE,
    OPS_FLAG__SET_PERFORMANCE,
    OPS_FLAG__SET_SCENARIO,
)

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler


class FlagSimpleOpWriteHandler(AbstractWriteHandler):
    """Handles writing flag setting statements.."""

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)

    def write_content(self) -> Vertex | None:
        op: SsbOperation = self.start_vertex["op"]
        self.decompiler.source_map_add_opcode(op.offset)
        if op.op_code.name == OPS_FLAG__CALC_BIT:
            self.decompiler.write_stmnt(f"{op.params[0]}[{op.params[1]}] = {op.params[2]};")
        elif op.op_code.name == OPS_FLAG__CALC_VALUE:
            self.decompiler.write_stmnt(f"{op.params[0]} {SsbCalcOperator(op.params[1]).notation} {op.params[2]};")  # type: ignore
        elif op.op_code.name == OPS_FLAG__CALC_VARIABLE:
            self.decompiler.write_stmnt(
                f"{op.params[0]} {SsbCalcOperator(op.params[1]).notation} value({op.params[2]});"  # type: ignore
            )
        elif op.op_code.name == OPS_FLAG__CLEAR:
            self.decompiler.write_stmnt(f"clear {op.params[0]};")
        elif op.op_code.name == OPS_FLAG__INITIAL:
            self.decompiler.write_stmnt(f"init {op.params[0]};")
        elif op.op_code.name == OPS_FLAG__SET:
            self.decompiler.write_stmnt(f"{op.params[0]} = {op.params[1]};")
        elif op.op_code.name == OPS_FLAG__RESET_DUNGEON_RESULT:
            self.decompiler.write_stmnt("reset dungeon_result;")
        elif op.op_code.name == OPS_FLAG__RESET_SCENARIO:
            self.decompiler.write_stmnt(f"reset scn({op.params[0]});")
        elif op.op_code.name == OPS_FLAG__SET_ADVENTURE_LOG:
            self.decompiler.write_stmnt(f"adventure_log = {op.params[0]};")
        elif op.op_code.name == OPS_FLAG__SET_DUNGEON_MODE:
            flag_value = self.decompiler.dungeon_mode_constants.get_explorerscript_constant_for(op.params[1])  # type: ignore
            self.decompiler.write_stmnt(f"dungeon_mode({op.params[0]}) = {flag_value};")
        elif op.op_code.name == OPS_FLAG__SET_PERFORMANCE:
            self.decompiler.write_stmnt(
                f"{self.decompiler.performance_progress_list_var_name}[{op.params[0]}] = {op.params[1]};"
            )
        elif op.op_code.name == OPS_FLAG__SET_SCENARIO:
            self.decompiler.write_stmnt(f"{op.params[0]} = scn[{op.params[1]}, {op.params[2]}];")
        else:
            raise ValueError(f"Unknown flag setting opcode: {op}")

        exits = self.start_vertex.out_edges()
        if len(exits) == 1:
            next_vertex = exits[0].target_vertex
        elif len(exits) == 0:
            next_vertex = None
        else:
            raise ValueError("After a simple opcode there must be exactly 0 or 1 immediate opcode.")
        return next_vertex
