#  MIT License
#
#  Copyright (c) 2020-2021 Parakoopa and the SkyTemple Contributors
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
from typing import Optional, List, Dict

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.antlr.ExplorerScriptVisitor import ExplorerScriptVisitor
from explorerscript.error import SsbCompilerError
from explorerscript.macro import ExplorerScriptMacro
from explorerscript.source_map import SourceMapBuilder
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.macro_def import MacroDefCompileHandler
from explorerscript.ssb_converting.compiler.compiler_visitor.statement_visitor import StatementVisitor
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, Counter
from explorerscript.util import _


class MacroVisitor(ExplorerScriptVisitor):
    """ Collects all macros as Macro models from an ExplorerScript tree. """
    def __init__(
            self, performance_progress_list_var_name: str, macros: Dict[str, ExplorerScriptMacro],
            macro_resolution_order: List[str]
    ):
        # Global compilation context for the handlers
        self.source_map_builder = SourceMapBuilder()
        self.compiler_ctx = CompilerCtx(
            Counter(), self.source_map_builder, {}, Counter(),
            performance_progress_list_var_name, macros.copy()
        )
        self.macro_resolution_order = macro_resolution_order

        self._root_handler: Optional[AbstractCompileHandler] = None

    def visitStart(self, ctx: ExplorerScriptParser.StartContext) -> Dict[str, ExplorerScriptMacro]:
        macros = {}
        handlers = [child.accept(self) for child in ctx.macrodef()]
        for handler in sorted(handlers, key=lambda h: self.macro_resolution_order.index(h.get_name())):
            m: ExplorerScriptMacro = self.visitMacrodef_children(handler)
            self.compiler_ctx.macros[m.name] = m
            macros[m.name] = m
        return macros

    def visitMacrodef(self, ctx: ExplorerScriptParser.MacrodefContext) -> MacroDefCompileHandler:
        """Builds the handler for the macro def."""
        return MacroDefCompileHandler(ctx, self.compiler_ctx)

    def visitMacrodef_children(self, macrodef_handler: MacroDefCompileHandler) -> ExplorerScriptMacro:
        """Visit the children of the macro def, after the macro resolution order has been processed"""
        self._root_handler = macrodef_handler
        self.visitChildren(macrodef_handler.ctx)

        blueprints = self._root_handler.collect()
        name = self._root_handler.get_name()
        variables = self._root_handler.get_variables()

        return ExplorerScriptMacro(name, variables, blueprints, self.source_map_builder.build())

    def visitFunc_alias(self, ctx: ExplorerScriptParser.Func_aliasContext):
        raise SsbCompilerError(_("Macros can not alias."))

    def visitFunc_suite(self, ctx: ExplorerScriptParser.Func_suiteContext):
        for stmt_ctx in ctx.stmt():
            stmt_ctx.accept(StatementVisitor(self._root_handler, self.compiler_ctx))
