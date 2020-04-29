"""Data types used to describe ssb components"""
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
from enum import Enum
from typing import Dict, TypeVar, Union, List, OrderedDict as OrderedDictType, NamedTuple


def escape_quotes(string):
    return string.replace('"', '\\"').replace("'", "\\'")


def escape_newlines(string):
    return string.replace('\n', '\\n')


class SsbRoutineType(Enum):
    GENERIC = 1
    ACTOR = 3
    OBJECT = 4
    PERFORMER = 5
    COROUTINE = 9
    INVALID = -1

    @staticmethod
    def create_for_index(idx: int):
        if idx == 1:
            return SsbRoutineType.GENERIC
        if idx == 3:
            return SsbRoutineType.ACTOR
        if idx == 4:
            return SsbRoutineType.OBJECT
        if idx == 5:
            return SsbRoutineType.PERFORMER
        if idx == 9:
            return SsbRoutineType.COROUTINE
        return SsbRoutineType.INVALID


class SsbNamedId:
    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name

    def __repr__(self):
        return str(self)

    def __str__(self):
        return f"{self.__class__.__name__}<{self.name}({self.id})>"

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return int(self) == int(other)

    def __int__(self):
        return self.id


class SsbOpCode(SsbNamedId):
    pass


class SsbCoroutine(SsbNamedId):
    pass


class SsbWarning(UserWarning):
    pass


class SsbRoutineInfo:
    def __init__(self, type: SsbRoutineType, linked_to: int, linked_to_name: str = None):
        self.type: SsbRoutineType = type
        self.linked_to = linked_to
        self.linked_to_name = linked_to_name

    @property
    def linked_to_repr(self) -> str:
        if self.linked_to_name:
            return self.linked_to_name
        return str(self.linked_to)

    def __repr__(self):
        return str(self)

    def __str__(self):
        return f"{self.__class__.__name__}<{self.type}({self.linked_to})>"

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return self.type == other.type and self.linked_to == other.linked_to

    def __hash__(self):
        return hash((self.type,  self.linked_to, self.linked_to_name))


class SsbOpParamConstant:
    """An actual constant representing an int"""
    def __init__(self, name: str):
        self.name = name

    def __str__(self):
        return self.name


class SsbOpParamConstString:
    """A string constant from the table of string constants in an Ssb"""
    def __init__(self, name: str):
        self.name = name

    def __str__(self):
        return f"'{self.name}'"


class SsbOpParamLanguageString:
    """A string from the table of strings in an Ssb"""
    def __init__(self, strings: Dict[str, str]):  # {language_name: string}
        self.strings = strings
        # Because this will print a multiline output, this may specify the original indent of the current
        # line in the converter, may be set by the converter before converting to string
        self.indent = 0

    def __str__(self):
        string = '{\n'
        for language, lang_string in self.strings.items():
            string += ' ' * ((self.indent + 1) * NUMBER_OF_SPACES_PER_INDENT)
            string += f'{language}="{escape_newlines(escape_quotes(lang_string))}",\n'
        string += ' ' * (self.indent * NUMBER_OF_SPACES_PER_INDENT)
        string += '}'
        return string


class SsbOpParamPositionMarker:
    """Actually a tuple of four SSB binary parameters encoded as one positon marker"""
    def __init__(self, name: str, x_offset: int, y_offset: int, x_relative: int, y_relative: int):
        self.name = name
        self.x_offset = x_offset
        self.y_offset = y_offset
        self.x_relative = x_relative
        self.y_relative = y_relative

    def __str__(self):
        x_offset_marker = ''
        if self.x_offset == 2 or self.x_offset == 3:
            x_offset_marker = '+'
        elif self.x_offset >= 4:
            x_offset_marker = '++'
        y_offset_marker = ''
        if self.y_offset == 2 or self.y_offset == 3:
            y_offset_marker = '+'
        elif self.y_offset >= 4:
            y_offset_marker = '++'
        return f'Position<\'{self.name}\', {self.x_relative}{x_offset_marker}, {self.y_relative}{y_offset_marker}>'


SsbOpParam = Union[int, SsbOpParamConstant, SsbOpParamConstString, SsbOpParamLanguageString, SsbOpParamPositionMarker]


class SsbOperation:
    def __init__(self, offset: int, op_code: SsbOpCode, params: List[SsbOpParam]):
        self.offset = offset
        self.op_code = op_code
        self.params = params

    def __repr__(self):
        return str(self)

    def __str__(self):
        return f"{self.__class__.__name__}<{str({k:v for k,v in self.__dict__.items()})}>"

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return self.offset == other.offset and self.op_code == other.op_code and self.params == other.params


class SsbOperator(Enum):
    """Operator parameter used in Branch and Switch operations."""
    FALSE = 0, 'FALSE'
    TRUE = 1, 'TRUE'
    EQ = 2, '=='
    GT = 3, '>'
    LT = 4, '<'
    GE = 5, '>='
    LE = 6, '<='
    NOT = 7, '!='
    AND = 8, '&'
    XOR = 9, '^'
    BIT_SET = 10, '&<<'

    def __new__(cls, *args, **kwargs):
        obj = object.__new__(cls)
        obj._value_ = args[0]
        return obj

    # ignore the first param since it's already set by __new__
    def __init__(self, _: str, notation: str = None):
        self._notation_ = notation

    def __str__(self):
        return self.value

    @property
    def notation(self):
        return self._notation_


class SsbCalcOperator(Enum):
    """Operator parameter used in flag_Calc* operations."""
    ASSIGN = 0, '='
    MINUS = 1, '-='
    PLUS = 2, '+='
    MULTIPLY = 3, '*='
    DIVIDE = 4, '/='

    def __new__(cls, *args, **kwargs):
        obj = object.__new__(cls)
        obj._value_ = args[0]
        return obj

    # ignore the first param since it's already set by __new__
    def __init__(self, _: str, notation: str = None):
        self._notation_ = notation

    def __str__(self):
        return self.value

    @property
    def notation(self):
        return self._notation_


class DungeonModeConstants:
    def __init__(self, open_constant: str, request_constant: str, close_constant: str):
        self.open_constant = open_constant
        self.request_constant = request_constant
        self.close_constant = close_constant

    def get_explorerscript_flag_set_for(self, idx: int):
        if idx == 1:
            return self.open_constant
        if idx == 2:
            return self.request_constant
        if idx == 3:
            return f'{self.open_constant} & {self.request_constant}'
        return self.close_constant


NUMBER_OF_SPACES_PER_INDENT = 4
