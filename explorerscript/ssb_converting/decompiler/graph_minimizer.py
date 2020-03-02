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

import warnings
from enum import Enum, auto
from typing import List, Union, Set, Dict, Tuple

from igraph import Graph, IN

from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, OPS_THAT_END_CONTROL_FLOW, SsbLabel, OP_HOLD


class ControlFlowToken(Enum):
    # Building the control flow was aborted, because after reaching the previous node the flow loops
    LOOP = auto()


ControlFlowItem = Union[SsbOperation, ControlFlowToken]


class SsbGraphMinimizer:
    def __init__(self, routine_ops: List[List[SsbOperation]]):
        self._graphs: List[Graph] = []
        for rtn_id, rtn in enumerate(routine_ops):
            g = Graph(directed=True)
            self._graphs.append(g)
            if len(rtn) < 1:
                # Should not happen
                continue
            # Map of label id -> id of opcode in routine
            label_indices: Dict[int, int] = {}
            for i, op in enumerate(rtn):
                g.add_vertex(i, label=f"<{i}>{op.op_code.name}", op=op)
                if isinstance(op, SsbLabel):
                    label_indices[op.id] = i
            self._get_edges(g, rtn, rtn_id, label_indices)

    def get_control_flow(self) -> List[List[List[ControlFlowItem]]]:  # for each routine: for each run: list of cfi
        """
        Traverses the current graphs for each routine and returns possible control flows.
        Returns all possible control flows through a routine.

        Return is a list of op_codes and some special tokens (see enum ControlFlowToken).
        """
        for i, graph in enumerate(self._graphs):
            with open(f'/home/marco/austausch/dev/skytemple/files/skytemple_files/script/ssb/dbg/dbg_output/graphs/{i}.dot', 'w') as f:
                graph.write_dot(f)
            unconnected_vertices = []
            for v in graph.vs:
                if len(list(v.all_edges())) < 1 and v['name'] != 0:
                    unconnected_vertices.append(v['label'])
            if len(unconnected_vertices) > 0:
                warnings.warn(f"Routine {i} has unconnected ops: {unconnected_vertices}")
        exit(1)

    def optimize_paths(self):
        pass

    def group_objs(self):
        pass

    def group_switch_cases(self):
        pass

    def group_switches(self):
        pass

    def group_branches(self):
        pass

    def build_loops(self):
        pass

    def remove_label_markers(self):
        pass

    def _get_edges(self, g: Graph, rtn: List[SsbOperation], rtn_id: int, label_indices: Dict[int, int]):
        """
        Get the edges for the graph g by a list of SsbOperations. Will branch at SsbLabelJumps.
        """
        already_visited = set()
        self._get_edges__add_edge(g, rtn, rtn_id, label_indices, 0, already_visited)

        # Also collect left-over opcodes at the very end of a routine. For some routines there seems to be code
        # at the end that SEEMS unreachable, but we collect it anyway and try connect it from reverse with the first
        # ending opcode we can find
        op_code_idx = len(rtn) - 1
        # Not applicable for one-instruction routines.
        while op_code_idx > 1:
            if len(list(g.incident(op_code_idx, IN))) < 1:
                g.add_edge(op_code_idx - 1, op_code_idx, flow_level=0, label=0)
                op_code_idx -= 1
            else:
                break

    def _get_edges__add_edge(self,
                             g: Graph, rtn: List[SsbOperation], rtn_id: int, label_indices: Dict[int, int],
                             op_i: int, already_visited: Set[int], flow_level=0):
        if op_i in already_visited:
            return  # Loop
        already_visited.add(op_i)
        for flow_level, nxt in self._get_edges__get_next_for(rtn, rtn_id, flow_level, label_indices, op_i):
            g.add_edge(op_i, nxt, flow_level=flow_level, label=flow_level)
            self._get_edges__add_edge(g, rtn, rtn_id, label_indices, nxt, already_visited, flow_level)

    def _get_edges__get_next_for(self, rtn: List[SsbOperation], rtn_id: int, flow_level: int,
                                 label_indices: Dict[int, int], op_i: int) -> List[Tuple[int, int]]:
        """
        Returns a list of next opcodes to visit from this opcode and
        their flow level (flow_level for normal continue; flow_level + 1 for jump)
        """
        next_ops: List[Tuple[int, int]] = []

        op = rtn[op_i]
        real_op = op
        is_label_jump = False
        if isinstance(op, SsbLabelJump):
            real_op = op.root
            is_label_jump = True
        # If this is not a guaranteed jump or the last op_code in rtn, one possible branch is always just the next op:
        if len(rtn) > op_i + 1 and real_op.op_code.name not in OPS_THAT_END_CONTROL_FLOW:
            next_ops.append((flow_level, op_i + 1))
        # If this is a label jump, we can also continue at the label
        if is_label_jump and op.label.routine_id == rtn_id:
            next_ops.append((flow_level + 1, label_indices[op.label.id]))

        # If this would be the end but we are "Hold", then MAYBE there's still a statement after use, which we should
        # include, see notes at constant.
        if real_op.op_code.name == OP_HOLD and len(rtn) > op_i + 1:
            if rtn[op_i + 1].op_code.name in OPS_THAT_END_CONTROL_FLOW:
                next_ops.append((flow_level, op_i + 1))

        return next_ops
