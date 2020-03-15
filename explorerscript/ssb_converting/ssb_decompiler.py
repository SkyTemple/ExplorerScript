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
import warnings
from typing import Optional, Tuple

from igraph._igraph import Vertex, Edge

from explorerscript.ssb_converting.decompiler.graph_utils import iterate_switch_edges_using_edges_and_op
from explorerscript.ssb_converting.decompiler.label_jump_to_resolver import OpsLabelJumpToResolver
from explorerscript.ssb_converting.ssb_special_ops import *
from explorerscript.ssb_converting.decompiler.graph_minimizer import SsbGraphMinimizer
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineType, SsbCoroutine, SsbRoutineInfo, SsbOpParam, \
    SsbOperation, NUMBER_OF_SPACES_PER_INDENT


# Special markings for decompiler
ENDED_ON_FALLTHROUGH = 'EOFALL'


class SsbDecompiler:

    def __init__(self, routine_infos: List[SsbRoutineInfo], routine_ops: List[List[SsbOperation]], named_coroutines: List[SsbCoroutine]):
        self._routine_infos = routine_infos
        self._routine_ops = routine_ops
        self._named_coroutines: Dict[int, str] = {x.id: x.name for x in named_coroutines}
        self._output = ""
        self._indent = 0
        self._labels_already_printed = []

        self._op_handlers = {
            SsbLabel: self._handle_op__label,
            SsbForeignLabel: self._handle_op__foreign_label,
            SsbLabelJump: self._handle_op__label_jump,
            SsbOperation: self._handle_op__simple_op,
            type(None): self._handle_op__end_of_branch
        }

        # Some ssb operations may not have special graph nodes,
        # but we still process them special
        self._ssb_operations_special_cases_handlers = {
            None: self._handle_op__simple_op__simple
        }
        for x in OPS_THAT_END_CONTROL_FLOW:
            self._ssb_operations_special_cases_handlers[x] = self._handle_op__simple_op__keyword
        for x in OPS_CTX:
            self._ssb_operations_special_cases_handlers[x] = self._handle_op__simple_op__ctx

        # There can be multiple or none label markers.
        self._label_marker_handlers = {
            IfEnd: self._handle_op__label__if_end,
            SwitchEnd: self._handle_op__label__switch_end,
            SwitchFalltrough: self._handle_op__label__switch_fallthrough,
            ForeverStart: self._handle_op__label__forever_start,
            ForeverEnd: self._handle_op__label__forever_end
        }

        self._label_jump_marker_handlers = {
            MultiIfStart: self._handle_op__label_jump__if_start,
            IfStart: self._handle_op__label_jump__if_start,
            MultiSwitchStart: self._handle_op__label_jump__switch_start,
            SwitchStart: self._handle_op__label_jump__switch_start,
            ForeverContinue: self._handle_op__label_jump__forever_continue,
            ForeverBreak: self._handle_op__label_jump__forever_break,
            type(None): self._handle_op__label_jump__raw,
        }

    def convert(self) -> str:
        self._output = ""
        self._indent = 0
        self._labels_already_printed = []

        # Step 1: Build labels
        resolver = OpsLabelJumpToResolver(self._routine_ops)
        self._routine_ops = list(resolver)

        # Step 2: Build and optimize execution graph
        grapher = SsbGraphMinimizer(self._routine_ops)
        control_flow_before_minimize = grapher.get_control_flow()
        # Remove redundant labels
        grapher.optimize_paths()
        # Build groups switch+cases, switch groups, branch-groups
        # get rid of as many label references (jumps) as possible
        grapher.build_branches()
        grapher.group_branches()
        grapher.build_and_group_switch_cases()
        grapher.group_switches()
        grapher.group_switch_cases()
        grapher.build_switch_fallthroughs()
        # Process loops
        grapher.build_loops()
        # Remove all labels that are no longer needed, because they are only referenced from one place or implicit
        # control flow
        grapher.remove_label_markers()

        # We can now just go through the graph and build the result.

        # Of course our changes must not affect the actual control flow
        assert control_flow_before_minimize == grapher.get_control_flow()

        for r_id, (r_info, r_graph) in enumerate(zip(self._routine_infos, grapher.get_graphs())):
            self._write_routine_header(r_id, r_info)
            with _Blk(self):
                if len(r_graph.vs) == 0:
                    # TODO
                    #raise ValueError(f"Empty routines are currently not supported ({r_id}, {r_info})")
                    self._write_stmnt("not supported")
                    continue
                self._handle_vertex(r_graph.vs[0], None, [], [], [])
            self._write_line()
        return self._output

    def _write_routine_header(self, r_id, r_info):
        if r_info.type == SsbRoutineType.COROUTINE:
            if r_id in self._named_coroutines:
                self._write_stmnt(f"coro {self._named_coroutines[r_id]}:")
            else:
                raise ValueError(f"Unknown coroutine for: {r_id}, {r_info}")
        elif r_info.type == SsbRoutineType.ACTOR:
            self._write_stmnt(f"def {r_id} for actor({r_info.linked_to}):")
        elif r_info.type == SsbRoutineType.OBJECT:
            self._write_stmnt(f"def {r_id} for object({r_info.linked_to}):")
        elif r_info.type == SsbRoutineType.PERFORMER:
            self._write_stmnt(f"def {r_id} for performer({r_info.linked_to}):")
        elif r_info.type == SsbRoutineType.GENERIC:
            self._write_stmnt(f"def {r_id}:")
        else:
            raise ValueError(f"Unknown routine type for: {r_id}, {r_info}")

    def _handle_vertex(self, v: Optional[Vertex], previous_op: Optional[SsbOperation],
                       open_ifs: List[int], open_switches: List[int], open_loops: List[int]) -> Tuple[int, List[Edge], tuple]:
        """Handle a single vertex, proxies to _handle_op"""
        return self._handle_op(
            v['op'] if v else None, v.out_edges() if v is not None else [], previous_op, open_ifs, open_switches, open_loops
        )

    def _handle_op(self, op: Optional[SsbOperation], exits: List[Edge], previous_op: Optional[SsbOperation],
                   open_ifs: List[int], open_switches: List[int], open_loops: List[int]) -> Tuple[int, List[Edge], tuple]:
        """Handle a single operation, returns number of operations printed by this (because of branching code, etc.)"""
        handler = self._op_handlers[SsbOperation]
        if type(op) in self._op_handlers:
            handler = self._op_handlers[type(op)]
        return handler(
            op=op,
            exits=exits,
            previous_op=previous_op,
            open_ifs=open_ifs,
            open_switches=open_switches,
            open_loops=open_loops
        )

    def _handle_op__label(self, op: SsbLabel, previous_op: Optional[SsbOperation], exits: List[Edge], **kwargs) -> Tuple[int, List[Edge], tuple]:
        ops_written = 0
        # EXCEPTION for Switch Fallthrough. This has to be checked first.
        # Only if the previous statement is NOT a switch. If it is, then this is actually the actual branch
        # for this switch case
        if any(isinstance(m, SwitchFalltrough) for m in op.markers) and len(kwargs['open_switches']) > 0 and not self._is_switch_start(previous_op):
            if op.needs_to_be_printed() and op.id not in self._labels_already_printed:
                self._write_label(op)
                self._labels_already_printed.append(op.id)
                ops_written += 1
            return ops_written, [], {ENDED_ON_FALLTHROUGH}
        # Okay! A label! Let's check if we need to print it
        may_have_to_write_jump = False
        if op.id in self._labels_already_printed:
            may_have_to_write_jump = True
        elif op.needs_to_be_printed():
            self._write_label(op)
            self._labels_already_printed.append(op.id)
            ops_written += 1
        # And now let's hand it off to our marker handlers
        should_end_control_flow = False
        should_start_block = False
        for m in op.markers:
            if type(m) in self._label_marker_handlers:
                l_should_end_control_flow, l_should_start_block = self._label_marker_handlers[type(m)](op=op, m=m, exits=exits, **kwargs)
                if l_should_end_control_flow:
                    should_end_control_flow = True
                if l_should_start_block:
                    should_start_block = True
            else:
                raise ValueError(f"Unknown label marker type ({type(m)}) for {op}: {m}")
        if should_end_control_flow:
            # This label ends the control flow on this indentation level, it resumes one level above.
            return ops_written, exits, tuple()
        elif may_have_to_write_jump:
            # We are at the end, since we already printed this entire branch somewhere else.
            return self._write_label_jump(op.id, previous_op), [], tuple()
        else:
            # This label continues control flow on this indentation level
            if len(exits) == 1:
                next_vertex = exits[0].target_vertex
            elif len(exits) == 0:
                next_vertex = None
            else:
                raise ValueError(f"After a label there must be exactly 0 or 1 immediate opcode.")
            if should_start_block:
                with _Blk(self):
                    ops_written += 1
                    r = self._handle_vertex(next_vertex, previous_op=op, **kwargs)
            else:
                r = self._handle_vertex(next_vertex, previous_op=op, **kwargs)
            return ops_written + r[0], r[1], r[2]

    def _handle_op__foreign_label(self, op: SsbForeignLabel, previous_op: SsbOperation, exits: List[Edge], **kwargs) -> Tuple[int, List[Edge], tuple]:
        # We definitely need to print that
        assert len(exits) == 0
        return self._write_label_jump(op.label, previous_op), exits, tuple()

    def _handle_op__label_jump(self, op: SsbLabelJump, **kwargs) -> Tuple[int, List[Edge], tuple]:
        m = op.get_marker()
        if type(m) in self._label_jump_marker_handlers:
            return self._label_jump_marker_handlers[type(m)](op=op, m=m, **kwargs)
        else:
            raise ValueError(f"Unknown label marker type ({type(m)}) for {op}: {m}")

    def _handle_op__simple_op(self, op: SsbOperation, **kwargs) -> Tuple[int, List[Edge], tuple]:
        handler = self._ssb_operations_special_cases_handlers[None]
        for h_types, h in self._ssb_operations_special_cases_handlers.items():
            if op.op_code.name == h_types:
                handler = h
        return handler(op, **kwargs)

    def _handle_op__end_of_branch(self, op: None, previous_op: Optional[SsbOperation], **kwargs) -> Tuple[int, List[Edge], tuple]:
        if previous_op is None:
            # ???
            raise ValueError("Found end of branch, but no previous op...?")
        if previous_op.op_code.name not in OPS_THAT_END_CONTROL_FLOW:
            # All branches must end with something that ends their control flow
            warnings.warn(f"Had to insert a return after {previous_op}, because it was last in branch.")
            self._write_return()
            return 1, [], tuple()
        return 0, [], tuple()

    def _handle_op__simple_op__keyword(self, op: SsbOperation, exits: List[Edge], previous_op, **kwargs) -> Tuple[int, List[Edge], tuple]:
        if op.op_code.name == OP_RETURN:
            self._write_return()
        elif op.op_code.name == OP_END:
            self._write_end()
        elif op.op_code.name == OP_HOLD:
            self._write_hold()
        else:
            raise ValueError(f"Unknown keyword opcode: {op}")
        if len(exits) == 1:
            next_vertex = exits[0].target_vertex
        elif len(exits) == 0:
            next_vertex = None
        else:
            raise ValueError(f"After a simple opcode there must be exactly 0 or 1 immediate opcode.")
        r = self._handle_vertex(next_vertex, previous_op=op, **kwargs)
        return 1 + r[0], r[1], r[2]

    def _handle_op__simple_op__ctx(self, op: SsbOperation, exits: List[Edge], previous_op, **kwargs) -> Tuple[int, List[Edge], tuple]:
        params = op.params
        if isinstance(params, dict):
            params = list(params.values())
        if len(params) != 1:
            raise ValueError(f"Error reading operation for {op.op_code.name} ({op}). Must have exactly one argument.")
        if op.op_code.name == OPS_CTX_LIVES:
            self._write_stmnt(f"with actor {params[0]}:")
        elif op.op_code.name == OPS_CTX_OBJECT:
            self._write_stmnt(f"with object {params[0]}:")
        elif op.op_code.name == OPS_CTX_PERFORMER:
            self._write_stmnt(f"with performer {params[0]}:")
        else:
            raise ValueError(f"Unknown ctx opcode: {op}")

        assert len(exits) == 1, "After a lives/object/performer op, there must be exactly one op following."
        # Read the context opcode.
        with _Blk(self):
            len_of_blk, exits_after_ctx, extra_tpl = self._handle_op__simple_op__simple(
                exits[0].target_vertex['op'], exits=exits[0].target_vertex.out_edges(),
                previous_op=op, single_op=True, **kwargs
            )
            if len_of_blk != 1:
                raise ValueError(f"lives/performer/object blocks must contain opcodes that don't start any "
                                 f"branching code. Child of {op} generated {len_of_blk}")

        if len(exits_after_ctx) == 1:
            next_vertex = exits_after_ctx[0].target_vertex
        elif len(exits_after_ctx) == 0:
            next_vertex = None
        else:
            raise ValueError(f"After a simple opcode there must be exactly 0 or 1 immediate opcode.")
        r = self._handle_vertex(next_vertex, previous_op=op, **kwargs)
        return 2 + r[0], r[1], r[2]

    def _handle_op__simple_op__simple(self, op: SsbOperation, exits: List[Edge], previous_op, single_op=False, **kwargs) -> Tuple[int, List[Edge], tuple]:
        if isinstance(op.params, list):
            # Ordered arguments
            params = ", ".join(
                [self._single_param_to_string(param) for param in op.params]
            ).rstrip(", ")
        elif isinstance(op.params, dict):
            # Named arguments
            params = ", ".join(
                [self._single_param_to_string(param, param_name) for param_name, param in op.params.items()]
            ).rstrip(", ")
        else:
            raise ValueError(f"Invalid argument list type for {op}: {op.params.__class__.__name__}")
        self._write_stmnt(f"{op.op_code.name}({params})")
        if single_op:
            return 1, exits, tuple()
        if len(exits) == 1:
            next_vertex = exits[0].target_vertex
        elif len(exits) == 0:
            next_vertex = None
        else:
            raise ValueError(f"After a simple opcode there must be exactly 0 or 1 immediate opcode.")
        r = self._handle_vertex(next_vertex, previous_op=op, **kwargs)
        return 1 + r[0], r[1], r[2]

    def _handle_op__label__if_end(self, m: IfEnd, open_ifs: List[Edge], **kwargs) -> Tuple[bool, bool]:
        # These checks are actually not valid, because we might come from somewhere entirely different...
        #if m.if_id in open_ifs[:-1]:
        #    raise UnmatchedBranchError(f"Found closing if for id {m.if_id}, but expected to close if {open_ifs[-1]} first.")

        # End an if, if it's the last one opened at this path
        ok = len(open_ifs) > 0 and open_ifs[-1] == m.if_id
        if ok:
            open_ifs.pop()
        return ok, False

    def _handle_op__label__switch_end(self, m: SwitchEnd, open_switches: List[Edge], **kwargs) -> Tuple[bool, bool]:
        #if m.switch_id in open_switches[:-1]:
        #    raise ValueError(f"Found closing switch for id {m.switch_id}, but expected to close switch {open_switches[-1]} first.")

        ok = len(open_switches) > 0 and open_switches[-1] == m.switch_id
        if ok:
            open_switches.pop()
        return ok, False

    def _handle_op__label__switch_fallthrough(self, **kwargs) -> Tuple[bool, bool]:
        # This is checked separately!
        return False, False

    def _handle_op__label__forever_start(self, m: ForeverStart, open_loops: List[Edge], **kwargs) -> Tuple[bool, bool]:
        open_loops.append(m.loop_id)
        self._write_stmnt("forever:")
        return False, True

    def _handle_op__label__forever_end(self, m: ForeverStart, open_loops: List[Edge], **kwargs) -> Tuple[bool, bool]:
        #if m.loop_id in open_loops[:-1]:
        #    raise ValueError(f"Found closing loop for id {m.loop_id}, but expected to close loop {open_loops[-1]} first.")

        ok = len(open_loops) > 0 and open_loops[-1] == m.loop_id
        if ok:
            open_loops.pop()
        return ok, False

    def _handle_op__label_jump__if_start(
            self, op: SsbLabelJump, m: IfStart, exits: List[Edge], previous_op, open_ifs, **kwargs
    ) -> Tuple[int, List[Edge], tuple]:
        open_ifs_orig = open_ifs.copy()
        open_ifs.append(m.if_id)
        if isinstance(m, MultiIfStart):
            list_of_clauses = [self._if_header_for(s) for s in m.original_ssb_ifs_ops]
        else:
            list_of_clauses = [self._if_header_for(op)]
        self._write_stmnt(f"if {' or '.join(list_of_clauses)}:")
        else_edge = [e for e in exits if e['is_else']][0]
        if_edge = [e for e in exits if not e['is_else']][0]
        if else_edge == if_edge:
            # Great if!
            with _Blk(self):
                self._write_pass()
                r = self._handle_vertex(else_edge.target_vertex, open_ifs=open_ifs_orig, previous_op=op, **kwargs)
            return 2 + r[0], r[1], r[2]
        else:
            with _Blk(self):
                count_if, if_end, _ = self._handle_vertex(if_edge.target_vertex, open_ifs=open_ifs.copy(), previous_op=op, **kwargs)
                if count_if == 0:
                    self._write_pass()
            else_ends_on_common_vtx = True
            count_else = 0
            if not (isinstance(else_edge.target_vertex['op'], SsbLabel) and any(isinstance(mx, IfEnd) and m.if_id == mx.if_id for mx in else_edge.target_vertex['op'].markers)):
                else_ends_on_common_vtx = False
                self._write_stmnt(f"else:")
                with _Blk(self):
                    count_else, else_end, _ = self._handle_vertex(else_edge.target_vertex, open_ifs=open_ifs.copy(), previous_op=op, **kwargs)
                    if count_else == 0:
                        self._write_pass()
            if (else_ends_on_common_vtx and len(if_end) > 0) or (len(if_end) > 0 and len(else_end) > 0 and if_end[0].source == else_end[0].source):
                # End on the same end vertex, continue after.
                r = self._handle_vertex(if_end[0].target_vertex, open_ifs=open_ifs_orig, previous_op=op, **kwargs)
                return 2 + count_if + count_else + r[0], r[1], r[2]
            return 2 + count_if + count_else, [], tuple()

    def _handle_op__label_jump__switch_start(
            self, op: SsbLabelJump, m: SwitchStart, exits: List[Edge], previous_op, open_switches, **kwargs
    ) -> Tuple[int, List[Edge], tuple]:
        open_switches_orig = open_switches.copy()
        open_switches.append(m.switch_id)
        multi = isinstance(m, MultiSwitchStart)
        if multi:
            self._write_stmnt(f"multi switch ({', '.join([self._switch_header_for(s) for s in m.original_ssb_switch_ops])}):")
        else:
            self._write_stmnt(f"switch {self._switch_header_for(op)}:")
        # All switch end vertices we encounter are collected here, if this is exactly one entry long, we have a common
        # end.
        ops_written = 1
        switch_end_vertices = set()
        if len(exits) == 1:
            # Not a real switch:
            with _Blk(self):
                ops_written += 1
                self._write_pass()
            r = self._handle_vertex(exits[0].target_vertex, open_switches=open_switches_orig, previous_op=op, **kwargs)
            return ops_written + r[0], r[1], r[2]
        elif len(exits) > 1:
            for e, switch_case_ops in iterate_switch_edges_using_edges_and_op(exits, op):
                with _Blk(self):
                    for sco in switch_case_ops:
                        ops_written += 1
                        if multi:
                            self._write_stmnt(f"case {sco.switch_index}, {self._case_header_for(sco.op)}:")
                        else:
                            self._write_stmnt(f"case {self._case_header_for(sco.op)}:")
                    with _Blk(self):
                        if isinstance(e.target_vertex['op'], SsbLabelJump) and any(isinstance(mx, SwitchEnd) and mx.switch_id == m.switch_id for mx in e.target_vertex['op'].markers):
                            # cool case.
                            self._write_pass()
                        else:
                            count_case, case_end, markings = self._handle_vertex(e.target_vertex, open_switches=open_switches.copy(), previous_op=op, **kwargs)
                            if ENDED_ON_FALLTHROUGH not in markings:
                                self._write_stmnt("break")
                                ops_written += 1
                            ops_written += count_case
                            switch_end_vertices.update([e.source_vertex for e in case_end])
                            if count_case == 0:
                                self._write_pass()
            if len(switch_end_vertices) == 1:
                # End on the same end vertex, continue after.
                out_edges = switch_end_vertices.pop().out_edges()
                assert len(out_edges) == 1
                r = self._handle_vertex(out_edges[0].target_vertex, open_switches=open_switches_orig, previous_op=op, **kwargs)
                return ops_written + r[0], r[1], r[2]
        return ops_written, [], tuple()

    def _handle_op__label_jump__forever_continue(
            self, **kwargs
    ) -> Tuple[int, List[Edge], tuple]:
        # Print a continue and end.
        # TODO: Remove implicit continues
        self._write_stmnt("continue  # this may be redundant if it's the last statement in loop.")
        return 1, [], tuple()

    def _handle_op__label_jump__forever_break(
            self, **kwargs
    ) -> Tuple[int, List[Edge], tuple]:
        # Print a break and end.
        self._write_stmnt("break")
        return 1, [], tuple()

    def _handle_op__label_jump__raw(
            self, m: None, op: SsbLabelJump, exits: List[Edge], previous_op, **kwargs
    ) -> Tuple[int, List[Edge], tuple]:
        # Nothing to do, this is dealt with, when processing the label after this
        # either we print a jump there, or we just proceed.
        assert len(exits) == 1, "A jump must have exactly one point to jump to"
        return self._handle_vertex(exits[0].target_vertex, previous_op=op, **kwargs)

    def _single_param_to_string(self, param: SsbOpParam, param_name=None):
        if hasattr(param, 'indent'):
            param.indent = self._indent
        if param_name is not None:
            return f"{param_name}={str(param)}"
        return str(param)

    def _write_stmnt(self, stmnt):
        """Write a simple single line statement"""
        self._output += " " * (self._indent * NUMBER_OF_SPACES_PER_INDENT)
        self._output += stmnt
        self._write_line()

    def _write_line(self):
        self._output += "\n"

    @staticmethod
    def _is_switch_start(op: SsbOperation):
        return isinstance(op, SsbLabel) and any(isinstance(m, SwitchStart) for m in op.markers)

    def _write_label(self, op: SsbLabel):
        self._write_stmnt(f'$label_{op.id}')

    def _write_label_jump(self, label_id: int, previous_op: SsbOperation) -> int:
        # Depending on what the previous operation was, this has to be printed differently
        if not isinstance(previous_op, SsbLabelJump):
            # We need a jump now. We didn't have one but now we will.
            self._write_stmnt(f"jump @label_{label_id}")
            return 1
        elif previous_op.get_marker() is None:
            # Normal jump, just print that
            self._write_stmnt(f"jump @label_{label_id}")
            return 1
        elif isinstance(previous_op.get_marker(), ForeverContinue) or isinstance(previous_op.get_marker(), ForeverBreak):
            # Loop continue/break
            # Do nothing
            return 0
        else:
            # Jump as part of a control structure
            self._write_stmnt(f"@label_{label_id}")
            return 1

    def _write_return(self):
        self._write_stmnt("return")

    def _write_end(self):
        self._write_stmnt("end")

    def _write_hold(self):
        self._write_stmnt("hold")

    def _write_pass(self):
        self._write_stmnt("pass")

    def _if_header_for(self, s: SsbLabelJump) -> str:
        # todo
        return "todo"

    def _switch_header_for(self, s: SsbOperation) -> str:
        # todo
        return "todo"

    def _case_header_for(self, s: SsbOperation) -> str:
        # todo
        return "todo"


# noinspection PyProtectedMember
class _Blk(object):
    def __init__(self, reader):
        self.reader = reader

    def __enter__(self):
        self.reader._indent += 1

    def __exit__(self, exc_type, exc_value, exc_traceback):
        self.reader._indent -= 1
