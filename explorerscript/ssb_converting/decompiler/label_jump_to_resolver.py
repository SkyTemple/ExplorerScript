"""
Resolves the offsets of memory jump instructions in a list of ssb routines to label jumps
and inserts labels at the appropriate locations.
"""
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
from typing import List, Dict

from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import process_op_for_jump, SsbLabel
logger = logging.getLogger(__name__)


class OpsLabelJumpToResolver:
    def __init__(self, routines: List[List[SsbOperation]]):
        logger.debug("Constructing labels and jumps...")
        # A mapping of labels: {mem_location: label_name}
        self.labels: Dict[int, SsbLabel] = {}
        self.routines = []
        for routine_id, rtn in enumerate(routines):
            new_rtn_ops = []
            self.routines.append(new_rtn_ops)
            for op in rtn:
                new_rtn_ops.append(process_op_for_jump(op, self.labels, routine_id))

    def __iter__(self):
        rtn_iterator = iter(self.routines)
        try:
            while True:
                # This will eventually raise StopIteration.
                yield list(self._iter_routine(next(rtn_iterator)))
        except StopIteration:
            return

    def _iter_routine(self, rtn):
        op_iterator = iter(rtn)
        try:
            while True:
                # This will eventually raise StopIteration.
                next_item = next(op_iterator)
                if next_item.offset in self.labels:
                    yield self.labels[next_item.offset]
                yield next_item
        except StopIteration:
            return
