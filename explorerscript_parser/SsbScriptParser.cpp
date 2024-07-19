
// Generated from SsbScript.g4 by ANTLR 4.13.0


#include "SsbScriptVisitor.h"

#include "SsbScriptParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SsbScriptParserStaticData final {
  SsbScriptParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SsbScriptParserStaticData(const SsbScriptParserStaticData&) = delete;
  SsbScriptParserStaticData(SsbScriptParserStaticData&&) = delete;
  SsbScriptParserStaticData& operator=(const SsbScriptParserStaticData&) = delete;
  SsbScriptParserStaticData& operator=(SsbScriptParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ssbscriptParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
SsbScriptParserStaticData *ssbscriptParserStaticData = nullptr;

void ssbscriptParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ssbscriptParserStaticData != nullptr) {
    return;
  }
#else
  assert(ssbscriptParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SsbScriptParserStaticData>(
    std::vector<std::string>{
      "pos_argument", "jump_marker", "start", "funcdef", "simple_def", "coro_def", 
      "for_target_def", "primitive", "stmt", "operation", "inline_ctx", 
      "func_suite", "func_alias", "arglist", "position_marker", "position_marker_arg", 
      "label", "string", "lang_string", "lang_string_argument", "string_value", 
      "ctx_header", "for_target_def_target"
    },
    std::vector<std::string>{
      "", "';'", "", "", "", "'coro'", "'def'", "'for_actor'", "'for_object'", 
      "'for_performer'", "'alias'", "'for'", "'previous'", "'Position'", 
      "", "", "", "", "", "", "", "", "'('", "')'", "','", "':'", "'='", 
      "'+'", "'@'", "'\\u00A7'", "'{'", "'}'", "'<'", "'>'"
    },
    std::vector<std::string>{
      "", "", "STRING_LITERAL", "MULTILINE_STRING_LITERAL", "FOR_TARGET", 
      "CORO", "DEF", "FOR_ACTOR", "FOR_OBJECT", "FOR_PERFORMER", "ALIAS", 
      "FOR", "PREVIOUS", "POSITION", "IDENTIFIER", "VARIABLE", "MACRO_CALL", 
      "INTEGER", "DECIMAL_INTEGER", "OCT_INTEGER", "HEX_INTEGER", "BIN_INTEGER", 
      "OPEN_PAREN", "CLOSE_PAREN", "COMMA", "COLON", "ASSIGN", "PLUS", "AT", 
      "PARAGRAPH", "OPEN_BRACE", "CLOSE_BRACE", "OPEN_SHARP", "CLOSE_SHARP", 
      "DECIMAL", "SKIP_", "UNKNOWN_CHAR"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,36,187,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,0,3,0,50,8,0,1,1,1,1,1,1,1,2,5,2,56,8,2,10,2,12,
  	2,59,9,2,1,2,1,2,1,3,1,3,1,3,3,3,66,8,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,
  	5,1,6,1,6,1,6,1,6,3,6,80,8,6,1,6,1,6,3,6,84,8,6,1,6,1,6,1,7,1,7,1,7,1,
  	7,1,7,3,7,93,8,7,1,8,1,8,3,8,97,8,8,1,8,1,8,1,9,1,9,3,9,103,8,9,1,9,1,
  	9,3,9,107,8,9,1,9,1,9,1,10,1,10,1,10,1,10,1,11,1,11,4,11,117,8,11,11,
  	11,12,11,118,1,11,3,11,122,8,11,1,11,1,11,1,12,1,12,1,12,1,12,1,13,1,
  	13,1,13,5,13,133,8,13,10,13,12,13,136,9,13,1,13,3,13,139,8,13,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,16,1,16,1,16,1,17,1,
  	17,3,17,157,8,17,1,18,1,18,1,18,1,18,5,18,163,8,18,10,18,12,18,166,9,
  	18,1,18,3,18,169,8,18,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,20,1,21,1,
  	21,1,21,1,22,1,22,1,22,3,22,185,8,22,1,22,0,0,23,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,40,42,44,0,3,2,0,17,17,34,34,1,0,28,
  	29,1,0,2,3,185,0,49,1,0,0,0,2,51,1,0,0,0,4,57,1,0,0,0,6,65,1,0,0,0,8,
  	67,1,0,0,0,10,71,1,0,0,0,12,75,1,0,0,0,14,92,1,0,0,0,16,96,1,0,0,0,18,
  	100,1,0,0,0,20,110,1,0,0,0,22,114,1,0,0,0,24,125,1,0,0,0,26,129,1,0,0,
  	0,28,140,1,0,0,0,30,149,1,0,0,0,32,151,1,0,0,0,34,156,1,0,0,0,36,158,
  	1,0,0,0,38,172,1,0,0,0,40,176,1,0,0,0,42,178,1,0,0,0,44,184,1,0,0,0,46,
  	50,3,14,7,0,47,50,3,28,14,0,48,50,3,2,1,0,49,46,1,0,0,0,49,47,1,0,0,0,
  	49,48,1,0,0,0,50,1,1,0,0,0,51,52,5,28,0,0,52,53,5,14,0,0,53,3,1,0,0,0,
  	54,56,3,6,3,0,55,54,1,0,0,0,56,59,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,
  	58,60,1,0,0,0,59,57,1,0,0,0,60,61,5,0,0,1,61,5,1,0,0,0,62,66,3,10,5,0,
  	63,66,3,8,4,0,64,66,3,12,6,0,65,62,1,0,0,0,65,63,1,0,0,0,65,64,1,0,0,
  	0,66,7,1,0,0,0,67,68,5,6,0,0,68,69,5,17,0,0,69,70,3,22,11,0,70,9,1,0,
  	0,0,71,72,5,5,0,0,72,73,5,14,0,0,73,74,3,22,11,0,74,11,1,0,0,0,75,76,
  	5,6,0,0,76,77,5,17,0,0,77,79,3,44,22,0,78,80,5,22,0,0,79,78,1,0,0,0,79,
  	80,1,0,0,0,80,81,1,0,0,0,81,83,3,14,7,0,82,84,5,23,0,0,83,82,1,0,0,0,
  	83,84,1,0,0,0,84,85,1,0,0,0,85,86,3,22,11,0,86,13,1,0,0,0,87,93,5,34,
  	0,0,88,93,5,17,0,0,89,93,5,14,0,0,90,93,5,15,0,0,91,93,3,34,17,0,92,87,
  	1,0,0,0,92,88,1,0,0,0,92,89,1,0,0,0,92,90,1,0,0,0,92,91,1,0,0,0,93,15,
  	1,0,0,0,94,97,3,18,9,0,95,97,3,32,16,0,96,94,1,0,0,0,96,95,1,0,0,0,97,
  	98,1,0,0,0,98,99,5,1,0,0,99,17,1,0,0,0,100,102,5,14,0,0,101,103,3,20,
  	10,0,102,101,1,0,0,0,102,103,1,0,0,0,103,104,1,0,0,0,104,106,5,22,0,0,
  	105,107,3,26,13,0,106,105,1,0,0,0,106,107,1,0,0,0,107,108,1,0,0,0,108,
  	109,5,23,0,0,109,19,1,0,0,0,110,111,5,32,0,0,111,112,3,42,21,0,112,113,
  	5,33,0,0,113,21,1,0,0,0,114,121,5,30,0,0,115,117,3,16,8,0,116,115,1,0,
  	0,0,117,118,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,122,1,0,0,0,120,
  	122,3,24,12,0,121,116,1,0,0,0,121,120,1,0,0,0,122,123,1,0,0,0,123,124,
  	5,31,0,0,124,23,1,0,0,0,125,126,5,10,0,0,126,127,5,12,0,0,127,128,5,1,
  	0,0,128,25,1,0,0,0,129,134,3,0,0,0,130,131,5,24,0,0,131,133,3,0,0,0,132,
  	130,1,0,0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,138,1,
  	0,0,0,136,134,1,0,0,0,137,139,5,24,0,0,138,137,1,0,0,0,138,139,1,0,0,
  	0,139,27,1,0,0,0,140,141,5,13,0,0,141,142,5,32,0,0,142,143,5,2,0,0,143,
  	144,5,24,0,0,144,145,3,30,15,0,145,146,5,24,0,0,146,147,3,30,15,0,147,
  	148,5,33,0,0,148,29,1,0,0,0,149,150,7,0,0,0,150,31,1,0,0,0,151,152,7,
  	1,0,0,152,153,5,14,0,0,153,33,1,0,0,0,154,157,3,40,20,0,155,157,3,36,
  	18,0,156,154,1,0,0,0,156,155,1,0,0,0,157,35,1,0,0,0,158,159,5,30,0,0,
  	159,164,3,38,19,0,160,161,5,24,0,0,161,163,3,38,19,0,162,160,1,0,0,0,
  	163,166,1,0,0,0,164,162,1,0,0,0,164,165,1,0,0,0,165,168,1,0,0,0,166,164,
  	1,0,0,0,167,169,5,24,0,0,168,167,1,0,0,0,168,169,1,0,0,0,169,170,1,0,
  	0,0,170,171,5,31,0,0,171,37,1,0,0,0,172,173,5,14,0,0,173,174,5,26,0,0,
  	174,175,3,40,20,0,175,39,1,0,0,0,176,177,7,2,0,0,177,41,1,0,0,0,178,179,
  	5,14,0,0,179,180,3,14,7,0,180,43,1,0,0,0,181,182,5,11,0,0,182,185,5,14,
  	0,0,183,185,5,4,0,0,184,181,1,0,0,0,184,183,1,0,0,0,185,45,1,0,0,0,17,
  	49,57,65,79,83,92,96,102,106,118,121,134,138,156,164,168,184
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ssbscriptParserStaticData = staticData.release();
}

}

SsbScriptParser::SsbScriptParser(TokenStream *input) : SsbScriptParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SsbScriptParser::SsbScriptParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SsbScriptParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ssbscriptParserStaticData->atn, ssbscriptParserStaticData->decisionToDFA, ssbscriptParserStaticData->sharedContextCache, options);
}

