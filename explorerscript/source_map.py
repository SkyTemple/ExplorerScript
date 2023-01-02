#  MIT License
#
#  Copyright (c) 2020-2023 Capypara and the SkyTemple Contributors
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
import logging
from typing import Dict, Tuple, List, Union, Optional, Iterable
logger = logging.getLogger(__name__)


class SourceMapPositionMark:
    """A position mark encoded in the source code of SSBScript / ExplorerScript."""
    def __init__(self, line_number: int, column_number: int, end_line_number: int, end_column_number: int,
                 name: str, x_offset: int, y_offset: int, x_relative: int, y_relative: int):
        self.line_number = line_number
        self.column_number = column_number
        self.end_line_number = end_line_number
        self.end_column_number = end_column_number
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
               f'"{self.name}" @{self.line_number}:{self.column_number}->{self.end_line_number}:{self.end_column_number} - ' \
               f'{self.x_relative}:{self.x_offset}, {self.y_relative}:{self.y_offset}>)'

    def __repr__(self):
        return str(self)

    def __eq__(self, other):
        if not isinstance(other, SourceMapPositionMark):
            return False
        return self.line_number == other.line_number and \
                self.column_number == other.column_number and \
                self.end_line_number == other.end_line_number and \
                self.end_column_number == other.end_column_number and \
                self.name == other.name and \
                self.x_offset == other.x_offset and \
                self.y_offset == other.y_offset and \
                self.x_relative == other.x_relative and \
                self.y_relative == other.y_relative

    def serialize(self) -> list:
        return [
            self.line_number, self.column_number, self.end_line_number, self.end_column_number,
            self.name, self.x_offset, self.y_offset, self.x_relative, self.y_relative
        ]

    @classmethod
    def deserialize(cls, data_list) -> 'SourceMapPositionMark':
        return SourceMapPositionMark(
            line_number=data_list[0], column_number=data_list[1],
            end_line_number=data_list[2], end_column_number=data_list[3],
            name=data_list[4], x_offset=data_list[5], y_offset=data_list[6],
            x_relative=data_list[7], y_relative=data_list[8]
        )


class SourceMapping:
    def __init__(self, line_number: int, column: int):
        self.line = line_number
        self.column = column

    def serialize(self) -> list:
        return [
            self.line, self.column
        ]

    @classmethod
    def deserialize(cls, data_list) -> 'SourceMapping':
        return SourceMapping(
            data_list[0], data_list[1]
        )


