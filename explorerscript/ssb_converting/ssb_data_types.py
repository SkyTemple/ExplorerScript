"""Data types used to describe ssb components"""

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

import string
from enum import Enum
from typing import Union
from collections.abc import MutableSequence


def escape_quotes(string: str, which_quotes: str | None = None) -> str:
    if which_quotes is None:
        return string.replace('"', '\\"').replace("'", "\\'")
    return string.replace(f"{which_quotes}", f"\\{which_quotes}")


def escape_newlines(string: str) -> str:
    return string.replace("\n", "\\n")


def repr_string(string: str, indent: int = 0, prefer_single_qoute: bool = False) -> str:
    if prefer_single_qoute:
        preferred_quote = "'"
        preferred_multiline_quote = "'''"
        secondary_multiline_quote = '"""'
    else:
        preferred_quote = '"'
        preferred_multiline_quote = '"""'
        secondary_multiline_quote = "'''"

    if "\n" not in string:
        # Single line string
        return f"{preferred_quote}{escape_quotes(string, which_quotes=preferred_quote)}{preferred_quote}"
    if preferred_multiline_quote in string:
        if secondary_multiline_quote in string:
            # uh oh... We can't properly handle this at the moment. We fall back to single line string representation.
            return f"{preferred_quote}{escape_newlines(escape_quotes(string, which_quotes=preferred_quote))}{preferred_quote}"
        return _repr_multiline_string(string, indent, secondary_multiline_quote)
    return _repr_multiline_string(string, indent, preferred_multiline_quote)


def _repr_multiline_string(string: str, indent: int, delimiter: str) -> str:
    lines = string.split("\n")
    indentprefix = " " * (NUMBER_OF_SPACES_PER_INDENT * indent)
    output = "\n".join(indentprefix + (" " * NUMBER_OF_SPACES_PER_INDENT) + o for o in lines)
    return f"{delimiter}\n{output}\n{indentprefix}{delimiter}"


class SsbRoutineType(Enum):
    GENERIC = 1
    ACTOR = 3
    OBJECT = 4
    PERFORMER = 5
    COROUTINE = 9
    INVALID = -1

    @staticmethod
    def create_for_index(idx: int) -> SsbRoutineType:
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

    def __repr__(self) -> str:
        return str(self)

    def __str__(self) -> str:
        return f"{self.__class__.__name__}<{self.name}({self.id})>"

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, self.__class__):
            return False
        return int(self) == int(other)

    def __int__(self) -> int:
        return self.id


class SsbOpCode(SsbNamedId):
    pass


class SsbCoroutine(SsbNamedId):
    pass


class SsbWarning(UserWarning):
    pass


class SsbRoutineInfo:
    type: SsbRoutineType
    linked_to: int
    linked_to_name: str | None

    def __init__(self, type: SsbRoutineType, linked_to: int, linked_to_name: str | None = None):
        self.type = type
        self.linked_to = linked_to
        self.linked_to_name = linked_to_name

    @property
    def linked_to_repr(self) -> str:
        if self.linked_to_name:
            return self.linked_to_name
        return str(self.linked_to)

    def __repr__(self) -> str:
        return str(self)

    def __str__(self) -> str:
        return f"{self.__class__.__name__}<{self.type}({self.linked_to})>"

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, self.__class__):
            return False
        return self.type == other.type and self.linked_to == other.linked_to

    def __hash__(self) -> int:
        return hash((self.type, self.linked_to, self.linked_to_name))


DIGITS = set(string.digits)


class SsbOpParamFixedPoint:
    """A fixed point number, encoded as a string."""

    class NegativeZero:
        pass  # Marker type for negative numbers.

    def __init__(self, whole_part: int | type[SsbOpParamFixedPoint.NegativeZero], fract_part: str):
        assert set(fract_part) <= DIGITS
        if whole_part == SsbOpParamFixedPoint.NegativeZero:
            self.value = f"-0.{fract_part}"
        else:
            self.value = f"{whole_part}.{fract_part}"

    @classmethod
    def from_float(cls, value: float) -> SsbOpParamFixedPoint:
        slf = cls(0, "0")
        slf.value = str(value)
        return slf

    @classmethod
    def from_str(cls, value: str) -> SsbOpParamFixedPoint:
        try:
            parts = value.split(".", 1)
            whole_part = parts[0].lstrip("0")
            if whole_part == "":
                whole_part = "0"
            elif whole_part.rstrip("0") == "-":
                whole_part = "-0"

            whole: int | type[SsbOpParamFixedPoint.NegativeZero]
            whole = int(whole_part) if whole_part != "-0" else SsbOpParamFixedPoint.NegativeZero

            if len(parts) == 1:
                return cls(whole, "0")
            fract = parts[1]
            return cls(whole, fract)
        except ValueError as e:
            raise ValueError(f"Invalid fixed point decimal: {value}") from e

    def __str__(self) -> str:
        return self.value

    def __repr__(self) -> str:
        return str(self)

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, SsbOpParamFixedPoint):
            return False
        return self.value == other.value


class SsbOpParamConstant:
    """An actual constant representing an int"""

    name: str

    def __init__(self, name: str):
        self.name = name

    def __str__(self) -> str:
        return self.name

    def __repr__(self) -> str:
        return str(self)

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, SsbOpParamConstant):
            return False
        return self.name == other.name


