"""
Opposite of decompiler.label_jump_to_resolver -> Removes LabelJumps and Labels
and replaces jumps by regular opcodes arguments.
"""

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

import logging

from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, SsbLabel
from explorerscript.util import f, _

logger = logging.getLogger(__name__)


class OpsLabelJumpToRemover:
    def __init__(self, routines: list[list[SsbOperation]], label_offsets: dict[int, int]):
        logger.debug("Removing labels - replacing them with opcode jumps...")
        self.routines: list[list[SsbOperation]] = []

        # label_offsets is a dict that maps label ids to their next opcode offset id
        for routine_id, rtn in enumerate(routines):
            new_rtn_ops: list[SsbOperation] = []
            self.routines.append(new_rtn_ops)
            for op in rtn:
                if isinstance(op, SsbLabelJump):
                    # Remove the jump and add the label offset as last argument
                    new_op = op.root
                    assert op.label is not None
                    if op.label.id not in label_offsets:
                        label_id = op.label.original_name
                        if label_id is None:
                            label_id = f"<internal:{op.label.id}>"
                        raise SsbCompilerError(
                            f(_("Label {label_id} does not exist, but a jump to it does (remove it)."))
                        )
                    new_op.params.append(label_offsets[op.label.id])
                    new_rtn_ops.append(new_op)
                elif isinstance(op, SsbLabel):
                    # Remove
                    pass
                else:
                    new_rtn_ops.append(op)
