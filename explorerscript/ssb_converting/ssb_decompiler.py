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

from typing import List, Dict

from explorerscript.ssb_converting.decompiler.label_jump_to_resolver import OpsLabelJumpToResolver
from explorerscript.ssb_converting.decompiler.graph_minimizer import SsbGraphMinimizer
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineType, SsbCoroutine, SsbRoutineInfo, SsbOpParam, \
    SsbOperation, NUMBER_OF_SPACES_PER_INDENT


class SsbDecompiler:
    def __init__(self, routine_infos: List[SsbRoutineInfo], routine_ops: List[List[SsbOperation]], named_coroutines: List[SsbCoroutine]):
        self._routine_infos = routine_infos
        self._routine_ops = routine_ops
        self._named_coroutines: Dict[int, str] = {x.id: x.name for x in named_coroutines}
        self._output = ""
        self._indent = 0
        self._labels = []

    def convert(self) -> str:
        self._output = ""
        self._indent = 0

        # TODO: Ability to run without any filtering in pipeline except for labels
        # TODO: Compare execution graphs before and after modify of pipeline

        # Step 1: Build labels
        resolver = OpsLabelJumpToResolver(self._routine_ops)
        self._routine_ops = list(resolver)

        # Step 2: Build and optimize execution graph
        grapher = SsbGraphMinimizer(self._routine_ops)
        control_flow_before_minimize = grapher.get_control_flow()
        # Remove redundant labels
        grapher.optimize_paths()
        # Build groups from performer/object/actor pairs, switch+cases, switch groups, branch-groups
        # get rid of as many label references (jumps) as possible
        grapher.group_objs()
        grapher.build_branches()
        grapher.group_branches()
        grapher.build_and_group_switch_cases()
        grapher.group_switches()
        grapher.group_switch_cases()
        # Process loops
        grapher.build_loops()
        # Remove all labels that are no longer needed, because they are only referenced from one place or implicit
        # control flow
        grapher.remove_label_markers()

        # We can now just go through the graph and build the result.

        # Of course our changes must not affect the actual control flow
        assert control_flow_before_minimize == grapher.get_control_flow()

        for r_id, (r_info, r_ops) in enumerate(zip(self._routine_infos, self._routine_ops)):
            self._write_routine_header(r_id, r_info)
            with _Blk(self):
                if len(r_ops) == 0:
                    # TODO
                    #raise ValueError(f"Empty routines are currently not supported ({r_id}, {r_info})")
                    self._write_stmnt("not supported")
                for op in r_ops:
                    self._read_op(op)
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

    def _read_op(self, op: SsbOperation):
        # TODO!
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


# noinspection PyProtectedMember
class _Blk(object):
    def __init__(self, reader):
        self.reader = reader

    def __enter__(self):
        self.reader._indent += 1

    def __exit__(self, exc_type, exc_value, exc_traceback):
        self.reader._indent -= 1
