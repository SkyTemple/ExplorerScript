
// Generated from SsbScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "SsbScriptParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SsbScriptParser.
 */
class  SsbScriptListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterPos_argument(SsbScriptParser::Pos_argumentContext *ctx) = 0;
  virtual void exitPos_argument(SsbScriptParser::Pos_argumentContext *ctx) = 0;

  virtual void enterJump_marker(SsbScriptParser::Jump_markerContext *ctx) = 0;
  virtual void exitJump_marker(SsbScriptParser::Jump_markerContext *ctx) = 0;

  virtual void enterStart(SsbScriptParser::StartContext *ctx) = 0;
  virtual void exitStart(SsbScriptParser::StartContext *ctx) = 0;

  virtual void enterFuncdef(SsbScriptParser::FuncdefContext *ctx) = 0;
  virtual void exitFuncdef(SsbScriptParser::FuncdefContext *ctx) = 0;

  virtual void enterSimple_def(SsbScriptParser::Simple_defContext *ctx) = 0;
  virtual void exitSimple_def(SsbScriptParser::Simple_defContext *ctx) = 0;

  virtual void enterCoro_def(SsbScriptParser::Coro_defContext *ctx) = 0;
  virtual void exitCoro_def(SsbScriptParser::Coro_defContext *ctx) = 0;

  virtual void enterFor_target_def(SsbScriptParser::For_target_defContext *ctx) = 0;
  virtual void exitFor_target_def(SsbScriptParser::For_target_defContext *ctx) = 0;

  virtual void enterInteger_like(SsbScriptParser::Integer_likeContext *ctx) = 0;
  virtual void exitInteger_like(SsbScriptParser::Integer_likeContext *ctx) = 0;

  virtual void enterStmt(SsbScriptParser::StmtContext *ctx) = 0;
  virtual void exitStmt(SsbScriptParser::StmtContext *ctx) = 0;

  virtual void enterOperation(SsbScriptParser::OperationContext *ctx) = 0;
  virtual void exitOperation(SsbScriptParser::OperationContext *ctx) = 0;

  virtual void enterInline_ctx(SsbScriptParser::Inline_ctxContext *ctx) = 0;
  virtual void exitInline_ctx(SsbScriptParser::Inline_ctxContext *ctx) = 0;

  virtual void enterFunc_suite(SsbScriptParser::Func_suiteContext *ctx) = 0;
  virtual void exitFunc_suite(SsbScriptParser::Func_suiteContext *ctx) = 0;

  virtual void enterFunc_alias(SsbScriptParser::Func_aliasContext *ctx) = 0;
  virtual void exitFunc_alias(SsbScriptParser::Func_aliasContext *ctx) = 0;

  virtual void enterArglist(SsbScriptParser::ArglistContext *ctx) = 0;
  virtual void exitArglist(SsbScriptParser::ArglistContext *ctx) = 0;

  virtual void enterPosition_marker(SsbScriptParser::Position_markerContext *ctx) = 0;
  virtual void exitPosition_marker(SsbScriptParser::Position_markerContext *ctx) = 0;

  virtual void enterPosition_marker_arg(SsbScriptParser::Position_marker_argContext *ctx) = 0;
  virtual void exitPosition_marker_arg(SsbScriptParser::Position_marker_argContext *ctx) = 0;

  virtual void enterLabel(SsbScriptParser::LabelContext *ctx) = 0;
  virtual void exitLabel(SsbScriptParser::LabelContext *ctx) = 0;

  virtual void enterString(SsbScriptParser::StringContext *ctx) = 0;
  virtual void exitString(SsbScriptParser::StringContext *ctx) = 0;

  virtual void enterLang_string(SsbScriptParser::Lang_stringContext *ctx) = 0;
  virtual void exitLang_string(SsbScriptParser::Lang_stringContext *ctx) = 0;

  virtual void enterLang_string_argument(SsbScriptParser::Lang_string_argumentContext *ctx) = 0;
  virtual void exitLang_string_argument(SsbScriptParser::Lang_string_argumentContext *ctx) = 0;

  virtual void enterString_value(SsbScriptParser::String_valueContext *ctx) = 0;
  virtual void exitString_value(SsbScriptParser::String_valueContext *ctx) = 0;

  virtual void enterCtx_header(SsbScriptParser::Ctx_headerContext *ctx) = 0;
  virtual void exitCtx_header(SsbScriptParser::Ctx_headerContext *ctx) = 0;

  virtual void enterFor_target_def_target(SsbScriptParser::For_target_def_targetContext *ctx) = 0;
  virtual void exitFor_target_def_target(SsbScriptParser::For_target_def_targetContext *ctx) = 0;


};

