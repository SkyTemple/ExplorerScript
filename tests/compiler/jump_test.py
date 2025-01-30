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

from explorerscript.ssb_converting.ssb_compiler import ExplorerScriptSsbCompiler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation

LOOPING_SCRIPT = """
def 0 {
    @foo;
    me_Stop();
    jump @foo;
    end;
}
"""

SELF_LOOPING_SCRIPT = """
def 0 {
    @foo;
    jump @foo;
    end;
}
"""


class StringTestCase(unittest.TestCase):
    """
    Tests compilation of jumps.
    """

    def test_looping_exps(self) -> None:
        routine_ops = self.compile_exps(LOOPING_SCRIPT)
        self.assertEqual(1, len(routine_ops))
        routine = routine_ops[0]
        self.assertEqual(3, len(routine))

        # FIRST OP
        op_to_check = routine[0]
        self.assertEqual("me_Stop", op_to_check.op_code.name)
        self.assertEqual(1, op_to_check.offset)
        self.assertEqual(0, len(op_to_check.params))

        # SECOND OP
        op_to_check = routine[1]
        self.assertEqual("Jump", op_to_check.op_code.name)
        self.assertEqual(2, op_to_check.offset)
        self.assertEqual(1, len(op_to_check.params))
        self.assertIs(1, op_to_check.params[0])

        # THIRD OP
        op_to_check = routine[2]
        self.assertEqual("End", op_to_check.op_code.name)
        self.assertEqual(3, op_to_check.offset)
        self.assertEqual(0, len(op_to_check.params))

    def test_self_looping_exps(self) -> None:
        routine_ops = self.compile_exps(SELF_LOOPING_SCRIPT)

        self.assertEqual(1, len(routine_ops))
        routine = routine_ops[0]
        self.assertEqual(2, len(routine))

        # FIRST OP
        op_to_check = routine[0]
        self.assertEqual("Jump", op_to_check.op_code.name)
        self.assertEqual(1, op_to_check.offset)
        self.assertEqual(1, len(op_to_check.params))
        self.assertIs(1, op_to_check.params[0])

        # SECOND OP
        op_to_check = routine[1]
        self.assertEqual("End", op_to_check.op_code.name)
        self.assertEqual(2, op_to_check.offset)
        self.assertEqual(0, len(op_to_check.params))

    def compile_exps(self, src: str) -> list[list[SsbOperation]]:
        compiler = ExplorerScriptSsbCompiler("N/A", [])
        compiler.compile(src, "/dev/null")
        assert compiler.routine_ops
        return compiler.routine_ops
