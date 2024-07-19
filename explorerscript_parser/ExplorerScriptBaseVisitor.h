// Generated from ExplorerScript.g4 by ANTLR 4.13.0

#pragma once


#include <pybind11/pybind11.h>
#include "antlr4-runtime.h"
#include "ExplorerScriptVisitor.h"


/**
 * This class provides an empty implementation of ExplorerScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExplorerScriptBaseVisitor : public ExplorerScriptVisitor {
public:

  virtual std::any visitStart(ExplorerScriptParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImport_stmt(ExplorerScriptParser::Import_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant_assign(ExplorerScriptParser::Constant_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMacrodef(ExplorerScriptParser::MacrodefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(ExplorerScriptParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_stmt(ExplorerScriptParser::Simple_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCntrl_stmt(ExplorerScriptParser::Cntrl_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJump(ExplorerScriptParser::JumpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(ExplorerScriptParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMacro_call(ExplorerScriptParser::Macro_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCtx_block(ExplorerScriptParser::Ctx_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_block(ExplorerScriptParser::If_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElseif_block(ExplorerScriptParser::Elseif_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElse_block(ExplorerScriptParser::Else_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_header(ExplorerScriptParser::If_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_h_negatable(ExplorerScriptParser::If_h_negatableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_h_op(ExplorerScriptParser::If_h_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_h_bit(ExplorerScriptParser::If_h_bitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_h_scn(ExplorerScriptParser::If_h_scnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_block(ExplorerScriptParser::Switch_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMessage_switch_block(ExplorerScriptParser::Message_switch_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingle_case_block(ExplorerScriptParser::Single_case_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefault(ExplorerScriptParser::DefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_header(ExplorerScriptParser::Switch_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_h_scn(ExplorerScriptParser::Switch_h_scnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_h_random(ExplorerScriptParser::Switch_h_randomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_h_dungeon_mode(ExplorerScriptParser::Switch_h_dungeon_modeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitch_h_sector(ExplorerScriptParser::Switch_h_sectorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCase_header(ExplorerScriptParser::Case_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCase_h_menu(ExplorerScriptParser::Case_h_menuContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCase_h_menu2(ExplorerScriptParser::Case_h_menu2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCase_h_op(ExplorerScriptParser::Case_h_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForever_block(ExplorerScriptParser::Forever_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_block(ExplorerScriptParser::For_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile_block(ExplorerScriptParser::While_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(ExplorerScriptParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment_regular(ExplorerScriptParser::Assignment_regularContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment_clear(ExplorerScriptParser::Assignment_clearContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment_initial(ExplorerScriptParser::Assignment_initialContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment_reset(ExplorerScriptParser::Assignment_resetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment_adv_log(ExplorerScriptParser::Assignment_adv_logContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment_dungeon_mode(ExplorerScriptParser::Assignment_dungeon_modeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment_scn(ExplorerScriptParser::Assignment_scnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_of(ExplorerScriptParser::Value_ofContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScn_var(ExplorerScriptParser::Scn_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConditional_operator(ExplorerScriptParser::Conditional_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_operator(ExplorerScriptParser::Assign_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncdef(ExplorerScriptParser::FuncdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_def(ExplorerScriptParser::Simple_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCoro_def(ExplorerScriptParser::Coro_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_target_def(ExplorerScriptParser::For_target_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitive(ExplorerScriptParser::PrimitiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation(ExplorerScriptParser::OperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInline_ctx(ExplorerScriptParser::Inline_ctxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_suite(ExplorerScriptParser::Func_suiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_alias(ExplorerScriptParser::Func_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArglist(ExplorerScriptParser::ArglistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPos_argument(ExplorerScriptParser::Pos_argumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPosition_marker(ExplorerScriptParser::Position_markerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPosition_marker_arg(ExplorerScriptParser::Position_marker_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabel(ExplorerScriptParser::LabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString(ExplorerScriptParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLang_string(ExplorerScriptParser::Lang_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLang_string_argument(ExplorerScriptParser::Lang_string_argumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString_value(ExplorerScriptParser::String_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCtx_header(ExplorerScriptParser::Ctx_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_target_def_target(ExplorerScriptParser::For_target_def_targetContext *ctx) override {
    return visitChildren(ctx);
  }



      virtual std::any defaultResult() override {
        return static_cast<pybind11::object>(pybind11::none());
      }
    };