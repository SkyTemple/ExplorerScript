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
from typing import Dict, Tuple


class SourceMap:
    """
    A source map for ExplorerScript and SSBScript back to the SSB binary opcodes.
    Takes a routine id and opcode index and returns the line in the source code, that this
    operation is at.

    Can be created in the following ways:
    - When loading SSB:
      - For SSBScript:
        - During decompilation.
      - For ExplorerScript:
        - Either during the decompilation, if no ExplorerScript exists yet.
        - From an existing source map file.
    - When compiling SSBScript or ExplorerScript the source map is also generated.
    """
    def __init__(self, mappings: Dict[int, Dict[int, Tuple[int, int]]]):
        """Init from a dictionary of mappings
        (keys are routine ids, values are dict of line numbers + column for opcodes)"""
        self._mappings = mappings

    def get_position(self, routine_id: int, op_offset: int) -> Tuple[int, int]:
        if routine_id in self._mappings:
            if op_offset in routine_id:
                return self._mappings[routine_id][op_offset]
            return None
        raise ValueError(f"Unknown routine {routine_id}")

    def __iter__(self):
        for routine_id, routine in self._mappings.items():
            for opcode_offset, (line_number, column) in routine.items():
                yield routine_id, opcode_offset, line_number, column


class SourceMapBuilder:
    # TODO: Column
    def __init__(self):
        self._mappings = {}
        self._active_routine = None

    def routine(self, i):
        self._active_routine = i
        self._mappings[self._active_routine] = {}

    def add_opcode(self, op_offset, line_number, column):
        self._mappings[self._active_routine][op_offset] = (line_number, column)

    def build(self):
        return SourceMap(self._mappings)
