
// Generated from ExplorerScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  ExplorerScriptLexer : public antlr4::Lexer {
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

  explicit ExplorerScriptLexer(antlr4::CharStream *input);

  ~ExplorerScriptLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

