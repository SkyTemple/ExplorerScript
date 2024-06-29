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

from explorerscript.ssb_converting.ssb_data_types import SsbOpParamConstString, SsbOpParamLanguageString


class StringTestCase(unittest.TestCase):
    """
    Tests decompiled representation of strings.
    """

    def test_single_line(self) -> None:
        self.assertEqual("'foobar'", str(SsbOpParamConstString("foobar")))

    def test_single_line_no_extra_escapes(self) -> None:
        self.assertEqual("'foo\"bar'", str(SsbOpParamConstString('foo"bar')))

    def test_single_line_lang_string(self) -> None:
        self.assertEqual(
            """{
    lang="foobar",
}""",
            str(SsbOpParamLanguageString({"lang": "foobar"})),
        )

    def test_single_line_lang_string_pre_indented(self) -> None:
        lang_string = SsbOpParamLanguageString({"lang": "foobar"})
        lang_string.indent = 2
        self.assertEqual(
            """{
            lang="foobar",
        }""",
            str(lang_string),
        )

    def test_multi_line(self) -> None:
        self.assertEqual(
            """'''
    foo
    bar
'''""",
            str(SsbOpParamConstString("foo\nbar")),
        )

    def test_multi_line_pre_indented(self) -> None:
        param = SsbOpParamConstString("foo\nbar")
        param.indent = 2
        self.assertEqual(
            """'''
            foo
            bar
        '''""",
            str(param),
        )

    def test_multi_line_contains_preferred(self) -> None:
        self.assertEqual(
            '''"""
    foo\'\'\'
    bar
"""''',
            str(SsbOpParamConstString("foo'''\nbar")),
        )

    def test_multi_line_contains_both(self) -> None:
        self.assertEqual(
            "'foo\\'\\'\\'\"\"\"\\nbar'",
            str(SsbOpParamConstString("foo'''\"\"\"\nbar")),
        )

    def test_multi_line_lang_string(self) -> None:
        lang_string = SsbOpParamLanguageString({"lang": "foo\nbar"})
        self.assertEqual(
            '''{
    lang="""
        foo
        bar
    """,
}''',
            str(lang_string),
        )

    def test_multi_line_lang_string_pre_indented(self) -> None:
        lang_string = SsbOpParamLanguageString({"lang": "foo\nbar"})
        lang_string.indent = 2
        self.assertEqual(
            '''{
            lang="""
                foo
                bar
            """,
        }''',
            str(lang_string),
        )

    def test_multi_line_lang_string_pre_indented_two_langs(self) -> None:
        lang_string = SsbOpParamLanguageString({"lang": "foo\nbar", "lang2": 'baz"""\nbuzz'})
        lang_string.indent = 2
        self.assertEqual(
            '''{
            lang="""
                foo
                bar
            """,
            lang2=\'\'\'
                baz"""
                buzz
            \'\'\',
        }''',
            str(lang_string),
        )
