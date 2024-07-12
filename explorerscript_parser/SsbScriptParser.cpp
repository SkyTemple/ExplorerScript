
// Generated from SsbScript.g4 by ANTLR 4.13.0


#include "SsbScriptListener.h"

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
      "for_target_def", "integer_like", "stmt", "operation", "inline_ctx", 
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
  	4,1,36,183,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,0,1,0,3,0,51,8,0,1,1,1,1,1,1,1,2,5,2,57,8,2,10,
  	2,12,2,60,9,2,1,2,1,2,1,3,1,3,1,3,3,3,67,8,3,1,4,1,4,1,4,1,4,1,5,1,5,
  	1,5,1,5,1,6,1,6,1,6,1,6,3,6,81,8,6,1,6,1,6,3,6,85,8,6,1,6,1,6,1,7,1,7,
  	1,8,1,8,3,8,93,8,8,1,8,1,8,1,9,1,9,3,9,99,8,9,1,9,1,9,3,9,103,8,9,1,9,
  	1,9,1,10,1,10,1,10,1,10,1,11,1,11,4,11,113,8,11,11,11,12,11,114,1,11,
  	3,11,118,8,11,1,11,1,11,1,12,1,12,1,12,1,12,1,13,1,13,1,13,5,13,129,8,
  	13,10,13,12,13,132,9,13,1,13,3,13,135,8,13,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,15,1,15,1,16,1,16,1,16,1,17,1,17,3,17,153,8,17,1,
  	18,1,18,1,18,1,18,5,18,159,8,18,10,18,12,18,162,9,18,1,18,3,18,165,8,
  	18,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,20,1,21,1,21,1,21,1,22,1,22,1,
  	22,3,22,181,8,22,1,22,0,0,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,0,4,3,0,14,15,17,17,34,34,2,0,17,17,34,34,1,0,
  	28,29,1,0,2,3,178,0,50,1,0,0,0,2,52,1,0,0,0,4,58,1,0,0,0,6,66,1,0,0,0,
  	8,68,1,0,0,0,10,72,1,0,0,0,12,76,1,0,0,0,14,88,1,0,0,0,16,92,1,0,0,0,
  	18,96,1,0,0,0,20,106,1,0,0,0,22,110,1,0,0,0,24,121,1,0,0,0,26,125,1,0,
  	0,0,28,136,1,0,0,0,30,145,1,0,0,0,32,147,1,0,0,0,34,152,1,0,0,0,36,154,
  	1,0,0,0,38,168,1,0,0,0,40,172,1,0,0,0,42,174,1,0,0,0,44,180,1,0,0,0,46,
  	51,3,14,7,0,47,51,3,34,17,0,48,51,3,28,14,0,49,51,3,2,1,0,50,46,1,0,0,
  	0,50,47,1,0,0,0,50,48,1,0,0,0,50,49,1,0,0,0,51,1,1,0,0,0,52,53,5,28,0,
  	0,53,54,5,14,0,0,54,3,1,0,0,0,55,57,3,6,3,0,56,55,1,0,0,0,57,60,1,0,0,
  	0,58,56,1,0,0,0,58,59,1,0,0,0,59,61,1,0,0,0,60,58,1,0,0,0,61,62,5,0,0,
  	1,62,5,1,0,0,0,63,67,3,10,5,0,64,67,3,8,4,0,65,67,3,12,6,0,66,63,1,0,
  	0,0,66,64,1,0,0,0,66,65,1,0,0,0,67,7,1,0,0,0,68,69,5,6,0,0,69,70,5,17,
  	0,0,70,71,3,22,11,0,71,9,1,0,0,0,72,73,5,5,0,0,73,74,5,14,0,0,74,75,3,
  	22,11,0,75,11,1,0,0,0,76,77,5,6,0,0,77,78,5,17,0,0,78,80,3,44,22,0,79,
  	81,5,22,0,0,80,79,1,0,0,0,80,81,1,0,0,0,81,82,1,0,0,0,82,84,3,14,7,0,
  	83,85,5,23,0,0,84,83,1,0,0,0,84,85,1,0,0,0,85,86,1,0,0,0,86,87,3,22,11,
  	0,87,13,1,0,0,0,88,89,7,0,0,0,89,15,1,0,0,0,90,93,3,18,9,0,91,93,3,32,
  	16,0,92,90,1,0,0,0,92,91,1,0,0,0,93,94,1,0,0,0,94,95,5,1,0,0,95,17,1,
  	0,0,0,96,98,5,14,0,0,97,99,3,20,10,0,98,97,1,0,0,0,98,99,1,0,0,0,99,100,
  	1,0,0,0,100,102,5,22,0,0,101,103,3,26,13,0,102,101,1,0,0,0,102,103,1,
  	0,0,0,103,104,1,0,0,0,104,105,5,23,0,0,105,19,1,0,0,0,106,107,5,32,0,
  	0,107,108,3,42,21,0,108,109,5,33,0,0,109,21,1,0,0,0,110,117,5,30,0,0,
  	111,113,3,16,8,0,112,111,1,0,0,0,113,114,1,0,0,0,114,112,1,0,0,0,114,
  	115,1,0,0,0,115,118,1,0,0,0,116,118,3,24,12,0,117,112,1,0,0,0,117,116,
  	1,0,0,0,118,119,1,0,0,0,119,120,5,31,0,0,120,23,1,0,0,0,121,122,5,10,
  	0,0,122,123,5,12,0,0,123,124,5,1,0,0,124,25,1,0,0,0,125,130,3,0,0,0,126,
  	127,5,24,0,0,127,129,3,0,0,0,128,126,1,0,0,0,129,132,1,0,0,0,130,128,
  	1,0,0,0,130,131,1,0,0,0,131,134,1,0,0,0,132,130,1,0,0,0,133,135,5,24,
  	0,0,134,133,1,0,0,0,134,135,1,0,0,0,135,27,1,0,0,0,136,137,5,13,0,0,137,
  	138,5,32,0,0,138,139,5,2,0,0,139,140,5,24,0,0,140,141,3,30,15,0,141,142,
  	5,24,0,0,142,143,3,30,15,0,143,144,5,33,0,0,144,29,1,0,0,0,145,146,7,
  	1,0,0,146,31,1,0,0,0,147,148,7,2,0,0,148,149,5,14,0,0,149,33,1,0,0,0,
  	150,153,3,40,20,0,151,153,3,36,18,0,152,150,1,0,0,0,152,151,1,0,0,0,153,
  	35,1,0,0,0,154,155,5,30,0,0,155,160,3,38,19,0,156,157,5,24,0,0,157,159,
  	3,38,19,0,158,156,1,0,0,0,159,162,1,0,0,0,160,158,1,0,0,0,160,161,1,0,
  	0,0,161,164,1,0,0,0,162,160,1,0,0,0,163,165,5,24,0,0,164,163,1,0,0,0,
  	164,165,1,0,0,0,165,166,1,0,0,0,166,167,5,31,0,0,167,37,1,0,0,0,168,169,
  	5,14,0,0,169,170,5,26,0,0,170,171,3,40,20,0,171,39,1,0,0,0,172,173,7,
  	3,0,0,173,41,1,0,0,0,174,175,5,14,0,0,175,176,3,14,7,0,176,43,1,0,0,0,
  	177,178,5,11,0,0,178,181,5,14,0,0,179,181,5,4,0,0,180,177,1,0,0,0,180,
  	179,1,0,0,0,181,45,1,0,0,0,16,50,58,66,80,84,92,98,102,114,117,130,134,
  	152,160,164,180
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

