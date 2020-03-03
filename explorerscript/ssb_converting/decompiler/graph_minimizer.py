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
import sys
import warnings
from enum import Enum, auto
from typing import List, Union, Set, Dict, Tuple

from igraph import Graph, IN, OUT

from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, OPS_THAT_END_CONTROL_FLOW, SsbLabel, OP_HOLD, \
    OP_JUMP


class ControlFlowToken(Enum):
    # Building the control flow was aborted, because after reaching the previous node the flow loops
    LOOP = auto()


ControlFlowItem = Union[SsbOperation, ControlFlowToken]
sys.setrecursionlimit(10000)


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
                v = g.add_vertex(i, label=f"<{i}>{op.op_code.name}", op=op, style='solid', shape='ellipse')
                if isinstance(op, SsbLabel):
                    label_indices[op.id] = i
                    v['style'] = 'filled'
                    v['fillcolor'] = '#B446E3'
                    v['shape'] = 'rectangle'
                elif isinstance(op, SsbLabelJump):
                    v['style'] = 'filled'
                    v['fillcolor'] = '#38BCFF'
            self._get_edges(g, rtn, rtn_id, label_indices)

    def count_labels(self):
        # TODO
        return 0

    def get_control_flow(self) -> List[List[List[ControlFlowItem]]]:  # for each routine: for each run: list of cfi
        """
        Traverses the current graphs for each routine and returns possible control flows.
        Returns all possible control flows through a routine.

        Return is a list of op_codes and some special tokens (see enum ControlFlowToken).
        """
        exit(1)

    def optimize_paths(self):
        """Perform some general optimizations."""
        for g in self._graphs:
            vs_to_delete = []
            for v in g.vs:
                if isinstance(v['op'], SsbLabelJump) and v['op'].root.op_code.name == OP_JUMP:
                    # IS JUMP.
                    ins = g.incident(v, IN)
                    if len(ins) == 1:
                        iv = g.es[ins[0]].source_vertex
                        if isinstance(iv['op'], SsbLabel):
                            # IS JUMP AND BEFORE IS LABEL:
                            vs_to_delete += self._optimize_paths__jump_after_label(g, jump=v, label=iv)
            g.delete_vertices(vs_to_delete)

    def _optimize_paths__jump_after_label(self, g, jump, label):
        """
        Remove all connections to labels that just jump to another label,
        with direct connections to that label.
        """
        outs = g.incident(jump, OUT)
        assert len(outs) == 1
        ov = g.es[outs[0]].target_vertex
        if isinstance(ov['op'], SsbLabel):
            # The jump target is just another label, redirect previous label to this one.
            ins = g.incident(label, IN)
            for in_edge_id in ins:
                old_in_edge = g.es[in_edge_id]
                attr = old_in_edge.attributes()
                iv = old_in_edge.source
                # Create a new edge between the target label and the old entry point
                g.add_edge(iv, ov, **attr)
            g.delete_edges(ins)
            return [jump.index, label.index]
        return []

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
