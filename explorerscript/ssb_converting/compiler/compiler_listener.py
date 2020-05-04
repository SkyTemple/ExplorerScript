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
from typing import List

from explorerscript.antlr.ExplorerScriptListener import ExplorerScriptListener
from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.source_map import SourceMapBuilder
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_adventure_log import \
    AssignmentAdventureLogCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_clear import \
    AssignmentClearCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_dungeon_mode import \
    AssignmentDungeonModeCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_initial import \
    AssignmentInitialCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_regular import \
    AssignmentRegularCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_reset import \
    AssignmentResetCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_scenario import \
    AssignmentScenarioCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.assignment_operator import \
    AssignOperatorCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.conditional_operator import \
    ConditionalOperatorCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.integer_like import IntegerLikeCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.label import LabelCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.lang_string import LangStringCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.lang_string_arg import \
    LangStringArgumentCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.position_marker import PositionMarkerCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.position_marker_arg import \
    PositionMarkerArgCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.scn_var import ScnVarCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.string import StringCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.value_of import ValueOfCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ctxs.ctx_block import CtxBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.forevers.forever_block import \
    ForeverBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.else_block import ElseBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.elseif_block import ElseIfBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.bit import IfHeaderBitCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.operator import \
    IfHeaderOperatorCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.scn import IfHeaderScnCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.if_block import IfBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.if_header import IfHeaderCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_headers.menu import \
    CaseHeaderMenuCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_headers.op import \
    CaseHeaderOpCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_header import \
    CaseHeaderCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.default_case_block import \
    DefaultCaseBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.message_switch import \
    MessageSwitchCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_block import \
    CaseBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_block import \
    SwitchBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_header import \
    SwitchHeaderCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.dungeon_mode import \
    SwitchHeaderDungeonModeCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.random import \
    SwitchHeaderRandomCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.scn import \
    SwitchHeaderScnCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.sector import \
    SwitchHeaderSectorCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.coro_def import CoroDefCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.for_target_def import ForTargetDefCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.functions.simple_def import SimpleDefCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.null import NullCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.arg import ArgCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.arg_list import ArgListCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.operation import OperationCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.statements.control_statement import \
    ControlStatementCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.statements.jump import JumpCompileHandler
from explorerscript.ssb_converting.compiler.utils import Counter, CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbOperation


