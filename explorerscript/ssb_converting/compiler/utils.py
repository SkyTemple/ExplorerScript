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
from __future__ import annotations

import itertools
import logging
from collections import deque
from typing import TYPE_CHECKING, MutableSequence, Iterable, Any

from antlr4 import ParserRuleContext

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.source_map import SourceMapBuilder
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam, SsbOpCode
from explorerscript.ssb_converting.ssb_special_ops import (
    SsbLabel,
    SsbLabelJump,
    OPS_THAT_END_CONTROL_FLOW,
    OP_DUMMY_END,
    OPS_CTX,
)
from explorerscript.util import f, _

logger = logging.getLogger(__name__)

if TYPE_CHECKING:
    from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AnyLoopBlockCompileHandler
    from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_block import (
        CaseBlockCompileHandler,
    )
    from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.default_case_block import (
        DefaultCaseBlockCompileHandler,
    )
    from explorerscript.macro import ExplorerScriptMacro


class Counter:
    count: int

    def __init__(self) -> None:
        self.count = 0

    def __call__(self, *args, **kwargs):  # type: ignore
        self.count += 1
        return self.count

    def allocate(self, how_many: int) -> int:
        """
        Pre-allocate a certain number of opcodes for the counter, this will increase
        the counter by the given amount and return the first allocated number.
        """
        first = self.count + 1
        self.count += how_many
        return first

    @property
    def next_id(self) -> int:
        return self.count + 1


class CompilerCtx:
    counter_ops: Counter
    source_map_builder: SourceMapBuilder
    # A dict that assigns all collected labels their next opcode id.
    collected_labels: dict[str, SsbLabel]
    counter_labels: Counter
    # Loaded macros that can be used for macro calls.
    macros: dict[str, ExplorerScriptMacro]

    performance_progress_list_var_name: str

    # Current handlers for structures that have ending opcodes collected by child handlers
    _loops: list[AnyLoopBlockCompileHandler]
    _switch_cases: list[DefaultCaseBlockCompileHandler | CaseBlockCompileHandler]

    def __init__(
        self,
        counter_ops: Counter,
        source_map_builder: SourceMapBuilder,
        collected_labels: dict[str, SsbLabel],
        counter_labels: Counter,
        performance_progress_list_var_name: str,
        macros: dict[str, ExplorerScriptMacro],
    ):
        self.counter_ops = counter_ops
        self.source_map_builder = source_map_builder
        self.collected_labels = collected_labels
        self.counter_labels = counter_labels
        self.macros = macros

        self.performance_progress_list_var_name = performance_progress_list_var_name

        self._loops = []
        self._switch_cases = []

    def add_loop(self, h: AnyLoopBlockCompileHandler) -> None:
        self._loops.append(h)

    def remove_loop(self) -> None:
        self._loops.pop()

    def add_switch_case(self, h: DefaultCaseBlockCompileHandler | CaseBlockCompileHandler) -> None:
        self._switch_cases.append(h)

    def remove_switch_case(self) -> None:
        self._switch_cases.pop()

    def continue_loop(self, ctx: ParserRuleContext) -> SsbOperation:
        """Handle the continue opcode"""
        if len(self._loops) < 1:
            raise SsbCompilerError(f(_("Unexpected continue; in line {ctx.start.line}")))
        return self._loops[-1].continue_loop()

    def break_loop(self, ctx: ParserRuleContext) -> SsbOperation:
        """Handle the break forever opcode"""
        if len(self._loops) < 1:
            raise SsbCompilerError(f(_("Unexpected break_loop; in line {ctx.start.line}")))
        return self._loops[-1].break_loop()

    def break_case(self, ctx: ParserRuleContext) -> SsbOperation:
        """Handle the break opcode"""
        if len(self._switch_cases) < 1:
            raise SsbCompilerError(f(_("Unexpected break; in line {ctx.start.line}")))
        return self._switch_cases[-1].break_case()


class SsbLabelJumpBlueprint:
    """A builder for a label jump, to be used when compiling ifs/switches."""

    compiler_ctx: CompilerCtx
    ctx: ParserRuleContext
    op_code_name: str
    params: MutableSequence[SsbOpParam]
    number: int | None
    jump_is_positive: bool

    def __init__(
        self,
        compiler_ctx: CompilerCtx,
        ctx: ParserRuleContext,
        op_code_name: str,
        params: MutableSequence[SsbOpParam],
        jump_is_positive: bool = True,
    ):
        self.compiler_ctx: CompilerCtx = compiler_ctx
        self.ctx = ctx
        self.op_code_name: str = op_code_name
        self.params = params
        # offset indices for these blueprints can be pre-allocated.
        self.number = None
        # Whether or not this jump is negated (False) or not (True)
        self.jump_is_positive = jump_is_positive

    def set_index_number(self, number: int) -> None:
        self.number = number

    def set_jump_is_positive(self, val: bool) -> None:
        self.jump_is_positive = val

    def build_for(self, label: SsbLabel) -> SsbLabelJump:
        """Create a new jump operation for the given label. Counters will be increased, souce map updated."""
        assert label is not None
        number = self.number
        if number is None:
            number = self.compiler_ctx.counter_ops()

        self.compiler_ctx.source_map_builder.add_opcode(number, self.ctx.start.line - 1, self.ctx.start.column)
        return SsbLabelJump(SsbOperation(number, SsbOpCode(-1, self.op_code_name), self.params), label)


