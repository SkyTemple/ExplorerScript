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
import sys
from typing import TYPE_CHECKING
from collections.abc import Sequence

from igraph import IN, Edge, OUT, Vertex, Graph

from explorerscript.ssb_converting.decompiler.graph_building.graph_utils import (
    any_incoming_edge_is_loop,
    find_first_common_next_vertex_in_edges,
    find_first_common_next_vertex_in_edges__clear_cache,
    find_first_label_vertex_with_marker_that_matches_condition,
    find_lowest_and_highest_out_edge,
    get_all_vertices_between,
    get_out_edges_of_subgraph,
    has_unclosed_blocks,
    is_loop,
    is_reachable_when_removing,
    iterate_switch_edges,
    reverse_find_edge,
)
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import (
    SsbLabelJump,
    OPS_THAT_END_CONTROL_FLOW,
    SsbLabel,
    OP_HOLD,
    OP_JUMP,
    OPS_BRANCH,
    IfStart,
    IfEnd,
    MultiIfStart,
    OPS_SWITCH_CASE_MAP,
    SwitchStart,
    OPS_CTX,
    SwitchEnd,
    SwitchCaseOperation,
    SwitchFalltrough,
    ForeverContinue,
    ForeverBreak,
    ForeverStart,
    ForeverEnd,
    SsbForeignLabel,
    CallJump,
    OPS_THAT_WILL_JUMP_GUARANTEED,
)

logger = logging.getLogger(__name__)

sys.setrecursionlimit(10000)


