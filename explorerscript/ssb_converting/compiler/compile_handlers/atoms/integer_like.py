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
from typing import Union

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOpParamConstant
from explorerscript.util import exps_int


class IntegerLikeCompileHandler(AbstractCompileHandler):
    def collect(self) -> Union[int, SsbOpParamConstant]:
        self.ctx: ExplorerScriptParser.Integer_likeContext
        if self.ctx.INTEGER():
            return exps_int(str(self.ctx.INTEGER()))
        if self.ctx.IDENTIFIER():
            return SsbOpParamConstant(str(self.ctx.IDENTIFIER()))
        if self.ctx.VARIABLE():
            return SsbOpParamConstant(str(self.ctx.VARIABLE()))
        raise SsbCompilerError("Unknown 'integer like'.")

    def add(self, obj: any):
        # Doesn't accept anything.
        self._raise_add_error(obj)