SsbScriptParser::Integer_likeContext* SsbScriptParser::Pos_argumentContext::integer_like() {
  return getRuleContext<SsbScriptParser::Integer_likeContext>(0);
}

SsbScriptParser::StringContext* SsbScriptParser::Pos_argumentContext::string() {
  return getRuleContext<SsbScriptParser::StringContext>(0);
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

void SsbScriptParser::Pos_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPos_argument(this);
}

void SsbScriptParser::Pos_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPos_argument(this);
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
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::IDENTIFIER:
      case SsbScriptParser::VARIABLE:
      case SsbScriptParser::INTEGER:
      case SsbScriptParser::DECIMAL: {
        enterOuterAlt(_localctx, 1);
        setState(46);
        integer_like();
        break;
      }

      case SsbScriptParser::STRING_LITERAL:
      case SsbScriptParser::MULTILINE_STRING_LITERAL:
      case SsbScriptParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(47);
        string();
        break;
      }

      case SsbScriptParser::POSITION: {
        enterOuterAlt(_localctx, 3);
        setState(48);
        position_marker();
        break;
      }

      case SsbScriptParser::AT: {
        enterOuterAlt(_localctx, 4);
        setState(49);
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

void SsbScriptParser::Jump_markerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJump_marker(this);
}

