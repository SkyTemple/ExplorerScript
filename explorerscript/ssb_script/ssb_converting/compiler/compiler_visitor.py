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

from enum import Enum, auto

from explorerscript.common_syntax import parse_position_marker_arg, parse_primitive, parse_for_target
from explorerscript.error import SsbCompilerError
from explorerscript.source_map import SourceMapBuilder, SourceMapPositionMark
from explorerscript.ssb_converting.compiler.utils import singleline_string_literal, string_literal
from explorerscript.ssb_converting.ssb_data_types import (
    SsbRoutineInfo,
    SsbOperation,
    SsbRoutineType,
    SsbOpParam,
    SsbOpCode,
    SsbOpParamConstString,
    SsbOpParamLanguageString,
    SsbOpParamConstant,
    SsbOpParamPositionMarker,
    SsbOpParamFixedPoint,
)
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, SsbLabelJump
from explorerscript.util import exps_int, _
from explorerscript_parser import SsbScriptBaseVisitor
from explorerscript_parser import SsbScriptParser


class ListenerArgType(Enum):
    INVALID = auto()
    INTEGER = auto()
    DECIMAL = auto()
    CONSTANT = auto()
    VARIABLE = auto()
    STRING_LITERAL = auto()
    LANGUAGE_STRING = auto()
    JUMP = auto()
    POSITION_MARKER = auto()


