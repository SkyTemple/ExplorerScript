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

import re

from pygments.lexer import RegexLexer, include, words
from pygments.token import Comment, Name, String, Text, Number

KEYWORDS = (
    "import",
    "coro",
    "def",
    "macro",
    "for_actor",
    "for_object",
    "for_performer",
    "alias",
    "previous",
    "not",
    "if",
    "elseif",
    "else",
    "forever",
    "with",
    "switch",
    "debug",
    "edit",
    "variation",
    "random",
    "sector",
    "menu2",
    "menu",
    "case",
    "default",
    "clear",
    "reset",
    "init",
    "scn",
    "dungeon_result",
    "adventure_log",
    "continue",
    "break",
    "break_loop",
    "return",
    "end",
    "hold",
    "jump",
    "call",
    "while",
    "for",
    "const",
    # Weak keywords
    "TRUE",
    "FALSE",
    "actor",
    "object",
    "performer",
    "value",
    "dungeon_mode",
)


# TODO: Not finished and pretty lazy atm.
class ExplorerScriptLexer(RegexLexer):
    """ExplorerScript as a (very) simple Pygments Lexer, mainly for use with Sphinx."""

    name = "ExplorerScript"
    aliases = ["explorerscript", "exps"]
    filenames = ["*.exps"]

    flags = re.MULTILINE | re.DOTALL

    tokens = {
        "comments": [
            (r"/\*.*?\*/", Comment.Multiline),
            (r"//.*?\n", Comment.Single),
        ],
        "root": [
            (words(KEYWORDS, suffix=r"\b"), Name.Builtin),
            include("comments"),
            (r"[$%][a-zA-Z_][0-9a-zA-Z_]*", Name.Variable),
            (r"[§@][a-zA-Z_][0-9a-zA-Z_]*", Name.Label),
            (r"[a-zA-Z_][0-9a-zA-Z_]*", Name),
            include("numbers"),
            ('"""', String, "mdq_string"),
            ("'''", String, "msq_string"),
            ('"', String, "dq_string"),
            ("'", String, "sq_string"),
            (r".", Text),
        ],
        "numbers": [
            (r".5", Number.Float),
            (r"0[0-7]+j?", Number.Oct),
            (r"0[bB][01]+", Number.Bin),
            (r"0[xX][a-fA-F0-9]+", Number.Hex),
            (r"\d+", Number.Integer),
        ],
        "mdq_string": [('"""', String, "#pop"), ('"', String), include("dq_string")],
        "msq_string": [("'''", String, "#pop"), ("'", String), include("sq_string")],
        "dq_string": [
            ('[^"]+', String),
            ('"', String, "#pop"),
        ],
        "sq_string": [
            ("[^']+", String),
            ("'", String, "#pop"),
        ],
    }
