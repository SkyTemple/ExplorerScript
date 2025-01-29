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

from igraph import Vertex, Edge

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.block import BlockWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.label import LabelWriteHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_data_types import SsbOperator
from explorerscript.ssb_converting.ssb_special_ops import IfStart, SsbLabelJump, MultiIfStart, SsbLabel, IfEnd
from explorerscript.ssb_converting.util import Blk

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

logger = logging.getLogger(__name__)


class IfWriteHandler(AbstractWriteHandler):
    """Handles writing ifs."""

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)
        self.ended_on_jump = True

    def write_content(self) -> Vertex | None:
        op: SsbLabelJump = self.start_vertex["op"]
        m = op.get_marker()
        assert isinstance(m, IfStart)
        else_edge: Edge | None
        if_edge, else_edge = self._write_if_header("if", op, self.start_vertex)

        if else_edge == if_edge:
            logger.debug("<%d> Handling empty if-block (%s)...", id(self.start_vertex), op)
            # Great if!
            with Blk(self.decompiler):
                pass
            return else_edge.target_vertex
        else:
            logger.debug("<%d> Handling if-block (%s)...", id(self.start_vertex), op)
            with Blk(self.decompiler):
                # Handle if-branch
                if_branch_handler = BlockWriteHandler(
                    if_edge.target_vertex,
                    self.decompiler,
                    self,
                    self.start_vertex,
                    check_end_block=self.check_end_block,
                )
                v_after_if_branch = if_branch_handler.write_content()
            else_ends_on_common_vtx = True
            v_after_else_branch = None
            if not (
                isinstance(else_edge.target_vertex["op"], SsbLabel)
                and any(isinstance(mx, IfEnd) and m.if_id == mx.if_id for mx in else_edge.target_vertex["op"].markers)
            ):
                # Handle all else-ifs that might be in between
                # TODO: does this actually work correctly for the common-end detection...? It think this works?
                else_edge = self._build_else_if_chain(else_edge)
                if else_edge is not None:
                    logger.debug("<%d> Handling else-block...", id(self.start_vertex))
                    else_ends_on_common_vtx = False
                    self.decompiler.write_stmnt(" else", False)
                    with Blk(self.decompiler):
                        # Handle else-branch
                        else_branch_handler = BlockWriteHandler(
                            else_edge.target_vertex,
                            self.decompiler,
                            self,
                            self.start_vertex,
                            check_end_block=self.check_end_block,
                        )
                        v_after_else_branch = else_branch_handler.write_content()

            # Those must be the same, either None or a common vertex
            # ... or either of them must end on a jump, then it's also okay if one of them is None but the other not.
            assert (
                not else_edge
                or else_ends_on_common_vtx
                or if_branch_handler.last_handler_in_block.ended_on_jump  # type: ignore
                or else_branch_handler.last_handler_in_block.ended_on_jump  # type: ignore
                or v_after_if_branch == v_after_else_branch
            ), f"Invalid if-structure for if {m.if_id}"

            if v_after_if_branch is None:
                return v_after_else_branch
            return v_after_if_branch

    def check_end_block(self, block: BlockWriteHandler, next_handler: AbstractWriteHandler) -> bool:
        """
        An if should end either if there are no vertices left (duh!) or if the end-if label is reached.
        This method also makes logical checks: No other if or switch or loop may be ended directly in this sub-block.
        """
        if isinstance(next_handler, LabelWriteHandler):
            lwh = next_handler

            if len(lwh.ended_ifs) > 0:
                if self.start_vertex["op"].get_marker().if_id in lwh.ended_ifs:
                    return False
                # else:
                #    raise ValueError("An unexpected if was ended while waiting for if to end.")

            # if len(lwh.ended_loops) > 0 or len(lwh.ended_switches) > 0:
            #    raise ValueError("An invalid switch or loop was ended while waiting for an if end.")
        return True

    def _if_header_for(self, op: SsbOperation) -> str:
        # TODO: More error checking for parameters would probably be a good idea
        if op.op_code.name == "Branch":
            return f"{op.params[0]} {SsbOperator.EQ.notation} {op.params[1]}"
        if op.op_code.name == "BranchBit":
            return f"{op.params[0]}[{op.params[1]}]"
        if op.op_code.name == "BranchDebug":
            if op.params[0] > 0:  # type: ignore
                return "debug"
            else:
                return "not debug"
        if op.op_code.name == "BranchEdit":
            if op.params[0] > 0:  # type: ignore
                return "edit"
            else:
                return "not edit"
        if op.op_code.name == "BranchExecuteSub":
            return f"BranchExecuteSub({', '.join([str(x) for x in op.params])})"
        if op.op_code.name == "BranchPerformance":
            n = "not " if op.params[1] < 1 else ""  # type: ignore
            return f"{n}{self.decompiler.performance_progress_list_var_name}[{op.params[0]}]"
        if op.op_code.name == "BranchScenarioNow":
            return f"scn({op.params[0]}) == [{op.params[1]}, {op.params[2]}]"
        if op.op_code.name == "BranchScenarioNowAfter":
            return f"scn({op.params[0]}) >= [{op.params[1]}, {op.params[2]}]"
        if op.op_code.name == "BranchScenarioNowBefore":
            return f"scn({op.params[0]}) <= [{op.params[1]}, {op.params[2]}]"
        if op.op_code.name == "BranchScenarioAfter":
            return f"scn({op.params[0]}) > [{op.params[1]}, {op.params[2]}]"
        if op.op_code.name == "BranchScenarioBefore":
            return f"scn({op.params[0]}) < [{op.params[1]}, {op.params[2]}]"
        if op.op_code.name == "BranchSum":
            return f"BranchSum({', '.join([str(x) for x in op.params])})"
        if op.op_code.name == "BranchValue":
            return f"{op.params[0]} {SsbOperator(op.params[1]).notation} {op.params[2]}"  # type: ignore
        if op.op_code.name == "BranchVariable":
            return f"{op.params[0]} {SsbOperator(op.params[1]).notation} value({op.params[2]})"  # type: ignore
        if op.op_code.name == "BranchVariation":
            if op.params[0] > 0:  # type: ignore
                return "variation"
            else:
                return "not variation"
        raise ValueError(f"Unknown if-operation {op.op_code.name}")

    def _build_else_if_chain(self, in_edge: Edge) -> Edge | None:
        """Starting from the in_edge try to build as many elseif constructs as possible."""
        op: SsbOperation = in_edge.target_vertex["op"]
        while isinstance(op, SsbLabelJump) and isinstance(op.get_marker(), IfStart):
            logger.debug("<%d> Handling else-if-block (%s)...", id(self.start_vertex), op)
            m = op.get_marker()
            assert isinstance(m, IfStart)
            if_edge, else_edge = self._write_if_header("elseif", op, in_edge.target_vertex, False)

            if else_edge == if_edge:
                # Great if!
                logger.debug("<%d> Empty else-if-block (%s).", id(self.start_vertex), op)
                with Blk(self.decompiler):
                    pass
                return None
            else:
                # If they are the same, we also need to print the else with a jump to it, so we need to make sure,
                # the label is wirrten!
                if else_edge.target == if_edge.target:
                    if isinstance(if_edge.target_vertex["op"], SsbLabel):
                        if_edge.target_vertex["op"].force_write = True

                with Blk(self.decompiler):
                    # Handle elseif-branch
                    BlockWriteHandler(
                        if_edge.target_vertex,
                        self.decompiler,
                        self,
                        self.start_vertex,
                        check_end_block=self.check_end_block,
                    ).write_content()
                next_vertex_ends = isinstance(else_edge.target_vertex["op"], SsbLabel) and any(
                    isinstance(mx, IfEnd) and m.if_id == mx.if_id for mx in else_edge.target_vertex["op"].markers
                )
                if else_edge.target == if_edge.target or not next_vertex_ends:
                    # this will lead to the opcodes be
                    assert in_edge != else_edge  # ???
                    in_edge = else_edge
                    op = in_edge.target_vertex["op"]
                elif next_vertex_ends:
                    # VERY IMPORTANT: If we already wrote this somewhere else, we NEED to write an else regardless,
                    # because we WON'T be printing it's opcodes next otherwise!
                    eop = else_edge.target_vertex["op"]
                    if isinstance(eop, SsbLabel) and eop.id in self.decompiler.labels_already_printed:
                        return else_edge
                    else:
                        return None
                else:
                    return None
        return in_edge

    def _write_if_header(
        self, header_str: str, op: SsbLabelJump, v: Vertex, include_newline_in_header: bool = True
    ) -> tuple[Edge, Edge]:
        m = op.get_marker()
        assert isinstance(m, IfStart)
        if isinstance(m, MultiIfStart):
            list_of_clauses = [self._if_header_for(s) for s in m.original_ssb_ifs_ops]
        else:
            list_of_clauses = [self._if_header_for(op.root)]

        exits = v.out_edges()

        self.decompiler.source_map_add_opcode(op.offset)
        opt_space = " " if not include_newline_in_header else ""
        not_str = "" if not m.is_not else " not"
        self.decompiler.write_stmnt(
            f"{opt_space}{header_str}{not_str} ( {' || '.join(list_of_clauses)} )", include_newline_in_header
        )
        else_edge = [e for e in exits if e["is_else"]][0]
        if_edge = [e for e in exits if not e["is_else"]][0]
        return if_edge, else_edge
