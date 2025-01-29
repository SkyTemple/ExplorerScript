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

from igraph import Graph, Vertex

from explorerscript.error import SsbCompilerError
from explorerscript.macro import ExplorerScriptMacro
from explorerscript.util import _, f
from explorerscript_parser import ExplorerScriptParser, ExplorerScriptBaseVisitor


class MacroResolutionOrderVisitor(ExplorerScriptBaseVisitor):
    """Sorts a dict of Macros by how macros depend on them, returns a list of macro names"""

    _in_macros: dict[str, ExplorerScriptMacro]
    # Values depend on keys:
    _dependency_graph: Graph
    _already_added_to_graph: set[str]
    _active_macro_name: str | None = None

    def __init__(self, in_macros: dict[str, ExplorerScriptMacro]):
        self._in_macros = in_macros
        self._dependency_graph = Graph(directed=True)
        self._already_added_to_graph = set()
        for name in self._in_macros.keys():
            self._create_vertex(name)
        self._active_macro_name = None
        super().__init__()

    def visitStart(self, ctx: ExplorerScriptParser.StartContext) -> list[str]:
        self.visitChildren(ctx)
        self._check_cycles()
        roots = [v for v in self._dependency_graph.vs if len(v.in_edges()) == 0]
        resolution_order: list[str] = []
        for v in roots:
            resolution_order_local = []
            for sv in self._dependency_graph.bfsiter(v.index):
                if sv["name"] in resolution_order:
                    resolution_order.remove(sv["name"])
                resolution_order_local.append(sv["name"])
            resolution_order += resolution_order_local
        return resolution_order

    def visitMacrodef(self, ctx: ExplorerScriptParser.MacrodefContext) -> None:
        self._active_macro_name = str(ctx.IDENTIFIER())
        self._create_vertex(self._active_macro_name)
        self.visitChildren(ctx)
        self._active_macro_name = None

    def visitImport_stmt(self, ctx: ExplorerScriptParser.Import_stmtContext) -> None:
        # Are not visited.
        return None

    def visitFuncdef(self, ctx: ExplorerScriptParser.FuncdefContext) -> None:
        # Are not visited.
        return None

    def visitConstant_assign(self, ctx: ExplorerScriptParser.Constant_assignContext) -> None:
        # Are not visited.
        return None

    def visitMacro_call(self, ctx: ExplorerScriptParser.Macro_callContext) -> None:
        name = str(ctx.MACRO_CALL())[1:]
        assert self._active_macro_name is not None
        self._create_vertex(name)
        if not self._dependency_graph.are_adjacent(name, self._active_macro_name):
            self._dependency_graph.add_edge(name, self._active_macro_name)

    def _create_vertex(self, name: str) -> None:
        if name not in self._already_added_to_graph:
            self._already_added_to_graph.add(name)
            self._dependency_graph.add_vertex(name, label=name)

    def _check_cycles(self) -> None:
        for v in self._dependency_graph.vs:
            if any(self._has_path(out_e.target, v) for out_e in v.out_edges()):
                raise SsbCompilerError(
                    f(_("Dependency cycle detected while trying to resolve macros (for macro '{v['name']}')."))
                )
            # Check direct cycles
            if any(v.index == e.target for e in v.out_edges()):
                raise SsbCompilerError(
                    f(_("Dependency cycle detected while trying to resolve macros (for macro '{v['name']}')."))
                )

    def _has_path(self, a: Vertex | int, b: Vertex) -> bool:
        # TODO: can be done more efficiently
        return len(b.graph.get_all_simple_paths(a, b)) > 0
