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
from enum import Enum, auto
from typing import Optional, List, Union, Dict

from explorerscript.source_map import SourceMapBuilder, SourceMapPositionMark
from explorerscript.ssb_converting.compiler.utils import string_literal
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbOperation, SsbRoutineType, SsbOpParam, \
    SsbOpCode, SsbOpParamConstString, SsbOpParamLanguageString, SsbOpParamConstant, SsbOpParamPositionMarker
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, SsbLabelJump
from explorerscript.antlr.SsbScriptListener import SsbScriptListener
from explorerscript.antlr.SsbScriptParser import SsbScriptParser
from explorerscript.util import exps_int


class ListenerArgType(Enum):
    INVALID = auto()
    INTEGER = auto()
    CONSTANT = auto()
    STRING_LITERAL = auto()
    LANGUAGE_STRING = auto()
    JUMP = auto()
    POSITION_MARKER = auto()


class SsbScriptCompilerListener(SsbScriptListener):
    """Builds the SSB data structures while listening for parsing events."""
    def __init__(self):
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
        self._argument_value: Union[int, str, dict[str, str]] = -1

        self._last_op_line = -1
        self._op_idx_in_current_line = 0

        self._collected_lang_string: dict[str, str] = {}
        self._collected_pos_marker: Optional[SsbOpParamPositionMarker] = None

        self._collected_labels: dict[str, SsbLabel] = {}
        self._label_increment_id = -1
        self._turn_next_op_into_label_jump_for: Optional[SsbLabel] = None
        self._labels_before_op: list[SsbLabel] = []

        self._total_number_collected_ops = -1
        self._collected_ops: list[SsbOperation] = []
        self._active_routine_id = -1
        self._collected_params: list[SsbOpParam] = []

    def exitSimple_def(self, ctx: SsbScriptParser.Simple_defContext):
        self._active_routine_id = exps_int(str(ctx.INTEGER()))
        self._enlarge_routine_info()
        self.routine_infos[self._active_routine_id] = SsbRoutineInfo(SsbRoutineType.GENERIC, 0)
        self.routine_ops[self._active_routine_id] = self._collected_ops
        self._collected_ops = []

    def exitCoro_def(self, ctx: SsbScriptParser.Coro_defContext):
        self._active_routine_id += 1
        self._enlarge_routine_info()
        self.named_coroutines[self._active_routine_id] = str(ctx.IDENTIFIER())
        self.routine_infos[self._active_routine_id] = SsbRoutineInfo(SsbRoutineType.COROUTINE, 0)
        self.routine_ops[self._active_routine_id] = self._collected_ops
        self._collected_ops = []

    def exitFor_target_def(self, ctx: SsbScriptParser.For_target_defContext):
        self._active_routine_id = exps_int(str(ctx.INTEGER()))
        self._enlarge_routine_info()
        linked_to = -1
        linked_to_name = None
        integer_like = str(ctx.integer_like().children[0])
        try:
            linked_to = exps_int(integer_like)
        except:
            linked_to_name = integer_like

        if str(ctx.FOR_TARGET()) == 'for_actor':
            self.routine_infos[self._active_routine_id] = SsbRoutineInfo(SsbRoutineType.ACTOR, linked_to, linked_to_name)
        elif str(ctx.FOR_TARGET()) == 'for_object':
            self.routine_infos[self._active_routine_id] = SsbRoutineInfo(SsbRoutineType.OBJECT, linked_to, linked_to_name)
        else:
            self.routine_infos[self._active_routine_id] = SsbRoutineInfo(SsbRoutineType.PERFORMER, linked_to, linked_to_name)
        self.routine_ops[self._active_routine_id] = self._collected_ops
        self._collected_ops = []

    def exitOperation(self, ctx: SsbScriptParser.OperationContext):
        op_code_name = str(ctx.IDENTIFIER())

        collected_params = self._collected_params
        self._collected_params = []

        self._total_number_collected_ops += 1
        root_op = SsbOperation(
            self._total_number_collected_ops,
            SsbOpCode(-1, op_code_name),
            collected_params
        )
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
            self._total_number_collected_ops, ctx.start.line - 1, ctx.start.column
        )

        # Add position marker to source map
        if ctx.start.line != self._last_op_line:
            self._last_op_line = ctx.start.line
            self._op_idx_in_current_line = 0
        else:
            self._op_idx_in_current_line += 1
        for i, arg in enumerate(collected_params):
            if isinstance(arg, SsbOpParamPositionMarker):
                self.source_map_builder.add_position_mark(SourceMapPositionMark(
                    # Antlr line ids are 1-indexed.
                    ctx.start.line - 1, ctx.start.column,
                    ctx.stop.line - 1, ctx.stop.column,
                    arg.name, arg.x_offset, arg.y_offset,
                    arg.x_relative, arg.y_relative
                ))

        self._collected_pos_marker_for_current_op = []

    def enterPos_argument(self, ctx: SsbScriptParser.Pos_argumentContext):
        self._is_processing_argument = True

    def exitPos_argument(self, ctx: SsbScriptParser.Pos_argumentContext):
        self._is_processing_argument = False
        self._turn_next_op_into_label_jump_for = None
        if self._argument_type == ListenerArgType.JUMP:
            label_name = self._argument_value
            if label_name in self._collected_labels:
                label = self._collected_labels[label_name]
            else:
                self._label_increment_id += 1
                label = SsbLabel(
                    self._label_increment_id, -1  # todo: routine id is not set yet, but not used anyway.
                )
                self._collected_labels[label_name] = label
            self._turn_next_op_into_label_jump_for = label
        elif self._argument_type == ListenerArgType.STRING_LITERAL:
            self._collected_params.append(SsbOpParamConstString(self._argument_value))
        elif self._argument_type == ListenerArgType.LANGUAGE_STRING:
            self._collected_params.append(SsbOpParamLanguageString(self._argument_value))
        elif self._argument_type == ListenerArgType.INTEGER:
            self._collected_params.append(self._argument_value)
        elif self._argument_type == ListenerArgType.CONSTANT:
            self._collected_params.append(SsbOpParamConstant(self._argument_value))
        elif self._argument_type == ListenerArgType.POSITION_MARKER:
            self._collected_params.append(self._collected_pos_marker)

    def enterPosition_marker(self, ctx: SsbScriptParser.Position_markerContext):
        if self._is_processing_argument:
            self._collected_pos_marker = SsbOpParamPositionMarker('NOT SET', -1, -1, -1, -1)

    def exitPosition_marker(self, ctx: SsbScriptParser.Position_markerContext):
        if self._is_processing_argument:
            self._collected_pos_marker.name = string_literal(ctx.STRING_LITERAL())

    def exitPosition_marker_arg(self, ctx: SsbScriptParser.Position_marker_argContext):
        if self._is_processing_argument:
            self._argument_type = ListenerArgType.POSITION_MARKER
            relative = exps_int(str(ctx.INTEGER()))
            point_five = ctx.POINT_FIVE()
            offset = 0
            if point_five:
                offset = 2
            if self._collected_pos_marker.x_offset == -1:
                # We collected the x argument
                self._collected_pos_marker.x_offset = offset
                self._collected_pos_marker.x_relative = relative
            else:
                # We collected the y argument
                self._collected_pos_marker.y_offset = offset
                self._collected_pos_marker.y_relative = relative

    def exitInteger_like(self, ctx: SsbScriptParser.Integer_likeContext):
        if self._is_processing_argument:
            if ctx.INTEGER():
                self._argument_type = ListenerArgType.INTEGER
                self._argument_value = exps_int(str(ctx.INTEGER()))
            elif ctx.IDENTIFIER():
                self._argument_type = ListenerArgType.CONSTANT
                self._argument_value = str(ctx.IDENTIFIER())

    def exitJump_marker(self, ctx: SsbScriptParser.Jump_markerContext):
        if self._is_processing_argument:
            self._argument_type = ListenerArgType.JUMP
            self._argument_value = str(ctx.IDENTIFIER())

    def exitString(self, ctx: SsbScriptParser.StringContext):
        if self._is_processing_argument:
            string = ctx.STRING_LITERAL()
            if string:
                self._argument_type = ListenerArgType.STRING_LITERAL
                self._argument_value = string_literal(string)
            else:
                # Process the collected lang string
                self._argument_type = ListenerArgType.LANGUAGE_STRING
                self._argument_value = self._collected_lang_string

    def enterLang_string(self, ctx: SsbScriptParser.Lang_stringContext):
        self._collected_lang_string = {}

    def exitLang_string_argument(self, ctx: SsbScriptParser.Lang_string_argumentContext):
        self._collected_lang_string[str(ctx.IDENTIFIER())] = string_literal(ctx.STRING_LITERAL())

    def exitLabel(self, ctx: SsbScriptParser.LabelContext):
        label_name = str(ctx.IDENTIFIER())
        
        if label_name in self._collected_labels:
            label = self._collected_labels[label_name]
        else:
            self._label_increment_id += 1
            label = SsbLabel(
                self._label_increment_id, -1  # todo: routine id is not set yet, but not used anyway.
            )
            self._collected_labels[label_name] = label

        self._collected_ops.append(label)

        # Set this, so that the next operation can set the offset to this pos.
        # This is a list, because in theory there can be multiple labels right next to each other, pointing
        # to the same op.
        self._labels_before_op.append(label)

    def _enlarge_routine_info(self):
        if len(self.routine_infos) - 1 < self._active_routine_id:
            needed = self._active_routine_id - len(self.routine_infos) + 1
            for i in range(0, needed):
                self.routine_infos.append(None)
                self.routine_ops.append([])
                self.named_coroutines.append([])