class SsbScriptCompilerVisitor(SsbScriptBaseVisitor):
    """Builds the SSB data structures while listening for parsing events."""

    def __init__(self) -> None:
        # The information about routines stored in the ssb.
        self.routine_infos: list[SsbRoutineInfo] = []
        self.routine_ops: list[list[SsbOperation]] = []
        self.named_coroutines: list[str] = []
        # A dict that assigns all collected labels their next opcode id.
        self.label_offsets: dict[int, int] = {}
        # Source map
        self.source_map_builder: SourceMapBuilder = SourceMapBuilder()

        self._is_processing_argument = False
        self._argument_type: ListenerArgType = ListenerArgType.INVALID
        self._argument_value: int | str | dict[str, str] = -1

        self._last_op_line = -1
        self._op_idx_in_current_line = 0

        self._collected_lang_string: dict[str, str] = {}
        self._collected_pos_marker: SsbOpParamPositionMarker | None = None

        self._collected_labels: dict[str, SsbLabel] = {}
        self._label_increment_id = -1
        self._turn_next_op_into_label_jump_for: SsbLabel | None = None
        self._labels_before_op: list[SsbLabel] = []

        self._total_number_collected_ops = -1
        self._collected_ops: list[SsbOperation] = []
        self._active_routine_id = -1
        self._collected_params: list[SsbOpParam] = []
        super().__init__()

    def visitSimple_def(self, ctx: SsbScriptParser.Simple_defContext) -> None:
        self.visitChildren(ctx)
        self._active_routine_id = exps_int(str(ctx.INTEGER()))
        self._enlarge_routine_info()
        self.routine_infos[self._active_routine_id] = SsbRoutineInfo(SsbRoutineType.GENERIC, 0)
        self.routine_ops[self._active_routine_id] = self._collected_ops
        self._collected_ops = []

    def visitCoro_def(self, ctx: SsbScriptParser.Coro_defContext) -> None:
        self.visitChildren(ctx)
        self._active_routine_id += 1
        self._enlarge_routine_info()
        self.named_coroutines[self._active_routine_id] = str(ctx.IDENTIFIER())
        self.routine_infos[self._active_routine_id] = SsbRoutineInfo(SsbRoutineType.COROUTINE, 0)
        self.routine_ops[self._active_routine_id] = self._collected_ops
        self._collected_ops = []

    def visitFor_target_def(self, ctx: SsbScriptParser.For_target_defContext) -> None:
        self.visitChildren(ctx)
        self._active_routine_id = exps_int(str(ctx.INTEGER()))
        self._enlarge_routine_info()
        linked_to, linked_to_name = parse_for_target(parse_primitive(ctx.primitive(), allow_string=False))

        target: SsbScriptParser.For_target_def_targetContext = ctx.for_target_def_target()
        legacy_deprecated_target = target.FOR_TARGET()
        new_style_target = target.IDENTIFIER()
        if str(legacy_deprecated_target) == "for_actor" or str(new_style_target) == "actor":
            self.routine_infos[self._active_routine_id] = SsbRoutineInfo(
                SsbRoutineType.ACTOR, linked_to, linked_to_name
            )
        elif str(legacy_deprecated_target) == "for_object" or str(new_style_target) == "object":
            self.routine_infos[self._active_routine_id] = SsbRoutineInfo(
                SsbRoutineType.OBJECT, linked_to, linked_to_name
            )
        elif str(legacy_deprecated_target) == "for_performer" or str(new_style_target) == "performer":
            self.routine_infos[self._active_routine_id] = SsbRoutineInfo(
                SsbRoutineType.PERFORMER, linked_to, linked_to_name
            )
        else:
            raise SsbCompilerError("A targeted routine must be 'for' an 'actor', 'object' or 'performer'.")
        self.routine_ops[self._active_routine_id] = self._collected_ops
        self._collected_ops = []

    def visitOperation(self, ctx: SsbScriptParser.OperationContext) -> None:
        self.visitChildren(ctx)
        op_code_name = str(ctx.IDENTIFIER())

        collected_params = self._collected_params
        self._collected_params = []

        inline_ctx = ctx.inline_ctx()
        if inline_ctx is not None:
            raise SsbCompilerError(_("Operations in SSBScript cannot contain an inline context."))

        self._total_number_collected_ops += 1
        root_op = SsbOperation(self._total_number_collected_ops, SsbOpCode(-1, op_code_name), collected_params)
        if not self._turn_next_op_into_label_jump_for:
            self._collected_ops.append(root_op)
        else:
            self._collected_ops.append(SsbLabelJump(root_op, self._turn_next_op_into_label_jump_for))
            self._turn_next_op_into_label_jump_for = None

        # Collect the opcode ID for the label that was right before this operation.
        while len(self._labels_before_op) > 0:
            label_before_op = self._labels_before_op.pop()
            self.label_offsets[label_before_op.id] = self._total_number_collected_ops

        # Add to source map
        self.source_map_builder.add_opcode(
            # Antlr line ids are 1-indexed.
            self._total_number_collected_ops,
            ctx.start.line - 1,
            ctx.start.charPositionInLine,
        )

        # Add position marker to source map
        if ctx.start.line != self._last_op_line:
            self._last_op_line = ctx.start.line
            self._op_idx_in_current_line = 0
        else:
            self._op_idx_in_current_line += 1
        for i, arg in enumerate(collected_params):
            if isinstance(arg, SsbOpParamPositionMarker):
                self.source_map_builder.add_position_mark(
                    SourceMapPositionMark(
                        # Antlr line ids are 1-indexed.
                        ctx.start.line - 1,
                        ctx.start.charPositionInLine,
                        ctx.stop.line - 1,
                        ctx.stop.charPositionInLine,
                        arg.name,
                        arg.x_offset,
                        arg.y_offset,
                        arg.x_relative,
                        arg.y_relative,
                    )
                )

    def visitPos_argument(self, ctx: SsbScriptParser.Pos_argumentContext) -> None:
        self._is_processing_argument = True
        self.visitChildren(ctx)
        self._is_processing_argument = False
        self._turn_next_op_into_label_jump_for = None
        if self._argument_type == ListenerArgType.JUMP:
            label_name = self._argument_value
            assert isinstance(label_name, str)
            if label_name in self._collected_labels:
                label = self._collected_labels[label_name]
            else:
                self._label_increment_id += 1
                label = SsbLabel(
                    self._label_increment_id,
                    -1,  # todo: routine id is not set yet, but not used anyway.
                )
                self._collected_labels[label_name] = label
            self._turn_next_op_into_label_jump_for = label
        elif self._argument_type == ListenerArgType.STRING_LITERAL:
            assert isinstance(self._argument_value, str)
            self._collected_params.append(SsbOpParamConstString(self._argument_value))
        elif self._argument_type == ListenerArgType.LANGUAGE_STRING:
            assert isinstance(self._argument_value, dict)
            self._collected_params.append(SsbOpParamLanguageString(self._argument_value))
        elif self._argument_type == ListenerArgType.INTEGER:
            assert isinstance(self._argument_value, int)
            self._collected_params.append(self._argument_value)
        elif self._argument_type == ListenerArgType.DECIMAL:
            assert isinstance(self._argument_value, str)
            self._collected_params.append(SsbOpParamFixedPoint.from_str(self._argument_value))
        elif self._argument_type == ListenerArgType.VARIABLE:
            assert isinstance(self._argument_value, str)
            self._collected_params.append(SsbOpParamConstant(self._argument_value))
        elif self._argument_type == ListenerArgType.CONSTANT:
            assert isinstance(self._argument_value, str)
            self._collected_params.append(SsbOpParamConstant(self._argument_value))
        elif self._argument_type == ListenerArgType.POSITION_MARKER:
            assert self._collected_pos_marker is not None
            self._collected_params.append(self._collected_pos_marker)

    def visitPosition_marker(self, ctx: SsbScriptParser.Position_markerContext) -> None:
        if self._is_processing_argument:
            self._collected_pos_marker = SsbOpParamPositionMarker("NOT SET", -1, -1, -1, -1)
        self.visitChildren(ctx)
        if self._is_processing_argument:
            assert self._collected_pos_marker is not None
            self._collected_pos_marker.name = singleline_string_literal(str(ctx.STRING_LITERAL()))

    def visitPosition_marker_arg(self, ctx: SsbScriptParser.Position_marker_argContext) -> None:
        self.visitChildren(ctx)
        if self._is_processing_argument:
            assert self._collected_pos_marker is not None
            self._argument_type = ListenerArgType.POSITION_MARKER
            relative, offset = parse_position_marker_arg(ctx)
            if self._collected_pos_marker.x_offset == -1:
                # We collected the x argument
                self._collected_pos_marker.x_offset = offset
                self._collected_pos_marker.x_relative = relative
            else:
                # We collected the y argument
                self._collected_pos_marker.y_offset = offset
                self._collected_pos_marker.y_relative = relative

    def visitPrimitive(self, ctx: SsbScriptParser.PrimitiveContext) -> None:
        self.visitChildren(ctx)
        if self._is_processing_argument:
            if ctx.INTEGER():
                self._argument_type = ListenerArgType.INTEGER
                self._argument_value = exps_int(str(ctx.INTEGER()))
            elif ctx.DECIMAL():
                self._argument_type = ListenerArgType.DECIMAL
                self._argument_value = str(ctx.DECIMAL())
            elif ctx.IDENTIFIER():
                self._argument_type = ListenerArgType.CONSTANT
                self._argument_value = str(ctx.IDENTIFIER())
            elif ctx.VARIABLE():
                self._argument_type = ListenerArgType.VARIABLE
                self._argument_value = str(ctx.VARIABLE())
            # Strings are processed in exitString/exitLang_string

    def visitJump_marker(self, ctx: SsbScriptParser.Jump_markerContext) -> None:
        self.visitChildren(ctx)
        if self._is_processing_argument:
            self._argument_type = ListenerArgType.JUMP
            self._argument_value = str(ctx.IDENTIFIER())

    def visitString(self, ctx: SsbScriptParser.StringContext) -> None:
        self.visitChildren(ctx)
        if self._is_processing_argument:
            string_value = ctx.string_value()
            if string_value:
                self._argument_type = ListenerArgType.STRING_LITERAL
                self._argument_value = string_literal(ctx.string_value())
            else:
                # Process the collected lang string
                self._argument_type = ListenerArgType.LANGUAGE_STRING
                self._argument_value = self._collected_lang_string

    def visitLang_string(self, ctx: SsbScriptParser.Lang_stringContext) -> None:
        self._collected_lang_string = {}
        self.visitChildren(ctx)

    def visitLang_string_argument(self, ctx: SsbScriptParser.Lang_string_argumentContext) -> None:
        self.visitChildren(ctx)
        self._collected_lang_string[str(ctx.IDENTIFIER())] = string_literal(ctx.string_value())

    def visitLabel(self, ctx: SsbScriptParser.LabelContext) -> None:
        self.visitChildren(ctx)
        label_name = str(ctx.IDENTIFIER())

        if label_name in self._collected_labels:
            label = self._collected_labels[label_name]
        else:
            self._label_increment_id += 1
            label = SsbLabel(
                self._label_increment_id,
                -1,  # todo: routine id is not set yet, but not used anyway.
            )
            self._collected_labels[label_name] = label

        self._collected_ops.append(label)

        # Set this, so that the next operation can set the offset to this pos.
        # This is a list, because in theory there can be multiple labels right next to each other, pointing
        # to the same op.
        self._labels_before_op.append(label)

    def _enlarge_routine_info(self) -> None:
        if len(self.routine_infos) - 1 < self._active_routine_id:
            needed = self._active_routine_id - len(self.routine_infos) + 1
            for i in range(0, needed):
                self.routine_infos.append(None)  # type: ignore
                self.routine_ops.append([])
                self.named_coroutines.append([])  # type: ignore
