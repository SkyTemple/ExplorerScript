
// Generated from SsbScript.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  SsbScriptLexer : public antlr4::Lexer {
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

  explicit SsbScriptLexer(antlr4::CharStream *input);

  ~SsbScriptLexer() override;


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