void SsbScriptParser::Jump_markerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJump_marker(this);
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
    setState(52);
    match(SsbScriptParser::AT);
    setState(53);
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

void SsbScriptParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void SsbScriptParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
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
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SsbScriptParser::CORO

    || _la == SsbScriptParser::DEF) {
      setState(55);
      funcdef();
      setState(60);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(61);
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

void SsbScriptParser::FuncdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncdef(this);
}

void SsbScriptParser::FuncdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncdef(this);
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
    setState(66);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(63);
      coro_def();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(64);
      simple_def();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(65);
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

void SsbScriptParser::Simple_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_def(this);
}

void SsbScriptParser::Simple_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_def(this);
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
    setState(68);
    match(SsbScriptParser::DEF);
    setState(69);
    match(SsbScriptParser::INTEGER);
    setState(70);
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

void SsbScriptParser::Coro_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCoro_def(this);
}

void SsbScriptParser::Coro_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCoro_def(this);
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
    setState(72);
    match(SsbScriptParser::CORO);
    setState(73);
    match(SsbScriptParser::IDENTIFIER);
    setState(74);
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

SsbScriptParser::Integer_likeContext* SsbScriptParser::For_target_defContext::integer_like() {
  return getRuleContext<SsbScriptParser::Integer_likeContext>(0);
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

void SsbScriptParser::For_target_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_target_def(this);
}

void SsbScriptParser::For_target_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_target_def(this);
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
    setState(76);
    match(SsbScriptParser::DEF);
    setState(77);
    match(SsbScriptParser::INTEGER);
    setState(78);
    for_target_def_target();
    setState(80);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::OPEN_PAREN) {
      setState(79);
      match(SsbScriptParser::OPEN_PAREN);
    }
    setState(82);
    integer_like();
    setState(84);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::CLOSE_PAREN) {
      setState(83);
      match(SsbScriptParser::CLOSE_PAREN);
    }
    setState(86);
    func_suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Integer_likeContext ------------------------------------------------------------------

SsbScriptParser::Integer_likeContext::Integer_likeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SsbScriptParser::Integer_likeContext::DECIMAL() {
  return getToken(SsbScriptParser::DECIMAL, 0);
}

tree::TerminalNode* SsbScriptParser::Integer_likeContext::INTEGER() {
  return getToken(SsbScriptParser::INTEGER, 0);
}

tree::TerminalNode* SsbScriptParser::Integer_likeContext::IDENTIFIER() {
  return getToken(SsbScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* SsbScriptParser::Integer_likeContext::VARIABLE() {
  return getToken(SsbScriptParser::VARIABLE, 0);
}


size_t SsbScriptParser::Integer_likeContext::getRuleIndex() const {
  return SsbScriptParser::RuleInteger_like;
}

void SsbScriptParser::Integer_likeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger_like(this);
}

void SsbScriptParser::Integer_likeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger_like(this);
}

SsbScriptParser::Integer_likeContext* SsbScriptParser::integer_like() {
  Integer_likeContext *_localctx = _tracker.createInstance<Integer_likeContext>(_ctx, getState());
  enterRule(_localctx, 14, SsbScriptParser::RuleInteger_like);
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
    setState(88);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 17180049408) != 0))) {
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

void SsbScriptParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void SsbScriptParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
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
    setState(92);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::IDENTIFIER: {
        setState(90);
        operation();
        break;
      }

      case SsbScriptParser::AT:
      case SsbScriptParser::PARAGRAPH: {
        setState(91);
        label();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(94);
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

void SsbScriptParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void SsbScriptParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
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
    setState(96);
    match(SsbScriptParser::IDENTIFIER);
    setState(98);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::OPEN_SHARP) {
      setState(97);
      inline_ctx();
    }
    setState(100);
    match(SsbScriptParser::OPEN_PAREN);
    setState(102);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 18522234892) != 0)) {
      setState(101);
      arglist();
    }
    setState(104);
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

void SsbScriptParser::Inline_ctxContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInline_ctx(this);
}

void SsbScriptParser::Inline_ctxContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInline_ctx(this);
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
    setState(106);
    match(SsbScriptParser::OPEN_SHARP);
    setState(107);
    ctx_header();
    setState(108);
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

void SsbScriptParser::Func_suiteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_suite(this);
}

