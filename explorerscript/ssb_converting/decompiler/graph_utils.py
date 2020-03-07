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
from typing import Tuple, List, Union, Dict

from igraph import IN, Edge, OUT, Vertex, Graph

from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, SsbLabel


def find_lowest_and_highest_out_edge(g, vertex, attr) -> Tuple[Edge, Edge]:
    edges: List[Edge] = [g.es[e] for e in g.incident(vertex, OUT)]
    # noinspection PyTypeChecker
    if len(edges) == 0:
        raise ValueError("The vertex has no edges.")
    return min(edges, key=lambda k: k[attr]), max(edges, key=lambda k: k[attr])


def find_first_common_next_vertex_in_edges(g, es: List[Edge], vs_to_not_visit: List[int] = None) -> Union[None, List[Edge]]:
    """
    Finds the first vertex (actually list of edges that lead to it for each edge in es)
    which is reachable by all edges in es.

    It's made sure that ALL paths that are started from these starting points lead to there,
    this means for splitting-sub-paths it's also checked that they have a common end vertex and the
    search is continued from there.

    If no common vertex is found, returns None.
    """
    assert len(es) > 1
    result = _find_first_common_next_vertex_in_edges__impl(g, es, [], vs_to_not_visit)
    return result


def _find_first_common_next_vertex_in_edges__impl(
        g, es: List[Union[Edge, None]], map_of_visited: [List[Dict[int, int]]], vs_to_not_visit: List[int] = None
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
    while not all(e is None for e in es):
        # Add current edges to list of visited
        for i, e in enumerate(es):
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
        new_es = []
        for i, e in enumerate(es):
            if e is None:
                new_es.append(None)
                continue
            v = e.target_vertex
            if v.index in vs_to_not_visit:
                # Potential endless recursion situation. Abort.
                new_es.append(None)
                continue
            v_es = v.out_edges()
            if len(v_es) == 0:
                new_es.append(None)
            elif len(v_es) == 1:
                new_es.append(v_es[0])
            else:
                # Recursively find the next new common vertex
                list_of_visited_vs_on_branch = vs_to_not_visit + list(map_of_visited[i].keys())
                new_common_vertex_edges = find_first_common_next_vertex_in_edges(g, v_es, list_of_visited_vs_on_branch)
                if new_common_vertex_edges is None:
                    new_es.append(None)
                else:
                    new_es.append(new_common_vertex_edges[0])

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
