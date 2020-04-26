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

from igraph import Vertex

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.block import BlockWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.label import LabelWriteHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import IfStart, SsbLabelJump, MultiIfStart, SsbLabel, IfEnd
from explorerscript.ssb_converting.util import Blk
from explorerscript.ssb_converting.ssb_data_types import SsbOperator


class IfWriteHandler(AbstractWriteHandler):
    """Handles writing ifs."""

    def __init__(self, start_vertex: Vertex, decompiler, parent):
        super().__init__(start_vertex, decompiler, parent)
        self.ended_on_jump = True

    def write_content(self):
        op: SsbLabelJump = self.start_vertex['op']
        m: IfStart = op.get_marker()
        # TODO: Detection of if ends for multi ifs, see EVENT_HA_YU_SHU_DO
        if isinstance(m, MultiIfStart):
            list_of_clauses = [self._if_header_for(s, is_not) for s, is_not in zip(m.original_ssb_ifs_ops, m.original_ssb_ifs_is_not)]
        else:
            list_of_clauses = [self._if_header_for(op.root, op.get_marker().is_not)]

        exits = self.start_vertex.out_edges()

        self.decompiler.source_map_add_opcode(op.offset)
        self.decompiler.write_stmnt(f"if ({' or '.join(list_of_clauses)})")
        else_edge = [e for e in exits if e['is_else']][0]
        if_edge = [e for e in exits if not e['is_else']][0]

        if else_edge == if_edge:
            # Great if!
            with Blk(self.decompiler):
                pass
            return else_edge.target_vertex
        else:
            with Blk(self.decompiler):
                # Handle if-branch
                if_branch_handler = BlockWriteHandler(
                    if_edge.target_vertex, self.decompiler, self, self.start_vertex,
                    check_end_block=self.check_end_block
                )
                v_after_if_branch = if_branch_handler.write_content()
            else_ends_on_common_vtx = True
            v_after_else_branch = None
            if not (isinstance(else_edge.target_vertex['op'], SsbLabel) and any(isinstance(mx, IfEnd) and m.if_id == mx.if_id for mx in else_edge.target_vertex['op'].markers)):
                else_ends_on_common_vtx = False
                self.decompiler.write_stmnt(" else", False)
                with Blk(self.decompiler):
                    # Handle else-branch
                    else_branch_handler = BlockWriteHandler(
                        else_edge.target_vertex, self.decompiler, self, self.start_vertex,
                        check_end_block=self.check_end_block
                    )
                    v_after_else_branch = else_branch_handler.write_content()

            # Those must be the same, either None or a common vertex
            # ... or either of them must end on a jump, then it's also okay if one of them is None but the other not.
            assert else_ends_on_common_vtx or \
                   if_branch_handler.last_handler_in_block.ended_on_jump or \
                   else_branch_handler.last_handler_in_block.ended_on_jump or \
                   v_after_if_branch == v_after_else_branch, f"Invalid if-structure for if {m.if_id}"

            if v_after_if_branch is None:
                return v_after_else_branch
            return v_after_if_branch

    def check_end_block(self, block: BlockWriteHandler, next_handler: AbstractWriteHandler):
        """
        An if should end either if there are no vertices left (duh!) or if the end-if label is reached.
        This method also makes logical checks: No other if or switch or loop may be ended directly in this sub-block.
        """
        if isinstance(next_handler, LabelWriteHandler):
            lwh = next_handler

            if len(lwh.ended_ifs) > 1:
                if self.start_vertex['op'].get_marker().if_id in lwh.ended_ifs:
                    return False
                #else:
                #    raise ValueError("An unexpected if was ended while waiting for if to end.")

            #if len(lwh.ended_loops) > 0 or len(lwh.ended_switches) > 0:
            #    raise ValueError("An invalid switch or loop was ended while waiting for an if end.")
        return True

    @classmethod
    def _if_header_for(cls, op: SsbOperation, is_not):
        if is_not:
            # Remove double nots (see RESCUE_DEBUG)
            return f'not {cls._if_header_for_impl(op)}'.lstrip('not not ')
        return cls._if_header_for_impl(op)

    @staticmethod
    def _if_header_for_impl(op: SsbOperation):
        # TODO: More error checking for parameters would probably be a good idea
        if op.op_code.name == 'Branch':
            return f'{op.params[0]} {SsbOperator.EQ.notation} {op.params[1]}'
        if op.op_code.name == 'BranchBit':
            return f'{op.params[0]}[{op.params[1]}]'
        if op.op_code.name == 'BranchDebug':
            if op.params[0] > 0:
                return 'debug'
            else:
                return 'not debug'
        if op.op_code.name == 'BranchEdit':
            if op.params[0] > 0:
                return 'edit'
            else:
                return 'not edit'
        if op.op_code.name == 'BranchExecuteSub':
            return f'BranchExecuteSub({", ".join([str(x) for x in op.params])})'
        if op.op_code.name == 'BranchPerformance':
            return f'BranchPerformance({", ".join([str(x) for x in op.params])})'
        if op.op_code.name == 'BranchScenarioNow':
            return f'scn {op.params[0]}[== {op.params[1]}, == {op.params[2]}]'
        if op.op_code.name == 'BranchScenarioNowAfter':
            return f'scn {op.params[0]}[== {op.params[1]}, >= {op.params[2]}]'
        if op.op_code.name == 'BranchScenarioNowBefore':
            return f'scn {op.params[0]}[== {op.params[1]}, <= {op.params[2]}]'
        if op.op_code.name == 'BranchScenarioAfter':
            return f'scn {op.params[0]}[== {op.params[1]}, > {op.params[2]}]'
        if op.op_code.name == 'BranchScenarioBefore':
            return f'scn {op.params[0]}[== {op.params[1]}, < {op.params[2]}]'
        if op.op_code.name == 'BranchSum':
            return f'BranchSum({", ".join([str(x) for x in op.params])})'
        if op.op_code.name == 'BranchValue':
            return f'{op.params[0]} {SsbOperator(op.params[1]).notation} {op.params[2]}'
        if op.op_code.name == 'BranchVariable':
            return f'{op.params[0]} {SsbOperator(op.params[1]).notation} value({op.params[2]})'
        if op.op_code.name == 'BranchVariation':
            if op.params[0] > 0:
                return 'variation'
            else:
                return 'not variation'
        raise ValueError(f"Unknown if-operation {op.op_code.name}")
