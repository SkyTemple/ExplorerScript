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
import unittest
from typing import Callable, TYPE_CHECKING

from explorerscript.ssb_converting.ssb_compiler import ExplorerScriptSsbCompiler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParamConstString, SsbOpParamLanguageString
from explorerscript.ssb_script.ssb_converting.ssb_compiler import SsbScriptSsbCompiler

TEMPLATE = """
def 0 {{
    foo({});
    bar({{language={}}});
}}
"""

SIMPLE_DOUBLEQ_STRING = ('"Foobar"', "Foobar")
SIMPLE_SINGLEQ_STRING = ("'Foobar'", "Foobar")
ESCAPED_DOUBLEQ_STRING = (r'"Before\"After"', 'Before"After')
ESCAPED_SINGLEQ_STRING = (r"'Before\'After'", "Before'After")
OTHER_ESCAPED_DOUBLEQ_STRING = (r'"Before\'After"', "Before'After")
OTHER_ESCAPED_SINGLEQ_STRING = (r"'Before\"After'", 'Before"After')
NEWLINE_DOUBLEQ_STRING = (r'"Foo\nBar"', "Foo\nBar")
NEWLINE_SINGLEQ_STRING = (r"'Foo\nBar'", "Foo\nBar")
BACKSLASH_DOUBLEQ_STRING = (r'"Foo\\Bar\\"', r"Foo\\Bar\\")
BACKSLASH_SINGLEQ_STRING = (r"'Foo\\Bar\\'", r"Foo\\Bar\\")

MULTILINE_SINGLELINE_DOUBLEQ_STRING = ('"""FooBar"""', "FooBar")
MULTILINE_SINGLELINE_SINGLEQ_STRING = ("'''FooBar'''", "FooBar")
MULTILINE_SIMPLE_DOUBLEQ_STRING = ('"""Foo\nBar"""', "Foo\nBar")
MULTILINE_SIMPLE_SINGLEQ_STRING = ("'''Foo\nBar'''", "Foo\nBar")
MULTILINE_START_INDENT_DOUBLEQ_STRING = ('"""    Foo\nBar"""', "    Foo\nBar")
MULTILINE_START_INDENT_SINGLEQ_STRING = ("'''    Foo\nBar'''", "    Foo\nBar")
MULTILINE_HANGING_SIMPLE_DOUBLEQ_STRING = ('"""Foo\n    Bar"""', "Foo\nBar")
MULTILINE_HANGING_SIMPLE_SINGLEQ_STRING = ("'''Foo\n    Bar'''", "Foo\nBar")
MULTILINE_HANGING_SIMPLE_EXTRA_LINE_DOUBLEQ_STRING = ('"""\n        Foo\n        Bar\n    """', "Foo\nBar")
MULTILINE_HANGING_SIMPLE_EXTRA_LINE_SINGLEQ_STRING = ("'''\n        Foo\n        Bar\n     '''", "Foo\nBar")
MULTILINE_HANGING_SIMPLE_EXTRA_LINE_PRE_DOUBLEQ_STRING = ('"""Pre\n        Foo\n        Bar\n    """', "Pre\nFoo\nBar")
MULTILINE_HANGING_SIMPLE_EXTRA_LINE_PRE_SINGLEQ_STRING = ("'''Pre\n        Foo\n        Bar\n     '''", "Pre\nFoo\nBar")
MULTILINE_COMPLEX_INDENTS_DOUBLEQ_STRING = (
    '"""\n           ok\n        Foo\n        Bar\n            What?\n              I don\'t know\n    """',
    "   ok\nFoo\nBar\n    What?\n      I don't know",
)
MULTILINE_COMPLEX_INDENTS_SINGLEQ_STRING = (
    "'''\n           ok\n        Foo\n        Bar\n            What?\n              I don't know\n    '''",
    "   ok\nFoo\nBar\n    What?\n      I don't know",
)
MULTILINE_ESCAPES_DOUBLEQ_STRING = (r'"""X\nY\\Z\"A\'B"""', r"X\nY\\Z\"A\'B")
MULTILINE_ESCAPES_SINGLEQ_STRING = (r"'''X\nY\\Z\"A\'B'''", r"X\nY\\Z\"A\'B")

MULTILINE_DOCTEST_A = (
    """'''First Line
      Second Line
        Some indentation in the third line
      Fourth Line
             '''""",
    "First Line\nSecond Line\n  Some indentation in the third line\nFourth Line",
)
MULTILINE_DOCTEST_B = (
    '''"""
      First Line
      Second Line
        Some indentation in the third line
      Fourth Line"""''',
    "First Line\nSecond Line\n  Some indentation in the third line\nFourth Line",
)
MULTILINE_DOCTEST_C = (
    '''"""
      First Line
      Second Line
        Some indentation in the third line
           Fourth Line"""''',
    "First Line\nSecond Line\n  Some indentation in the third line\n     Fourth Line",
)


