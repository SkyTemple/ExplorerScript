#  MIT License
#
#  Copyright (c) 2020 Parakoopa
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
from typing import List, Dict

from explorerscript.source_map import SourceMap


class SourceMapVisualizer:
    """Visualizes a source map by adding comments to it's source code pointing to the opcodes."""
    def __init__(self, source_code: str, source_map: SourceMap):
        self.source_code = source_code
        self._source_map = source_map
        # A dict of a list of strings to insert at given lines
        self._inserts: Dict[int, List[str]] = {}

        # Opcodes
        for opcode_offset, line_number, column in self._source_map:
            self._insert_comment(line_number, f'col: {column} - 0x{opcode_offset:0x}')
        # Position Marks
        for pos_mark in self._source_map.position_marks:
            self._insert_comment(pos_mark.line_number, f'{pos_mark}')

    def write(self) -> str:
        string_array = []
        for original_line_number, line_content in enumerate(self.source_code.split('\n')):
            if original_line_number in self._inserts:
                for comment in self._inserts[original_line_number]:
                    string_array.append(comment)
            string_array.append(line_content)
        return '\n'.join(string_array)

    def _insert_comment(self, line_number, txt):
        if line_number not in self._inserts:
            self._inserts[line_number] = []
        self._inserts[line_number].append(f'// {txt}')