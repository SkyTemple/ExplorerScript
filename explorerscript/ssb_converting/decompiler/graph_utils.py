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


def find_lowest_and_highest_out_edge(g, vertex, attr) -> Tuple[Edge, Edge]:
    edges: List[Edge] = [g.es[e] for e in g.incident(vertex, OUT)]
    # noinspection PyTypeChecker
    if len(edges) == 0:
        raise ValueError("The vertex has no edges.")
    return min(edges, key=lambda k: k[attr]), max(edges, key=lambda k: k[attr])


def find_first_common_next_vertex_in_edges(
        g,
        v1: Vertex, v2: Vertex,
        v1_in_edge: int = None, v2_in_edge: int = None,
        visited1: Dict[int, Edge] = None, visited2: Dict[int, Edge] = None, recursion_check: List[Tuple[int, int]] = None
) -> Tuple[Union[Edge, None], Union[Edge, None]]:
    # TODO: Rewrite to support:
    # ... proper recursion for splitting paths
    # ... arbitrary amount of vertices
    if v1_in_edge is None:
        v1_in_edge = g.incident(v1, IN)[0]
    if v2_in_edge is None:
        v2_in_edge = g.incident(v2, IN)[0]
    if visited1 is None:
        visited1 = {}
    else:
        visited1 = visited1.copy()
    if visited2 is None:
        visited2 = {}
    else:
        visited2 = visited2.copy()
    if recursion_check is None:
        recursion_check = []

    if (v1.index, v2.index) in recursion_check:
        return None, None
    recursion_check.append((v1.index, v2.index))

    visited1[v1.index] = v1_in_edge
    visited2[v2.index] = v2_in_edge

    inc1 = [g.es[e] for e in g.incident(v1, OUT)]
    inc2 = [g.es[e] for e in g.incident(v2, OUT)]

    intersection = set(visited1.keys()).intersection(visited2.keys())
    if len(intersection) > 0:
        end_vertex = intersection.pop()
        return g.es[visited1[end_vertex]], g.es[visited2[end_vertex]]

    # Not found yet, try recursively to continue down the path.
    for new_e1 in inc1:
        new_v1 = new_e1.target_vertex

        return_candidate = find_first_common_next_vertex_in_edges(
            g, new_v1, v2, new_e1.index, v2_in_edge, visited1, visited2, recursion_check
        )

        if return_candidate != (None, None):
            return return_candidate

    for new_e2 in inc2:
        new_v2 = new_e2.target_vertex

        return_candidate = find_first_common_next_vertex_in_edges(
            g, v1, new_v2, v1_in_edge, new_e2.index, visited1, visited2, recursion_check
        )

        if return_candidate != (None, None):
            return return_candidate

    # Negative end condition: One if the paths ends
    return None, None


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
