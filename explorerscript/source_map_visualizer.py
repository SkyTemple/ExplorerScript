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

from explorerscript.source_map import SourceMap, MacroSourceMapping


class SourceMapVisualizer:
    """Visualizes a source map by adding comments to it's source code pointing to the opcodes."""

    source_code: str
    source_map: SourceMap
    _inserts: dict[int, list[str]]

    def __init__(self, source_code: str, source_map: SourceMap, apply_for_macro_calls: str | None = None):
        self.source_code = source_code
        self._source_map = source_map
        # A dict of a list of strings to insert at given lines
        self._inserts = {}

        # Opcodes
        for opcode_offset, mapping in self._source_map:
            if not isinstance(mapping, MacroSourceMapping):
                if apply_for_macro_calls is None:
                    self._insert_comment(mapping.line, f"col: {mapping.column} - 0x{opcode_offset:0x}")
            else:
                if mapping.relpath_included_file == apply_for_macro_calls:
                    self._insert_comment(
                        mapping.line,
                        f"~{mapping.macro_name}:: "
                        f"col: {mapping.column} - 0x{opcode_offset:0x}"
                        f" - [StepOut -> 0x{mapping.return_addr:0x}] "
                        f"[{mapping.parameter_mapping}]",
                    )
                if mapping.called_in:
                    called_in_file, called_in_line, called_in_col = mapping.called_in
                    if called_in_file == apply_for_macro_calls:
                        self._insert_comment(
                            called_in_line,
                            f"col: {called_in_col} - 0x{opcode_offset:0x} (CALL TO ~{mapping.macro_name})",
                        )
        # Position Marks
        for pos_mark in self._source_map.get_position_marks__direct():
            self._insert_comment(pos_mark.line_number, f"{pos_mark}")

    def write(self) -> str:
        string_array = []
        for original_line_number, line_content in enumerate(self.source_code.split("\n")):
            if original_line_number in self._inserts:
                for comment in self._inserts[original_line_number]:
                    string_array.append(comment)
            string_array.append(line_content)
        return "\n".join(string_array)

    def _insert_comment(self, line_number: int, txt: str) -> None:
        if line_number not in self._inserts:
            self._inserts[line_number] = []
        self._inserts[line_number].append(f"// {txt}")
