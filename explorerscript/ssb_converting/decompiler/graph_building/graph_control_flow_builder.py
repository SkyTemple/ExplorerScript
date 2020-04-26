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

#  MIT License
#
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#
#
from enum import Enum, auto
from typing import Optional

from igraph import Graph, Vertex, Edge

from explorerscript.ssb_converting.decompiler.graph_building.graph_utils import find_lowest_and_highest_out_edge
from explorerscript.ssb_converting.ssb_special_ops import *


class ControlFlowToken(Enum):
    # Building the control flow was aborted, because by reaching the node before this LOOP token, the flow loops
    LOOP = auto()


ControlFlowItem = Union[SsbOperation, ControlFlowToken]


class GraphControlFlowBuilder:
    """A class to check that ExplorerScript graphs are optimized correctly."""
    def __init__(self, g: Graph):
        self.g = g

    def get_flow(self) -> List[List[ControlFlowItem]]:  # for each flow: list of cfi
        """
        Traverses the graph and returns possible operation control flows. The graph is processed using DFS.

        The ssb operations in the list are the raw operations (not from ssb_special_ops). As such labels are also not
        included.

        Return is a list of op_codes and some special tokens (see enum ControlFlowToken).
        """
        built_flows = []
        # start with the root
        branch_stack: List[ControlFlowBranch] = [ControlFlowBranch(self.g.vs[0], None, [], [])]
        while len(branch_stack) > 0:
            current = branch_stack.pop()

            force_end_after_this = current.check_loop()

            if isinstance(current.v['op'], SsbLabelJump):
                marker = current.v['op'].get_marker()
                # IF AND MULTI IF
                if isinstance(marker, MultiIfStart) or isinstance(marker, IfStart):
                    else_edge, if_edge = find_lowest_and_highest_out_edge(current.v.graph, current.v, 'flow_level')
                    if isinstance(marker, MultiIfStart):
                        branch_ops_to_process_for = marker.original_ssb_ifs_ops
                    else:
                        branch_ops_to_process_for = [current.v['op']]
                    for if_op in branch_ops_to_process_for:
                        # Add branch OP to flow
                        current.flow_to_here.append(self._normalized_op(if_op.root))
                        # Continue with if and else edges
                        nxt = []
                        self._next_for_out_edge(nxt, current.copy(), if_edge, force_end_after_this)
                        if else_edge != if_edge:
                            self._next_for_out_edge(nxt, current.copy(), else_edge, force_end_after_this)
                        branch_stack = nxt + branch_stack
                elif isinstance(marker, MultiSwitchStart):
                    pass  # todo - collect switch statements and their cases, using iterate_switch_edges, copy, continue in order
                elif isinstance(marker, SwitchStart):
                    pass  # todo - collect switch and it's cases, using iterate_switch_edges, copy, continue in order
                else:  # regular label jump / ForeverContinue / ForeverBreak
                    # Ignore.
                    nxt = self._next(current, force_end_after_this)
                    assert len(nxt) == 1
                    branch_stack += nxt
            elif isinstance(current.v['op'], SsbLabel) or isinstance(current.v['op'], SsbForeignLabel):
                # We never care about labels, just continue
                nxt = self._next(current, force_end_after_this)
                assert len(nxt) == 1
                branch_stack = nxt + branch_stack
            else:  # regular operation
                current.flow_to_here.append(self._normalized_op(current.v['op']))
                nxt = self._next(current, force_end_after_this)
                assert len(nxt) < 2
                branch_stack = nxt + branch_stack

            if force_end_after_this:
                # Mark this as a loop
                current.flow_to_here.append(ControlFlowToken.LOOP)
            if force_end_after_this or current.has_ended():
                # Collect leaves
                built_flows.append(current.flow_to_here)
        return built_flows


class ControlFlowBranch:
    """A single branch of control flow (or more accurately, the current 'pointer' to it's head."""
    def __init__(self, v: Optional[Vertex], in_e: Optional[Edge],
                 flow_to_here: List[ControlFlowItem], already_visited: List[int]):
        self.v = v
        self.in_e = in_e
        self.flow_to_here = flow_to_here
        self.already_visited = already_visited

    def copy(self):
        """Creates a copy; the new instance will have a copy of flow_to_here and already_visited."""
        return ControlFlowBranch(
            self.v, self.in_e, self.flow_to_here.copy(), self.already_visited.copy()
        )

    def has_ended(self):
        return self.v is None

    def check_loop(self):
        """Checks for a loop. Can only be called once per v, because it also updates the list of visited."""
        is_in = self.v.index in self.already_visited
        if not is_in:
            self.already_visited.append(self.v.index)
        return is_in
