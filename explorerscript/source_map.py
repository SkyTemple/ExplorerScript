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
import json
from typing import Dict, Tuple, List, Union, Optional


class SourceMapPositionMark:
    """A position mark encoded in the source code of SSBScript / ExplorerScript."""
    def __init__(self, line_number: int, column_number: int, argument_idx: int,
                 name: str, x_offset: int, y_offset: int, x_relative: int, y_relative: int):
        self.line_number = line_number
        self.column_number = column_number
        self.argument_idx = argument_idx
        self.name = name
        self.x_offset = x_offset
        self.y_offset = y_offset
        self.x_relative = x_relative
        self.y_relative = y_relative

    @property
    def x_with_offset(self) -> Union[int, float]:
        """
        Returns the x position with offset, in tiles, as float or int
        See also skytemple_files.script.ssa.position.
        """
        offset = 0
        if self.x_offset == 2 or self.x_offset == 3:
            offset = 0.5
        elif self.x_offset >= 4:
            offset = 2
        return self.x_relative + offset

    @property
    def y_with_offset(self) -> Union[int, float]:
        """
        Returns the x position with offset, in tiles, as float or int
        See also skytemple_files.script.ssa.position.
        """
        offset = 0
        if self.y_offset == 2 or self.y_offset == 3:
            offset = 0.5
        elif self.y_offset >= 4:
            offset = 2
        return self.y_relative + offset

    def __str__(self):
        return f'SourceMapPositionMark<' \
               f'"{self.name}" @{self.line_number}:{self.column_number}:{self.argument_idx} - ' \
               f'{self.x_relative}:{self.x_offset}, {self.y_relative}:{self.y_offset}>)'

    def __eq__(self, other):
        if not isinstance(other, SourceMapPositionMark):
            return False
        return self.line_number == other.line_number and \
                self.column_number == other.column_number and \
                self.argument_idx == other.argument_idx and \
                self.name == other.name and \
                self.x_offset == other.x_offset and \
                self.y_offset == other.y_offset and \
                self.x_relative == other.x_relative and \
                self.y_relative == other.y_relative

    def serialize(self) -> str:
        return json.dumps([
            self.line_number, self.column_number, self.argument_idx,
            self.name, self.x_offset, self.y_offset, self.x_relative, self.y_relative
        ])

    @classmethod
    def deserialize(cls, json_str: str) -> 'SourceMapPositionMark':
        json_d = json.loads(json_str)
        return SourceMapPositionMark(
            line_number=json_d[0], column_number=json_d[1], argument_idx=json_d[2],
            name=json_d[3], x_offset=json_d[4], y_offset=json_d[5], x_relative=json_d[6], y_relative=json_d[7]
        )


