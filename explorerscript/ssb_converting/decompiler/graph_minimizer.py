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

from explorerscript.ssb_converting.decompiler.graph_utils import *
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, OPS_THAT_END_CONTROL_FLOW, SsbLabel, OP_HOLD, \
    OP_JUMP, OPS_BRANCH, IfStart, IfEnd, MultiIfStart, OPS_SWITCH_CASE_MAP, SwitchStart, OPS_CTX, SwitchEnd, \
    MultiSwitchStart, SwitchCaseOperation, SwitchFalltrough, ForeverContinue, ForeverBreak, ForeverStart


class ControlFlowToken(Enum):
    # Building the control flow was aborted, because after reaching the node before this token the flow loops
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
                v = g.add_vertex(i, label=None, op=op, style='solid', shape='ellipse')
                if isinstance(op, SsbLabel):
                    label_indices[op.id] = i
                self._update_vertex_style(v)
            self._get_edges(g, rtn, rtn_id, label_indices)

    def count_labels(self):
        # TODO
        return 0

    def get_control_flow(self) -> List[List[List[ControlFlowItem]]]:  # for each routine: for each run: list of cfi
        """
        Traverses the current graphs for each routine and returns possible control flows.
        Returns all possible control flows through a routine.

        The ssb operations in the list are the raw operations (not from ssb_special_ops). As such labels are also not
        included.

        This method can be used to check if the graph minimizing methods change the control flow (they shouldn't!)

        Return is a list of op_codes and some special tokens (see enum ControlFlowToken).
        """
        # TODO
        return None

    def optimize_paths(self):
        """Perform some general optimizations. To be run before any of the other graph changing methods."""
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
        Example to check: D01P11A/um2402.ssb
        - RULE: [Any, Label1, Jump[in=1,out=1], Label2] -> [Any, Label2]
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

    def build_branches(self):
        """
        Marks "ifs" in the graph, based on Branch* opcodes.
        Examples to check:
        - unionall 73 for if-only,
        - 10 for else-only,
        - 274 for if-else w tail,
        - 90 for if-else w tail [2] and if-only [3]
        - complex: 89
        """
        for i, g in enumerate(self._graphs):
            vs_to_delete = set()
            current_if_id = -1
            for v in g.vs:
                if isinstance(v['op'], SsbLabelJump) and v['op'].root.op_code.name in OPS_BRANCH.keys():
                    current_if_id += 1
                    # IS A BRANCH OPCODE
                    v['op'].add_marker(IfStart(current_if_id))
                    self._update_vertex_style(v)
                    else_edge, if_edge = find_lowest_and_highest_out_edge(g, v, 'flow_level')
                    assert else_edge != if_edge
                    else_edge['is_else'] = True
                    self._update_edge_style(else_edge)

                    # Common end label
                    result = find_first_common_next_vertex_in_edges(g, [if_edge, else_edge])
                    if result is not None:
                        e_on_if_bef_end, e_on_else_bef_end = result
                        end_vertex = e_on_if_bef_end.target_vertex
                        v_on_if_bef_end = e_on_if_bef_end.source_vertex
                        v_on_else_bef_end = e_on_else_bef_end.source_vertex
                        if not isinstance(end_vertex['op'], SsbLabel):
                            # There's no real end, but a loop. TODO: This could lead to real problems...
                            warnings.warn("If-Branch ended on a vertex that is not a label...")
                            continue
                        end_vertex['op'].add_marker(IfEnd(current_if_id))
                        self._update_vertex_style(end_vertex)

                        # Remove the jumps before the common end label (if they exist), we don't need them anymore.
                        if isinstance(v_on_if_bef_end['op'], SsbLabelJump) and v_on_if_bef_end['op'].root.op_code.name == OP_JUMP:
                            vs_to_delete.add(v_on_if_bef_end.index)
                            e_before_jump_on_if = g.es[g.incident(v_on_if_bef_end, IN)[0]]
                            self._reconnect(g, e_before_jump_on_if.source, e_before_jump_on_if, end_vertex)

                        if e_on_if_bef_end == e_on_else_bef_end:
                            # The common path of the two branches happens after the first actual stop, possibly
                            # because of an unfinished inner branch.
                            # TODO: This could lead to real problems...
                            warnings.warn("If-Branches ended via the same edge...")
                            continue

                        if isinstance(v_on_else_bef_end['op'], SsbLabelJump) and v_on_else_bef_end['op'].root.op_code.name == OP_JUMP:
                            vs_to_delete.add(v_on_else_bef_end.index)
                            e_before_jump_on_else = g.es[g.incident(v_on_else_bef_end, IN)[0]]
                            self._reconnect(g, e_before_jump_on_else.source, e_before_jump_on_else, end_vertex)

            g.delete_vertices(vs_to_delete)

    def group_branches(self):
        """
        Groups branches right next to each other in the else-path, that have the same if-path together (if x or y)
        Examples to check:
        - unionall 86 2+3

        Must be run after build_branches.
        """
        for i, g in enumerate(self._graphs):
            vs_to_delete = set()
            for v in g.vs:
                if isinstance(v['op'], SsbLabelJump) and isinstance(v['op'].get_marker(), IfStart) and v not in vs_to_delete:
                    # IS IF
                    else_edge = [e for e in v.out_edges() if e['is_else']][0]
                    if_edge = [e for e in v.out_edges() if not e['is_else']][0]
                    v_at_else = else_edge.target_vertex
                    if self._group_branches__is_if_group_possible(if_edge, v_at_else):
                        # Build an if-group
                        original_op_v = v['op']
                        original_op_v_at_else = v_at_else['op']
                        v_if_id = original_op_v.get_marker().if_id
                        v_at_else_if_id = original_op_v_at_else.get_marker().if_id
                        # v op:                         Turn into SsbMultiIfStart
                        #                               and add original v op and v_at_else op to original_ssb_ifs
                        original_op_v.remove_marker()
                        original_op_v.add_marker(MultiIfStart(v_if_id, [original_op_v.root, original_op_v_at_else.root]))
                        # Obfuscate original opcode name and remove root, to clarify that this is a special case
                        original_op_v.root = None
                        original_op_v.op_code.name = 'ES_MULTI_IF'
                        # v_at_else:                    Delete
                        vs_to_delete.add(v_at_else)
                        # v:                            Reconnect with else of v_at_else
                        v_at_else__else_edge = [e for e in v_at_else.out_edges() if e['is_else']][0]
                        self._reconnect(g, v, else_edge, v_at_else__else_edge.target_vertex)
                        # v op:                         Add original
                        # SsbEndIf for v_at_else:       Remove if id of v_at_else
                        end, marker_idx = find_first_label_vertex_with_marker_that_matches_condition(
                            g, lambda m: isinstance(m, IfEnd) and m.if_id == v_at_else_if_id
                        )
                        if end:
                            del end['op'].markers[marker_idx]
                            self._update_vertex_style(end)
                        self._update_vertex_style(v)
                        # Repeat for maybe other connected ifs:
                        else_edge = [e for e in v.out_edges() if e['is_else']][0]
                        if_edge = [e for e in v.out_edges() if not e['is_else']][0]
                        v_at_else = else_edge.target_vertex
                        while self._group_branches__is_if_group_possible(if_edge, v_at_else):
                            original_op_v_at_else = v_at_else['op']
                            v_at_else_if_id = original_op_v_at_else.get_marker().if_id
                            # v_at_else:                    Delete
                            vs_to_delete.add(v_at_else)
                            # v:                            Reconnect with else of v_at_else
                            v_at_else__else_edge = [e for e in v_at_else.out_edges() if e['is_else']][0]
                            self._reconnect(g, v, else_edge, v_at_else__else_edge.target_vertex)
                            # v op:                         Add v_at_else op to original_ssb_ifs
                            v['op'].get_marker().add_if(original_op_v_at_else.root)
                            # SsbEndIf for v_at_else:  Remove if id of v_at_else
                            end, marker_idx = find_first_label_vertex_with_marker_that_matches_condition(
                                g, lambda m: isinstance(m, IfEnd) and m.if_id == v_at_else_if_id
                            )
                            if end:
                                del end['op'].markers[marker_idx]
                                self._update_vertex_style(end)
                            self._update_vertex_style(v)
                            else_edge = [e for e in v.out_edges() if e['is_else']][0]
                            if_edge = [e for e in v.out_edges() if not e['is_else']][0]
                            v_at_else = else_edge.target_vertex

            g.delete_vertices(vs_to_delete)

    @staticmethod
    def _group_branches__is_if_group_possible(base_if_v__edge_if, v_to_check):
        if isinstance(v_to_check['op'], SsbLabelJump) and isinstance(v_to_check['op'].get_marker(), IfStart):
            v_to_check__edge_if = [e for e in v_to_check.out_edges() if not e['is_else']][0]
            return v_to_check__edge_if.target == base_if_v__edge_if.target
        return False

    def build_and_group_switch_cases(self):
        for i, g in enumerate(self._graphs):
            vs_to_delete = set()
            current_switch_id = -1
            for v in g.vs:
                if v['op'].op_code.name in OPS_SWITCH_CASE_MAP.keys() and v not in vs_to_delete:
                    current_switch_id += 1
                    # SWITCH
                    # -- FIRST: FINDING THE START POINTS
                    v['op'] = SsbLabelJump(v['op'], None)
                    v['op'].add_marker(SwitchStart(current_switch_id))
                    self._update_vertex_style(v)
                    # Collect all cases for this switch
                    possible_cases = OPS_SWITCH_CASE_MAP[v['op'].root.op_code.name]
                    out_edges = v.out_edges()
                    assert len(out_edges) == 1
                    next_vertex = out_edges[0].target_vertex
                    current_flow_attributes = out_edges[0].attributes()
                    case_i = -1
                    while next_vertex is not None and isinstance(next_vertex['op'], SsbLabelJump) \
                            and next_vertex['op'].root is not None \
                            and next_vertex['op'].root.op_code.name in possible_cases:
                        case_i += 1
                        else_edge, case_edge = find_lowest_and_highest_out_edge(g, next_vertex, 'flow_level')
                        if else_edge == case_edge:
                            else_edge = None
                        case_edge['switch_ops'] = [SwitchCaseOperation(0, case_i, next_vertex['op'].root)]
                        self._update_edge_style(case_edge)
                        # Connect switch with case_edge
                        self._reconnect(g, v, case_edge, case_edge.target_vertex, True)
                        #
                        if else_edge is not None:
                            else_edge_target_vertex = else_edge.target_vertex
                            g.delete_edges([case_edge.index, else_edge.index])
                        else:
                            else_edge_target_vertex = None
                            g.delete_edges(case_edge.index)
                        vs_to_delete.add(next_vertex)
                        next_vertex = else_edge_target_vertex
                    # Else edge:
                    if next_vertex is not None:
                        v_else_edge = next(e for e in v.out_edges() if e['switch_ops'] is None)
                        if not v_else_edge.target_vertex == next_vertex:
                            g.delete_edges(v_else_edge)
                            # Connect v with the end of the case chain
                            e = g.add_edge(v, next_vertex, **current_flow_attributes)
                            e['is_else'] = True
                            self._update_edge_style(e)
                        else:
                            v_else_edge['is_else'] = True
                            self._update_edge_style(v_else_edge)

                    # -- SECOND: FINDING THE END POINTS
                    # Common end label
                    if len(v.out_edges()) < 2:
                        continue
                    result = find_first_common_next_vertex_in_edges(g, v.out_edges())
                    if result is not None:
                        end_vertex = result[0].target_vertex
                        if not isinstance(end_vertex['op'], SsbLabel):
                            # There's no real end, but a loop. TODO: This could lead to real problems...
                            warnings.warn("Switch ended on a vertex that is not a label...")
                            continue
                        end_vertex['op'].add_marker(SwitchEnd(current_switch_id))
                        self._update_vertex_style(end_vertex)

                        already_updated_switch_end_in_edges = []
                        es_to_delete = []
                        for e in result:
                            if e in already_updated_switch_end_in_edges:
                                # The common path of the branches happens after the first actual stop, possibly
                                # because of an unfinished inner branch.
                                # TODO: This could lead to real problems...
                                warnings.warn("Switch-Branches ended via the same edge...")
                                continue

                            # Remove the jumps before the common end label (if they exist), we don't need them anymore.
                            if isinstance(e.source_vertex['op'], SsbLabelJump) and e.source_vertex['op'].root.op_code.name == OP_JUMP:
                                vs_to_delete.add(e.source_vertex.index)
                                e_before_jump = g.es[g.incident(e.source_vertex, IN)[0]]
                                es_to_delete.append(e_before_jump)
                                self._reconnect(g, e_before_jump.source, e_before_jump, end_vertex, True)
                        g.delete_edges(es_to_delete)

            g.delete_vertices(vs_to_delete)

    def group_switches(self):
        """
        Groups switches right next to each other in the else-path (multi switch)
        Examples to check:
        - unionall 11

        Must be run after build_and_group_switch_cases.
        """
        for i, g in enumerate(self._graphs):
            vs_to_delete = set()
            for v in g.vs:
                if isinstance(v['op'], SsbLabelJump) and isinstance(v['op'].get_marker(), SwitchStart) and v not in vs_to_delete:
                    # IS SWITCH
                    else_edge_candidates = [e for e in v.out_edges() if e['is_else']]
                    if len(else_edge_candidates) < 1:
                        continue
                    else_edge = else_edge_candidates[0]
                    v_at_else = else_edge.target_vertex
                    if self._group_branches__is_switch_group_possible(g, v, v_at_else):
                        # Build a switch-group
                        original_op_v = v['op']
                        original_op_v_at_else = v_at_else['op']
                        v_switch_id = original_op_v.get_marker().switch_id
                        # v op:                         Turn into SsbMultiSwitchStart
                        #                               and add original v op and v_at_else op to original_ssb_switches
                        original_op_v.remove_marker()
                        original_op_v.add_marker(MultiSwitchStart(v_switch_id, [original_op_v.root, original_op_v_at_else.root]))
                        # Obfuscate original opcode name and remove root, to clarify that this is a special case
                        original_op_v.root = None
                        original_op_v.op_code.name = 'ES_MULTI_SWITCH'
                        # v_at_else:                    Delete
                        vs_to_delete.add(v_at_else)
                        for e in v_at_else.out_edges():
                            # v:                            Reconnect with else of v_at_else
                            if e['is_else']:
                                self._reconnect(g, v, else_edge, e.target_vertex, True)
                            # v:                            Add all of the other switch cases:
                            else:
                                new_e = self._reconnect(g, v, e, e.target_vertex, True)
                                for op in new_e['switch_ops']:
                                    op.switch_index = 1
                                self._update_edge_style(new_e)
                        self._update_vertex_style(v)
                        # Repeat for maybe other connected switches:
                        g.delete_edges(else_edge)
                        else_edge = [e for e in v.out_edges() if e['is_else']][0]
                        v_at_else = else_edge.target_vertex
                        switch_index = 1
                        while self._group_branches__is_switch_group_possible(g, v, v_at_else):
                            switch_index += 1
                            original_op_v_at_else = v_at_else['op']
                            # v_at_else:                    Delete
                            vs_to_delete.add(v_at_else)
                            for e in v_at_else.out_edges():
                                # v:                            Reconnect with else of v_at_else
                                if e['is_else']:
                                    self._reconnect(g, v, else_edge, e.target_vertex, True)
                                # v:                            Add all of the other switch cases:
                                else:
                                    new_e = self._reconnect(g, v, e, e.target_vertex, True)
                                    for op in new_e['switch_ops']:
                                        op.switch_index = switch_index
                                    self._update_edge_style(new_e)
                            # v op:                         Add v_at_else op to original_ssb_switches
                            v['op'].get_marker().add_switch(original_op_v_at_else.root)
                            self._update_vertex_style(v)
                            g.delete_edges(else_edge)
                            else_edge = [e for e in v.out_edges() if e['is_else']][0]
                            v_at_else = else_edge.target_vertex

            g.delete_vertices(vs_to_delete)

    def _group_branches__is_switch_group_possible(self, g, base_switch: Vertex, v_to_check: Vertex):
        if isinstance(v_to_check['op'], SsbLabelJump) and isinstance(v_to_check['op'].get_marker(), SwitchStart):
            # Both switches need to have the same end
            a_end, _ = find_first_label_vertex_with_marker_that_matches_condition(
                g, lambda m: isinstance(m, SwitchEnd) and m.switch_id == base_switch['op'].get_marker().switch_id
            )
            b_end, b_marker_idx = find_first_label_vertex_with_marker_that_matches_condition(
                g, lambda m: isinstance(m, SwitchEnd) and m.switch_id == v_to_check['op'].get_marker().switch_id
            )
            if a_end == b_end and a_end is not None:
                # To save some time, also already remove the end marker for v_to_check:
                del b_end['op'].markers[b_marker_idx]
                self._update_vertex_style(b_end)
                return True
        return False

    def group_switch_cases(self):
        """Group cases of a switch or multi switch that jump to the same point"""
        for i, g in enumerate(self._graphs):
            es_to_delete = set()
            for v in g.vs:
                if isinstance(v['op'], SsbLabelJump) and isinstance(v['op'].get_marker(), SwitchStart):
                    # SWITCH. Let's see what cases can be combined
                    case_targets = {}
                    for e in v.out_edges():
                        if e.target not in case_targets:
                            case_targets[e.target] = []
                        case_targets[e.target].append(e)
                    for e_group in case_targets.values():
                        try:
                            first_e_idx = next(i_first_n_else for i_first_n_else, e in enumerate(e_group) if not e['is_else'])
                        except StopIteration:
                            # group only has an else
                            continue
                        first_e = e_group.pop(first_e_idx)
                        for rest_e in e_group:
                            es_to_delete.add(rest_e)
                            if rest_e['is_else']:
                                first_e['is_else'] = True
                            else:
                                first_e['switch_ops'] += rest_e['switch_ops']
                        self._update_edge_style(first_e)

            g.delete_edges(es_to_delete)

    def build_switch_fallthroughs(self):
        """
        Mark switch fallthroughs (ends of case branches lead to next case branch or default).
        Examples:
            - unionall 67 (1 and 15)
        """
        for i, g in enumerate(self._graphs):
            for v in g.vs:
                if isinstance(v['op'], SsbLabelJump) and isinstance(v['op'].get_marker(), SwitchStart):
                    es_already_processed = set()
                    if len(v.out_edges()) < 2:
                        continue
                    list_of_edges = [i[0] for i in iterate_switch_edges(v)]
                    for i, e in enumerate(list_of_edges):
                        if e in es_already_processed:
                            continue
                        es_already_processed.add(e)
                        possible_fallthrough_marker = e.target_vertex
                        if isinstance(possible_fallthrough_marker['op'], SsbLabel):
                            # Get incoming edges and trace back if one is from the previous switch case.
                            pfm_in_edges = possible_fallthrough_marker.in_edges()
                            if len(pfm_in_edges) == 2:
                                edge = next(pfme for pfme in pfm_in_edges if pfme != e)
                                e_others = reverse_find_edge(edge, lambda e: e['switch_ops'] is not None)
                                for e_other in e_others:
                                    if list_of_edges[i - 1] == e_other and e_other.source == v.index:
                                        possible_fallthrough_marker['op'].add_marker(SwitchFalltrough())
                                        # These falltrough situations may lead to wrong loop markings:
                                        self._update_vertex_style(possible_fallthrough_marker)
                                        break

    def build_loops(self):
        """
        Build loop like structures, with beginnings, loopings points (continues) and breaking points.
        Valid loops don't contain any half-started ifs/switches or subloops. They all either end with proper
        end markers or by continuing or breaking on every sub-branch.
        Uses BFS to also allow nested loops.
        """
        for i, g in enumerate(self._graphs):
            loop_id = -1
            vs_to_delete = set()
            if len(g.vs) < 1:
                continue
            for v in g.bfsiter(g.vs[0]):
                loop_edges = [e for e in v.in_edges() if e['loop']]
                if len(loop_edges) > 0:
                    # To this node jumps a loop. Check if we can build a proper forever-loop.
                    can_build, break_points, continue_points, redundant_jumps = self._build_loops__try_loop(v)
                    if can_build:
                        es_to_delete = set()
                        print(f">>>> FOUND LOOP IN {i}")
                        loop_id += 1
                        v['op'].add_marker(ForeverStart(loop_id))
                        self._update_vertex_style(v)
                        for loop_edge in break_points:
                            break_point = loop_edge.source_vertex
                            break_target = loop_edge.target_vertex
                            if break_point['op'].get_marker():
                                # TODO: Not done! To get the actual break points, find common next vertex
                                #       of all break points and then apply breakpoint status to all jumps before that.
                                #       (if there's only one just use that one)
                                #       If any of the jumps already has a marker or there is none, add a new one and mark it instead.
                                #       If no common end vertex can be found, fail for now.
                                # Already has a marker, add a new opcode in between
                                loop_edge_flow_level = loop_edge['flow_level']
                                actual_break_point = g.add_vertex(label=None, op=SsbLabelJump(break_point['op'], None), style='solid', shape='ellipse')
                                actual_break_point['op'].remove_marker()
                                actual_break_point['op'].add_marker(ForeverBreak(loop_id))
                                es_to_delete.add(loop_edge)
                                e = self._reconnect(g, break_point, loop_edge, actual_break_point, True)
                                e = g.add_edge(actual_break_point, break_target, flow_level=loop_edge_flow_level, label=None, is_else=False, switch_ops=None, loop=e['loop'])
                                self._update_edge_style(e)
                                self._update_vertex_style(actual_break_point)
                            else:
                                # Doesn't have a marker yet, mark as break
                                break_point['op'].add_marker(ForeverBreak(loop_id))
                                self._update_vertex_style(break_point)
                        for loop_edge in continue_points:
                            continue_point = loop_edge.source_vertex
                            if continue_point['op'].get_marker():
                                # Already has a marker, add a new opcode in between
                                loop_edge_flow_level = loop_edge['flow_level']
                                actual_continue_point = g.add_vertex(label=None, op=SsbLabelJump(continue_point['op'], None), style='solid', shape='ellipse')
                                actual_continue_point['op'].remove_marker()
                                actual_continue_point['op'].add_marker(ForeverContinue(loop_id))
                                es_to_delete.add(loop_edge)
                                e = self._reconnect(g, continue_point, loop_edge, actual_continue_point, True)
                                e['loop'] = False
                                e = g.add_edge(actual_continue_point, v, flow_level=loop_edge_flow_level, label=None, is_else=False, switch_ops=None, loop=True)
                                self._update_edge_style(e)
                                self._update_vertex_style(actual_continue_point)
                            else:
                                # Doesn't have a marker yet, mark as break
                                continue_point['op'].add_marker(ForeverContinue(loop_id))
                                self._update_vertex_style(continue_point)
                        for loop_edge in redundant_jumps:
                            redundant_jump = loop_edge.source_vertex
                            if len(redundant_jump.out_edges()) == 1 and redundant_jump['op'].get_marker() is None:
                                assert len(redundant_jump.in_edges()) == 1
                                before = redundant_jump.in_edges()[0].source_vertex
                                es_to_delete.add(loop_edge)
                                self._reconnect(g, before, loop_edge, v, True)
                                vs_to_delete.add(redundant_jump)
                        g.delete_edges(es_to_delete)

            g.delete_vertices(vs_to_delete)

    def _build_loops__try_loop(self, start: Vertex) -> Tuple[bool, Union[List[Edge], None], Union[List[Edge], None], Union[List[Edge], None]]:
        """
        Try to find a loopable section of the graph starting at v.
        If found, the second entry of the returned tuple contains breaking points and the third all required continue
        markers. The fourth contains a list of vertices that implicitly continue, they are redundant jumps and can
        be removed.
        """
        # Allow loops when all sub-structures are closed (either continue/implicit or break). Allow breaks
        # for ifs, if the other branch is also a break or a continue: and for switch if break is in else-path
        # and all other paths either end on break or continue. Ignore closed ifs and switches.
        # Print like this:
        #  - If | Break in if, either continue/break in else:
        #      forever:
        #        if x:
        #          break
        #        else:
        #          continue/break
        #        <NOTHING HERE>
        #  - If | Break in else, continue in if:
        #      forever:
        #        if x:
        #          ...
        #          continue
        #        break
        #  - Switch with break in default, all other continue [note that the break comes then AFTER the switch]:
        #      forever:
        #        switch:
        #          case A:
        #            continue
        #          case B:
        #            continue
        #        break

        # Continues are implicit if:
        # For if:
        #  - If does not have an end and all branches of the if continue
        # For switch:
        #  - Switch does not have an end and all branches of the switch continue
        # For regular control flow:
        #  - Always

        continues = []
        breaks = []
        redundant = []

        already_visited_vertices = set()

        possible, _, had_to_break_but_didnt = self._build_loops__recursion(
            start, start, already_visited_vertices, continues, breaks, redundant
        )
        if possible and not had_to_break_but_didnt:
            return True, breaks, continues, redundant
        return False, None, None, None

    def _build_loops__recursion(
            self, start: Vertex, v: Vertex, already_visited_vertices, continues, breaks, redundant
    ) -> Tuple[bool, bool, bool]:
        # TODO: Rewrite non-recursively.
        must_break_before = False
        already_visited_vertices.add(v)
        out_edges = v.out_edges()
        edges_continue = [False for _ in out_edges]
        an_edge_breaks = False
        possible_continues = []
        if len(out_edges) == 0:
            # This is a dead-end. There must be a break before this
            return True, False, True
        for i, out_edge in enumerate(out_edges):
            if out_edge['loop']:
                # This path will loop again. What to do?
                if out_edge.target_vertex == start:
                    # CONTINUE / IMPLICIT
                    edges_continue[i] = True
                    possible_continues.append(out_edge)
                elif isinstance(out_edge.target_vertex['op'], SsbLabel) and any(isinstance(m, ForeverStart) for m in out_edge.target_vertex['op'].markers):
                    # Crossing into another loop. Must be a break before.
                    return True, False, True
                elif out_edge.target_vertex in already_visited_vertices:
                    # Subloop loop point, ignore. Counts as a continue.
                    edges_continue[i] = True
                    continue
                else:
                    # Impossible looping jump outside the main loop, can't continue from here, there
                    # must be a break before.
                    return True, False, True
            else:
                # Proceed normally in the loop
                possible, all_will_continue_or_break, must_break_before = self._build_loops__recursion(
                    start, out_edge.target_vertex, already_visited_vertices, continues, breaks, redundant
                )
                if not possible:
                    return False, False, False
                if all_will_continue_or_break:
                    edges_continue[i] = True
        # Get break edge if all other edges are continues
        if any(edges_continue):
            for i, out_edge in enumerate(out_edges):
                if not edges_continue[i]:
                    # Check if this is a switch but we are not on the else branch (impossible)
                    if isinstance(v['op'], SsbLabelJump) and isinstance(v['op'].get_marker(), SwitchStart):
                        if not out_edge['is_else']:
                            return False, False, False
                    breaks.append(out_edge)
                    an_edge_breaks = True
                    must_break_before = False
        if an_edge_breaks or (isinstance(v['op'], SsbLabelJump) and v['op'].get_marker() is None):
            redundant += possible_continues
        else:
            continues += possible_continues

        return True, any(edges_continue), must_break_before

    def remove_label_markers(self):
        for i, g in enumerate(self._graphs):
            vs_to_delete = set()
            # First, let's delete all redundant jumps (actual OP_JUMPs that jump to opcodes with only one in edge)
            for v in g.vs:
                if isinstance(v['op'], SsbLabelJump) and v['op'].root is not None and v['op'].root.op_code.name == OP_JUMP:
                    in_edges = v.in_edges()
                    out_edges = v.out_edges()
                    if len(in_edges) != 0:
                        assert len(in_edges) == 1 and len(out_edges) == 1
                        v_before = in_edges[0].source_vertex
                        v_after = out_edges[0].target_vertex
                        if len(v_after.in_edges()) > 1:
                            # The jump target has multiple entry points, keep the jump
                            continue
                        e = self._reconnect(g, v_before, in_edges[0], v_after, True)
                        e['flow_level'] = e['flow_level'] + 1
                        self._update_edge_style(e)
                    vs_to_delete.add(v)
            g.delete_vertices(vs_to_delete)
            vs_to_delete = set()
            # Then delete all redundant labels (only one in edge)
            for v in g.vs:
                if isinstance(v['op'], SsbLabel):
                    in_edges = v.in_edges()
                    out_edges = v.out_edges()
                    if len(in_edges) == 0:
                        vs_to_delete.add(v)
                    elif len(in_edges) == 1:
                        assert len(out_edges) == 1
                        v_before = in_edges[0].source_vertex
                        v_after = out_edges[0].target_vertex
                        self._reconnect(g, v_before, in_edges[0], v_after, True)
                        vs_to_delete.add(v)
            g.delete_vertices(vs_to_delete)

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
                e = g.add_edge(op_code_idx - 1, op_code_idx, flow_level=0, label=None, is_else=False, switch_ops=None, loop=False)
                self._update_edge_style(e)
                v_op = g.vs[op_code_idx]['op']
                # Don't forget the labels
                if isinstance(v_op, SsbLabelJump) and v_op.label.routine_id == rtn_id and v_op.root.op_code.name != OP_JUMP:
                    is_loop = label_indices[v_op.label.id] < op_code_idx and len(g.incident(label_indices[v_op.label.id], IN)) > 0
                    g.add_edge(op_code_idx, label_indices[v_op.label.id], flow_level=1, label=None, is_else=False, switch_ops=None, loop=is_loop)
                    self._update_edge_style(e)
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
            e = g.add_edge(op_i, nxt, flow_level=flow_level, label=None, is_else=False, switch_ops=None, loop=False)
            if is_loop(g, g.vs[op_i], e):
                e['loop'] = True
            self._update_edge_style(e)
            self._get_edges__add_edge(g, rtn, rtn_id, label_indices, nxt, already_visited, flow_level)

    def _get_edges__get_next_for(self, rtn: List[SsbOperation], rtn_id: int, flow_level: int,
                                 label_indices: Dict[int, int], op_i: int) -> List[Tuple[int, int]]:
        """
        Returns a list of next opcodes to visit from this opcode and
        their flow level (flow_level for normal continue; flow_level + 1 for jump)
        """
        next_ops: List[Tuple[int, int]] = []

        previous_op = rtn[op_i - 1]
        # If the previous op is one of OPS_CTX, then the immediate control flow will not end,
        # even if we get one of OPS_THAT_END_CONTROL_FLOW.
        flow_can_not_end = previous_op.op_code.name in OPS_CTX
        op = rtn[op_i]
        real_op = op
        is_label_jump = False
        if isinstance(op, SsbLabelJump):
            real_op = op.root
            is_label_jump = True
        # If this is not a guaranteed jump or the last op_code in rtn, one possible branch is always just the next op:
        if len(rtn) > op_i + 1 and (flow_can_not_end or real_op.op_code.name not in OPS_THAT_END_CONTROL_FLOW):
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

    @classmethod
    def _reconnect(cls, g, old_vertex, old_vertex_edge_to_remove, new_vertex_to_connect, do_not_delete = False):
        attr = old_vertex_edge_to_remove.attributes()
        if not do_not_delete:
            g.delete_edges(old_vertex_edge_to_remove)
        e = g.add_edge(old_vertex, new_vertex_to_connect, **attr)
        cls._update_edge_style(e)
        return e

    @staticmethod
    def _update_vertex_style(v):
        v['label'] = f"<{v['name']}>{v['op'].op_code.name}"
        if isinstance(v['op'], SsbLabel):
            v['style'] = 'striped'
            v['fillcolor'] = '#B446E3'
            v['shape'] = 'rectangle'
            if len(v['op'].markers) > 0:
                marker_str = ""
                v['fillcolor'] = ''
                for marker in v['op'].markers:
                    if isinstance(marker, IfEnd):
                        v['fillcolor'] += '#A85400:'
                    elif isinstance(marker, SwitchEnd):
                        v['fillcolor'] += '#005F26:'
                    elif isinstance(marker, SwitchFalltrough):
                        v['fillcolor'] += '#8ABC82:'
                    elif isinstance(marker, ForeverStart):
                        v['fillcolor'] += '#00366D:'
                    marker_str += str(marker) + ";"
                marker_str = marker_str[:-1]
                v['fillcolor'] = v['fillcolor'][:-1]
                v['label'] += f" ({marker_str})"
        elif isinstance(v['op'], SsbLabelJump):
            v['style'] = 'filled'  # TODO: wedged not working...?
            v['fillcolor'] = '#38BCFF'
            v['shape'] = 'ellipse'
            if len(v['op'].markers) > 0:
                marker_str = ""
                v['fillcolor'] = ''
                for marker in v['op'].markers:
                    if isinstance(marker, MultiIfStart):
                        v['fillcolor'] += '#E3BF00:'
                    elif isinstance(marker, IfStart):
                        v['fillcolor'] += '#E36A00:'
                    elif isinstance(marker, MultiSwitchStart):
                        v['fillcolor'] += '#00BC5A:'
                    elif isinstance(marker, SwitchStart):
                        v['fillcolor'] += '#00BC3F:'
                    elif isinstance(marker, ForeverContinue):
                        v['fillcolor'] += '#0C00BC:'
                    elif isinstance(marker, ForeverBreak):
                        v['fillcolor'] += '#6694FF:'
                    marker_str += str(marker) + ";"
                marker_str = marker_str[:-1]
                v['fillcolor'] = v['fillcolor'][:-1]
                v['label'] += f" ({marker_str})"

    @staticmethod
    def _update_edge_style(e):
        e['color'] = 'black'
        e['label'] = str(e['flow_level'])
        if e['is_else']:
            e['label'] += ' <Else>'
        if e['loop']:
            e['color'] = 'red'
            e['label'] += ' <Loop>'
        if e['switch_ops'] is not None:
            for op in e['switch_ops']:
                e['label'] += f"\n[{op.switch_index}:{op.index}:{op.op.op_code.name}]"