class MacroSourceMapping(SourceMapping):
    def __init__(self, relpath_included_file: str, macro_name: str,
                 line_number: int, column: int,
                 called_in: Optional[Tuple[str, int, int]],
                 return_addr: Optional[int], parameter_mapping: Dict[str, Union[int, str]]):
        super().__init__(line_number, column)
        self.relpath_included_file = relpath_included_file
        self.macro_name = macro_name
        self.return_addr = return_addr
        # If this is the first operation in a Macro, this field contains the line number and column
        # of the Macro call
        # Tuple contains relative_included_file, line number, column number of the call file.
        self.called_in = called_in
        # The opcode address to jump to when stepping out of this macro
        self.return_addr = return_addr
        # The mapping of parameter values for the current macro context, only for informational
        # purposes. Contains the string representation or integer value
        self.parameter_mapping = parameter_mapping

    def serialize(self) -> list:
        return [
            self.relpath_included_file, self.macro_name, self.line, self.column,
            self.called_in, self.return_addr, self.parameter_mapping
        ]

    @classmethod
    def deserialize(cls, data_list) -> 'MacroSourceMapping':
        return MacroSourceMapping(
            data_list[0], data_list[1], data_list[2], data_list[3], data_list[4], data_list[5], data_list[6]
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
            mappings: Dict[int, SourceMapping],
            position_marks: List[SourceMapPositionMark],
            mappings_macros: Dict[int, MacroSourceMapping],
            position_marks_macro: List[Tuple[Optional[str], str, SourceMapPositionMark]]
    ):
        """
        mappings:               Actual main source mappings:
                                Keys are opcode offsets, values are the source mapping
        position_marks:         Encoded position marks
        mappings_macro:         Source mappings in macros.
                                Keys are opcode offsets, values are the macro source mapping
        position_marks_macro:   Position marks encoded in macros. Values are tuple of:
                                - relative file path, macro name, position mark
        """
        self._mappings = mappings
        self._position_marks = position_marks
        self._mappings_macros = mappings_macros
        self._position_marks_macro = position_marks_macro

    @property
    def is_empty(self):
        return len(self._mappings) == 0

    def get_op_line_and_col(self, op_offset: int) -> Optional[SourceMapping]:
        if op_offset in self._mappings:
            return self._mappings[op_offset]
        if op_offset in self._mappings_macros:
            return self._mappings_macros[op_offset]

    def get_op_line_and_col__direct(self, op_offset: int) -> Optional[SourceMapping]:
        if op_offset in self._mappings:
            return self._mappings[op_offset]

    def get_op_line_and_col__macros(self, op_offset: int) -> Optional[MacroSourceMapping]:
        if op_offset in self._mappings_macros:
            return self._mappings_macros[op_offset]
        
    def get_position_marks__direct(self) -> List[SourceMapPositionMark]:
        return self._position_marks

    def get_position_marks__macros(self) -> List[Tuple[Optional[str], str, SourceMapPositionMark]]:
        return self._position_marks_macro

    def __iter__(self) -> Iterable[Tuple[int, MacroSourceMapping]]:
        """
        Iterates over all source map entries, including the macro entries.
        If it's a macro entry, macro_name is a string.
        """
        for opcode_offset, entry in self._mappings.items():
            yield opcode_offset, entry
        for opcode_offset, entry in self._mappings_macros.items():
            yield opcode_offset, entry

    def collect_mappings__macros(self) -> Iterable[Tuple[int, MacroSourceMapping]]:
        for opcode_offset, entry in self._mappings_macros.items():
            yield opcode_offset, entry

    def __eq__(self, other):
        if not isinstance(other, SourceMap):
            return False
        return self._mappings == other._mappings and self._position_marks == other._position_marks

    def __str__(self):
        return self.serialize()

    def serialize(self, pretty=False) -> str:
        return json.dumps({
            'map': {int(x): m.serialize() for x, m in self._mappings.items()},
            'pos_marks': [m.serialize() for m in self._position_marks],
            'macros': {
                'map': {int(x): m.serialize() for x, m in self._mappings_macros.items()},
                'pos_marks': [[y[0], y[1], y[2].serialize()] for y in self._position_marks_macro]
            }
        }, indent=2 if pretty else None)

    @classmethod
    def deserialize(cls, json_str: str) -> 'SourceMap':
        json_d = json.loads(json_str)
        return SourceMap(
            {int(x): SourceMapping.deserialize(y) for x, y in json_d['map'].items()},
            [SourceMapPositionMark.deserialize(m) for m in json_d['pos_marks']],
            {int(x): MacroSourceMapping.deserialize(y) for x, y in json_d['macros']['map'].items()},
            [(y[0], y[1], SourceMapPositionMark.deserialize(y[2])) for y in json_d['macros']['pos_marks']]
        )

    @classmethod
    def create_empty(cls):
        return cls({}, [], {}, [])

    def rewrite_offsets(self, new_mapping: Dict[int, int]):
        """
        Replace all opcode offsets (in mappings, macrco mappings, macro return addresses) with new
        offsets. The parameter is a dict mapping old offsets to new offsets.
        """
        # It may happen, that the new mapping contains fewer opcodes than originally added (eg. if they were optimized)
        # but that's ok.
        self._mappings = {new_mapping[key]: val for key, val in self._mappings.items() if key in new_mapping}
        self._mappings_macros = {new_mapping[key]: val for key, val in self._mappings_macros.items() if key in new_mapping}
        max_old_offset = max(new_mapping.keys())

        for m in self._mappings_macros.values():
            if m.return_addr:
                addr = m.return_addr
                while addr not in new_mapping:
                    # if the return addr opcode was optimized away, we take the next index. TODO: Good idea?
                    addr += 1
                    if addr > max_old_offset:
                        addr = None
                        break
                if addr is not None:
                    m.return_addr = new_mapping[addr]