class ExplorerScriptCompilerListener(ExplorerScriptListener):
    """Builds the SSB data structures while listening for parsing events."""
    def __init__(self, performance_progress_list_var_name: str):
        # The information about routines stored in the ssb.
        self.routine_infos: List[SsbRoutineInfo] = []
        self.routine_ops: List[List[SsbOperation]] = []
        self.named_coroutines: List[str] = []
        # Source map
        self.source_map_builder: SourceMapBuilder = SourceMapBuilder()

        # Global compilation context for the handlers
        self.compiler_ctx = CompilerCtx(
            Counter(), self.source_map_builder, {}, Counter(), performance_progress_list_var_name
        )

        self._active_routine_id = -1
        # This stack contains the handlers for the blocks during compilation.
        # The bottom is always the null handler, which raises an assertion error if any method is called.
        self._current_handlers: List[AbstractCompileHandler] = [NullCompileHandler(None, self.compiler_ctx)]

    def enterSimple_def(self, ctx: ExplorerScriptParser.Simple_defContext):
        self._current_handlers.append(SimpleDefCompileHandler(ctx, self.compiler_ctx))

    def exitSimple_def(self, ctx: ExplorerScriptParser.Simple_defContext):
        """ Exits a def X { } """
        # noinspection PyTypeChecker
        h: SimpleDefCompileHandler = self._generic_end_handler(ctx)
        self._active_routine_id = h.get_new_routine_id(self._active_routine_id)
        self._enlarge_routine_info()
        self.routine_infos[self._active_routine_id], self.routine_ops[self._active_routine_id] = h.collect()

    def enterCoro_def(self, ctx: ExplorerScriptParser.Coro_defContext):
        self._current_handlers.append(CoroDefCompileHandler(ctx, self.compiler_ctx))

    def exitCoro_def(self, ctx: ExplorerScriptParser.Coro_defContext):
        """ Exits a coro X { } """
        # noinspection PyTypeChecker
        h: CoroDefCompileHandler = self._generic_end_handler(ctx)
        self._active_routine_id = h.get_new_routine_id(self._active_routine_id)
        self._enlarge_routine_info()

        self.named_coroutines[self._active_routine_id], \
            self.routine_infos[self._active_routine_id], \
            self.routine_ops[self._active_routine_id] = h.collect()

    def enterFor_target_def(self, ctx: ExplorerScriptParser.For_target_defContext):
        self._current_handlers.append(ForTargetDefCompileHandler(ctx, self.compiler_ctx))

    def exitFor_target_def(self, ctx: ExplorerScriptParser.For_target_defContext):
        """ Exits a def X (for_Y Z) { } """
        # noinspection PyTypeChecker
        h: ForTargetDefCompileHandler = self._generic_end_handler(ctx)
        self._active_routine_id = h.get_new_routine_id(self._active_routine_id)
        self._enlarge_routine_info()
        self.routine_infos[self._active_routine_id], self.routine_ops[self._active_routine_id] = h.collect()

    def exitCntrl_stmt(self, ctx: ExplorerScriptParser.Cntrl_stmtContext):
        self._current_handlers[-1].add(ControlStatementCompileHandler(ctx, self.compiler_ctx))

    def exitJump(self, ctx: ExplorerScriptParser.JumpContext):
        self._current_handlers[-1].add(JumpCompileHandler(ctx, self.compiler_ctx))

    def enterCtx_block(self, ctx: ExplorerScriptParser.Ctx_blockContext):
        self._current_handlers.append(CtxBlockCompileHandler(ctx, self.compiler_ctx))

    def exitCtx_block(self, ctx: ExplorerScriptParser.Ctx_blockContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterIf_block(self, ctx: ExplorerScriptParser.If_blockContext):
        self._current_handlers.append(IfBlockCompileHandler(ctx, self.compiler_ctx))

    def exitIf_block(self, ctx: ExplorerScriptParser.If_blockContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterElseif_block(self, ctx: ExplorerScriptParser.Elseif_blockContext):
        self._current_handlers.append(ElseIfBlockCompileHandler(ctx, self.compiler_ctx))

    def exitElseif_block(self, ctx: ExplorerScriptParser.Elseif_blockContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterElse_block(self, ctx: ExplorerScriptParser.Else_blockContext):
        self._current_handlers.append(ElseBlockCompileHandler(ctx, self.compiler_ctx))

    def exitElse_block(self, ctx: ExplorerScriptParser.Else_blockContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterIf_header(self, ctx: ExplorerScriptParser.If_headerContext):
        self._current_handlers.append(IfHeaderCompileHandler(ctx, self.compiler_ctx))

    def exitIf_header(self, ctx: ExplorerScriptParser.If_headerContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterIf_h_op(self, ctx: ExplorerScriptParser.If_h_opContext):
        self._current_handlers.append(IfHeaderOperatorCompileHandler(ctx, self.compiler_ctx))

    def exitIf_h_op(self, ctx: ExplorerScriptParser.If_h_opContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterIf_h_bit(self, ctx: ExplorerScriptParser.If_h_bitContext):
        self._current_handlers.append(IfHeaderBitCompileHandler(ctx, self.compiler_ctx))

    def exitIf_h_bit(self, ctx: ExplorerScriptParser.If_h_bitContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterIf_h_scn(self, ctx: ExplorerScriptParser.If_h_scnContext):
        self._current_handlers.append(IfHeaderScnCompileHandler(ctx, self.compiler_ctx))

    def exitIf_h_scn(self, ctx: ExplorerScriptParser.If_h_scnContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterSwitch_block(self, ctx: ExplorerScriptParser.Switch_blockContext):
        self._current_handlers.append(SwitchBlockCompileHandler(ctx, self.compiler_ctx))

    def exitSwitch_block(self, ctx: ExplorerScriptParser.Switch_blockContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterMessage_switch_block(self, ctx: ExplorerScriptParser.Message_switch_blockContext):
        self._current_handlers.append(MessageSwitchCompileHandler(ctx, self.compiler_ctx))

    def exitMessage_switch_block(self, ctx: ExplorerScriptParser.Message_switch_blockContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterSingle_case_block(self, ctx: ExplorerScriptParser.Single_case_blockContext):
        self._current_handlers.append(CaseBlockCompileHandler(ctx, self.compiler_ctx))

    def exitSingle_case_block(self, ctx: ExplorerScriptParser.Single_case_blockContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterDefault(self, ctx: ExplorerScriptParser.DefaultContext):
        self._current_handlers.append(DefaultCaseBlockCompileHandler(ctx, self.compiler_ctx))

    def exitDefault(self, ctx: ExplorerScriptParser.DefaultContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterSwitch_header(self, ctx: ExplorerScriptParser.Switch_headerContext):
        self._current_handlers.append(SwitchHeaderCompileHandler(ctx, self.compiler_ctx))

    def exitSwitch_header(self, ctx: ExplorerScriptParser.Switch_headerContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterSwitch_h_scn(self, ctx: ExplorerScriptParser.Switch_h_scnContext):
        self._current_handlers.append(SwitchHeaderScnCompileHandler(ctx, self.compiler_ctx))

    def exitSwitch_h_scn(self, ctx: ExplorerScriptParser.Switch_h_scnContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterSwitch_h_random(self, ctx: ExplorerScriptParser.Switch_h_randomContext):
        self._current_handlers.append(SwitchHeaderRandomCompileHandler(ctx, self.compiler_ctx))

    def exitSwitch_h_random(self, ctx: ExplorerScriptParser.Switch_h_randomContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterSwitch_h_dungeon_mode(self, ctx: ExplorerScriptParser.Switch_h_dungeon_modeContext):
        self._current_handlers.append(SwitchHeaderDungeonModeCompileHandler(ctx, self.compiler_ctx))

    def exitSwitch_h_dungeon_mode(self, ctx: ExplorerScriptParser.Switch_h_dungeon_modeContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterSwitch_h_sector(self, ctx: ExplorerScriptParser.Switch_h_sectorContext):
        self._current_handlers.append(SwitchHeaderSectorCompileHandler(ctx, self.compiler_ctx))

    def exitSwitch_h_sector(self, ctx: ExplorerScriptParser.Switch_h_sectorContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterCase_header(self, ctx: ExplorerScriptParser.Case_headerContext):
        self._current_handlers.append(CaseHeaderCompileHandler(ctx, self.compiler_ctx))

    def exitCase_header(self, ctx: ExplorerScriptParser.Case_headerContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterCase_h_menu(self, ctx: ExplorerScriptParser.Case_h_menuContext):
        self._current_handlers.append(CaseHeaderMenuCompileHandler(ctx, self.compiler_ctx, False))

    def exitCase_h_menu(self, ctx: ExplorerScriptParser.Case_h_menuContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterCase_h_menu2(self, ctx: ExplorerScriptParser.Case_h_menu2Context):
        self._current_handlers.append(CaseHeaderMenuCompileHandler(ctx, self.compiler_ctx, True))

    def exitCase_h_menu2(self, ctx: ExplorerScriptParser.Case_h_menu2Context):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterCase_h_op(self, ctx: ExplorerScriptParser.Case_h_opContext):
        self._current_handlers.append(CaseHeaderOpCompileHandler(ctx, self.compiler_ctx))

    def exitCase_h_op(self, ctx: ExplorerScriptParser.Case_h_opContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterForever_block(self, ctx: ExplorerScriptParser.Forever_blockContext):
        h = ForeverBlockCompileHandler(ctx, self.compiler_ctx)
        self._current_handlers.append(h)

    def exitForever_block(self, ctx: ExplorerScriptParser.Forever_blockContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterAssignment_regular(self, ctx: ExplorerScriptParser.Assignment_regularContext):
        self._current_handlers.append(AssignmentRegularCompileHandler(ctx, self.compiler_ctx))

    def exitAssignment_regular(self, ctx: ExplorerScriptParser.Assignment_regularContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterAssignment_clear(self, ctx: ExplorerScriptParser.Assignment_clearContext):
        self._current_handlers.append(AssignmentClearCompileHandler(ctx, self.compiler_ctx))

    def exitAssignment_clear(self, ctx: ExplorerScriptParser.Assignment_clearContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterAssignment_initial(self, ctx: ExplorerScriptParser.Assignment_initialContext):
        self._current_handlers.append(AssignmentInitialCompileHandler(ctx, self.compiler_ctx))

    def exitAssignment_initial(self, ctx: ExplorerScriptParser.Assignment_initialContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterAssignment_reset(self, ctx: ExplorerScriptParser.Assignment_resetContext):
        self._current_handlers.append(AssignmentResetCompileHandler(ctx, self.compiler_ctx))

    def exitAssignment_reset(self, ctx: ExplorerScriptParser.Assignment_resetContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterAssignment_adv_log(self, ctx: ExplorerScriptParser.Assignment_adv_logContext):
        self._current_handlers.append(AssignmentAdventureLogCompileHandler(ctx, self.compiler_ctx))

    def exitAssignment_adv_log(self, ctx: ExplorerScriptParser.Assignment_adv_logContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterAssignment_dungeon_mode(self, ctx: ExplorerScriptParser.Assignment_dungeon_modeContext):
        self._current_handlers.append(AssignmentDungeonModeCompileHandler(ctx, self.compiler_ctx))

    def exitAssignment_dungeon_mode(self, ctx: ExplorerScriptParser.Assignment_dungeon_modeContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterAssignment_scn(self, ctx: ExplorerScriptParser.Assignment_scnContext):
        self._current_handlers.append(AssignmentScenarioCompileHandler(ctx, self.compiler_ctx))

    def exitAssignment_scn(self, ctx: ExplorerScriptParser.Assignment_scnContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterValue_of(self, ctx: ExplorerScriptParser.Value_ofContext):
        self._current_handlers.append(ValueOfCompileHandler(ctx, self.compiler_ctx))

    def exitValue_of(self, ctx: ExplorerScriptParser.Value_ofContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterScn_var(self, ctx: ExplorerScriptParser.Scn_varContext):
        self._current_handlers.append(ScnVarCompileHandler(ctx, self.compiler_ctx))

    def exitScn_var(self, ctx: ExplorerScriptParser.Scn_varContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def exitConditional_operator(self, ctx: ExplorerScriptParser.Conditional_operatorContext):
        self._current_handlers[-1].add(ConditionalOperatorCompileHandler(ctx, self.compiler_ctx))

    def exitAssign_operator(self, ctx: ExplorerScriptParser.Assign_operatorContext):
        self._current_handlers[-1].add(AssignOperatorCompileHandler(ctx, self.compiler_ctx))

    def exitInteger_like(self, ctx: ExplorerScriptParser.Integer_likeContext):
        self._current_handlers[-1].add(IntegerLikeCompileHandler(ctx, self.compiler_ctx))

    def enterOperation(self, ctx: ExplorerScriptParser.OperationContext):
        self._current_handlers.append(OperationCompileHandler(ctx, self.compiler_ctx))

    def exitOperation(self, ctx: ExplorerScriptParser.OperationContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterArglist(self, ctx: ExplorerScriptParser.ArglistContext):
        self._current_handlers.append(ArgListCompileHandler(ctx, self.compiler_ctx))

    def exitArglist(self, ctx: ExplorerScriptParser.ArglistContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterPos_argument(self, ctx: ExplorerScriptParser.Pos_argumentContext):
        self._current_handlers.append(ArgCompileHandler(ctx, self.compiler_ctx))

    def exitPos_argument(self, ctx: ExplorerScriptParser.Pos_argumentContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterPosition_marker(self, ctx: ExplorerScriptParser.Position_markerContext):
        self._current_handlers.append(PositionMarkerCompileHandler(ctx, self.compiler_ctx))

    def exitPosition_marker(self, ctx: ExplorerScriptParser.Position_markerContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def exitPosition_marker_arg(self, ctx: ExplorerScriptParser.Position_marker_argContext):
        self._current_handlers[-1].add(PositionMarkerArgCompileHandler(ctx, self.compiler_ctx))

    def enterLabel(self, ctx: ExplorerScriptParser.LabelContext):
        self._current_handlers.append(LabelCompileHandler(ctx, self.compiler_ctx))

    def exitLabel(self, ctx: ExplorerScriptParser.LabelContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterString(self, ctx: ExplorerScriptParser.StringContext):
        self._current_handlers.append(StringCompileHandler(ctx, self.compiler_ctx))

    def exitString(self, ctx: ExplorerScriptParser.StringContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def enterLang_string(self, ctx: ExplorerScriptParser.Lang_stringContext):
        self._current_handlers.append(LangStringCompileHandler(ctx, self.compiler_ctx))

    def exitLang_string(self, ctx: ExplorerScriptParser.Lang_stringContext):
        h = self._generic_end_handler(ctx)
        self._current_handlers[-1].add(h)

    def exitLang_string_argument(self, ctx: ExplorerScriptParser.Lang_string_argumentContext):
        self._current_handlers[-1].add(LangStringArgumentCompileHandler(ctx, self.compiler_ctx))

    def _enlarge_routine_info(self):
        if len(self.routine_infos) - 1 < self._active_routine_id:
            needed = self._active_routine_id - len(self.routine_infos) + 1
            for i in range(0, needed):
                self.routine_infos.append(None)
                self.routine_ops.append([])
                self.named_coroutines.append([])

    def _generic_end_handler(self, ctx) -> AbstractCompileHandler:
        h = self._current_handlers.pop()
        assert id(h.ctx) == id(ctx), "Fatal compilation error: Unexpected compilation handler on stack."
        assert not isinstance(h, NullCompileHandler), "Fatal compilation error: Stack error."
        return h
