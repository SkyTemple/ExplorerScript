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
from antlr4 import InputStream, CommonTokenStream

from explorerscript.antlr.ExplorerScriptLexer import ExplorerScriptLexer
from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.error import ParseError
from explorerscript.syntax_error_listener import SyntaxErrorListener


class ExplorerScriptReader:
    """Constructs a parsing tree out of ExplorerScript source code."""
    def __init__(self, source_code: str):
        self.source_code = source_code
        self.parser = None

    def read(self):
        """
        :raises: ParseError
        """
        input_stream = InputStream(self.source_code)
        lexer = ExplorerScriptLexer(input_stream)
        stream = CommonTokenStream(lexer)
        self.parser = ExplorerScriptParser(stream)
        error_listener = SyntaxErrorListener()
        self.parser.addErrorListener(error_listener)

        # Start Parsing
        tree = self.parser.start()

        # Look for errors
        if len(error_listener.syntax_errors) > 0:
            # We only return the first error, the rest is probably not relevant, since
            # the first screws everything over.
            raise ParseError(error_listener.syntax_errors[0])

        return tree

    def get_parser(self):
        return self.parser
