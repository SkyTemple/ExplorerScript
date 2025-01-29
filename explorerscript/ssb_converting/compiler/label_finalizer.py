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

from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, SsbLabelJump, OP_JUMP

logger = logging.getLogger(__name__)


class LabelFinalizer:
    """
    Updates the opcodes of all labels and builds a table of them.
    Also removes all jumps that jump to a label right after.
    """

    def __init__(self, routines: list[list[SsbOperation]]):
        logger.debug("Finalizing and optimizing labels...")
        self.routines: list[list[SsbOperation]] = []
        self.label_offsets: dict[int, int] = {}

        labels_waiting: list[SsbLabel] = []
        for r_id, r in enumerate(routines):
            new_r: list[SsbOperation] = []
            self.routines.append(new_r)
            for op_i, op in enumerate(r):
                if isinstance(op, SsbLabel):
                    labels_waiting.append(op)
                    new_r.append(op)
                else:
                    op_was_removed = False
                    if isinstance(op, SsbLabelJump) and op.root.op_code.name == OP_JUMP:
                        # Remove any regular jumps that just jump to a label right after
                        for label in self._labels_after(r, op_i):
                            if op.label == label:
                                op_was_removed = True

                    if not op_was_removed:
                        new_r.append(op)
                        for label in labels_waiting:
                            label.offset = op.offset
                            self.label_offsets[label.id] = label.offset
                        labels_waiting = []

    @classmethod
    def _labels_after(cls, r: list[SsbOperation], op_i: int, skip_redundant_label_jumps: bool = True) -> list[SsbLabel]:
        """Returns all labels in r after the opcode with index op_i (until the next non-label)."""
        ls: list[SsbLabel] = []
        cursor = op_i + 1
        try:
            while isinstance(r[cursor], SsbLabel) or isinstance(r[cursor], SsbLabelJump):
                if isinstance(r[cursor], SsbLabelJump):
                    # If this is a label jump, we ignore it, if it ALSO just jumps to a label right after,
                    # we only do this once because of performance concerns.
                    have_match = False
                    if skip_redundant_label_jumps:
                        for label in cls._labels_after(r, cursor, False):
                            if r[cursor].label == label:  # type: ignore
                                have_match = True
                                break
                    if have_match:
                        cursor += 1
                        continue
                    break
                ls.append(r[cursor])  # type: ignore
                cursor += 1
        except IndexError:
            pass
        return ls
