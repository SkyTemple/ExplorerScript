
// Generated from ExplorerScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "ExplorerScriptListener.h"


/**
 * This class provides an empty implementation of ExplorerScriptListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ExplorerScriptBaseListener : public ExplorerScriptListener {
public:

  virtual void enterStart(ExplorerScriptParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(ExplorerScriptParser::StartContext * /*ctx*/) override { }

  virtual void enterImport_stmt(ExplorerScriptParser::Import_stmtContext * /*ctx*/) override { }
  virtual void exitImport_stmt(ExplorerScriptParser::Import_stmtContext * /*ctx*/) override { }

  virtual void enterMacrodef(ExplorerScriptParser::MacrodefContext * /*ctx*/) override { }
  virtual void exitMacrodef(ExplorerScriptParser::MacrodefContext * /*ctx*/) override { }

  virtual void enterStmt(ExplorerScriptParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(ExplorerScriptParser::StmtContext * /*ctx*/) override { }

  virtual void enterSimple_stmt(ExplorerScriptParser::Simple_stmtContext * /*ctx*/) override { }
  virtual void exitSimple_stmt(ExplorerScriptParser::Simple_stmtContext * /*ctx*/) override { }

  virtual void enterCntrl_stmt(ExplorerScriptParser::Cntrl_stmtContext * /*ctx*/) override { }
  virtual void exitCntrl_stmt(ExplorerScriptParser::Cntrl_stmtContext * /*ctx*/) override { }

  virtual void enterJump(ExplorerScriptParser::JumpContext * /*ctx*/) override { }
  virtual void exitJump(ExplorerScriptParser::JumpContext * /*ctx*/) override { }

  virtual void enterCall(ExplorerScriptParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(ExplorerScriptParser::CallContext * /*ctx*/) override { }

  virtual void enterMacro_call(ExplorerScriptParser::Macro_callContext * /*ctx*/) override { }
  virtual void exitMacro_call(ExplorerScriptParser::Macro_callContext * /*ctx*/) override { }

  virtual void enterCtx_block(ExplorerScriptParser::Ctx_blockContext * /*ctx*/) override { }
  virtual void exitCtx_block(ExplorerScriptParser::Ctx_blockContext * /*ctx*/) override { }

  virtual void enterIf_block(ExplorerScriptParser::If_blockContext * /*ctx*/) override { }
  virtual void exitIf_block(ExplorerScriptParser::If_blockContext * /*ctx*/) override { }

  virtual void enterElseif_block(ExplorerScriptParser::Elseif_blockContext * /*ctx*/) override { }
  virtual void exitElseif_block(ExplorerScriptParser::Elseif_blockContext * /*ctx*/) override { }

  virtual void enterElse_block(ExplorerScriptParser::Else_blockContext * /*ctx*/) override { }
  virtual void exitElse_block(ExplorerScriptParser::Else_blockContext * /*ctx*/) override { }

  virtual void enterIf_header(ExplorerScriptParser::If_headerContext * /*ctx*/) override { }
  virtual void exitIf_header(ExplorerScriptParser::If_headerContext * /*ctx*/) override { }

  virtual void enterIf_h_negatable(ExplorerScriptParser::If_h_negatableContext * /*ctx*/) override { }
  virtual void exitIf_h_negatable(ExplorerScriptParser::If_h_negatableContext * /*ctx*/) override { }

  virtual void enterIf_h_op(ExplorerScriptParser::If_h_opContext * /*ctx*/) override { }
  virtual void exitIf_h_op(ExplorerScriptParser::If_h_opContext * /*ctx*/) override { }

  virtual void enterIf_h_bit(ExplorerScriptParser::If_h_bitContext * /*ctx*/) override { }
  virtual void exitIf_h_bit(ExplorerScriptParser::If_h_bitContext * /*ctx*/) override { }

  virtual void enterIf_h_scn(ExplorerScriptParser::If_h_scnContext * /*ctx*/) override { }
  virtual void exitIf_h_scn(ExplorerScriptParser::If_h_scnContext * /*ctx*/) override { }

  virtual void enterSwitch_block(ExplorerScriptParser::Switch_blockContext * /*ctx*/) override { }
  virtual void exitSwitch_block(ExplorerScriptParser::Switch_blockContext * /*ctx*/) override { }

  virtual void enterMessage_switch_block(ExplorerScriptParser::Message_switch_blockContext * /*ctx*/) override { }
  virtual void exitMessage_switch_block(ExplorerScriptParser::Message_switch_blockContext * /*ctx*/) override { }

  virtual void enterSingle_case_block(ExplorerScriptParser::Single_case_blockContext * /*ctx*/) override { }
  virtual void exitSingle_case_block(ExplorerScriptParser::Single_case_blockContext * /*ctx*/) override { }

  virtual void enterDefault(ExplorerScriptParser::DefaultContext * /*ctx*/) override { }
  virtual void exitDefault(ExplorerScriptParser::DefaultContext * /*ctx*/) override { }

  virtual void enterSwitch_header(ExplorerScriptParser::Switch_headerContext * /*ctx*/) override { }
  virtual void exitSwitch_header(ExplorerScriptParser::Switch_headerContext * /*ctx*/) override { }

  virtual void enterSwitch_h_scn(ExplorerScriptParser::Switch_h_scnContext * /*ctx*/) override { }
  virtual void exitSwitch_h_scn(ExplorerScriptParser::Switch_h_scnContext * /*ctx*/) override { }

  virtual void enterSwitch_h_random(ExplorerScriptParser::Switch_h_randomContext * /*ctx*/) override { }
  virtual void exitSwitch_h_random(ExplorerScriptParser::Switch_h_randomContext * /*ctx*/) override { }

  virtual void enterSwitch_h_dungeon_mode(ExplorerScriptParser::Switch_h_dungeon_modeContext * /*ctx*/) override { }
  virtual void exitSwitch_h_dungeon_mode(ExplorerScriptParser::Switch_h_dungeon_modeContext * /*ctx*/) override { }

  virtual void enterSwitch_h_sector(ExplorerScriptParser::Switch_h_sectorContext * /*ctx*/) override { }
  virtual void exitSwitch_h_sector(ExplorerScriptParser::Switch_h_sectorContext * /*ctx*/) override { }

  virtual void enterCase_header(ExplorerScriptParser::Case_headerContext * /*ctx*/) override { }
  virtual void exitCase_header(ExplorerScriptParser::Case_headerContext * /*ctx*/) override { }

  virtual void enterCase_h_menu(ExplorerScriptParser::Case_h_menuContext * /*ctx*/) override { }
  virtual void exitCase_h_menu(ExplorerScriptParser::Case_h_menuContext * /*ctx*/) override { }

  virtual void enterCase_h_menu2(ExplorerScriptParser::Case_h_menu2Context * /*ctx*/) override { }
  virtual void exitCase_h_menu2(ExplorerScriptParser::Case_h_menu2Context * /*ctx*/) override { }

  virtual void enterCase_h_op(ExplorerScriptParser::Case_h_opContext * /*ctx*/) override { }
  virtual void exitCase_h_op(ExplorerScriptParser::Case_h_opContext * /*ctx*/) override { }

  virtual void enterForever_block(ExplorerScriptParser::Forever_blockContext * /*ctx*/) override { }
  virtual void exitForever_block(ExplorerScriptParser::Forever_blockContext * /*ctx*/) override { }

  virtual void enterFor_block(ExplorerScriptParser::For_blockContext * /*ctx*/) override { }
  virtual void exitFor_block(ExplorerScriptParser::For_blockContext * /*ctx*/) override { }

  virtual void enterWhile_block(ExplorerScriptParser::While_blockContext * /*ctx*/) override { }
  virtual void exitWhile_block(ExplorerScriptParser::While_blockContext * /*ctx*/) override { }

  virtual void enterAssignment(ExplorerScriptParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(ExplorerScriptParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterAssignment_regular(ExplorerScriptParser::Assignment_regularContext * /*ctx*/) override { }
  virtual void exitAssignment_regular(ExplorerScriptParser::Assignment_regularContext * /*ctx*/) override { }

  virtual void enterAssignment_clear(ExplorerScriptParser::Assignment_clearContext * /*ctx*/) override { }
  virtual void exitAssignment_clear(ExplorerScriptParser::Assignment_clearContext * /*ctx*/) override { }

  virtual void enterAssignment_initial(ExplorerScriptParser::Assignment_initialContext * /*ctx*/) override { }
  virtual void exitAssignment_initial(ExplorerScriptParser::Assignment_initialContext * /*ctx*/) override { }

  virtual void enterAssignment_reset(ExplorerScriptParser::Assignment_resetContext * /*ctx*/) override { }
  virtual void exitAssignment_reset(ExplorerScriptParser::Assignment_resetContext * /*ctx*/) override { }

  virtual void enterAssignment_adv_log(ExplorerScriptParser::Assignment_adv_logContext * /*ctx*/) override { }
  virtual void exitAssignment_adv_log(ExplorerScriptParser::Assignment_adv_logContext * /*ctx*/) override { }

  virtual void enterAssignment_dungeon_mode(ExplorerScriptParser::Assignment_dungeon_modeContext * /*ctx*/) override { }
  virtual void exitAssignment_dungeon_mode(ExplorerScriptParser::Assignment_dungeon_modeContext * /*ctx*/) override { }

  virtual void enterAssignment_scn(ExplorerScriptParser::Assignment_scnContext * /*ctx*/) override { }
  virtual void exitAssignment_scn(ExplorerScriptParser::Assignment_scnContext * /*ctx*/) override { }

  virtual void enterValue_of(ExplorerScriptParser::Value_ofContext * /*ctx*/) override { }
  virtual void exitValue_of(ExplorerScriptParser::Value_ofContext * /*ctx*/) override { }

  virtual void enterScn_var(ExplorerScriptParser::Scn_varContext * /*ctx*/) override { }
  virtual void exitScn_var(ExplorerScriptParser::Scn_varContext * /*ctx*/) override { }

  virtual void enterConditional_operator(ExplorerScriptParser::Conditional_operatorContext * /*ctx*/) override { }
  virtual void exitConditional_operator(ExplorerScriptParser::Conditional_operatorContext * /*ctx*/) override { }

  virtual void enterAssign_operator(ExplorerScriptParser::Assign_operatorContext * /*ctx*/) override { }
  virtual void exitAssign_operator(ExplorerScriptParser::Assign_operatorContext * /*ctx*/) override { }

  virtual void enterFuncdef(ExplorerScriptParser::FuncdefContext * /*ctx*/) override { }
  virtual void exitFuncdef(ExplorerScriptParser::FuncdefContext * /*ctx*/) override { }

  virtual void enterSimple_def(ExplorerScriptParser::Simple_defContext * /*ctx*/) override { }
  virtual void exitSimple_def(ExplorerScriptParser::Simple_defContext * /*ctx*/) override { }

  virtual void enterCoro_def(ExplorerScriptParser::Coro_defContext * /*ctx*/) override { }
  virtual void exitCoro_def(ExplorerScriptParser::Coro_defContext * /*ctx*/) override { }

  virtual void enterFor_target_def(ExplorerScriptParser::For_target_defContext * /*ctx*/) override { }
  virtual void exitFor_target_def(ExplorerScriptParser::For_target_defContext * /*ctx*/) override { }

  virtual void enterInteger_like(ExplorerScriptParser::Integer_likeContext * /*ctx*/) override { }
  virtual void exitInteger_like(ExplorerScriptParser::Integer_likeContext * /*ctx*/) override { }

  virtual void enterOperation(ExplorerScriptParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(ExplorerScriptParser::OperationContext * /*ctx*/) override { }

  virtual void enterInline_ctx(ExplorerScriptParser::Inline_ctxContext * /*ctx*/) override { }
  virtual void exitInline_ctx(ExplorerScriptParser::Inline_ctxContext * /*ctx*/) override { }

  virtual void enterFunc_suite(ExplorerScriptParser::Func_suiteContext * /*ctx*/) override { }
  virtual void exitFunc_suite(ExplorerScriptParser::Func_suiteContext * /*ctx*/) override { }

  virtual void enterFunc_alias(ExplorerScriptParser::Func_aliasContext * /*ctx*/) override { }
  virtual void exitFunc_alias(ExplorerScriptParser::Func_aliasContext * /*ctx*/) override { }

  virtual void enterArglist(ExplorerScriptParser::ArglistContext * /*ctx*/) override { }
  virtual void exitArglist(ExplorerScriptParser::ArglistContext * /*ctx*/) override { }

  virtual void enterPos_argument(ExplorerScriptParser::Pos_argumentContext * /*ctx*/) override { }
  virtual void exitPos_argument(ExplorerScriptParser::Pos_argumentContext * /*ctx*/) override { }

  virtual void enterPosition_marker(ExplorerScriptParser::Position_markerContext * /*ctx*/) override { }
  virtual void exitPosition_marker(ExplorerScriptParser::Position_markerContext * /*ctx*/) override { }

  virtual void enterPosition_marker_arg(ExplorerScriptParser::Position_marker_argContext * /*ctx*/) override { }
  virtual void exitPosition_marker_arg(ExplorerScriptParser::Position_marker_argContext * /*ctx*/) override { }

  virtual void enterLabel(ExplorerScriptParser::LabelContext * /*ctx*/) override { }
  virtual void exitLabel(ExplorerScriptParser::LabelContext * /*ctx*/) override { }

  virtual void enterString(ExplorerScriptParser::StringContext * /*ctx*/) override { }
  virtual void exitString(ExplorerScriptParser::StringContext * /*ctx*/) override { }

  virtual void enterLang_string(ExplorerScriptParser::Lang_stringContext * /*ctx*/) override { }
  virtual void exitLang_string(ExplorerScriptParser::Lang_stringContext * /*ctx*/) override { }

  virtual void enterLang_string_argument(ExplorerScriptParser::Lang_string_argumentContext * /*ctx*/) override { }
  virtual void exitLang_string_argument(ExplorerScriptParser::Lang_string_argumentContext * /*ctx*/) override { }

  virtual void enterString_value(ExplorerScriptParser::String_valueContext * /*ctx*/) override { }
  virtual void exitString_value(ExplorerScriptParser::String_valueContext * /*ctx*/) override { }

  virtual void enterCtx_header(ExplorerScriptParser::Ctx_headerContext * /*ctx*/) override { }
  virtual void exitCtx_header(ExplorerScriptParser::Ctx_headerContext * /*ctx*/) override { }

  virtual void enterFor_target_def_target(ExplorerScriptParser::For_target_def_targetContext * /*ctx*/) override { }
  virtual void exitFor_target_def_target(ExplorerScriptParser::For_target_def_targetContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