class SsbOpParamConstString:
    """A string constant from the table of string constants in an Ssb"""

    name: str
    indent: int

    def __init__(self, name: str):
        self.name = name
        self.indent = 0

    def __str__(self) -> str:
        return repr_string(self.name, indent=self.indent, prefer_single_qoute=True)

    def __repr__(self) -> str:
        return f"str({str(self)})"

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, SsbOpParamConstString):
            return False
        return self.name == other.name


class SsbOpParamLanguageString:
    """A string from the table of strings in an Ssb"""

    strings: dict[str, str]

    def __init__(self, strings: dict[str, str]):  # {language_name: string}
        self.strings = strings
        # Because this will print a multiline output, this may specify the original indent of the current
        # line in the converter, may be set by the converter before converting to string
        self.indent = 0

    def __str__(self) -> str:
        string = "{\n"
        for language, lang_string in self.strings.items():
            string += " " * ((self.indent + 1) * NUMBER_OF_SPACES_PER_INDENT)
            string += f"{language}={repr_string(lang_string, indent=self.indent + 1)},\n"
        string += " " * (self.indent * NUMBER_OF_SPACES_PER_INDENT)
        string += "}"
        return string

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, SsbOpParamLanguageString):
            return False
        return self.strings == other.strings


class SsbOpParamPositionMarker:
    """Actually a tuple of four SSB binary parameters encoded as one positon marker"""

    name: str
    x_offset: int
    y_offset: int
    x_relative: int
    y_relative: int

    def __init__(self, name: str, x_offset: int, y_offset: int, x_relative: int, y_relative: int):
        self.name = name
        self.x_offset = x_offset
        self.y_offset = y_offset
        self.x_relative = x_relative
        self.y_relative = y_relative

    @property
    def x_final(self) -> str:
        x_offset_marker = ""
        if self.x_offset > 1:
            x_offset_marker = ".5"
        return f"{self.x_relative}{x_offset_marker}"

    @property
    def y_final(self) -> str:
        y_offset_marker = ""
        if self.y_offset > 1:
            y_offset_marker = ".5"
        return f"{self.y_relative}{y_offset_marker}"

    def __str__(self) -> str:
        return f"Position<'{self.name}', {self.x_final}, {self.y_final}>"

    def __repr__(self) -> str:
        return f"SsbOpParamPositionMarker('{self.name}', {self.x_offset}, {self.y_offset}, {self.x_relative}, {self.y_relative})"

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, SsbOpParamPositionMarker):
            return False
        return (
            self.x_offset == other.x_offset
            and self.y_offset == other.y_offset
            and self.x_relative == other.x_relative
            and self.y_relative == other.y_relative
        )


SsbOpParam = Union[
    int,
    SsbOpParamFixedPoint,
    SsbOpParamConstant,
    SsbOpParamConstString,
    SsbOpParamLanguageString,
    SsbOpParamPositionMarker,
]


class SsbOperation:
    offset: int
    op_code: SsbOpCode
    params: MutableSequence[SsbOpParam]

    def __init__(self, offset: int, op_code: SsbOpCode, params: MutableSequence[SsbOpParam]):
        self.offset = offset
        self.op_code = op_code
        self.params = params

    def __repr__(self) -> str:
        return str(self)

    def __str__(self) -> str:
        return f"{self.__class__.__name__}<{str({k: v for k, v in self.__dict__.items()})}>"

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, self.__class__):
            return False
        return self.offset == other.offset and self.op_code == other.op_code and self.params == other.params


class SsbOperator(Enum):
    """Operator parameter used in Branch and Switch operations."""

    FALSE = 0, "FALSE"
    TRUE = 1, "TRUE"
    EQ = 2, "=="
    GT = 3, ">"
    LT = 4, "<"
    GE = 5, ">="
    LE = 6, "<="
    NOT = 7, "!="
    AND = 8, "&"
    XOR = 9, "^"
    BIT_SET = 10, "&<<"

    def __new__(cls, *args, **kwargs):  # type: ignore
        obj = object.__new__(cls)
        obj._value_ = args[0]
        return obj

    # ignore the first param since it's already set by __new__
    def __init__(self, _: str, notation: str):
        self._notation_ = notation

    def __str__(self) -> str:
        return self.name

    @property
    def notation(self) -> str:
        return self._notation_


class SsbCalcOperator(Enum):
    """Operator parameter used in flag_Calc* operations."""

    ASSIGN = 0, "="
    MINUS = 1, "-="
    PLUS = 2, "+="
    MULTIPLY = 3, "*="
    DIVIDE = 4, "/="

    def __new__(cls, *args, **kwargs):  # type: ignore
        obj = object.__new__(cls)
        obj._value_ = args[0]
        return obj

    # ignore the first param since it's already set by __new__
    def __init__(self, _: str, notation: str):
        self._notation_ = notation

    def __str__(self) -> str:
        return self.name

    @property
    def notation(self) -> str:
        return self._notation_


class DungeonModeConstants:
    def __init__(self, close_constant: str, open_constant: str, request_constant: str, open_and_request_constant: str):
        self.open_constant = open_constant
        self.request_constant = request_constant
        self.close_constant = close_constant
        self.open_and_request_constant = open_and_request_constant

    def get_explorerscript_constant_for(self, idx: int) -> str:
        if idx == 1:
            return self.open_constant
        if idx == 2:
            return self.request_constant
        if idx == 3:
            return self.open_and_request_constant
        return self.close_constant


NUMBER_OF_SPACES_PER_INDENT = 4