void SsbScriptParser::Func_suiteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_suite(this);
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
    setState(110);
    match(SsbScriptParser::OPEN_BRACE);
    setState(117);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::IDENTIFIER:
      case SsbScriptParser::AT:
      case SsbScriptParser::PARAGRAPH: {
        setState(112); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(111);
          stmt();
          setState(114); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 805322752) != 0));
        break;
      }

      case SsbScriptParser::ALIAS: {
        setState(116);
        func_alias();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(119);
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

void SsbScriptParser::Func_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_alias(this);
}

void SsbScriptParser::Func_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_alias(this);
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
    setState(121);
    match(SsbScriptParser::ALIAS);
    setState(122);
    match(SsbScriptParser::PREVIOUS);
    setState(123);
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

void SsbScriptParser::ArglistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArglist(this);
}

void SsbScriptParser::ArglistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArglist(this);
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
    setState(125);
    pos_argument();
    setState(130);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(126);
        match(SsbScriptParser::COMMA);
        setState(127);
        pos_argument(); 
      }
      setState(132);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::COMMA) {
      setState(133);
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

void SsbScriptParser::Position_markerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPosition_marker(this);
}

void SsbScriptParser::Position_markerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPosition_marker(this);
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
    setState(136);
    match(SsbScriptParser::POSITION);
    setState(137);
    match(SsbScriptParser::OPEN_SHARP);
    setState(138);
    match(SsbScriptParser::STRING_LITERAL);
    setState(139);
    match(SsbScriptParser::COMMA);
    setState(140);
    position_marker_arg();
    setState(141);
    match(SsbScriptParser::COMMA);
    setState(142);
    position_marker_arg();
    setState(143);
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

void SsbScriptParser::Position_marker_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPosition_marker_arg(this);
}

void SsbScriptParser::Position_marker_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPosition_marker_arg(this);
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
    setState(145);
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

void SsbScriptParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void SsbScriptParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
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
    setState(147);
    _la = _input->LA(1);
    if (!(_la == SsbScriptParser::AT

    || _la == SsbScriptParser::PARAGRAPH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(148);
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

void SsbScriptParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void SsbScriptParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
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
    setState(152);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::STRING_LITERAL:
      case SsbScriptParser::MULTILINE_STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(150);
        string_value();
        break;
      }

      case SsbScriptParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(151);
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

void SsbScriptParser::Lang_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLang_string(this);
}

void SsbScriptParser::Lang_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLang_string(this);
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
    setState(154);
    match(SsbScriptParser::OPEN_BRACE);
    setState(155);
    lang_string_argument();
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(156);
        match(SsbScriptParser::COMMA);
        setState(157);
        lang_string_argument(); 
      }
      setState(162);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SsbScriptParser::COMMA) {
      setState(163);
      match(SsbScriptParser::COMMA);
    }
    setState(166);
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

void SsbScriptParser::Lang_string_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLang_string_argument(this);
}

void SsbScriptParser::Lang_string_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLang_string_argument(this);
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
    setState(168);
    match(SsbScriptParser::IDENTIFIER);
    setState(169);
    match(SsbScriptParser::ASSIGN);
    setState(170);
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

void SsbScriptParser::String_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString_value(this);
}

void SsbScriptParser::String_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString_value(this);
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
    setState(172);
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

SsbScriptParser::Integer_likeContext* SsbScriptParser::Ctx_headerContext::integer_like() {
  return getRuleContext<SsbScriptParser::Integer_likeContext>(0);
}


size_t SsbScriptParser::Ctx_headerContext::getRuleIndex() const {
  return SsbScriptParser::RuleCtx_header;
}

void SsbScriptParser::Ctx_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCtx_header(this);
}

void SsbScriptParser::Ctx_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCtx_header(this);
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
    setState(174);
    match(SsbScriptParser::IDENTIFIER);
    setState(175);
    integer_like();
   
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

void SsbScriptParser::For_target_def_targetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_target_def_target(this);
}

void SsbScriptParser::For_target_def_targetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SsbScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_target_def_target(this);
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
    setState(180);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SsbScriptParser::FOR: {
        enterOuterAlt(_localctx, 1);
        setState(177);
        match(SsbScriptParser::FOR);
        setState(178);
        match(SsbScriptParser::IDENTIFIER);
        break;
      }

      case SsbScriptParser::FOR_TARGET: {
        enterOuterAlt(_localctx, 2);
        setState(179);
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
