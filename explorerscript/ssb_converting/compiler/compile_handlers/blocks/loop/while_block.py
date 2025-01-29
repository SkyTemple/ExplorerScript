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

from typing import cast

from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractComplexLoopBlockCompileHandler,
    AbstractStatementCompileHandler,
    AbstractComplexStatementCompileHandler,
    AnyLoopBlockCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.if_header import IfHeaderCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, OP_JUMP
from explorerscript_parser import ExplorerScriptParser, Antlr4ParserRuleContext


class WhileBlockCompileHandler(
    AbstractComplexLoopBlockCompileHandler[
        ExplorerScriptParser.While_blockContext,
        "AbstractStatementCompileHandler[Antlr4ParserRuleContext] | IfHeaderCompileHandler",
    ]
):
    """
    Compiles a while loop:
    In the positive case: A forever loop with a Branch operation in the end, that checks if the loop should run,
    and a jump before the block to that check.

    Positive:
    - START_LABEL
    - Jump to CHECK_LABEL
    - BLOCK_LABEL
    - <...>
    - CHECK_LABEL
    - Branch? -> BLOCK_LABEL
    - END_LABEL

    Negative:
    - START_LABEL
    - Branch? -> END_LABEL
    - <...>
    - Jump to START_LABEL
    - END_LABEL
    """

    def __init__(self, ctx: ExplorerScriptParser.While_blockContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._branch_blueprint: SsbLabelJumpBlueprint | None = None

    def collect(self) -> list[SsbOperation]:
        with self.compiler_ctx.in_loop(cast(AnyLoopBlockCompileHandler, self)):
            is_positive = self.ctx.NOT() is None
            assert self._branch_blueprint is not None

            if is_positive:
                check_label = SsbLabel(self.compiler_ctx.counter_labels(), -1, f"{self.__class__.__name__} check label")
                block_label = SsbLabel(self.compiler_ctx.counter_labels(), -1, f"{self.__class__.__name__} block label")
                retval = (
                    [self._start_label, self._generate_jump_operation(OP_JUMP, [], check_label), block_label]
                    + self._process_block(False)
                    + [check_label, self._branch_blueprint.build_for(block_label), self._end_label]
                )
            else:
                retval = (
                    [
                        self._start_label,
                        self._branch_blueprint.build_for(self._end_label),
                    ]
                    + self._process_block(False)
                    + [self._generate_jump_operation(OP_JUMP, [], self._start_label), self._end_label]
                )
        return retval

    def add(self, obj: AbstractStatementCompileHandler[Antlr4ParserRuleContext] | IfHeaderCompileHandler) -> None:
        if isinstance(obj, IfHeaderCompileHandler):
            self._branch_blueprint = obj.collect()
            return
        if isinstance(obj, AbstractComplexStatementCompileHandler):
            self._added_handlers.append(obj)
            return
        self._raise_add_error(obj)
