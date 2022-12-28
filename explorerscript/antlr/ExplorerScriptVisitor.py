# Generated from ExplorerScript.g4 by ANTLR 4.11.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .ExplorerScriptParser import ExplorerScriptParser
else:
    from ExplorerScriptParser import ExplorerScriptParser

# This class defines a complete generic visitor for a parse tree produced by ExplorerScriptParser.

class ExplorerScriptVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by ExplorerScriptParser#start.
    def visitStart(self, ctx:ExplorerScriptParser.StartContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#import_stmt.
    def visitImport_stmt(self, ctx:ExplorerScriptParser.Import_stmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#macrodef.
    def visitMacrodef(self, ctx:ExplorerScriptParser.MacrodefContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#stmt.
    def visitStmt(self, ctx:ExplorerScriptParser.StmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#simple_stmt.
    def visitSimple_stmt(self, ctx:ExplorerScriptParser.Simple_stmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#cntrl_stmt.
    def visitCntrl_stmt(self, ctx:ExplorerScriptParser.Cntrl_stmtContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#jump.
    def visitJump(self, ctx:ExplorerScriptParser.JumpContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#call.
    def visitCall(self, ctx:ExplorerScriptParser.CallContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#macro_call.
    def visitMacro_call(self, ctx:ExplorerScriptParser.Macro_callContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#ctx_block.
    def visitCtx_block(self, ctx:ExplorerScriptParser.Ctx_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#ctx_header.
    def visitCtx_header(self, ctx:ExplorerScriptParser.Ctx_headerContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#if_block.
    def visitIf_block(self, ctx:ExplorerScriptParser.If_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#elseif_block.
    def visitElseif_block(self, ctx:ExplorerScriptParser.Elseif_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#else_block.
    def visitElse_block(self, ctx:ExplorerScriptParser.Else_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#if_header.
    def visitIf_header(self, ctx:ExplorerScriptParser.If_headerContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#if_h_negatable.
    def visitIf_h_negatable(self, ctx:ExplorerScriptParser.If_h_negatableContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#if_h_op.
    def visitIf_h_op(self, ctx:ExplorerScriptParser.If_h_opContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#if_h_bit.
    def visitIf_h_bit(self, ctx:ExplorerScriptParser.If_h_bitContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#if_h_scn.
    def visitIf_h_scn(self, ctx:ExplorerScriptParser.If_h_scnContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#switch_block.
    def visitSwitch_block(self, ctx:ExplorerScriptParser.Switch_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#message_switch_block.
    def visitMessage_switch_block(self, ctx:ExplorerScriptParser.Message_switch_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#single_case_block.
    def visitSingle_case_block(self, ctx:ExplorerScriptParser.Single_case_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#default.
    def visitDefault(self, ctx:ExplorerScriptParser.DefaultContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#switch_header.
    def visitSwitch_header(self, ctx:ExplorerScriptParser.Switch_headerContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#switch_h_scn.
    def visitSwitch_h_scn(self, ctx:ExplorerScriptParser.Switch_h_scnContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#switch_h_random.
    def visitSwitch_h_random(self, ctx:ExplorerScriptParser.Switch_h_randomContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#switch_h_dungeon_mode.
    def visitSwitch_h_dungeon_mode(self, ctx:ExplorerScriptParser.Switch_h_dungeon_modeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#switch_h_sector.
    def visitSwitch_h_sector(self, ctx:ExplorerScriptParser.Switch_h_sectorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#case_header.
    def visitCase_header(self, ctx:ExplorerScriptParser.Case_headerContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#case_h_menu.
    def visitCase_h_menu(self, ctx:ExplorerScriptParser.Case_h_menuContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#case_h_menu2.
    def visitCase_h_menu2(self, ctx:ExplorerScriptParser.Case_h_menu2Context):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#case_h_op.
    def visitCase_h_op(self, ctx:ExplorerScriptParser.Case_h_opContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#forever_block.
    def visitForever_block(self, ctx:ExplorerScriptParser.Forever_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#for_block.
    def visitFor_block(self, ctx:ExplorerScriptParser.For_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#while_block.
    def visitWhile_block(self, ctx:ExplorerScriptParser.While_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#assignment.
    def visitAssignment(self, ctx:ExplorerScriptParser.AssignmentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#assignment_regular.
    def visitAssignment_regular(self, ctx:ExplorerScriptParser.Assignment_regularContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#assignment_clear.
    def visitAssignment_clear(self, ctx:ExplorerScriptParser.Assignment_clearContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#assignment_initial.
    def visitAssignment_initial(self, ctx:ExplorerScriptParser.Assignment_initialContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#assignment_reset.
    def visitAssignment_reset(self, ctx:ExplorerScriptParser.Assignment_resetContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#assignment_adv_log.
    def visitAssignment_adv_log(self, ctx:ExplorerScriptParser.Assignment_adv_logContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#assignment_dungeon_mode.
    def visitAssignment_dungeon_mode(self, ctx:ExplorerScriptParser.Assignment_dungeon_modeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#assignment_scn.
    def visitAssignment_scn(self, ctx:ExplorerScriptParser.Assignment_scnContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#value_of.
    def visitValue_of(self, ctx:ExplorerScriptParser.Value_ofContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#scn_var.
    def visitScn_var(self, ctx:ExplorerScriptParser.Scn_varContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#conditional_operator.
    def visitConditional_operator(self, ctx:ExplorerScriptParser.Conditional_operatorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#assign_operator.
    def visitAssign_operator(self, ctx:ExplorerScriptParser.Assign_operatorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#funcdef.
    def visitFuncdef(self, ctx:ExplorerScriptParser.FuncdefContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#simple_def.
    def visitSimple_def(self, ctx:ExplorerScriptParser.Simple_defContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#coro_def.
    def visitCoro_def(self, ctx:ExplorerScriptParser.Coro_defContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#for_target_def.
    def visitFor_target_def(self, ctx:ExplorerScriptParser.For_target_defContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#integer_like.
    def visitInteger_like(self, ctx:ExplorerScriptParser.Integer_likeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#operation.
    def visitOperation(self, ctx:ExplorerScriptParser.OperationContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#func_suite.
    def visitFunc_suite(self, ctx:ExplorerScriptParser.Func_suiteContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#func_alias.
    def visitFunc_alias(self, ctx:ExplorerScriptParser.Func_aliasContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#arglist.
    def visitArglist(self, ctx:ExplorerScriptParser.ArglistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#pos_argument.
    def visitPos_argument(self, ctx:ExplorerScriptParser.Pos_argumentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#position_marker.
    def visitPosition_marker(self, ctx:ExplorerScriptParser.Position_markerContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#position_marker_arg.
    def visitPosition_marker_arg(self, ctx:ExplorerScriptParser.Position_marker_argContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#label.
    def visitLabel(self, ctx:ExplorerScriptParser.LabelContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#string.
    def visitString(self, ctx:ExplorerScriptParser.StringContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#lang_string.
    def visitLang_string(self, ctx:ExplorerScriptParser.Lang_stringContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ExplorerScriptParser#lang_string_argument.
    def visitLang_string_argument(self, ctx:ExplorerScriptParser.Lang_string_argumentContext):
        return self.visitChildren(ctx)



del ExplorerScriptParser