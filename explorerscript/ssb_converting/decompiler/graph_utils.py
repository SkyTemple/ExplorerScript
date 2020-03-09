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
import itertools
from typing import Tuple, List, Union, Dict, Set

from igraph import IN, Edge, OUT, Vertex, Graph

from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, SsbLabel, MultiSwitchStart, SwitchCaseOperation


def find_lowest_and_highest_out_edge(g, vertex, attr) -> Tuple[Edge, Edge]:
    edges: List[Edge] = [g.es[e] for e in g.incident(vertex, OUT)]
    # noinspection PyTypeChecker
    if len(edges) == 0:
        raise ValueError("The vertex has no edges.")
    return min(edges, key=lambda k: k[attr]), max(edges, key=lambda k: k[attr])


def find_first_common_next_vertex_in_edges(g, es: List[Edge], allow_open_branches = False, vs_to_not_visit: List[int] = None) -> Union[None, List[Edge]]:
    """
    Finds the first vertex (actually list of edges that lead to it for each edge in es)
    which is reachable by all edges in es.

    It's made sure that ALL paths that are started from these starting points lead to there,
    this means for splitting-sub-paths it's also checked that they have a common end vertex and the
    search is continued from there.

    If no common vertex is found, returns None.
    """
    assert len(es) > 1
    result = _find_first_common_next_vertex_in_edges__impl(g, [{e} for e in es], [], allow_open_branches, vs_to_not_visit)
    return result


def _find_first_common_next_vertex_in_edges__impl(
        g, es: List[Set[Union[Edge, None]]], map_of_visited: [List[Dict[int, int]]],
        allow_open_branches: bool, vs_to_not_visit: List[int] = None
) -> Union[None, List[Edge]]:
    """
    :param g: Graph
    :param es: List of edges. An edge can be None, if the end of this part of the tree was reached
    :param map_of_visited: For each e in es: Dict of visited vertices -> the edges that lead to them
    :return:
    """

    if not vs_to_not_visit:
        vs_to_not_visit = []

    # If all incoming edges are None, we didn't find anything :(
    while not all(e == {None} for e in es):
        # Add current edges to list of visited
        for i, e_set in enumerate(es):
            for e in e_set:
                if e is not None:
                    if len(map_of_visited) <= i:
                        map_of_visited.append({})
                    map_of_visited[i][e.target] = e.index

        # Check if the end vertex was found
        intersection_result = set(map_of_visited[0].keys())
        for s in map_of_visited[1:]:
            intersection_result.intersection_update(s)
        if len(intersection_result) > 0:
            end_vertex = intersection_result.pop()
            return [g.es[s[end_vertex]] for s in map_of_visited]

        # Not found... too bad! Try to go through the path and find it
        # Get next edge for all paths
        new_es: List[Set[Union[Edge, None]]] = []
        for i, e_set in enumerate(es):
            new_es_entry = set()
            new_es.append(new_es_entry)
            for e in e_set:
                if e is None:
                    new_es_entry.add(None)
                    continue
                v = e.target_vertex
                if v.index in vs_to_not_visit:
                    # Potential endless recursion situation. Abort.
                    new_es_entry.add(None)
                    continue
                v_es = v.out_edges()
                if len(v_es) == 0:
                    new_es_entry.add(None)
                elif len(v_es) == 1:
                    new_es_entry.add(v_es[0])
                else:
                    if allow_open_branches:
                        # Open branches are allowed, just add this edge to the new es.
                        vs_to_not_visit.append(v.index)
                        new_es_entry.update(v_es)
                    else:
                        # Recursively find the next new common vertex
                        list_of_visited_vs_on_branch = vs_to_not_visit + list(map_of_visited[i].keys())
                        new_common_vertex_edges = find_first_common_next_vertex_in_edges(
                            g, v_es, allow_open_branches, list_of_visited_vs_on_branch
                        )
                        if new_common_vertex_edges is None:
                            new_es_entry.add(None)
                        else:
                            new_es_entry.add(new_common_vertex_edges[0])

        es = new_es


