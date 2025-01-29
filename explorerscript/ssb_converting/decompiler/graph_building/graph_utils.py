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

import functools
import itertools
import logging
import operator
from collections import Counter
from threading import Lock
from typing import cast
from collections.abc import Callable, Generator, Sequence

from igraph import Edge, OUT, Vertex, Graph

from explorerscript.ssb_converting.ssb_special_ops import (
    SsbLabelJump,
    SsbLabel,
    SwitchCaseOperation,
    IfEnd,
    SwitchEnd,
    IfStart,
    SwitchStart,
    ForeverStart,
    LabelMarker,
)

logger = logging.getLogger(__name__)


def find_lowest_and_highest_out_edge(g: Graph, vertex: Vertex, attr: str) -> tuple[Edge, Edge]:
    edges: list[Edge] = [g.es[e] for e in g.incident(vertex, OUT)]
    # noinspection PyTypeChecker
    if len(edges) == 0:
        raise ValueError("The vertex has no edges.")
    return min(edges, key=lambda k: k[attr]), max(edges, key=lambda k: k[attr])


cache_lock = Lock()
find_first_common_next_vertex_in_edges_cache: dict[int, dict[str, list[Edge] | None]] = {}


def find_first_common_next_vertex_in_edges__clear_cache(g: Graph) -> None:
    with cache_lock:
        find_first_common_next_vertex_in_edges_cache[id(g)] = {}


def find_first_common_next_vertex_in_edges(
    g: Graph,
    es: Sequence[Edge] | set[Edge],
    allow_open_branches: bool = False,
    allow_loops: bool = False,
    vs_to_not_visit: list[int] | None = None,
    allow_loop_edges: bool = True,
) -> None | list[Edge]:
    """
    Finds the first vertex (actually list of edges that lead to it for each edge in es)
    which is reachable by all edges in es.

    es must contain at least two edges.

    If allow_open_branches is False:
        It's made sure that ALL paths that are started from these starting points lead to there,
        this means for splitting-sub-paths it's also checked that they have a common end vertex and the
        search is continued from there.

    If allow_loops is False:
        If a vertex is visited twice (loop detected), aborts this branch.
    Else:
        If a vertex is visited 100 times (possibly infinite loop detected!), aborts this branch

    If allow_loop_edges is False:
        Edges which are marked as causing logical loops are visited
    Else:
        Those edges are not visited, aborting the branch.

    If no common vertex is found, returns None.
    """
    # TODO: Performance with (not allow_open_branches).
    es_ids = ",".join(sorted([str(e.index) for e in es]))
    with cache_lock:
        if id(g) not in find_first_common_next_vertex_in_edges_cache:
            find_first_common_next_vertex_in_edges_cache[id(g)] = {}
        if es_ids in find_first_common_next_vertex_in_edges_cache[id(g)]:
            return find_first_common_next_vertex_in_edges_cache[id(g)][es_ids]
    assert len(es) > 1
    result = _find_first_common_next_vertex_in_edges__impl(
        g, [{e} for e in es], [], allow_open_branches, allow_loops, vs_to_not_visit, allow_loop_edges
    )
    with cache_lock:
        # cache may have been cleared in the meantime
        find_first_common_next_vertex_in_edges_cache[id(g)][es_ids] = result
    return result


