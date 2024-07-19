
// Generated from ExplorerScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  ExplorerScriptParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, OP_FALSE = 2, OP_TRUE = 3, ASSIGN = 4, OPEN_SHARP = 5, CLOSE_SHARP = 6, 
    OP_EQ = 7, OP_LE = 8, OP_GE = 9, OP_NEQ = 10, OP_AND = 11, OP_XOR = 12, 
    OP_BICH = 13, OP_MINUS = 14, OP_PLUS = 15, OP_MULTIPLY = 16, OP_DIVIDE = 17, 
    OR = 18, NOT = 19, JUMP = 20, CALL = 21, IMPORT = 22, CONST = 23, MACRO = 24, 
    IF = 25, ELSEIF = 26, ELSE = 27, FOREVER = 28, WITH = 29, SWITCH = 30, 
    RETURN = 31, END = 32, HOLD = 33, CONTINUE = 34, BREAK = 35, BREAK_LOOP = 36, 
    VALUE = 37, DEBUG = 38, EDIT = 39, VARIATION = 40, RANDOM = 41, SECTOR = 42, 
    DUNGEON_MODE = 43, MENU2 = 44, MENU = 45, CASE = 46, DEFAULT = 47, CLEAR = 48, 
    RESET = 49, INIT = 50, SCN = 51, DUNGEON_RESULT = 52, ADVENTURE_LOG = 53, 
    MESSAGE_SWITCH_TALK = 54, MESSAGE_SWITCH_MONOLOGUE = 55, WHILE = 56, 
    OPEN_BRACKET = 57, CLOSE_BRACKET = 58, STRING_LITERAL = 59, MULTILINE_STRING_LITERAL = 60, 
    FOR_TARGET = 61, CORO = 62, DEF = 63, FOR_ACTOR = 64, FOR_OBJECT = 65, 
    FOR_PERFORMER = 66, ALIAS = 67, FOR = 68, PREVIOUS = 69, POSITION = 70, 
    IDENTIFIER = 71, VARIABLE = 72, MACRO_CALL = 73, INTEGER = 74, DECIMAL_INTEGER = 75, 
    OCT_INTEGER = 76, HEX_INTEGER = 77, BIN_INTEGER = 78, OPEN_PAREN = 79, 
    CLOSE_PAREN = 80, COMMA = 81, COLON = 82, PLUS = 83, AT = 84, PARAGRAPH = 85, 
    OPEN_BRACE = 86, CLOSE_BRACE = 87, DECIMAL = 88, SKIP_ = 89, UNKNOWN_CHAR = 90
  };

  enum {
    RuleStart = 0, RuleImport_stmt = 1, RuleConstant_assign = 2, RuleMacrodef = 3, 
    RuleStmt = 4, RuleSimple_stmt = 5, RuleCntrl_stmt = 6, RuleJump = 7, 
    RuleCall = 8, RuleMacro_call = 9, RuleCtx_block = 10, RuleIf_block = 11, 
    RuleElseif_block = 12, RuleElse_block = 13, RuleIf_header = 14, RuleIf_h_negatable = 15, 
    RuleIf_h_op = 16, RuleIf_h_bit = 17, RuleIf_h_scn = 18, RuleSwitch_block = 19, 
    RuleMessage_switch_block = 20, RuleSingle_case_block = 21, RuleDefault = 22, 
    RuleSwitch_header = 23, RuleSwitch_h_scn = 24, RuleSwitch_h_random = 25, 
    RuleSwitch_h_dungeon_mode = 26, RuleSwitch_h_sector = 27, RuleCase_header = 28, 
    RuleCase_h_menu = 29, RuleCase_h_menu2 = 30, RuleCase_h_op = 31, RuleForever_block = 32, 
    RuleFor_block = 33, RuleWhile_block = 34, RuleAssignment = 35, RuleAssignment_regular = 36, 
    RuleAssignment_clear = 37, RuleAssignment_initial = 38, RuleAssignment_reset = 39, 
    RuleAssignment_adv_log = 40, RuleAssignment_dungeon_mode = 41, RuleAssignment_scn = 42, 
    RuleValue_of = 43, RuleScn_var = 44, RuleConditional_operator = 45, 
    RuleAssign_operator = 46, RuleFuncdef = 47, RuleSimple_def = 48, RuleCoro_def = 49, 
    RuleFor_target_def = 50, RulePrimitive = 51, RuleOperation = 52, RuleInline_ctx = 53, 
    RuleFunc_suite = 54, RuleFunc_alias = 55, RuleArglist = 56, RulePos_argument = 57, 
    RulePosition_marker = 58, RulePosition_marker_arg = 59, RuleLabel = 60, 
    RuleString = 61, RuleLang_string = 62, RuleLang_string_argument = 63, 
    RuleString_value = 64, RuleCtx_header = 65, RuleFor_target_def_target = 66
  };

  explicit ExplorerScriptParser(antlr4::TokenStream *input);

  ExplorerScriptParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ExplorerScriptParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StartContext;
  class Import_stmtContext;
  class Constant_assignContext;
  class MacrodefContext;
  class StmtContext;
  class Simple_stmtContext;
  class Cntrl_stmtContext;
  class JumpContext;
  class CallContext;
  class Macro_callContext;
  class Ctx_blockContext;
  class If_blockContext;
  class Elseif_blockContext;
  class Else_blockContext;
  class If_headerContext;
  class If_h_negatableContext;
  class If_h_opContext;
  class If_h_bitContext;
  class If_h_scnContext;
  class Switch_blockContext;
  class Message_switch_blockContext;
  class Single_case_blockContext;
  class DefaultContext;
  class Switch_headerContext;
  class Switch_h_scnContext;
  class Switch_h_randomContext;
  class Switch_h_dungeon_modeContext;
  class Switch_h_sectorContext;
  class Case_headerContext;
  class Case_h_menuContext;
  class Case_h_menu2Context;
  class Case_h_opContext;
  class Forever_blockContext;
  class For_blockContext;
  class While_blockContext;
  class AssignmentContext;
  class Assignment_regularContext;
  class Assignment_clearContext;
  class Assignment_initialContext;
  class Assignment_resetContext;
  class Assignment_adv_logContext;
  class Assignment_dungeon_modeContext;
  class Assignment_scnContext;
  class Value_ofContext;
  class Scn_varContext;
  class Conditional_operatorContext;
  class Assign_operatorContext;
  class FuncdefContext;
  class Simple_defContext;
  class Coro_defContext;
  class For_target_defContext;
  class PrimitiveContext;
  class OperationContext;
  class Inline_ctxContext;
  class Func_suiteContext;
  class Func_aliasContext;
  class ArglistContext;
  class Pos_argumentContext;
  class Position_markerContext;
  class Position_marker_argContext;
  class LabelContext;
  class StringContext;
  class Lang_stringContext;
  class Lang_string_argumentContext;
  class String_valueContext;
  class Ctx_headerContext;
  class For_target_def_targetContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Import_stmtContext *> import_stmt();
    Import_stmtContext* import_stmt(size_t i);
    std::vector<MacrodefContext *> macrodef();
    MacrodefContext* macrodef(size_t i);
    std::vector<FuncdefContext *> funcdef();
    FuncdefContext* funcdef(size_t i);
    std::vector<Constant_assignContext *> constant_assign();
    Constant_assignContext* constant_assign(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  Import_stmtContext : public antlr4::ParserRuleContext {
  public:
    Import_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    antlr4::tree::TerminalNode *STRING_LITERAL();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_stmtContext* import_stmt();

  class  Constant_assignContext : public antlr4::ParserRuleContext {
  public:
    Constant_assignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ASSIGN();
    PrimitiveContext *primitive();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_assignContext* constant_assign();

  class  MacrodefContext : public antlr4::ParserRuleContext {
  public:
    MacrodefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MACRO();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    Func_suiteContext *func_suite();
    std::vector<antlr4::tree::TerminalNode *> VARIABLE();
    antlr4::tree::TerminalNode* VARIABLE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MacrodefContext* macrodef();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_assignContext *constant_assign();
    Simple_stmtContext *simple_stmt();
    Ctx_blockContext *ctx_block();
    If_blockContext *if_block();
    Switch_blockContext *switch_block();
    Message_switch_blockContext *message_switch_block();
    Forever_blockContext *forever_block();
    For_blockContext *for_block();
    While_blockContext *while_block();
    Macro_callContext *macro_call();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  Simple_stmtContext : public antlr4::ParserRuleContext {
  public:
    Simple_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OperationContext *operation();
    LabelContext *label();
    Cntrl_stmtContext *cntrl_stmt();
    JumpContext *jump();
    CallContext *call();
    AssignmentContext *assignment();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_stmtContext* simple_stmt();

  class  Cntrl_stmtContext : public antlr4::ParserRuleContext {
  public:
    Cntrl_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *HOLD();
    antlr4::tree::TerminalNode *CONTINUE();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *BREAK_LOOP();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cntrl_stmtContext* cntrl_stmt();

  class  JumpContext : public antlr4::ParserRuleContext {
  public:
    JumpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *JUMP();
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  JumpContext* jump();

  class  CallContext : public antlr4::ParserRuleContext {
  public:
    CallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALL();
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallContext* call();

  class  Macro_callContext : public antlr4::ParserRuleContext {
  public:
    Macro_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MACRO_CALL();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    ArglistContext *arglist();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Macro_callContext* macro_call();

  class  Ctx_blockContext : public antlr4::ParserRuleContext {
  public:
    Ctx_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    Ctx_headerContext *ctx_header();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<Simple_stmtContext *> simple_stmt();
    Simple_stmtContext* simple_stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ctx_blockContext* ctx_block();

  class  If_blockContext : public antlr4::ParserRuleContext {
  public:
    If_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    std::vector<If_headerContext *> if_header();
    If_headerContext* if_header(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    antlr4::tree::TerminalNode *NOT();
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    std::vector<Elseif_blockContext *> elseif_block();
    Elseif_blockContext* elseif_block(size_t i);
    Else_blockContext *else_block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_blockContext* if_block();

  class  Elseif_blockContext : public antlr4::ParserRuleContext {
  public:
    Elseif_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSEIF();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    std::vector<If_headerContext *> if_header();
    If_headerContext* if_header(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    antlr4::tree::TerminalNode *NOT();
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Elseif_blockContext* elseif_block();

  class  Else_blockContext : public antlr4::ParserRuleContext {
  public:
    Else_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Else_blockContext* else_block();

  class  If_headerContext : public antlr4::ParserRuleContext {
  public:
    If_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_h_opContext *if_h_op();
    If_h_bitContext *if_h_bit();
    If_h_negatableContext *if_h_negatable();
    If_h_scnContext *if_h_scn();
    OperationContext *operation();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_headerContext* if_header();

  class  If_h_negatableContext : public antlr4::ParserRuleContext {
  public:
    If_h_negatableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEBUG();
    antlr4::tree::TerminalNode *EDIT();
    antlr4::tree::TerminalNode *VARIATION();
    antlr4::tree::TerminalNode *NOT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_h_negatableContext* if_h_negatable();

  class  If_h_opContext : public antlr4::ParserRuleContext {
  public:
    If_h_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PrimitiveContext *> primitive();
    PrimitiveContext* primitive(size_t i);
    Conditional_operatorContext *conditional_operator();
    Value_ofContext *value_of();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_h_opContext* if_h_op();

  class  If_h_bitContext : public antlr4::ParserRuleContext {
  public:
    If_h_bitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveContext *primitive();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();
    antlr4::tree::TerminalNode *NOT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_h_bitContext* if_h_bit();

  class  If_h_scnContext : public antlr4::ParserRuleContext {
  public:
    If_h_scnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Scn_varContext *scn_var();
    Conditional_operatorContext *conditional_operator();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> INTEGER();
    antlr4::tree::TerminalNode* INTEGER(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_h_scnContext* if_h_scn();

  class  Switch_blockContext : public antlr4::ParserRuleContext {
  public:
    Switch_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWITCH();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    Switch_headerContext *switch_header();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<DefaultContext *> default_();
    DefaultContext* default_(size_t i);
    std::vector<Single_case_blockContext *> single_case_block();
    Single_case_blockContext* single_case_block(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_blockContext* switch_block();

  class  Message_switch_blockContext : public antlr4::ParserRuleContext {
  public:
    Message_switch_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_PAREN();
    PrimitiveContext *primitive();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    antlr4::tree::TerminalNode *MESSAGE_SWITCH_TALK();
    antlr4::tree::TerminalNode *MESSAGE_SWITCH_MONOLOGUE();
    std::vector<DefaultContext *> default_();
    DefaultContext* default_(size_t i);
    std::vector<Single_case_blockContext *> single_case_block();
    Single_case_blockContext* single_case_block(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Message_switch_blockContext* message_switch_block();

  class  Single_case_blockContext : public antlr4::ParserRuleContext {
  public:
    Single_case_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    Case_headerContext *case_header();
    antlr4::tree::TerminalNode *COLON();
    PrimitiveContext *primitive();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Single_case_blockContext* single_case_block();

  class  DefaultContext : public antlr4::ParserRuleContext {
  public:
    DefaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFAULT();
    antlr4::tree::TerminalNode *COLON();
    PrimitiveContext *primitive();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefaultContext* default_();

  class  Switch_headerContext : public antlr4::ParserRuleContext {
  public:
    Switch_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveContext *primitive();
    OperationContext *operation();
    Switch_h_scnContext *switch_h_scn();
    Switch_h_randomContext *switch_h_random();
    Switch_h_dungeon_modeContext *switch_h_dungeon_mode();
    Switch_h_sectorContext *switch_h_sector();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_headerContext* switch_header();

  class  Switch_h_scnContext : public antlr4::ParserRuleContext {
  public:
    Switch_h_scnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Scn_varContext *scn_var();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_h_scnContext* switch_h_scn();

  class  Switch_h_randomContext : public antlr4::ParserRuleContext {
  public:
    Switch_h_randomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANDOM();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    PrimitiveContext *primitive();
    antlr4::tree::TerminalNode *CLOSE_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_h_randomContext* switch_h_random();

  class  Switch_h_dungeon_modeContext : public antlr4::ParserRuleContext {
  public:
    Switch_h_dungeon_modeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DUNGEON_MODE();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    PrimitiveContext *primitive();
    antlr4::tree::TerminalNode *CLOSE_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_h_dungeon_modeContext* switch_h_dungeon_mode();

  class  Switch_h_sectorContext : public antlr4::ParserRuleContext {
  public:
    Switch_h_sectorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SECTOR();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    antlr4::tree::TerminalNode *CLOSE_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Switch_h_sectorContext* switch_h_sector();

  class  Case_headerContext : public antlr4::ParserRuleContext {
  public:
    Case_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveContext *primitive();
    Case_h_menuContext *case_h_menu();
    Case_h_menu2Context *case_h_menu2();
    Case_h_opContext *case_h_op();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_headerContext* case_header();

  class  Case_h_menuContext : public antlr4::ParserRuleContext {
  public:
    Case_h_menuContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MENU();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    PrimitiveContext *primitive();
    antlr4::tree::TerminalNode *CLOSE_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_h_menuContext* case_h_menu();

  class  Case_h_menu2Context : public antlr4::ParserRuleContext {
  public:
    Case_h_menu2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MENU2();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    PrimitiveContext *primitive();
    antlr4::tree::TerminalNode *CLOSE_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_h_menu2Context* case_h_menu2();

  class  Case_h_opContext : public antlr4::ParserRuleContext {
  public:
    Case_h_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Conditional_operatorContext *conditional_operator();
    Value_ofContext *value_of();
    PrimitiveContext *primitive();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_h_opContext* case_h_op();

  class  Forever_blockContext : public antlr4::ParserRuleContext {
  public:
    Forever_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOREVER();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Forever_blockContext* forever_block();

  class  For_blockContext : public antlr4::ParserRuleContext {
  public:
    For_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    std::vector<Simple_stmtContext *> simple_stmt();
    Simple_stmtContext* simple_stmt(size_t i);
    If_headerContext *if_header();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_blockContext* for_block();

  class  While_blockContext : public antlr4::ParserRuleContext {
  public:
    While_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    If_headerContext *if_header();
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *OPEN_BRACE();
    antlr4::tree::TerminalNode *CLOSE_BRACE();
    antlr4::tree::TerminalNode *NOT();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_blockContext* while_block();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assignment_regularContext *assignment_regular();
    Assignment_clearContext *assignment_clear();
    Assignment_initialContext *assignment_initial();
    Assignment_resetContext *assignment_reset();
    Assignment_adv_logContext *assignment_adv_log();
    Assignment_dungeon_modeContext *assignment_dungeon_mode();
    Assignment_scnContext *assignment_scn();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  Assignment_regularContext : public antlr4::ParserRuleContext {
  public:
    Assignment_regularContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PrimitiveContext *> primitive();
    PrimitiveContext* primitive(size_t i);
    Assign_operatorContext *assign_operator();
    Value_ofContext *value_of();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_regularContext* assignment_regular();

  class  Assignment_clearContext : public antlr4::ParserRuleContext {
  public:
    Assignment_clearContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLEAR();
    PrimitiveContext *primitive();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_clearContext* assignment_clear();

  class  Assignment_initialContext : public antlr4::ParserRuleContext {
  public:
    Assignment_initialContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INIT();
    PrimitiveContext *primitive();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_initialContext* assignment_initial();

  class  Assignment_resetContext : public antlr4::ParserRuleContext {
  public:
    Assignment_resetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESET();
    antlr4::tree::TerminalNode *DUNGEON_RESULT();
    Scn_varContext *scn_var();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_resetContext* assignment_reset();

  class  Assignment_adv_logContext : public antlr4::ParserRuleContext {
  public:
    Assignment_adv_logContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADVENTURE_LOG();
    antlr4::tree::TerminalNode *ASSIGN();
    PrimitiveContext *primitive();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_adv_logContext* assignment_adv_log();

  class  Assignment_dungeon_modeContext : public antlr4::ParserRuleContext {
  public:
    Assignment_dungeon_modeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DUNGEON_MODE();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    std::vector<PrimitiveContext *> primitive();
    PrimitiveContext* primitive(size_t i);
    antlr4::tree::TerminalNode *CLOSE_PAREN();
    antlr4::tree::TerminalNode *ASSIGN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_dungeon_modeContext* assignment_dungeon_mode();

  class  Assignment_scnContext : public antlr4::ParserRuleContext {
  public:
    Assignment_scnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveContext *primitive();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *SCN();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> INTEGER();
    antlr4::tree::TerminalNode* INTEGER(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_scnContext* assignment_scn();

  class  Value_ofContext : public antlr4::ParserRuleContext {
  public:
    Value_ofContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VALUE();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    PrimitiveContext *primitive();
    antlr4::tree::TerminalNode *CLOSE_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_ofContext* value_of();

  class  Scn_varContext : public antlr4::ParserRuleContext {
  public:
    Scn_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCN();
    antlr4::tree::TerminalNode *OPEN_PAREN();
    PrimitiveContext *primitive();
    antlr4::tree::TerminalNode *CLOSE_PAREN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Scn_varContext* scn_var();

  class  Conditional_operatorContext : public antlr4::ParserRuleContext {
  public:
    Conditional_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_FALSE();
    antlr4::tree::TerminalNode *OP_TRUE();
    antlr4::tree::TerminalNode *OP_EQ();
    antlr4::tree::TerminalNode *OP_GE();
    antlr4::tree::TerminalNode *OP_LE();
    antlr4::tree::TerminalNode *OPEN_SHARP();
    antlr4::tree::TerminalNode *CLOSE_SHARP();
    antlr4::tree::TerminalNode *OP_NEQ();
    antlr4::tree::TerminalNode *OP_AND();
    antlr4::tree::TerminalNode *OP_XOR();
    antlr4::tree::TerminalNode *OP_BICH();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conditional_operatorContext* conditional_operator();

  class  Assign_operatorContext : public antlr4::ParserRuleContext {
  public:
    Assign_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP_MINUS();
    antlr4::tree::TerminalNode *OP_PLUS();
    antlr4::tree::TerminalNode *OP_MULTIPLY();
    antlr4::tree::TerminalNode *OP_DIVIDE();
    antlr4::tree::TerminalNode *ASSIGN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_operatorContext* assign_operator();

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

  class  Pos_argumentContext : public antlr4::ParserRuleContext {
  public:
    Pos_argumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveContext *primitive();
    Position_markerContext *position_marker();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pos_argumentContext* pos_argument();

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

