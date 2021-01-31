#  MIT License
#
#  Copyright (c) 2020-2021 Parakoopa and the SkyTemple Contributors
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

from typing import Optional

from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.integer_like import IntegerLikeCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOpParam, SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import OP_SWITCH_DUNGEON_MODE
from explorerscript.util import _


class SwitchHeaderDungeonModeCompileHandler(AbstractCompileHandler):
    def __init__(self, ctx, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self.value: Optional[SsbOpParam] = None

    def collect(self) -> SsbOperation:
        if self.value is None:
            raise SsbCompilerError(_("No dungeon id set for dungeon_mode switch condition."))

        return self._generate_operation(OP_SWITCH_DUNGEON_MODE, [self.value])

    def add(self, obj: any):
        if isinstance(obj, IntegerLikeCompileHandler):
            self.value = obj.collect()
            return

        self._raise_add_error(obj)
