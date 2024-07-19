// Generated from SsbScript.g4 by ANTLR 4.13.0

#pragma once


#include <pybind11/pybind11.h>
#include "antlr4-runtime.h"
#include "SsbScriptVisitor.h"


/**
 * This class provides an empty implementation of SsbScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SsbScriptBaseVisitor : public SsbScriptVisitor {
public:

  virtual std::any visitPos_argument(SsbScriptParser::Pos_argumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJump_marker(SsbScriptParser::Jump_markerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStart(SsbScriptParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncdef(SsbScriptParser::FuncdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_def(SsbScriptParser::Simple_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCoro_def(SsbScriptParser::Coro_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_target_def(SsbScriptParser::For_target_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitive(SsbScriptParser::PrimitiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(SsbScriptParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperation(SsbScriptParser::OperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInline_ctx(SsbScriptParser::Inline_ctxContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_suite(SsbScriptParser::Func_suiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_alias(SsbScriptParser::Func_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArglist(SsbScriptParser::ArglistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPosition_marker(SsbScriptParser::Position_markerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPosition_marker_arg(SsbScriptParser::Position_marker_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabel(SsbScriptParser::LabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString(SsbScriptParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLang_string(SsbScriptParser::Lang_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLang_string_argument(SsbScriptParser::Lang_string_argumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString_value(SsbScriptParser::String_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCtx_header(SsbScriptParser::Ctx_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_target_def_target(SsbScriptParser::For_target_def_targetContext *ctx) override {
    return visitChildren(ctx);
  }



      virtual std::any defaultResult() override {
        return static_cast<pybind11::object>(pybind11::none());
      }
    };