class SsbGraphMinimizer:
    def __init__(self, routine_ops: Sequence[Sequence[SsbOperation]], optimize_ending_opcodes: bool = True):
        self._graphs: list[Graph] = []
        self.optimize_ending_opcodes = optimize_ending_opcodes
        for rtn_id, rtn in enumerate(routine_ops):
            g = Graph(directed=True)
            self._graphs.append(g)
            if len(rtn) < 1:
                # Should not happen
                continue
            # Map of label id -> id of opcode in routine
            label_indices: dict[int, int] = {}
            for i, op in enumerate(rtn):
                v = g.add_vertex(f"v{i}", label=None, op=op, style="solid", shape="ellipse")
                if isinstance(op, SsbLabel):
                    label_indices[op.id] = i
                self._update_vertex_style(v)
            self._get_edges(g, rtn, rtn_id, label_indices)

    def count_labels(self) -> int:
        """Count labels without markers (real labels)"""
        count = 0
        for g in self._graphs:
            for v in g.vs:
                if isinstance(v["op"], SsbLabel) and len(v["op"].markers) == 0:
                    count += 1
        return count

    def optimize_paths(self) -> None:
        """Perform some general optimizations. To be run before any of the other graph changing methods."""
        logger.debug("Optimizing paths...")
        for g in self._graphs:
            vs_to_delete = []
            for v in g.vs:
                if isinstance(v["op"], SsbLabelJump) and v["op"].root.op_code.name == OP_JUMP:
                    # IS JUMP.
                    ins = g.incident(v, IN)
                    if len(ins) == 1:
                        iv = g.es[ins[0]].source_vertex
                        if isinstance(iv["op"], SsbLabel):
                            # IS JUMP AND BEFORE IS LABEL:
                            vs_to_delete += self._optimize_paths__jump_after_label(g, jump=v, label=iv)
            g.delete_vertices(vs_to_delete)

    def _optimize_paths__jump_after_label(self, g: Graph, jump: Vertex, label: Vertex) -> list[int]:
        """
        Remove all connections to labels that just jump to another label,
        with direct connections to that label.
        Example to check: D01P11A/um2402.ssb
        - RULE: [Any, Label1, Jump[in=1,out=1], Label2] -> [Any, Label2]
        """
        outs = g.incident(jump, OUT)
        assert len(outs) == 1
        ov = g.es[outs[0]].target_vertex
        if isinstance(ov["op"], SsbLabel):
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

    def build_branches(self) -> None:
        """
        Marks "ifs" in the graph, based on Branch* opcodes.
        Examples to check:
        - unionall 73 for if-only,
        - 10 for else-only,
        - 274 for if-else w tail,
        - 90 for if-else w tail [2] and if-only [3]
        - complex: 89
        """
        logger.debug("Building branches...")
        for i, g in enumerate(self._graphs):
            vs_to_delete = set()
            current_if_id = -1
            for v in g.vs:
                if isinstance(v["op"], SsbLabelJump) and v["op"].root.op_code.name in OPS_BRANCH.keys():
                    current_if_id += 1
                    # IS A BRANCH OPCODE
                    try:
                        else_edge, if_edge = find_lowest_and_highest_out_edge(g, v, "flow_level")
                    except ValueError:
                        logger.warning(f"If without edges: {v}")
                        continue
                    assert else_edge != if_edge
                    v["op"].add_marker(IfStart(current_if_id))
                    self._update_vertex_style(v)
                    else_edge["is_else"] = True
                    self._update_edge_style(else_edge)

                    # Common end label
                    find_first_common_next_vertex_in_edges__clear_cache(g)  # TODO: Cache seems to be broken atm.
                    result = find_first_common_next_vertex_in_edges(g, [if_edge, else_edge])
                    if result is not None:
                        e_on_if_bef_end, e_on_else_bef_end = result
                        end_vertex = e_on_if_bef_end.target_vertex
                        v_on_if_bef_end = e_on_if_bef_end.source_vertex
                        v_on_else_bef_end = e_on_else_bef_end.source_vertex
                        if not isinstance(end_vertex["op"], SsbLabel):
                            # There's no real end, but a loop. TODO: This could lead to real problems...
                            logger.warning("If-Branch ended on a vertex that is not a label...")
                            continue
                        end_vertex["op"].add_marker(IfEnd(current_if_id))
                        self._update_vertex_style(end_vertex)

                        # Remove the jumps before the common end label (if they exist), we don't need them anymore.
                        if (
                            isinstance(v_on_if_bef_end["op"], SsbLabelJump)
                            and v_on_if_bef_end["op"].root.op_code.name == OP_JUMP
                        ):
                            vs_to_delete.add(v_on_if_bef_end.index)
                            in_edges = v_on_if_bef_end.in_edges()
                            if len(in_edges) > 0:  # TODO: Why is this < 1 sometimes? This really shouldn't happen...?
                                e_before_jump_on_if = in_edges[0]
                                self._reconnect(g, e_before_jump_on_if.source, e_before_jump_on_if, end_vertex)

                        if e_on_if_bef_end == e_on_else_bef_end:
                            # The common path of the two branches happens after the first actual stop, possibly
                            # because of an unfinished inner branch.
                            # TODO: This could lead to real problems...
                            logger.warning("If-Branches ended via the same edge...")
                            continue

                        if (
                            isinstance(v_on_else_bef_end["op"], SsbLabelJump)
                            and v_on_else_bef_end["op"].root.op_code.name == OP_JUMP
                        ):
                            vs_to_delete.add(v_on_else_bef_end.index)
                            in_edges = v_on_else_bef_end.in_edges()
                            if len(in_edges) > 0:  # TODO: Why is this < 1 sometimes? This really shouldn't happen...?
                                e_before_jump_on_else = in_edges[0]
                                self._reconnect(g, e_before_jump_on_else.source, e_before_jump_on_else, end_vertex)

            g.delete_vertices(vs_to_delete)

    def invert_branches(self) -> None:
        """
        Invert if-start marker (mark them as not and switch the else/if branches), if the if-branch is
        currently empty.

        Must be run after build_branches.
        """
        logger.debug("Searching for inverted branches...")
        for i, g in enumerate(self._graphs):
            vs_to_delete: set[Vertex] = set()
            for v in g.vs:
                if (
                    isinstance(v["op"], SsbLabelJump)
                    and isinstance(v["op"].get_marker(), IfStart)
                    and v not in vs_to_delete
                ):
                    # IS IF
                    marker = v["op"].get_marker()
                    if TYPE_CHECKING:
                        assert marker is not None and isinstance(marker, IfStart)
                    if_id = marker.if_id
                    else_edge = [e for e in v.out_edges() if e["is_else"]][0]
                    if_edge = [e for e in v.out_edges() if not e["is_else"]][0]
                    v_at_if = if_edge.target_vertex
                    # If both edges end at the same vertex, inverting doesn't really make sense
                    if if_edge.target == else_edge.target:
                        continue
                    if isinstance(v_at_if["op"], SsbLabel) and any(
                        isinstance(m, IfEnd) and m.if_id == if_id for m in v_at_if["op"].markers
                    ):
                        # Else ends directly at end of if-branch. Swap!
                        else_edge["is_else"] = False
                        if_edge["is_else"] = True
                        marker.is_not = True
                        self._update_edge_style(else_edge)
                        self._update_edge_style(if_edge)
                        self._update_vertex_style(v)

    def group_branches(self) -> None:
        """
        Groups branches right next to each other in the else-path, that have the same if-path together (if x or y)
        Examples to check:
        - unionall 86 2+3

        Must be run after build_branches.
        """
        logger.debug("Grouping branches...")
        for i, g in enumerate(self._graphs):
            vs_to_delete = set()
            for v in g.vs:
                if (
                    isinstance(v["op"], SsbLabelJump)
                    and isinstance(v["op"].get_marker(), IfStart)
                    and v not in vs_to_delete
                ):
                    # IS IF
                    else_edge = [e for e in v.out_edges() if e["is_else"]][0]
                    if_edge = [e for e in v.out_edges() if not e["is_else"]][0]
                    v_at_else = else_edge.target_vertex
                    first_run = True
                    while self._group_branches__is_if_group_possible(if_edge, v_at_else):
                        # Build an if-group
                        original_op_v: SsbLabelJump = v["op"]
                        original_op_v_at_else = v_at_else["op"]
                        marker = original_op_v.get_marker()
                        if TYPE_CHECKING:
                            assert marker is not None and isinstance(marker, IfStart)
                        v_if_id = marker.if_id
                        v_at_else_if_id = original_op_v_at_else.get_marker().if_id
                        if first_run:
                            # v op:                         Turn into SsbMultiIfStart
                            #                               and add original v op and v_at_else op to original_ssb_ifs
                            original_op_v.remove_marker()
                            original_op_v.add_marker(
                                MultiIfStart(v_if_id, [original_op_v.root, original_op_v_at_else.root])
                            )
                            # Obfuscate original opcode name and remove root, to clarify that this is a special case
                            original_op_v.unset_root()
                            original_op_v.op_code.name = "ES_OR_MULTI_IF"
                            first_run = False
                        else:
                            marker_multi = v["op"].get_marker()
                            assert marker_multi is not None and isinstance(marker_multi, MultiIfStart)
                            # v op:                         Add v_at_else op to original_ssb_ifs
                            marker_multi.add_if(original_op_v_at_else.root)
                        # v_at_else:                    Delete
                        vs_to_delete.add(v_at_else)
                        # v:                            Reconnect with else of v_at_else
                        v_at_else__else_edge = [e for e in v_at_else.out_edges() if e["is_else"]][0]
                        self._reconnect(g, v, else_edge, v_at_else__else_edge.target_vertex)
                        # SsbEndIf for v_at_else:       Remove if id of v_at_else
                        end, marker_idx = find_first_label_vertex_with_marker_that_matches_condition(
                            g, lambda m: isinstance(m, IfEnd) and m.if_id == v_at_else_if_id
                        )
                        if end:
                            del end["op"].markers[marker_idx]
                            self._update_vertex_style(end)
                        self._update_vertex_style(v)
                        # Repeat for maybe other connected ifs:
                        else_edge = [e for e in v.out_edges() if e["is_else"]][0]
                        if_edge = [e for e in v.out_edges() if not e["is_else"]][0]
                        v_at_else = else_edge.target_vertex

            g.delete_vertices(vs_to_delete)

    @staticmethod
    def _group_branches__is_if_group_possible(base_if_v__edge_if: Edge, v_to_check: Vertex) -> bool:
        if isinstance(v_to_check["op"], SsbLabelJump) and isinstance(v_to_check["op"].get_marker(), IfStart):
            v_to_check__edge_if = [e for e in v_to_check.out_edges() if not e["is_else"]][0]
            return v_to_check__edge_if.target == base_if_v__edge_if.target
        return False

    def build_and_group_switch_cases(self) -> None:
        logger.debug("Building switches...")
        for i, g in enumerate(self._graphs):
            vs_to_delete: set[Vertex | int] = set()
            current_switch_id = -1
            for v in g.vs:
                if v["op"].op_code.name in OPS_SWITCH_CASE_MAP.keys() and v not in vs_to_delete:
                    current_switch_id += 1
                    # SWITCH
                    out_edges = v.out_edges()
                    if len(out_edges) == 0:
                        logger.warning(f"Warning: A switch was not connected: {v['label']}.")
                        continue
                    # -- FIRST: FINDING THE START POINTS
                    v["op"] = SsbLabelJump(v["op"], None)
                    v["op"].add_marker(SwitchStart(current_switch_id))
                    self._update_vertex_style(v)
                    # Collect all cases for this switch
                    possible_cases = OPS_SWITCH_CASE_MAP[v["op"].root.op_code.name]
                    next_vertex: Vertex | None = out_edges[0].target_vertex
                    current_flow_attributes = out_edges[0].attributes()
                    case_i = -1
                    while (
                        next_vertex is not None
                        and isinstance(next_vertex["op"], SsbLabelJump)
                        and next_vertex["op"].maybe_root is not None
                        and next_vertex["op"].root.op_code.name in possible_cases
                    ):
                        case_i += 1
                        else_edge: Edge | None
                        else_edge, case_edge = find_lowest_and_highest_out_edge(g, next_vertex, "flow_level")
                        if else_edge == case_edge:
                            else_edge = None
                        case_edge["switch_ops"] = [SwitchCaseOperation(0, case_i, next_vertex["op"].root)]
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
                        v_else_edge = next(e for e in v.out_edges() if e["switch_ops"] is None)
                        if not v_else_edge.target_vertex == next_vertex:
                            g.delete_edges(v_else_edge)
                            # Connect v with the end of the case chain
                            e = g.add_edge(v, next_vertex, **current_flow_attributes)
                            e["is_else"] = True
                            self._update_edge_style(e)
                        else:
                            v_else_edge["is_else"] = True
                            self._update_edge_style(v_else_edge)

                    # -- SECOND: FINDING THE END POINTS
                    # Common end label
                    if len(v.out_edges()) < 2:
                        continue
                    result = find_first_common_next_vertex_in_edges(g, v.out_edges())
                    if result is not None:
                        end_vertex = result[0].target_vertex
                        if not isinstance(end_vertex["op"], SsbLabel):
                            # There's no real end, but a loop. TODO: This could lead to real problems...
                            logger.warning("Switch ended on a vertex that is not a label...")
                            continue
                        end_vertex["op"].add_marker(SwitchEnd(current_switch_id))
                        self._update_vertex_style(end_vertex)

                        already_updated_switch_end_in_edges = []
                        es_to_delete = []
                        for e in result:
                            if e in already_updated_switch_end_in_edges:
                                # The common path of the branches happens after the first actual stop, possibly
                                # because of an unfinished inner branch.
                                # TODO: This could lead to real problems...
                                logger.warning("Switch-Branches ended via the same edge...")
                                find_first_common_next_vertex_in_edges__clear_cache(g)
                                continue
                            already_updated_switch_end_in_edges.append(e)
                            # Remove the jumps before the common end label (if they exist), we don't need them anymore.
                            if (
                                isinstance(e.source_vertex["op"], SsbLabelJump)
                                and e.source_vertex["op"].maybe_root is not None
                                and e.source_vertex["op"].root.op_code.name == OP_JUMP
                            ):
                                vs_to_delete.add(e.source_vertex.index)
                                e_before_jump = g.es[g.incident(e.source_vertex, IN)[0]]
                                es_to_delete.append(e_before_jump)
                                self._reconnect(g, e_before_jump.source, e_before_jump, end_vertex, True)
                        g.delete_edges(es_to_delete)
                    find_first_common_next_vertex_in_edges__clear_cache(g)

            g.delete_vertices(vs_to_delete)

    def group_switch_cases(self) -> None:
        """Group cases of a switch or multi switch that jump to the same point"""
        logger.debug("Grouping switches...")
        for i, g in enumerate(self._graphs):
            es_to_delete = set()
            for v in g.vs:
                if isinstance(v["op"], SsbLabelJump) and isinstance(v["op"].get_marker(), SwitchStart):
                    # SWITCH. Let's see what cases can be combined
                    case_targets: dict[int, list[Edge]] = {}
                    for e in v.out_edges():
                        if e.target not in case_targets:
                            case_targets[e.target] = []
                        case_targets[e.target].append(e)
                    for e_group in case_targets.values():
                        try:
                            first_e_idx = next(
                                i_first_n_else for i_first_n_else, e in enumerate(e_group) if not e["is_else"]
                            )
                        except StopIteration:
                            # group only has an else
                            continue
                        first_e = e_group.pop(first_e_idx)
                        for rest_e in e_group:
                            es_to_delete.add(rest_e)
                            if rest_e["is_else"]:
                                first_e["is_else"] = True
                            else:
                                first_e["switch_ops"] += rest_e["switch_ops"]
                        self._update_edge_style(first_e)

            g.delete_edges(es_to_delete)
            if len(es_to_delete) > 0:
                find_first_common_next_vertex_in_edges__clear_cache(g)

    def build_switch_fallthroughs(self) -> None:
        """
        Mark switch fallthroughs (ends of case branches lead to next case branch or default).
        Examples:
            - unionall 67 (1 and 15)
        """
        logger.debug("Building switch fallthroughs...")
        for i, g in enumerate(self._graphs):
            for v in g.vs:
                if isinstance(v["op"], SsbLabelJump) and isinstance(v["op"].get_marker(), SwitchStart):
                    es_already_processed = set()
                    if len(v.out_edges()) < 2:
                        continue
                    list_of_edges = [i[0] for i in iterate_switch_edges(v)]
                    for i, e in enumerate(list_of_edges):
                        if e in es_already_processed:
                            continue
                        es_already_processed.add(e)
                        possible_fallthrough_marker = e.target_vertex
                        if isinstance(possible_fallthrough_marker["op"], SsbLabel):
                            # If this label already has a switch end marker for this switch, it's
                            # obviously no fallthrough situation...
                            v_marker = v["op"].get_marker()
                            if TYPE_CHECKING:
                                assert v_marker is not None and isinstance(v_marker, SwitchStart)
                            if any(
                                [
                                    isinstance(m, SwitchEnd) and m.switch_id == v_marker.switch_id
                                    for m in possible_fallthrough_marker["op"].markers
                                ]
                            ):
                                continue
                            # Get incoming edges and trace back if one is from the previous switch case.
                            pfm_in_edges = possible_fallthrough_marker.in_edges()
                            if len(pfm_in_edges) == 2:
                                edge = next(pfme for pfme in pfm_in_edges if pfme != e)
                                e_others = reverse_find_edge(edge, lambda e: e["switch_ops"] is not None)
                                for e_other in e_others:
                                    if list_of_edges[i - 1] == e_other and e_other.source == v.index:
                                        # If this branch opens and ifs/loops/switches but doesn't close them,
                                        # we can not turn this into a fallthrough.
                                        if has_unclosed_blocks(g.get_shortest_paths(e_other.source, edge.target), g):
                                            continue
                                        possible_fallthrough_marker["op"].add_marker(SwitchFalltrough())
                                        # These falltrough situations may lead to wrong loop markings:
                                        self._update_vertex_style(possible_fallthrough_marker)
                                        break

    def build_loops(self) -> None:
        """
        Build loop like structures, with beginnings, loopings points (continues) and breaking points.
        Valid loops don't contain any half-started ifs/switches or subloops. They all either end with proper
        end markers or by continuing or breaking on every sub-branch.
        Uses BFS to also allow nested loops.
        Test cases:
        - 85
        - 677
        - 12
        - 673
        - D01P11A/dus03/0
        """
        logger.debug("Detecting loops...")
        # TODO: Loop detection & creation really needs to be re-written.
        for i, g in enumerate(self._graphs):
            find_first_common_next_vertex_in_edges__clear_cache(g)
            loop_id = -1
            if len(g.vs) < 1:
                continue
            had_to_restart = True
            while had_to_restart:
                had_to_restart = False
                for v in g.bfsiter(g.vs[0]):
                    loop_edges = [e for e in v.in_edges() if e["loop"]]
                    if len(loop_edges) > 0 and len(v["op"].markers) == 0:
                        # To this node jumps a loop. Check if we can build a proper forever-loop.
                        can_build, break_points, continue_points = self._build_loops__try_loop(v)
                        # Proper loop detection is hard... This is a backup check, to make sure, that
                        # any of the break and continue vertices are not reachable from outside the loop.
                        # Perform the backup proper loop detection check, to make sure we can't reach any of
                        # the continue and break points from outside the loop
                        if can_build:
                            assert break_points is not None and continue_points is not None
                            for loop_edge in break_points + continue_points:
                                if is_reachable_when_removing(g, loop_edge.source, 0, v.index):
                                    # We can't build this loop, the break point would be
                                    # reachable from outside the loop!
                                    can_build = False
                                    break
                        if can_build:
                            assert break_points is not None and continue_points is not None
                            loop_id += 1
                            # Mark break points end vertex as end of loop
                            if len(break_points) > 1:
                                break_points[0].target_vertex["op"].add_marker(ForeverEnd(loop_id))
                                self._update_vertex_style(break_points[0].target_vertex)
                            es_to_delete = set()
                            vs_to_delete: set[int] = set()
                            v["op"].add_marker(ForeverStart(loop_id))
                            self._update_vertex_style(v)
                            for loop_edge in break_points:
                                break_point = loop_edge.source_vertex
                                break_target = loop_edge.target_vertex
                                if not isinstance(break_point["op"], SsbLabelJump) or break_point["op"].get_marker():
                                    # Already has a marker, add a new opcode in between
                                    loop_edge_flow_level = loop_edge["flow_level"]
                                    actual_break_point = g.add_vertex(
                                        label=None,
                                        op=SsbLabelJump(break_point["op"], None),
                                        style="solid",
                                        shape="ellipse",
                                    )
                                    actual_break_point["op"].remove_marker()
                                    actual_break_point["op"].add_marker(ForeverBreak(loop_id))
                                    es_to_delete.add(loop_edge)
                                    e = self._reconnect(g, break_point, loop_edge, actual_break_point, True)
                                    e = g.add_edge(
                                        actual_break_point,
                                        break_target,
                                        flow_level=loop_edge_flow_level,
                                        label=None,
                                        is_else=False,
                                        switch_ops=None,
                                        loop=e["loop"],
                                    )
                                    self._update_edge_style(e)
                                    self._update_vertex_style(actual_break_point)
                                else:
                                    # Doesn't have a marker yet, mark as break
                                    break_point["op"].add_marker(ForeverBreak(loop_id))
                                    self._update_vertex_style(break_point)
                            for loop_edge in continue_points:
                                continue_point = loop_edge.source_vertex
                                if (
                                    not isinstance(continue_point["op"], SsbLabelJump)
                                    or continue_point["op"].get_marker()
                                ):
                                    # Already has a marker or is not a jump, add a new opcode in between
                                    loop_edge_flow_level = loop_edge["flow_level"]
                                    actual_continue_point = g.add_vertex(
                                        label=None,
                                        op=SsbLabelJump(continue_point["op"], None),
                                        style="solid",
                                        shape="ellipse",
                                    )
                                    actual_continue_point["op"].remove_marker()
                                    actual_continue_point["op"].add_marker(ForeverContinue(loop_id))
                                    es_to_delete.add(loop_edge)
                                    e = self._reconnect(g, continue_point, loop_edge, actual_continue_point, True)
                                    e["loop"] = False
                                    e = g.add_edge(
                                        actual_continue_point,
                                        v,
                                        flow_level=loop_edge_flow_level,
                                        label=None,
                                        is_else=False,
                                        switch_ops=None,
                                        loop=True,
                                    )
                                    self._update_edge_style(e)
                                    self._update_vertex_style(actual_continue_point)
                                else:
                                    # Doesn't have a marker yet, mark as continue
                                    continue_point["op"].add_marker(ForeverContinue(loop_id))
                                    self._update_vertex_style(continue_point)

                            g.delete_edges(es_to_delete)
                            g.delete_vertices(vs_to_delete)
                            # We need to start from the beginning sadly because we can't
                            # continue iterating the modified graph!
                            had_to_restart = True
                            break

    def _build_loops__try_loop(self, start: Vertex) -> tuple[bool, list[Edge] | None, list[Edge] | None]:
        """
        Try to find a loopable section of the graph starting at v.
        If found, the second entry of the returned tuple contains breaking points and the third all required continue
        markers.
        """
        continues = [e for e in start.in_edges() if e["loop"]]

        # Make sure the loop doesn't cross any existing loops
        def path_filter(e: Edge, v: Vertex) -> bool:
            return not any_incoming_edge_is_loop(v)

        immediate_breaks_b = get_out_edges_of_subgraph(start.graph, start, [c.source for c in continues], path_filter)
        if immediate_breaks_b is None:
            return False, None, None
        immediate_breaks = [start.graph.es[e] for e in immediate_breaks_b]
        # Not done! To get the actual break points, find common next vertex
        # of all break points and then apply breakpoint status to all jumps before that, that can be accesed on any
        # path from the immediate breaks.
        # (if there's only one just use that one)
        if len(immediate_breaks) > 1:
            # we can allow open branches, because we know all other branches will either also break
            # or loop
            # we don't allow loops, because the breaks of the nested loop might lead to some really nasty edge cases.
            breaks = find_first_common_next_vertex_in_edges(
                start.graph, immediate_breaks, allow_open_branches=True, allow_loops=False, allow_loop_edges=False
            )
            if not breaks:
                return False, None, None
            break_target = breaks[0].target_vertex
            if break_target == start:
                # hm, this really shouldn't happen.
                logger.warning("Warning, break node was starting node when building loop")
                return False, None, None
            breaks_set = set(breaks)
            # Get a list of all vertices visited from the immediate break points, to the first common end point
            vertices = set()
            for e in immediate_breaks:
                vertices.update(
                    get_all_vertices_between(
                        start.graph, e.target, break_target.index, lambda e, v: v != start and path_filter(e, v)
                    )
                )
            # Check all other in edges of this loop end, we may have more allowed break points in the list of vertices
            for e2 in break_target.in_edges():
                if e2.source in vertices:
                    breaks_set.add(e2)
        else:
            breaks_set = set(immediate_breaks)

        return True, list(b for b in breaks_set if b not in continues), continues

    def remove_label_markers(self) -> None:
        logger.debug("Removing unnecessary labels...")
        for i, g in enumerate(self._graphs):
            find_first_common_next_vertex_in_edges__clear_cache(g)
            vs_to_delete = set()
            # First, let's delete all redundant jumps (actual OP_JUMPs that jump to opcodes with only one in edge)
            for v in g.vs:
                if (
                    isinstance(v["op"], SsbLabelJump)
                    and v["op"].maybe_root is not None
                    and v["op"].root.op_code.name == OP_JUMP
                    and v["op"].get_marker() is None
                ):
                    in_edges = v.in_edges()
                    out_edges = v.out_edges()
                    if len(in_edges) != 0:
                        assert len(in_edges) == 1 and len(out_edges) == 1
                        v_before = in_edges[0].source_vertex
                        v_after = out_edges[0].target_vertex
                        if isinstance(v_after["op"], SsbLabel):
                            # if we don't remove it, we will definitely have to print it:
                            v_after["op"].force_write = True
                        if len(v_after.in_edges()) > 1:
                            # The jump target has multiple entry points, keep the jump
                            continue
                        if (
                            isinstance(v_after["op"], SsbForeignLabel)
                            or v_after["op"].id == 0
                            or out_edges[0]["loop"]
                            or (isinstance(v_after["op"], SsbLabel) and len(v_after["op"].markers) > 0)
                        ):
                            # The jump target is a special label, loops, or is the first operation, we really
                            # shouldn't remove it
                            # (may be a loop start for example)
                            continue
                        e = self._reconnect(g, v_before, in_edges[0], v_after, True)
                        e["flow_level"] = e["flow_level"] + 1
                        self._update_edge_style(e)
                    vs_to_delete.add(v)
            g.delete_vertices(vs_to_delete)
            vs_to_delete = set()
            # Then delete all redundant labels (only one in edge)
            for v in g.vs:
                if isinstance(v["op"], SsbLabel):
                    in_edges = v.in_edges()
                    out_edges = v.out_edges()
                    if len(in_edges) == 0:
                        vs_to_delete.add(v)
                    elif len(in_edges) == 1:
                        assert len(out_edges) == 1
                        if (
                            v["op"].id == 0
                            or in_edges[0]["loop"]
                            or (
                                isinstance(v["op"], SsbLabel)
                                and (
                                    v["op"].force_write
                                    or v["op"].referenced_from_other_routine
                                    or len(v["op"].markers) > 0
                                )
                            )
                        ):
                            # The label is a special label, loops, or is the first operation, we really
                            # shouldn't remove it
                            # (may be a loop start for example)
                            continue
                        v_before = in_edges[0].source_vertex
                        v_after = out_edges[0].target_vertex
                        self._reconnect(g, v_before, in_edges[0], v_after, True)
                        vs_to_delete.add(v)
            g.delete_vertices(vs_to_delete)

    def _get_edges(self, g: Graph, rtn: Sequence[SsbOperation], rtn_id: int, label_indices: dict[int, int]) -> None:
        """
        Get the edges for the graph g by a list of SsbOperations. Will branch at SsbLabelJumps.
        """
        already_visited: set[int] = set()
        self._get_edges__add_edge(g, rtn, rtn_id, label_indices, 0, already_visited)
        return
        # TODO: below is for debugging.

        # Also collect left-over opcodes at the very end of a routine. For some routines there seems to be code
        # at the end that SEEMS unreachable, but we collect it anyway and try connect it from reverse with the first
        # ending opcode we can find
        op_code_idx = len(rtn) - 1
        # Not applicable, if the last opcode is a jump
        # TODO: Two loops and even different iteration mechanisms? probably want to refactor this...
        for i in reversed(range(0, op_code_idx + 1)):
            if len(list(g.incident(i, IN))) > 0:
                if isinstance(g.vs[i]["op"], SsbLabelJump) and g.vs[i]["op"].root.op_code.name == OP_JUMP:
                    return
                break
        # Not applicable for one-instruction routines.
        while op_code_idx > 1:
            if len(list(g.incident(op_code_idx, IN))) < 1:
                e = g.add_edge(
                    op_code_idx - 1, op_code_idx, flow_level=0, label=None, is_else=False, switch_ops=None, loop=False
                )
                self._update_edge_style(e)
                v_op = g.vs[op_code_idx]["op"]
                # Don't forget the labels
                if (
                    isinstance(v_op, SsbLabelJump)
                    and v_op.label.routine_id == rtn_id
                    and v_op.root.op_code.name != OP_JUMP
                ):
                    is_loop = (
                        label_indices[v_op.label.id] < op_code_idx
                        and len(g.incident(label_indices[v_op.label.id], IN)) > 0
                    )
                    g.add_edge(
                        op_code_idx,
                        label_indices[v_op.label.id],
                        flow_level=1,
                        label=None,
                        is_else=False,
                        switch_ops=None,
                        loop=is_loop,
                    )
                    self._update_edge_style(e)
                op_code_idx -= 1
            else:
                break

    def _get_edges__add_edge(
        self,
        g: Graph,
        rtn: Sequence[SsbOperation],
        rtn_id: int,
        label_indices: dict[int, int],
        op_i: int,
        already_visited: set[int],
        flow_level: int = 0,
    ) -> None:
        nxt_stack = [(flow_level, op_i)]
        while len(nxt_stack) > 0:
            flow_level, op_i = nxt_stack.pop()
            if op_i in already_visited:
                continue  # Loop
            if isinstance(g.vs[op_i]["op"], SsbForeignLabel):
                continue  # No out edges here, no real ops here.
            already_visited.add(op_i)
            for flow_level, nxt in self._get_edges__get_next_for(g, rtn, rtn_id, flow_level, label_indices, op_i):
                e = g.add_edge(op_i, nxt, flow_level=flow_level, label=None, is_else=False, switch_ops=None, loop=False)
                if is_loop(g, g.vs[op_i], e):
                    e["loop"] = True
                self._update_edge_style(e)
                nxt_stack.insert(0, (flow_level, nxt))

    def _get_edges__get_next_for(
        self,
        g: Graph,
        rtn: Sequence[SsbOperation],
        rtn_id: int,
        flow_level: int,
        label_indices: dict[int, int],
        op_i: int,
    ) -> list[tuple[int, int]]:
        """
        Returns a list of next opcodes to visit from this opcode and
        their flow level (flow_level for normal continue; flow_level + 1 for jump)
        """
        next_ops: list[tuple[int, int]] = []

        previous_op = rtn[op_i - 1]
        # If the previous op is one of OPS_CTX, then the immediate control flow will not end,
        # even if we get one of OPS_THAT_END_CONTROL_FLOW.
        flow_can_not_end = previous_op.op_code.name in OPS_CTX or not self.optimize_ending_opcodes
        op = rtn[op_i]
        real_op = op
        is_label_jump = False
        if isinstance(op, SsbLabelJump):
            real_op = op.root
            is_label_jump = True
        is_guaranteed_jump = real_op.op_code.name in OPS_THAT_WILL_JUMP_GUARANTEED
        # If this is not a guaranteed jump or the last op_code in rtn, one possible branch is always just the next op,
        if (
            not is_guaranteed_jump
            and len(rtn) > op_i + 1
            and (flow_can_not_end or real_op.op_code.name not in OPS_THAT_END_CONTROL_FLOW)
        ):
            next_ops.append((flow_level, op_i + 1))
        # If this is a label jump, we can also continue at the label
        if is_label_jump:
            if TYPE_CHECKING:
                assert isinstance(op, SsbLabelJump)
            assert op.label is not None
            if op.label.routine_id == rtn_id:
                next_ops.append((flow_level + 1, label_indices[op.label.id]))
            else:
                # We need a foreign label reference
                v = g.add_vertex(
                    f"FLR<from{op_i}>", label=None, op=SsbForeignLabel(op.label), style="solid", shape="ellipse"
                )
                self._update_vertex_style(v)
                next_ops.append((flow_level + 1, v.index))

        # If this would be the end but we are "Hold", then MAYBE there's still a statement after use, which we should
        # include, see notes at constant.
        if real_op.op_code.name == OP_HOLD and len(rtn) > op_i + 1:
            if rtn[op_i + 1].op_code.name in OPS_THAT_END_CONTROL_FLOW:
                next_ops.append((flow_level, op_i + 1))

        return next_ops

    @classmethod
    def _reconnect(
        cls,
        g: Graph,
        old_vertex: Vertex | int,
        old_vertex_edge_to_remove: Edge,
        new_vertex_to_connect: Vertex,
        do_not_delete: bool = False,
    ) -> Edge:
        attr = old_vertex_edge_to_remove.attributes()
        if not do_not_delete:
            g.delete_edges(old_vertex_edge_to_remove)
        e = g.add_edge(old_vertex, new_vertex_to_connect, **attr)
        cls._update_edge_style(e)
        return e

    @staticmethod
    def _update_vertex_style(v: Vertex) -> None:
        v["label"] = f"<{v['name']}>{v['op'].op_code.name}"
        if isinstance(v["op"], SsbForeignLabel):
            v["style"] = "striped"
            v["fillcolor"] = "#D693E3"
            v["shape"] = "rectangle"
        if isinstance(v["op"], SsbLabel):
            v["style"] = "striped"
            v["fillcolor"] = "#B446E3"
            v["shape"] = "rectangle"
            if len(v["op"].markers) > 0:
                marker_str = ""
                v["fillcolor"] = ""
                for marker in v["op"].markers:
                    if isinstance(marker, IfEnd):
                        v["fillcolor"] += "#A85400:"
                    elif isinstance(marker, SwitchEnd):
                        v["fillcolor"] += "#005F26:"
                    elif isinstance(marker, SwitchFalltrough):
                        v["fillcolor"] += "#8ABC82:"
                    elif isinstance(marker, ForeverStart):
                        v["fillcolor"] += "#00366D:"
                    elif isinstance(marker, ForeverEnd):
                        v["fillcolor"] += "#00616D:"
                    marker_str += str(marker) + ";"
                marker_str = marker_str[:-1]
                v["fillcolor"] = v["fillcolor"][:-1]
                v["label"] += f" ({marker_str})"
        elif isinstance(v["op"], SsbLabelJump):
            v["style"] = "filled"  # TODO: wedged not working...?
            v["fillcolor"] = "#38BCFF"
            v["shape"] = "ellipse"
            if len(v["op"].markers) > 0:
                marker_str = ""
                v["fillcolor"] = ""
                for jmarker in v["op"].markers:
                    if isinstance(jmarker, CallJump):
                        v["fillcolor"] += "#A3C96D:"
                    elif isinstance(jmarker, MultiIfStart):
                        v["fillcolor"] += "#E3BF00:"
                    elif isinstance(jmarker, IfStart):
                        v["fillcolor"] += "#E36A00:"
                    elif isinstance(jmarker, SwitchStart):
                        v["fillcolor"] += "#00BC3F:"
                    elif isinstance(jmarker, ForeverContinue):
                        v["fillcolor"] += "#0C00BC:"
                    elif isinstance(jmarker, ForeverBreak):
                        v["fillcolor"] += "#6694FF:"
                    marker_str += str(jmarker) + ";"
                marker_str = marker_str[:-1]
                v["fillcolor"] = v["fillcolor"][:-1]
                v["label"] += f" ({marker_str})"

    @staticmethod
    def _update_edge_style(e: Edge) -> None:
        e["color"] = "black"
        e["label"] = str(e["flow_level"])
        if e["is_else"]:
            e["label"] += " <Else>"
        if e["loop"]:
            e["color"] = "red"
            e["label"] += " <Loop>"
        if e["switch_ops"] is not None:
            for op in e["switch_ops"]:
                e["label"] += f"\n[{op.switch_index}:{op.index}:{op.op.op_code.name}]"

    def get_graphs(self) -> list[Graph]:
        return self._graphs

    # Additional utility transformations for debugging:

    def remove_all_labels_and_simple_jumps(self) -> None:
        for i, g in enumerate(self._graphs):
            vs_to_delete: set[Vertex] = set()
            first_pass = True
            while first_pass or len(vs_to_delete) > 0:
                vs_to_delete = set()
                first_pass = False
                for v in g.vs:
                    if v["op"].op_code.name == OP_JUMP or (
                        isinstance(v["op"], SsbLabelJump) and v["op"].root.op_code.name == OP_JUMP
                    ):
                        self._delete_and_reconnect(v, vs_to_delete)
                    if isinstance(v["op"], SsbLabel):
                        self._delete_and_reconnect(v, vs_to_delete)
                    # due to some issues, we better break and continue in next run, even if very slow
                    if len(vs_to_delete) > 0:
                        break
                g.delete_vertices(vs_to_delete)
            # check
            for v in g.vs:
                assert not isinstance(v["op"], SsbLabel)
                assert not (isinstance(v["op"], SsbLabelJump) and v["op"].root.op_code.name == OP_JUMP)

    def _delete_and_reconnect(self, v: Vertex, vs_to_delete: set[Vertex]) -> None:
        g = v.graph
        in_edges = v.in_edges()
        out_edges = v.out_edges()
        if len(in_edges) == 0:
            vs_to_delete.add(v)
        else:
            assert len(out_edges) == 1
            v_after = out_edges[0].target_vertex
            for e in in_edges:
                v_before = e.source_vertex
                self._reconnect(g, v_before, e, v_after, True)
            vs_to_delete.add(v)