def _find_first_common_next_vertex_in_edges__impl(
    g: Graph,
    es: list[set[Edge | None]],
    map_of_visited: list[dict[int, int]],
    allow_open_branches: bool,
    allow_loops: bool,
    vs_to_not_visit: list[int] | None = None,
    allow_loop_edges: bool = True,
) -> None | list[Edge]:
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
            should_remove = set()
            for e in e_set:
                if e is not None:
                    if len(map_of_visited) <= i:
                        map_of_visited.append({})
                    if e.target in map_of_visited[i]:
                        # We already visited this before on this path...
                        should_remove.add(e)
                    map_of_visited[i][e.target] = e.index
            for e in should_remove:
                e_set.remove(e)
            if len(e_set) == 0:
                es[i] = {None}

        # Check if the end vertex was found
        intersection_result = set(map_of_visited[0].keys())
        for s in map_of_visited[1:]:
            intersection_result.intersection_update(s)
        if len(intersection_result) > 0:
            end_vertex = intersection_result.pop()
            return [g.es[s[end_vertex]] for s in map_of_visited]

        # Not found... too bad! Try to go through the path and find it
        # Get next edge for all paths
        new_es: list[set[Edge | None]] = []
        for i, e_set in enumerate(es):
            new_es_entry: set[Edge | None] = set()
            new_es.append(new_es_entry)
            for e in e_set:
                if e is None:
                    new_es_entry.add(None)
                    continue
                v = e.target_vertex
                if v.index in vs_to_not_visit:
                    if not allow_loops or vs_to_not_visit.count(v.index) > 100:
                        # Potential endless recursion situation. Abort.
                        new_es_entry.add(None)
                        continue
                v_es: list[Edge] = []
                for e in v_es:
                    if e.index in g.es:
                        v_es.append(e)
                if not allow_loop_edges:
                    # Remove edges marked as looping
                    v_es = [e for e in v_es if not any_incoming_edge_is_loop(e.target_vertex)]
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
                            g, v_es, allow_open_branches, allow_loops, list_of_visited_vs_on_branch
                        )
                        if new_common_vertex_edges is None:
                            new_es_entry.add(None)
                        else:
                            new_es_entry.add(new_common_vertex_edges[0])

        es = new_es
    return None


def find_end_label_in_edges(g: Graph, es: list[Edge]) -> None | list[Edge | None]:
    """
    Finds the first vertex with SsbLabel op (actually list of edges that lead to it for each edge in es)
    which is reachable by some edges in es. We search for the ONE vertex joining most of the paths,
    if multiple paths are joined by different vertices, this currently still only returns the one that joins
    the most.

    es must contain at least two edges.

    If allow_open_branches is False:
        It's made sure that ALL paths that are started from these starting points lead to there,
        this means for splitting-sub-paths it's also checked that they have an end label and all the labels
        that are between this end label and the splitting path are removed, because using them
        would leave branches open

    This is similar to find_first_common_next_vertex_in_edges, but...:
        - It's faster [edit: lol no]
        - It doesn't support loops
        - It only works with SsbLabels
        - It allows some edges not to end on the common label
        - allow_open_branches=False is not supported.

    If no common vertex is found returns None. The returned list contains one in-edge for each original out-edge
    in es. If from this edge the point is not reachable, it may contain None for it.

    If an end label is found, but it's path later crosses with any of the other paths created by the edges in es,
    it's not a valid end label (None is returned).
    """
    # TODO: Doesn't reaaaly work yet, also doesn't stop at loops yet and is too slow.
    vertices_visitied_by_paths_for_e_in_es = []
    labels_visitied_by_paths_for_e_in_es = []
    for e in es:
        vs = {v.index for v in g.bfsiter(e.target)}

        # This below is WAY to slow. We instead now check, after building the branch and switch labels, if they
        # are even possible and remove all invalidly if/switch ends.

        # # Check if all branches are closed in paths. Remove all vertices in between from vs:
        # if not allow_open_branches:
        #     # While traversing the list of paths, we don't need to check vertices twice
        #     already_checked = set()
        #     for p in paths:
        #         for v in p:
        #             if v not in already_checked and v in vs:
        #                 already_checked.add(v)
        #                 out_edges = g.vs[v].out_edges()
        #                 if len(out_edges) > 1:
        #                     sub_common_end_edges = find_end_label_in_edges(g, out_edges)
        #                     if sub_common_end_edges is None:
        #                         # Remove the entire rest of the paths from here, nothing from v (including v) can be
        #                         # valid
        #                         for sp in paths:
        #                             if v in sp:
        #                                 idx_of_v = sp.index(v)
        #                                 for vib in sp[idx_of_v+1:]:
        #                                     if vib in vs:
        #                                         vs.remove(vib)
        #                         break
        #                     else:
        #                         sub_common_vertex = next(e.target for e in sub_common_end_edges if e is not None)
        #                         for sp in paths:
        #                             # This gets all elements in this path between v and sub_common_vertex (not inclusive)
        #                             if v in sp and sub_common_vertex in sp:
        #                                 vertices_in_between = sp[(sp.reverse(), len(sp) - sp.index(v), sp.reverse())[1]: sp.index(sub_common_vertex)]
        #                                 for vib in vertices_in_between:
        #                                     if vib in vs:
        #                                         vs.remove(vib)

        vertices_visitied_by_paths_for_e_in_es.append(vs)
        labels_visitied_by_paths_for_e_in_es.append({v for v in vs if isinstance(g.vs[v]["op"], SsbLabel)})

    counter = Counter(labels_visitied_by_paths_for_e_in_es[0])
    for v in labels_visitied_by_paths_for_e_in_es[1:]:
        counter.update(v)

    if len(counter) == 0:
        # No common end
        return None

    # TODO: Check  D01P11A/enter02.ssb/0

    common_v, common_v_count = counter.most_common()[0]
    if common_v_count < 2:
        # No common end
        return None

    vs_visited_by_common_v = set(functools.reduce(operator.iconcat, g.get_all_simple_paths(common_v, None)))
    vs_visited_by_common_v.remove(common_v)
    # Check if this crosses another path
    for orig_vs in vertices_visitied_by_paths_for_e_in_es:
        # Only check for those paths that DON'T contain the common vertex, because for the others
        # we will obviously have all the vertices of the rest of the paths
        if common_v not in orig_vs and len(orig_vs.intersection(vs_visited_by_common_v)) > 0:
            # It crosses another path :(
            # TODO: Maybe we can return the second most common then?
            return None

    # collect original path in edges to this vertex
    in_edges: list[Edge | None] = []
    for i, in_e in enumerate(es):
        if in_e.target == common_v:
            in_edges.append(in_e)
            continue
        paths_e = g.get_all_simple_paths(in_e.target, common_v)
        if len(paths_e) == 0:
            in_edges.append(None)
        for path in paths_e:
            v_idx_in_vs_e = path.index(common_v)
            if v_idx_in_vs_e == 0:
                in_vertex = es[i].source
            else:
                in_vertex = path[v_idx_in_vs_e - 1]
            in_edges.append(g.es[g.get_eid(in_vertex, common_v)])
            break

    return in_edges


