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
import os.path
import unittest
from tempfile import TemporaryDirectory

from explorerscript.ssb_converting.ssb_compiler import ExplorerScriptSsbCompiler
from explorerscript.ssb_script.ssb_converting.ssb_decompiler import SsbScriptSsbDecompiler

INCLUDED_EXPS = """
const INCLUDED_CONST = 99;

macro macroTest($var1, $var2) {
    inMacro(BAR, FOO, INCLUDED_CONST, $var1, $var2);
} 

"""

INPUT_EXPS = """
import "included.exps";

const FOO = 12;
def 0 {
    const BAR = "Hello";
    const BAZ = FOO;
    const BUZZ = ACTOR_ONE;
    const INCLUDED = INCLUDED_CONST;
    myOperation(BAR, 12, BAZ, BUZZ, OBJECT_TWO);
    included(INCLUDED, INCLUDED_CONST);
    after(AFTER, AFTER_TWO);
    ~macroTest(BAR, FOO);
}

def 1 {
    const BAR = "Second";
    myOperationInTwo(BAR, FOO, BUZZ);
    included(INCLUDED, INCLUDED_CONST);
    after(AFTER, AFTER_TWO);
}

const AFTER = FOO;
const AFTER_TWO = {
    english="lang string"
};

"""

EXPECTED_SSB_SCRIPT = """
def 0 {
    myOperation('Hello', 12, 12, ACTOR_ONE, OBJECT_TWO);
    included(99, 99);
    after(12, {
        english="lang string",
    });
    inMacro(BAR, FOO, 99, 'Hello', 12);
}

def 1 {
    myOperationInTwo('Second', 12, BUZZ);
    included(INCLUDED, 99);
    after(12, {
        english="lang string",
    });
}
"""


class UserConstantsMacrosIncludesTestCase(unittest.TestCase):
    """
    Tests macros, includes and user-defined constants.
    """

    def test_compile(self) -> None:
        with TemporaryDirectory() as tempdir:
            with open(os.path.join(tempdir, "included.exps"), "w") as f:
                f.write(INCLUDED_EXPS)
            compiler = ExplorerScriptSsbCompiler("N/A", [tempdir])
            compiler.compile(INPUT_EXPS, "/dev/null")

            assert compiler.routine_infos is not None
            assert compiler.routine_ops is not None
            ssbscript_decompiler = SsbScriptSsbDecompiler(
                compiler.routine_infos,
                compiler.routine_ops,  # type: ignore
                [],
            )
            ssbscript, _ = ssbscript_decompiler.convert()

            self.assertEqual(EXPECTED_SSB_SCRIPT.strip(), ssbscript.strip())
