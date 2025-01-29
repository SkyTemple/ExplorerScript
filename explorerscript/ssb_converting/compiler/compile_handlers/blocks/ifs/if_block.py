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

from typing import Union

from typing import TypeAlias


from explorerscript_parser import ExplorerScriptParser, Antlr4ParserRuleContext
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractComplexBlockCompileHandler,
    AbstractStatementCompileHandler,
    AbstractComplexStatementCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.else_block import ElseBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.elseif_block import ElseIfBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.if_header import IfHeaderCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, SsbLabelJump, OP_JUMP

_SupportedHandlers: TypeAlias = Union[
    AbstractStatementCompileHandler[Antlr4ParserRuleContext],
    IfHeaderCompileHandler,
    ElseIfBlockCompileHandler,
    ElseBlockCompileHandler,
]


class IfBlockCompileHandler(
    AbstractComplexBlockCompileHandler[ExplorerScriptParser.If_blockContext, _SupportedHandlers]
):
    """Handles an entire if block, with it's optional elseif and else sub-blocks."""

    def __init__(self, ctx: ExplorerScriptParser.If_blockContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._if_header_handlers: list[IfHeaderCompileHandler] = []
        self._else_if_handlers: list[ElseIfBlockCompileHandler] = []
        self._else_handler: ElseBlockCompileHandler | None = None

    def collect(self) -> list[SsbOperation]:
        self.ctx: ExplorerScriptParser.If_blockContext
        if_header__allocations: list[int] = []  # list index in ops!
        if_block__was_output = False
        elseif_header__allocations: list[list[int]] = []  # list index in ops!
        elseif_block__was_output: list[bool] = []
        # 0. Prepare the end label to insert.
        end_label = SsbLabel(self.compiler_ctx.counter_labels(), -1, "entire if-block end label")
        is_positive = self.ctx.NOT() is None

        ops: list[SsbOperation] = []

        # 1. Go over all if header ops:
        for h in self._if_header_handlers:
            ops.append(None)  # type: ignore
            h.set_positive(is_positive)
            jmpb = h.collect()
            self._header_jump_blueprints.append(jmpb)
            jmpb.set_index_number(self.compiler_ctx.counter_ops.allocate(1))
            # Allocate 1 for it's branch op
            if_header__allocations.append(len(ops) - 1)
        if not self._header_jump_blueprints[0].jump_is_positive:
            # If all the header jumps are negative (if one is all are!) output the block now, else do it later
            if_block__was_output = True
            ops += self._process_block()
        # 2. For each else if: Go over all if header ops:
        for else_if_h in self._else_if_handlers:
            jmp_blueprints = else_if_h.create_header_jump_templates()
            this_elseif__allocations = []
            this_elseif__was_output = False
            for jmpb in jmp_blueprints:
                ops.append(None)  # type: ignore
                jmpb.set_index_number(self.compiler_ctx.counter_ops.allocate(1))
                # Allocate 1 for it's branch op
                this_elseif__allocations.append(len(ops) - 1)
            if not jmp_blueprints[0].jump_is_positive:
                # If all the header jumps are negative (if one is all are!) output the block now, else do it later
                this_elseif__was_output = True
                ops += else_if_h.collect()
            elseif_header__allocations.append(this_elseif__allocations)
            elseif_block__was_output.append(this_elseif__was_output)
        # 3. Collect else sub block ops
        if self._else_handler:
            ops += self._else_handler.collect()
        else:
            # 3b. If no else: Create an else block with just one jump without target
            ops.append(self._generate_empty_jump())
        # 4. Collect if sub block ops, if not already done
        if not if_block__was_output:
            if_block__was_output = True
            ops += self._process_block()
        # 5. Collect remaining elseif sub block ops
        for i, else_if_h in enumerate(self._else_if_handlers):
            if not elseif_block__was_output[i]:
                elseif_block__was_output[i] = True
                ops += else_if_h.collect()
        # 6. Go through all blocks and check, if the last op is a jump without target
        #    if so: insert jump to the end label
        for op in ops:
            if isinstance(op, SsbLabelJump) and op.root.op_code.name == OP_JUMP and op.label is None:
                op.label = end_label
        # 7. Process header ops
        for i, jmp in enumerate(self.get_processed_header_jumps()):
            allocation = if_header__allocations[i]
            ops[allocation] = jmp
        for i, else_if_h in enumerate(self._else_if_handlers):
            for j, jmp in enumerate(else_if_h.get_processed_header_jumps()):
                allocation = elseif_header__allocations[i][j]
                ops[allocation] = jmp

        return ops + [end_label]

    def add(self, obj: _SupportedHandlers) -> None:
        if isinstance(obj, IfHeaderCompileHandler):
            self._if_header_handlers.append(obj)
            return
        if isinstance(obj, ElseIfBlockCompileHandler):
            self._else_if_handlers.append(obj)
            return
        if isinstance(obj, ElseBlockCompileHandler):
            self._else_handler = obj
            return
        if isinstance(obj, AbstractComplexStatementCompileHandler):
            # Sub statement for the block
            self._added_handlers.append(obj)
            return
        self._raise_add_error(obj)