def has_path_not_using_any_loop_edges(v1: Vertex, v2: Vertex) -> bool:
    """Check if there are paths between v1 and v2 using only edges with the attribute "loop"=True."""
    edges = v1.out_edges()
    vs_already_visited = {v1}
    while len(edges) > 0:
        edge = edges.pop()
        if edge.target_vertex in vs_already_visited:
            continue
        if edge.target_vertex == v2:
            return True
        vs_already_visited.add(edge.target_vertex)
        if not edge["loop"]:
            edges += edge.target_vertex.out_edges()
    return False


def is_loop(g: Graph, v: Vertex, e: Edge) -> bool:
    """Check if a vertex can reach itself again using the provided edge (check if the edge creates a loop)"""
    if not has_path_not_using_any_loop_edges(e.target_vertex, v):
        return False

    # Simulate deletion of edge and check if still loops
    e_orig_source = e.source
    e_orig_target = e.target
    e_orig_attr = e.attributes()
    g.delete_edges(e)

    has_any_loops = False
    for e in v.out_edges():
        if has_path_not_using_any_loop_edges(e.target_vertex, v):
            has_any_loops = True
            break

    g.add_edge(e_orig_source, e_orig_target, **e_orig_attr)

    return not has_any_loops


def find_first_label_vertex_with_marker_that_matches_condition(
    g: Graph, cb: Callable[[LabelMarker], bool]
) -> tuple[Vertex | None, int | None]:
    for v in g.vs:
        if isinstance(v["op"], SsbLabel):
            for i, marker in enumerate(v["op"].markers):
                if cb(marker):
                    return v, i
    return None, None


def iterate_switch_edges(v: Vertex) -> Generator[tuple[Edge, Sequence[SwitchCaseOperation], bool]]:
    """See iterate_switch_edges_using_edges_and_op."""
    return iterate_switch_edges_using_edges_and_op(v.out_edges(), v["op"])


