"""
Registry of special known ssb operations for the decompiler and some code to handle them.
ExplorerScript only maps ssb opcodes by name.
TODO: These are only valid for Sky-style ssb.
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
from typing import Dict, Union, List, Optional

from igraph import Graph, Vertex

from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpCode, SsbOpParamConstant

OP_JUMP = 'Jump'
OP_CALL = 'Call'

OP_BRANCH = 'Branch'
OP_BRANCH_BIT = 'BranchBit'
OP_BRANCH_DEBUG = 'BranchDebug'
OP_BRANCH_EDIT = 'BranchEdit'
OP_BRANCH_PERFORMANCE = 'BranchPerformance'
OP_BRANCH_SCENARIO_NOW = 'BranchScenarioNow'
OP_BRANCH_SCENARIO_NOW_AFTER = 'BranchScenarioNowAfter'
OP_BRANCH_SCENARIO_NOW_BEFORE = 'BranchScenarioNowBefore'
OP_BRANCH_SCENARIO_AFTER = 'BranchScenarioAfter'
OP_BRANCH_SCENARIO_BEFORE = 'BranchScenarioBefore'
OP_BRANCH_VALUE = 'BranchValue'
OP_BRANCH_VARIABLE = 'BranchVariable'
OP_BRANCH_VARIATION = 'BranchVariation'

OPS_BRANCH = {
    OP_BRANCH: 2,
    OP_BRANCH_BIT: 2,
    OP_BRANCH_DEBUG: 1,
    OP_BRANCH_EDIT: 1,
    'BranchExecuteSub': 1,
    OP_BRANCH_PERFORMANCE: 2,
    OP_BRANCH_SCENARIO_NOW: 3,
    OP_BRANCH_SCENARIO_NOW_AFTER: 3,
    OP_BRANCH_SCENARIO_NOW_BEFORE: 3,
    OP_BRANCH_SCENARIO_AFTER: 3,
    OP_BRANCH_SCENARIO_BEFORE: 3,
    'BranchSum': 3,
    OP_BRANCH_VALUE: 3,
    OP_BRANCH_VARIABLE: 3,
    OP_BRANCH_VARIATION: 1,
}

OP_CASE = 'Case'
OP_CASE_MENU = 'CaseMenu'
OP_CASE_MENU2 = 'CaseMenu2'
OP_CASE_VALUE = 'CaseValue'
OP_CASE_VARIABLE = 'CaseVariable'
OP_CASE_SCENARIO = 'CaseScenario'

OP_SWITCH = 'Switch'
OP_SWITCH_SECTOR = 'SwitchSector'
OP_SWITCH_SCENARIO = 'SwitchScenario'
OP_SWITCH_RANDOM = 'SwitchRandom'
OP_SWITCH_SCENARIO_LEVEL = 'SwitchScenarioLevel'
OP_SWITCH_DUNGEON_MODE = 'SwitchDungeonMode'
OPS_REGULAR_CASES = [OP_CASE, OP_CASE_VALUE, OP_CASE_VARIABLE, OP_CASE_SCENARIO]
OPS_SWITCH_CASE_MAP = {
    'message_SwitchMenu': [OP_CASE_MENU, OP_CASE_MENU2],
    'message_SwitchMenu2': [OP_CASE_MENU, OP_CASE_MENU2],
    OP_SWITCH: OPS_REGULAR_CASES,
    OP_SWITCH_SECTOR: OPS_REGULAR_CASES,
    'ProcessSpecial': OPS_REGULAR_CASES,
    'message_Menu': OPS_REGULAR_CASES,
    OP_SWITCH_SCENARIO: OPS_REGULAR_CASES,
    OP_SWITCH_RANDOM: OPS_REGULAR_CASES,
    OP_SWITCH_SCENARIO_LEVEL: OPS_REGULAR_CASES,
    OP_SWITCH_DUNGEON_MODE: OPS_REGULAR_CASES,
    'main_EnterAdventure': OPS_REGULAR_CASES,
    'main_EnterRescueUser': OPS_REGULAR_CASES,
    'main_EnterTraining': OPS_REGULAR_CASES,
    'main_EnterTraining2': OPS_REGULAR_CASES
}

OP_MESSAGE_SWITCH_TALK = 'message_SwitchTalk'
OP_MESSAGE_SWITCH_MONOLOGUE = 'message_SwitchMonologue'
OP_CASE_TEXT = 'CaseText'
OP_DEFAULT_TEXT = 'DefaultText'
OPS_SWITCH_TEXT_CASE_CASES_LIST = [OP_CASE_TEXT, OP_DEFAULT_TEXT]
OPS_SWITCH_TEXT_CASE_MAP = {
    OP_MESSAGE_SWITCH_TALK: OPS_SWITCH_TEXT_CASE_CASES_LIST,
    OP_MESSAGE_SWITCH_MONOLOGUE: OPS_SWITCH_TEXT_CASE_CASES_LIST,
}

# A list of ops with jumps to memory offsets, values are the parameter index containing the jump
OPS_WITH_JUMP_TO_MEM_OFFSET = {
    OP_CASE: 1,
    OP_CASE_MENU: 1,
    OP_CASE_MENU2: 1,
    OP_CASE_SCENARIO: 2,
    OP_CASE_VALUE: 2,
    OP_CASE_VARIABLE: 2,
    # Special case; these opcodes ALWAYS jumps:
    OP_JUMP: 0,
    OP_CALL: 0,
}
OPS_WITH_JUMP_TO_MEM_OFFSET.update(OPS_BRANCH)

OPS_ALL_SPECIAL = [
    OP_JUMP, OP_CALL,

    OP_BRANCH, OP_BRANCH_BIT, OP_BRANCH_DEBUG, OP_BRANCH_EDIT, OP_BRANCH_PERFORMANCE,
    OP_BRANCH_SCENARIO_NOW, OP_BRANCH_SCENARIO_NOW_AFTER, OP_BRANCH_SCENARIO_NOW_BEFORE,
    OP_BRANCH_SCENARIO_AFTER, OP_BRANCH_SCENARIO_BEFORE,
    OP_BRANCH_VALUE, OP_BRANCH_VARIABLE, OP_BRANCH_VARIATION,
    OP_CASE, OP_CASE_MENU, OP_CASE_MENU2, OP_CASE_VALUE, OP_CASE_VARIABLE, OP_CASE_SCENARIO,

    OP_SWITCH, OP_SWITCH_SECTOR, OP_SWITCH_SCENARIO, OP_SWITCH_RANDOM, OP_SWITCH_SCENARIO_LEVEL,
    OP_SWITCH_DUNGEON_MODE, OP_MESSAGE_SWITCH_TALK, OP_MESSAGE_SWITCH_MONOLOGUE, OP_CASE_TEXT, OP_DEFAULT_TEXT
]


# THEORY:
# Hold doesn't ACTUALLY end the execution, it just freezes the calling object/"thread" forever,
# until the script is replaced?
# After Hold we can assume the execution flow is stopped, but sometimes there's also still another token of
# OPS_THAT_END_CONTROL_FLOW after it, and we should probably include that when reading in ssb.
# TODO: in some cases Hold might actually be able to continue and also be used that way!
OP_HOLD = 'Hold'
OP_RETURN = 'Return'
OP_END = 'End'
# The opcode to insert if a control flow ending opcode needs to be inserted
OP_DUMMY_END = OP_RETURN

# These ops end the control flow in the current routine
# (usually by jumping somewhere else and NOT "automatically" returining.)
# This does not include OpCodes that MAY jump somewhere else (branching opcodes, see above)
OPS_THAT_END_CONTROL_FLOW = [
    OP_JUMP, OP_RETURN, OP_END, OP_HOLD, 'JumpCommon', 'Destroy'
]


OPS_CTX_LIVES = 'lives'
OPS_CTX_OBJECT = 'object'
OPS_CTX_PERFORMER = 'performer'
# The next OP after these will be executed in the context of an actor/object/performer
OPS_CTX = [OPS_CTX_LIVES, OPS_CTX_OBJECT, OPS_CTX_PERFORMER]


OPS_FLAG__CALC_BIT             = 'flag_CalcBit'
OPS_FLAG__CALC_VALUE           = 'flag_CalcValue'
OPS_FLAG__CALC_VARIABLE        = 'flag_CalcVariable'
OPS_FLAG__CLEAR                = 'flag_Clear'
OPS_FLAG__INITIAL              = 'flag_Initial'
OPS_FLAG__SET                  = 'flag_Set'
OPS_FLAG__RESET_DUNGEON_RESULT = 'flag_ResetDungeonResult'
OPS_FLAG__RESET_SCENARIO       = 'flag_ResetScenario'
OPS_FLAG__SET_ADVENTURE_LOG    = 'flag_SetAdventureLog'
OPS_FLAG__SET_DUNGEON_MODE     = 'flag_SetDungeonMode'
#OPS_FLAG__SET_DUNGEON_RESULT  = 'flag_SetDungeonResult'
OPS_FLAG__SET_PERFORMANCE      = 'flag_SetPerformance'
OPS_FLAG__SET_SCENARIO         = 'flag_SetScenario'

OPS_FLAG_ALL = [
    OPS_FLAG__CALC_BIT, OPS_FLAG__CALC_VALUE, OPS_FLAG__CALC_VARIABLE, OPS_FLAG__CLEAR,
    OPS_FLAG__INITIAL, OPS_FLAG__SET, OPS_FLAG__RESET_DUNGEON_RESULT, OPS_FLAG__RESET_SCENARIO,
    OPS_FLAG__SET_ADVENTURE_LOG, OPS_FLAG__SET_DUNGEON_MODE, OPS_FLAG__SET_PERFORMANCE,
    OPS_FLAG__SET_SCENARIO
]


class LabelMarker:
    pass


class LabelJumpMarker:
    pass


class CallJump(LabelJumpMarker):
    def __str__(self):
        return f"CALL"


class IfStart(LabelJumpMarker):
    def __init__(self, if_id: int):
        self.if_id = if_id
        self.is_not = False

    def __str__(self):
        return f"IF{' NOT' if self.is_not else ''}({self.if_id})"


class MultiIfStart(IfStart):
    def __init__(self, if_id: int, start_ifs):
        super().__init__(if_id)
        self.original_ssb_ifs_ops: list[SsbOperation] = start_ifs

    def __str__(self):
        return f"MIF{' NOT' if self.is_not else ''}({self.if_id}[{len(self.original_ssb_ifs_ops)}])"

    def add_if(self, ssb_if: SsbOperation):
        """Add the ORIGINAL opcodes (NOT SsbLabelJump, but their ROOT) to this list of ifs."""
        self.original_ssb_ifs_ops.append(ssb_if)


class SwitchStart(LabelJumpMarker):
    def __init__(self, switch_id: int):
        self.switch_id = switch_id

    def __str__(self):
        return f"SWITCH({self.switch_id})"


class ForeverContinue(LabelJumpMarker):
    def __init__(self, loop_id: int):
        self.loop_id = loop_id

    def __str__(self):
        return f"LOOP_CONTINUE({self.loop_id})"


class ForeverBreak(LabelJumpMarker):
    def __init__(self, loop_id: int):
        self.loop_id = loop_id

    def __str__(self):
        return f"LOOP_BREAK({self.loop_id})"


class IfEnd(LabelMarker):
    def __init__(self, if_id: int):
        self.if_id = if_id

    def __str__(self):
        return f"IF({self.if_id})"


class SwitchEnd(LabelMarker):
    def __init__(self, switch_id: int):
        self.switch_id = switch_id

    def __str__(self):
        return f"SWITCH({self.switch_id})"


class SwitchFalltrough(LabelMarker):
    def __str__(self):
        return f"FALL"


class ForeverStart(LabelMarker):
    def __init__(self, loop_id: int):
        self.loop_id = loop_id

    def __str__(self):
        return f"LOOP({self.loop_id})"


class ForeverEnd(LabelMarker):
    def __init__(self, loop_id: int):
        self.loop_id = loop_id

    def __str__(self):
        return f"END_LOOP({self.loop_id})"


class SsbLabel(SsbOperation):
    """A label that other operations can jump to"""
    def __init__(self, id: int, routine_id: int, debugging_note: str = None, original_name: str = None):
        #                                                      Params only for debugging
        super().__init__(-1, SsbOpCode(-1, f'ES_LABEL<{id}>'), [id])
        self.id: int = id
        # Routine id this label lies in
        self.routine_id = routine_id
        # Whether or not this label is referenced from another routine
        self.referenced_from_other_routine = False
        # Markers for this label (type of label)
        self.markers: list[LabelMarker] = []
        self.debugging_note = debugging_note
        # The original name in source code, if applicable
        self.original_name = original_name
        self.force_write = False

    def add_marker(self, m: LabelMarker):
        self.markers.append(m)

    def needs_to_be_printed(self, my_vertex_index: int, number_in_vs: int, graph: Graph):
        """If the number of incoming vertices is bigger than max_in_vs, then we need to print this label"""
        # TODO: There are still issues with this logic, we just output all for now (except switch fallthroughs!)
        return not(any([isinstance(m, SwitchFalltrough) for m in self.markers]))
        if self.force_write or my_vertex_index == 0 or self.referenced_from_other_routine:
            # If the label is the root vertex or referenced from another routine we NEED to output it!
            return True
        max_in_vs = 1
        for m in self.markers:
            if isinstance(m, SwitchFalltrough):
                # Switch fallthroughs can not be printed.
                return False
            if isinstance(m, IfEnd):
                max_in_vs += 1  # Each if adds one else branch.
            if isinstance(m, SwitchEnd):
                start: Vertex = self._find_switch_start_vertex(graph, m.switch_id)
                if not start:
                    raise ValueError(f"Start for switch {m.switch_id} not found.")
                max_in_vs += len(start.out_edges()) - 1
        return number_in_vs > max_in_vs

    @staticmethod
    def _find_switch_start_vertex(graph: Graph, switch_id: int) -> Optional[Vertex]:
        for v in graph.vs:
            if 'op' not in v.attributes():
                continue
            if isinstance(v['op'], SsbLabelJump):
                for m in v['op'].markers:
                    if isinstance(m, SwitchStart) and m.switch_id == switch_id:
                        return v
        return None

    def __str__(self):
        return f"{self.__class__.__name__}<id={self.id}, note={self.debugging_note}, markers={self.markers}>"


class SsbForeignLabel(SsbOperation):
    """A reference to a label in another routine"""
    def __init__(self, label: SsbLabel):
        #                                                              Params only for debugging
        super().__init__(-1, SsbOpCode(-1, f'ES_FOREIGN<{label.id}>'), [label.id])
        self.label = label


class SsbLabelJump(SsbOperation):
    """An op that jumps to a label."""
    def __init__(self, root: SsbOperation, label: Union[SsbLabel, None]):
        if isinstance(root, SsbLabelJump):
            # SsbLabelJumps can not be nested, that makes no sense. But for convenience, they can be "copied" this way.
            root = root.root
        if label is not None:
            label_id = label.id
        else:
            label_id = -1
        #                                                                             Params only for debugging
        super().__init__(root.offset, SsbOpCode(-1, f'ES_JUMP<{root.op_code.name}>'), [label_id])
        self.root = root
        # May be None, if so the connected edges determine the different jumps
        self.label = label
        # Markers for this jump (type of jump)
        self.markers: list[LabelJumpMarker] = []

    def add_marker(self, m: LabelJumpMarker):
        if len(self.markers) > 0:
            raise ValueError("Jumps can currently only have one or zero markers.")
        self.markers.append(m)

    def remove_marker(self):
        """Remove the first (and only) marker if exists."""
        if len(self.markers) > 0:
            del self.markers[0]

    def get_marker(self):
        """Returns the first (and only) marker if exists, otherwise None."""
        if len(self.markers) > 0:
            return self.markers[0]
        return None


class SwitchCaseOperation:
    """ For marking the edge of a switch. """
    def __init__(self, switch_index: int, index: int, op: SsbOperation):
        self.switch_index = switch_index
        self.index = index
        self.op = op

    def __str__(self):
        return f"{self.switch_index}:{self.index} :: {self.op}"


def process_op_for_jump(op: SsbOperation, known_labels: dict[int, SsbLabel], routine_id: int) -> SsbOperation:
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
        jmp = SsbLabelJump(
            SsbOperation(op.offset, op.op_code, new_params),
            label
        )
        if op.op_code.name == OP_CALL:
            jmp.markers.append(CallJump())
        return jmp
    return op
