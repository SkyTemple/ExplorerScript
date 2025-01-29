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

from typing import Any, cast

from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractCompileHandler,
    HANDL,
    CTX,
    AnyCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_adventure_log import (
    AssignmentAdventureLogCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_clear import (
    AssignmentClearCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_dungeon_mode import (
    AssignmentDungeonModeCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_initial import (
    AssignmentInitialCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_regular import (
    AssignmentRegularCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_reset import (
    AssignmentResetCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.assignments.assignment_scenario import (
    AssignmentScenarioCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.assignment_operator import (
    AssignOperatorCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.conditional_operator import (
    ConditionalOperatorCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.label import LabelCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.position_marker import PositionMarkerCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.position_marker_arg import (
    PositionMarkerArgCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.primitive import PrimitiveCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.scn_var import ScnVarCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.value_of import ValueOfCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ctxs.ctx_block import CtxBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.else_block import ElseBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.elseif_block import ElseIfBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.bit import IfHeaderBitCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.negatable import (
    IfHeaderNegatableCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.operator import (
    IfHeaderOperatorCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.header.scn import IfHeaderScnCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.if_block import IfBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.ifs.if_header import IfHeaderCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.loop.for_block import ForBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.loop.forever_block import ForeverBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.loop.while_block import WhileBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_block import CaseBlockCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_header import CaseHeaderCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_headers.menu import (
    CaseHeaderMenuCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_headers.op import (
    CaseHeaderOpCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.default_case_block import (
    DefaultCaseBlockCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.message_switch import (
    MessageSwitchCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_block import (
    SwitchBlockCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_header import (
    SwitchHeaderCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.dungeon_mode import (
    SwitchHeaderDungeonModeCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.random import (
    SwitchHeaderRandomCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.scn import (
    SwitchHeaderScnCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.sector import (
    SwitchHeaderSectorCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.null import NullCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.arg import ArgCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.arg_list import ArgListCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.macro_call import MacroCallCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.operation import OperationCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.statements.call import CallCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.statements.control_statement import (
    ControlStatementCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.statements.jump import JumpCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.util import _
from explorerscript_parser import ExplorerScriptParser, ExplorerScriptBaseVisitor, Antlr4ParserRuleContext


class StatementVisitor(ExplorerScriptBaseVisitor):
    """This listener collects a single statements from a routine / macro."""

    def __init__(self, root_handler: AnyCompileHandler, compiler_ctx: CompilerCtx) -> None:
        self.compiler_ctx = compiler_ctx
        # This stack contains the handlers for the blocks during compilation.
        # The bottom is always the null handler, which raises an assertion error if any method is called.
        self._current_handlers: list[AnyCompileHandler] = [
            NullCompileHandler(Antlr4ParserRuleContext(), self.compiler_ctx),
            root_handler,
        ]
        super().__init__()

    def visitCntrl_stmt(self, ctx: ExplorerScriptParser.Cntrl_stmtContext) -> Any:
        return self._push_handler_and_add(ctx, ControlStatementCompileHandler)

    def visitJump(self, ctx: ExplorerScriptParser.JumpContext) -> Any:
        return self._push_handler_and_add(ctx, JumpCompileHandler)

    def visitCall(self, ctx: ExplorerScriptParser.CallContext) -> Any:
        return self._push_handler_and_add(ctx, CallCompileHandler)

    def visitCtx_block(self, ctx: ExplorerScriptParser.Ctx_blockContext) -> Any:
        return self._push_handler_and_add(ctx, CtxBlockCompileHandler)

    def visitIf_block(self, ctx: ExplorerScriptParser.If_blockContext) -> Any:
        return self._push_handler_and_add(ctx, IfBlockCompileHandler)

    def visitElseif_block(self, ctx: ExplorerScriptParser.Elseif_blockContext) -> Any:
        return self._push_handler_and_add(ctx, ElseIfBlockCompileHandler)

    def visitElse_block(self, ctx: ExplorerScriptParser.Else_blockContext) -> Any:
        return self._push_handler_and_add(ctx, ElseBlockCompileHandler)

    def visitIf_header(self, ctx: ExplorerScriptParser.If_headerContext) -> Any:
        return self._push_handler_and_add(ctx, IfHeaderCompileHandler)

    def visitIf_h_negatable(self, ctx: ExplorerScriptParser.If_h_negatableContext) -> Any:
        return self._push_handler_and_add(ctx, IfHeaderNegatableCompileHandler)

    def visitIf_h_op(self, ctx: ExplorerScriptParser.If_h_opContext) -> Any:
        return self._push_handler_and_add(ctx, IfHeaderOperatorCompileHandler)

    def visitIf_h_bit(self, ctx: ExplorerScriptParser.If_h_bitContext) -> Any:
        return self._push_handler_and_add(ctx, IfHeaderBitCompileHandler)

    def visitIf_h_scn(self, ctx: ExplorerScriptParser.If_h_scnContext) -> Any:
        return self._push_handler_and_add(ctx, IfHeaderScnCompileHandler)

    def visitSwitch_block(self, ctx: ExplorerScriptParser.Switch_blockContext) -> Any:
        return self._push_handler_and_add(ctx, SwitchBlockCompileHandler)

    def visitMessage_switch_block(self, ctx: ExplorerScriptParser.Message_switch_blockContext) -> Any:
        return self._push_handler_and_add(ctx, MessageSwitchCompileHandler)

    def visitSingle_case_block(self, ctx: ExplorerScriptParser.Single_case_blockContext) -> Any:
        return self._push_handler_and_add(ctx, CaseBlockCompileHandler)

    def visitDefault(self, ctx: ExplorerScriptParser.DefaultContext) -> Any:
        return self._push_handler_and_add(ctx, DefaultCaseBlockCompileHandler)

    def visitSwitch_header(self, ctx: ExplorerScriptParser.Switch_headerContext) -> Any:
        return self._push_handler_and_add(ctx, SwitchHeaderCompileHandler)

    def visitSwitch_h_scn(self, ctx: ExplorerScriptParser.Switch_h_scnContext) -> Any:
        return self._push_handler_and_add(ctx, SwitchHeaderScnCompileHandler)

    def visitSwitch_h_random(self, ctx: ExplorerScriptParser.Switch_h_randomContext) -> Any:
        return self._push_handler_and_add(ctx, SwitchHeaderRandomCompileHandler)

    def visitSwitch_h_dungeon_mode(self, ctx: ExplorerScriptParser.Switch_h_dungeon_modeContext) -> Any:
        return self._push_handler_and_add(ctx, SwitchHeaderDungeonModeCompileHandler)

    def visitSwitch_h_sector(self, ctx: ExplorerScriptParser.Switch_h_sectorContext) -> Any:
        return self._push_handler_and_add(ctx, SwitchHeaderSectorCompileHandler)

    def visitCase_header(self, ctx: ExplorerScriptParser.Case_headerContext) -> Any:
        return self._push_handler_and_add(ctx, CaseHeaderCompileHandler)

    def visitCase_h_menu(self, ctx: ExplorerScriptParser.Case_h_menuContext) -> Any:
        # TODO: Fix typing (mypy: Cannot infer type argument 1 of ...)
        return self._push_handler_and_add(ctx, CaseHeaderMenuCompileHandler, is_menu_2=False)  # type: ignore

    def visitCase_h_menu2(self, ctx: ExplorerScriptParser.Case_h_menu2Context) -> Any:
        # TODO: Fix typing (mypy: Cannot infer type argument 1 of ...)
        return self._push_handler_and_add(ctx, CaseHeaderMenuCompileHandler, is_menu_2=True)  # type: ignore

    def visitCase_h_op(self, ctx: ExplorerScriptParser.Case_h_opContext) -> Any:
        # TODO: Fix typing (mypy: Cannot infer type argument 1 of ...)
        return self._push_handler_and_add(ctx, CaseHeaderOpCompileHandler)  # type: ignore

    def visitForever_block(self, ctx: ExplorerScriptParser.Forever_blockContext) -> Any:
        return self._push_handler_and_add(ctx, ForeverBlockCompileHandler)

    def visitFor_block(self, ctx: ExplorerScriptParser.For_blockContext) -> Any:
        return self._push_handler_and_add(ctx, ForBlockCompileHandler)

    def visitWhile_block(self, ctx: ExplorerScriptParser.While_blockContext) -> Any:
        return self._push_handler_and_add(ctx, WhileBlockCompileHandler)

    def visitAssignment_regular(self, ctx: ExplorerScriptParser.Assignment_regularContext) -> Any:
        return self._push_handler_and_add(ctx, AssignmentRegularCompileHandler)

    def visitAssignment_clear(self, ctx: ExplorerScriptParser.Assignment_clearContext) -> Any:
        return self._push_handler_and_add(ctx, AssignmentClearCompileHandler)

    def visitAssignment_initial(self, ctx: ExplorerScriptParser.Assignment_initialContext) -> Any:
        return self._push_handler_and_add(ctx, AssignmentInitialCompileHandler)

    def visitAssignment_reset(self, ctx: ExplorerScriptParser.Assignment_resetContext) -> Any:
        return self._push_handler_and_add(ctx, AssignmentResetCompileHandler)

    def visitAssignment_adv_log(self, ctx: ExplorerScriptParser.Assignment_adv_logContext) -> Any:
        return self._push_handler_and_add(ctx, AssignmentAdventureLogCompileHandler)

    def visitAssignment_dungeon_mode(self, ctx: ExplorerScriptParser.Assignment_dungeon_modeContext) -> Any:
        return self._push_handler_and_add(ctx, AssignmentDungeonModeCompileHandler)

    def visitAssignment_scn(self, ctx: ExplorerScriptParser.Assignment_scnContext) -> Any:
        return self._push_handler_and_add(ctx, AssignmentScenarioCompileHandler)

    def visitValue_of(self, ctx: ExplorerScriptParser.Value_ofContext) -> Any:
        return self._push_handler_and_add(ctx, ValueOfCompileHandler)

    def visitScn_var(self, ctx: ExplorerScriptParser.Scn_varContext) -> Any:
        return self._push_handler_and_add(ctx, ScnVarCompileHandler)

    def visitConditional_operator(self, ctx: ExplorerScriptParser.Conditional_operatorContext) -> Any:
        return self._push_handler_and_add(ctx, ConditionalOperatorCompileHandler)

    def visitAssign_operator(self, ctx: ExplorerScriptParser.Assign_operatorContext) -> Any:
        return self._push_handler_and_add(ctx, AssignOperatorCompileHandler)

    def visitPrimitive(self, ctx: ExplorerScriptParser.PrimitiveContext) -> Any:
        return self._push_handler_and_add(ctx, PrimitiveCompileHandler)

    def visitOperation(self, ctx: ExplorerScriptParser.OperationContext) -> Any:
        return self._push_handler_and_add(ctx, OperationCompileHandler)

    def visitArglist(self, ctx: ExplorerScriptParser.ArglistContext) -> Any:
        return self._push_handler_and_add(ctx, ArgListCompileHandler)

    def visitPos_argument(self, ctx: ExplorerScriptParser.Pos_argumentContext) -> Any:
        return self._push_handler_and_add(ctx, ArgCompileHandler)

    def visitPosition_marker(self, ctx: ExplorerScriptParser.Position_markerContext) -> Any:
        return self._push_handler_and_add(ctx, PositionMarkerCompileHandler)

    def visitPosition_marker_arg(self, ctx: ExplorerScriptParser.Position_marker_argContext) -> Any:
        return self._push_handler_and_add(ctx, PositionMarkerArgCompileHandler)

    def visitLabel(self, ctx: ExplorerScriptParser.LabelContext) -> Any:
        return self._push_handler_and_add(ctx, LabelCompileHandler)

    def visitString(self, ctx: ExplorerScriptParser.StringContext) -> Any:
        pass  # Strings are handled by the PrimitiveCompileHandler directly.

    def visitLang_string(self, ctx: ExplorerScriptParser.Lang_stringContext) -> Any:
        pass  # Strings are handled by the PrimitiveCompileHandler directly.

    def visitLang_string_argument(self, ctx: ExplorerScriptParser.Lang_string_argumentContext) -> Any:
        pass  # Strings are handled by the PrimitiveCompileHandler directly.

    def visitMacro_call(self, ctx: ExplorerScriptParser.Macro_callContext) -> Any:
        return self._push_handler_and_add(ctx, MacroCallCompileHandler)

    def visitConstant_assign(self, ctx: ExplorerScriptParser.Constant_assignContext) -> None:
        # Are not visited.
        return None

    def _push_handler_and_add(
        self,
        ctx: CTX,
        compile_handler: type[AbstractCompileHandler[CTX, HANDL]],
        **kwargs: Any,
    ) -> Any:
        """Pushes the handler on the stack, visits the children and when done adds the handler to the parent handler."""
        retval, h = self._push_handler(ctx, compile_handler, **kwargs)
        self._current_handlers[-1].add(h)
        return retval

    def _push_handler(
        self,
        ctx: CTX,
        compile_handler: type[AbstractCompileHandler[CTX, HANDL]],
        **kwargs: Any,
    ) -> tuple[Any, AnyCompileHandler]:
        """Pushes the handler on the stack, visits the children and returns result and handler."""
        self._current_handlers.append(cast(AnyCompileHandler, compile_handler(ctx, self.compiler_ctx, **kwargs)))
        retval = self.visitChildren(ctx)
        h = self._current_handlers.pop()
        assert id(h.ctx) == id(ctx), _("Fatal compilation error: Unexpected compilation handler on stack.")
        assert not isinstance(h, NullCompileHandler), _("Fatal compilation error: Stack error.")
        return retval, h
