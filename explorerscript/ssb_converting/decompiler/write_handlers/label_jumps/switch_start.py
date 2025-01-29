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

from explorerscript.ssb_converting.decompiler.graph_building.graph_utils import (
    iterate_switch_edges_using_edges_and_op,
    find_switch_end_label,
)
from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.block import BlockWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.label import LabelWriteHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_data_types import SsbOperator
from explorerscript.ssb_converting.ssb_special_ops import (
    SsbLabelJump,
    SwitchStart,
    OPS_THAT_END_CONTROL_FLOW,
    OP_SWITCH_DUNGEON_MODE,
)
from explorerscript.ssb_converting.util import Blk

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

logger = logging.getLogger(__name__)


class SwitchWriteHandler(AbstractWriteHandler):
    """Handles writing switches."""

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)
        self.ended_on_jump = True

    def write_content(self) -> Vertex | None:
        op: SsbLabelJump = self.start_vertex["op"]
        m = op.get_marker()
        assert isinstance(m, SwitchStart)
        self.decompiler.source_map_add_opcode(op.offset)
        self.decompiler.write_stmnt(f"switch ( {self._switch_header_for(op.root)} )")
        is_switch_dungeon_mode = op.root.op_code.name == OP_SWITCH_DUNGEON_MODE

        exits = self.start_vertex.out_edges()
        edges_that_will_be_visited_multiple_times = set()
        already_printed_edges = set()
        logger.debug("Handling a switch (%s)...", op)

        if len(exits) == 1 and (exits[0]["switch_ops"] is None or len(exits[0]["switch_ops"]) == 0):
            # Not a real switch (empty body menu or special process)
            logger.debug("switch was empty.")
            self.decompiler.write_stmnt(" { }", False)
            return exits[0].target_vertex
        else:
            list_of_switch_cases = list(iterate_switch_edges_using_edges_and_op(exits, op))
            # Build a list of all edges that will be visited multiple times, make sure to generate a label for them
            for e, _, __ in list_of_switch_cases:
                if e in already_printed_edges:
                    edges_that_will_be_visited_multiple_times.add(e)
                already_printed_edges.add(e)
            already_printed_edges = set()  # reuse
            with Blk(self.decompiler):
                logger.debug("Handling switch cases...")
                for e, switch_case_ops, is_default in list_of_switch_cases:
                    for sco in switch_case_ops:
                        logger.debug("Writing switch case (%s)...", sco)
                        self.decompiler.source_map_add_opcode(sco.op.offset)
                        self.decompiler.write_stmnt(f"case {self._case_header_for(sco.op, is_switch_dungeon_mode)}:")
                    if is_default:
                        logger.debug("Writing default...")
                        self.decompiler.write_stmnt("default:")
                    with Blk(self.decompiler, False):
                        logger.debug("... NOW block for cases.")
                        # If this will be visited multiple times, we need a label
                        if e in edges_that_will_be_visited_multiple_times and e not in already_printed_edges:
                            self.decompiler.write_stmnt(f"@switch{m.switch_id}_{e.index};")
                        if e in already_printed_edges:
                            # Write the label jump instead
                            self.decompiler.write_stmnt(f"jump @switch{m.switch_id}_{e.index};")
                        else:
                            already_printed_edges.add(e)
                            # Print a switch case branch
                            handler = BlockWriteHandler(
                                e.target_vertex,
                                self.decompiler,
                                self,
                                self.start_vertex,
                                check_end_block=self.check_end_block,
                            )
                            handler.write_content()
                            if (
                                not isinstance(handler.last_handler_in_block, LabelWriteHandler)
                                or not handler.last_handler_in_block.switch_fell_through
                            ):
                                root_op_before = self._get_root_op(handler.last_vertex)
                                assert handler.last_handler_in_block is not None
                                if not handler.last_handler_in_block.ended_on_jump and (
                                    root_op_before is None
                                    or root_op_before.op_code.name not in OPS_THAT_END_CONTROL_FLOW
                                ):
                                    self.decompiler.write_stmnt("break;")

            next_vertex = find_switch_end_label(self.start_vertex.graph, m.switch_id)
            if next_vertex:
                # End on the same end vertex, continue after.
                return next_vertex

            return None

    def check_end_block(self, block: BlockWriteHandler, next_handler: AbstractWriteHandler) -> bool:
        """
        A switch should end either if there are no vertices left (duh!) or if the end-switch label is reached.
        This method also makes logical checks: No other if or switch or loop may be ended directly in this sub-block.
        """
        if isinstance(next_handler, LabelWriteHandler):
            lwh = next_handler

            if len(lwh.ended_switches) > 0:
                if self.start_vertex["op"].get_marker().switch_id in lwh.ended_switches:
                    return False
                # else:
                #    raise ValueError("An unexpected switch was ended while waiting for switch to end.")

            # if len(lwh.ended_loops) > 0 or len(lwh.ended_ifs) > 0:
            #    raise ValueError("An invalid if or loop was ended while waiting for a switch end.")
        return True

    @staticmethod
    def _switch_header_for(op: SsbOperation) -> str:
        # TODO: More error checking for parameters would probably be a good idea
        if op.op_code.name in [
            "message_SwitchMenu",
            "message_SwitchMenu2",
            "SwitchDirection",
            "SwitchDirectionLives",
            "SwitchDirectionLives2",
            "SwitchDirectionMark",
            "SwitchLives",
            "SwitchValue",
            "SwitchVariable",
            "main_EnterAdventure",
            "main_EnterRescueUser",
            "main_EnterTraining",
            "main_EnterTraining2",
            "message_Menu",
            "ProcessSpecial",
        ]:
            return f"{op.op_code.name}({', '.join([str(x) for x in op.params])})"
        if op.op_code.name == OP_SWITCH_DUNGEON_MODE:
            return f"dungeon_mode({op.params[0]})"
        if op.op_code.name == "SwitchRandom":
            return f"random({op.params[0]})"
        if op.op_code.name == "SwitchScenario":
            return f"scn({op.params[0]})[0]"
        if op.op_code.name == "SwitchScenarioLevel":
            return f"scn({op.params[0]})[1]"
        if op.op_code.name == "SwitchSector":
            return "sector()"
        if op.op_code.name == "Switch":
            return f"{op.params[0]}"
        raise ValueError(f"Unknown switch {op.op_code.name}")

    def _case_header_for(self, op: SsbOperation, is_switch_dungeon_mode: bool) -> str:
        # TODO: More error checking for parameters would probably be a good idea
        if op.op_code.name == "Case":
            if is_switch_dungeon_mode:
                return f"{self.decompiler.dungeon_mode_constants.get_explorerscript_constant_for(op.params[0])}"  # type: ignore
            return f"{op.params[0]}"
        if op.op_code.name == "CaseMenu":
            if hasattr(op.params[0], "indent"):
                op.params[0].indent = self.decompiler.indent
            return f"menu({op.params[0]})"
        if op.op_code.name == "CaseMenu2":
            return f"menu2({op.params[0]})"
        if op.op_code.name == "CaseScenario":
            # TODO: This will convert them into CaseValues. Might cause issues.
            return f"{SsbOperator(op.params[0]).notation} {op.params[1]}"  # type: ignore
        if op.op_code.name == "CaseValue":
            return f"{SsbOperator(op.params[0]).notation} {op.params[1]}"  # type: ignore
        if op.op_code.name == "CaseVariable":
            return f"{SsbOperator(op.params[0]).notation} value({op.params[1]})"  # type: ignore
        raise ValueError(f"Unknown switch-case {op.op_code.name}")

    def _get_root_op(self, v: Vertex | None) -> SsbOperation | None:
        if v is None:
            return None
        if isinstance(v["op"], SsbLabelJump):
            return v["op"].maybe_root
        return v["op"]