class SourceMap:
    """
    A source map for ExplorerScript and SSBScript back to the SSB binary opcodes.
    Takes a routine id and opcode index and returns the line in the source code, that this
    operation is at.

    The mapped addresses are the addresses relative to the first routine opcode address.

    Can be created in the following ways:
    - When loading SSB:
      - For SSBScript:
        - During decompilation.
      - For ExplorerScript:
        - Either during the decompilation, if no ExplorerScript exists yet.
        - From an existing source map file.
    - When compiling SSBScript or ExplorerScript the source map is also generated.

    This also provides information about position marks used in the source file.
    """
    def __init__(
            self,
            mappings: Dict[int, Tuple[int, int]],
            position_marks: List[SourceMapPositionMark],
            mappings_macros: Dict[int, Tuple[Optional[str], str, int, int]],
            position_marks_macro: List[Tuple[Optional[str], str, SourceMapPositionMark]]
    ):
        """
        mappings:               Actual main source mappings:
                                Keys are opcode offsets, values are tuple of line numbers + column
        position_marks:         Encoded position marks
        mappings_macro:         Source mappings in macros.
                                Keys are opcode offsets, values are a tuple of
                                - relative path to source file name (if not in this file; then None)
                                - macro name
                                - line number in the source file of this macro
                                - column
        position_marks_macro:   Position marks encoded in macros. Values are tuple of:
                                - relative file path, macro name, position mark
        """
        self._mappings = mappings
        self._position_marks = position_marks
        # TODO: Make retrievable directly with get_position?
        self._mappings_macros = mappings_macros
        self._position_marks_macro = position_marks_macro

    def get_op_line_and_col__direct(self, op_offset: int) -> Tuple[int, int]:
        if op_offset in self._mappings:
            return self._mappings[op_offset]

    def get_op_line_and_col__macros(self, op_offset: int) -> Tuple[Optional[str], str, int, int]:
        if op_offset in self._mappings_macros:
            return self._mappings_macros[op_offset]
        
    def get_position_marks__direct(self) -> List[SourceMapPositionMark]:
        return self._position_marks

    def get_position_marks__macros(self) -> List[Tuple[Optional[str], str, SourceMapPositionMark]]:
        return self._position_marks_macro

    def __iter__(self):
        """
        Iterates over all source map entries, including the macro entries.
        If it's a macro entry, macro_name is a string.
        """
        for opcode_offset, (line_number, column) in self._mappings.items():
            yield None, None, opcode_offset, line_number, column
        for opcode_offset, (macro_file, macro_name, line_number, column) in self._mappings_macros.items():
            yield macro_file, macro_name, opcode_offset, line_number, column

    def collect_mappings__macros(self):
        for opcode_offset, (macro_file, macro_name, line_number, column) in self._mappings_macros.items():
            yield macro_file, macro_name, opcode_offset, line_number, column

    def __eq__(self, other):
        if not isinstance(other, SourceMap):
            return False
        return self._mappings == other._mappings and self._position_marks == other._position_marks

    def __str__(self):
        return self.serialize()

    def serialize(self, pretty=False) -> str:
        return json.dumps({
            'map': self._mappings,
            'pos_marks': [m.serialize() for m in self._position_marks],
            'macros': {
                'map': self._mappings_macros,
                'pos_marks': [[y[0], y[1], y[2].serialize()] for y in self._position_marks_macro]
            }
        }, indent=2 if pretty else None)

    @classmethod
    def deserialize(cls, json_str: str) -> 'SourceMap':
        json_d = json.loads(json_str)
        return SourceMap(
            {x: (y[0], y[1]) for x, y in json_d['map'].items()},
            [SourceMapPositionMark.deserialize(m) for m in json_d['pos_marks']],
            {x: (y[0], y[1], y[2], y[3]) for x, y in json_d['macros']['map'].items()},
            [(y[0], y[1], SourceMapPositionMark.deserialize(y[2])) for y in json_d['macros']['pos_marks']],
        )

    @classmethod
    def create_empty(cls):
        return cls({}, [], {}, [])


class SourceMapBuilder:
    def __init__(self):
        self._mappings = {}
        self._pos_marks = []
        self._mappings_macros = {}
        self._pos_marks_macros = []

    def add_opcode(self, op_offset, line_number, column):
        self._mappings[op_offset] = (line_number, column)

    def add_position_mark(self, position_mark: SourceMapPositionMark):
        self._pos_marks.append(position_mark)

    def build(self):
        return SourceMap(self._mappings, self._pos_marks, self._mappings_macros, self._pos_marks_macros)

    def add_macro_opcode(self, op_offset, if_incl_rel_path: Optional[str], macro_name: str, line_number, column):
        """Add an operation that has it's source code in a macro.
        If the macro is in a different file, if_incl_rel_path should contain the relative path to this file
        from the original source file that this source map is generated for."""
        self._mappings_macros[op_offset] = (if_incl_rel_path, macro_name, line_number, column)

    def add_macro_position_mark(self, if_incl_rel_path: Optional[str], macro_name: str, position_mark: SourceMapPositionMark):
        """Add a position mark, that has it's source code in a macro. See notes for add_macro_opcode"""
        self._pos_marks_macros.append((if_incl_rel_path, macro_name, position_mark))
