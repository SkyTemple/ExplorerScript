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

from typing import overload, Literal, Any, NoReturn
from collections.abc import Mapping

from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.utils import string_literal
from explorerscript.ssb_converting.ssb_data_types import (
    SsbOpParam,
    SsbOpParamFixedPoint,
    SsbOpParamConstant,
    SsbOpParamConstString,
    SsbOpParamLanguageString,
)
from explorerscript.util import exps_int, _
from explorerscript_parser import ExplorerScriptParser, SsbScriptParser


@overload
def parse_primitive(
    primitive: ExplorerScriptParser.PrimitiveContext | SsbScriptParser.PrimitiveContext,
    *,
    user_constants: Mapping[str, SsbOpParam] | None = None,
    allow_integer_like: Literal[True] = True,
    allow_string: Literal[True] = True,
) -> int | SsbOpParamFixedPoint | SsbOpParamConstant | SsbOpParamConstString | SsbOpParamLanguageString: ...


@overload
def parse_primitive(
    primitive: ExplorerScriptParser.PrimitiveContext | SsbScriptParser.PrimitiveContext,
    *,
    user_constants: Mapping[str, SsbOpParam] | None = None,
    allow_integer_like: Literal[True],
    allow_string: Literal[False],
) -> int | SsbOpParamFixedPoint | SsbOpParamConstant: ...


@overload
def parse_primitive(
    primitive: ExplorerScriptParser.PrimitiveContext | SsbScriptParser.PrimitiveContext,
    *,
    user_constants: Mapping[str, SsbOpParam] | None = None,
    allow_integer_like: Literal[False],
    allow_string: Literal[True],
) -> SsbOpParamConstString | SsbOpParamLanguageString: ...


@overload
def parse_primitive(
    primitive: ExplorerScriptParser.PrimitiveContext | SsbScriptParser.PrimitiveContext,
    *,
    user_constants: Mapping[str, SsbOpParam] | None = None,
    allow_integer_like: Literal[False],
    allow_string: Literal[False],
) -> NoReturn: ...


@overload  # https://github.com/python/mypy/issues/14764
def parse_primitive(
    primitive: ExplorerScriptParser.PrimitiveContext | SsbScriptParser.PrimitiveContext,
    *,
    user_constants: Mapping[str, SsbOpParam] | None = None,
    allow_integer_like: bool = True,
    allow_string: bool = True,
) -> int | SsbOpParamFixedPoint | SsbOpParamConstant | SsbOpParamConstString | SsbOpParamLanguageString: ...


def parse_primitive(
    primitive: ExplorerScriptParser.PrimitiveContext | SsbScriptParser.PrimitiveContext,
    *,
    user_constants: Mapping[str, SsbOpParam] | None = None,
    allow_integer_like: bool = True,
    allow_string: bool = True,
) -> int | SsbOpParamFixedPoint | SsbOpParamConstant | SsbOpParamConstString | SsbOpParamLanguageString:
    if primitive.INTEGER():
        if not allow_integer_like:
            raise SsbCompilerError(_("Integer not allowed at this position."))
        return exps_int(str(primitive.INTEGER()))
    if primitive.DECIMAL():
        if not allow_integer_like:
            raise SsbCompilerError(_("Decimal not allowed at this position."))
        return SsbOpParamFixedPoint.from_str(str(primitive.DECIMAL()))
    if primitive.IDENTIFIER():
        ident = str(primitive.IDENTIFIER())
        if user_constants is not None and ident in user_constants:
            return parse_resolved_primitive(
                user_constants[ident],
                allow_integer_like=allow_integer_like,
                allow_string=allow_string,
            )
        if not allow_integer_like:
            raise SsbCompilerError(_("Constant not allowed at this position."))
        return SsbOpParamConstant(ident)
    if primitive.VARIABLE():
        ident = str(primitive.VARIABLE())
        if user_constants is not None and ident in user_constants:
            return parse_resolved_primitive(
                user_constants[ident],
                allow_integer_like=allow_integer_like,
                allow_string=allow_string,
            )
        if not allow_integer_like:
            raise SsbCompilerError(_("Variable or constant not allowed at this position."))
        return SsbOpParamConstant(ident)
    if primitive.string():
        if not allow_string:
            raise SsbCompilerError(_("String not allowed at this position."))
        return _parse_string(primitive.string())
    raise SsbCompilerError("Unknown primitive.")


@overload
def parse_resolved_primitive(
    primitive: SsbOpParam,
    *,
    allow_integer_like: Literal[True] = True,
    allow_string: Literal[True] = True,
) -> int | SsbOpParamFixedPoint | SsbOpParamConstant | SsbOpParamConstString | SsbOpParamLanguageString: ...


