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

from explorerscript_parser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractComplexStatementCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_block import CaseBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.default_case_block import (
    DefaultCaseBlockCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_header import (
    SwitchHeaderCompileHandler,
)
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import (
    SsbLabel,
    OP_JUMP,
    OP_SWITCH_SCENARIO,
    OP_CASE_VALUE,
    OP_CASE_SCENARIO,
)
from explorerscript.util import _, f

_SupportedHandlers = Union[CaseBlockCompileHandler, DefaultCaseBlockCompileHandler, SwitchHeaderCompileHandler]


class SwitchBlockCompileHandler(
    AbstractComplexStatementCompileHandler[ExplorerScriptParser.Switch_blockContext, _SupportedHandlers]
):
    """Handles an entire switch block, with all it's cases."""

    def __init__(self, ctx: ExplorerScriptParser.Switch_blockContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._switch_header_handler: SwitchHeaderCompileHandler | None = None
        self._case_handlers: list[CaseBlockCompileHandler | DefaultCaseBlockCompileHandler] = []
        self._default_handler_index: int = -1
        self._default_handler: DefaultCaseBlockCompileHandler | None = None

    def collect(self) -> list[SsbOperation]:
        # 0. Prepare labels to insert
        default_start_label = SsbLabel(self.compiler_ctx.counter_labels(), -1, "switch default start label")
        end_label = SsbLabel(self.compiler_ctx.counter_labels(), -1, "entire switch-block end label")
        default_jmp_to_case_block: SsbLabelJumpBlueprint | None = None
        case_ops: list[SsbOperation] = []
        default_ops: list[SsbOperation]

        # 0b. Switch op
        assert self._switch_header_handler is not None
        switch_op = self._switch_header_handler.collect()

        # If there is no default and also no cases... we really don't need anything.
        if self._default_handler is None and len(self._case_handlers) == 0:
            return [switch_op]

        # 1. For each case: Generate and allocate case header op templates
        for h in self._case_handlers:
            h.set_end_label(end_label)
            if h.is_message_case:
                raise SsbCompilerError(
                    f(_("A switch case must contain a list of statements (line {self.ctx.start.line})."))
                )
            assert isinstance(h, CaseBlockCompileHandler)
            jmp_blueprint = h.get_header_jump_template()
            first = self.compiler_ctx.counter_ops.allocate(1)
            jmp_blueprint.set_index_number(first)
            # A little special case: If the switch header op is SwitchScenario and the case is CaseValue, change it to
            # CaseScenario, just to be more consistent with how the game odes it.
            if switch_op.op_code.name == OP_SWITCH_SCENARIO and jmp_blueprint.op_code_name == OP_CASE_VALUE:
                jmp_blueprint.op_code_name = OP_CASE_SCENARIO

        # 2. Default block (first because default is after no case op branched)
        if self._default_handler is not None:
            self._default_handler.set_end_label(end_label)
            default_ops = []
            # Insert a jump blueprint for now, note it, and if it comes up later during 3b,
            # process it like explained there.
            default_jmp_to_case_block = SsbLabelJumpBlueprint(self.compiler_ctx, self.ctx, OP_JUMP, [])
            self._case_handlers.insert(self._default_handler_index, self._default_handler)
        else:
            # 2c. If no default: Create a default block with just one jump to end label
            default_ops = [self._generate_jump_operation(OP_JUMP, [], end_label)]
        # 3. For each case:
        cases_waiting_for_a_block = []
        for i, h in enumerate(self._case_handlers):
            if not h.has_sub_block_handlers():
                # 3b. Else: Jump to the block of the next case which has a block.
                cases_waiting_for_a_block.append(h)
            else:
                # 3a. If the case has operations: Collect case sub-block ops
                ops = h.collect()
                start_label = h.get_start_label()
                assert start_label is not None
                if isinstance(h, DefaultCaseBlockCompileHandler):
                    assert default_jmp_to_case_block is not None
                    default_ops = [default_jmp_to_case_block.build_for(start_label)]
                for h_waiting in cases_waiting_for_a_block:
                    if isinstance(h_waiting, DefaultCaseBlockCompileHandler):
                        assert default_jmp_to_case_block is not None
                        default_ops = [default_jmp_to_case_block.build_for(start_label)]
                    else:
                        h_waiting.set_processed_header_jumps(
                            [h_waiting.get_header_jump_template().build_for(start_label)]
                        )
                cases_waiting_for_a_block = []
                case_ops += ops
        # 3c. Edge case: We expected a next case with ops, but got end of switch instead. Invalid!
        if len(cases_waiting_for_a_block) > 0:
            raise SsbCompilerError(f(_("Unexpected switch end (line {self.ctx.start.line})")))
        # 4. Build ops list
        header_ops = [switch_op]
        for h in self._case_handlers:
            header_ops += h.get_processed_header_jumps()
        return header_ops + [default_start_label] + default_ops + case_ops + [end_label]

    def add(self, obj: _SupportedHandlers) -> None:
        if isinstance(obj, CaseBlockCompileHandler):
            self._case_handlers.append(obj)
            return
        if isinstance(obj, DefaultCaseBlockCompileHandler):
            if self._default_handler is not None:
                raise SsbCompilerError(
                    f(_("A switch block can only have a single default case (line {self.ctx.start.line})."))
                )
            self._default_handler = obj
            self._default_handler_index = len(self._case_handlers)
            return
        if isinstance(obj, SwitchHeaderCompileHandler):
            self._switch_header_handler = obj
            return
        self._raise_add_error(obj)