class StringTestCase(unittest.TestCase):
    """
    Tests compilation of strings.
    """

    def test_simple_doubleq_ssbscript(self) -> None:
        self.do_test_string(SIMPLE_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_simple_singleq_ssbscript(self) -> None:
        self.do_test_string(SIMPLE_SINGLEQ_STRING, self.compile_ssbscript)

    def test_escaped_doubleq_ssbscript(self) -> None:
        self.do_test_string(ESCAPED_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_escaped_singleq_ssbscript(self) -> None:
        self.do_test_string(ESCAPED_SINGLEQ_STRING, self.compile_ssbscript)

    def test_other_escaped_doubleq_ssbscript(self) -> None:
        self.do_test_string(OTHER_ESCAPED_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_other_escaped_singleq_ssbscript(self) -> None:
        self.do_test_string(OTHER_ESCAPED_SINGLEQ_STRING, self.compile_ssbscript)

    def test_newline_doubleq_ssbscript(self) -> None:
        self.do_test_string(NEWLINE_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_newline_singleq_ssbscript(self) -> None:
        self.do_test_string(NEWLINE_SINGLEQ_STRING, self.compile_ssbscript)

    def test_backslash_doubleq_ssbscript(self) -> None:
        self.do_test_string(BACKSLASH_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_backslash_singleq_ssbscript(self) -> None:
        self.do_test_string(BACKSLASH_SINGLEQ_STRING, self.compile_ssbscript)

    def test_multiline_singleline_doubleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_SINGLELINE_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_multiline_singleline_singleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_SINGLELINE_SINGLEQ_STRING, self.compile_ssbscript)

    def test_multiline_simple_doubleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_SIMPLE_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_multiline_simple_singleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_SIMPLE_SINGLEQ_STRING, self.compile_ssbscript)

    def test_multiline_start_indent_doubleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_START_INDENT_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_multiline_start_indent_singleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_START_INDENT_SINGLEQ_STRING, self.compile_ssbscript)

    def test_multiline_hanging_simple_doubleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_multiline_hanging_simple_singleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_SINGLEQ_STRING, self.compile_ssbscript)

    def test_multiline_hanging_simple_extra_line_doubleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_EXTRA_LINE_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_multiline_hanging_simple_extra_line_singleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_EXTRA_LINE_SINGLEQ_STRING, self.compile_ssbscript)

    def test_multiline_hanging_simple_extra_line_pre_doubleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_EXTRA_LINE_PRE_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_multiline_hanging_simple_extra_line_pre_singleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_EXTRA_LINE_PRE_SINGLEQ_STRING, self.compile_ssbscript)

    def test_multiline_complex_indents_doubleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_COMPLEX_INDENTS_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_multiline_complex_indents_singleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_COMPLEX_INDENTS_SINGLEQ_STRING, self.compile_ssbscript)

    def test_multiline_escapes_doubleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_ESCAPES_DOUBLEQ_STRING, self.compile_ssbscript)

    def test_multiline_escapes_singleq_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_ESCAPES_SINGLEQ_STRING, self.compile_ssbscript)

    def test_multiline_doctest_a_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_DOCTEST_A, self.compile_ssbscript)

    def test_multiline_doctest_b_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_DOCTEST_B, self.compile_ssbscript)

    def test_multiline_doctest_c_ssbscript(self) -> None:
        self.do_test_string(MULTILINE_DOCTEST_C, self.compile_ssbscript)

    def test_simple_doubleq_exps(self) -> None:
        self.do_test_string(SIMPLE_DOUBLEQ_STRING, self.compile_exps)

    def test_simple_singleq_exps(self) -> None:
        self.do_test_string(SIMPLE_SINGLEQ_STRING, self.compile_exps)

    def test_escaped_doubleq_exps(self) -> None:
        self.do_test_string(ESCAPED_DOUBLEQ_STRING, self.compile_exps)

    def test_escaped_singleq_exps(self) -> None:
        self.do_test_string(ESCAPED_SINGLEQ_STRING, self.compile_exps)

    def test_other_escaped_doubleq_exps(self) -> None:
        self.do_test_string(OTHER_ESCAPED_DOUBLEQ_STRING, self.compile_exps)

    def test_other_escaped_singleq_exps(self) -> None:
        self.do_test_string(OTHER_ESCAPED_SINGLEQ_STRING, self.compile_exps)

    def test_newline_doubleq_exps(self) -> None:
        self.do_test_string(NEWLINE_DOUBLEQ_STRING, self.compile_exps)

    def test_newline_singleq_exps(self) -> None:
        self.do_test_string(NEWLINE_SINGLEQ_STRING, self.compile_exps)

    def test_backslash_doubleq_exps(self) -> None:
        self.do_test_string(BACKSLASH_DOUBLEQ_STRING, self.compile_exps)

    def test_backslash_singleq_exps(self) -> None:
        self.do_test_string(BACKSLASH_SINGLEQ_STRING, self.compile_exps)

    def test_multiline_singleline_doubleq_exps(self) -> None:
        self.do_test_string(MULTILINE_SINGLELINE_DOUBLEQ_STRING, self.compile_exps)

    def test_multiline_singleline_singleq_exps(self) -> None:
        self.do_test_string(MULTILINE_SINGLELINE_SINGLEQ_STRING, self.compile_exps)

    def test_multiline_simple_doubleq_exps(self) -> None:
        self.do_test_string(MULTILINE_SIMPLE_DOUBLEQ_STRING, self.compile_exps)

    def test_multiline_simple_singleq_exps(self) -> None:
        self.do_test_string(MULTILINE_SIMPLE_SINGLEQ_STRING, self.compile_exps)

    def test_multiline_start_indent_doubleq_exps(self) -> None:
        self.do_test_string(MULTILINE_START_INDENT_DOUBLEQ_STRING, self.compile_exps)

    def test_multiline_start_indent_singleq_exps(self) -> None:
        self.do_test_string(MULTILINE_START_INDENT_SINGLEQ_STRING, self.compile_exps)

    def test_multiline_hanging_simple_doubleq_exps(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_DOUBLEQ_STRING, self.compile_exps)

    def test_multiline_hanging_simple_singleq_exps(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_SINGLEQ_STRING, self.compile_exps)

    def test_multiline_hanging_simple_extra_line_doubleq_exps(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_EXTRA_LINE_DOUBLEQ_STRING, self.compile_exps)

    def test_multiline_hanging_simple_extra_line_singleq_exps(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_EXTRA_LINE_SINGLEQ_STRING, self.compile_exps)

    def test_multiline_hanging_simple_extra_line_pre_doubleq_exps(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_EXTRA_LINE_PRE_DOUBLEQ_STRING, self.compile_exps)

    def test_multiline_hanging_simple_extra_line_pre_singleq_exps(self) -> None:
        self.do_test_string(MULTILINE_HANGING_SIMPLE_EXTRA_LINE_PRE_SINGLEQ_STRING, self.compile_exps)

    def test_multiline_complex_indents_doubleq_exps(self) -> None:
        self.do_test_string(MULTILINE_COMPLEX_INDENTS_DOUBLEQ_STRING, self.compile_exps)

    def test_multiline_complex_indents_singleq_exps(self) -> None:
        self.do_test_string(MULTILINE_COMPLEX_INDENTS_SINGLEQ_STRING, self.compile_exps)

    def test_multiline_escapes_doubleq_exps(self) -> None:
        self.do_test_string(MULTILINE_ESCAPES_DOUBLEQ_STRING, self.compile_exps)

    def test_multiline_escapes_singleq_exps(self) -> None:
        self.do_test_string(MULTILINE_ESCAPES_SINGLEQ_STRING, self.compile_exps)

    def test_multiline_doctest_a_exps(self) -> None:
        self.do_test_string(MULTILINE_DOCTEST_A, self.compile_exps)

    def test_multiline_doctest_b_exps(self) -> None:
        self.do_test_string(MULTILINE_DOCTEST_B, self.compile_exps)

    def test_multiline_doctest_c_exps(self) -> None:
        self.do_test_string(MULTILINE_DOCTEST_C, self.compile_exps)

    def do_test_string(
        self, src_expected: tuple[str, str], compile_func: Callable[[str], list[list[SsbOperation]]]
    ) -> None:
        src, expected = src_expected
        routine_ops = compile_func(TEMPLATE.format(src, src))
        self.assertEqual(1, len(routine_ops))
        routine = routine_ops[0]
        self.assertEqual(2, len(routine))

        normal_string_op = routine[0]
        self.assertEqual("foo", normal_string_op.op_code.name)
        self.assertEqual(1, len(normal_string_op.params))
        self.assertIsInstance(normal_string_op.params[0], SsbOpParamConstString)
        if TYPE_CHECKING:
            assert isinstance(normal_string_op.params[0], SsbOpParamConstString)
        self.assertEqual(expected, normal_string_op.params[0].name)

        lang_string_op = routine[1]
        self.assertEqual("bar", lang_string_op.op_code.name)
        self.assertEqual(1, len(lang_string_op.params))
        self.assertIsInstance(lang_string_op.params[0], SsbOpParamLanguageString)
        if TYPE_CHECKING:
            assert isinstance(lang_string_op.params[0], SsbOpParamLanguageString)
        self.assertEqual(1, len(lang_string_op.params[0].strings))
        self.assertIn("language", lang_string_op.params[0].strings)
        self.assertEqual(expected, lang_string_op.params[0].strings["language"])

    def compile_ssbscript(self, src: str) -> list[list[SsbOperation]]:
        compiler = SsbScriptSsbCompiler()
        compiler.compile(src)
        assert compiler.routine_ops
        return compiler.routine_ops

    def compile_exps(self, src: str) -> list[list[SsbOperation]]:
        compiler = ExplorerScriptSsbCompiler("N/A", [])
        compiler.compile(src, "/dev/null")
        assert compiler.routine_ops
        return compiler.routine_ops
