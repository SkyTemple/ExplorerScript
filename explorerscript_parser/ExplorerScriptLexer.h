
// Generated from ExplorerScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  ExplorerScriptLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, OP_FALSE = 2, OP_TRUE = 3, ASSIGN = 4, OPEN_SHARP = 5, CLOSE_SHARP = 6, 
    OP_EQ = 7, OP_LE = 8, OP_GE = 9, OP_NEQ = 10, OP_AND = 11, OP_XOR = 12, 
    OP_BICH = 13, OP_MINUS = 14, OP_PLUS = 15, OP_MULTIPLY = 16, OP_DIVIDE = 17, 
    OR = 18, NOT = 19, JUMP = 20, CALL = 21, IMPORT = 22, MACRO = 23, IF = 24, 
    ELSEIF = 25, ELSE = 26, FOREVER = 27, WITH = 28, SWITCH = 29, RETURN = 30, 
    END = 31, HOLD = 32, CONTINUE = 33, BREAK = 34, BREAK_LOOP = 35, VALUE = 36, 
    DEBUG = 37, EDIT = 38, VARIATION = 39, RANDOM = 40, SECTOR = 41, DUNGEON_MODE = 42, 
    MENU2 = 43, MENU = 44, CASE = 45, DEFAULT = 46, CLEAR = 47, RESET = 48, 
    INIT = 49, SCN = 50, DUNGEON_RESULT = 51, ADVENTURE_LOG = 52, MESSAGE_SWITCH_TALK = 53, 
    MESSAGE_SWITCH_MONOLOGUE = 54, WHILE = 55, OPEN_BRACKET = 56, CLOSE_BRACKET = 57, 
    STRING_LITERAL = 58, MULTILINE_STRING_LITERAL = 59, FOR_TARGET = 60, 
    CORO = 61, DEF = 62, FOR_ACTOR = 63, FOR_OBJECT = 64, FOR_PERFORMER = 65, 
    ALIAS = 66, FOR = 67, PREVIOUS = 68, POSITION = 69, IDENTIFIER = 70, 
    VARIABLE = 71, MACRO_CALL = 72, INTEGER = 73, DECIMAL_INTEGER = 74, 
    OCT_INTEGER = 75, HEX_INTEGER = 76, BIN_INTEGER = 77, OPEN_PAREN = 78, 
    CLOSE_PAREN = 79, COMMA = 80, COLON = 81, PLUS = 82, AT = 83, PARAGRAPH = 84, 
    OPEN_BRACE = 85, CLOSE_BRACE = 86, DECIMAL = 87, SKIP_ = 88, UNKNOWN_CHAR = 89
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

