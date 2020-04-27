#  MIT License
#
#  Copyright (c) 2020 Parakoopa
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

from igraph import Vertex

from explorerscript.ssb_converting.decompiler.graph_building.graph_utils import iterate_switch_edges_using_edges_and_op
from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.block import BlockWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.label import LabelWriteHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, SwitchStart, MultiSwitchStart, \
    OPS_THAT_END_CONTROL_FLOW
from explorerscript.ssb_converting.util import Blk
from explorerscript.ssb_converting.ssb_data_types import SsbOperator


class SwitchWriteHandler(AbstractWriteHandler):
    """Handles writing ifs."""

    def __init__(self, start_vertex: Vertex, decompiler, parent):
        super().__init__(start_vertex, decompiler, parent)
        self.ended_on_jump = True

    def write_content(self):
        op: SsbLabelJump = self.start_vertex['op']
        m: SwitchStart = op.get_marker()
        multi = isinstance(m, MultiSwitchStart)
        self.decompiler.source_map_add_opcode(op.offset)
        if multi:
            self.decompiler.write_stmnt(
                f"multi switch ({', '.join([self._switch_header_for(s) for s in m.original_ssb_switch_ops])}):"
            )
        else:
            self.decompiler.write_stmnt(
                f"switch ({self._switch_header_for(op.root)})"
            )

        exits = self.start_vertex.out_edges()
        switch_end_vertices = set()
        edges_that_will_be_visited_multiple_times = set()
        already_printed_edges = set()

        if len(exits) == 1:
            # Not a real switch (empty body menu or special process)
            self.decompiler.write_stmnt(" { }", False)
            return exits[0].target_vertex
        elif len(exits) > 1:
            list_of_switch_cases = list(iterate_switch_edges_using_edges_and_op(exits, op))
            # Build a list of all edges that will be visited multiple times, make sure to generate a label for them
            for e, _, __ in list_of_switch_cases:
                if e in already_printed_edges:
                    edges_that_will_be_visited_multiple_times.add(e)
                already_printed_edges.add(e)
            already_printed_edges = set()  # reuse
            with Blk(self.decompiler):
                for e, switch_case_ops, is_default in list_of_switch_cases:
                    for sco in switch_case_ops:
                        if multi:
                            self.decompiler.source_map_add_opcode(sco.op.offset)
                            self.decompiler.write_stmnt(f"case {sco.switch_index}, {self._case_header_for(sco.op)}:")
                        else:
                            self.decompiler.write_stmnt(f"case {self._case_header_for(sco.op)}:")
                    if is_default:
                        self.decompiler.write_stmnt("default:")
                    with Blk(self.decompiler, False):
                        # If this will be visited multiple times, we need a label
                        if e in edges_that_will_be_visited_multiple_times and e not in already_printed_edges:
                            self.decompiler.write_stmnt(f"$switch{m.switch_id}_{e.index};")
                        if e in already_printed_edges:
                            # Write the label jump instead
                            self.decompiler.write_stmnt(f"jump @switch{m.switch_id}_{e.index};")
                        else:
                            already_printed_edges.add(e)
                            # Print a switch case branch
                            handler = BlockWriteHandler(
                                e.target_vertex, self.decompiler, self, self.start_vertex,
                                check_end_block=self.check_end_block
                            )
                            end_vertex = handler.write_content()
                            if not isinstance(handler.last_handler_in_block, LabelWriteHandler) or not handler.last_handler_in_block.switch_fell_through:
                                root_op_before = self._get_root_op(handler.last_vertex)
                                if not handler.last_handler_in_block.ended_on_jump and (root_op_before is None or root_op_before.op_code.name not in OPS_THAT_END_CONTROL_FLOW):
                                    self.decompiler.write_stmnt("break;")
                            # If this branch didn't end on a label jump: Add it's end vertex to the set of end vertices
                            if not handler.last_handler_in_block or not handler.last_handler_in_block.ended_on_jump:
                                switch_end_vertices.add(end_vertex)

            if len(switch_end_vertices) == 1:
                # End on the same end vertex, continue after.
                return switch_end_vertices.pop()

            return None

    def check_end_block(self, block: BlockWriteHandler, next_handler: AbstractWriteHandler):
        """
        A switch should end either if there are no vertices left (duh!) or if the end-switch label is reached.
        This method also makes logical checks: No other if or switch or loop may be ended directly in this sub-block.
        """
        if isinstance(next_handler, LabelWriteHandler):
            lwh = next_handler

            if len(lwh.ended_switches) > 0:
                if self.start_vertex['op'].get_marker().switch_id in lwh.ended_switches:
                    return False
                #else:
                #    raise ValueError("An unexpected switch was ended while waiting for switch to end.")

            #if len(lwh.ended_loops) > 0 or len(lwh.ended_ifs) > 0:
            #    raise ValueError("An invalid if or loop was ended while waiting for a switch end.")
        return True

    @staticmethod
    def _switch_header_for(op: SsbOperation):
        # TODO: More error checking for parameters would probably be a good idea
        if op.op_code.name in [
            'message_SwitchMenu', 'message_SwitchMenu2', 'SwitchDirection', 'SwitchDirectionLives',
            'SwitchDirectionLives2', 'SwitchDirectionMark', 'SwitchLives', 'SwitchValue', 'SwitchVariable',
            'main_EnterAdventure'
        ]:
            return f'{op.op_code.name}({", ".join([str(x) for x in op.params])})'
        if op.op_code.name == 'message_Menu':
            return f'special_menu({op.params[0]})'
        if op.op_code.name == 'ProcessSpecial':
            return f'special_process({op.params[0]})'
        if op.op_code.name == 'SwitchDungeonMode':
            return f'dungeon_mode({op.params[0]})'
        if op.op_code.name == 'SwitchRandom':
            return f'random({op.params[0]})'
        if op.op_code.name == 'SwitchScenario':
            return f'scn({op.params[0]})[0])'
        if op.op_code.name == 'SwitchScenarioLevel':
            return f'scn({op.params[0]})[1])'
        if op.op_code.name == 'SwitchSector':
            return f'sector()'
        if op.op_code.name == 'Switch':
            return f'{op.params[0]}'
        raise ValueError(f"Unknown switch {op.op_code.name}")

    def _case_header_for(self, op: SsbOperation):
        # TODO: More error checking for parameters would probably be a good idea
        if op.op_code.name == 'Case':
            return f'{op.params[0]}'
        if op.op_code.name == 'CaseMenu':
            if hasattr(op.params[0], 'indent'):
                op.params[0].indent = self.decompiler.indent
            return f'menu {op.params[0]}'
        if op.op_code.name == 'CaseMenu2':
            return f'CaseMenu2({", ".join([str(x) for x in op.params])})'
        if op.op_code.name == 'CaseScenario':
            # TODO: This will convert them into CaseValues. Might cause issues.
            return f'{SsbOperator(op.params[0]).notation} {op.params[1]}'
        if op.op_code.name == 'CaseValue':
            return f'{SsbOperator(op.params[0]).notation} {op.params[1]}'
        if op.op_code.name == 'CaseVariable':
            return f'{SsbOperator(op.params[0]).notation} value({op.params[1]})'
        raise ValueError(f"Unknown switch-case {op.op_code.name}")

    def _get_root_op(self, v):
        if v is None:
            return None
        if isinstance(v['op'], SsbLabelJump):
            return v['op'].root
        return v['op']
