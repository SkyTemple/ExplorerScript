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
from typing import List

from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractBlockCompileHandler, \
    AbstractStatementCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, OP_JUMP


class ForeverBlockCompileHandler(AbstractBlockCompileHandler):
    """Handles an entire forever block."""
    def __init__(self, ctx, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._start_label = SsbLabel(
            self.compiler_ctx.counter_labels(), -1  # todo: routine id is not set yet, but not used anyway.
        )
        self._end_label = SsbLabel(
            self.compiler_ctx.counter_labels(), -1  # todo: routine id is not set yet, but not used anyway.
        )

    def collect(self) -> List[SsbOperation]:
        self.compiler_ctx.add_forever(self)
        retval = [self._start_label] + self._process_block(False) + [self._end_label]
        self.compiler_ctx.remove_forever()
        return retval

    def continue_forever(self) -> SsbOperation:
        return self._generate_jump_operation(OP_JUMP, [], self._start_label)

    def break_forever(self) -> SsbOperation:
        return self._generate_jump_operation(OP_JUMP, [], self._end_label)

    def add(self, obj: any):
        if isinstance(obj, AbstractStatementCompileHandler):
            # Sub statement for the block
            self._added_handlers.append(obj)
            return
        self._raise_add_error(obj)