def string_literal(string: ExplorerScriptParser.String_valueContext) -> str:
    single_line = string.STRING_LITERAL()
    if single_line:
        return singleline_string_literal(single_line)
    return multiline_string_literal(string.MULTILINE_STRING_LITERAL())


def singleline_string_literal(string: str) -> str:
    # This isn't the greatest escaping but it works for most cases. Changing it now would be backwards incompatible.
    return str(string)[1:-1].replace('\\"', '"').replace("\\'", "'").replace("\\n", "\n")


def multiline_string_literal(string: str) -> str:
    string = str(string)[3:-3]
    all_lines = string.splitlines()
    lines: list[str] = []
    last_line = ""

    if len(all_lines) == 0:
        first_line = ""
    elif len(all_lines) == 1:
        first_line = all_lines[0]
    elif len(all_lines) == 2:
        first_line = all_lines[0]
        last_line = all_lines[1]
    else:
        [first_line, *lines, last_line] = all_lines

    last_line_stripped = last_line.lstrip(" ")
    if len(last_line_stripped) != 0:
        # The last line contains characters, treat it as normal.
        lines.append(last_line)

    whitespace_counts: list[int] = [_count_iter_items(itertools.takewhile(lambda c: c == " ", line)) for line in lines]
    min_whitespace_count = min(whitespace_counts, default=0)

    transformed_lines = [line[min_whitespace_count:] for line in lines]

    nl_if_lines = "\n" if first_line != "" and len(transformed_lines) > 0 else ""

    return first_line + nl_if_lines + "\n".join(transformed_lines)


def _count_iter_items(iterable: Iterable[Any]) -> int:
    """
    Consume an iterable not reading it into memory; return the number of items.
    """
    counter = itertools.count()
    deque(zip(iterable, counter), maxlen=0)
    return next(counter)


def routine_op_offsets_are_ordered(routine_ops: list[list[SsbOperation]]) -> bool:
    last_offset = -1
    for routine in routine_ops:
        for op in routine:
            if op.offset != -1 and op.offset <= last_offset:
                return False
            last_offset = op.offset

    return True


def strip_last_label(routine_ops: list[list[SsbOperation]]) -> list[list[SsbOperation]]:
    """
    Checks if the last opcode of a routine is a label, and if so
    removes it. if there are jumps to it, they are removed and replaced with an OP_DUMMY_END.
    """
    logger.debug("Stripping last label...")
    returned_routine_ops = []
    for routine in routine_ops:
        if len(routine) > 0:
            while isinstance(routine[-1], SsbLabel):
                indices_to_remove = set()
                label = routine[-1]
                # Remove the label
                del routine[-1]
                # Replace the jumps to it with returns
                op_before_ends_control_flow = False
                for op_i, op in enumerate(routine):
                    if isinstance(op, SsbLabelJump) and op.label == label:
                        # We only have to insert the OP_DUMMY_END, if the previous op didn't end control flow
                        if op_before_ends_control_flow:
                            indices_to_remove.add(op_i)
                        else:
                            routine[op_i] = SsbOperation(op.offset, SsbOpCode(-1, OP_DUMMY_END), [])
                            op_before_ends_control_flow = False
                    else:
                        if isinstance(op, SsbLabel):
                            # If there is a label before, then something might jump here!
                            if _number_of_jumps_to_label(op, routine) > 1:
                                op_before_ends_control_flow = False
                        else:
                            op_before_ends_control_flow = does_op_end_control_flow(
                                op, routine[op_i - 1] if op_i > 0 else None
                            )
                routine = [x for i, x in enumerate(routine) if i not in indices_to_remove]
            returned_routine_ops.append(routine)
        else:
            returned_routine_ops.append([])
    return returned_routine_ops


def does_op_end_control_flow(op: SsbOperation, previous_op: SsbOperation | None) -> bool:
    if previous_op is not None and previous_op.op_code.name in OPS_CTX:
        return False
    if isinstance(op, SsbLabelJump):
        return op.root.op_code.name in OPS_THAT_END_CONTROL_FLOW
    return op.op_code.name in OPS_THAT_END_CONTROL_FLOW


def _number_of_jumps_to_label(label: SsbLabel, routine: list[SsbOperation]) -> int:
    counter = 0
    for o in routine:
        if isinstance(o, SsbLabelJump) and o.label == label:
            counter += 1
    return counter
