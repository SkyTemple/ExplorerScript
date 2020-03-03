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
from typing import Dict, Union, List

from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpCode, SsbOpParamConstant

OP_JUMP = 'Jump'

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
    # Special case; this OpCode ALWAYS jumps:
    OP_JUMP: 0,
}


# THEORY:
# Hold doesn't ACTUALLY end the execution, it just freezes the calling object/"thread" forever,
# until the script is replaced?
# After Hold we can assume the execution flow is stopped, but sometimes there's also still another token of
# OPS_THAT_END_CONTROL_FLOW after it, and we should probably include that when reading in ssb.
# TODO: in some cases Hold might actually be able to continue and also be used that way!
OP_HOLD = 'Hold'


# These ops end the control flow in the current routine
# (usually by jumping somewhere else and NOT "automatically" returining.)
# This does not include OpCodes that MAY jump somewhere else (branching opcodes, see above)
OPS_THAT_END_CONTROL_FLOW = [
    OP_JUMP, 'Return', 'End', OP_HOLD
]

class SsbLabel(SsbOperation):
    """A label that other operations can jump to"""
    def __init__(self, id: int, routine_id: int):
        #                                                      Params only for debugging
        super().__init__(-1, SsbOpCode(-1, f'ES_LABEL<{id}>'), [id])
        self.id: int = id
        # Routine id this label lies in
        self.routine_id = routine_id
        # Whether or not this label is referenced from another routine
        self.referenced_from_other_routine = False


class SsbLabelJump(SsbOperation):
    """An op that jumps to a label."""
    def __init__(self, root: SsbOperation, label: SsbLabel):
        #                                                                             Params only for debugging
        super().__init__(root.offset, SsbOpCode(-1, f'ES_JUMP<{root.op_code.name}>'), [label.id])
        self.root = root
        self.label = label


def process_op_for_jump(op: SsbOperation, known_labels: Dict[int, SsbLabel], routine_id: int) -> SsbOperation:
    """
    Processes the operation.
    If it doesn't contain a jump to a memory offset, op is simply returned.

    Otherwise, a label for the jump location is searched in known_labels.
    - If found: Returns a OperationSubtree with a copy of op as root, and the label op as subtree.
                The param with the jump offset is removed from the op copy.
    - If not found: A new label with an auto-incremented id is generated and added to the known_labels.
                    Then: see above for "if found".
    """
    if op.op_code.name in OPS_WITH_JUMP_TO_MEM_OFFSET.keys():
        param_list = op.params if isinstance(op.params, list) else list(op.params.values())
        jump_param_idx = OPS_WITH_JUMP_TO_MEM_OFFSET[op.op_code.name]
        if len(param_list) < jump_param_idx:
            raise ValueError(f"The parameters for the OpCode {op.op_code.name} must contain a jump address at index {jump_param_idx}.")
        old_offset = param_list[jump_param_idx]
        if old_offset in known_labels:
            label = known_labels[old_offset]
            if routine_id != label.routine_id:
                label.referenced_from_other_routine = True
        else:
            if len(known_labels) == 0:
                next_label_id = 0
            else:
                next_label_id = max(label.id for label in known_labels.values()) + 1
            label = SsbLabel(next_label_id, routine_id)
            known_labels[old_offset] = label
        new_params = param_list.copy()
        del new_params[jump_param_idx]
        return SsbLabelJump(
            SsbOperation(op.offset, op.op_code, new_params),
            label
        )
    return op
