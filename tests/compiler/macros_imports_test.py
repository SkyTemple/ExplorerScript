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
import os
import unittest

from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.ssb_compiler import ExplorerScriptSsbCompiler


class MacrosImportsTestCase(unittest.TestCase):
    """
    Tests that macros and imports can be correctly resolved and compiled.
    Implicity tests some syntax and general parsing logic.
    TODO: When adding the second test, put the common methods in a base class.
    TODO: We should do more actual checking of the result, instead of just checking
          if it works.
    """
    def test_simple1(self):
        self.assert_can_compile("test_simple1")

    def test_simple2(self):
        self.assert_can_compile("test_simple2")

    def test_simple3_chain(self):
        self.assert_can_compile("test_simple3_chain")

    def test_nested(self):
        self.assert_can_compile("test_nested")

    def test_nested_chain(self):
        self.assert_can_compile("test_nested_chain")

    def test_other_file(self):
        self.assert_can_compile("test_other_file")

    def test_other_two(self):
        self.assert_can_compile("test_other_two")

    def test_complex(self):
        self.assert_can_compile("test_complex")

    def test_err_notfound(self):
        self.assert_can_not_compile("test_err_notfound", SsbCompilerError)

    def test_err_params(self):
        self.assert_can_not_compile("test_err_params", ValueError)

    def test_err_recursion1(self):
        self.assert_can_not_compile("test_err_recursion1", SsbCompilerError)

    def test_err_recursion2(self):
        self.assert_can_not_compile("test_err_recursion2", SsbCompilerError)

    def assert_can_compile(self, fixture_name):
        self.compile(fixture_name)

    def assert_can_not_compile(self, fixture_name, error):
        self.assertRaises(error, self.compile, fixture_name)

    def compile(self, fixture_name):
        fixture_path = self.__fixture_path(fixture_name)
        compiler = ExplorerScriptSsbCompiler(
            "N/A", []
        )
        with open(fixture_path) as f:
            exps_source = f.read()
        compiler.compile(exps_source, fixture_path)

    @staticmethod
    def __fixture_path(fixture_name):
        return os.path.abspath(
            os.path.join(os.path.dirname(__file__),
                         os.pardir,
                         'fixtures',
                         'compiler',
                         'macros_imports_test',
                         fixture_name,
                         'main.exps')
        )
