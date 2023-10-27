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
import logging
from typing import Tuple

from explorerscript.source_map import SourceMapBuilder, SourceMapPositionMark, SourceMap
from explorerscript.ssb_converting.decompiler.label_jump_to_resolver import OpsLabelJumpToResolver
from explorerscript.ssb_converting.decompiler.write_handlers.labels.forever_start import ForeverWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.routine import RoutineWriteHandler
from explorerscript.ssb_converting.ssb_special_ops import *
from explorerscript.ssb_converting.decompiler.graph_building.graph_minimizer import SsbGraphMinimizer
from explorerscript.ssb_converting.ssb_data_types import SsbCoroutine, SsbRoutineInfo, SsbOpParam, \
    SsbOperation, NUMBER_OF_SPACES_PER_INDENT, SsbOpParamPositionMarker, DungeonModeConstants
logger = logging.getLogger(__name__)


class ExplorerScriptSsbDecompiler:
    """
    Base class for a ExplorerScriptDecompiler. This takes the "enriched" base components of an SSB model and turns them
    into ExplorerScript. To convert an actual model into this directly,
    see skytemple_files.script.ssb.model.Ssb.to_explorerscript.
    """

    def __init__(self, routine_infos: List[SsbRoutineInfo],
                 routine_ops: List[List[SsbOperation]],
                 named_coroutines: List[SsbCoroutine], performance_progress_list_var_name: str,
                 dungeon_mode_constants: DungeonModeConstants
                 ):
        """
        performance_progress_list_var_name is the name of the constant for the variable
        PERFORMANCE_PROGRESS_LIST, it's converted into special opcodes!

        dungeon_mode_constants must be an instance of DungeonModeConstants, used for
        flag_SetDungeonMode (dungeon_mode(X) = ...).
        """
        self._routine_infos = routine_infos
        self._routine_ops = routine_ops
        self.named_coroutines: Dict[int, str] = {x.id: x.name for x in named_coroutines}
        self._output = ""
        self.indent = 0
        self._line_number = 1
        self.labels_already_printed = []
        self.smb: SourceMapBuilder = None
        self.performance_progress_list_var_name = performance_progress_list_var_name
        self.dungeon_mode_constants = dungeon_mode_constants
        # Since forever blocks break_loops do NOT have to be on the exact next level, we use a stack system instead!
        self.forever_start_handler_stack: List[ForeverWriteHandler] = []

    def convert(self) -> tuple[str, SourceMap]:
        logger.debug("Decompiling ExplorerScript...")
        self._output = ""
        self.indent = 0
        self.labels_already_printed = []
        self._line_number = 1
        self.smb = SourceMapBuilder()

        # Step 1: Build labels
        resolver = OpsLabelJumpToResolver(self._routine_ops)
        self._routine_ops = list(resolver)
        has_any_calls = any(any(isinstance(op, SsbLabelJump)
                                and any(isinstance(x, CallJump) for x in op.markers) for op in rtn)
                            for rtn in self._routine_ops)

        # Step 2: Build and optimize execution graph
        logger.debug("Building base graph...")
        # If we have any calls, we disable the optimization that stops at ending opcodes.
        grapher = SsbGraphMinimizer(self._routine_ops, not has_any_calls)
        logger.debug("Built base graph...")
        # Remove redundant labels
        grapher.optimize_paths()
        # Build groups switch+cases, switch groups, branch-groups
        # get rid of as many label references (jumps) as possible
        grapher.build_branches()
        grapher.group_branches()
        grapher.invert_branches()
        grapher.build_and_group_switch_cases()
        grapher.group_switch_cases()
        grapher.build_switch_fallthroughs()
        # Process loops
        grapher.build_loops()
        # Remove all labels that are no longer needed, because they are only referenced from one place or implicit
        # control flow
        grapher.remove_label_markers()

        # Step 3:
        # We can now just go through the graph and build the result.
        for r_id, (r_info, r_graph) in enumerate(zip(self._routine_infos, grapher.get_graphs())):
            logger.debug("Decompiling (%d, %s)...", r_id, self.named_coroutines[r_id] if r_id in self.named_coroutines else None)
            RoutineWriteHandler(self, r_id, r_info, r_graph).write_content()

        return self._output, self.smb.build()

    def write_stmnt(self, stmnt, line=True):
        """Write a simple single line statement"""
        if line:
            self.write_line()
        self._line_number += stmnt.count('\n')
        self._output += stmnt

    def write_line(self):
        self._line_number += 1
        self._output += "\n"
        self._output += " " * (self.indent * NUMBER_OF_SPACES_PER_INDENT)

    def write_return(self):
        self.write_stmnt("return;")

    def write_end(self):
        self.write_stmnt("end;")

    def write_hold(self):
        self.write_stmnt("hold;")

    def write_label_jump(self, label_id: int, previous_op: SsbOperation):
        # Depending on what the previous operation was, this has to be printed differently
        if not isinstance(previous_op, SsbLabelJump):
            # We need a jump now. We didn't have one but now we will.
            self.write_stmnt(f"jump @label_{label_id};")
        elif previous_op.get_marker() is None:
            # Normal jump, just print that
            self.write_stmnt(f"jump @label_{label_id};")
        elif isinstance(previous_op.get_marker(), ForeverContinue) or isinstance(previous_op.get_marker(), ForeverBreak):
            # Loop continue/break
            # Do nothing
            pass
        else:
            # Jump as part of a control structure
            self.write_stmnt(f"jump @label_{label_id};")

    def source_map_add_opcode(self, op_offset):
        """Has to be called BEFORE writing the opcode."""
        # TODO: Assumes that all statements start in a new line after indent.
        #       Might need this more flexible.
        self.smb.add_opcode(op_offset, self._line_number, self.indent * NUMBER_OF_SPACES_PER_INDENT)

    def source_map_add_position_mark(self, length, param: SsbOpParamPositionMarker):
        col_number = self.indent * NUMBER_OF_SPACES_PER_INDENT
        self.smb.add_position_mark(
            SourceMapPositionMark(
                line_number=self._line_number, column_number=col_number,
                end_line_number=self._line_number, end_column_number=col_number + length,
                name=param.name,
                x_offset=param.x_offset, y_offset=param.y_offset, x_relative=param.x_relative,
                y_relative=param.y_relative
            )
        )
