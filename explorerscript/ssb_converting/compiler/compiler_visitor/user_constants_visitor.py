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

from explorerscript.common_syntax import parse_primitive
from explorerscript.ssb_converting.compiler.utils import UserDefinedConstants
from explorerscript.ssb_converting.ssb_data_types import SsbOpParam
from explorerscript.util import exps_int
from explorerscript_parser import ExplorerScriptParser, ExplorerScriptBaseVisitor


class UserConstantsVisitor(ExplorerScriptBaseVisitor):
    """Collects all constants in all scopes of an ExplorerScript source file."""

    collected_constants: UserDefinedConstants
    _current_constant_context: dict[str, SsbOpParam]

    def __init__(self, start_constants: None | UserDefinedConstants = None):
        if start_constants is None:
            self.collected_constants = UserDefinedConstants({}, {}, {})
        else:
            self.collected_constants = start_constants
        super().__init__()

    def visitStart(self, ctx: ExplorerScriptParser.StartContext) -> UserDefinedConstants:
        self._current_constant_context = self.collected_constants.global_constants
        self.visitChildren(ctx)
        return self.collected_constants

    def visitMacrodef(self, ctx: ExplorerScriptParser.MacrodefContext) -> None:
        const_ctx: dict[str, SsbOpParam] = {}
        self.collected_constants.macrodefdef_constants[str(ctx.IDENTIFIER())] = const_ctx
        self._current_constant_context = const_ctx
        self.visitChildren(ctx)
        self._current_constant_context = self.collected_constants.global_constants

    def visitSimple_def(self, ctx: ExplorerScriptParser.Simple_defContext) -> None:
        self._visit_func(exps_int(str(ctx.INTEGER())))
        self.visitChildren(ctx)
        self._current_constant_context = self.collected_constants.global_constants

    def visitCoro_def(self, ctx: ExplorerScriptParser.Coro_defContext) -> None:
        self._visit_func(str(ctx.IDENTIFIER()))
        self.visitChildren(ctx)
        self._current_constant_context = self.collected_constants.global_constants

    def visitFor_target_def(self, ctx: ExplorerScriptParser.For_target_defContext) -> None:
        self._visit_func(exps_int(str(ctx.INTEGER())))
        self.visitChildren(ctx)
        self._current_constant_context = self.collected_constants.global_constants

    def _visit_func(self, idx: int | str) -> None:
        const_ctx: dict[str, SsbOpParam] = {}
        self.collected_constants.funcdef_constants[idx] = const_ctx
        self._current_constant_context = const_ctx

    def visitConstant_assign(self, ctx: ExplorerScriptParser.Constant_assignContext) -> None:
        const_name = str(ctx.IDENTIFIER())
        const_val = ctx.primitive()
        self._current_constant_context[const_name] = parse_primitive(
            const_val, user_constants=self.collected_constants.in_scope(self._current_constant_context)
        )
