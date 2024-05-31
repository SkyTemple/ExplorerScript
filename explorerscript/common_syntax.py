#  MIT License
#
#  Copyright (c) 2020-2024 Capypara and the SkyTemple Contributors
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
from typing import Union

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.antlr.SsbScriptParser import SsbScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.util import exps_int, _


def parse_position_marker_arg(
        ctx: Union[ExplorerScriptParser.Position_marker_argContext, SsbScriptParser.Position_marker_argContext]
):
    offset = 0
    pos = 0
    if ctx.INTEGER():
        pos = exps_int(str(ctx.INTEGER()))
    elif ctx.DECIMAL():
        decimal_parts = str(ctx.DECIMAL()).split(".")

        if len(decimal_parts) == 1:  # .XXXXX
            dec_part = int(decimal_parts[0].rstrip("0") if decimal_parts[1] != "0" else "0")  # strip 0s of the decimal places
        elif len(decimal_parts) == 2:  # XXXXX.YYYYY
            pos = int(decimal_parts[0] if decimal_parts[0] != "" else "0")
            dec_part = int(decimal_parts[1].rstrip("0") if decimal_parts[1] != "0" else "0")  # strip 0s of the decimal places
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