def is_loop(g: Graph, v: Vertex, e: Edge):
    """ Check if a vertex can reach itself again using the provided edge (check if the edge creates a loop)"""
    lists_of_path_with_edge = e.target_vertex.get_shortest_paths(v)
    if all(len(path_with_edge) < 1 for path_with_edge in lists_of_path_with_edge):
        return False

    # Simulate deletion of edge and check if still loops
    e_orig_source = e.source
    e_orig_target = e.target
    e_orig_attr = e.attributes()
    g.delete_edges(e)

    path_list = []
    for e in v.out_edges():
        path_list += e.target_vertex.get_shortest_paths(v)
    has_any_loops = any(len(p) > 0 for p in path_list)

    g.add_edge(e_orig_source, e_orig_target, **e_orig_attr)

    return not has_any_loops


def find_first_label_vertex_with_marker_that_matches_condition(g: Graph, cb):
    for v in g.vs:
        if isinstance(v['op'], SsbLabel):
            for i, marker in enumerate(v['op'].markers):
                if cb(marker):
                    return v, i
    return None, None


def iterate_switch_edges(v: Vertex) -> Tuple[Edge, List[SwitchCaseOperation]]:
    """
    Iterate out edges of a vertex with a SsbLabelJump op that has a SsbSwitchStart marker (a switch).

    Yields edges in the order that would be evaluated by the game (multi-switch cases are grouped however, as
    long as they are in order):
    - [switch_id,index] -> [edge]
    - 0,1|1,0 -> a
    - 0,2 -> b
    - 1,2 -> c
    - 0,3|1,1 -> b

    This is the same order as printed in ExplorerScript.

    Edges can be yielded multiple times. This can happen when there are gaps in the indices:
    - 0,0|0,1|0,2 -> a
    - 0,3 -> b
    - 0,4|0,5 -> a

    Returns tuples of edges and applicable operations.
    """
    case_edges = v.out_edges()
    number_of_switches_in_switch = 1 if not isinstance(v['op'].get_marker(), MultiSwitchStart) else v['op'].get_marker().number_of_switches()
    map_switches_ops_edges = []
    for i in range(0, number_of_switches_in_switch):
        map_ops_edges = {}
        for e in case_edges:
            if e['switch_ops'] is not None:
                for op in e['switch_ops']:
                    if op.switch_index == i:
                        map_ops_edges[op.index] = e
        map_ops_edges = [map_ops_edges[k] for k in sorted(map_ops_edges)]
        map_switches_ops_edges.append(map_ops_edges)

    cursors = [0 for _ in range(0, number_of_switches_in_switch)]
    first_cursor_not_at_end = 0
    next_edge = map_switches_ops_edges[first_cursor_not_at_end][cursors[first_cursor_not_at_end]]
    ops_for_edge = []
    while first_cursor_not_at_end < len(cursors):
        if map_switches_ops_edges[first_cursor_not_at_end][cursors[first_cursor_not_at_end]] != next_edge:
            yield next_edge, ops_for_edge
            next_edge = map_switches_ops_edges[first_cursor_not_at_end][cursors[first_cursor_not_at_end]]
            ops_for_edge = []
        for i in range(first_cursor_not_at_end, len(cursors)):
            while cursors[i] < len(map_switches_ops_edges[i]) and map_switches_ops_edges[i][cursors[i]] == next_edge:
                ops_for_edge.append(next(op for op in next_edge['switch_ops'] if op.switch_index == i and op.index == cursors[i]))
                cursors[i] += 1
        while first_cursor_not_at_end < len(cursors) and cursors[first_cursor_not_at_end] >= len(map_switches_ops_edges[first_cursor_not_at_end]):
            first_cursor_not_at_end += 1
    yield next_edge, ops_for_edge


def reverse_find_edge(e, cb, loop_check: Set[Vertex] = None) -> List[Edge]:
    """
    Returns all edges that match the condition, that can be reached by traversing backwards.
    If found, the search is ended at that edge.
    Returns empty list if not found.
    """
    if cb(e):
        return [e]
    if loop_check is None:
        loop_check = set()
    found = []
    if e.source not in loop_check:
        loop_check.add(e.source)
        for ie in e.source_vertex.in_edges():
            found += reverse_find_edge(ie, cb, loop_check)
    return found
