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

from typing import Literal, overload, NoReturn

from explorerscript.common_syntax import parse_primitive
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.ssb_data_types import (
    SsbOpParamConstant,
    SsbOpParamFixedPoint,
    SsbOpParamLanguageString,
    SsbOpParamConstString,
)
from explorerscript_parser import ExplorerScriptParser


# noinspection PyMethodOverriding
class PrimitiveCompileHandler(AbstractCompileHandler[ExplorerScriptParser.PrimitiveContext, None]):
    @overload
    def collect(
        self,
        *,
        allow_integer_like: Literal[True] = True,
        allow_string: Literal[True] = True,
    ) -> int | SsbOpParamFixedPoint | SsbOpParamConstant | SsbOpParamConstString | SsbOpParamLanguageString: ...

    @overload
    def collect(
        self,
        *,
        allow_integer_like: Literal[True] = ...,
        allow_string: Literal[False],
    ) -> int | SsbOpParamFixedPoint | SsbOpParamConstant: ...

    @overload
    def collect(
        self,
        *,
        allow_integer_like: Literal[False],
        allow_string: Literal[True],
    ) -> SsbOpParamConstString | SsbOpParamLanguageString: ...

    @overload
    def collect(
        self,
        *,
        allow_integer_like: Literal[False],
        allow_string: Literal[False],
    ) -> NoReturn: ...

    @overload  # https://github.com/python/mypy/issues/14764
    def collect(
        self,
        *,
        allow_integer_like: bool = True,
        allow_string: bool = True,
    ) -> int | SsbOpParamFixedPoint | SsbOpParamConstant | SsbOpParamConstString | SsbOpParamLanguageString: ...

    def collect(
        self,
        *,
        allow_integer_like: bool = True,
        allow_string: bool = True,
    ) -> int | SsbOpParamFixedPoint | SsbOpParamConstant | SsbOpParamConstString | SsbOpParamLanguageString:
        return parse_primitive(
            self.ctx,
            user_constants=self.compiler_ctx.user_constants.in_scope(self.compiler_ctx.current_user_constants_scope),
            allow_integer_like=allow_integer_like,
            allow_string=allow_string,
        )

    def add(self, obj: None) -> None:
        self._raise_add_error(obj)
