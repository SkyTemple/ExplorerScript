#  MIT License
#
#  Copyright (c) 2020-2024 Capypara and the SkyTemple Contributors
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

from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.ssb_compiler import ExplorerScriptSsbCompiler
from explorerscript.ssb_converting.ssb_data_types import SsbOpParamPositionMarker
from explorerscript.ssb_script.ssb_converting.ssb_compiler import SsbScriptSsbCompiler


NO_DECIMAL = """def 0 { foobar(Position<'', 123, 456>); }"""
NO_DECIMAL_EXPECTED = [SsbOpParamPositionMarker("", 0, 0, 123, 456)]
DECIMAL = """def 0 { foobar(Position<'', 123.0, 456.500>); }"""
DECIMAL_EXPECTED = [SsbOpParamPositionMarker("", 0, 2, 123, 456)]
OPOINT_DECIMAL = """def 0 { foobar(Position<'', .0, .5>); }"""
OPOINT_DECIMAL_EXPECTED = [SsbOpParamPositionMarker("", 0, 2, 0, 0)]
INVALID_DECIMAL = """def 0 { foobar(Position<'', 123.1, 456>); }"""
NEGATIVE_NO_DECIMAL = """def 0 { foobar(Position<'', -123, -456>); }"""
NEGATIVE_NO_DECIMAL_EXPECTED = [SsbOpParamPositionMarker("", 0, 0, -123, -456)]
NEGATIVE_DECIMAL = """def 0 { foobar(Position<'', -123.0, -456.500>); }"""
NEGATIVE_DECIMAL_EXPECTED = [SsbOpParamPositionMarker("", 0, 2, -123, -456)]
NEGATIVE_INVALID_DECIMAL = """def 0 { foobar(Position<'', -123.1, 456>); }"""


class PositionMarkArgTestCase(unittest.TestCase):
    """
    Tests that position mark arguments are correctly compiled.
    """

    def test_no_decimal_ssbscript(self):
        self.assertEqual(NO_DECIMAL_EXPECTED, self.compile_ssbscript(NO_DECIMAL))

    def test_no_decimal_exps(self):
        self.assertEqual(NO_DECIMAL_EXPECTED, self.compile_exps(NO_DECIMAL))

    def test_decimal_ssbscript(self):
        self.assertEqual(DECIMAL_EXPECTED, self.compile_ssbscript(DECIMAL))

    def test_decimal_exps(self):
        self.assertEqual(DECIMAL_EXPECTED, self.compile_exps(DECIMAL))

    def test_opoint_decimal_ssbscript(self):
        self.assertEqual(OPOINT_DECIMAL_EXPECTED, self.compile_ssbscript(OPOINT_DECIMAL))

    def test_opoint_decimal_exps(self):
        self.assertEqual(OPOINT_DECIMAL_EXPECTED, self.compile_exps(OPOINT_DECIMAL))

    def test_invalid_decimal_ssbscript(self):
        self.assertRaises(SsbCompilerError, lambda: self.compile_ssbscript(INVALID_DECIMAL))

    def test_invalid_decimal_exps(self):
        self.assertRaises(SsbCompilerError, lambda: self.compile_exps(INVALID_DECIMAL))

    def test_negative_no_decimal_ssbscript(self):
        self.assertEqual(NEGATIVE_NO_DECIMAL_EXPECTED, self.compile_ssbscript(NEGATIVE_NO_DECIMAL))

    def test_negative_no_decimal_exps(self):
        self.assertEqual(NEGATIVE_NO_DECIMAL_EXPECTED, self.compile_exps(NEGATIVE_NO_DECIMAL))

    def test_negative_decimal_ssbscript(self):
        self.assertEqual(NEGATIVE_DECIMAL_EXPECTED, self.compile_ssbscript(NEGATIVE_DECIMAL))

    def test_negative_decimal_exps(self):
        self.assertEqual(NEGATIVE_DECIMAL_EXPECTED, self.compile_exps(NEGATIVE_DECIMAL))

    def test_negative_invalid_decimal_ssbscript(self):
        self.assertRaises(SsbCompilerError, lambda: self.compile_ssbscript(NEGATIVE_INVALID_DECIMAL))

    def test_negative_invalid_decimal_exps(self):
        self.assertRaises(SsbCompilerError, lambda: self.compile_exps(NEGATIVE_INVALID_DECIMAL))

    def compile_ssbscript(self, src: str):
        compiler = SsbScriptSsbCompiler()
        compiler.compile(src)
        assert compiler.routine_ops
        return compiler.routine_ops[0][0].params

    def compile_exps(self, src: str):
        compiler = ExplorerScriptSsbCompiler("N/A", [])
        compiler.compile(src, "/dev/null")
        assert compiler.routine_ops
        return compiler.routine_ops[0][0].params
