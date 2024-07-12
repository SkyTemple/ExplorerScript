
// Generated from ExplorerScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ExplorerScriptParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ExplorerScriptParser.
 */
class  ExplorerScriptListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(ExplorerScriptParser::StartContext *ctx) = 0;
  virtual void exitStart(ExplorerScriptParser::StartContext *ctx) = 0;

  virtual void enterImport_stmt(ExplorerScriptParser::Import_stmtContext *ctx) = 0;
  virtual void exitImport_stmt(ExplorerScriptParser::Import_stmtContext *ctx) = 0;

  virtual void enterMacrodef(ExplorerScriptParser::MacrodefContext *ctx) = 0;
  virtual void exitMacrodef(ExplorerScriptParser::MacrodefContext *ctx) = 0;

  virtual void enterStmt(ExplorerScriptParser::StmtContext *ctx) = 0;
  virtual void exitStmt(ExplorerScriptParser::StmtContext *ctx) = 0;

  virtual void enterSimple_stmt(ExplorerScriptParser::Simple_stmtContext *ctx) = 0;
  virtual void exitSimple_stmt(ExplorerScriptParser::Simple_stmtContext *ctx) = 0;

  virtual void enterCntrl_stmt(ExplorerScriptParser::Cntrl_stmtContext *ctx) = 0;
  virtual void exitCntrl_stmt(ExplorerScriptParser::Cntrl_stmtContext *ctx) = 0;

  virtual void enterJump(ExplorerScriptParser::JumpContext *ctx) = 0;
  virtual void exitJump(ExplorerScriptParser::JumpContext *ctx) = 0;

  virtual void enterCall(ExplorerScriptParser::CallContext *ctx) = 0;
  virtual void exitCall(ExplorerScriptParser::CallContext *ctx) = 0;

  virtual void enterMacro_call(ExplorerScriptParser::Macro_callContext *ctx) = 0;
  virtual void exitMacro_call(ExplorerScriptParser::Macro_callContext *ctx) = 0;

  virtual void enterCtx_block(ExplorerScriptParser::Ctx_blockContext *ctx) = 0;
  virtual void exitCtx_block(ExplorerScriptParser::Ctx_blockContext *ctx) = 0;

  virtual void enterIf_block(ExplorerScriptParser::If_blockContext *ctx) = 0;
  virtual void exitIf_block(ExplorerScriptParser::If_blockContext *ctx) = 0;

  virtual void enterElseif_block(ExplorerScriptParser::Elseif_blockContext *ctx) = 0;
  virtual void exitElseif_block(ExplorerScriptParser::Elseif_blockContext *ctx) = 0;

  virtual void enterElse_block(ExplorerScriptParser::Else_blockContext *ctx) = 0;
  virtual void exitElse_block(ExplorerScriptParser::Else_blockContext *ctx) = 0;

  virtual void enterIf_header(ExplorerScriptParser::If_headerContext *ctx) = 0;
  virtual void exitIf_header(ExplorerScriptParser::If_headerContext *ctx) = 0;

  virtual void enterIf_h_negatable(ExplorerScriptParser::If_h_negatableContext *ctx) = 0;
  virtual void exitIf_h_negatable(ExplorerScriptParser::If_h_negatableContext *ctx) = 0;

  virtual void enterIf_h_op(ExplorerScriptParser::If_h_opContext *ctx) = 0;
  virtual void exitIf_h_op(ExplorerScriptParser::If_h_opContext *ctx) = 0;

  virtual void enterIf_h_bit(ExplorerScriptParser::If_h_bitContext *ctx) = 0;
  virtual void exitIf_h_bit(ExplorerScriptParser::If_h_bitContext *ctx) = 0;

  virtual void enterIf_h_scn(ExplorerScriptParser::If_h_scnContext *ctx) = 0;
  virtual void exitIf_h_scn(ExplorerScriptParser::If_h_scnContext *ctx) = 0;

  virtual void enterSwitch_block(ExplorerScriptParser::Switch_blockContext *ctx) = 0;
  virtual void exitSwitch_block(ExplorerScriptParser::Switch_blockContext *ctx) = 0;

  virtual void enterMessage_switch_block(ExplorerScriptParser::Message_switch_blockContext *ctx) = 0;
  virtual void exitMessage_switch_block(ExplorerScriptParser::Message_switch_blockContext *ctx) = 0;

  virtual void enterSingle_case_block(ExplorerScriptParser::Single_case_blockContext *ctx) = 0;
  virtual void exitSingle_case_block(ExplorerScriptParser::Single_case_blockContext *ctx) = 0;

  virtual void enterDefault(ExplorerScriptParser::DefaultContext *ctx) = 0;
  virtual void exitDefault(ExplorerScriptParser::DefaultContext *ctx) = 0;

  virtual void enterSwitch_header(ExplorerScriptParser::Switch_headerContext *ctx) = 0;
  virtual void exitSwitch_header(ExplorerScriptParser::Switch_headerContext *ctx) = 0;

  virtual void enterSwitch_h_scn(ExplorerScriptParser::Switch_h_scnContext *ctx) = 0;
  virtual void exitSwitch_h_scn(ExplorerScriptParser::Switch_h_scnContext *ctx) = 0;

  virtual void enterSwitch_h_random(ExplorerScriptParser::Switch_h_randomContext *ctx) = 0;
  virtual void exitSwitch_h_random(ExplorerScriptParser::Switch_h_randomContext *ctx) = 0;

  virtual void enterSwitch_h_dungeon_mode(ExplorerScriptParser::Switch_h_dungeon_modeContext *ctx) = 0;
  virtual void exitSwitch_h_dungeon_mode(ExplorerScriptParser::Switch_h_dungeon_modeContext *ctx) = 0;

  virtual void enterSwitch_h_sector(ExplorerScriptParser::Switch_h_sectorContext *ctx) = 0;
  virtual void exitSwitch_h_sector(ExplorerScriptParser::Switch_h_sectorContext *ctx) = 0;

  virtual void enterCase_header(ExplorerScriptParser::Case_headerContext *ctx) = 0;
  virtual void exitCase_header(ExplorerScriptParser::Case_headerContext *ctx) = 0;

  virtual void enterCase_h_menu(ExplorerScriptParser::Case_h_menuContext *ctx) = 0;
  virtual void exitCase_h_menu(ExplorerScriptParser::Case_h_menuContext *ctx) = 0;

  virtual void enterCase_h_menu2(ExplorerScriptParser::Case_h_menu2Context *ctx) = 0;
  virtual void exitCase_h_menu2(ExplorerScriptParser::Case_h_menu2Context *ctx) = 0;

  virtual void enterCase_h_op(ExplorerScriptParser::Case_h_opContext *ctx) = 0;
  virtual void exitCase_h_op(ExplorerScriptParser::Case_h_opContext *ctx) = 0;

  virtual void enterForever_block(ExplorerScriptParser::Forever_blockContext *ctx) = 0;
  virtual void exitForever_block(ExplorerScriptParser::Forever_blockContext *ctx) = 0;

  virtual void enterFor_block(ExplorerScriptParser::For_blockContext *ctx) = 0;
  virtual void exitFor_block(ExplorerScriptParser::For_blockContext *ctx) = 0;

  virtual void enterWhile_block(ExplorerScriptParser::While_blockContext *ctx) = 0;
  virtual void exitWhile_block(ExplorerScriptParser::While_blockContext *ctx) = 0;

  virtual void enterAssignment(ExplorerScriptParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(ExplorerScriptParser::AssignmentContext *ctx) = 0;

  virtual void enterAssignment_regular(ExplorerScriptParser::Assignment_regularContext *ctx) = 0;
  virtual void exitAssignment_regular(ExplorerScriptParser::Assignment_regularContext *ctx) = 0;

  virtual void enterAssignment_clear(ExplorerScriptParser::Assignment_clearContext *ctx) = 0;
  virtual void exitAssignment_clear(ExplorerScriptParser::Assignment_clearContext *ctx) = 0;

  virtual void enterAssignment_initial(ExplorerScriptParser::Assignment_initialContext *ctx) = 0;
  virtual void exitAssignment_initial(ExplorerScriptParser::Assignment_initialContext *ctx) = 0;

  virtual void enterAssignment_reset(ExplorerScriptParser::Assignment_resetContext *ctx) = 0;
  virtual void exitAssignment_reset(ExplorerScriptParser::Assignment_resetContext *ctx) = 0;

  virtual void enterAssignment_adv_log(ExplorerScriptParser::Assignment_adv_logContext *ctx) = 0;
  virtual void exitAssignment_adv_log(ExplorerScriptParser::Assignment_adv_logContext *ctx) = 0;

  virtual void enterAssignment_dungeon_mode(ExplorerScriptParser::Assignment_dungeon_modeContext *ctx) = 0;
  virtual void exitAssignment_dungeon_mode(ExplorerScriptParser::Assignment_dungeon_modeContext *ctx) = 0;

  virtual void enterAssignment_scn(ExplorerScriptParser::Assignment_scnContext *ctx) = 0;
  virtual void exitAssignment_scn(ExplorerScriptParser::Assignment_scnContext *ctx) = 0;

  virtual void enterValue_of(ExplorerScriptParser::Value_ofContext *ctx) = 0;
  virtual void exitValue_of(ExplorerScriptParser::Value_ofContext *ctx) = 0;

  virtual void enterScn_var(ExplorerScriptParser::Scn_varContext *ctx) = 0;
  virtual void exitScn_var(ExplorerScriptParser::Scn_varContext *ctx) = 0;

  virtual void enterConditional_operator(ExplorerScriptParser::Conditional_operatorContext *ctx) = 0;
  virtual void exitConditional_operator(ExplorerScriptParser::Conditional_operatorContext *ctx) = 0;

  virtual void enterAssign_operator(ExplorerScriptParser::Assign_operatorContext *ctx) = 0;
  virtual void exitAssign_operator(ExplorerScriptParser::Assign_operatorContext *ctx) = 0;

  virtual void enterFuncdef(ExplorerScriptParser::FuncdefContext *ctx) = 0;
  virtual void exitFuncdef(ExplorerScriptParser::FuncdefContext *ctx) = 0;

  virtual void enterSimple_def(ExplorerScriptParser::Simple_defContext *ctx) = 0;
  virtual void exitSimple_def(ExplorerScriptParser::Simple_defContext *ctx) = 0;

  virtual void enterCoro_def(ExplorerScriptParser::Coro_defContext *ctx) = 0;
  virtual void exitCoro_def(ExplorerScriptParser::Coro_defContext *ctx) = 0;

  virtual void enterFor_target_def(ExplorerScriptParser::For_target_defContext *ctx) = 0;
  virtual void exitFor_target_def(ExplorerScriptParser::For_target_defContext *ctx) = 0;

  virtual void enterInteger_like(ExplorerScriptParser::Integer_likeContext *ctx) = 0;
  virtual void exitInteger_like(ExplorerScriptParser::Integer_likeContext *ctx) = 0;

  virtual void enterOperation(ExplorerScriptParser::OperationContext *ctx) = 0;
  virtual void exitOperation(ExplorerScriptParser::OperationContext *ctx) = 0;

  virtual void enterInline_ctx(ExplorerScriptParser::Inline_ctxContext *ctx) = 0;
  virtual void exitInline_ctx(ExplorerScriptParser::Inline_ctxContext *ctx) = 0;

  virtual void enterFunc_suite(ExplorerScriptParser::Func_suiteContext *ctx) = 0;
  virtual void exitFunc_suite(ExplorerScriptParser::Func_suiteContext *ctx) = 0;

  virtual void enterFunc_alias(ExplorerScriptParser::Func_aliasContext *ctx) = 0;
  virtual void exitFunc_alias(ExplorerScriptParser::Func_aliasContext *ctx) = 0;

  virtual void enterArglist(ExplorerScriptParser::ArglistContext *ctx) = 0;
  virtual void exitArglist(ExplorerScriptParser::ArglistContext *ctx) = 0;

  virtual void enterPos_argument(ExplorerScriptParser::Pos_argumentContext *ctx) = 0;
  virtual void exitPos_argument(ExplorerScriptParser::Pos_argumentContext *ctx) = 0;

  virtual void enterPosition_marker(ExplorerScriptParser::Position_markerContext *ctx) = 0;
  virtual void exitPosition_marker(ExplorerScriptParser::Position_markerContext *ctx) = 0;

  virtual void enterPosition_marker_arg(ExplorerScriptParser::Position_marker_argContext *ctx) = 0;
  virtual void exitPosition_marker_arg(ExplorerScriptParser::Position_marker_argContext *ctx) = 0;

  virtual void enterLabel(ExplorerScriptParser::LabelContext *ctx) = 0;
  virtual void exitLabel(ExplorerScriptParser::LabelContext *ctx) = 0;

  virtual void enterString(ExplorerScriptParser::StringContext *ctx) = 0;
  virtual void exitString(ExplorerScriptParser::StringContext *ctx) = 0;

  virtual void enterLang_string(ExplorerScriptParser::Lang_stringContext *ctx) = 0;
  virtual void exitLang_string(ExplorerScriptParser::Lang_stringContext *ctx) = 0;

  virtual void enterLang_string_argument(ExplorerScriptParser::Lang_string_argumentContext *ctx) = 0;
  virtual void exitLang_string_argument(ExplorerScriptParser::Lang_string_argumentContext *ctx) = 0;

  virtual void enterString_value(ExplorerScriptParser::String_valueContext *ctx) = 0;
  virtual void exitString_value(ExplorerScriptParser::String_valueContext *ctx) = 0;

  virtual void enterCtx_header(ExplorerScriptParser::Ctx_headerContext *ctx) = 0;
  virtual void exitCtx_header(ExplorerScriptParser::Ctx_headerContext *ctx) = 0;

  virtual void enterFor_target_def_target(ExplorerScriptParser::For_target_def_targetContext *ctx) = 0;
  virtual void exitFor_target_def_target(ExplorerScriptParser::For_target_def_targetContext *ctx) = 0;


};