# TODO: in_op isn't used. This is either wrong or the documentation should be updated.
def iterate_switch_edges_using_edges_and_op(
    case_edges: list[Edge], in_op: SsbLabelJump
) -> Generator[tuple[Edge, Sequence[SwitchCaseOperation], bool]]:
    """
    Iterate out edges of a vertex with a SsbLabelJump op that has a SsbSwitchStart marker (a switch).

    Yields edges in the order that would be evaluated by the game.
    - [index] -> [edge]
    - 1|1,0 -> a
    - 2 -> b
    - 2 -> c
    - 3|1,1 -> b

    This is the same order as printed in ExplorerScript.

    Edges can be yielded multiple times. This can happen when there are gaps in the indices:
    - 0|1|2 -> a
    - 3 -> b
    - 4|5 -> a

    Returns tuples of edges, applicable operations and whether or not this edge is also the default edge.
    The default edge is only yielded once.
    """
    # TODO: Since multi switches were removed, this could be simplified.
    number_of_switches_in_switch = 1
    map_switches_ops_edges = []
    already_yielded_default = False
    for i in range(0, number_of_switches_in_switch):
        map_ops_edges_s = {}
        for e in case_edges:
            if e["switch_ops"] is not None:
                for op in e["switch_ops"]:
                    if op.switch_index == i:
                        map_ops_edges_s[op.index] = e
        map_ops_edges = [map_ops_edges_s[k] for k in sorted(map_ops_edges_s)]
        map_switches_ops_edges.append(map_ops_edges)

    cursors = [0 for _ in range(0, number_of_switches_in_switch)]
    first_cursor_not_at_end = 0
    next_edge = map_switches_ops_edges[first_cursor_not_at_end][cursors[first_cursor_not_at_end]]
    ops_for_edge: list[SwitchCaseOperation] = []
    while first_cursor_not_at_end < len(cursors):
        if map_switches_ops_edges[first_cursor_not_at_end][cursors[first_cursor_not_at_end]] != next_edge:
            yield next_edge, ops_for_edge, cast(bool, next_edge["is_else"]) and not already_yielded_default
            if next_edge["is_else"]:
                already_yielded_default = True
            next_edge = map_switches_ops_edges[first_cursor_not_at_end][cursors[first_cursor_not_at_end]]
            ops_for_edge = []
        for i in range(first_cursor_not_at_end, len(cursors)):
            while cursors[i] < len(map_switches_ops_edges[i]) and map_switches_ops_edges[i][cursors[i]] == next_edge:
                ops_for_edge.append(
                    next(op for op in next_edge["switch_ops"] if op.switch_index == i and op.index == cursors[i])
                )
                cursors[i] += 1
        while first_cursor_not_at_end < len(cursors) and cursors[first_cursor_not_at_end] >= len(
            map_switches_ops_edges[first_cursor_not_at_end]
        ):
            first_cursor_not_at_end += 1
    yield next_edge, ops_for_edge, next_edge["is_else"] and not already_yielded_default
    if next_edge["is_else"]:
        already_yielded_default = True

    # Also take care of the default case if there are no extra switch ops for it
    if not already_yielded_default:
        else_edge_candidates = [e for e in case_edges if e["is_else"]]
        if len(else_edge_candidates) > 0 and else_edge_candidates[0]["switch_ops"] is None:
            yield else_edge_candidates[0], [], True


def reverse_find_edge(e: Edge, cb: Callable[[Edge], bool], loop_check: set[int] | None = None) -> list[Edge]:
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


