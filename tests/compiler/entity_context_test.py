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

from explorerscript.ssb_converting.ssb_compiler import ExplorerScriptSsbCompiler
from explorerscript.ssb_script.ssb_converting.ssb_decompiler import SsbScriptSsbDecompiler

INLINE_CTX = """
def 0 {
    operation_actor1<actor ACTOR_FOO>(12);
    operation_actor2<actor ACTOR_FOO>(34);
    operation_no_entity(BAZ);
    operation_object1<object OBJECT_BAR>(XYZ);
    operation_object2<object OBJECT_BAR>(0);
    operation_object3<object OBJECT_BAZ>();
    operation_performer<performer 9>();
}
"""

SINGLE_WITH = """
def 0 {
    with (actor ACTOR_FOO) {
        operation_actor1(12);
    }
    with (actor ACTOR_FOO) {
        operation_actor2(34);
    }
    operation_no_entity(BAZ);
    with (object OBJECT_BAR) {
        operation_object1(XYZ);
    }
    with (object OBJECT_BAR) {
        operation_object2(0);
    }
    with (object OBJECT_BAZ) {
        operation_object3();
    }
    with (performer 9) {
        operation_performer();
    }
}
"""

MULTI_WITH = """
def 0 {
    with (actor ACTOR_FOO) {
        operation_actor1(12);
        operation_actor2(34);
    }
    operation_no_entity(BAZ);
    with (object OBJECT_BAR) {
        operation_object1(XYZ);
        operation_object2(0);
    }
    with (object OBJECT_BAZ) {
        operation_object3();
    }
    with (performer 9) {
        operation_performer();
    }
}
"""

EXPECTED_SSBSCRIPT = """
def 0 {
    lives(ACTOR_FOO);
    operation_actor1(12);
    lives(ACTOR_FOO);
    operation_actor2(34);
    operation_no_entity(BAZ);
    object(OBJECT_BAR);
    operation_object1(XYZ);
    object(OBJECT_BAR);
    operation_object2(0);
    object(OBJECT_BAZ);
    operation_object3();
    performer(9);
    operation_performer();
}
"""


class StringTestCase(unittest.TestCase):
    """
    Tests with-statements and inline context statements.
    """

    def test_inline_ctx(self) -> None:
        self.do_test(INLINE_CTX)

    def test_single_with(self) -> None:
        self.do_test(SINGLE_WITH)

    def test_multi_with(self) -> None:
        self.do_test(MULTI_WITH)

    def do_test(self, exps_src: str) -> None:
        compiler = ExplorerScriptSsbCompiler("N/A", [])
        compiler.compile(exps_src, "/dev/null")
        assert compiler.routine_infos is not None
        assert compiler.routine_ops is not None
        produced_ssb_script, _ = SsbScriptSsbDecompiler(
            compiler.routine_infos,
            compiler.routine_ops,  # type: ignore
            [],
        ).convert()
        self.assertEqual(EXPECTED_SSBSCRIPT, produced_ssb_script)
