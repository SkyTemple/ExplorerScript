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
from typing import List, Optional, Dict

from explorerscript.antlr.ExplorerScriptVisitor import ExplorerScriptVisitor
from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.macro import ExplorerScriptMacro
from explorerscript.source_map import SourceMapBuilder
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.integer_like import IntegerLikeCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.coro_def import CoroDefCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.for_target_def import ForTargetDefCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.simple_def import SimpleDefCompileHandler
from explorerscript.ssb_converting.compiler.compiler_visitor.statement_visitor import StatementVisitor
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, Counter
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbOperation


class RoutineVisitor(ExplorerScriptVisitor):
    """Builds the SSB data structures while visiting the parsing tree."""
    def __init__(self, performance_progress_list_var_name: str, macros: Dict[str, ExplorerScriptMacro]):
        # The information about routines stored in the ssb.
        self.routine_infos: List[SsbRoutineInfo] = []
        self.routine_ops: List[List[SsbOperation]] = []
        self.named_coroutines: List[str] = []
        # Source map
        self.source_map_builder: SourceMapBuilder = SourceMapBuilder()

        # Global compilation context for the handlers
        self.compiler_ctx = CompilerCtx(
            Counter(), self.source_map_builder, {}, Counter(), performance_progress_list_var_name, macros
        )

        self._active_routine_id = -1
        self._root_handler: Optional[AbstractCompileHandler] = None

    def visitImport_stmt(self, ctx: ExplorerScriptParser.Import_stmtContext):
        # Are not visited.
        return

    def visitMacrodef(self, ctx: ExplorerScriptParser.MacrodefContext):
        # Are not visited.
        return

    def visitSimple_def(self, ctx: ExplorerScriptParser.Simple_defContext):
        self._root_handler = SimpleDefCompileHandler(ctx, self.compiler_ctx)
        self._active_routine_id = self._root_handler.get_new_routine_id(self._active_routine_id)
        self._enlarge_routine_info()

        self.visitChildren(ctx)
        self.routine_infos[self._active_routine_id], \
            self.routine_ops[self._active_routine_id] = self._root_handler.collect()

    def visitCoro_def(self, ctx: ExplorerScriptParser.Coro_defContext):
        self._root_handler = CoroDefCompileHandler(ctx, self.compiler_ctx)
        self._active_routine_id = self._root_handler.get_new_routine_id(self._active_routine_id)
        self._enlarge_routine_info()

        self.visitChildren(ctx)
        self.named_coroutines[self._active_routine_id], \
            self.routine_infos[self._active_routine_id], \
            self.routine_ops[self._active_routine_id] = self._root_handler.collect()

    def visitFor_target_def(self, ctx: ExplorerScriptParser.For_target_defContext):
        self._root_handler = ForTargetDefCompileHandler(ctx, self.compiler_ctx)
        self._active_routine_id = self._root_handler.get_new_routine_id(self._active_routine_id)
        self._enlarge_routine_info()

        self.visitChildren(ctx)
        self.routine_infos[self._active_routine_id], \
            self.routine_ops[self._active_routine_id] = self._root_handler.collect()

    def visitFunc_alias(self, ctx: ExplorerScriptParser.Func_aliasContext):
        return []

    def visitFunc_suite(self, ctx: ExplorerScriptParser.Func_suiteContext):
        for stmt_ctx in ctx.stmt():
            stmt_ctx.accept(StatementVisitor(self._root_handler, self.compiler_ctx))

    def visitInteger_like(self, ctx: ExplorerScriptParser.Integer_likeContext):
        self._root_handler.add(IntegerLikeCompileHandler(ctx, self.compiler_ctx))

    def _enlarge_routine_info(self):
        if len(self.routine_infos) - 1 < self._active_routine_id:
            needed = self._active_routine_id - len(self.routine_infos) + 1
            for i in range(0, needed):
                self.routine_infos.append(None)
                self.routine_ops.append([])
                self.named_coroutines.append([])
