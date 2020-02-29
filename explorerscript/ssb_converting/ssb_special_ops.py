"""
Registry of special known ssb operations for the decompiler and some code to handle them.
ExplorerScript only maps ssb opcodes by name.
TODO: These are only valid for Sky-style ssb.
"""
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
from typing import Dict

from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpCode

# A list of ops with jumps to memory offsets, values are the parameter index containing the jump
OPS_WITH_JUMP_TO_MEM_OFFSET = {
    'Branch': 2,
    'BranchBit': 2,
    'BranchDebug': 1,
    'BranchEdit': 1,
    'BranchExecuteSub': 1,
    'BranchPerformance': 2,
    'BranchScenarioNow': 3,
    'BranchScenarioNowAfter': 3,
    'BranchScenarioNowBefore': 3,
    'BranchScenarioAfter': 3,
    'BranchScenarioBefore': 3,
    'BranchSum': 3,
    'BranchValue': 3,
    'BranchVariable': 3,
    'BranchVariation': 1,
    #'Call': 0,  TODO: Check
    #'CancelRecoverCommon': 0,  TODO: Check
    'Case': 1,
    'CaseMenu': 1,
    #'CaseMenu2': 1,  TODO: Check
    'CaseScenario': 2,
    'CaseValue': 2,
    'CaseVariable': 2,
    'Jump': 0,
}


class SsbLabel(SsbOperation):
    def __init__(self, id: int):
        super().__init__(-1, SsbOpCode(-1, 'LABEL'), [id])
        self.id: int = id


def process_op_for_jump(op: SsbOperation, known_labels: Dict[int, SsbLabel]) -> SsbOperation:
    """
    Processes the operation.
    If it doesn't contain a jump to a memory offset, op is simply returned.

    Otherwise, a label for the jump location is searched in known_labels.
    - If found: the id of the label is inserted in the place of the memory jump param.
    - If not found: A new label with an auto-incremented id is generated and added to the known_labels.
                    The id of the label is inserted in the place of the memory jump param.
    """
    if op.op_code.name in OPS_WITH_JUMP_TO_MEM_OFFSET.keys():
        param_list = op.params if isinstance(op.params, list) else list(op.params.values())
        jump_param_idx = OPS_WITH_JUMP_TO_MEM_OFFSET[op.op_code.name]
        if len(param_list) < jump_param_idx:
            raise ValueError(f"The parameters for the opcode {op.op_code.name} must contain a jump address at index {jump_param_idx}.")
        old_offset = param_list[jump_param_idx]
        if old_offset in known_labels:
            label = known_labels[old_offset]
        else:
            if len(known_labels) == 0:
                next_label_id = 0
            else:
                next_label_id = max(label.id for label in known_labels.values()) + 1
            label = SsbLabel(next_label_id)
            known_labels[old_offset] = label
        new_params = param_list.copy()
        new_params[jump_param_idx] = label.id
        return SsbOperation(op.offset, op.op_code, new_params)
    return op
