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
from typing import List, Dict, Tuple

from explorerscript.source_map import SourceMapBuilder, SourceMap, SourceMapPositionMark
from explorerscript.ssb_converting.decompiler.label_jump_to_resolver import OpsLabelJumpToResolver
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbOperation, SsbCoroutine, SsbRoutineType, \
    SsbOpParam, NUMBER_OF_SPACES_PER_INDENT, SsbOpParamPositionMarker
from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, SsbLabel
from explorerscript.ssb_converting.util import Blk
logger = logging.getLogger(__name__)


class SsbScriptSsbDecompiler:
    """
    Base class for a SsbDecompiler. This takes the "enriched" base components of an SSB model and turn them
    into SSBScript. To convert an actual model into this directly,
    see skytemple_files.script.ssb.model.Ssb.to_ssb_script.
    """
    def __init__(self, routine_infos: list[SsbRoutineInfo], routine_ops: list[list[SsbOperation]], named_coroutines: list[SsbCoroutine]):
        self._routine_infos = routine_infos
        self._routine_ops = routine_ops
        self._named_coroutines: dict[int, str] = {x.id: x.name for x in named_coroutines}
        self._output = ""
        self.indent = 0
        self._line_number = 1
        self._source_map_builder: SourceMapBuilder = None

    def convert(self) -> tuple[str, SourceMap]:
        logger.debug("Decompiling SSBScript...")
        self._output = ""
        self.indent = 0
        self._line_number = 1
        self._source_map_builder = SourceMapBuilder()

        # Step 1: Build labels
        resolver = OpsLabelJumpToResolver(self._routine_ops)
        self._routine_ops = list(resolver)

        for r_id, (r_info, r_ops) in enumerate(zip(self._routine_infos, self._routine_ops)):
            logger.debug("Decompiling (%d, %s)...", r_id, self._named_coroutines[r_id] if r_id in self._named_coroutines else None)
            self._write_routine_header(r_id, r_info)
            with Blk(self):
                if len(r_ops) == 0:
                    self.write_stmnt("alias previous;")
                for op in r_ops:
                    if isinstance(op, SsbLabel):
                        self.write_stmnt(f"§label_{op.id};")
                    else:
                        self._read_op(op)
            self._write_line()
        return self._output, self._source_map_builder.build()

    def _write_routine_header(self, r_id, r_info):
        if r_info.type == SsbRoutineType.COROUTINE:
            if r_id in self._named_coroutines:
                self.write_stmnt(f"coro {self._named_coroutines[r_id]}")
            else:
                raise ValueError(f"Unknown coroutine for: {r_id}, {r_info}")
        elif r_info.type == SsbRoutineType.ACTOR:
            self.write_stmnt(f"def {r_id} for_actor({r_info.linked_to_repr})")
        elif r_info.type == SsbRoutineType.OBJECT:
            self.write_stmnt(f"def {r_id} for_object({r_info.linked_to_repr})")
        elif r_info.type == SsbRoutineType.PERFORMER:
            self.write_stmnt(f"def {r_id} for_performer({r_info.linked_to_repr})")
        elif r_info.type == SsbRoutineType.GENERIC:
            self.write_stmnt(f"def {r_id}")
        else:
            raise ValueError(f"Unknown routine type for: {r_id}, {r_info}")

    def _read_op(self, op: SsbOperation):
        real_op = op
        if isinstance(op, SsbLabelJump):
            real_op = op.root

        orig_params = real_op.params
        if isinstance(op.params, dict):
            orig_params = real_op.params.values()

        # Build parameter string
        params = ", ".join(
            [self._single_param_to_string(param) for param in orig_params]
        )
        # Add label marker to parameter string, if needed
        if isinstance(op, SsbLabelJump):
            if len(orig_params) > 0:
                params += ", "
            params += f"@label_{op.label.id}"
        # Build position mark source maps
        for param in orig_params:
            if isinstance(param, SsbOpParamPositionMarker):
                cn = self.indent * NUMBER_OF_SPACES_PER_INDENT
                self._source_map_builder.add_position_mark(SourceMapPositionMark(
                    line_number=self._line_number, column_number=cn,
                    end_line_number=self._line_number, end_column_number=cn + len(self._single_param_to_string(param)),
                    name=param.name,
                    x_offset=param.x_offset, y_offset=param.y_offset,
                    x_relative=param.x_relative, y_relative=param.y_relative
                ))
        self._source_map_builder.add_opcode(op.offset, self._line_number, self.indent * NUMBER_OF_SPACES_PER_INDENT)
        self.write_stmnt(f"{real_op.op_code.name}({params});")

    def _single_param_to_string(self, param: SsbOpParam):
        if hasattr(param, 'indent'):
            param.indent = self.indent
        return str(param)

    def write_stmnt(self, stmnt, line=True):
        """Write a simple single line statement"""
        if line:
            self._write_line()
        self._line_number += stmnt.count('\n')
        self._output += stmnt

    def _write_line(self):
        self._line_number += 1
        self._output += "\n"
        self._output += " " * (self.indent * NUMBER_OF_SPACES_PER_INDENT)
