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

from inspect import currentframe
from typing import TYPE_CHECKING, Any

if TYPE_CHECKING:
    from typing import SupportsInt, SupportsIndex

try:
    import builtins

    _ = builtins._  # type: ignore
except Exception:

    def _(a):  # type: ignore
        return a  # type: ignore


def open_utf8(file, mode="r", *args, **kwargs):  # type: ignore
    """Like open, but always uses the utf-8 encoding, on all platforms."""
    return open(file, mode, *args, encoding="utf-8", **kwargs)  # type: ignore


def exps_int(to_convert: str | SupportsInt | SupportsIndex) -> int:
    """Converts to integer, auto-detecting the base (if string)."""
    try:
        if isinstance(to_convert, str):
            return int(to_convert, 0)
        return int(to_convert)
    except TypeError as e:
        raise ValueError("Invalid value for conversion to ExplorerScript integer") from e


def f(s: str, additional_locals: Any | None = None) -> str:
    """f-strings as a function, for use with translatable strings: f'{techticks}' == f('{techticks}')"""
    if additional_locals is None:
        additional_locals = {}
    frame = currentframe().f_back  # type: ignore
    s1 = s.replace("'", "\\'").replace("\n", "\\n")
    additional_locals.update(frame.f_locals)  # type: ignore
    try:
        return eval(f"f'{s1}'", additional_locals, frame.f_globals)  # type: ignore
    except SyntaxError:
        s1 = s.replace('"', '\\"').replace("\n", "\\n")
        return eval(f'f"{s1}"', additional_locals, frame.f_globals)  # type: ignore
