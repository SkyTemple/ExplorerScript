"""
Opposite of decompiler.label_jump_to_resolver -> Removes LabelJumps and Labels
and replaces jumps by regular opcodes arguments.
 """
#  MIT License
#
#  Copyright (c) 2020-2021 Parakoopa and the SkyTemple Contributors
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
from typing import List, Dict

from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabelJump, SsbLabel
logger = logging.getLogger(__name__)


class OpsLabelJumpToRemover:
    def __init__(self, routines: List[List[SsbOperation]], label_offsets: Dict[int, int]):
        logger.debug("Removing labels - replacing them with opcode jumps...")
        self.routines = []

        # label_offsets is a dict that maps label ids to their next opcode offset id
        for routine_id, rtn in enumerate(routines):
            new_rtn_ops = []
            self.routines.append(new_rtn_ops)
            for op in rtn:
                if isinstance(op, SsbLabelJump):
                    # Remove the jump and add the label offset as last argument
                    new_op = op.root
                    new_op.params.append(label_offsets[op.label.id])
                    new_rtn_ops.append(new_op)
                elif isinstance(op, SsbLabel):
                    # Remove
                    pass
                else:
                    new_rtn_ops.append(op)
