
// Generated from SsbScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  SsbScriptParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, STRING_LITERAL = 2, MULTILINE_STRING_LITERAL = 3, FOR_TARGET = 4, 
    CORO = 5, DEF = 6, FOR_ACTOR = 7, FOR_OBJECT = 8, FOR_PERFORMER = 9, 
    ALIAS = 10, FOR = 11, PREVIOUS = 12, POSITION = 13, IDENTIFIER = 14, 
    VARIABLE = 15, MACRO_CALL = 16, INTEGER = 17, DECIMAL_INTEGER = 18, 
    OCT_INTEGER = 19, HEX_INTEGER = 20, BIN_INTEGER = 21, OPEN_PAREN = 22, 
    CLOSE_PAREN = 23, COMMA = 24, COLON = 25, ASSIGN = 26, PLUS = 27, AT = 28, 
    PARAGRAPH = 29, OPEN_BRACE = 30, CLOSE_BRACE = 31, OPEN_SHARP = 32, 
    CLOSE_SHARP = 33, DECIMAL = 34, SKIP_ = 35, UNKNOWN_CHAR = 36
  };

  enum {
    RulePos_argument = 0, RuleJump_marker = 1, RuleStart = 2, RuleFuncdef = 3, 
    RuleSimple_def = 4, RuleCoro_def = 5, RuleFor_target_def = 6, RulePrimitive = 7, 
    RuleStmt = 8, RuleOperation = 9, RuleInline_ctx = 10, RuleFunc_suite = 11, 
    RuleFunc_alias = 12, RuleArglist = 13, RulePosition_marker = 14, RulePosition_marker_arg = 15, 
    RuleLabel = 16, RuleString = 17, RuleLang_string = 18, RuleLang_string_argument = 19, 
    RuleString_value = 20, RuleCtx_header = 21, RuleFor_target_def_target = 22
  };

  explicit SsbScriptParser(antlr4::TokenStream *input);

  SsbScriptParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~SsbScriptParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Pos_argumentContext;
  class Jump_markerContext;
  class StartContext;
  class FuncdefContext;
  class Simple_defContext;
  class Coro_defContext;
  class For_target_defContext;
  class PrimitiveContext;
  class StmtContext;
  class OperationContext;
  class Inline_ctxContext;
  class Func_suiteContext;
  class Func_aliasContext;
  class ArglistContext;
  class Position_markerContext;
  class Position_marker_argContext;
  class LabelContext;
  class StringContext;
  class Lang_stringContext;
  class Lang_string_argumentContext;
  class String_valueContext;
  class Ctx_headerContext;
  class For_target_def_targetContext; 

  class  Pos_argumentContext : public antlr4::ParserRuleContext {
  public:
    Pos_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveContext *primitive();
    Position_markerContext *position_marker();
    Jump_markerContext *jump_marker();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pos_argumentContext* pos_argument();

  class  Jump_markerContext : public antlr4::ParserRuleContext {
  public:
    Jump_markerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Jump_markerContext* jump_marker();

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<FuncdefContext *> funcdef();
    FuncdefContext* funcdef(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  FuncdefContext : public antlr4::ParserRuleContext {
  public:
    FuncdefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Coro_defContext *coro_def();
    Simple_defContext *simple_def();
    For_target_defContext *for_target_def();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncdefContext* funcdef();

  class  Simple_defContext : public antlr4::ParserRuleContext {
  public:
    Simple_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEF();
    antlr4::tree::TerminalNode *INTEGER();
    Func_suiteContext *func_suite();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_defContext* simple_def();

  class  Coro_defContext : public antlr4::ParserRuleContext {
  public:
    Coro_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CORO();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Func_suiteContext *func_suite();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Coro_defContext* coro_def();

  class  For_target_defContext : public antlr4::ParserRuleContext {
  public:
    For_target_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEF();
    antlr4::tree::TerminalNode *INTEGER();
    For_target_def_targetContext *for_target_def_target();
    PrimitiveContext *primitive();
    Func_suiteContext *func_suite();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_target_defContext* for_target_def();

  class  PrimitiveContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DECIMAL();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *VARIABLE();
    StringContext *string();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveContext* primitive();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OperationContext *operation();
    LabelContext *label();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    Inline_ctxContext *inline_ctx();
    ArglistContext *arglist();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationContext* operation();

  class  Inline_ctxContext : public antlr4::ParserRuleContext {
  public:
    Inline_ctxContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_SHARP();
    Ctx_headerContext *ctx_header();
    antlr4::tree::TerminalNode *CLOSE_SHARP();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inline_ctxContext* inline_ctx();

  class  Func_suiteContext : public antlr4::ParserRuleContext {
  public:
    Func_suiteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    Func_aliasContext *func_alias();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_suiteContext* func_suite();

  class  Func_aliasContext : public antlr4::ParserRuleContext {
  public:
    Func_aliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALIAS();
    antlr4::tree::TerminalNode *PREVIOUS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_aliasContext* func_alias();

  class  ArglistContext : public antlr4::ParserRuleContext {
  public:
    ArglistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Pos_argumentContext *> pos_argument();
    Pos_argumentContext* pos_argument(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArglistContext* arglist();

  class  Position_markerContext : public antlr4::ParserRuleContext {
  public:
    Position_markerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POSITION();
    antlr4::tree::TerminalNode *OPEN_SHARP();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<Position_marker_argContext *> position_marker_arg();
    Position_marker_argContext* position_marker_arg(size_t i);
    antlr4::tree::TerminalNode *CLOSE_SHARP();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Position_markerContext* position_marker();

  class  Position_marker_argContext : public antlr4::ParserRuleContext {
  public:
    Position_marker_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *DECIMAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Position_marker_argContext* position_marker_arg();

  class  LabelContext : public antlr4::ParserRuleContext {
  public:
    LabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *PARAGRAPH();
    antlr4::tree::TerminalNode *AT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelContext* label();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    String_valueContext *string_value();
    Lang_stringContext *lang_string();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringContext* string();

  class  Lang_stringContext : public antlr4::ParserRuleContext {
  public:
    Lang_stringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACE();
    std::vector<Lang_string_argumentContext *> lang_string_argument();
    Lang_string_argumentContext* lang_string_argument(size_t i);
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Lang_stringContext* lang_string();

  class  Lang_string_argumentContext : public antlr4::ParserRuleContext {
  public:
    Lang_string_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ASSIGN();
    String_valueContext *string_value();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Lang_string_argumentContext* lang_string_argument();

  class  String_valueContext : public antlr4::ParserRuleContext {
  public:
    String_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MULTILINE_STRING_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  String_valueContext* string_value();

  class  Ctx_headerContext : public antlr4::ParserRuleContext {
  public:
    Ctx_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    PrimitiveContext *primitive();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ctx_headerContext* ctx_header();

  class  For_target_def_targetContext : public antlr4::ParserRuleContext {
  public:
    For_target_def_targetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *FOR_TARGET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_target_def_targetContext* for_target_def_target();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