class SourceMapBuilder:
    def __init__(self):
        self._mappings = {}
        self._pos_marks = []
        self._mappings_macros = {}
        self._pos_marks_macros = []
        self._next_macro_called_in: Optional[SourceMapping] = None
        self._macro_context__stack: List[Tuple[int, Dict[str, Union[int, str]]]] = []
        #logger.debug("<%d>: Init.", id(self))

    def add_opcode(self, op_offset, line_number, column):
        self._mappings[op_offset] = SourceMapping(line_number, column)
        #logger.debug("<%d>: Adding opcode: %d -> %d, %d", id(self), op_offset, line_number, column)

    def add_position_mark(self, position_mark: SourceMapPositionMark):
        self._pos_marks.append(position_mark)
        #logger.debug("<%d>: Adding PositionMark: %s", id(self), position_mark)

    def macro_context__push(self, opcode_to_jump_to: int, parameter_mapping: Dict[str, Union[int, str]]):
        """
        Push a new macro return address and parameter mapping to the stack, all added macro ops will
        use what's on the top of the stack.
        """
        self._macro_context__stack.append((opcode_to_jump_to, parameter_mapping))
        #logger.debug("<%d>: -- PUSH MACRO CTX --> [%d, %s]", id(self), opcode_to_jump_to, parameter_mapping)

    def macro_context__pop(self):
        """
        Pop a macro context from the stack.
        """
        self._macro_context__stack.pop()
        #logger.debug("<%d>: <-- POP MACRO CTX", id(self))

    def next_macro_opcode_called_in(self, if_incl_rel_path: Optional[str], line_number, column):
        """Mark the next added macro opcode as being called in this line/column. This marks a macro call."""
        self._next_macro_called_in = (if_incl_rel_path, line_number, column)
        #logger.debug("<%d>: Marked next macro opcode as called in %s:%d, %d", id(self), str(if_incl_rel_path), line_number, column)

    def add_macro_opcode(self, op_offset, if_incl_rel_path: Optional[str], macro_name: str,
                         line_number, column):
        """
        Add an operation that has it's source code in a macro.
        If the macro is in a different file, if_incl_rel_path should contain the relative path to this file
        from the original source file that this source map is generated for.
        At least one macro return address entry has to be on the call stack!
        """
        if len(self._macro_context__stack) < 1:
            raise ValueError("There are no return addresses on the macro return address stack, "
                             "can not add macro opcode.")
        called_in = None
        if self._next_macro_called_in is not None:
            called_in = self._next_macro_called_in
            self._next_macro_called_in = None
        return_addr, parameter_mapping = self._macro_context__stack[-1]
        #logger.debug("<%d>: Adding macro opcode: %s:%s:%d -> %d, %d", id(self), if_incl_rel_path, macro_name, op_offset, line_number, column)
        self._mappings_macros[op_offset] = MacroSourceMapping(if_incl_rel_path, macro_name,
                                                              line_number,
                                                              column, called_in, return_addr, parameter_mapping)

    def add_macro_position_mark(self, if_incl_rel_path: Optional[str], macro_name: str, position_mark: SourceMapPositionMark):
        """Add a position mark, that has it's source code in a macro. See notes for add_macro_opcode"""
        self._pos_marks_macros.append((if_incl_rel_path, macro_name, position_mark))
        #logger.debug("<%d>: Adding Macro PositionMark: %s:%s - %s", id(self), if_incl_rel_path, macro_name, position_mark)

    def build(self):
        return SourceMap(self._mappings, self._pos_marks,
                         self._mappings_macros, self._pos_marks_macros)
