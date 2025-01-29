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

from collections.abc import Sequence

from explorerscript.util import f, _
from explorerscript_parser import Antlr4ErrorListener


class AntlrSyntaxError:
    def __init__(self, recognizer, offendingSymbol, line, column, msg, e):  # type: ignore
        self.recognizer = recognizer
        self.offendingSymbol = offendingSymbol
        self.line = line
        self.column = column
        self.msg = msg
        self.e = e

    def __str__(self) -> str:
        return f(_("line {self.line}:{self.column}: {self.msg}"))


class SyntaxErrorListener(Antlr4ErrorListener):
    """General purpose error listener for Antlr"""

    _syntax_errors: list[AntlrSyntaxError]

    def __init__(self):  # type: ignore
        self._syntax_errors = []
        super().__init__()

    @property
    def syntax_errors(self) -> Sequence[AntlrSyntaxError]:
        return self._syntax_errors

    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):  # type: ignore
        self._syntax_errors.append(AntlrSyntaxError(recognizer, offendingSymbol, line, column, msg, e))

    def __str__(self) -> str:
        return "\n".join(str(e) for e in self.syntax_errors)
