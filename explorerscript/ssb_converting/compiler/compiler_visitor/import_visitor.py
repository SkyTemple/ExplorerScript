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

from explorerscript.ssb_converting.compiler.utils import singleline_string_literal
from explorerscript_parser import ExplorerScriptParser, ExplorerScriptBaseVisitor


class ImportVisitor(ExplorerScriptBaseVisitor):
    """Returns the list of files to import from an ExplorerScript parsing tree."""

    def __init__(self) -> None:
        super().__init__()

    def visitImport_stmt(self, ctx: ExplorerScriptParser.Import_stmtContext) -> str:
        return singleline_string_literal(str(ctx.STRING_LITERAL()))

    def visitFuncdef(self, ctx: ExplorerScriptParser.FuncdefContext) -> None:
        # Are not visited.
        return None

    def visitMacrodef(self, ctx: ExplorerScriptParser.MacrodefContext) -> None:
        # Are not visited.
        return None

    def visitConstant_assign(self, ctx: ExplorerScriptParser.Constant_assignContext) -> None:
        # Are not visited.
        return None

    def defaultResult(self) -> list[str]:  # type: ignore
        return []

    def visitTerminal(self, node: Any) -> None:
        return None

    def aggregateResult(self, aggregate: list[str], nextResult: str) -> list[str]:
        if nextResult is not None:
            aggregate.append(nextResult)
        return aggregate
