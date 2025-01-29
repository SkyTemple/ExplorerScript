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

from typing import Any

from explorerscript_parser import ExplorerScriptParser, ExplorerScriptBaseVisitor


class HasRoutinesVisitor(ExplorerScriptBaseVisitor):
    """Visitor that returns whether or not the ExplorerScript tree contains any routines."""

    def __init__(self) -> None:
        super().__init__()

    def visitImport_stmt(self, ctx: ExplorerScriptParser.Import_stmtContext) -> bool:
        # Are not visited.
        return False

    def visitFuncdef(self, ctx: ExplorerScriptParser.FuncdefContext) -> bool:
        return True

    def visitMacrodef(self, ctx: ExplorerScriptParser.MacrodefContext) -> bool:
        # Are not visited.
        return False

    def visitConstant_assign(self, ctx: ExplorerScriptParser.Constant_assignContext) -> None:
        # Are not visited.
        return None

    def defaultResult(self) -> bool:  # type: ignore
        return False

    def visitTerminal(self, node: Any) -> bool:
        return False

    def aggregateResult(self, aggregate: bool, nextResult: bool) -> bool:
        return aggregate or nextResult
