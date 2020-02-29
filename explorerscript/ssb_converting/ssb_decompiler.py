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
from typing import List, Tuple, Dict, TypeVar, Union
from typing import OrderedDict as OrderedDictType

NUMBER_OF_SPACES_PER_INDENT = 4


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


class SsbRoutineInfo:
    def __init__(self, type: SsbRoutineType, linked_to: int):
        self.type = type
        self.linked_to = linked_to

    def __repr__(self):
        return str(self)

    def __str__(self):
        return f"{self.__class__.__name__}<{self.type}({self.linked_to})>"


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


SsbOpParam = TypeVar('SsbOpParam', int, SsbOpParamConstant, SsbOpParamConstString, SsbOpParamLanguageString)
ListOfSsbOpParam = Union[List[SsbOpCode], OrderedDictType[str, SsbOpParam]]


class SsbOperation:
    def __init__(self, offset: int, op_code: SsbOpCode, params: ListOfSsbOpParam):
        self.offset = offset
        self.op_code = op_code
        self.params = params

    def __repr__(self):
        return str(self)

    def __str__(self):
        return f"{self.__class__.__name__}<{str({k:v for k,v in self.__dict__.items()})}>"


class SsbDecompiler:
    def __init__(self, routines: List[Tuple[SsbRoutineInfo, List[SsbOperation]]], named_coroutines: List[SsbCoroutine]):
        self._routines = routines
        self._named_coroutines: Dict[int, str] = {x.id: x.name for x in named_coroutines}
        self._output = ""
        self._indent = 0

    def convert(self) -> str:
        self._output = ""
        self._indent = 0
        for r_id, (r_info, r_ops) in enumerate(self._routines):
            self._write_routine_header(r_id, r_info)
            with _Blk(self):
                if len(r_ops) == 0:
                    # TODO
                    #raise ValueError(f"Empty routines are currently not supported ({r_id}, {r_info})")
                    self._write_stmnt("not supported")
                for op in r_ops:
                    self._read_op(op)
            self._write_line()
        return self._output

    def _write_routine_header(self, r_id, r_info):
        if r_info.type == SsbRoutineType.COROUTINE:
            if r_id in self._named_coroutines:
                self._write_stmnt(f"coro {self._named_coroutines[r_id]}:")
            else:
                raise ValueError(f"Unknown coroutine for: {r_id}, {r_info}")
        elif r_info.type == SsbRoutineType.ACTOR:
            self._write_stmnt(f"def {r_id} for actor({r_info.linked_to}):")
        elif r_info.type == SsbRoutineType.OBJECT:
            self._write_stmnt(f"def {r_id} for object({r_info.linked_to}):")
        elif r_info.type == SsbRoutineType.PERFORMER:
            self._write_stmnt(f"def {r_id} for performer({r_info.linked_to}):")
        elif r_info.type == SsbRoutineType.GENERIC:
            self._write_stmnt(f"def {r_id}:")
        else:
            raise ValueError(f"Unknown routine type for: {r_id}, {r_info}")

    def _read_op(self, op: SsbOperation):
        # TODO!
        if isinstance(op.params, list):
            # Ordered arguments
            params = ", ".join(
                [self._single_param_to_string(param) for param in op.params]
            ).rstrip(", ")
        elif isinstance(op.params, dict):
            # Named arguments
            params = ", ".join(
                [self._single_param_to_string(param, param_name) for param_name, param in op.params.items()]
            ).rstrip(", ")
        else:
            raise ValueError(f"Invalid argument list type for {op}: {op.params.__class__.__name__}")
        self._write_stmnt(f"{op.op_code.name}({params})")

    def _single_param_to_string(self, param: SsbOpParam, param_name=None):
        if hasattr(param, 'indent'):
            param.indent = self._indent
        if param_name is not None:
            return f"{param_name}={str(param)}"
        return str(param)

    def _write_stmnt(self, stmnt):
        """Write a simple single line statement"""
        self._output += " " * (self._indent * NUMBER_OF_SPACES_PER_INDENT)
        self._output += stmnt
        self._write_line()

    def _write_line(self):
        self._output += "\n"


# noinspection PyProtectedMember
class _Blk(object):
    def __init__(self, reader):
        self.reader = reader

    def __enter__(self):
        self.reader._indent += 1

    def __exit__(self, exc_type, exc_value, exc_traceback):
        self.reader._indent -= 1
