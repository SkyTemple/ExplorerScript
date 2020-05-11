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
from collections import OrderedDict
from typing import Dict, Set, Optional

from igraph import Graph

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.antlr.ExplorerScriptVisitor import ExplorerScriptVisitor
from explorerscript.error import SsbCompilerError
from explorerscript.macro import ExplorerScriptMacro


class MacroResolutionOrderVisitor(ExplorerScriptVisitor):
    """Sorts a dict of Macros by how macros depend on them, returns a list of macro names"""
    def __init__(self, in_macros: Dict[str, ExplorerScriptMacro]):
        self._in_macros: Dict[str, ExplorerScriptMacro] = in_macros
        # Values depend on keys:
        self._dependency_graph = Graph(directed=True)
        self._already_added_to_graph = set()
        for name in self._in_macros.keys():
            self._create_vertex(name)
        self._active_macro_name: Optional[str] = None

    def visitStart(self, ctx: ExplorerScriptParser.StartContext) -> Dict[str, ExplorerScriptMacro]:
        self.visitChildren(ctx)
        self._check_cycles()
        roots = [v for v in self._dependency_graph.vs if len(v.in_edges()) == 0]
        resolution_order = []
        for v in roots:
            for sv in self._dependency_graph.bfsiter(v.index):
                if sv['name'] not in resolution_order:
                    resolution_order.insert(0, sv['name'])
        return resolution_order

    def visitMacrodef(self, ctx: ExplorerScriptParser.MacrodefContext):
        self._active_macro_name = str(ctx.IDENTIFIER())
        self._create_vertex(self._active_macro_name)
        self.visitChildren(ctx)
        self._active_macro_name = None

    def visitImport_stmt(self, ctx: ExplorerScriptParser.Import_stmtContext):
        # Are not visited.
        return None

    def visitFuncdef(self, ctx: ExplorerScriptParser.FuncdefContext):
        # Are not visited.
        return None

    def visitMacro_call(self, ctx: ExplorerScriptParser.Macro_callContext):
        name = str(ctx.MACRO_CALL())[1:]
        assert self._active_macro_name is not None
        self._create_vertex(name)
        if not self._dependency_graph.are_connected(name, self._active_macro_name):
            self._dependency_graph.add_edge(self._active_macro_name, name)

    def _create_vertex(self, name):
        if name not in self._already_added_to_graph:
            self._already_added_to_graph.add(name)
            self._dependency_graph.add_vertex(name, label=name)

    def _check_cycles(self):
        vs_to_check = set(i for i in range(0, len(self._dependency_graph.vs)))
        while len(vs_to_check) > 0:
            v = vs_to_check.pop()
            vs_visited_in_run = {v}
            vs_to_check_inner = {v}
            while len(vs_to_check_inner) > 0:
                v_inner = vs_to_check_inner.pop()
                vs_directly_connected = set()
                for e in self._dependency_graph.vs[v_inner].out_edges():
                    v_inner = e.target
                    if v_inner in vs_directly_connected:
                        continue
                    vs_directly_connected.add(v_inner)
                    if v_inner in vs_visited_in_run:
                        raise SsbCompilerError(f"Dependency cycle detected while trying to resolve macros"
                                               f" (for macro '{e.target_vertex['name']}').")
                    vs_visited_in_run.add(v_inner)
                    vs_to_check_inner.add(v_inner)