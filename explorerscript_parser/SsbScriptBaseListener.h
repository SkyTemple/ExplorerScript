
// Generated from SsbScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "SsbScriptListener.h"


/**
 * This class provides an empty implementation of SsbScriptListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SsbScriptBaseListener : public SsbScriptListener {
public:

  virtual void enterPos_argument(SsbScriptParser::Pos_argumentContext * /*ctx*/) override { }
  virtual void exitPos_argument(SsbScriptParser::Pos_argumentContext * /*ctx*/) override { }

  virtual void enterJump_marker(SsbScriptParser::Jump_markerContext * /*ctx*/) override { }
  virtual void exitJump_marker(SsbScriptParser::Jump_markerContext * /*ctx*/) override { }

  virtual void enterStart(SsbScriptParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(SsbScriptParser::StartContext * /*ctx*/) override { }

  virtual void enterFuncdef(SsbScriptParser::FuncdefContext * /*ctx*/) override { }
  virtual void exitFuncdef(SsbScriptParser::FuncdefContext * /*ctx*/) override { }

  virtual void enterSimple_def(SsbScriptParser::Simple_defContext * /*ctx*/) override { }
  virtual void exitSimple_def(SsbScriptParser::Simple_defContext * /*ctx*/) override { }

  virtual void enterCoro_def(SsbScriptParser::Coro_defContext * /*ctx*/) override { }
  virtual void exitCoro_def(SsbScriptParser::Coro_defContext * /*ctx*/) override { }

  virtual void enterFor_target_def(SsbScriptParser::For_target_defContext * /*ctx*/) override { }
  virtual void exitFor_target_def(SsbScriptParser::For_target_defContext * /*ctx*/) override { }

  virtual void enterInteger_like(SsbScriptParser::Integer_likeContext * /*ctx*/) override { }
  virtual void exitInteger_like(SsbScriptParser::Integer_likeContext * /*ctx*/) override { }

  virtual void enterStmt(SsbScriptParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(SsbScriptParser::StmtContext * /*ctx*/) override { }

  virtual void enterOperation(SsbScriptParser::OperationContext * /*ctx*/) override { }
  virtual void exitOperation(SsbScriptParser::OperationContext * /*ctx*/) override { }

  virtual void enterInline_ctx(SsbScriptParser::Inline_ctxContext * /*ctx*/) override { }
  virtual void exitInline_ctx(SsbScriptParser::Inline_ctxContext * /*ctx*/) override { }

  virtual void enterFunc_suite(SsbScriptParser::Func_suiteContext * /*ctx*/) override { }
  virtual void exitFunc_suite(SsbScriptParser::Func_suiteContext * /*ctx*/) override { }

  virtual void enterFunc_alias(SsbScriptParser::Func_aliasContext * /*ctx*/) override { }
  virtual void exitFunc_alias(SsbScriptParser::Func_aliasContext * /*ctx*/) override { }

  virtual void enterArglist(SsbScriptParser::ArglistContext * /*ctx*/) override { }
  virtual void exitArglist(SsbScriptParser::ArglistContext * /*ctx*/) override { }

  virtual void enterPosition_marker(SsbScriptParser::Position_markerContext * /*ctx*/) override { }
  virtual void exitPosition_marker(SsbScriptParser::Position_markerContext * /*ctx*/) override { }

  virtual void enterPosition_marker_arg(SsbScriptParser::Position_marker_argContext * /*ctx*/) override { }
  virtual void exitPosition_marker_arg(SsbScriptParser::Position_marker_argContext * /*ctx*/) override { }

  virtual void enterLabel(SsbScriptParser::LabelContext * /*ctx*/) override { }
  virtual void exitLabel(SsbScriptParser::LabelContext * /*ctx*/) override { }

  virtual void enterString(SsbScriptParser::StringContext * /*ctx*/) override { }
  virtual void exitString(SsbScriptParser::StringContext * /*ctx*/) override { }

  virtual void enterLang_string(SsbScriptParser::Lang_stringContext * /*ctx*/) override { }
  virtual void exitLang_string(SsbScriptParser::Lang_stringContext * /*ctx*/) override { }

  virtual void enterLang_string_argument(SsbScriptParser::Lang_string_argumentContext * /*ctx*/) override { }
  virtual void exitLang_string_argument(SsbScriptParser::Lang_string_argumentContext * /*ctx*/) override { }

  virtual void enterString_value(SsbScriptParser::String_valueContext * /*ctx*/) override { }
  virtual void exitString_value(SsbScriptParser::String_valueContext * /*ctx*/) override { }

  virtual void enterCtx_header(SsbScriptParser::Ctx_headerContext * /*ctx*/) override { }
  virtual void exitCtx_header(SsbScriptParser::Ctx_headerContext * /*ctx*/) override { }

  virtual void enterFor_target_def_target(SsbScriptParser::For_target_def_targetContext * /*ctx*/) override { }
  virtual void exitFor_target_def_target(SsbScriptParser::For_target_def_targetContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

