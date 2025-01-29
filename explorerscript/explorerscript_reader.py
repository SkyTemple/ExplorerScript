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

from explorerscript.error import ParseError
from explorerscript.syntax_error_listener import SyntaxErrorListener
from explorerscript_parser import ExplorerScriptParserWrapper


class ExplorerScriptReader:
    """Constructs a parsing tree out of ExplorerScript source code."""

    source_code: str

    def __init__(self, source_code: str):
        self.source_code = source_code

    def read(self) -> ExplorerScriptParserWrapper:
        """
        :raises: ParseError
        """
        error_listener = SyntaxErrorListener()
        parser = ExplorerScriptParserWrapper(self.source_code, error_listener)

        # Look for errors
        if len(error_listener.syntax_errors) > 0:
            # We only return the first error, the rest is probably not relevant, since
            # the first screws everything over.
            raise ParseError(error_listener.syntax_errors[0])

        return parser
