
// Generated from ExplorerScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ExplorerScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExplorerScriptParser.
 */
class  ExplorerScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExplorerScriptParser.
   */
    virtual std::any visitStart(ExplorerScriptParser::StartContext *context) = 0;

    virtual std::any visitImport_stmt(ExplorerScriptParser::Import_stmtContext *context) = 0;

    virtual std::any visitConstant_assign(ExplorerScriptParser::Constant_assignContext *context) = 0;

    virtual std::any visitMacrodef(ExplorerScriptParser::MacrodefContext *context) = 0;

    virtual std::any visitStmt(ExplorerScriptParser::StmtContext *context) = 0;

    virtual std::any visitSimple_stmt(ExplorerScriptParser::Simple_stmtContext *context) = 0;

    virtual std::any visitCntrl_stmt(ExplorerScriptParser::Cntrl_stmtContext *context) = 0;

    virtual std::any visitJump(ExplorerScriptParser::JumpContext *context) = 0;

    virtual std::any visitCall(ExplorerScriptParser::CallContext *context) = 0;

    virtual std::any visitMacro_call(ExplorerScriptParser::Macro_callContext *context) = 0;

    virtual std::any visitCtx_block(ExplorerScriptParser::Ctx_blockContext *context) = 0;

    virtual std::any visitIf_block(ExplorerScriptParser::If_blockContext *context) = 0;

    virtual std::any visitElseif_block(ExplorerScriptParser::Elseif_blockContext *context) = 0;

    virtual std::any visitElse_block(ExplorerScriptParser::Else_blockContext *context) = 0;

    virtual std::any visitIf_header(ExplorerScriptParser::If_headerContext *context) = 0;

    virtual std::any visitIf_h_negatable(ExplorerScriptParser::If_h_negatableContext *context) = 0;

    virtual std::any visitIf_h_op(ExplorerScriptParser::If_h_opContext *context) = 0;

    virtual std::any visitIf_h_bit(ExplorerScriptParser::If_h_bitContext *context) = 0;

    virtual std::any visitIf_h_scn(ExplorerScriptParser::If_h_scnContext *context) = 0;

    virtual std::any visitSwitch_block(ExplorerScriptParser::Switch_blockContext *context) = 0;

    virtual std::any visitMessage_switch_block(ExplorerScriptParser::Message_switch_blockContext *context) = 0;

    virtual std::any visitSingle_case_block(ExplorerScriptParser::Single_case_blockContext *context) = 0;

    virtual std::any visitDefault(ExplorerScriptParser::DefaultContext *context) = 0;

    virtual std::any visitSwitch_header(ExplorerScriptParser::Switch_headerContext *context) = 0;

    virtual std::any visitSwitch_h_scn(ExplorerScriptParser::Switch_h_scnContext *context) = 0;

    virtual std::any visitSwitch_h_random(ExplorerScriptParser::Switch_h_randomContext *context) = 0;

    virtual std::any visitSwitch_h_dungeon_mode(ExplorerScriptParser::Switch_h_dungeon_modeContext *context) = 0;

    virtual std::any visitSwitch_h_sector(ExplorerScriptParser::Switch_h_sectorContext *context) = 0;

    virtual std::any visitCase_header(ExplorerScriptParser::Case_headerContext *context) = 0;

    virtual std::any visitCase_h_menu(ExplorerScriptParser::Case_h_menuContext *context) = 0;

    virtual std::any visitCase_h_menu2(ExplorerScriptParser::Case_h_menu2Context *context) = 0;

    virtual std::any visitCase_h_op(ExplorerScriptParser::Case_h_opContext *context) = 0;

    virtual std::any visitForever_block(ExplorerScriptParser::Forever_blockContext *context) = 0;

    virtual std::any visitFor_block(ExplorerScriptParser::For_blockContext *context) = 0;

    virtual std::any visitWhile_block(ExplorerScriptParser::While_blockContext *context) = 0;

    virtual std::any visitAssignment(ExplorerScriptParser::AssignmentContext *context) = 0;

    virtual std::any visitAssignment_regular(ExplorerScriptParser::Assignment_regularContext *context) = 0;

    virtual std::any visitAssignment_clear(ExplorerScriptParser::Assignment_clearContext *context) = 0;

    virtual std::any visitAssignment_initial(ExplorerScriptParser::Assignment_initialContext *context) = 0;

    virtual std::any visitAssignment_reset(ExplorerScriptParser::Assignment_resetContext *context) = 0;

    virtual std::any visitAssignment_adv_log(ExplorerScriptParser::Assignment_adv_logContext *context) = 0;

    virtual std::any visitAssignment_dungeon_mode(ExplorerScriptParser::Assignment_dungeon_modeContext *context) = 0;

    virtual std::any visitAssignment_scn(ExplorerScriptParser::Assignment_scnContext *context) = 0;

    virtual std::any visitValue_of(ExplorerScriptParser::Value_ofContext *context) = 0;

    virtual std::any visitScn_var(ExplorerScriptParser::Scn_varContext *context) = 0;

    virtual std::any visitConditional_operator(ExplorerScriptParser::Conditional_operatorContext *context) = 0;

    virtual std::any visitAssign_operator(ExplorerScriptParser::Assign_operatorContext *context) = 0;

    virtual std::any visitFuncdef(ExplorerScriptParser::FuncdefContext *context) = 0;

    virtual std::any visitSimple_def(ExplorerScriptParser::Simple_defContext *context) = 0;

    virtual std::any visitCoro_def(ExplorerScriptParser::Coro_defContext *context) = 0;

    virtual std::any visitFor_target_def(ExplorerScriptParser::For_target_defContext *context) = 0;

    virtual std::any visitPrimitive(ExplorerScriptParser::PrimitiveContext *context) = 0;

    virtual std::any visitOperation(ExplorerScriptParser::OperationContext *context) = 0;

    virtual std::any visitInline_ctx(ExplorerScriptParser::Inline_ctxContext *context) = 0;

    virtual std::any visitFunc_suite(ExplorerScriptParser::Func_suiteContext *context) = 0;

    virtual std::any visitFunc_alias(ExplorerScriptParser::Func_aliasContext *context) = 0;

    virtual std::any visitArglist(ExplorerScriptParser::ArglistContext *context) = 0;

    virtual std::any visitPos_argument(ExplorerScriptParser::Pos_argumentContext *context) = 0;

    virtual std::any visitPosition_marker(ExplorerScriptParser::Position_markerContext *context) = 0;

    virtual std::any visitPosition_marker_arg(ExplorerScriptParser::Position_marker_argContext *context) = 0;

    virtual std::any visitLabel(ExplorerScriptParser::LabelContext *context) = 0;

    virtual std::any visitString(ExplorerScriptParser::StringContext *context) = 0;

    virtual std::any visitLang_string(ExplorerScriptParser::Lang_stringContext *context) = 0;

    virtual std::any visitLang_string_argument(ExplorerScriptParser::Lang_string_argumentContext *context) = 0;

    virtual std::any visitString_value(ExplorerScriptParser::String_valueContext *context) = 0;

    virtual std::any visitCtx_header(ExplorerScriptParser::Ctx_headerContext *context) = 0;

    virtual std::any visitFor_target_def_target(ExplorerScriptParser::For_target_def_targetContext *context) = 0;


};