SsbScriptParser::~SsbScriptParser() {
  delete _interpreter;
}

const atn::ATN& SsbScriptParser::getATN() const {
  return *ssbscriptParserStaticData->atn;
}

std::string SsbScriptParser::getGrammarFileName() const {
  return "SsbScript.g4";
}

const std::vector<std::string>& SsbScriptParser::getRuleNames() const {
  return ssbscriptParserStaticData->ruleNames;
}

const dfa::Vocabulary& SsbScriptParser::getVocabulary() const {
  return ssbscriptParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SsbScriptParser::getSerializedATN() const {
  return ssbscriptParserStaticData->serializedATN;
}


//----------------- Pos_argumentContext ------------------------------------------------------------------

SsbScriptParser::Pos_argumentContext::Pos_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SsbScriptParser::PrimitiveContext* SsbScriptParser::Pos_argumentContext::primitive() {
  return getRuleContext<SsbScriptParser::PrimitiveContext>(0);
}

SsbScriptParser::Position_markerContext* SsbScriptParser::Pos_argumentContext::position_marker() {
  return getRuleContext<SsbScriptParser::Position_markerContext>(0);
}

SsbScriptParser::Jump_markerContext* SsbScriptParser::Pos_argumentContext::jump_marker() {
  return getRuleContext<SsbScriptParser::Jump_markerContext>(0);
}


size_t SsbScriptParser::Pos_argumentContext::getRuleIndex() const {
  return SsbScriptParser::RulePos_argument;
}


std::any SsbScriptParser::Pos_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitPos_argument(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Pos_argumentContext* SsbScriptParser::pos_argument() {
  Pos_argumentContext *_localctx = _tracker.createInstance<Pos_argumentContext>(_ctx, getState());
  enterRule(_localctx, 0, SsbScriptParser::RulePos_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::STRING_LITERAL:
      case SsbScriptParser::MULTILINE_STRING_LITERAL:
      case SsbScriptParser::IDENTIFIER:
      case SsbScriptParser::VARIABLE:
      case SsbScriptParser::INTEGER:
      case SsbScriptParser::OPEN_BRACE:
      case SsbScriptParser::DECIMAL: {
        enterOuterAlt(_localctx, 1);
        setState(46);
        primitive();
        break;
      }

      case SsbScriptParser::POSITION: {
        enterOuterAlt(_localctx, 2);
        setState(47);
        position_marker();
        break;
      }

      case SsbScriptParser::AT: {
        enterOuterAlt(_localctx, 3);
        setState(48);
        jump_marker();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Jump_markerContext ------------------------------------------------------------------

SsbScriptParser::Jump_markerContext::Jump_markerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Jump_markerContext::AT() {
  return getToken(SsbScriptParser::AT, 0);
}

tree::TerminalNode* SsbScriptParser::Jump_markerContext::IDENTIFIER() {
  return getToken(SsbScriptParser::IDENTIFIER, 0);
}


size_t SsbScriptParser::Jump_markerContext::getRuleIndex() const {
  return SsbScriptParser::RuleJump_marker;
}


std::any SsbScriptParser::Jump_markerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitJump_marker(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Jump_markerContext* SsbScriptParser::jump_marker() {
  Jump_markerContext *_localctx = _tracker.createInstance<Jump_markerContext>(_ctx, getState());
  enterRule(_localctx, 2, SsbScriptParser::RuleJump_marker);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(SsbScriptParser::AT);
    setState(52);
    match(SsbScriptParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartContext ------------------------------------------------------------------

SsbScriptParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::StartContext::EOF() {
  return getToken(SsbScriptParser::EOF, 0);
}

std::vector<SsbScriptParser::FuncdefContext *> SsbScriptParser::StartContext::funcdef() {
  return getRuleContexts<SsbScriptParser::FuncdefContext>();
}

SsbScriptParser::FuncdefContext* SsbScriptParser::StartContext::funcdef(size_t i) {
  return getRuleContext<SsbScriptParser::FuncdefContext>(i);
}


size_t SsbScriptParser::StartContext::getRuleIndex() const {
  return SsbScriptParser::RuleStart;
}


std::any SsbScriptParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::StartContext* SsbScriptParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 4, SsbScriptParser::RuleStart);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SsbScriptParser::CORO

    || _la == SsbScriptParser::DEF) {
      setState(54);
      funcdef();
      setState(59);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(60);
    match(SsbScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncdefContext ------------------------------------------------------------------

SsbScriptParser::FuncdefContext::FuncdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SsbScriptParser::Coro_defContext* SsbScriptParser::FuncdefContext::coro_def() {
  return getRuleContext<SsbScriptParser::Coro_defContext>(0);
}

SsbScriptParser::Simple_defContext* SsbScriptParser::FuncdefContext::simple_def() {
  return getRuleContext<SsbScriptParser::Simple_defContext>(0);
}

SsbScriptParser::For_target_defContext* SsbScriptParser::FuncdefContext::for_target_def() {
  return getRuleContext<SsbScriptParser::For_target_defContext>(0);
}


size_t SsbScriptParser::FuncdefContext::getRuleIndex() const {
  return SsbScriptParser::RuleFuncdef;
}


std::any SsbScriptParser::FuncdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitFuncdef(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::FuncdefContext* SsbScriptParser::funcdef() {
  FuncdefContext *_localctx = _tracker.createInstance<FuncdefContext>(_ctx, getState());
  enterRule(_localctx, 6, SsbScriptParser::RuleFuncdef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(65);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(62);
      coro_def();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(63);
      simple_def();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(64);
      for_target_def();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_defContext ------------------------------------------------------------------

SsbScriptParser::Simple_defContext::Simple_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Simple_defContext::DEF() {
  return getToken(SsbScriptParser::DEF, 0);
}

tree::TerminalNode* SsbScriptParser::Simple_defContext::INTEGER() {
  return getToken(SsbScriptParser::INTEGER, 0);
}

SsbScriptParser::Func_suiteContext* SsbScriptParser::Simple_defContext::func_suite() {
  return getRuleContext<SsbScriptParser::Func_suiteContext>(0);
}


size_t SsbScriptParser::Simple_defContext::getRuleIndex() const {
  return SsbScriptParser::RuleSimple_def;
}


std::any SsbScriptParser::Simple_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitSimple_def(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Simple_defContext* SsbScriptParser::simple_def() {
  Simple_defContext *_localctx = _tracker.createInstance<Simple_defContext>(_ctx, getState());
  enterRule(_localctx, 8, SsbScriptParser::RuleSimple_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(SsbScriptParser::DEF);
    setState(68);
    match(SsbScriptParser::INTEGER);
    setState(69);
    func_suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Coro_defContext ------------------------------------------------------------------

SsbScriptParser::Coro_defContext::Coro_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Coro_defContext::CORO() {
  return getToken(SsbScriptParser::CORO, 0);
}

tree::TerminalNode* SsbScriptParser::Coro_defContext::IDENTIFIER() {
  return getToken(SsbScriptParser::IDENTIFIER, 0);
}

SsbScriptParser::Func_suiteContext* SsbScriptParser::Coro_defContext::func_suite() {
  return getRuleContext<SsbScriptParser::Func_suiteContext>(0);
}


size_t SsbScriptParser::Coro_defContext::getRuleIndex() const {
  return SsbScriptParser::RuleCoro_def;
}


std::any SsbScriptParser::Coro_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitCoro_def(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Coro_defContext* SsbScriptParser::coro_def() {
  Coro_defContext *_localctx = _tracker.createInstance<Coro_defContext>(_ctx, getState());
  enterRule(_localctx, 10, SsbScriptParser::RuleCoro_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(SsbScriptParser::CORO);
    setState(72);
    match(SsbScriptParser::IDENTIFIER);
    setState(73);
    func_suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_target_defContext ------------------------------------------------------------------

SsbScriptParser::For_target_defContext::For_target_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::For_target_defContext::DEF() {
  return getToken(SsbScriptParser::DEF, 0);
}

tree::TerminalNode* SsbScriptParser::For_target_defContext::INTEGER() {
  return getToken(SsbScriptParser::INTEGER, 0);
}

SsbScriptParser::For_target_def_targetContext* SsbScriptParser::For_target_defContext::for_target_def_target() {
  return getRuleContext<SsbScriptParser::For_target_def_targetContext>(0);
}

SsbScriptParser::PrimitiveContext* SsbScriptParser::For_target_defContext::primitive() {
  return getRuleContext<SsbScriptParser::PrimitiveContext>(0);
}

SsbScriptParser::Func_suiteContext* SsbScriptParser::For_target_defContext::func_suite() {
  return getRuleContext<SsbScriptParser::Func_suiteContext>(0);
}

tree::TerminalNode* SsbScriptParser::For_target_defContext::OPEN_PAREN() {
  return getToken(SsbScriptParser::OPEN_PAREN, 0);
}

tree::TerminalNode* SsbScriptParser::For_target_defContext::CLOSE_PAREN() {
  return getToken(SsbScriptParser::CLOSE_PAREN, 0);
}


size_t SsbScriptParser::For_target_defContext::getRuleIndex() const {
  return SsbScriptParser::RuleFor_target_def;
}


std::any SsbScriptParser::For_target_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitFor_target_def(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::For_target_defContext* SsbScriptParser::for_target_def() {
  For_target_defContext *_localctx = _tracker.createInstance<For_target_defContext>(_ctx, getState());
  enterRule(_localctx, 12, SsbScriptParser::RuleFor_target_def);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(SsbScriptParser::DEF);
    setState(76);
    match(SsbScriptParser::INTEGER);
    setState(77);
    for_target_def_target();
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::OPEN_PAREN) {
      setState(78);
      match(SsbScriptParser::OPEN_PAREN);
    }
    setState(81);
    primitive();
    setState(83);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::CLOSE_PAREN) {
      setState(82);
      match(SsbScriptParser::CLOSE_PAREN);
    }
    setState(85);
    func_suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimitiveContext ------------------------------------------------------------------

SsbScriptParser::PrimitiveContext::PrimitiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::PrimitiveContext::DECIMAL() {
  return getToken(SsbScriptParser::DECIMAL, 0);
}

tree::TerminalNode* SsbScriptParser::PrimitiveContext::INTEGER() {
  return getToken(SsbScriptParser::INTEGER, 0);
}

tree::TerminalNode* SsbScriptParser::PrimitiveContext::IDENTIFIER() {
  return getToken(SsbScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* SsbScriptParser::PrimitiveContext::VARIABLE() {
  return getToken(SsbScriptParser::VARIABLE, 0);
}

SsbScriptParser::StringContext* SsbScriptParser::PrimitiveContext::string() {
  return getRuleContext<SsbScriptParser::StringContext>(0);
}


size_t SsbScriptParser::PrimitiveContext::getRuleIndex() const {
  return SsbScriptParser::RulePrimitive;
}


std::any SsbScriptParser::PrimitiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitPrimitive(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::PrimitiveContext* SsbScriptParser::primitive() {
  PrimitiveContext *_localctx = _tracker.createInstance<PrimitiveContext>(_ctx, getState());
  enterRule(_localctx, 14, SsbScriptParser::RulePrimitive);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::DECIMAL: {
        enterOuterAlt(_localctx, 1);
        setState(87);
        match(SsbScriptParser::DECIMAL);
        break;
      }

      case SsbScriptParser::INTEGER: {
        enterOuterAlt(_localctx, 2);
        setState(88);
        match(SsbScriptParser::INTEGER);
        break;
      }

      case SsbScriptParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(89);
        match(SsbScriptParser::IDENTIFIER);
        break;
      }

      case SsbScriptParser::VARIABLE: {
        enterOuterAlt(_localctx, 4);
        setState(90);
        match(SsbScriptParser::VARIABLE);
        break;
      }

      case SsbScriptParser::STRING_LITERAL:
      case SsbScriptParser::MULTILINE_STRING_LITERAL:
      case SsbScriptParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 5);
        setState(91);
        string();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

SsbScriptParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SsbScriptParser::OperationContext* SsbScriptParser::StmtContext::operation() {
  return getRuleContext<SsbScriptParser::OperationContext>(0);
}

SsbScriptParser::LabelContext* SsbScriptParser::StmtContext::label() {
  return getRuleContext<SsbScriptParser::LabelContext>(0);
}


size_t SsbScriptParser::StmtContext::getRuleIndex() const {
  return SsbScriptParser::RuleStmt;
}


std::any SsbScriptParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::StmtContext* SsbScriptParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 16, SsbScriptParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::IDENTIFIER: {
        setState(94);
        operation();
        break;
      }

      case SsbScriptParser::AT:
      case SsbScriptParser::PARAGRAPH: {
        setState(95);
        label();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(98);
    match(SsbScriptParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

SsbScriptParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::OperationContext::IDENTIFIER() {
  return getToken(SsbScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* SsbScriptParser::OperationContext::OPEN_PAREN() {
  return getToken(SsbScriptParser::OPEN_PAREN, 0);
}

tree::TerminalNode* SsbScriptParser::OperationContext::CLOSE_PAREN() {
  return getToken(SsbScriptParser::CLOSE_PAREN, 0);
}

SsbScriptParser::Inline_ctxContext* SsbScriptParser::OperationContext::inline_ctx() {
  return getRuleContext<SsbScriptParser::Inline_ctxContext>(0);
}

SsbScriptParser::ArglistContext* SsbScriptParser::OperationContext::arglist() {
  return getRuleContext<SsbScriptParser::ArglistContext>(0);
}


size_t SsbScriptParser::OperationContext::getRuleIndex() const {
  return SsbScriptParser::RuleOperation;
}


std::any SsbScriptParser::OperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitOperation(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::OperationContext* SsbScriptParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 18, SsbScriptParser::RuleOperation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    match(SsbScriptParser::IDENTIFIER);
    setState(102);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::OPEN_SHARP) {
      setState(101);
      inline_ctx();
    }
    setState(104);
    match(SsbScriptParser::OPEN_PAREN);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 18522234892) != 0)) {
      setState(105);
      arglist();
    }
    setState(108);
    match(SsbScriptParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Inline_ctxContext ------------------------------------------------------------------

SsbScriptParser::Inline_ctxContext::Inline_ctxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Inline_ctxContext::OPEN_SHARP() {
  return getToken(SsbScriptParser::OPEN_SHARP, 0);
}

SsbScriptParser::Ctx_headerContext* SsbScriptParser::Inline_ctxContext::ctx_header() {
  return getRuleContext<SsbScriptParser::Ctx_headerContext>(0);
}

tree::TerminalNode* SsbScriptParser::Inline_ctxContext::CLOSE_SHARP() {
  return getToken(SsbScriptParser::CLOSE_SHARP, 0);
}


size_t SsbScriptParser::Inline_ctxContext::getRuleIndex() const {
  return SsbScriptParser::RuleInline_ctx;
}


std::any SsbScriptParser::Inline_ctxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitInline_ctx(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Inline_ctxContext* SsbScriptParser::inline_ctx() {
  Inline_ctxContext *_localctx = _tracker.createInstance<Inline_ctxContext>(_ctx, getState());
  enterRule(_localctx, 20, SsbScriptParser::RuleInline_ctx);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    match(SsbScriptParser::OPEN_SHARP);
    setState(111);
    ctx_header();
    setState(112);
    match(SsbScriptParser::CLOSE_SHARP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_suiteContext ------------------------------------------------------------------

SsbScriptParser::Func_suiteContext::Func_suiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Func_suiteContext::OPEN_BRACE() {
  return getToken(SsbScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* SsbScriptParser::Func_suiteContext::CLOSE_BRACE() {
  return getToken(SsbScriptParser::CLOSE_BRACE, 0);
}

SsbScriptParser::Func_aliasContext* SsbScriptParser::Func_suiteContext::func_alias() {
  return getRuleContext<SsbScriptParser::Func_aliasContext>(0);
}

std::vector<SsbScriptParser::StmtContext *> SsbScriptParser::Func_suiteContext::stmt() {
  return getRuleContexts<SsbScriptParser::StmtContext>();
}

SsbScriptParser::StmtContext* SsbScriptParser::Func_suiteContext::stmt(size_t i) {
  return getRuleContext<SsbScriptParser::StmtContext>(i);
}


size_t SsbScriptParser::Func_suiteContext::getRuleIndex() const {
  return SsbScriptParser::RuleFunc_suite;
}


std::any SsbScriptParser::Func_suiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitFunc_suite(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Func_suiteContext* SsbScriptParser::func_suite() {
  Func_suiteContext *_localctx = _tracker.createInstance<Func_suiteContext>(_ctx, getState());
  enterRule(_localctx, 22, SsbScriptParser::RuleFunc_suite);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(SsbScriptParser::OPEN_BRACE);
    setState(121);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::IDENTIFIER:
      case SsbScriptParser::AT:
      case SsbScriptParser::PARAGRAPH: {
        setState(116); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(115);
          stmt();
          setState(118); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 805322752) != 0));
        break;
      }

      case SsbScriptParser::ALIAS: {
        setState(120);
        func_alias();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(123);
    match(SsbScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_aliasContext ------------------------------------------------------------------

SsbScriptParser::Func_aliasContext::Func_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Func_aliasContext::ALIAS() {
  return getToken(SsbScriptParser::ALIAS, 0);
}

tree::TerminalNode* SsbScriptParser::Func_aliasContext::PREVIOUS() {
  return getToken(SsbScriptParser::PREVIOUS, 0);
}


size_t SsbScriptParser::Func_aliasContext::getRuleIndex() const {
  return SsbScriptParser::RuleFunc_alias;
}


std::any SsbScriptParser::Func_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitFunc_alias(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Func_aliasContext* SsbScriptParser::func_alias() {
  Func_aliasContext *_localctx = _tracker.createInstance<Func_aliasContext>(_ctx, getState());
  enterRule(_localctx, 24, SsbScriptParser::RuleFunc_alias);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(SsbScriptParser::ALIAS);
    setState(126);
    match(SsbScriptParser::PREVIOUS);
    setState(127);
    match(SsbScriptParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

SsbScriptParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SsbScriptParser::Pos_argumentContext *> SsbScriptParser::ArglistContext::pos_argument() {
  return getRuleContexts<SsbScriptParser::Pos_argumentContext>();
}

SsbScriptParser::Pos_argumentContext* SsbScriptParser::ArglistContext::pos_argument(size_t i) {
  return getRuleContext<SsbScriptParser::Pos_argumentContext>(i);
}

std::vector<tree::TerminalNode *> SsbScriptParser::ArglistContext::COMMA() {
  return getTokens(SsbScriptParser::COMMA);
}

tree::TerminalNode* SsbScriptParser::ArglistContext::COMMA(size_t i) {
  return getToken(SsbScriptParser::COMMA, i);
}


size_t SsbScriptParser::ArglistContext::getRuleIndex() const {
  return SsbScriptParser::RuleArglist;
}


std::any SsbScriptParser::ArglistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitArglist(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::ArglistContext* SsbScriptParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 26, SsbScriptParser::RuleArglist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(129);
    pos_argument();
    setState(134);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(130);
        match(SsbScriptParser::COMMA);
        setState(131);
        pos_argument(); 
      }
      setState(136);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::COMMA) {
      setState(137);
      match(SsbScriptParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Position_markerContext ------------------------------------------------------------------

SsbScriptParser::Position_markerContext::Position_markerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Position_markerContext::POSITION() {
  return getToken(SsbScriptParser::POSITION, 0);
}

tree::TerminalNode* SsbScriptParser::Position_markerContext::OPEN_SHARP() {
  return getToken(SsbScriptParser::OPEN_SHARP, 0);
}

tree::TerminalNode* SsbScriptParser::Position_markerContext::STRING_LITERAL() {
  return getToken(SsbScriptParser::STRING_LITERAL, 0);
}

std::vector<tree::TerminalNode *> SsbScriptParser::Position_markerContext::COMMA() {
  return getTokens(SsbScriptParser::COMMA);
}

tree::TerminalNode* SsbScriptParser::Position_markerContext::COMMA(size_t i) {
  return getToken(SsbScriptParser::COMMA, i);
}

std::vector<SsbScriptParser::Position_marker_argContext *> SsbScriptParser::Position_markerContext::position_marker_arg() {
  return getRuleContexts<SsbScriptParser::Position_marker_argContext>();
}

SsbScriptParser::Position_marker_argContext* SsbScriptParser::Position_markerContext::position_marker_arg(size_t i) {
  return getRuleContext<SsbScriptParser::Position_marker_argContext>(i);
}

tree::TerminalNode* SsbScriptParser::Position_markerContext::CLOSE_SHARP() {
  return getToken(SsbScriptParser::CLOSE_SHARP, 0);
}


size_t SsbScriptParser::Position_markerContext::getRuleIndex() const {
  return SsbScriptParser::RulePosition_marker;
}


std::any SsbScriptParser::Position_markerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitPosition_marker(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Position_markerContext* SsbScriptParser::position_marker() {
  Position_markerContext *_localctx = _tracker.createInstance<Position_markerContext>(_ctx, getState());
  enterRule(_localctx, 28, SsbScriptParser::RulePosition_marker);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(SsbScriptParser::POSITION);
    setState(141);
    match(SsbScriptParser::OPEN_SHARP);
    setState(142);
    match(SsbScriptParser::STRING_LITERAL);
    setState(143);
    match(SsbScriptParser::COMMA);
    setState(144);
    position_marker_arg();
    setState(145);
    match(SsbScriptParser::COMMA);
    setState(146);
    position_marker_arg();
    setState(147);
    match(SsbScriptParser::CLOSE_SHARP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Position_marker_argContext ------------------------------------------------------------------

SsbScriptParser::Position_marker_argContext::Position_marker_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Position_marker_argContext::INTEGER() {
  return getToken(SsbScriptParser::INTEGER, 0);
}

tree::TerminalNode* SsbScriptParser::Position_marker_argContext::DECIMAL() {
  return getToken(SsbScriptParser::DECIMAL, 0);
}


size_t SsbScriptParser::Position_marker_argContext::getRuleIndex() const {
  return SsbScriptParser::RulePosition_marker_arg;
}


std::any SsbScriptParser::Position_marker_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitPosition_marker_arg(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Position_marker_argContext* SsbScriptParser::position_marker_arg() {
  Position_marker_argContext *_localctx = _tracker.createInstance<Position_marker_argContext>(_ctx, getState());
  enterRule(_localctx, 30, SsbScriptParser::RulePosition_marker_arg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    _la = _input->LA(1);
    if (!(_la == SsbScriptParser::INTEGER

    || _la == SsbScriptParser::DECIMAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

SsbScriptParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::LabelContext::IDENTIFIER() {
  return getToken(SsbScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* SsbScriptParser::LabelContext::PARAGRAPH() {
  return getToken(SsbScriptParser::PARAGRAPH, 0);
}

tree::TerminalNode* SsbScriptParser::LabelContext::AT() {
  return getToken(SsbScriptParser::AT, 0);
}


size_t SsbScriptParser::LabelContext::getRuleIndex() const {
  return SsbScriptParser::RuleLabel;
}


std::any SsbScriptParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::LabelContext* SsbScriptParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 32, SsbScriptParser::RuleLabel);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    _la = _input->LA(1);
    if (!(_la == SsbScriptParser::AT

    || _la == SsbScriptParser::PARAGRAPH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(152);
    match(SsbScriptParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

SsbScriptParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SsbScriptParser::String_valueContext* SsbScriptParser::StringContext::string_value() {
  return getRuleContext<SsbScriptParser::String_valueContext>(0);
}

SsbScriptParser::Lang_stringContext* SsbScriptParser::StringContext::lang_string() {
  return getRuleContext<SsbScriptParser::Lang_stringContext>(0);
}


size_t SsbScriptParser::StringContext::getRuleIndex() const {
  return SsbScriptParser::RuleString;
}


std::any SsbScriptParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::StringContext* SsbScriptParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 34, SsbScriptParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::STRING_LITERAL:
      case SsbScriptParser::MULTILINE_STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(154);
        string_value();
        break;
      }

      case SsbScriptParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(155);
        lang_string();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Lang_stringContext ------------------------------------------------------------------

SsbScriptParser::Lang_stringContext::Lang_stringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Lang_stringContext::OPEN_BRACE() {
  return getToken(SsbScriptParser::OPEN_BRACE, 0);
}

std::vector<SsbScriptParser::Lang_string_argumentContext *> SsbScriptParser::Lang_stringContext::lang_string_argument() {
  return getRuleContexts<SsbScriptParser::Lang_string_argumentContext>();
}

SsbScriptParser::Lang_string_argumentContext* SsbScriptParser::Lang_stringContext::lang_string_argument(size_t i) {
  return getRuleContext<SsbScriptParser::Lang_string_argumentContext>(i);
}

tree::TerminalNode* SsbScriptParser::Lang_stringContext::CLOSE_BRACE() {
  return getToken(SsbScriptParser::CLOSE_BRACE, 0);
}

std::vector<tree::TerminalNode *> SsbScriptParser::Lang_stringContext::COMMA() {
  return getTokens(SsbScriptParser::COMMA);
}

tree::TerminalNode* SsbScriptParser::Lang_stringContext::COMMA(size_t i) {
  return getToken(SsbScriptParser::COMMA, i);
}


size_t SsbScriptParser::Lang_stringContext::getRuleIndex() const {
  return SsbScriptParser::RuleLang_string;
}


std::any SsbScriptParser::Lang_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitLang_string(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Lang_stringContext* SsbScriptParser::lang_string() {
  Lang_stringContext *_localctx = _tracker.createInstance<Lang_stringContext>(_ctx, getState());
  enterRule(_localctx, 36, SsbScriptParser::RuleLang_string);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(SsbScriptParser::OPEN_BRACE);
    setState(159);
    lang_string_argument();
    setState(164);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(160);
        match(SsbScriptParser::COMMA);
        setState(161);
        lang_string_argument(); 
      }
      setState(166);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::COMMA) {
      setState(167);
      match(SsbScriptParser::COMMA);
    }
    setState(170);
    match(SsbScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Lang_string_argumentContext ------------------------------------------------------------------

SsbScriptParser::Lang_string_argumentContext::Lang_string_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Lang_string_argumentContext::IDENTIFIER() {
  return getToken(SsbScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* SsbScriptParser::Lang_string_argumentContext::ASSIGN() {
  return getToken(SsbScriptParser::ASSIGN, 0);
}

SsbScriptParser::String_valueContext* SsbScriptParser::Lang_string_argumentContext::string_value() {
  return getRuleContext<SsbScriptParser::String_valueContext>(0);
}


size_t SsbScriptParser::Lang_string_argumentContext::getRuleIndex() const {
  return SsbScriptParser::RuleLang_string_argument;
}


std::any SsbScriptParser::Lang_string_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitLang_string_argument(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Lang_string_argumentContext* SsbScriptParser::lang_string_argument() {
  Lang_string_argumentContext *_localctx = _tracker.createInstance<Lang_string_argumentContext>(_ctx, getState());
  enterRule(_localctx, 38, SsbScriptParser::RuleLang_string_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(SsbScriptParser::IDENTIFIER);
    setState(173);
    match(SsbScriptParser::ASSIGN);
    setState(174);
    string_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- String_valueContext ------------------------------------------------------------------

SsbScriptParser::String_valueContext::String_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::String_valueContext::MULTILINE_STRING_LITERAL() {
  return getToken(SsbScriptParser::MULTILINE_STRING_LITERAL, 0);
}

tree::TerminalNode* SsbScriptParser::String_valueContext::STRING_LITERAL() {
  return getToken(SsbScriptParser::STRING_LITERAL, 0);
}


size_t SsbScriptParser::String_valueContext::getRuleIndex() const {
  return SsbScriptParser::RuleString_value;
}


std::any SsbScriptParser::String_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitString_value(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::String_valueContext* SsbScriptParser::string_value() {
  String_valueContext *_localctx = _tracker.createInstance<String_valueContext>(_ctx, getState());
  enterRule(_localctx, 40, SsbScriptParser::RuleString_value);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    _la = _input->LA(1);
    if (!(_la == SsbScriptParser::STRING_LITERAL

    || _la == SsbScriptParser::MULTILINE_STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ctx_headerContext ------------------------------------------------------------------

SsbScriptParser::Ctx_headerContext::Ctx_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Ctx_headerContext::IDENTIFIER() {
  return getToken(SsbScriptParser::IDENTIFIER, 0);
}

SsbScriptParser::PrimitiveContext* SsbScriptParser::Ctx_headerContext::primitive() {
  return getRuleContext<SsbScriptParser::PrimitiveContext>(0);
}


size_t SsbScriptParser::Ctx_headerContext::getRuleIndex() const {
  return SsbScriptParser::RuleCtx_header;
}


std::any SsbScriptParser::Ctx_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitCtx_header(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::Ctx_headerContext* SsbScriptParser::ctx_header() {
  Ctx_headerContext *_localctx = _tracker.createInstance<Ctx_headerContext>(_ctx, getState());
  enterRule(_localctx, 42, SsbScriptParser::RuleCtx_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(SsbScriptParser::IDENTIFIER);
    setState(179);
    primitive();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_target_def_targetContext ------------------------------------------------------------------

SsbScriptParser::For_target_def_targetContext::For_target_def_targetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::For_target_def_targetContext::FOR() {
  return getToken(SsbScriptParser::FOR, 0);
}

tree::TerminalNode* SsbScriptParser::For_target_def_targetContext::IDENTIFIER() {
  return getToken(SsbScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* SsbScriptParser::For_target_def_targetContext::FOR_TARGET() {
  return getToken(SsbScriptParser::FOR_TARGET, 0);
}


size_t SsbScriptParser::For_target_def_targetContext::getRuleIndex() const {
  return SsbScriptParser::RuleFor_target_def_target;
}


std::any SsbScriptParser::For_target_def_targetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SsbScriptVisitor*>(visitor))
    return parserVisitor->visitFor_target_def_target(this);
  else
    return visitor->visitChildren(this);
}

SsbScriptParser::For_target_def_targetContext* SsbScriptParser::for_target_def_target() {
  For_target_def_targetContext *_localctx = _tracker.createInstance<For_target_def_targetContext>(_ctx, getState());
  enterRule(_localctx, 44, SsbScriptParser::RuleFor_target_def_target);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(184);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::FOR: {
        enterOuterAlt(_localctx, 1);
        setState(181);
        match(SsbScriptParser::FOR);
        setState(182);
        match(SsbScriptParser::IDENTIFIER);
        break;
      }

      case SsbScriptParser::FOR_TARGET: {
        enterOuterAlt(_localctx, 2);
        setState(183);
        match(SsbScriptParser::FOR_TARGET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void SsbScriptParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ssbscriptParserInitialize();
#else
  ::antlr4::internal::call_once(ssbscriptParserOnceFlag, ssbscriptParserInitialize);
#endif
}
