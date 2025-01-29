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

import itertools
import logging
from collections import deque
from collections.abc import Mapping
from contextlib import contextmanager
from dataclasses import dataclass
from typing import TYPE_CHECKING, Any, TypeVar
from collections.abc import MutableSequence, Iterable, Iterator

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
from explorerscript_parser import ExplorerScriptParser, Antlr4ParserRuleContext, SsbScriptParser

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

_KT = TypeVar("_KT")  # Key type.
_VT_co = TypeVar("_VT_co", covariant=True)  # Value type covariant containers.


class MultiScopeDict(Mapping[_KT, _VT_co]):
    """A mapping backend by multiple dicts, which are looked up in descending order."""

    def __init__(self, *args: dict[_KT, _VT_co]) -> None:
        self.dicts = args

    def __getitem__(self, key: _KT) -> _VT_co:
        for a_dict in reversed(self.dicts):
            if key in a_dict:
                return a_dict[key]
        raise KeyError(key)

    def __contains__(self, key: Any) -> bool:
        for a_dict in reversed(self.dicts):
            if key in a_dict:
                return True
        return False

    def __len__(self) -> Any:
        raise NotImplementedError("MultiScopeDict can not be queried for length.")

    def __iter__(self) -> Any:
        raise NotImplementedError("MultiScopeDict can not be iterated.")


@dataclass
class UserDefinedConstants:
    """All known user defined constants"""

    global_constants: dict[str, SsbOpParam]
    funcdef_constants: dict[int | str, dict[str, SsbOpParam]]
    macrodefdef_constants: dict[str, dict[str, SsbOpParam]]

    def in_scope(self, scope_vars: dict[str, SsbOpParam]) -> Mapping[str, SsbOpParam]:
        """Returns the user defined constants available in the given scope"""
        return MultiScopeDict(self.global_constants, scope_vars)


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

    user_constants: UserDefinedConstants
    current_user_constants_scope: dict[str, SsbOpParam]

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
        user_constants: UserDefinedConstants,
    ):
        self.counter_ops = counter_ops
        self.source_map_builder = source_map_builder
        self.collected_labels = collected_labels
        self.counter_labels = counter_labels
        self.macros = macros

        self.performance_progress_list_var_name = performance_progress_list_var_name

        self.user_constants = user_constants
        self.current_user_constants_scope = {}

        self._loops = []
        self._switch_cases = []

    @contextmanager
    def in_funcdef(self, idx: str | int) -> Iterator[None]:
        self.current_user_constants_scope = self.user_constants.funcdef_constants.get(idx, {})
        yield
        self.current_user_constants_scope = {}

    @contextmanager
    def in_macrodef(self, idx: str) -> Iterator[None]:
        self.current_user_constants_scope = self.user_constants.macrodefdef_constants.get(idx, {})
        yield
        self.current_user_constants_scope = {}

    @contextmanager
    def in_loop(self, h: AnyLoopBlockCompileHandler) -> Iterator[None]:
        self._loops.append(h)
        yield
        self._loops.pop()

    @contextmanager
    def in_switch_case(self, h: DefaultCaseBlockCompileHandler | CaseBlockCompileHandler) -> Iterator[None]:
        self._switch_cases.append(h)
        yield
        self._switch_cases.pop()

    def continue_loop(self, ctx: Antlr4ParserRuleContext) -> SsbOperation:
        """Handle the continue opcode"""
        if len(self._loops) < 1:
            raise SsbCompilerError(f(_("Unexpected continue; in line {ctx.start.line}")))
        return self._loops[-1].continue_loop()

    def break_loop(self, ctx: Antlr4ParserRuleContext) -> SsbOperation:
        """Handle the break forever opcode"""
        if len(self._loops) < 1:
            raise SsbCompilerError(f(_("Unexpected break_loop; in line {ctx.start.line}")))
        return self._loops[-1].break_loop()

    def break_case(self, ctx: Antlr4ParserRuleContext) -> SsbOperation:
        """Handle the break opcode"""
        if len(self._switch_cases) < 1:
            raise SsbCompilerError(f(_("Unexpected break; in line {ctx.start.line}")))
        return self._switch_cases[-1].break_case()


class SsbLabelJumpBlueprint:
    """A builder for a label jump, to be used when compiling ifs/switches."""

    compiler_ctx: CompilerCtx
    ctx: Antlr4ParserRuleContext
    op_code_name: str
    params: MutableSequence[SsbOpParam]
    number: int | None
    jump_is_positive: bool

    def __init__(
        self,
        compiler_ctx: CompilerCtx,
        ctx: Antlr4ParserRuleContext,
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

        self.compiler_ctx.source_map_builder.add_opcode(
            number, self.ctx.start.line - 1, self.ctx.start.charPositionInLine
        )
        return SsbLabelJump(SsbOperation(number, SsbOpCode(-1, self.op_code_name), self.params), label)


def string_literal(string: ExplorerScriptParser.String_valueContext | SsbScriptParser.String_valueContext) -> str:
    single_line = string.STRING_LITERAL()
    if single_line:
        return singleline_string_literal(str(single_line))
    return multiline_string_literal(str(string.MULTILINE_STRING_LITERAL()))


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
            jump_counts: dict[int, int] = {}
            for op in routine:
                if isinstance(op, SsbLabelJump) and op.label is not None:
                    jump_counts[op.label.id] = jump_counts.get(op.label.id, 0) + 1

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
                            if jump_counts.get(op.id, 0) > 1:
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
