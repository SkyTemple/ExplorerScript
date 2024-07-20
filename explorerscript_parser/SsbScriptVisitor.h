
// Generated from SsbScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "SsbScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SsbScriptParser.
 */
class  SsbScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SsbScriptParser.
   */
    virtual std::any visitPos_argument(SsbScriptParser::Pos_argumentContext *context) = 0;

    virtual std::any visitJump_marker(SsbScriptParser::Jump_markerContext *context) = 0;

    virtual std::any visitStart(SsbScriptParser::StartContext *context) = 0;

    virtual std::any visitFuncdef(SsbScriptParser::FuncdefContext *context) = 0;

    virtual std::any visitSimple_def(SsbScriptParser::Simple_defContext *context) = 0;

    virtual std::any visitCoro_def(SsbScriptParser::Coro_defContext *context) = 0;

    virtual std::any visitFor_target_def(SsbScriptParser::For_target_defContext *context) = 0;

    virtual std::any visitPrimitive(SsbScriptParser::PrimitiveContext *context) = 0;

    virtual std::any visitStmt(SsbScriptParser::StmtContext *context) = 0;

    virtual std::any visitOperation(SsbScriptParser::OperationContext *context) = 0;

    virtual std::any visitInline_ctx(SsbScriptParser::Inline_ctxContext *context) = 0;

    virtual std::any visitFunc_suite(SsbScriptParser::Func_suiteContext *context) = 0;

    virtual std::any visitFunc_alias(SsbScriptParser::Func_aliasContext *context) = 0;

    virtual std::any visitArglist(SsbScriptParser::ArglistContext *context) = 0;

    virtual std::any visitPosition_marker(SsbScriptParser::Position_markerContext *context) = 0;

    virtual std::any visitPosition_marker_arg(SsbScriptParser::Position_marker_argContext *context) = 0;

    virtual std::any visitLabel(SsbScriptParser::LabelContext *context) = 0;

    virtual std::any visitString(SsbScriptParser::StringContext *context) = 0;

    virtual std::any visitLang_string(SsbScriptParser::Lang_stringContext *context) = 0;

    virtual std::any visitLang_string_argument(SsbScriptParser::Lang_string_argumentContext *context) = 0;

    virtual std::any visitString_value(SsbScriptParser::String_valueContext *context) = 0;

    virtual std::any visitCtx_header(SsbScriptParser::Ctx_headerContext *context) = 0;

    virtual std::any visitFor_target_def_target(SsbScriptParser::For_target_def_targetContext *context) = 0;


};

