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
    AbstractStatementCompileHandler,
    AbstractComplexStatementCompileHandler,
    AbstractLoopBlockCompileHandler,
    AnyLoopBlockCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.if_header import IfHeaderCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import OP_JUMP, SsbLabel
from explorerscript_parser import ExplorerScriptParser, Antlr4ParserRuleContext


class ForBlockCompileHandler(AbstractLoopBlockCompileHandler[ExplorerScriptParser.For_blockContext]):
    """
    Compiles a for loop.
    It has three parts:
    - <Init Statement>: The statement to run before the loop starts, to initialize it
    - <Check If Header>: The if-condition to check if the loop should be repeated (also before first run)
    - <End Statement>: The statement to run after each run of the loop

    If the loops is continue'd the end statement is still run and also the check! -> jump to NEW_RUN_LABEL.

    Structure:
    - START_LABEL
    - <Init Statement>
    - Jump to INITIAL_LABEL

    - BLOCK_LABEL
    - <...>

    - NEW_RUN_LABEL
    - <End Statement>

    - INITIAL_LABEL
    - Branch <Check If Header>? -> BLOCK_LABEL
    - END_LABEL
    """

    def __init__(self, ctx: ExplorerScriptParser.For_blockContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._block_label = SsbLabel(self.compiler_ctx.counter_labels(), -1, f"{self.__class__.__name__} block label")
        self._new_run_label = SsbLabel(
            self.compiler_ctx.counter_labels(), -1, f"{self.__class__.__name__} new run label"
        )
        self._initial_label = SsbLabel(
            self.compiler_ctx.counter_labels(), -1, f"{self.__class__.__name__} initial label"
        )
        self._branch_blueprint: SsbLabelJumpBlueprint | None = None
        self._init_statement_handler: AbstractStatementCompileHandler[Antlr4ParserRuleContext] | None = None
        self._end_statement_handler: AbstractStatementCompileHandler[Antlr4ParserRuleContext] | None = None

    def collect(self) -> list[SsbOperation]:
        with self.compiler_ctx.in_loop(cast(AnyLoopBlockCompileHandler, self)):
            assert (
                self._init_statement_handler is not None
                and self._end_statement_handler is not None
                and self._branch_blueprint is not None
            )
            retval = (
                [self._start_label]
                + self._init_statement_handler.collect()
                + [self._generate_jump_operation(OP_JUMP, [], self._initial_label), self._block_label]
                + self._process_block(False)
                + [self._new_run_label]
                + self._end_statement_handler.collect()
                + [self._initial_label, self._branch_blueprint.build_for(self._block_label), self._end_label]
            )
        return retval

    def add(self, obj: AbstractStatementCompileHandler[Antlr4ParserRuleContext]) -> None:
        if isinstance(obj, AbstractComplexStatementCompileHandler):
            if self._init_statement_handler is None:
                self._init_statement_handler = obj
            elif self._end_statement_handler is None:
                self._end_statement_handler = obj
            else:
                self._added_handlers.append(obj)
            return
        if isinstance(obj, IfHeaderCompileHandler):
            self._branch_blueprint = obj.collect()
            return
        self._raise_add_error(obj)

    def continue_loop(self) -> SsbOperation:
        return self._generate_jump_operation(OP_JUMP, [], self._new_run_label)
