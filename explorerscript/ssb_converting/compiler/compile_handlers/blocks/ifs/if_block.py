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
from typing import List, Optional

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractBlockCompileHandler, \
    AbstractStatementCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.else_block import ElseBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.elseif_block import ElseIfBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.if_header import IfHeaderCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel


class IfBlockCompileHandler(AbstractBlockCompileHandler):
    """Handles an entire if block, with it's optional elseif and else sub-blocks."""
    def __init__(self, ctx, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._if_header_handlers: List[IfHeaderCompileHandler] = []
        self._else_if_handlers: List[ElseIfBlockCompileHandler] = []
        self._else_handler: Optional[ElseBlockCompileHandler] = None

    def collect(self) -> List[SsbOperation]:
        self.ctx: ExplorerScriptParser.If_blockContext
        if_block_ops: List[SsbOperation]
        elseif_blocks_ops: List[List[SsbOperation]] = []
        else_block_ops: List[SsbOperation]
        # 0. Prepare the end label to insert.
        end_label = SsbLabel(
            self.compiler_ctx.counter_labels(), -1  # todo: routine id is not set yet, but not used anyway.
        )

        # 1. Generate and allocate if header op templates
        self._header_jump_blueprints = [h.collect() for h in self._if_header_handlers]
        first = self.compiler_ctx.counter_ops.allocate(len(self._header_jump_blueprints))
        for i, h in enumerate(self._header_jump_blueprints):
            h.set_index_number(first + i)
        # 2. For each else if: Generate and allocate if header op templates
        for else_if_h in self._else_if_handlers:
            jmp_blueprints = else_if_h.create_header_jump_templates()
            first = self.compiler_ctx.counter_ops.allocate(len(jmp_blueprints))
            for i, h in enumerate(jmp_blueprints):
                h.set_index_number(first + i)
        # 3. Collect else sub block ops (first because else is after no branch op branched)
        if self._else_handler:
            else_block_ops = self._else_handler.collect()
        # 3b. If no else: Create an else block with just one jump without target
        else:
            else_block_ops = [self._generate_empty_jump()]
        # 4. Collect If sub block ops
        if_block_ops = self._process_block()
        # 5. Collect elseif sub block ops
        for h in self._else_if_handlers:
            elseif_blocks_ops.append(h.collect())
        # 6. Go through all blocks and check, if the last op is a jump without target
        #    if so: insert jump to the end label
        self._update_last_jump_to_end_label(if_block_ops, end_label)
        for block in elseif_blocks_ops:
            self._update_last_jump_to_end_label(block, end_label)
        self._update_last_jump_to_end_label(else_block_ops, end_label)
        # 7. Build ops list
        ops = self.get_processed_header_jumps()
        for h in self._else_if_handlers:
            ops += h.get_processed_header_jumps()
        ops += else_block_ops
        ops += if_block_ops
        for o in elseif_blocks_ops:
            ops += o
        return ops + [end_label]

    def add(self, obj: any):
        if isinstance(obj, AbstractStatementCompileHandler):
            # Sub statement for the block
            self._added_handlers.append(obj)
            return
        if isinstance(obj, IfHeaderCompileHandler):
            self._if_header_handlers.append(obj)
            return
        if isinstance(obj, ElseIfBlockCompileHandler):
            self._else_if_handlers.append(obj)
            return
        if isinstance(obj, ElseBlockCompileHandler):
            self._else_handler = obj
            return
        self._raise_add_error(obj)
