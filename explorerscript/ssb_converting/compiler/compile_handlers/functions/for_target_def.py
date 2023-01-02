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
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractFuncdefCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.integer_like import IntegerLikeCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbRoutineType
from explorerscript.util import exps_int


class ForTargetDefCompileHandler(AbstractFuncdefCompileHandler):
    def __init__(self, ctx, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._linked_to_target = None

    def collect(self) -> any:
        """Collects routine info and operations."""
        linked_to = -1
        linked_to_name = None
        integer_like = self._linked_to_target
        try:
            linked_to = exps_int(integer_like)
        except:
            linked_to_name = integer_like.name

        if str(self.ctx.FOR_TARGET()) == 'for_actor':
            routine_info = SsbRoutineInfo(SsbRoutineType.ACTOR, linked_to, linked_to_name)
        elif str(self.ctx.FOR_TARGET()) == 'for_object':
            routine_info = SsbRoutineInfo(SsbRoutineType.OBJECT, linked_to, linked_to_name)
        else:
            routine_info = SsbRoutineInfo(SsbRoutineType.PERFORMER, linked_to, linked_to_name)

        return routine_info, self.collect_ops()

    def get_new_routine_id(self, old_id: int) -> int:
        return exps_int(str(self.ctx.INTEGER()))

    def add(self, obj: any):
        if isinstance(obj, IntegerLikeCompileHandler):
            self._linked_to_target = obj.collect()
            return
        super().add(obj)