@overload
def parse_resolved_primitive(
    primitive: SsbOpParam,
    *,
    allow_integer_like: Literal[True],
    allow_string: Literal[False],
) -> int | SsbOpParamFixedPoint | SsbOpParamConstant: ...


@overload
def parse_resolved_primitive(
    primitive: SsbOpParam,
    *,
    allow_integer_like: Literal[False],
    allow_string: Literal[True],
) -> SsbOpParamConstString | SsbOpParamLanguageString: ...


@overload
def parse_resolved_primitive(
    primitive: SsbOpParam,
    *,
    allow_integer_like: Literal[False],
    allow_string: Literal[False],
) -> NoReturn: ...


@overload  # https://github.com/python/mypy/issues/14764
def parse_resolved_primitive(
    primitive: SsbOpParam,
    *,
    allow_integer_like: bool = True,
    allow_string: bool = True,
) -> int | SsbOpParamFixedPoint | SsbOpParamConstant | SsbOpParamConstString | SsbOpParamLanguageString: ...


def parse_resolved_primitive(
    primitive: SsbOpParam,
    *,
    allow_integer_like: bool = True,
    allow_string: bool = True,
) -> int | SsbOpParamFixedPoint | SsbOpParamConstant | SsbOpParamConstString | SsbOpParamLanguageString:
    if not allow_integer_like:
        if isinstance(primitive, int):
            raise SsbCompilerError(_("Integer not allowed at this position."))
        if isinstance(primitive, SsbOpParamFixedPoint):
            raise SsbCompilerError(_("Decimal not allowed at this position."))
        if isinstance(primitive, SsbOpParamConstant):
            raise SsbCompilerError(_("Variable or constant not allowed at this position."))
    if not allow_string:
        if isinstance(primitive, SsbOpParamConstString) or isinstance(primitive, SsbOpParamLanguageString):
            raise SsbCompilerError(_("String not allowed at this position."))
    return primitive  # type: ignore


def is_primitive_string(v: Any) -> bool:
    return isinstance(v, SsbOpParamLanguageString) or isinstance(v, SsbOpParamConstString)


def _parse_string(
    value: ExplorerScriptParser.StringContext | SsbScriptParser.StringContext,
) -> SsbOpParamConstString | SsbOpParamLanguageString:
    if value.lang_string():
        return _parse_lang_string(value.lang_string())
    elif value.string_value():
        return SsbOpParamConstString(string_literal(value.string_value()))
    raise SsbCompilerError("Invalid string, neither literal nor language string")


def _parse_lang_string(
    value: ExplorerScriptParser.Lang_stringContext | SsbScriptParser.Lang_stringContext,
) -> SsbOpParamLanguageString:
    language_dict = {}
    for argument in value.lang_string_argument():
        language_dict[str(argument.IDENTIFIER())] = string_literal(argument.string_value())
    return SsbOpParamLanguageString(language_dict)


def parse_for_target(value: SsbOpParam) -> tuple[int, str | None]:
    if isinstance(value, int):
        return exps_int(value), None
    elif isinstance(value, SsbOpParamConstant):
        return -1, str(value)
    else:
        raise SsbCompilerError(_("Invalid target for routine."))


def parse_position_marker_arg(
    ctx: ExplorerScriptParser.Position_marker_argContext | SsbScriptParser.Position_marker_argContext,
) -> tuple[int, int]:
    offset = 0
    pos = 0
    if ctx.INTEGER():
        pos = exps_int(str(ctx.INTEGER()))
    elif ctx.DECIMAL():
        decimal_parts = str(ctx.DECIMAL()).split(".")

        if len(decimal_parts) == 1:  # .XXXXX
            dec_part_raw_stripped = decimal_parts[0].rstrip("0")  # strip 0s off the decimal places
            dec_part = int(dec_part_raw_stripped if dec_part_raw_stripped != "" else "0")
        elif len(decimal_parts) == 2:  # XXXXX.YYYYY
            pos = int(decimal_parts[0] if decimal_parts[0] != "" else "0")
            dec_part_raw_stripped = decimal_parts[1].rstrip("0")  # strip 0s off the decimal places
            dec_part = int(dec_part_raw_stripped if dec_part_raw_stripped != "" else "0")
        else:
            raise SsbCompilerError("Logic error in decimal code for 'position marker arg'.")

        if dec_part == 5:
            offset = 2
        elif dec_part == 0:
            offset = 0
        else:
            raise SsbCompilerError(
                _("Position Marker arguments need to be an integer or a decimal with '.5' as the decimal places.")
            )
    else:
        raise SsbCompilerError("Unknown 'position marker arg'.")

    return pos, offset