def get_out_edges_of_subgraph(
    g: Graph, start: Vertex, to: list[Vertex | int], path_filter: Callable[[Edge, Vertex], bool] = lambda e, v: True
) -> set[int] | None:
    """
    Create a subgraph of the given list of vertices and then find all edges out of this sub-graph and return them
    Removes parts of the subgraph for all vertices for which path_filter returns False. The filter get's the
    in edge and the vertex as parameters.
    """
    vertices = set()
    for v in to:
        vertices.update(
            get_all_vertices_between(g, start.index, (v.index if isinstance(v, Vertex) else v), path_filter)
        )  # g.get_all_simple_paths(start, v)
    if len(vertices) == 0:
        # All paths have been filtered out
        return None
    edges = {g.get_eid(v1, v2, error=False, directed=False) for v1, v2 in itertools.combinations(vertices, 2)}
    if -1 in edges:
        edges.remove(-1)
    # Add all out vertices of the vertices above
    for v in vertices.copy():
        for e in g.vs[v].out_edges():
            vertices.add(e.target)
    # Make sure we didn't re-add something we shouldn't be collecting all eids
    for e2 in edges.copy():
        if g.es[e2].target_vertex != start and not path_filter(g.es[e2], g.es[e2].target_vertex):
            edges.remove(e2)
    # Remove all vertices not in subgraph and remove all edges in the original graph = only out edges of this subg.
    es = {e.index for e in g.es}
    # new_g.delete_edges(edges)
    es = es - edges
    # new_g.delete_vertices(set(v.index for v in g.vs) - vertices)
    for e3 in es.copy():
        if g.es[e3].source not in vertices or g.es[e3].target not in vertices:
            es.remove(e3)
    return es


def get_all_vertices_between(
    g: Graph, start: int, target: int, path_filter: Callable[[Edge, Vertex], bool] = lambda e, v: True
) -> set[int]:
    paths_to_go_through = []
    for e in g.vs[start].out_edges():
        paths_to_go_through.append((e, {start}))
    vs_on_the_way_to_target = set()
    vs_already_visited = set()
    while len(paths_to_go_through) > 0:
        e, vs_on_path = paths_to_go_through.pop()
        v = e.target_vertex
        if path_filter(e, v):
            if v.index == target:
                vs_on_the_way_to_target.add(v.index)
                vs_on_the_way_to_target.update(vs_on_path)
            elif v.index in vs_already_visited:
                if v.index in vs_on_the_way_to_target:
                    vs_on_the_way_to_target.update(vs_on_path)
            else:
                vs_already_visited.add(v.index)
                vs_on_path.add(v.index)
                for e in v.out_edges():
                    paths_to_go_through.append((e, vs_on_path.copy()))
    return vs_on_the_way_to_target


def find_switch_end_label(g: Graph, switch_id: int) -> Vertex | None:
    for v in g.vs:
        if isinstance(v["op"], SsbLabel) and any(
            isinstance(m, SwitchEnd) and m.switch_id == switch_id for m in v["op"].markers
        ):
            return v
    return None


def any_incoming_edge_is_loop(v: Vertex) -> bool:
    for e in v.in_edges():
        if e["loop"]:
            return True
    return False


def has_unclosed_blocks(paths: list[list[int]], g: Graph) -> bool:
    """Returns whether the path contains any unclosed ifs/switches or loops"""
    u_ifs = []
    u_switches = []
    u_loops: list[int] = []
    for p in paths:
        for iv in p:
            v = g.vs[iv]
            if isinstance(v["op"], SsbLabelJump):
                m = v["op"].get_marker()
                if isinstance(m, IfStart):
                    u_ifs.append(m.if_id)
                elif isinstance(m, SwitchStart):
                    u_switches.append(m.switch_id)
                elif isinstance(m, ForeverStart):
                    u_loops.append(m.loop_id)
            elif isinstance(v["op"], SsbLabel):
                for m2 in v["op"].markers:
                    try:
                        if isinstance(m2, IfEnd):
                            u_ifs.remove(m2.if_id)
                        elif isinstance(m2, SwitchEnd):
                            u_switches.remove(m2.switch_id)
                    except ValueError:
                        pass
                # We assume all loops are unclosed, because they can't reliably be fully closed in a situation like this.

    return len(u_ifs) > 0 or len(u_switches) > 0 or len(u_loops) > 0


def is_reachable_when_removing(g: Graph, check_id: int, start_id: int, remove_id: int) -> bool:
    """Checks if check is still reachable from start if remove is removed"""
    g_copy: Graph = g.copy()

    if check_id > remove_id:
        check_id -= 1
    if start_id > remove_id:
        remove_id -= 1

    # Simulate the removal on the copy
    g_copy.delete_vertices(remove_id)

    check = g_copy.vs[check_id]
    start = g_copy.vs[start_id]

    p = g_copy.get_shortest_paths(start, check)
    return len(p[0]) > 0
