# Generated from ExplorerScript.g4 by ANTLR 4.8
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .ExplorerScriptParser import ExplorerScriptParser
else:
    from ExplorerScriptParser import ExplorerScriptParser

# This class defines a complete listener for a parse tree produced by ExplorerScriptParser.
class ExplorerScriptListener(ParseTreeListener):

    # Enter a parse tree produced by ExplorerScriptParser#start.
    def enterStart(self, ctx:ExplorerScriptParser.StartContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#start.
    def exitStart(self, ctx:ExplorerScriptParser.StartContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#import_stmt.
    def enterImport_stmt(self, ctx:ExplorerScriptParser.Import_stmtContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#import_stmt.
    def exitImport_stmt(self, ctx:ExplorerScriptParser.Import_stmtContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#macrodef.
    def enterMacrodef(self, ctx:ExplorerScriptParser.MacrodefContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#macrodef.
    def exitMacrodef(self, ctx:ExplorerScriptParser.MacrodefContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#stmt.
    def enterStmt(self, ctx:ExplorerScriptParser.StmtContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#stmt.
    def exitStmt(self, ctx:ExplorerScriptParser.StmtContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#simple_stmt.
    def enterSimple_stmt(self, ctx:ExplorerScriptParser.Simple_stmtContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#simple_stmt.
    def exitSimple_stmt(self, ctx:ExplorerScriptParser.Simple_stmtContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#cntrl_stmt.
    def enterCntrl_stmt(self, ctx:ExplorerScriptParser.Cntrl_stmtContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#cntrl_stmt.
    def exitCntrl_stmt(self, ctx:ExplorerScriptParser.Cntrl_stmtContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#jump.
    def enterJump(self, ctx:ExplorerScriptParser.JumpContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#jump.
    def exitJump(self, ctx:ExplorerScriptParser.JumpContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#call.
    def enterCall(self, ctx:ExplorerScriptParser.CallContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#call.
    def exitCall(self, ctx:ExplorerScriptParser.CallContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#macro_call.
    def enterMacro_call(self, ctx:ExplorerScriptParser.Macro_callContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#macro_call.
    def exitMacro_call(self, ctx:ExplorerScriptParser.Macro_callContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#ctx_block.
    def enterCtx_block(self, ctx:ExplorerScriptParser.Ctx_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#ctx_block.
    def exitCtx_block(self, ctx:ExplorerScriptParser.Ctx_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#ctx_header.
    def enterCtx_header(self, ctx:ExplorerScriptParser.Ctx_headerContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#ctx_header.
    def exitCtx_header(self, ctx:ExplorerScriptParser.Ctx_headerContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#if_block.
    def enterIf_block(self, ctx:ExplorerScriptParser.If_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#if_block.
    def exitIf_block(self, ctx:ExplorerScriptParser.If_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#elseif_block.
    def enterElseif_block(self, ctx:ExplorerScriptParser.Elseif_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#elseif_block.
    def exitElseif_block(self, ctx:ExplorerScriptParser.Elseif_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#else_block.
    def enterElse_block(self, ctx:ExplorerScriptParser.Else_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#else_block.
    def exitElse_block(self, ctx:ExplorerScriptParser.Else_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#if_header.
    def enterIf_header(self, ctx:ExplorerScriptParser.If_headerContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#if_header.
    def exitIf_header(self, ctx:ExplorerScriptParser.If_headerContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#if_h_negatable.
    def enterIf_h_negatable(self, ctx:ExplorerScriptParser.If_h_negatableContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#if_h_negatable.
    def exitIf_h_negatable(self, ctx:ExplorerScriptParser.If_h_negatableContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#if_h_op.
    def enterIf_h_op(self, ctx:ExplorerScriptParser.If_h_opContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#if_h_op.
    def exitIf_h_op(self, ctx:ExplorerScriptParser.If_h_opContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#if_h_bit.
    def enterIf_h_bit(self, ctx:ExplorerScriptParser.If_h_bitContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#if_h_bit.
    def exitIf_h_bit(self, ctx:ExplorerScriptParser.If_h_bitContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#if_h_scn.
    def enterIf_h_scn(self, ctx:ExplorerScriptParser.If_h_scnContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#if_h_scn.
    def exitIf_h_scn(self, ctx:ExplorerScriptParser.If_h_scnContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#switch_block.
    def enterSwitch_block(self, ctx:ExplorerScriptParser.Switch_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#switch_block.
    def exitSwitch_block(self, ctx:ExplorerScriptParser.Switch_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#message_switch_block.
    def enterMessage_switch_block(self, ctx:ExplorerScriptParser.Message_switch_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#message_switch_block.
    def exitMessage_switch_block(self, ctx:ExplorerScriptParser.Message_switch_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#single_case_block.
    def enterSingle_case_block(self, ctx:ExplorerScriptParser.Single_case_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#single_case_block.
    def exitSingle_case_block(self, ctx:ExplorerScriptParser.Single_case_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#default.
    def enterDefault(self, ctx:ExplorerScriptParser.DefaultContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#default.
    def exitDefault(self, ctx:ExplorerScriptParser.DefaultContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#switch_header.
    def enterSwitch_header(self, ctx:ExplorerScriptParser.Switch_headerContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#switch_header.
    def exitSwitch_header(self, ctx:ExplorerScriptParser.Switch_headerContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#switch_h_scn.
    def enterSwitch_h_scn(self, ctx:ExplorerScriptParser.Switch_h_scnContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#switch_h_scn.
    def exitSwitch_h_scn(self, ctx:ExplorerScriptParser.Switch_h_scnContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#switch_h_random.
    def enterSwitch_h_random(self, ctx:ExplorerScriptParser.Switch_h_randomContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#switch_h_random.
    def exitSwitch_h_random(self, ctx:ExplorerScriptParser.Switch_h_randomContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#switch_h_dungeon_mode.
    def enterSwitch_h_dungeon_mode(self, ctx:ExplorerScriptParser.Switch_h_dungeon_modeContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#switch_h_dungeon_mode.
    def exitSwitch_h_dungeon_mode(self, ctx:ExplorerScriptParser.Switch_h_dungeon_modeContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#switch_h_sector.
    def enterSwitch_h_sector(self, ctx:ExplorerScriptParser.Switch_h_sectorContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#switch_h_sector.
    def exitSwitch_h_sector(self, ctx:ExplorerScriptParser.Switch_h_sectorContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#case_header.
    def enterCase_header(self, ctx:ExplorerScriptParser.Case_headerContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#case_header.
    def exitCase_header(self, ctx:ExplorerScriptParser.Case_headerContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#case_h_menu.
    def enterCase_h_menu(self, ctx:ExplorerScriptParser.Case_h_menuContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#case_h_menu.
    def exitCase_h_menu(self, ctx:ExplorerScriptParser.Case_h_menuContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#case_h_menu2.
    def enterCase_h_menu2(self, ctx:ExplorerScriptParser.Case_h_menu2Context):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#case_h_menu2.
    def exitCase_h_menu2(self, ctx:ExplorerScriptParser.Case_h_menu2Context):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#case_h_op.
    def enterCase_h_op(self, ctx:ExplorerScriptParser.Case_h_opContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#case_h_op.
    def exitCase_h_op(self, ctx:ExplorerScriptParser.Case_h_opContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#forever_block.
    def enterForever_block(self, ctx:ExplorerScriptParser.Forever_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#forever_block.
    def exitForever_block(self, ctx:ExplorerScriptParser.Forever_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#for_block.
    def enterFor_block(self, ctx:ExplorerScriptParser.For_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#for_block.
    def exitFor_block(self, ctx:ExplorerScriptParser.For_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#while_block.
    def enterWhile_block(self, ctx:ExplorerScriptParser.While_blockContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#while_block.
    def exitWhile_block(self, ctx:ExplorerScriptParser.While_blockContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#assignment.
    def enterAssignment(self, ctx:ExplorerScriptParser.AssignmentContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#assignment.
    def exitAssignment(self, ctx:ExplorerScriptParser.AssignmentContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#assignment_regular.
    def enterAssignment_regular(self, ctx:ExplorerScriptParser.Assignment_regularContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#assignment_regular.
    def exitAssignment_regular(self, ctx:ExplorerScriptParser.Assignment_regularContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#assignment_clear.
    def enterAssignment_clear(self, ctx:ExplorerScriptParser.Assignment_clearContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#assignment_clear.
    def exitAssignment_clear(self, ctx:ExplorerScriptParser.Assignment_clearContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#assignment_initial.
    def enterAssignment_initial(self, ctx:ExplorerScriptParser.Assignment_initialContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#assignment_initial.
    def exitAssignment_initial(self, ctx:ExplorerScriptParser.Assignment_initialContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#assignment_reset.
    def enterAssignment_reset(self, ctx:ExplorerScriptParser.Assignment_resetContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#assignment_reset.
    def exitAssignment_reset(self, ctx:ExplorerScriptParser.Assignment_resetContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#assignment_adv_log.
    def enterAssignment_adv_log(self, ctx:ExplorerScriptParser.Assignment_adv_logContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#assignment_adv_log.
    def exitAssignment_adv_log(self, ctx:ExplorerScriptParser.Assignment_adv_logContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#assignment_dungeon_mode.
    def enterAssignment_dungeon_mode(self, ctx:ExplorerScriptParser.Assignment_dungeon_modeContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#assignment_dungeon_mode.
    def exitAssignment_dungeon_mode(self, ctx:ExplorerScriptParser.Assignment_dungeon_modeContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#assignment_scn.
    def enterAssignment_scn(self, ctx:ExplorerScriptParser.Assignment_scnContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#assignment_scn.
    def exitAssignment_scn(self, ctx:ExplorerScriptParser.Assignment_scnContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#value_of.
    def enterValue_of(self, ctx:ExplorerScriptParser.Value_ofContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#value_of.
    def exitValue_of(self, ctx:ExplorerScriptParser.Value_ofContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#scn_var.
    def enterScn_var(self, ctx:ExplorerScriptParser.Scn_varContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#scn_var.
    def exitScn_var(self, ctx:ExplorerScriptParser.Scn_varContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#conditional_operator.
    def enterConditional_operator(self, ctx:ExplorerScriptParser.Conditional_operatorContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#conditional_operator.
    def exitConditional_operator(self, ctx:ExplorerScriptParser.Conditional_operatorContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#assign_operator.
    def enterAssign_operator(self, ctx:ExplorerScriptParser.Assign_operatorContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#assign_operator.
    def exitAssign_operator(self, ctx:ExplorerScriptParser.Assign_operatorContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#funcdef.
    def enterFuncdef(self, ctx:ExplorerScriptParser.FuncdefContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#funcdef.
    def exitFuncdef(self, ctx:ExplorerScriptParser.FuncdefContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#simple_def.
    def enterSimple_def(self, ctx:ExplorerScriptParser.Simple_defContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#simple_def.
    def exitSimple_def(self, ctx:ExplorerScriptParser.Simple_defContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#coro_def.
    def enterCoro_def(self, ctx:ExplorerScriptParser.Coro_defContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#coro_def.
    def exitCoro_def(self, ctx:ExplorerScriptParser.Coro_defContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#for_target_def.
    def enterFor_target_def(self, ctx:ExplorerScriptParser.For_target_defContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#for_target_def.
    def exitFor_target_def(self, ctx:ExplorerScriptParser.For_target_defContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#integer_like.
    def enterInteger_like(self, ctx:ExplorerScriptParser.Integer_likeContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#integer_like.
    def exitInteger_like(self, ctx:ExplorerScriptParser.Integer_likeContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#operation.
    def enterOperation(self, ctx:ExplorerScriptParser.OperationContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#operation.
    def exitOperation(self, ctx:ExplorerScriptParser.OperationContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#func_suite.
    def enterFunc_suite(self, ctx:ExplorerScriptParser.Func_suiteContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#func_suite.
    def exitFunc_suite(self, ctx:ExplorerScriptParser.Func_suiteContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#func_alias.
    def enterFunc_alias(self, ctx:ExplorerScriptParser.Func_aliasContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#func_alias.
    def exitFunc_alias(self, ctx:ExplorerScriptParser.Func_aliasContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#arglist.
    def enterArglist(self, ctx:ExplorerScriptParser.ArglistContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#arglist.
    def exitArglist(self, ctx:ExplorerScriptParser.ArglistContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#pos_argument.
    def enterPos_argument(self, ctx:ExplorerScriptParser.Pos_argumentContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#pos_argument.
    def exitPos_argument(self, ctx:ExplorerScriptParser.Pos_argumentContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#position_marker.
    def enterPosition_marker(self, ctx:ExplorerScriptParser.Position_markerContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#position_marker.
    def exitPosition_marker(self, ctx:ExplorerScriptParser.Position_markerContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#position_marker_arg.
    def enterPosition_marker_arg(self, ctx:ExplorerScriptParser.Position_marker_argContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#position_marker_arg.
    def exitPosition_marker_arg(self, ctx:ExplorerScriptParser.Position_marker_argContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#label.
    def enterLabel(self, ctx:ExplorerScriptParser.LabelContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#label.
    def exitLabel(self, ctx:ExplorerScriptParser.LabelContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#string.
    def enterString(self, ctx:ExplorerScriptParser.StringContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#string.
    def exitString(self, ctx:ExplorerScriptParser.StringContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#lang_string.
    def enterLang_string(self, ctx:ExplorerScriptParser.Lang_stringContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#lang_string.
    def exitLang_string(self, ctx:ExplorerScriptParser.Lang_stringContext):
        pass


    # Enter a parse tree produced by ExplorerScriptParser#lang_string_argument.
    def enterLang_string_argument(self, ctx:ExplorerScriptParser.Lang_string_argumentContext):
        pass

    # Exit a parse tree produced by ExplorerScriptParser#lang_string_argument.
    def exitLang_string_argument(self, ctx:ExplorerScriptParser.Lang_string_argumentContext):
        pass



del ExplorerScriptParser