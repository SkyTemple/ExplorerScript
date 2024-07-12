
// Generated from ExplorerScript.g4 by ANTLR 4.13.0


#include "ExplorerScriptListener.h"
#include "ExplorerScriptVisitor.h"

#include "ExplorerScriptParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ExplorerScriptParserStaticData final {
  ExplorerScriptParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ExplorerScriptParserStaticData(const ExplorerScriptParserStaticData&) = delete;
  ExplorerScriptParserStaticData(ExplorerScriptParserStaticData&&) = delete;
  ExplorerScriptParserStaticData& operator=(const ExplorerScriptParserStaticData&) = delete;
  ExplorerScriptParserStaticData& operator=(ExplorerScriptParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag explorerscriptParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ExplorerScriptParserStaticData *explorerscriptParserStaticData = nullptr;

void explorerscriptParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (explorerscriptParserStaticData != nullptr) {
    return;
  }
#else
  assert(explorerscriptParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ExplorerScriptParserStaticData>(
    std::vector<std::string>{
      "start", "import_stmt", "macrodef", "stmt", "simple_stmt", "cntrl_stmt", 
      "jump", "call", "macro_call", "ctx_block", "if_block", "elseif_block", 
      "else_block", "if_header", "if_h_negatable", "if_h_op", "if_h_bit", 
      "if_h_scn", "switch_block", "message_switch_block", "single_case_block", 
      "default", "switch_header", "switch_h_scn", "switch_h_random", "switch_h_dungeon_mode", 
      "switch_h_sector", "case_header", "case_h_menu", "case_h_menu2", "case_h_op", 
      "forever_block", "for_block", "while_block", "assignment", "assignment_regular", 
      "assignment_clear", "assignment_initial", "assignment_reset", "assignment_adv_log", 
      "assignment_dungeon_mode", "assignment_scn", "value_of", "scn_var", 
      "conditional_operator", "assign_operator", "funcdef", "simple_def", 
      "coro_def", "for_target_def", "integer_like", "operation", "inline_ctx", 
      "func_suite", "func_alias", "arglist", "pos_argument", "position_marker", 
      "position_marker_arg", "label", "string", "lang_string", "lang_string_argument", 
      "string_value", "ctx_header", "for_target_def_target"
    },
    std::vector<std::string>{
      "", "';'", "'FALSE'", "'TRUE'", "'='", "'<'", "'>'", "'=='", "'<='", 
      "'>='", "'!='", "'&'", "'^'", "'&<<'", "'-='", "'+='", "'*='", "'/='", 
      "'||'", "'not'", "'jump'", "'call'", "'import'", "'macro'", "'if'", 
      "'elseif'", "'else'", "'forever'", "'with'", "'switch'", "'return'", 
      "'end'", "'hold'", "'continue'", "'break'", "'break_loop'", "'value'", 
      "'debug'", "'edit'", "'variation'", "'random'", "'sector'", "'dungeon_mode'", 
      "'menu2'", "'menu'", "'case'", "'default'", "'clear'", "'reset'", 
      "'init'", "'scn'", "'dungeon_result'", "'adventure_log'", "'message_SwitchTalk'", 
      "'message_SwitchMonologue'", "'while'", "'['", "']'", "", "", "", 
      "'coro'", "'def'", "'for_actor'", "'for_object'", "'for_performer'", 
      "'alias'", "'for'", "'previous'", "'Position'", "", "", "", "", "", 
      "", "", "", "'('", "')'", "','", "':'", "'+'", "'@'", "'\\u00A7'", 
      "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "", "OP_FALSE", "OP_TRUE", "ASSIGN", "OPEN_SHARP", "CLOSE_SHARP", 
      "OP_EQ", "OP_LE", "OP_GE", "OP_NEQ", "OP_AND", "OP_XOR", "OP_BICH", 
      "OP_MINUS", "OP_PLUS", "OP_MULTIPLY", "OP_DIVIDE", "OR", "NOT", "JUMP", 
      "CALL", "IMPORT", "MACRO", "IF", "ELSEIF", "ELSE", "FOREVER", "WITH", 
      "SWITCH", "RETURN", "END", "HOLD", "CONTINUE", "BREAK", "BREAK_LOOP", 
      "VALUE", "DEBUG", "EDIT", "VARIATION", "RANDOM", "SECTOR", "DUNGEON_MODE", 
      "MENU2", "MENU", "CASE", "DEFAULT", "CLEAR", "RESET", "INIT", "SCN", 
      "DUNGEON_RESULT", "ADVENTURE_LOG", "MESSAGE_SWITCH_TALK", "MESSAGE_SWITCH_MONOLOGUE", 
      "WHILE", "OPEN_BRACKET", "CLOSE_BRACKET", "STRING_LITERAL", "MULTILINE_STRING_LITERAL", 
      "FOR_TARGET", "CORO", "DEF", "FOR_ACTOR", "FOR_OBJECT", "FOR_PERFORMER", 
      "ALIAS", "FOR", "PREVIOUS", "POSITION", "IDENTIFIER", "VARIABLE", 
      "MACRO_CALL", "INTEGER", "DECIMAL_INTEGER", "OCT_INTEGER", "HEX_INTEGER", 
      "BIN_INTEGER", "OPEN_PAREN", "CLOSE_PAREN", "COMMA", "COLON", "PLUS", 
      "AT", "PARAGRAPH", "OPEN_BRACE", "CLOSE_BRACE", "DECIMAL", "SKIP_", 
      "UNKNOWN_CHAR"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,89,637,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,7,
  	63,2,64,7,64,2,65,7,65,1,0,5,0,134,8,0,10,0,12,0,137,9,0,1,0,1,0,5,0,
  	141,8,0,10,0,12,0,144,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,
  	156,8,2,1,2,1,2,5,2,160,8,2,10,2,12,2,163,9,2,1,2,1,2,1,2,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,3,3,177,8,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,185,8,
  	4,1,4,1,4,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,3,8,202,
  	8,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,3,10,217,8,
  	10,1,10,1,10,1,10,1,10,5,10,223,8,10,10,10,12,10,226,9,10,1,10,1,10,1,
  	10,5,10,231,8,10,10,10,12,10,234,9,10,1,10,1,10,5,10,238,8,10,10,10,12,
  	10,241,9,10,1,10,3,10,244,8,10,1,11,1,11,3,11,248,8,11,1,11,1,11,1,11,
  	1,11,5,11,254,8,11,10,11,12,11,257,9,11,1,11,1,11,1,11,5,11,262,8,11,
  	10,11,12,11,265,9,11,1,11,1,11,1,12,1,12,1,12,5,12,272,8,12,10,12,12,
  	12,275,9,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,3,13,284,8,13,1,14,3,14,
  	287,8,14,1,14,1,14,1,15,1,15,1,15,1,15,3,15,295,8,15,1,16,3,16,298,8,
  	16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	18,1,18,1,18,1,18,1,18,1,18,1,18,5,18,320,8,18,10,18,12,18,323,9,18,1,
  	18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,334,8,19,10,19,12,19,
  	337,9,19,1,19,1,19,1,20,1,20,1,20,1,20,5,20,345,8,20,10,20,12,20,348,
  	9,20,1,20,3,20,351,8,20,1,21,1,21,1,21,5,21,356,8,21,10,21,12,21,359,
  	9,21,1,21,3,21,362,8,21,1,22,1,22,1,22,1,22,1,22,1,22,3,22,370,8,22,1,
  	23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,
  	25,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,3,27,395,8,27,1,28,1,28,1,
  	28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,30,1,30,1,30,3,30,410,8,30,1,
  	31,1,31,1,31,5,31,415,8,31,10,31,12,31,418,9,31,1,31,1,31,1,32,1,32,1,
  	32,1,32,1,32,1,32,1,32,1,32,1,32,5,32,431,8,32,10,32,12,32,434,9,32,1,
  	32,1,32,1,33,1,33,3,33,440,8,33,1,33,1,33,1,33,1,33,1,33,5,33,447,8,33,
  	10,33,12,33,450,9,33,1,33,1,33,1,34,1,34,1,34,1,34,1,34,1,34,1,34,3,34,
  	461,8,34,1,35,1,35,1,35,1,35,3,35,467,8,35,1,35,1,35,1,35,3,35,472,8,
  	35,1,36,1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,3,38,483,8,38,1,39,1,
  	39,1,39,1,39,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,
  	41,1,41,1,41,1,41,1,41,1,42,1,42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,
  	43,1,44,1,44,1,45,1,45,1,46,1,46,1,46,3,46,522,8,46,1,47,1,47,1,47,1,
  	47,1,48,1,48,1,48,1,48,1,49,1,49,1,49,1,49,3,49,536,8,49,1,49,1,49,3,
  	49,540,8,49,1,49,1,49,1,50,1,50,1,51,1,51,3,51,548,8,51,1,51,1,51,3,51,
  	552,8,51,1,51,1,51,1,52,1,52,1,52,1,52,1,53,1,53,4,53,562,8,53,11,53,
  	12,53,563,1,53,3,53,567,8,53,1,53,1,53,1,54,1,54,1,54,1,54,1,55,1,55,
  	1,55,5,55,578,8,55,10,55,12,55,581,9,55,1,55,3,55,584,8,55,1,56,1,56,
  	1,56,3,56,589,8,56,1,57,1,57,1,57,1,57,1,57,1,57,1,57,1,57,1,57,1,58,
  	1,58,1,59,1,59,1,59,1,60,1,60,3,60,607,8,60,1,61,1,61,1,61,1,61,5,61,
  	613,8,61,10,61,12,61,616,9,61,1,61,3,61,619,8,61,1,61,1,61,1,62,1,62,
  	1,62,1,62,1,63,1,63,1,64,1,64,1,64,1,65,1,65,1,65,3,65,635,8,65,1,65,
  	0,0,66,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,
  	92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,
  	130,0,9,1,0,30,35,1,0,37,39,1,0,53,54,2,0,2,3,5,13,2,0,4,4,14,17,3,0,
  	70,71,73,73,87,87,2,0,73,73,87,87,1,0,83,84,1,0,58,59,651,0,135,1,0,0,
  	0,2,147,1,0,0,0,4,151,1,0,0,0,6,176,1,0,0,0,8,184,1,0,0,0,10,188,1,0,
  	0,0,12,190,1,0,0,0,14,194,1,0,0,0,16,198,1,0,0,0,18,206,1,0,0,0,20,214,
  	1,0,0,0,22,245,1,0,0,0,24,268,1,0,0,0,26,283,1,0,0,0,28,286,1,0,0,0,30,
  	290,1,0,0,0,32,297,1,0,0,0,34,304,1,0,0,0,36,312,1,0,0,0,38,326,1,0,0,
  	0,40,340,1,0,0,0,42,352,1,0,0,0,44,369,1,0,0,0,46,371,1,0,0,0,48,376,
  	1,0,0,0,50,381,1,0,0,0,52,386,1,0,0,0,54,394,1,0,0,0,56,396,1,0,0,0,58,
  	401,1,0,0,0,60,406,1,0,0,0,62,411,1,0,0,0,64,421,1,0,0,0,66,437,1,0,0,
  	0,68,460,1,0,0,0,70,462,1,0,0,0,72,473,1,0,0,0,74,476,1,0,0,0,76,479,
  	1,0,0,0,78,484,1,0,0,0,80,488,1,0,0,0,82,495,1,0,0,0,84,504,1,0,0,0,86,
  	509,1,0,0,0,88,514,1,0,0,0,90,516,1,0,0,0,92,521,1,0,0,0,94,523,1,0,0,
  	0,96,527,1,0,0,0,98,531,1,0,0,0,100,543,1,0,0,0,102,545,1,0,0,0,104,555,
  	1,0,0,0,106,559,1,0,0,0,108,570,1,0,0,0,110,574,1,0,0,0,112,588,1,0,0,
  	0,114,590,1,0,0,0,116,599,1,0,0,0,118,601,1,0,0,0,120,606,1,0,0,0,122,
  	608,1,0,0,0,124,622,1,0,0,0,126,626,1,0,0,0,128,628,1,0,0,0,130,634,1,
  	0,0,0,132,134,3,2,1,0,133,132,1,0,0,0,134,137,1,0,0,0,135,133,1,0,0,0,
  	135,136,1,0,0,0,136,142,1,0,0,0,137,135,1,0,0,0,138,141,3,4,2,0,139,141,
  	3,92,46,0,140,138,1,0,0,0,140,139,1,0,0,0,141,144,1,0,0,0,142,140,1,0,
  	0,0,142,143,1,0,0,0,143,145,1,0,0,0,144,142,1,0,0,0,145,146,5,0,0,1,146,
  	1,1,0,0,0,147,148,5,22,0,0,148,149,5,58,0,0,149,150,5,1,0,0,150,3,1,0,
  	0,0,151,152,5,23,0,0,152,153,5,70,0,0,153,155,5,78,0,0,154,156,5,71,0,
  	0,155,154,1,0,0,0,155,156,1,0,0,0,156,161,1,0,0,0,157,158,5,80,0,0,158,
  	160,5,71,0,0,159,157,1,0,0,0,160,163,1,0,0,0,161,159,1,0,0,0,161,162,
  	1,0,0,0,162,164,1,0,0,0,163,161,1,0,0,0,164,165,5,79,0,0,165,166,3,106,
  	53,0,166,5,1,0,0,0,167,177,3,8,4,0,168,177,3,18,9,0,169,177,3,20,10,0,
  	170,177,3,36,18,0,171,177,3,38,19,0,172,177,3,62,31,0,173,177,3,64,32,
  	0,174,177,3,66,33,0,175,177,3,16,8,0,176,167,1,0,0,0,176,168,1,0,0,0,
  	176,169,1,0,0,0,176,170,1,0,0,0,176,171,1,0,0,0,176,172,1,0,0,0,176,173,
  	1,0,0,0,176,174,1,0,0,0,176,175,1,0,0,0,177,7,1,0,0,0,178,185,3,102,51,
  	0,179,185,3,118,59,0,180,185,3,10,5,0,181,185,3,12,6,0,182,185,3,14,7,
  	0,183,185,3,68,34,0,184,178,1,0,0,0,184,179,1,0,0,0,184,180,1,0,0,0,184,
  	181,1,0,0,0,184,182,1,0,0,0,184,183,1,0,0,0,185,186,1,0,0,0,186,187,5,
  	1,0,0,187,9,1,0,0,0,188,189,7,0,0,0,189,11,1,0,0,0,190,191,5,20,0,0,191,
  	192,5,83,0,0,192,193,5,70,0,0,193,13,1,0,0,0,194,195,5,21,0,0,195,196,
  	5,83,0,0,196,197,5,70,0,0,197,15,1,0,0,0,198,199,5,72,0,0,199,201,5,78,
  	0,0,200,202,3,110,55,0,201,200,1,0,0,0,201,202,1,0,0,0,202,203,1,0,0,
  	0,203,204,5,79,0,0,204,205,5,1,0,0,205,17,1,0,0,0,206,207,5,28,0,0,207,
  	208,5,78,0,0,208,209,3,128,64,0,209,210,5,79,0,0,210,211,5,85,0,0,211,
  	212,3,8,4,0,212,213,5,86,0,0,213,19,1,0,0,0,214,216,5,24,0,0,215,217,
  	5,19,0,0,216,215,1,0,0,0,216,217,1,0,0,0,217,218,1,0,0,0,218,219,5,78,
  	0,0,219,224,3,26,13,0,220,221,5,18,0,0,221,223,3,26,13,0,222,220,1,0,
  	0,0,223,226,1,0,0,0,224,222,1,0,0,0,224,225,1,0,0,0,225,227,1,0,0,0,226,
  	224,1,0,0,0,227,228,5,79,0,0,228,232,5,85,0,0,229,231,3,6,3,0,230,229,
  	1,0,0,0,231,234,1,0,0,0,232,230,1,0,0,0,232,233,1,0,0,0,233,235,1,0,0,
  	0,234,232,1,0,0,0,235,239,5,86,0,0,236,238,3,22,11,0,237,236,1,0,0,0,
  	238,241,1,0,0,0,239,237,1,0,0,0,239,240,1,0,0,0,240,243,1,0,0,0,241,239,
  	1,0,0,0,242,244,3,24,12,0,243,242,1,0,0,0,243,244,1,0,0,0,244,21,1,0,
  	0,0,245,247,5,25,0,0,246,248,5,19,0,0,247,246,1,0,0,0,247,248,1,0,0,0,
  	248,249,1,0,0,0,249,250,5,78,0,0,250,255,3,26,13,0,251,252,5,18,0,0,252,
  	254,3,26,13,0,253,251,1,0,0,0,254,257,1,0,0,0,255,253,1,0,0,0,255,256,
  	1,0,0,0,256,258,1,0,0,0,257,255,1,0,0,0,258,259,5,79,0,0,259,263,5,85,
  	0,0,260,262,3,6,3,0,261,260,1,0,0,0,262,265,1,0,0,0,263,261,1,0,0,0,263,
  	264,1,0,0,0,264,266,1,0,0,0,265,263,1,0,0,0,266,267,5,86,0,0,267,23,1,
  	0,0,0,268,269,5,26,0,0,269,273,5,85,0,0,270,272,3,6,3,0,271,270,1,0,0,
  	0,272,275,1,0,0,0,273,271,1,0,0,0,273,274,1,0,0,0,274,276,1,0,0,0,275,
  	273,1,0,0,0,276,277,5,86,0,0,277,25,1,0,0,0,278,284,3,30,15,0,279,284,
  	3,32,16,0,280,284,3,28,14,0,281,284,3,34,17,0,282,284,3,102,51,0,283,
  	278,1,0,0,0,283,279,1,0,0,0,283,280,1,0,0,0,283,281,1,0,0,0,283,282,1,
  	0,0,0,284,27,1,0,0,0,285,287,5,19,0,0,286,285,1,0,0,0,286,287,1,0,0,0,
  	287,288,1,0,0,0,288,289,7,1,0,0,289,29,1,0,0,0,290,291,3,100,50,0,291,
  	294,3,88,44,0,292,295,3,84,42,0,293,295,3,100,50,0,294,292,1,0,0,0,294,
  	293,1,0,0,0,295,31,1,0,0,0,296,298,5,19,0,0,297,296,1,0,0,0,297,298,1,
  	0,0,0,298,299,1,0,0,0,299,300,3,100,50,0,300,301,5,56,0,0,301,302,5,73,
  	0,0,302,303,5,57,0,0,303,33,1,0,0,0,304,305,3,86,43,0,305,306,3,88,44,
  	0,306,307,5,56,0,0,307,308,5,73,0,0,308,309,5,80,0,0,309,310,5,73,0,0,
  	310,311,5,57,0,0,311,35,1,0,0,0,312,313,5,29,0,0,313,314,5,78,0,0,314,
  	315,3,44,22,0,315,316,5,79,0,0,316,321,5,85,0,0,317,320,3,42,21,0,318,
  	320,3,40,20,0,319,317,1,0,0,0,319,318,1,0,0,0,320,323,1,0,0,0,321,319,
  	1,0,0,0,321,322,1,0,0,0,322,324,1,0,0,0,323,321,1,0,0,0,324,325,5,86,
  	0,0,325,37,1,0,0,0,326,327,7,2,0,0,327,328,5,78,0,0,328,329,3,100,50,
  	0,329,330,5,79,0,0,330,335,5,85,0,0,331,334,3,42,21,0,332,334,3,40,20,
  	0,333,331,1,0,0,0,333,332,1,0,0,0,334,337,1,0,0,0,335,333,1,0,0,0,335,
  	336,1,0,0,0,336,338,1,0,0,0,337,335,1,0,0,0,338,339,5,86,0,0,339,39,1,
  	0,0,0,340,341,5,45,0,0,341,342,3,54,27,0,342,350,5,81,0,0,343,345,3,6,
  	3,0,344,343,1,0,0,0,345,348,1,0,0,0,346,344,1,0,0,0,346,347,1,0,0,0,347,
  	351,1,0,0,0,348,346,1,0,0,0,349,351,3,120,60,0,350,346,1,0,0,0,350,349,
  	1,0,0,0,351,41,1,0,0,0,352,353,5,46,0,0,353,361,5,81,0,0,354,356,3,6,
  	3,0,355,354,1,0,0,0,356,359,1,0,0,0,357,355,1,0,0,0,357,358,1,0,0,0,358,
  	362,1,0,0,0,359,357,1,0,0,0,360,362,3,120,60,0,361,357,1,0,0,0,361,360,
  	1,0,0,0,362,43,1,0,0,0,363,370,3,100,50,0,364,370,3,102,51,0,365,370,
  	3,46,23,0,366,370,3,48,24,0,367,370,3,50,25,0,368,370,3,52,26,0,369,363,
  	1,0,0,0,369,364,1,0,0,0,369,365,1,0,0,0,369,366,1,0,0,0,369,367,1,0,0,
  	0,369,368,1,0,0,0,370,45,1,0,0,0,371,372,3,86,43,0,372,373,5,56,0,0,373,
  	374,5,73,0,0,374,375,5,57,0,0,375,47,1,0,0,0,376,377,5,40,0,0,377,378,
  	5,78,0,0,378,379,3,100,50,0,379,380,5,79,0,0,380,49,1,0,0,0,381,382,5,
  	42,0,0,382,383,5,78,0,0,383,384,3,100,50,0,384,385,5,79,0,0,385,51,1,
  	0,0,0,386,387,5,41,0,0,387,388,5,78,0,0,388,389,5,79,0,0,389,53,1,0,0,
  	0,390,395,3,100,50,0,391,395,3,56,28,0,392,395,3,58,29,0,393,395,3,60,
  	30,0,394,390,1,0,0,0,394,391,1,0,0,0,394,392,1,0,0,0,394,393,1,0,0,0,
  	395,55,1,0,0,0,396,397,5,44,0,0,397,398,5,78,0,0,398,399,3,120,60,0,399,
  	400,5,79,0,0,400,57,1,0,0,0,401,402,5,43,0,0,402,403,5,78,0,0,403,404,
  	3,100,50,0,404,405,5,79,0,0,405,59,1,0,0,0,406,409,3,88,44,0,407,410,
  	3,84,42,0,408,410,3,100,50,0,409,407,1,0,0,0,409,408,1,0,0,0,410,61,1,
  	0,0,0,411,412,5,27,0,0,412,416,5,85,0,0,413,415,3,6,3,0,414,413,1,0,0,
  	0,415,418,1,0,0,0,416,414,1,0,0,0,416,417,1,0,0,0,417,419,1,0,0,0,418,
  	416,1,0,0,0,419,420,5,86,0,0,420,63,1,0,0,0,421,422,5,67,0,0,422,423,
  	5,78,0,0,423,424,3,8,4,0,424,425,3,26,13,0,425,426,5,1,0,0,426,427,3,
  	8,4,0,427,428,5,79,0,0,428,432,5,85,0,0,429,431,3,6,3,0,430,429,1,0,0,
  	0,431,434,1,0,0,0,432,430,1,0,0,0,432,433,1,0,0,0,433,435,1,0,0,0,434,
  	432,1,0,0,0,435,436,5,86,0,0,436,65,1,0,0,0,437,439,5,55,0,0,438,440,
  	5,19,0,0,439,438,1,0,0,0,439,440,1,0,0,0,440,441,1,0,0,0,441,442,5,78,
  	0,0,442,443,3,26,13,0,443,444,5,79,0,0,444,448,5,85,0,0,445,447,3,6,3,
  	0,446,445,1,0,0,0,447,450,1,0,0,0,448,446,1,0,0,0,448,449,1,0,0,0,449,
  	451,1,0,0,0,450,448,1,0,0,0,451,452,5,86,0,0,452,67,1,0,0,0,453,461,3,
  	70,35,0,454,461,3,72,36,0,455,461,3,74,37,0,456,461,3,76,38,0,457,461,
  	3,78,39,0,458,461,3,80,40,0,459,461,3,82,41,0,460,453,1,0,0,0,460,454,
  	1,0,0,0,460,455,1,0,0,0,460,456,1,0,0,0,460,457,1,0,0,0,460,458,1,0,0,
  	0,460,459,1,0,0,0,461,69,1,0,0,0,462,466,3,100,50,0,463,464,5,56,0,0,
  	464,465,5,73,0,0,465,467,5,57,0,0,466,463,1,0,0,0,466,467,1,0,0,0,467,
  	468,1,0,0,0,468,471,3,90,45,0,469,472,3,100,50,0,470,472,3,84,42,0,471,
  	469,1,0,0,0,471,470,1,0,0,0,472,71,1,0,0,0,473,474,5,47,0,0,474,475,3,
  	100,50,0,475,73,1,0,0,0,476,477,5,49,0,0,477,478,3,100,50,0,478,75,1,
  	0,0,0,479,482,5,48,0,0,480,483,5,51,0,0,481,483,3,86,43,0,482,480,1,0,
  	0,0,482,481,1,0,0,0,483,77,1,0,0,0,484,485,5,52,0,0,485,486,5,4,0,0,486,
  	487,3,100,50,0,487,79,1,0,0,0,488,489,5,42,0,0,489,490,5,78,0,0,490,491,
  	3,100,50,0,491,492,5,79,0,0,492,493,5,4,0,0,493,494,3,100,50,0,494,81,
  	1,0,0,0,495,496,3,100,50,0,496,497,5,4,0,0,497,498,5,50,0,0,498,499,5,
  	56,0,0,499,500,5,73,0,0,500,501,5,80,0,0,501,502,5,73,0,0,502,503,5,57,
  	0,0,503,83,1,0,0,0,504,505,5,36,0,0,505,506,5,78,0,0,506,507,3,100,50,
  	0,507,508,5,79,0,0,508,85,1,0,0,0,509,510,5,50,0,0,510,511,5,78,0,0,511,
  	512,3,100,50,0,512,513,5,79,0,0,513,87,1,0,0,0,514,515,7,3,0,0,515,89,
  	1,0,0,0,516,517,7,4,0,0,517,91,1,0,0,0,518,522,3,96,48,0,519,522,3,94,
  	47,0,520,522,3,98,49,0,521,518,1,0,0,0,521,519,1,0,0,0,521,520,1,0,0,
  	0,522,93,1,0,0,0,523,524,5,62,0,0,524,525,5,73,0,0,525,526,3,106,53,0,
  	526,95,1,0,0,0,527,528,5,61,0,0,528,529,5,70,0,0,529,530,3,106,53,0,530,
  	97,1,0,0,0,531,532,5,62,0,0,532,533,5,73,0,0,533,535,3,130,65,0,534,536,
  	5,78,0,0,535,534,1,0,0,0,535,536,1,0,0,0,536,537,1,0,0,0,537,539,3,100,
  	50,0,538,540,5,79,0,0,539,538,1,0,0,0,539,540,1,0,0,0,540,541,1,0,0,0,
  	541,542,3,106,53,0,542,99,1,0,0,0,543,544,7,5,0,0,544,101,1,0,0,0,545,
  	547,5,70,0,0,546,548,3,104,52,0,547,546,1,0,0,0,547,548,1,0,0,0,548,549,
  	1,0,0,0,549,551,5,78,0,0,550,552,3,110,55,0,551,550,1,0,0,0,551,552,1,
  	0,0,0,552,553,1,0,0,0,553,554,5,79,0,0,554,103,1,0,0,0,555,556,5,5,0,
  	0,556,557,3,128,64,0,557,558,5,6,0,0,558,105,1,0,0,0,559,566,5,85,0,0,
  	560,562,3,6,3,0,561,560,1,0,0,0,562,563,1,0,0,0,563,561,1,0,0,0,563,564,
  	1,0,0,0,564,567,1,0,0,0,565,567,3,108,54,0,566,561,1,0,0,0,566,565,1,
  	0,0,0,567,568,1,0,0,0,568,569,5,86,0,0,569,107,1,0,0,0,570,571,5,66,0,
  	0,571,572,5,68,0,0,572,573,5,1,0,0,573,109,1,0,0,0,574,579,3,112,56,0,
  	575,576,5,80,0,0,576,578,3,112,56,0,577,575,1,0,0,0,578,581,1,0,0,0,579,
  	577,1,0,0,0,579,580,1,0,0,0,580,583,1,0,0,0,581,579,1,0,0,0,582,584,5,
  	80,0,0,583,582,1,0,0,0,583,584,1,0,0,0,584,111,1,0,0,0,585,589,3,100,
  	50,0,586,589,3,120,60,0,587,589,3,114,57,0,588,585,1,0,0,0,588,586,1,
  	0,0,0,588,587,1,0,0,0,589,113,1,0,0,0,590,591,5,69,0,0,591,592,5,5,0,
  	0,592,593,5,58,0,0,593,594,5,80,0,0,594,595,3,116,58,0,595,596,5,80,0,
  	0,596,597,3,116,58,0,597,598,5,6,0,0,598,115,1,0,0,0,599,600,7,6,0,0,
  	600,117,1,0,0,0,601,602,7,7,0,0,602,603,5,70,0,0,603,119,1,0,0,0,604,
  	607,3,126,63,0,605,607,3,122,61,0,606,604,1,0,0,0,606,605,1,0,0,0,607,
  	121,1,0,0,0,608,609,5,85,0,0,609,614,3,124,62,0,610,611,5,80,0,0,611,
  	613,3,124,62,0,612,610,1,0,0,0,613,616,1,0,0,0,614,612,1,0,0,0,614,615,
  	1,0,0,0,615,618,1,0,0,0,616,614,1,0,0,0,617,619,5,80,0,0,618,617,1,0,
  	0,0,618,619,1,0,0,0,619,620,1,0,0,0,620,621,5,86,0,0,621,123,1,0,0,0,
  	622,623,5,70,0,0,623,624,5,4,0,0,624,625,3,126,63,0,625,125,1,0,0,0,626,
  	627,7,8,0,0,627,127,1,0,0,0,628,629,5,70,0,0,629,630,3,100,50,0,630,129,
  	1,0,0,0,631,632,5,67,0,0,632,635,5,70,0,0,633,635,5,60,0,0,634,631,1,
  	0,0,0,634,633,1,0,0,0,635,131,1,0,0,0,54,135,140,142,155,161,176,184,
  	201,216,224,232,239,243,247,255,263,273,283,286,294,297,319,321,333,335,
  	346,350,357,361,369,394,409,416,432,439,448,460,466,471,482,521,535,539,
  	547,551,563,566,579,583,588,606,614,618,634
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  explorerscriptParserStaticData = staticData.release();
}

}

ExplorerScriptParser::ExplorerScriptParser(TokenStream *input) : ExplorerScriptParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ExplorerScriptParser::ExplorerScriptParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ExplorerScriptParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *explorerscriptParserStaticData->atn, explorerscriptParserStaticData->decisionToDFA, explorerscriptParserStaticData->sharedContextCache, options);
}

ExplorerScriptParser::~ExplorerScriptParser() {
  delete _interpreter;
}

const atn::ATN& ExplorerScriptParser::getATN() const {
  return *explorerscriptParserStaticData->atn;
}

std::string ExplorerScriptParser::getGrammarFileName() const {
  return "ExplorerScript.g4";
}

const std::vector<std::string>& ExplorerScriptParser::getRuleNames() const {
  return explorerscriptParserStaticData->ruleNames;
}

const dfa::Vocabulary& ExplorerScriptParser::getVocabulary() const {
  return explorerscriptParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ExplorerScriptParser::getSerializedATN() const {
  return explorerscriptParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

ExplorerScriptParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::StartContext::EOF() {
  return getToken(ExplorerScriptParser::EOF, 0);
}

std::vector<ExplorerScriptParser::Import_stmtContext *> ExplorerScriptParser::StartContext::import_stmt() {
  return getRuleContexts<ExplorerScriptParser::Import_stmtContext>();
}

ExplorerScriptParser::Import_stmtContext* ExplorerScriptParser::StartContext::import_stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::Import_stmtContext>(i);
}

std::vector<ExplorerScriptParser::MacrodefContext *> ExplorerScriptParser::StartContext::macrodef() {
  return getRuleContexts<ExplorerScriptParser::MacrodefContext>();
}

ExplorerScriptParser::MacrodefContext* ExplorerScriptParser::StartContext::macrodef(size_t i) {
  return getRuleContext<ExplorerScriptParser::MacrodefContext>(i);
}

std::vector<ExplorerScriptParser::FuncdefContext *> ExplorerScriptParser::StartContext::funcdef() {
  return getRuleContexts<ExplorerScriptParser::FuncdefContext>();
}

ExplorerScriptParser::FuncdefContext* ExplorerScriptParser::StartContext::funcdef(size_t i) {
  return getRuleContext<ExplorerScriptParser::FuncdefContext>(i);
}


size_t ExplorerScriptParser::StartContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleStart;
}

void ExplorerScriptParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void ExplorerScriptParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


std::any ExplorerScriptParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::StartContext* ExplorerScriptParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, ExplorerScriptParser::RuleStart);
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
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::IMPORT) {
      setState(132);
      import_stmt();
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 6917529027649470464) != 0)) {
      setState(140);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ExplorerScriptParser::MACRO: {
          setState(138);
          macrodef();
          break;
        }

        case ExplorerScriptParser::CORO:
        case ExplorerScriptParser::DEF: {
          setState(139);
          funcdef();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(144);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(145);
    match(ExplorerScriptParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_stmtContext ------------------------------------------------------------------

ExplorerScriptParser::Import_stmtContext::Import_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Import_stmtContext::IMPORT() {
  return getToken(ExplorerScriptParser::IMPORT, 0);
}

tree::TerminalNode* ExplorerScriptParser::Import_stmtContext::STRING_LITERAL() {
  return getToken(ExplorerScriptParser::STRING_LITERAL, 0);
}


size_t ExplorerScriptParser::Import_stmtContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleImport_stmt;
}

void ExplorerScriptParser::Import_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImport_stmt(this);
}

void ExplorerScriptParser::Import_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImport_stmt(this);
}


std::any ExplorerScriptParser::Import_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitImport_stmt(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Import_stmtContext* ExplorerScriptParser::import_stmt() {
  Import_stmtContext *_localctx = _tracker.createInstance<Import_stmtContext>(_ctx, getState());
  enterRule(_localctx, 2, ExplorerScriptParser::RuleImport_stmt);

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
    match(ExplorerScriptParser::IMPORT);
    setState(148);
    match(ExplorerScriptParser::STRING_LITERAL);
    setState(149);
    match(ExplorerScriptParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MacrodefContext ------------------------------------------------------------------

ExplorerScriptParser::MacrodefContext::MacrodefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::MacrodefContext::MACRO() {
  return getToken(ExplorerScriptParser::MACRO, 0);
}

tree::TerminalNode* ExplorerScriptParser::MacrodefContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExplorerScriptParser::MacrodefContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::MacrodefContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

ExplorerScriptParser::Func_suiteContext* ExplorerScriptParser::MacrodefContext::func_suite() {
  return getRuleContext<ExplorerScriptParser::Func_suiteContext>(0);
}

std::vector<tree::TerminalNode *> ExplorerScriptParser::MacrodefContext::VARIABLE() {
  return getTokens(ExplorerScriptParser::VARIABLE);
}

tree::TerminalNode* ExplorerScriptParser::MacrodefContext::VARIABLE(size_t i) {
  return getToken(ExplorerScriptParser::VARIABLE, i);
}

std::vector<tree::TerminalNode *> ExplorerScriptParser::MacrodefContext::COMMA() {
  return getTokens(ExplorerScriptParser::COMMA);
}

tree::TerminalNode* ExplorerScriptParser::MacrodefContext::COMMA(size_t i) {
  return getToken(ExplorerScriptParser::COMMA, i);
}


size_t ExplorerScriptParser::MacrodefContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleMacrodef;
}

void ExplorerScriptParser::MacrodefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMacrodef(this);
}

void ExplorerScriptParser::MacrodefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMacrodef(this);
}


std::any ExplorerScriptParser::MacrodefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitMacrodef(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::MacrodefContext* ExplorerScriptParser::macrodef() {
  MacrodefContext *_localctx = _tracker.createInstance<MacrodefContext>(_ctx, getState());
  enterRule(_localctx, 4, ExplorerScriptParser::RuleMacrodef);
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
    match(ExplorerScriptParser::MACRO);
    setState(152);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(153);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(155);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::VARIABLE) {
      setState(154);
      match(ExplorerScriptParser::VARIABLE);
    }
    setState(161);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::COMMA) {
      setState(157);
      match(ExplorerScriptParser::COMMA);
      setState(158);
      match(ExplorerScriptParser::VARIABLE);
      setState(163);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(164);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(165);
    func_suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

ExplorerScriptParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Simple_stmtContext* ExplorerScriptParser::StmtContext::simple_stmt() {
  return getRuleContext<ExplorerScriptParser::Simple_stmtContext>(0);
}

ExplorerScriptParser::Ctx_blockContext* ExplorerScriptParser::StmtContext::ctx_block() {
  return getRuleContext<ExplorerScriptParser::Ctx_blockContext>(0);
}

ExplorerScriptParser::If_blockContext* ExplorerScriptParser::StmtContext::if_block() {
  return getRuleContext<ExplorerScriptParser::If_blockContext>(0);
}

ExplorerScriptParser::Switch_blockContext* ExplorerScriptParser::StmtContext::switch_block() {
  return getRuleContext<ExplorerScriptParser::Switch_blockContext>(0);
}

ExplorerScriptParser::Message_switch_blockContext* ExplorerScriptParser::StmtContext::message_switch_block() {
  return getRuleContext<ExplorerScriptParser::Message_switch_blockContext>(0);
}

ExplorerScriptParser::Forever_blockContext* ExplorerScriptParser::StmtContext::forever_block() {
  return getRuleContext<ExplorerScriptParser::Forever_blockContext>(0);
}

ExplorerScriptParser::For_blockContext* ExplorerScriptParser::StmtContext::for_block() {
  return getRuleContext<ExplorerScriptParser::For_blockContext>(0);
}

ExplorerScriptParser::While_blockContext* ExplorerScriptParser::StmtContext::while_block() {
  return getRuleContext<ExplorerScriptParser::While_blockContext>(0);
}

ExplorerScriptParser::Macro_callContext* ExplorerScriptParser::StmtContext::macro_call() {
  return getRuleContext<ExplorerScriptParser::Macro_callContext>(0);
}


size_t ExplorerScriptParser::StmtContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleStmt;
}

void ExplorerScriptParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void ExplorerScriptParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


std::any ExplorerScriptParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 6, ExplorerScriptParser::RuleStmt);

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
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::JUMP:
      case ExplorerScriptParser::CALL:
      case ExplorerScriptParser::RETURN:
      case ExplorerScriptParser::END:
      case ExplorerScriptParser::HOLD:
      case ExplorerScriptParser::CONTINUE:
      case ExplorerScriptParser::BREAK:
      case ExplorerScriptParser::BREAK_LOOP:
      case ExplorerScriptParser::DUNGEON_MODE:
      case ExplorerScriptParser::CLEAR:
      case ExplorerScriptParser::RESET:
      case ExplorerScriptParser::INIT:
      case ExplorerScriptParser::ADVENTURE_LOG:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::AT:
      case ExplorerScriptParser::PARAGRAPH:
      case ExplorerScriptParser::DECIMAL: {
        setState(167);
        simple_stmt();
        break;
      }

      case ExplorerScriptParser::WITH: {
        setState(168);
        ctx_block();
        break;
      }

      case ExplorerScriptParser::IF: {
        setState(169);
        if_block();
        break;
      }

      case ExplorerScriptParser::SWITCH: {
        setState(170);
        switch_block();
        break;
      }

      case ExplorerScriptParser::MESSAGE_SWITCH_TALK:
      case ExplorerScriptParser::MESSAGE_SWITCH_MONOLOGUE: {
        setState(171);
        message_switch_block();
        break;
      }

      case ExplorerScriptParser::FOREVER: {
        setState(172);
        forever_block();
        break;
      }

      case ExplorerScriptParser::FOR: {
        setState(173);
        for_block();
        break;
      }

      case ExplorerScriptParser::WHILE: {
        setState(174);
        while_block();
        break;
      }

      case ExplorerScriptParser::MACRO_CALL: {
        setState(175);
        macro_call();
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

//----------------- Simple_stmtContext ------------------------------------------------------------------

ExplorerScriptParser::Simple_stmtContext::Simple_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::OperationContext* ExplorerScriptParser::Simple_stmtContext::operation() {
  return getRuleContext<ExplorerScriptParser::OperationContext>(0);
}

ExplorerScriptParser::LabelContext* ExplorerScriptParser::Simple_stmtContext::label() {
  return getRuleContext<ExplorerScriptParser::LabelContext>(0);
}

ExplorerScriptParser::Cntrl_stmtContext* ExplorerScriptParser::Simple_stmtContext::cntrl_stmt() {
  return getRuleContext<ExplorerScriptParser::Cntrl_stmtContext>(0);
}

ExplorerScriptParser::JumpContext* ExplorerScriptParser::Simple_stmtContext::jump() {
  return getRuleContext<ExplorerScriptParser::JumpContext>(0);
}

ExplorerScriptParser::CallContext* ExplorerScriptParser::Simple_stmtContext::call() {
  return getRuleContext<ExplorerScriptParser::CallContext>(0);
}

ExplorerScriptParser::AssignmentContext* ExplorerScriptParser::Simple_stmtContext::assignment() {
  return getRuleContext<ExplorerScriptParser::AssignmentContext>(0);
}


size_t ExplorerScriptParser::Simple_stmtContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSimple_stmt;
}

void ExplorerScriptParser::Simple_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_stmt(this);
}

void ExplorerScriptParser::Simple_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_stmt(this);
}


std::any ExplorerScriptParser::Simple_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSimple_stmt(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Simple_stmtContext* ExplorerScriptParser::simple_stmt() {
  Simple_stmtContext *_localctx = _tracker.createInstance<Simple_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, ExplorerScriptParser::RuleSimple_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(178);
      operation();
      break;
    }

    case 2: {
      setState(179);
      label();
      break;
    }

    case 3: {
      setState(180);
      cntrl_stmt();
      break;
    }

    case 4: {
      setState(181);
      jump();
      break;
    }

    case 5: {
      setState(182);
      call();
      break;
    }

    case 6: {
      setState(183);
      assignment();
      break;
    }

    default:
      break;
    }
    setState(186);
    match(ExplorerScriptParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cntrl_stmtContext ------------------------------------------------------------------

ExplorerScriptParser::Cntrl_stmtContext::Cntrl_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Cntrl_stmtContext::RETURN() {
  return getToken(ExplorerScriptParser::RETURN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Cntrl_stmtContext::END() {
  return getToken(ExplorerScriptParser::END, 0);
}

tree::TerminalNode* ExplorerScriptParser::Cntrl_stmtContext::HOLD() {
  return getToken(ExplorerScriptParser::HOLD, 0);
}

tree::TerminalNode* ExplorerScriptParser::Cntrl_stmtContext::CONTINUE() {
  return getToken(ExplorerScriptParser::CONTINUE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Cntrl_stmtContext::BREAK() {
  return getToken(ExplorerScriptParser::BREAK, 0);
}

tree::TerminalNode* ExplorerScriptParser::Cntrl_stmtContext::BREAK_LOOP() {
  return getToken(ExplorerScriptParser::BREAK_LOOP, 0);
}


size_t ExplorerScriptParser::Cntrl_stmtContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCntrl_stmt;
}

void ExplorerScriptParser::Cntrl_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCntrl_stmt(this);
}

void ExplorerScriptParser::Cntrl_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCntrl_stmt(this);
}


std::any ExplorerScriptParser::Cntrl_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCntrl_stmt(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Cntrl_stmtContext* ExplorerScriptParser::cntrl_stmt() {
  Cntrl_stmtContext *_localctx = _tracker.createInstance<Cntrl_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, ExplorerScriptParser::RuleCntrl_stmt);
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
    setState(188);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 67645734912) != 0))) {
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

//----------------- JumpContext ------------------------------------------------------------------

ExplorerScriptParser::JumpContext::JumpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::JumpContext::JUMP() {
  return getToken(ExplorerScriptParser::JUMP, 0);
}

tree::TerminalNode* ExplorerScriptParser::JumpContext::AT() {
  return getToken(ExplorerScriptParser::AT, 0);
}

tree::TerminalNode* ExplorerScriptParser::JumpContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}


size_t ExplorerScriptParser::JumpContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleJump;
}

void ExplorerScriptParser::JumpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJump(this);
}

void ExplorerScriptParser::JumpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJump(this);
}


std::any ExplorerScriptParser::JumpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitJump(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::JumpContext* ExplorerScriptParser::jump() {
  JumpContext *_localctx = _tracker.createInstance<JumpContext>(_ctx, getState());
  enterRule(_localctx, 12, ExplorerScriptParser::RuleJump);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(ExplorerScriptParser::JUMP);
    setState(191);
    match(ExplorerScriptParser::AT);
    setState(192);
    match(ExplorerScriptParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

ExplorerScriptParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::CallContext::CALL() {
  return getToken(ExplorerScriptParser::CALL, 0);
}

tree::TerminalNode* ExplorerScriptParser::CallContext::AT() {
  return getToken(ExplorerScriptParser::AT, 0);
}

tree::TerminalNode* ExplorerScriptParser::CallContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}


size_t ExplorerScriptParser::CallContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCall;
}

void ExplorerScriptParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}

void ExplorerScriptParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}


std::any ExplorerScriptParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::CallContext* ExplorerScriptParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 14, ExplorerScriptParser::RuleCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(ExplorerScriptParser::CALL);
    setState(195);
    match(ExplorerScriptParser::AT);
    setState(196);
    match(ExplorerScriptParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Macro_callContext ------------------------------------------------------------------

ExplorerScriptParser::Macro_callContext::Macro_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Macro_callContext::MACRO_CALL() {
  return getToken(ExplorerScriptParser::MACRO_CALL, 0);
}

tree::TerminalNode* ExplorerScriptParser::Macro_callContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Macro_callContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

ExplorerScriptParser::ArglistContext* ExplorerScriptParser::Macro_callContext::arglist() {
  return getRuleContext<ExplorerScriptParser::ArglistContext>(0);
}


size_t ExplorerScriptParser::Macro_callContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleMacro_call;
}

void ExplorerScriptParser::Macro_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMacro_call(this);
}

void ExplorerScriptParser::Macro_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMacro_call(this);
}


std::any ExplorerScriptParser::Macro_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitMacro_call(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Macro_callContext* ExplorerScriptParser::macro_call() {
  Macro_callContext *_localctx = _tracker.createInstance<Macro_callContext>(_ctx, getState());
  enterRule(_localctx, 16, ExplorerScriptParser::RuleMacro_call);
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
    setState(198);
    match(ExplorerScriptParser::MACRO_CALL);
    setState(199);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(201);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 58) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 58)) & 671135747) != 0)) {
      setState(200);
      arglist();
    }
    setState(203);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(204);
    match(ExplorerScriptParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ctx_blockContext ------------------------------------------------------------------

ExplorerScriptParser::Ctx_blockContext::Ctx_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Ctx_blockContext::WITH() {
  return getToken(ExplorerScriptParser::WITH, 0);
}

tree::TerminalNode* ExplorerScriptParser::Ctx_blockContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::Ctx_headerContext* ExplorerScriptParser::Ctx_blockContext::ctx_header() {
  return getRuleContext<ExplorerScriptParser::Ctx_headerContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Ctx_blockContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Ctx_blockContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

ExplorerScriptParser::Simple_stmtContext* ExplorerScriptParser::Ctx_blockContext::simple_stmt() {
  return getRuleContext<ExplorerScriptParser::Simple_stmtContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Ctx_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}


size_t ExplorerScriptParser::Ctx_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCtx_block;
}

void ExplorerScriptParser::Ctx_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCtx_block(this);
}

void ExplorerScriptParser::Ctx_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCtx_block(this);
}


std::any ExplorerScriptParser::Ctx_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCtx_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Ctx_blockContext* ExplorerScriptParser::ctx_block() {
  Ctx_blockContext *_localctx = _tracker.createInstance<Ctx_blockContext>(_ctx, getState());
  enterRule(_localctx, 18, ExplorerScriptParser::RuleCtx_block);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(ExplorerScriptParser::WITH);
    setState(207);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(208);
    ctx_header();
    setState(209);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(210);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(211);
    simple_stmt();
    setState(212);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_blockContext ------------------------------------------------------------------

ExplorerScriptParser::If_blockContext::If_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::If_blockContext::IF() {
  return getToken(ExplorerScriptParser::IF, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_blockContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

std::vector<ExplorerScriptParser::If_headerContext *> ExplorerScriptParser::If_blockContext::if_header() {
  return getRuleContexts<ExplorerScriptParser::If_headerContext>();
}

ExplorerScriptParser::If_headerContext* ExplorerScriptParser::If_blockContext::if_header(size_t i) {
  return getRuleContext<ExplorerScriptParser::If_headerContext>(i);
}

tree::TerminalNode* ExplorerScriptParser::If_blockContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_blockContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_blockContext::NOT() {
  return getToken(ExplorerScriptParser::NOT, 0);
}

std::vector<tree::TerminalNode *> ExplorerScriptParser::If_blockContext::OR() {
  return getTokens(ExplorerScriptParser::OR);
}

tree::TerminalNode* ExplorerScriptParser::If_blockContext::OR(size_t i) {
  return getToken(ExplorerScriptParser::OR, i);
}

std::vector<ExplorerScriptParser::StmtContext *> ExplorerScriptParser::If_blockContext::stmt() {
  return getRuleContexts<ExplorerScriptParser::StmtContext>();
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::If_blockContext::stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::StmtContext>(i);
}

std::vector<ExplorerScriptParser::Elseif_blockContext *> ExplorerScriptParser::If_blockContext::elseif_block() {
  return getRuleContexts<ExplorerScriptParser::Elseif_blockContext>();
}

ExplorerScriptParser::Elseif_blockContext* ExplorerScriptParser::If_blockContext::elseif_block(size_t i) {
  return getRuleContext<ExplorerScriptParser::Elseif_blockContext>(i);
}

ExplorerScriptParser::Else_blockContext* ExplorerScriptParser::If_blockContext::else_block() {
  return getRuleContext<ExplorerScriptParser::Else_blockContext>(0);
}


size_t ExplorerScriptParser::If_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleIf_block;
}

void ExplorerScriptParser::If_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_block(this);
}

void ExplorerScriptParser::If_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_block(this);
}


std::any ExplorerScriptParser::If_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_blockContext* ExplorerScriptParser::if_block() {
  If_blockContext *_localctx = _tracker.createInstance<If_blockContext>(_ctx, getState());
  enterRule(_localctx, 20, ExplorerScriptParser::RuleIf_block);
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
    setState(214);
    match(ExplorerScriptParser::IF);
    setState(216);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(215);
      match(ExplorerScriptParser::NOT);
    }
    setState(218);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(219);
    if_header();
    setState(224);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::OR) {
      setState(220);
      match(ExplorerScriptParser::OR);
      setState(221);
      if_header();
      setState(226);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(227);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(228);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(232);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68543623480737792) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & 1245305) != 0)) {
      setState(229);
      stmt();
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(235);
    match(ExplorerScriptParser::CLOSE_BRACE);
    setState(239);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::ELSEIF) {
      setState(236);
      elseif_block();
      setState(241);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(243);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::ELSE) {
      setState(242);
      else_block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Elseif_blockContext ------------------------------------------------------------------

ExplorerScriptParser::Elseif_blockContext::Elseif_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Elseif_blockContext::ELSEIF() {
  return getToken(ExplorerScriptParser::ELSEIF, 0);
}

tree::TerminalNode* ExplorerScriptParser::Elseif_blockContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

std::vector<ExplorerScriptParser::If_headerContext *> ExplorerScriptParser::Elseif_blockContext::if_header() {
  return getRuleContexts<ExplorerScriptParser::If_headerContext>();
}

ExplorerScriptParser::If_headerContext* ExplorerScriptParser::Elseif_blockContext::if_header(size_t i) {
  return getRuleContext<ExplorerScriptParser::If_headerContext>(i);
}

tree::TerminalNode* ExplorerScriptParser::Elseif_blockContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Elseif_blockContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Elseif_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Elseif_blockContext::NOT() {
  return getToken(ExplorerScriptParser::NOT, 0);
}

std::vector<tree::TerminalNode *> ExplorerScriptParser::Elseif_blockContext::OR() {
  return getTokens(ExplorerScriptParser::OR);
}

tree::TerminalNode* ExplorerScriptParser::Elseif_blockContext::OR(size_t i) {
  return getToken(ExplorerScriptParser::OR, i);
}

std::vector<ExplorerScriptParser::StmtContext *> ExplorerScriptParser::Elseif_blockContext::stmt() {
  return getRuleContexts<ExplorerScriptParser::StmtContext>();
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::Elseif_blockContext::stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::StmtContext>(i);
}


size_t ExplorerScriptParser::Elseif_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleElseif_block;
}

void ExplorerScriptParser::Elseif_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseif_block(this);
}

void ExplorerScriptParser::Elseif_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseif_block(this);
}


std::any ExplorerScriptParser::Elseif_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitElseif_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Elseif_blockContext* ExplorerScriptParser::elseif_block() {
  Elseif_blockContext *_localctx = _tracker.createInstance<Elseif_blockContext>(_ctx, getState());
  enterRule(_localctx, 22, ExplorerScriptParser::RuleElseif_block);
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
    setState(245);
    match(ExplorerScriptParser::ELSEIF);
    setState(247);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(246);
      match(ExplorerScriptParser::NOT);
    }
    setState(249);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(250);
    if_header();
    setState(255);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::OR) {
      setState(251);
      match(ExplorerScriptParser::OR);
      setState(252);
      if_header();
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(258);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(259);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(263);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68543623480737792) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & 1245305) != 0)) {
      setState(260);
      stmt();
      setState(265);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(266);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_blockContext ------------------------------------------------------------------

ExplorerScriptParser::Else_blockContext::Else_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Else_blockContext::ELSE() {
  return getToken(ExplorerScriptParser::ELSE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Else_blockContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Else_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

std::vector<ExplorerScriptParser::StmtContext *> ExplorerScriptParser::Else_blockContext::stmt() {
  return getRuleContexts<ExplorerScriptParser::StmtContext>();
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::Else_blockContext::stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::StmtContext>(i);
}


size_t ExplorerScriptParser::Else_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleElse_block;
}

void ExplorerScriptParser::Else_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse_block(this);
}

void ExplorerScriptParser::Else_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse_block(this);
}


std::any ExplorerScriptParser::Else_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitElse_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Else_blockContext* ExplorerScriptParser::else_block() {
  Else_blockContext *_localctx = _tracker.createInstance<Else_blockContext>(_ctx, getState());
  enterRule(_localctx, 24, ExplorerScriptParser::RuleElse_block);
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
    setState(268);
    match(ExplorerScriptParser::ELSE);
    setState(269);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(273);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68543623480737792) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & 1245305) != 0)) {
      setState(270);
      stmt();
      setState(275);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(276);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_headerContext ------------------------------------------------------------------

ExplorerScriptParser::If_headerContext::If_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::If_h_opContext* ExplorerScriptParser::If_headerContext::if_h_op() {
  return getRuleContext<ExplorerScriptParser::If_h_opContext>(0);
}

ExplorerScriptParser::If_h_bitContext* ExplorerScriptParser::If_headerContext::if_h_bit() {
  return getRuleContext<ExplorerScriptParser::If_h_bitContext>(0);
}

ExplorerScriptParser::If_h_negatableContext* ExplorerScriptParser::If_headerContext::if_h_negatable() {
  return getRuleContext<ExplorerScriptParser::If_h_negatableContext>(0);
}

ExplorerScriptParser::If_h_scnContext* ExplorerScriptParser::If_headerContext::if_h_scn() {
  return getRuleContext<ExplorerScriptParser::If_h_scnContext>(0);
}

ExplorerScriptParser::OperationContext* ExplorerScriptParser::If_headerContext::operation() {
  return getRuleContext<ExplorerScriptParser::OperationContext>(0);
}


size_t ExplorerScriptParser::If_headerContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleIf_header;
}

void ExplorerScriptParser::If_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_header(this);
}

void ExplorerScriptParser::If_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_header(this);
}


std::any ExplorerScriptParser::If_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_header(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_headerContext* ExplorerScriptParser::if_header() {
  If_headerContext *_localctx = _tracker.createInstance<If_headerContext>(_ctx, getState());
  enterRule(_localctx, 26, ExplorerScriptParser::RuleIf_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(278);
      if_h_op();
      break;
    }

    case 2: {
      setState(279);
      if_h_bit();
      break;
    }

    case 3: {
      setState(280);
      if_h_negatable();
      break;
    }

    case 4: {
      setState(281);
      if_h_scn();
      break;
    }

    case 5: {
      setState(282);
      operation();
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

//----------------- If_h_negatableContext ------------------------------------------------------------------

ExplorerScriptParser::If_h_negatableContext::If_h_negatableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::If_h_negatableContext::DEBUG() {
  return getToken(ExplorerScriptParser::DEBUG, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_h_negatableContext::EDIT() {
  return getToken(ExplorerScriptParser::EDIT, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_h_negatableContext::VARIATION() {
  return getToken(ExplorerScriptParser::VARIATION, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_h_negatableContext::NOT() {
  return getToken(ExplorerScriptParser::NOT, 0);
}


size_t ExplorerScriptParser::If_h_negatableContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleIf_h_negatable;
}

void ExplorerScriptParser::If_h_negatableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_h_negatable(this);
}

void ExplorerScriptParser::If_h_negatableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_h_negatable(this);
}


std::any ExplorerScriptParser::If_h_negatableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_h_negatable(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_h_negatableContext* ExplorerScriptParser::if_h_negatable() {
  If_h_negatableContext *_localctx = _tracker.createInstance<If_h_negatableContext>(_ctx, getState());
  enterRule(_localctx, 28, ExplorerScriptParser::RuleIf_h_negatable);
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
    setState(286);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(285);
      match(ExplorerScriptParser::NOT);
    }
    setState(288);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 962072674304) != 0))) {
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

//----------------- If_h_opContext ------------------------------------------------------------------

ExplorerScriptParser::If_h_opContext::If_h_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExplorerScriptParser::Integer_likeContext *> ExplorerScriptParser::If_h_opContext::integer_like() {
  return getRuleContexts<ExplorerScriptParser::Integer_likeContext>();
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::If_h_opContext::integer_like(size_t i) {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(i);
}

ExplorerScriptParser::Conditional_operatorContext* ExplorerScriptParser::If_h_opContext::conditional_operator() {
  return getRuleContext<ExplorerScriptParser::Conditional_operatorContext>(0);
}

ExplorerScriptParser::Value_ofContext* ExplorerScriptParser::If_h_opContext::value_of() {
  return getRuleContext<ExplorerScriptParser::Value_ofContext>(0);
}


size_t ExplorerScriptParser::If_h_opContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleIf_h_op;
}

void ExplorerScriptParser::If_h_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_h_op(this);
}

void ExplorerScriptParser::If_h_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_h_op(this);
}


std::any ExplorerScriptParser::If_h_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_h_op(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_h_opContext* ExplorerScriptParser::if_h_op() {
  If_h_opContext *_localctx = _tracker.createInstance<If_h_opContext>(_ctx, getState());
  enterRule(_localctx, 30, ExplorerScriptParser::RuleIf_h_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    integer_like();
    setState(291);
    conditional_operator();
    setState(294);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::VALUE: {
        setState(292);
        value_of();
        break;
      }

      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::DECIMAL: {
        setState(293);
        integer_like();
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

//----------------- If_h_bitContext ------------------------------------------------------------------

ExplorerScriptParser::If_h_bitContext::If_h_bitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::If_h_bitContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::If_h_bitContext::OPEN_BRACKET() {
  return getToken(ExplorerScriptParser::OPEN_BRACKET, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_h_bitContext::INTEGER() {
  return getToken(ExplorerScriptParser::INTEGER, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_h_bitContext::CLOSE_BRACKET() {
  return getToken(ExplorerScriptParser::CLOSE_BRACKET, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_h_bitContext::NOT() {
  return getToken(ExplorerScriptParser::NOT, 0);
}


size_t ExplorerScriptParser::If_h_bitContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleIf_h_bit;
}

void ExplorerScriptParser::If_h_bitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_h_bit(this);
}

void ExplorerScriptParser::If_h_bitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_h_bit(this);
}


std::any ExplorerScriptParser::If_h_bitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_h_bit(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_h_bitContext* ExplorerScriptParser::if_h_bit() {
  If_h_bitContext *_localctx = _tracker.createInstance<If_h_bitContext>(_ctx, getState());
  enterRule(_localctx, 32, ExplorerScriptParser::RuleIf_h_bit);
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
    setState(297);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(296);
      match(ExplorerScriptParser::NOT);
    }
    setState(299);
    integer_like();
    setState(300);
    match(ExplorerScriptParser::OPEN_BRACKET);
    setState(301);
    match(ExplorerScriptParser::INTEGER);
    setState(302);
    match(ExplorerScriptParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_h_scnContext ------------------------------------------------------------------

ExplorerScriptParser::If_h_scnContext::If_h_scnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Scn_varContext* ExplorerScriptParser::If_h_scnContext::scn_var() {
  return getRuleContext<ExplorerScriptParser::Scn_varContext>(0);
}

ExplorerScriptParser::Conditional_operatorContext* ExplorerScriptParser::If_h_scnContext::conditional_operator() {
  return getRuleContext<ExplorerScriptParser::Conditional_operatorContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::If_h_scnContext::OPEN_BRACKET() {
  return getToken(ExplorerScriptParser::OPEN_BRACKET, 0);
}

std::vector<tree::TerminalNode *> ExplorerScriptParser::If_h_scnContext::INTEGER() {
  return getTokens(ExplorerScriptParser::INTEGER);
}

tree::TerminalNode* ExplorerScriptParser::If_h_scnContext::INTEGER(size_t i) {
  return getToken(ExplorerScriptParser::INTEGER, i);
}

tree::TerminalNode* ExplorerScriptParser::If_h_scnContext::COMMA() {
  return getToken(ExplorerScriptParser::COMMA, 0);
}

tree::TerminalNode* ExplorerScriptParser::If_h_scnContext::CLOSE_BRACKET() {
  return getToken(ExplorerScriptParser::CLOSE_BRACKET, 0);
}


size_t ExplorerScriptParser::If_h_scnContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleIf_h_scn;
}

void ExplorerScriptParser::If_h_scnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_h_scn(this);
}

void ExplorerScriptParser::If_h_scnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_h_scn(this);
}


std::any ExplorerScriptParser::If_h_scnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_h_scn(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_h_scnContext* ExplorerScriptParser::if_h_scn() {
  If_h_scnContext *_localctx = _tracker.createInstance<If_h_scnContext>(_ctx, getState());
  enterRule(_localctx, 34, ExplorerScriptParser::RuleIf_h_scn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    scn_var();
    setState(305);
    conditional_operator();
    setState(306);
    match(ExplorerScriptParser::OPEN_BRACKET);
    setState(307);
    match(ExplorerScriptParser::INTEGER);
    setState(308);
    match(ExplorerScriptParser::COMMA);
    setState(309);
    match(ExplorerScriptParser::INTEGER);
    setState(310);
    match(ExplorerScriptParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_blockContext ------------------------------------------------------------------

ExplorerScriptParser::Switch_blockContext::Switch_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Switch_blockContext::SWITCH() {
  return getToken(ExplorerScriptParser::SWITCH, 0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_blockContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::Switch_headerContext* ExplorerScriptParser::Switch_blockContext::switch_header() {
  return getRuleContext<ExplorerScriptParser::Switch_headerContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_blockContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_blockContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

std::vector<ExplorerScriptParser::DefaultContext *> ExplorerScriptParser::Switch_blockContext::default_() {
  return getRuleContexts<ExplorerScriptParser::DefaultContext>();
}

ExplorerScriptParser::DefaultContext* ExplorerScriptParser::Switch_blockContext::default_(size_t i) {
  return getRuleContext<ExplorerScriptParser::DefaultContext>(i);
}

std::vector<ExplorerScriptParser::Single_case_blockContext *> ExplorerScriptParser::Switch_blockContext::single_case_block() {
  return getRuleContexts<ExplorerScriptParser::Single_case_blockContext>();
}

ExplorerScriptParser::Single_case_blockContext* ExplorerScriptParser::Switch_blockContext::single_case_block(size_t i) {
  return getRuleContext<ExplorerScriptParser::Single_case_blockContext>(i);
}


size_t ExplorerScriptParser::Switch_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSwitch_block;
}

void ExplorerScriptParser::Switch_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch_block(this);
}

void ExplorerScriptParser::Switch_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch_block(this);
}


std::any ExplorerScriptParser::Switch_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_blockContext* ExplorerScriptParser::switch_block() {
  Switch_blockContext *_localctx = _tracker.createInstance<Switch_blockContext>(_ctx, getState());
  enterRule(_localctx, 36, ExplorerScriptParser::RuleSwitch_block);
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
    setState(312);
    match(ExplorerScriptParser::SWITCH);
    setState(313);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(314);
    switch_header();
    setState(315);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(316);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(321);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::CASE

    || _la == ExplorerScriptParser::DEFAULT) {
      setState(319);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ExplorerScriptParser::DEFAULT: {
          setState(317);
          default_();
          break;
        }

        case ExplorerScriptParser::CASE: {
          setState(318);
          single_case_block();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(323);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(324);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Message_switch_blockContext ------------------------------------------------------------------

ExplorerScriptParser::Message_switch_blockContext::Message_switch_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Message_switch_blockContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Message_switch_blockContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Message_switch_blockContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Message_switch_blockContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Message_switch_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Message_switch_blockContext::MESSAGE_SWITCH_TALK() {
  return getToken(ExplorerScriptParser::MESSAGE_SWITCH_TALK, 0);
}

tree::TerminalNode* ExplorerScriptParser::Message_switch_blockContext::MESSAGE_SWITCH_MONOLOGUE() {
  return getToken(ExplorerScriptParser::MESSAGE_SWITCH_MONOLOGUE, 0);
}

std::vector<ExplorerScriptParser::DefaultContext *> ExplorerScriptParser::Message_switch_blockContext::default_() {
  return getRuleContexts<ExplorerScriptParser::DefaultContext>();
}

ExplorerScriptParser::DefaultContext* ExplorerScriptParser::Message_switch_blockContext::default_(size_t i) {
  return getRuleContext<ExplorerScriptParser::DefaultContext>(i);
}

std::vector<ExplorerScriptParser::Single_case_blockContext *> ExplorerScriptParser::Message_switch_blockContext::single_case_block() {
  return getRuleContexts<ExplorerScriptParser::Single_case_blockContext>();
}

ExplorerScriptParser::Single_case_blockContext* ExplorerScriptParser::Message_switch_blockContext::single_case_block(size_t i) {
  return getRuleContext<ExplorerScriptParser::Single_case_blockContext>(i);
}


size_t ExplorerScriptParser::Message_switch_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleMessage_switch_block;
}

void ExplorerScriptParser::Message_switch_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMessage_switch_block(this);
}

void ExplorerScriptParser::Message_switch_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMessage_switch_block(this);
}


std::any ExplorerScriptParser::Message_switch_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitMessage_switch_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Message_switch_blockContext* ExplorerScriptParser::message_switch_block() {
  Message_switch_blockContext *_localctx = _tracker.createInstance<Message_switch_blockContext>(_ctx, getState());
  enterRule(_localctx, 38, ExplorerScriptParser::RuleMessage_switch_block);
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
    setState(326);
    _la = _input->LA(1);
    if (!(_la == ExplorerScriptParser::MESSAGE_SWITCH_TALK

    || _la == ExplorerScriptParser::MESSAGE_SWITCH_MONOLOGUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(327);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(328);
    integer_like();
    setState(329);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(330);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(335);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::CASE

    || _la == ExplorerScriptParser::DEFAULT) {
      setState(333);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ExplorerScriptParser::DEFAULT: {
          setState(331);
          default_();
          break;
        }

        case ExplorerScriptParser::CASE: {
          setState(332);
          single_case_block();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(337);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(338);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Single_case_blockContext ------------------------------------------------------------------

ExplorerScriptParser::Single_case_blockContext::Single_case_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Single_case_blockContext::CASE() {
  return getToken(ExplorerScriptParser::CASE, 0);
}

ExplorerScriptParser::Case_headerContext* ExplorerScriptParser::Single_case_blockContext::case_header() {
  return getRuleContext<ExplorerScriptParser::Case_headerContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Single_case_blockContext::COLON() {
  return getToken(ExplorerScriptParser::COLON, 0);
}

ExplorerScriptParser::StringContext* ExplorerScriptParser::Single_case_blockContext::string() {
  return getRuleContext<ExplorerScriptParser::StringContext>(0);
}

std::vector<ExplorerScriptParser::StmtContext *> ExplorerScriptParser::Single_case_blockContext::stmt() {
  return getRuleContexts<ExplorerScriptParser::StmtContext>();
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::Single_case_blockContext::stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::StmtContext>(i);
}


size_t ExplorerScriptParser::Single_case_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSingle_case_block;
}

void ExplorerScriptParser::Single_case_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_case_block(this);
}

void ExplorerScriptParser::Single_case_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_case_block(this);
}


std::any ExplorerScriptParser::Single_case_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSingle_case_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Single_case_blockContext* ExplorerScriptParser::single_case_block() {
  Single_case_blockContext *_localctx = _tracker.createInstance<Single_case_blockContext>(_ctx, getState());
  enterRule(_localctx, 40, ExplorerScriptParser::RuleSingle_case_block);
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
    setState(340);
    match(ExplorerScriptParser::CASE);
    setState(341);
    case_header();
    setState(342);
    match(ExplorerScriptParser::COLON);
    setState(350);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::JUMP:
      case ExplorerScriptParser::CALL:
      case ExplorerScriptParser::IF:
      case ExplorerScriptParser::FOREVER:
      case ExplorerScriptParser::WITH:
      case ExplorerScriptParser::SWITCH:
      case ExplorerScriptParser::RETURN:
      case ExplorerScriptParser::END:
      case ExplorerScriptParser::HOLD:
      case ExplorerScriptParser::CONTINUE:
      case ExplorerScriptParser::BREAK:
      case ExplorerScriptParser::BREAK_LOOP:
      case ExplorerScriptParser::DUNGEON_MODE:
      case ExplorerScriptParser::CASE:
      case ExplorerScriptParser::DEFAULT:
      case ExplorerScriptParser::CLEAR:
      case ExplorerScriptParser::RESET:
      case ExplorerScriptParser::INIT:
      case ExplorerScriptParser::ADVENTURE_LOG:
      case ExplorerScriptParser::MESSAGE_SWITCH_TALK:
      case ExplorerScriptParser::MESSAGE_SWITCH_MONOLOGUE:
      case ExplorerScriptParser::WHILE:
      case ExplorerScriptParser::FOR:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::MACRO_CALL:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::AT:
      case ExplorerScriptParser::PARAGRAPH:
      case ExplorerScriptParser::CLOSE_BRACE:
      case ExplorerScriptParser::DECIMAL: {
        setState(346);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 68543623480737792) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & 1245305) != 0)) {
          setState(343);
          stmt();
          setState(348);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::OPEN_BRACE: {
        setState(349);
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

//----------------- DefaultContext ------------------------------------------------------------------

ExplorerScriptParser::DefaultContext::DefaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::DefaultContext::DEFAULT() {
  return getToken(ExplorerScriptParser::DEFAULT, 0);
}

tree::TerminalNode* ExplorerScriptParser::DefaultContext::COLON() {
  return getToken(ExplorerScriptParser::COLON, 0);
}

ExplorerScriptParser::StringContext* ExplorerScriptParser::DefaultContext::string() {
  return getRuleContext<ExplorerScriptParser::StringContext>(0);
}

std::vector<ExplorerScriptParser::StmtContext *> ExplorerScriptParser::DefaultContext::stmt() {
  return getRuleContexts<ExplorerScriptParser::StmtContext>();
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::DefaultContext::stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::StmtContext>(i);
}


size_t ExplorerScriptParser::DefaultContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleDefault;
}

void ExplorerScriptParser::DefaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefault(this);
}

void ExplorerScriptParser::DefaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefault(this);
}


std::any ExplorerScriptParser::DefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitDefault(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::DefaultContext* ExplorerScriptParser::default_() {
  DefaultContext *_localctx = _tracker.createInstance<DefaultContext>(_ctx, getState());
  enterRule(_localctx, 42, ExplorerScriptParser::RuleDefault);
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
    setState(352);
    match(ExplorerScriptParser::DEFAULT);
    setState(353);
    match(ExplorerScriptParser::COLON);
    setState(361);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::JUMP:
      case ExplorerScriptParser::CALL:
      case ExplorerScriptParser::IF:
      case ExplorerScriptParser::FOREVER:
      case ExplorerScriptParser::WITH:
      case ExplorerScriptParser::SWITCH:
      case ExplorerScriptParser::RETURN:
      case ExplorerScriptParser::END:
      case ExplorerScriptParser::HOLD:
      case ExplorerScriptParser::CONTINUE:
      case ExplorerScriptParser::BREAK:
      case ExplorerScriptParser::BREAK_LOOP:
      case ExplorerScriptParser::DUNGEON_MODE:
      case ExplorerScriptParser::CASE:
      case ExplorerScriptParser::DEFAULT:
      case ExplorerScriptParser::CLEAR:
      case ExplorerScriptParser::RESET:
      case ExplorerScriptParser::INIT:
      case ExplorerScriptParser::ADVENTURE_LOG:
      case ExplorerScriptParser::MESSAGE_SWITCH_TALK:
      case ExplorerScriptParser::MESSAGE_SWITCH_MONOLOGUE:
      case ExplorerScriptParser::WHILE:
      case ExplorerScriptParser::FOR:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::MACRO_CALL:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::AT:
      case ExplorerScriptParser::PARAGRAPH:
      case ExplorerScriptParser::CLOSE_BRACE:
      case ExplorerScriptParser::DECIMAL: {
        setState(357);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 68543623480737792) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & 1245305) != 0)) {
          setState(354);
          stmt();
          setState(359);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::OPEN_BRACE: {
        setState(360);
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

//----------------- Switch_headerContext ------------------------------------------------------------------

ExplorerScriptParser::Switch_headerContext::Switch_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Switch_headerContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

ExplorerScriptParser::OperationContext* ExplorerScriptParser::Switch_headerContext::operation() {
  return getRuleContext<ExplorerScriptParser::OperationContext>(0);
}

ExplorerScriptParser::Switch_h_scnContext* ExplorerScriptParser::Switch_headerContext::switch_h_scn() {
  return getRuleContext<ExplorerScriptParser::Switch_h_scnContext>(0);
}

ExplorerScriptParser::Switch_h_randomContext* ExplorerScriptParser::Switch_headerContext::switch_h_random() {
  return getRuleContext<ExplorerScriptParser::Switch_h_randomContext>(0);
}

ExplorerScriptParser::Switch_h_dungeon_modeContext* ExplorerScriptParser::Switch_headerContext::switch_h_dungeon_mode() {
  return getRuleContext<ExplorerScriptParser::Switch_h_dungeon_modeContext>(0);
}

ExplorerScriptParser::Switch_h_sectorContext* ExplorerScriptParser::Switch_headerContext::switch_h_sector() {
  return getRuleContext<ExplorerScriptParser::Switch_h_sectorContext>(0);
}


size_t ExplorerScriptParser::Switch_headerContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSwitch_header;
}

void ExplorerScriptParser::Switch_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch_header(this);
}

void ExplorerScriptParser::Switch_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch_header(this);
}


std::any ExplorerScriptParser::Switch_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_header(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_headerContext* ExplorerScriptParser::switch_header() {
  Switch_headerContext *_localctx = _tracker.createInstance<Switch_headerContext>(_ctx, getState());
  enterRule(_localctx, 44, ExplorerScriptParser::RuleSwitch_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(369);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(363);
      integer_like();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(364);
      operation();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(365);
      switch_h_scn();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(366);
      switch_h_random();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(367);
      switch_h_dungeon_mode();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(368);
      switch_h_sector();
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

//----------------- Switch_h_scnContext ------------------------------------------------------------------

ExplorerScriptParser::Switch_h_scnContext::Switch_h_scnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Scn_varContext* ExplorerScriptParser::Switch_h_scnContext::scn_var() {
  return getRuleContext<ExplorerScriptParser::Scn_varContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_scnContext::OPEN_BRACKET() {
  return getToken(ExplorerScriptParser::OPEN_BRACKET, 0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_scnContext::INTEGER() {
  return getToken(ExplorerScriptParser::INTEGER, 0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_scnContext::CLOSE_BRACKET() {
  return getToken(ExplorerScriptParser::CLOSE_BRACKET, 0);
}


size_t ExplorerScriptParser::Switch_h_scnContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSwitch_h_scn;
}

void ExplorerScriptParser::Switch_h_scnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch_h_scn(this);
}

void ExplorerScriptParser::Switch_h_scnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch_h_scn(this);
}


std::any ExplorerScriptParser::Switch_h_scnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_h_scn(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_h_scnContext* ExplorerScriptParser::switch_h_scn() {
  Switch_h_scnContext *_localctx = _tracker.createInstance<Switch_h_scnContext>(_ctx, getState());
  enterRule(_localctx, 46, ExplorerScriptParser::RuleSwitch_h_scn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    scn_var();
    setState(372);
    match(ExplorerScriptParser::OPEN_BRACKET);
    setState(373);
    match(ExplorerScriptParser::INTEGER);
    setState(374);
    match(ExplorerScriptParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_h_randomContext ------------------------------------------------------------------

ExplorerScriptParser::Switch_h_randomContext::Switch_h_randomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_randomContext::RANDOM() {
  return getToken(ExplorerScriptParser::RANDOM, 0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_randomContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Switch_h_randomContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_randomContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Switch_h_randomContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSwitch_h_random;
}

void ExplorerScriptParser::Switch_h_randomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch_h_random(this);
}

void ExplorerScriptParser::Switch_h_randomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch_h_random(this);
}


std::any ExplorerScriptParser::Switch_h_randomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_h_random(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_h_randomContext* ExplorerScriptParser::switch_h_random() {
  Switch_h_randomContext *_localctx = _tracker.createInstance<Switch_h_randomContext>(_ctx, getState());
  enterRule(_localctx, 48, ExplorerScriptParser::RuleSwitch_h_random);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(376);
    match(ExplorerScriptParser::RANDOM);
    setState(377);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(378);
    integer_like();
    setState(379);
    match(ExplorerScriptParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_h_dungeon_modeContext ------------------------------------------------------------------

ExplorerScriptParser::Switch_h_dungeon_modeContext::Switch_h_dungeon_modeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_dungeon_modeContext::DUNGEON_MODE() {
  return getToken(ExplorerScriptParser::DUNGEON_MODE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_dungeon_modeContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Switch_h_dungeon_modeContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_dungeon_modeContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Switch_h_dungeon_modeContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSwitch_h_dungeon_mode;
}

void ExplorerScriptParser::Switch_h_dungeon_modeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch_h_dungeon_mode(this);
}

void ExplorerScriptParser::Switch_h_dungeon_modeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch_h_dungeon_mode(this);
}


std::any ExplorerScriptParser::Switch_h_dungeon_modeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_h_dungeon_mode(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_h_dungeon_modeContext* ExplorerScriptParser::switch_h_dungeon_mode() {
  Switch_h_dungeon_modeContext *_localctx = _tracker.createInstance<Switch_h_dungeon_modeContext>(_ctx, getState());
  enterRule(_localctx, 50, ExplorerScriptParser::RuleSwitch_h_dungeon_mode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    match(ExplorerScriptParser::DUNGEON_MODE);
    setState(382);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(383);
    integer_like();
    setState(384);
    match(ExplorerScriptParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_h_sectorContext ------------------------------------------------------------------

ExplorerScriptParser::Switch_h_sectorContext::Switch_h_sectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_sectorContext::SECTOR() {
  return getToken(ExplorerScriptParser::SECTOR, 0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_sectorContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_sectorContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Switch_h_sectorContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSwitch_h_sector;
}

void ExplorerScriptParser::Switch_h_sectorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitch_h_sector(this);
}

void ExplorerScriptParser::Switch_h_sectorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitch_h_sector(this);
}


std::any ExplorerScriptParser::Switch_h_sectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_h_sector(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_h_sectorContext* ExplorerScriptParser::switch_h_sector() {
  Switch_h_sectorContext *_localctx = _tracker.createInstance<Switch_h_sectorContext>(_ctx, getState());
  enterRule(_localctx, 52, ExplorerScriptParser::RuleSwitch_h_sector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    match(ExplorerScriptParser::SECTOR);
    setState(387);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(388);
    match(ExplorerScriptParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_headerContext ------------------------------------------------------------------

ExplorerScriptParser::Case_headerContext::Case_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Case_headerContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

ExplorerScriptParser::Case_h_menuContext* ExplorerScriptParser::Case_headerContext::case_h_menu() {
  return getRuleContext<ExplorerScriptParser::Case_h_menuContext>(0);
}

ExplorerScriptParser::Case_h_menu2Context* ExplorerScriptParser::Case_headerContext::case_h_menu2() {
  return getRuleContext<ExplorerScriptParser::Case_h_menu2Context>(0);
}

ExplorerScriptParser::Case_h_opContext* ExplorerScriptParser::Case_headerContext::case_h_op() {
  return getRuleContext<ExplorerScriptParser::Case_h_opContext>(0);
}


size_t ExplorerScriptParser::Case_headerContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCase_header;
}

void ExplorerScriptParser::Case_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_header(this);
}

void ExplorerScriptParser::Case_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_header(this);
}


std::any ExplorerScriptParser::Case_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCase_header(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Case_headerContext* ExplorerScriptParser::case_header() {
  Case_headerContext *_localctx = _tracker.createInstance<Case_headerContext>(_ctx, getState());
  enterRule(_localctx, 54, ExplorerScriptParser::RuleCase_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(394);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::DECIMAL: {
        enterOuterAlt(_localctx, 1);
        setState(390);
        integer_like();
        break;
      }

      case ExplorerScriptParser::MENU: {
        enterOuterAlt(_localctx, 2);
        setState(391);
        case_h_menu();
        break;
      }

      case ExplorerScriptParser::MENU2: {
        enterOuterAlt(_localctx, 3);
        setState(392);
        case_h_menu2();
        break;
      }

      case ExplorerScriptParser::OP_FALSE:
      case ExplorerScriptParser::OP_TRUE:
      case ExplorerScriptParser::OPEN_SHARP:
      case ExplorerScriptParser::CLOSE_SHARP:
      case ExplorerScriptParser::OP_EQ:
      case ExplorerScriptParser::OP_LE:
      case ExplorerScriptParser::OP_GE:
      case ExplorerScriptParser::OP_NEQ:
      case ExplorerScriptParser::OP_AND:
      case ExplorerScriptParser::OP_XOR:
      case ExplorerScriptParser::OP_BICH: {
        enterOuterAlt(_localctx, 4);
        setState(393);
        case_h_op();
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

//----------------- Case_h_menuContext ------------------------------------------------------------------

ExplorerScriptParser::Case_h_menuContext::Case_h_menuContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Case_h_menuContext::MENU() {
  return getToken(ExplorerScriptParser::MENU, 0);
}

tree::TerminalNode* ExplorerScriptParser::Case_h_menuContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::StringContext* ExplorerScriptParser::Case_h_menuContext::string() {
  return getRuleContext<ExplorerScriptParser::StringContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Case_h_menuContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Case_h_menuContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCase_h_menu;
}

void ExplorerScriptParser::Case_h_menuContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_h_menu(this);
}

void ExplorerScriptParser::Case_h_menuContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_h_menu(this);
}


std::any ExplorerScriptParser::Case_h_menuContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCase_h_menu(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Case_h_menuContext* ExplorerScriptParser::case_h_menu() {
  Case_h_menuContext *_localctx = _tracker.createInstance<Case_h_menuContext>(_ctx, getState());
  enterRule(_localctx, 56, ExplorerScriptParser::RuleCase_h_menu);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    match(ExplorerScriptParser::MENU);
    setState(397);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(398);
    string();
    setState(399);
    match(ExplorerScriptParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_h_menu2Context ------------------------------------------------------------------

ExplorerScriptParser::Case_h_menu2Context::Case_h_menu2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Case_h_menu2Context::MENU2() {
  return getToken(ExplorerScriptParser::MENU2, 0);
}

tree::TerminalNode* ExplorerScriptParser::Case_h_menu2Context::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Case_h_menu2Context::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Case_h_menu2Context::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Case_h_menu2Context::getRuleIndex() const {
  return ExplorerScriptParser::RuleCase_h_menu2;
}

void ExplorerScriptParser::Case_h_menu2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_h_menu2(this);
}

void ExplorerScriptParser::Case_h_menu2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_h_menu2(this);
}


std::any ExplorerScriptParser::Case_h_menu2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCase_h_menu2(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Case_h_menu2Context* ExplorerScriptParser::case_h_menu2() {
  Case_h_menu2Context *_localctx = _tracker.createInstance<Case_h_menu2Context>(_ctx, getState());
  enterRule(_localctx, 58, ExplorerScriptParser::RuleCase_h_menu2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(ExplorerScriptParser::MENU2);
    setState(402);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(403);
    integer_like();
    setState(404);
    match(ExplorerScriptParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_h_opContext ------------------------------------------------------------------

ExplorerScriptParser::Case_h_opContext::Case_h_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Conditional_operatorContext* ExplorerScriptParser::Case_h_opContext::conditional_operator() {
  return getRuleContext<ExplorerScriptParser::Conditional_operatorContext>(0);
}

ExplorerScriptParser::Value_ofContext* ExplorerScriptParser::Case_h_opContext::value_of() {
  return getRuleContext<ExplorerScriptParser::Value_ofContext>(0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Case_h_opContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}


size_t ExplorerScriptParser::Case_h_opContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCase_h_op;
}

void ExplorerScriptParser::Case_h_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCase_h_op(this);
}

void ExplorerScriptParser::Case_h_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCase_h_op(this);
}


std::any ExplorerScriptParser::Case_h_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCase_h_op(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Case_h_opContext* ExplorerScriptParser::case_h_op() {
  Case_h_opContext *_localctx = _tracker.createInstance<Case_h_opContext>(_ctx, getState());
  enterRule(_localctx, 60, ExplorerScriptParser::RuleCase_h_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
    conditional_operator();
    setState(409);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::VALUE: {
        setState(407);
        value_of();
        break;
      }

      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::DECIMAL: {
        setState(408);
        integer_like();
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

//----------------- Forever_blockContext ------------------------------------------------------------------

ExplorerScriptParser::Forever_blockContext::Forever_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Forever_blockContext::FOREVER() {
  return getToken(ExplorerScriptParser::FOREVER, 0);
}

tree::TerminalNode* ExplorerScriptParser::Forever_blockContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Forever_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

std::vector<ExplorerScriptParser::StmtContext *> ExplorerScriptParser::Forever_blockContext::stmt() {
  return getRuleContexts<ExplorerScriptParser::StmtContext>();
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::Forever_blockContext::stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::StmtContext>(i);
}


size_t ExplorerScriptParser::Forever_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleForever_block;
}

void ExplorerScriptParser::Forever_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForever_block(this);
}

void ExplorerScriptParser::Forever_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForever_block(this);
}


std::any ExplorerScriptParser::Forever_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitForever_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Forever_blockContext* ExplorerScriptParser::forever_block() {
  Forever_blockContext *_localctx = _tracker.createInstance<Forever_blockContext>(_ctx, getState());
  enterRule(_localctx, 62, ExplorerScriptParser::RuleForever_block);
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
    setState(411);
    match(ExplorerScriptParser::FOREVER);
    setState(412);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(416);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68543623480737792) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & 1245305) != 0)) {
      setState(413);
      stmt();
      setState(418);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(419);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_blockContext ------------------------------------------------------------------

ExplorerScriptParser::For_blockContext::For_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::For_blockContext::FOR() {
  return getToken(ExplorerScriptParser::FOR, 0);
}

tree::TerminalNode* ExplorerScriptParser::For_blockContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

std::vector<ExplorerScriptParser::Simple_stmtContext *> ExplorerScriptParser::For_blockContext::simple_stmt() {
  return getRuleContexts<ExplorerScriptParser::Simple_stmtContext>();
}

ExplorerScriptParser::Simple_stmtContext* ExplorerScriptParser::For_blockContext::simple_stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::Simple_stmtContext>(i);
}

ExplorerScriptParser::If_headerContext* ExplorerScriptParser::For_blockContext::if_header() {
  return getRuleContext<ExplorerScriptParser::If_headerContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::For_blockContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::For_blockContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::For_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

std::vector<ExplorerScriptParser::StmtContext *> ExplorerScriptParser::For_blockContext::stmt() {
  return getRuleContexts<ExplorerScriptParser::StmtContext>();
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::For_blockContext::stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::StmtContext>(i);
}


size_t ExplorerScriptParser::For_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleFor_block;
}

void ExplorerScriptParser::For_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_block(this);
}

void ExplorerScriptParser::For_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_block(this);
}


std::any ExplorerScriptParser::For_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFor_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::For_blockContext* ExplorerScriptParser::for_block() {
  For_blockContext *_localctx = _tracker.createInstance<For_blockContext>(_ctx, getState());
  enterRule(_localctx, 64, ExplorerScriptParser::RuleFor_block);
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
    setState(421);
    match(ExplorerScriptParser::FOR);
    setState(422);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(423);
    simple_stmt();
    setState(424);
    if_header();
    setState(425);
    match(ExplorerScriptParser::T__0);
    setState(426);
    simple_stmt();
    setState(427);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(428);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(432);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68543623480737792) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & 1245305) != 0)) {
      setState(429);
      stmt();
      setState(434);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(435);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_blockContext ------------------------------------------------------------------

ExplorerScriptParser::While_blockContext::While_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::While_blockContext::WHILE() {
  return getToken(ExplorerScriptParser::WHILE, 0);
}

tree::TerminalNode* ExplorerScriptParser::While_blockContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::If_headerContext* ExplorerScriptParser::While_blockContext::if_header() {
  return getRuleContext<ExplorerScriptParser::If_headerContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::While_blockContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::While_blockContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::While_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::While_blockContext::NOT() {
  return getToken(ExplorerScriptParser::NOT, 0);
}

std::vector<ExplorerScriptParser::StmtContext *> ExplorerScriptParser::While_blockContext::stmt() {
  return getRuleContexts<ExplorerScriptParser::StmtContext>();
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::While_blockContext::stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::StmtContext>(i);
}


size_t ExplorerScriptParser::While_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleWhile_block;
}

void ExplorerScriptParser::While_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_block(this);
}

void ExplorerScriptParser::While_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_block(this);
}


std::any ExplorerScriptParser::While_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitWhile_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::While_blockContext* ExplorerScriptParser::while_block() {
  While_blockContext *_localctx = _tracker.createInstance<While_blockContext>(_ctx, getState());
  enterRule(_localctx, 66, ExplorerScriptParser::RuleWhile_block);
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
    setState(437);
    match(ExplorerScriptParser::WHILE);
    setState(439);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(438);
      match(ExplorerScriptParser::NOT);
    }
    setState(441);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(442);
    if_header();
    setState(443);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(444);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(448);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 68543623480737792) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & 1245305) != 0)) {
      setState(445);
      stmt();
      setState(450);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(451);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

ExplorerScriptParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Assignment_regularContext* ExplorerScriptParser::AssignmentContext::assignment_regular() {
  return getRuleContext<ExplorerScriptParser::Assignment_regularContext>(0);
}

ExplorerScriptParser::Assignment_clearContext* ExplorerScriptParser::AssignmentContext::assignment_clear() {
  return getRuleContext<ExplorerScriptParser::Assignment_clearContext>(0);
}

ExplorerScriptParser::Assignment_initialContext* ExplorerScriptParser::AssignmentContext::assignment_initial() {
  return getRuleContext<ExplorerScriptParser::Assignment_initialContext>(0);
}

ExplorerScriptParser::Assignment_resetContext* ExplorerScriptParser::AssignmentContext::assignment_reset() {
  return getRuleContext<ExplorerScriptParser::Assignment_resetContext>(0);
}

ExplorerScriptParser::Assignment_adv_logContext* ExplorerScriptParser::AssignmentContext::assignment_adv_log() {
  return getRuleContext<ExplorerScriptParser::Assignment_adv_logContext>(0);
}

ExplorerScriptParser::Assignment_dungeon_modeContext* ExplorerScriptParser::AssignmentContext::assignment_dungeon_mode() {
  return getRuleContext<ExplorerScriptParser::Assignment_dungeon_modeContext>(0);
}

ExplorerScriptParser::Assignment_scnContext* ExplorerScriptParser::AssignmentContext::assignment_scn() {
  return getRuleContext<ExplorerScriptParser::Assignment_scnContext>(0);
}


size_t ExplorerScriptParser::AssignmentContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment;
}

void ExplorerScriptParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void ExplorerScriptParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any ExplorerScriptParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::AssignmentContext* ExplorerScriptParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 68, ExplorerScriptParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(460);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(453);
      assignment_regular();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(454);
      assignment_clear();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(455);
      assignment_initial();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(456);
      assignment_reset();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(457);
      assignment_adv_log();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(458);
      assignment_dungeon_mode();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(459);
      assignment_scn();
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

//----------------- Assignment_regularContext ------------------------------------------------------------------

ExplorerScriptParser::Assignment_regularContext::Assignment_regularContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExplorerScriptParser::Integer_likeContext *> ExplorerScriptParser::Assignment_regularContext::integer_like() {
  return getRuleContexts<ExplorerScriptParser::Integer_likeContext>();
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Assignment_regularContext::integer_like(size_t i) {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(i);
}

ExplorerScriptParser::Assign_operatorContext* ExplorerScriptParser::Assignment_regularContext::assign_operator() {
  return getRuleContext<ExplorerScriptParser::Assign_operatorContext>(0);
}

ExplorerScriptParser::Value_ofContext* ExplorerScriptParser::Assignment_regularContext::value_of() {
  return getRuleContext<ExplorerScriptParser::Value_ofContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_regularContext::OPEN_BRACKET() {
  return getToken(ExplorerScriptParser::OPEN_BRACKET, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_regularContext::INTEGER() {
  return getToken(ExplorerScriptParser::INTEGER, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_regularContext::CLOSE_BRACKET() {
  return getToken(ExplorerScriptParser::CLOSE_BRACKET, 0);
}


size_t ExplorerScriptParser::Assignment_regularContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_regular;
}

void ExplorerScriptParser::Assignment_regularContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_regular(this);
}

void ExplorerScriptParser::Assignment_regularContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_regular(this);
}


std::any ExplorerScriptParser::Assignment_regularContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_regular(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_regularContext* ExplorerScriptParser::assignment_regular() {
  Assignment_regularContext *_localctx = _tracker.createInstance<Assignment_regularContext>(_ctx, getState());
  enterRule(_localctx, 70, ExplorerScriptParser::RuleAssignment_regular);
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
    setState(462);
    integer_like();
    setState(466);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::OPEN_BRACKET) {
      setState(463);
      match(ExplorerScriptParser::OPEN_BRACKET);
      setState(464);
      match(ExplorerScriptParser::INTEGER);
      setState(465);
      match(ExplorerScriptParser::CLOSE_BRACKET);
    }
    setState(468);
    assign_operator();
    setState(471);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::DECIMAL: {
        setState(469);
        integer_like();
        break;
      }

      case ExplorerScriptParser::VALUE: {
        setState(470);
        value_of();
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

//----------------- Assignment_clearContext ------------------------------------------------------------------

ExplorerScriptParser::Assignment_clearContext::Assignment_clearContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Assignment_clearContext::CLEAR() {
  return getToken(ExplorerScriptParser::CLEAR, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Assignment_clearContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}


size_t ExplorerScriptParser::Assignment_clearContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_clear;
}

void ExplorerScriptParser::Assignment_clearContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_clear(this);
}

void ExplorerScriptParser::Assignment_clearContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_clear(this);
}


std::any ExplorerScriptParser::Assignment_clearContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_clear(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_clearContext* ExplorerScriptParser::assignment_clear() {
  Assignment_clearContext *_localctx = _tracker.createInstance<Assignment_clearContext>(_ctx, getState());
  enterRule(_localctx, 72, ExplorerScriptParser::RuleAssignment_clear);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(473);
    match(ExplorerScriptParser::CLEAR);
    setState(474);
    integer_like();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_initialContext ------------------------------------------------------------------

ExplorerScriptParser::Assignment_initialContext::Assignment_initialContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Assignment_initialContext::INIT() {
  return getToken(ExplorerScriptParser::INIT, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Assignment_initialContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}


size_t ExplorerScriptParser::Assignment_initialContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_initial;
}

void ExplorerScriptParser::Assignment_initialContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_initial(this);
}

void ExplorerScriptParser::Assignment_initialContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_initial(this);
}


std::any ExplorerScriptParser::Assignment_initialContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_initial(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_initialContext* ExplorerScriptParser::assignment_initial() {
  Assignment_initialContext *_localctx = _tracker.createInstance<Assignment_initialContext>(_ctx, getState());
  enterRule(_localctx, 74, ExplorerScriptParser::RuleAssignment_initial);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(476);
    match(ExplorerScriptParser::INIT);
    setState(477);
    integer_like();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_resetContext ------------------------------------------------------------------

ExplorerScriptParser::Assignment_resetContext::Assignment_resetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Assignment_resetContext::RESET() {
  return getToken(ExplorerScriptParser::RESET, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_resetContext::DUNGEON_RESULT() {
  return getToken(ExplorerScriptParser::DUNGEON_RESULT, 0);
}

ExplorerScriptParser::Scn_varContext* ExplorerScriptParser::Assignment_resetContext::scn_var() {
  return getRuleContext<ExplorerScriptParser::Scn_varContext>(0);
}


size_t ExplorerScriptParser::Assignment_resetContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_reset;
}

void ExplorerScriptParser::Assignment_resetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_reset(this);
}

void ExplorerScriptParser::Assignment_resetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_reset(this);
}


std::any ExplorerScriptParser::Assignment_resetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_reset(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_resetContext* ExplorerScriptParser::assignment_reset() {
  Assignment_resetContext *_localctx = _tracker.createInstance<Assignment_resetContext>(_ctx, getState());
  enterRule(_localctx, 76, ExplorerScriptParser::RuleAssignment_reset);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    match(ExplorerScriptParser::RESET);
    setState(482);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::DUNGEON_RESULT: {
        setState(480);
        match(ExplorerScriptParser::DUNGEON_RESULT);
        break;
      }

      case ExplorerScriptParser::SCN: {
        setState(481);
        scn_var();
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

//----------------- Assignment_adv_logContext ------------------------------------------------------------------

ExplorerScriptParser::Assignment_adv_logContext::Assignment_adv_logContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Assignment_adv_logContext::ADVENTURE_LOG() {
  return getToken(ExplorerScriptParser::ADVENTURE_LOG, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_adv_logContext::ASSIGN() {
  return getToken(ExplorerScriptParser::ASSIGN, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Assignment_adv_logContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}


size_t ExplorerScriptParser::Assignment_adv_logContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_adv_log;
}

void ExplorerScriptParser::Assignment_adv_logContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_adv_log(this);
}

void ExplorerScriptParser::Assignment_adv_logContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_adv_log(this);
}


std::any ExplorerScriptParser::Assignment_adv_logContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_adv_log(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_adv_logContext* ExplorerScriptParser::assignment_adv_log() {
  Assignment_adv_logContext *_localctx = _tracker.createInstance<Assignment_adv_logContext>(_ctx, getState());
  enterRule(_localctx, 78, ExplorerScriptParser::RuleAssignment_adv_log);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(ExplorerScriptParser::ADVENTURE_LOG);
    setState(485);
    match(ExplorerScriptParser::ASSIGN);
    setState(486);
    integer_like();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_dungeon_modeContext ------------------------------------------------------------------

ExplorerScriptParser::Assignment_dungeon_modeContext::Assignment_dungeon_modeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Assignment_dungeon_modeContext::DUNGEON_MODE() {
  return getToken(ExplorerScriptParser::DUNGEON_MODE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_dungeon_modeContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

std::vector<ExplorerScriptParser::Integer_likeContext *> ExplorerScriptParser::Assignment_dungeon_modeContext::integer_like() {
  return getRuleContexts<ExplorerScriptParser::Integer_likeContext>();
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Assignment_dungeon_modeContext::integer_like(size_t i) {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(i);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_dungeon_modeContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_dungeon_modeContext::ASSIGN() {
  return getToken(ExplorerScriptParser::ASSIGN, 0);
}


size_t ExplorerScriptParser::Assignment_dungeon_modeContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_dungeon_mode;
}

void ExplorerScriptParser::Assignment_dungeon_modeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_dungeon_mode(this);
}

void ExplorerScriptParser::Assignment_dungeon_modeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_dungeon_mode(this);
}


std::any ExplorerScriptParser::Assignment_dungeon_modeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_dungeon_mode(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_dungeon_modeContext* ExplorerScriptParser::assignment_dungeon_mode() {
  Assignment_dungeon_modeContext *_localctx = _tracker.createInstance<Assignment_dungeon_modeContext>(_ctx, getState());
  enterRule(_localctx, 80, ExplorerScriptParser::RuleAssignment_dungeon_mode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(488);
    match(ExplorerScriptParser::DUNGEON_MODE);
    setState(489);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(490);
    integer_like();
    setState(491);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(492);
    match(ExplorerScriptParser::ASSIGN);
    setState(493);
    integer_like();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignment_scnContext ------------------------------------------------------------------

ExplorerScriptParser::Assignment_scnContext::Assignment_scnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Assignment_scnContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_scnContext::ASSIGN() {
  return getToken(ExplorerScriptParser::ASSIGN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_scnContext::SCN() {
  return getToken(ExplorerScriptParser::SCN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_scnContext::OPEN_BRACKET() {
  return getToken(ExplorerScriptParser::OPEN_BRACKET, 0);
}

std::vector<tree::TerminalNode *> ExplorerScriptParser::Assignment_scnContext::INTEGER() {
  return getTokens(ExplorerScriptParser::INTEGER);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_scnContext::INTEGER(size_t i) {
  return getToken(ExplorerScriptParser::INTEGER, i);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_scnContext::COMMA() {
  return getToken(ExplorerScriptParser::COMMA, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assignment_scnContext::CLOSE_BRACKET() {
  return getToken(ExplorerScriptParser::CLOSE_BRACKET, 0);
}


size_t ExplorerScriptParser::Assignment_scnContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_scn;
}

void ExplorerScriptParser::Assignment_scnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment_scn(this);
}

void ExplorerScriptParser::Assignment_scnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment_scn(this);
}


std::any ExplorerScriptParser::Assignment_scnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_scn(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_scnContext* ExplorerScriptParser::assignment_scn() {
  Assignment_scnContext *_localctx = _tracker.createInstance<Assignment_scnContext>(_ctx, getState());
  enterRule(_localctx, 82, ExplorerScriptParser::RuleAssignment_scn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(495);
    integer_like();
    setState(496);
    match(ExplorerScriptParser::ASSIGN);
    setState(497);
    match(ExplorerScriptParser::SCN);
    setState(498);
    match(ExplorerScriptParser::OPEN_BRACKET);
    setState(499);
    match(ExplorerScriptParser::INTEGER);
    setState(500);
    match(ExplorerScriptParser::COMMA);
    setState(501);
    match(ExplorerScriptParser::INTEGER);
    setState(502);
    match(ExplorerScriptParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_ofContext ------------------------------------------------------------------

ExplorerScriptParser::Value_ofContext::Value_ofContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Value_ofContext::VALUE() {
  return getToken(ExplorerScriptParser::VALUE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Value_ofContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Value_ofContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Value_ofContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Value_ofContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleValue_of;
}

void ExplorerScriptParser::Value_ofContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_of(this);
}

void ExplorerScriptParser::Value_ofContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_of(this);
}


std::any ExplorerScriptParser::Value_ofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitValue_of(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Value_ofContext* ExplorerScriptParser::value_of() {
  Value_ofContext *_localctx = _tracker.createInstance<Value_ofContext>(_ctx, getState());
  enterRule(_localctx, 84, ExplorerScriptParser::RuleValue_of);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(504);
    match(ExplorerScriptParser::VALUE);
    setState(505);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(506);
    integer_like();
    setState(507);
    match(ExplorerScriptParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scn_varContext ------------------------------------------------------------------

ExplorerScriptParser::Scn_varContext::Scn_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Scn_varContext::SCN() {
  return getToken(ExplorerScriptParser::SCN, 0);
}

tree::TerminalNode* ExplorerScriptParser::Scn_varContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Scn_varContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Scn_varContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Scn_varContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleScn_var;
}

void ExplorerScriptParser::Scn_varContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScn_var(this);
}

void ExplorerScriptParser::Scn_varContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScn_var(this);
}


std::any ExplorerScriptParser::Scn_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitScn_var(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Scn_varContext* ExplorerScriptParser::scn_var() {
  Scn_varContext *_localctx = _tracker.createInstance<Scn_varContext>(_ctx, getState());
  enterRule(_localctx, 86, ExplorerScriptParser::RuleScn_var);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(509);
    match(ExplorerScriptParser::SCN);
    setState(510);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(511);
    integer_like();
    setState(512);
    match(ExplorerScriptParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_operatorContext ------------------------------------------------------------------

ExplorerScriptParser::Conditional_operatorContext::Conditional_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OP_FALSE() {
  return getToken(ExplorerScriptParser::OP_FALSE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OP_TRUE() {
  return getToken(ExplorerScriptParser::OP_TRUE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OP_EQ() {
  return getToken(ExplorerScriptParser::OP_EQ, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OP_GE() {
  return getToken(ExplorerScriptParser::OP_GE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OP_LE() {
  return getToken(ExplorerScriptParser::OP_LE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OPEN_SHARP() {
  return getToken(ExplorerScriptParser::OPEN_SHARP, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::CLOSE_SHARP() {
  return getToken(ExplorerScriptParser::CLOSE_SHARP, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OP_NEQ() {
  return getToken(ExplorerScriptParser::OP_NEQ, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OP_AND() {
  return getToken(ExplorerScriptParser::OP_AND, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OP_XOR() {
  return getToken(ExplorerScriptParser::OP_XOR, 0);
}

tree::TerminalNode* ExplorerScriptParser::Conditional_operatorContext::OP_BICH() {
  return getToken(ExplorerScriptParser::OP_BICH, 0);
}


size_t ExplorerScriptParser::Conditional_operatorContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleConditional_operator;
}

void ExplorerScriptParser::Conditional_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional_operator(this);
}

void ExplorerScriptParser::Conditional_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional_operator(this);
}


std::any ExplorerScriptParser::Conditional_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitConditional_operator(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Conditional_operatorContext* ExplorerScriptParser::conditional_operator() {
  Conditional_operatorContext *_localctx = _tracker.createInstance<Conditional_operatorContext>(_ctx, getState());
  enterRule(_localctx, 88, ExplorerScriptParser::RuleConditional_operator);
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
    setState(514);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16364) != 0))) {
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

//----------------- Assign_operatorContext ------------------------------------------------------------------

ExplorerScriptParser::Assign_operatorContext::Assign_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Assign_operatorContext::OP_MINUS() {
  return getToken(ExplorerScriptParser::OP_MINUS, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assign_operatorContext::OP_PLUS() {
  return getToken(ExplorerScriptParser::OP_PLUS, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assign_operatorContext::OP_MULTIPLY() {
  return getToken(ExplorerScriptParser::OP_MULTIPLY, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assign_operatorContext::OP_DIVIDE() {
  return getToken(ExplorerScriptParser::OP_DIVIDE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Assign_operatorContext::ASSIGN() {
  return getToken(ExplorerScriptParser::ASSIGN, 0);
}


size_t ExplorerScriptParser::Assign_operatorContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssign_operator;
}

void ExplorerScriptParser::Assign_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign_operator(this);
}

void ExplorerScriptParser::Assign_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign_operator(this);
}


std::any ExplorerScriptParser::Assign_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssign_operator(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assign_operatorContext* ExplorerScriptParser::assign_operator() {
  Assign_operatorContext *_localctx = _tracker.createInstance<Assign_operatorContext>(_ctx, getState());
  enterRule(_localctx, 90, ExplorerScriptParser::RuleAssign_operator);
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
    setState(516);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 245776) != 0))) {
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

//----------------- FuncdefContext ------------------------------------------------------------------

ExplorerScriptParser::FuncdefContext::FuncdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Coro_defContext* ExplorerScriptParser::FuncdefContext::coro_def() {
  return getRuleContext<ExplorerScriptParser::Coro_defContext>(0);
}

ExplorerScriptParser::Simple_defContext* ExplorerScriptParser::FuncdefContext::simple_def() {
  return getRuleContext<ExplorerScriptParser::Simple_defContext>(0);
}

ExplorerScriptParser::For_target_defContext* ExplorerScriptParser::FuncdefContext::for_target_def() {
  return getRuleContext<ExplorerScriptParser::For_target_defContext>(0);
}


size_t ExplorerScriptParser::FuncdefContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleFuncdef;
}

void ExplorerScriptParser::FuncdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncdef(this);
}

void ExplorerScriptParser::FuncdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncdef(this);
}


std::any ExplorerScriptParser::FuncdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFuncdef(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::FuncdefContext* ExplorerScriptParser::funcdef() {
  FuncdefContext *_localctx = _tracker.createInstance<FuncdefContext>(_ctx, getState());
  enterRule(_localctx, 92, ExplorerScriptParser::RuleFuncdef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(521);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(518);
      coro_def();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(519);
      simple_def();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(520);
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

ExplorerScriptParser::Simple_defContext::Simple_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Simple_defContext::DEF() {
  return getToken(ExplorerScriptParser::DEF, 0);
}

tree::TerminalNode* ExplorerScriptParser::Simple_defContext::INTEGER() {
  return getToken(ExplorerScriptParser::INTEGER, 0);
}

ExplorerScriptParser::Func_suiteContext* ExplorerScriptParser::Simple_defContext::func_suite() {
  return getRuleContext<ExplorerScriptParser::Func_suiteContext>(0);
}


size_t ExplorerScriptParser::Simple_defContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSimple_def;
}

void ExplorerScriptParser::Simple_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_def(this);
}

void ExplorerScriptParser::Simple_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_def(this);
}


std::any ExplorerScriptParser::Simple_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSimple_def(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Simple_defContext* ExplorerScriptParser::simple_def() {
  Simple_defContext *_localctx = _tracker.createInstance<Simple_defContext>(_ctx, getState());
  enterRule(_localctx, 94, ExplorerScriptParser::RuleSimple_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(523);
    match(ExplorerScriptParser::DEF);
    setState(524);
    match(ExplorerScriptParser::INTEGER);
    setState(525);
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

ExplorerScriptParser::Coro_defContext::Coro_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Coro_defContext::CORO() {
  return getToken(ExplorerScriptParser::CORO, 0);
}

tree::TerminalNode* ExplorerScriptParser::Coro_defContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

ExplorerScriptParser::Func_suiteContext* ExplorerScriptParser::Coro_defContext::func_suite() {
  return getRuleContext<ExplorerScriptParser::Func_suiteContext>(0);
}


size_t ExplorerScriptParser::Coro_defContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCoro_def;
}

void ExplorerScriptParser::Coro_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCoro_def(this);
}

void ExplorerScriptParser::Coro_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCoro_def(this);
}


std::any ExplorerScriptParser::Coro_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCoro_def(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Coro_defContext* ExplorerScriptParser::coro_def() {
  Coro_defContext *_localctx = _tracker.createInstance<Coro_defContext>(_ctx, getState());
  enterRule(_localctx, 96, ExplorerScriptParser::RuleCoro_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(527);
    match(ExplorerScriptParser::CORO);
    setState(528);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(529);
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

ExplorerScriptParser::For_target_defContext::For_target_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::For_target_defContext::DEF() {
  return getToken(ExplorerScriptParser::DEF, 0);
}

tree::TerminalNode* ExplorerScriptParser::For_target_defContext::INTEGER() {
  return getToken(ExplorerScriptParser::INTEGER, 0);
}

ExplorerScriptParser::For_target_def_targetContext* ExplorerScriptParser::For_target_defContext::for_target_def_target() {
  return getRuleContext<ExplorerScriptParser::For_target_def_targetContext>(0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::For_target_defContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

ExplorerScriptParser::Func_suiteContext* ExplorerScriptParser::For_target_defContext::func_suite() {
  return getRuleContext<ExplorerScriptParser::Func_suiteContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::For_target_defContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::For_target_defContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::For_target_defContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleFor_target_def;
}

void ExplorerScriptParser::For_target_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_target_def(this);
}

void ExplorerScriptParser::For_target_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_target_def(this);
}


std::any ExplorerScriptParser::For_target_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFor_target_def(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::For_target_defContext* ExplorerScriptParser::for_target_def() {
  For_target_defContext *_localctx = _tracker.createInstance<For_target_defContext>(_ctx, getState());
  enterRule(_localctx, 98, ExplorerScriptParser::RuleFor_target_def);
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
    setState(531);
    match(ExplorerScriptParser::DEF);
    setState(532);
    match(ExplorerScriptParser::INTEGER);
    setState(533);
    for_target_def_target();
    setState(535);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::OPEN_PAREN) {
      setState(534);
      match(ExplorerScriptParser::OPEN_PAREN);
    }
    setState(537);
    integer_like();
    setState(539);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::CLOSE_PAREN) {
      setState(538);
      match(ExplorerScriptParser::CLOSE_PAREN);
    }
    setState(541);
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

ExplorerScriptParser::Integer_likeContext::Integer_likeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Integer_likeContext::DECIMAL() {
  return getToken(ExplorerScriptParser::DECIMAL, 0);
}

tree::TerminalNode* ExplorerScriptParser::Integer_likeContext::INTEGER() {
  return getToken(ExplorerScriptParser::INTEGER, 0);
}

tree::TerminalNode* ExplorerScriptParser::Integer_likeContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExplorerScriptParser::Integer_likeContext::VARIABLE() {
  return getToken(ExplorerScriptParser::VARIABLE, 0);
}


size_t ExplorerScriptParser::Integer_likeContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleInteger_like;
}

void ExplorerScriptParser::Integer_likeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger_like(this);
}

void ExplorerScriptParser::Integer_likeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger_like(this);
}


std::any ExplorerScriptParser::Integer_likeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitInteger_like(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::integer_like() {
  Integer_likeContext *_localctx = _tracker.createInstance<Integer_likeContext>(_ctx, getState());
  enterRule(_localctx, 100, ExplorerScriptParser::RuleInteger_like);
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
    setState(543);
    _la = _input->LA(1);
    if (!(((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & 131083) != 0))) {
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

//----------------- OperationContext ------------------------------------------------------------------

ExplorerScriptParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::OperationContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExplorerScriptParser::OperationContext::OPEN_PAREN() {
  return getToken(ExplorerScriptParser::OPEN_PAREN, 0);
}

tree::TerminalNode* ExplorerScriptParser::OperationContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}

ExplorerScriptParser::Inline_ctxContext* ExplorerScriptParser::OperationContext::inline_ctx() {
  return getRuleContext<ExplorerScriptParser::Inline_ctxContext>(0);
}

ExplorerScriptParser::ArglistContext* ExplorerScriptParser::OperationContext::arglist() {
  return getRuleContext<ExplorerScriptParser::ArglistContext>(0);
}


size_t ExplorerScriptParser::OperationContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleOperation;
}

void ExplorerScriptParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void ExplorerScriptParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}


std::any ExplorerScriptParser::OperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitOperation(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::OperationContext* ExplorerScriptParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 102, ExplorerScriptParser::RuleOperation);
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
    setState(545);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(547);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::OPEN_SHARP) {
      setState(546);
      inline_ctx();
    }
    setState(549);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(551);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 58) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 58)) & 671135747) != 0)) {
      setState(550);
      arglist();
    }
    setState(553);
    match(ExplorerScriptParser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Inline_ctxContext ------------------------------------------------------------------

ExplorerScriptParser::Inline_ctxContext::Inline_ctxContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Inline_ctxContext::OPEN_SHARP() {
  return getToken(ExplorerScriptParser::OPEN_SHARP, 0);
}

ExplorerScriptParser::Ctx_headerContext* ExplorerScriptParser::Inline_ctxContext::ctx_header() {
  return getRuleContext<ExplorerScriptParser::Ctx_headerContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Inline_ctxContext::CLOSE_SHARP() {
  return getToken(ExplorerScriptParser::CLOSE_SHARP, 0);
}


size_t ExplorerScriptParser::Inline_ctxContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleInline_ctx;
}

void ExplorerScriptParser::Inline_ctxContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInline_ctx(this);
}

void ExplorerScriptParser::Inline_ctxContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInline_ctx(this);
}


std::any ExplorerScriptParser::Inline_ctxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitInline_ctx(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Inline_ctxContext* ExplorerScriptParser::inline_ctx() {
  Inline_ctxContext *_localctx = _tracker.createInstance<Inline_ctxContext>(_ctx, getState());
  enterRule(_localctx, 104, ExplorerScriptParser::RuleInline_ctx);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555);
    match(ExplorerScriptParser::OPEN_SHARP);
    setState(556);
    ctx_header();
    setState(557);
    match(ExplorerScriptParser::CLOSE_SHARP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_suiteContext ------------------------------------------------------------------

ExplorerScriptParser::Func_suiteContext::Func_suiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Func_suiteContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

tree::TerminalNode* ExplorerScriptParser::Func_suiteContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

ExplorerScriptParser::Func_aliasContext* ExplorerScriptParser::Func_suiteContext::func_alias() {
  return getRuleContext<ExplorerScriptParser::Func_aliasContext>(0);
}

std::vector<ExplorerScriptParser::StmtContext *> ExplorerScriptParser::Func_suiteContext::stmt() {
  return getRuleContexts<ExplorerScriptParser::StmtContext>();
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::Func_suiteContext::stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::StmtContext>(i);
}


size_t ExplorerScriptParser::Func_suiteContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleFunc_suite;
}

void ExplorerScriptParser::Func_suiteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_suite(this);
}

void ExplorerScriptParser::Func_suiteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_suite(this);
}


std::any ExplorerScriptParser::Func_suiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFunc_suite(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Func_suiteContext* ExplorerScriptParser::func_suite() {
  Func_suiteContext *_localctx = _tracker.createInstance<Func_suiteContext>(_ctx, getState());
  enterRule(_localctx, 106, ExplorerScriptParser::RuleFunc_suite);
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
    setState(559);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(566);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::JUMP:
      case ExplorerScriptParser::CALL:
      case ExplorerScriptParser::IF:
      case ExplorerScriptParser::FOREVER:
      case ExplorerScriptParser::WITH:
      case ExplorerScriptParser::SWITCH:
      case ExplorerScriptParser::RETURN:
      case ExplorerScriptParser::END:
      case ExplorerScriptParser::HOLD:
      case ExplorerScriptParser::CONTINUE:
      case ExplorerScriptParser::BREAK:
      case ExplorerScriptParser::BREAK_LOOP:
      case ExplorerScriptParser::DUNGEON_MODE:
      case ExplorerScriptParser::CLEAR:
      case ExplorerScriptParser::RESET:
      case ExplorerScriptParser::INIT:
      case ExplorerScriptParser::ADVENTURE_LOG:
      case ExplorerScriptParser::MESSAGE_SWITCH_TALK:
      case ExplorerScriptParser::MESSAGE_SWITCH_MONOLOGUE:
      case ExplorerScriptParser::WHILE:
      case ExplorerScriptParser::FOR:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::MACRO_CALL:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::AT:
      case ExplorerScriptParser::PARAGRAPH:
      case ExplorerScriptParser::DECIMAL: {
        setState(561); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(560);
          stmt();
          setState(563); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 68543623480737792) != 0) || ((((_la - 67) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 67)) & 1245305) != 0));
        break;
      }

      case ExplorerScriptParser::ALIAS: {
        setState(565);
        func_alias();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(568);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_aliasContext ------------------------------------------------------------------

ExplorerScriptParser::Func_aliasContext::Func_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Func_aliasContext::ALIAS() {
  return getToken(ExplorerScriptParser::ALIAS, 0);
}

tree::TerminalNode* ExplorerScriptParser::Func_aliasContext::PREVIOUS() {
  return getToken(ExplorerScriptParser::PREVIOUS, 0);
}


size_t ExplorerScriptParser::Func_aliasContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleFunc_alias;
}

void ExplorerScriptParser::Func_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_alias(this);
}

void ExplorerScriptParser::Func_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_alias(this);
}


std::any ExplorerScriptParser::Func_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFunc_alias(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Func_aliasContext* ExplorerScriptParser::func_alias() {
  Func_aliasContext *_localctx = _tracker.createInstance<Func_aliasContext>(_ctx, getState());
  enterRule(_localctx, 108, ExplorerScriptParser::RuleFunc_alias);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(570);
    match(ExplorerScriptParser::ALIAS);
    setState(571);
    match(ExplorerScriptParser::PREVIOUS);
    setState(572);
    match(ExplorerScriptParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

ExplorerScriptParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExplorerScriptParser::Pos_argumentContext *> ExplorerScriptParser::ArglistContext::pos_argument() {
  return getRuleContexts<ExplorerScriptParser::Pos_argumentContext>();
}

ExplorerScriptParser::Pos_argumentContext* ExplorerScriptParser::ArglistContext::pos_argument(size_t i) {
  return getRuleContext<ExplorerScriptParser::Pos_argumentContext>(i);
}

std::vector<tree::TerminalNode *> ExplorerScriptParser::ArglistContext::COMMA() {
  return getTokens(ExplorerScriptParser::COMMA);
}

tree::TerminalNode* ExplorerScriptParser::ArglistContext::COMMA(size_t i) {
  return getToken(ExplorerScriptParser::COMMA, i);
}


size_t ExplorerScriptParser::ArglistContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleArglist;
}

void ExplorerScriptParser::ArglistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArglist(this);
}

void ExplorerScriptParser::ArglistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArglist(this);
}


std::any ExplorerScriptParser::ArglistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitArglist(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::ArglistContext* ExplorerScriptParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 110, ExplorerScriptParser::RuleArglist);
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
    setState(574);
    pos_argument();
    setState(579);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(575);
        match(ExplorerScriptParser::COMMA);
        setState(576);
        pos_argument(); 
      }
      setState(581);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
    setState(583);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::COMMA) {
      setState(582);
      match(ExplorerScriptParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pos_argumentContext ------------------------------------------------------------------

ExplorerScriptParser::Pos_argumentContext::Pos_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Pos_argumentContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}

ExplorerScriptParser::StringContext* ExplorerScriptParser::Pos_argumentContext::string() {
  return getRuleContext<ExplorerScriptParser::StringContext>(0);
}

ExplorerScriptParser::Position_markerContext* ExplorerScriptParser::Pos_argumentContext::position_marker() {
  return getRuleContext<ExplorerScriptParser::Position_markerContext>(0);
}


size_t ExplorerScriptParser::Pos_argumentContext::getRuleIndex() const {
  return ExplorerScriptParser::RulePos_argument;
}

void ExplorerScriptParser::Pos_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPos_argument(this);
}

void ExplorerScriptParser::Pos_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPos_argument(this);
}


std::any ExplorerScriptParser::Pos_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitPos_argument(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Pos_argumentContext* ExplorerScriptParser::pos_argument() {
  Pos_argumentContext *_localctx = _tracker.createInstance<Pos_argumentContext>(_ctx, getState());
  enterRule(_localctx, 112, ExplorerScriptParser::RulePos_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(588);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::DECIMAL: {
        enterOuterAlt(_localctx, 1);
        setState(585);
        integer_like();
        break;
      }

      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(586);
        string();
        break;
      }

      case ExplorerScriptParser::POSITION: {
        enterOuterAlt(_localctx, 3);
        setState(587);
        position_marker();
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

//----------------- Position_markerContext ------------------------------------------------------------------

ExplorerScriptParser::Position_markerContext::Position_markerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Position_markerContext::POSITION() {
  return getToken(ExplorerScriptParser::POSITION, 0);
}

tree::TerminalNode* ExplorerScriptParser::Position_markerContext::OPEN_SHARP() {
  return getToken(ExplorerScriptParser::OPEN_SHARP, 0);
}

tree::TerminalNode* ExplorerScriptParser::Position_markerContext::STRING_LITERAL() {
  return getToken(ExplorerScriptParser::STRING_LITERAL, 0);
}

std::vector<tree::TerminalNode *> ExplorerScriptParser::Position_markerContext::COMMA() {
  return getTokens(ExplorerScriptParser::COMMA);
}

tree::TerminalNode* ExplorerScriptParser::Position_markerContext::COMMA(size_t i) {
  return getToken(ExplorerScriptParser::COMMA, i);
}

std::vector<ExplorerScriptParser::Position_marker_argContext *> ExplorerScriptParser::Position_markerContext::position_marker_arg() {
  return getRuleContexts<ExplorerScriptParser::Position_marker_argContext>();
}

ExplorerScriptParser::Position_marker_argContext* ExplorerScriptParser::Position_markerContext::position_marker_arg(size_t i) {
  return getRuleContext<ExplorerScriptParser::Position_marker_argContext>(i);
}

tree::TerminalNode* ExplorerScriptParser::Position_markerContext::CLOSE_SHARP() {
  return getToken(ExplorerScriptParser::CLOSE_SHARP, 0);
}


size_t ExplorerScriptParser::Position_markerContext::getRuleIndex() const {
  return ExplorerScriptParser::RulePosition_marker;
}

void ExplorerScriptParser::Position_markerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPosition_marker(this);
}

void ExplorerScriptParser::Position_markerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPosition_marker(this);
}


std::any ExplorerScriptParser::Position_markerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitPosition_marker(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Position_markerContext* ExplorerScriptParser::position_marker() {
  Position_markerContext *_localctx = _tracker.createInstance<Position_markerContext>(_ctx, getState());
  enterRule(_localctx, 114, ExplorerScriptParser::RulePosition_marker);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(590);
    match(ExplorerScriptParser::POSITION);
    setState(591);
    match(ExplorerScriptParser::OPEN_SHARP);
    setState(592);
    match(ExplorerScriptParser::STRING_LITERAL);
    setState(593);
    match(ExplorerScriptParser::COMMA);
    setState(594);
    position_marker_arg();
    setState(595);
    match(ExplorerScriptParser::COMMA);
    setState(596);
    position_marker_arg();
    setState(597);
    match(ExplorerScriptParser::CLOSE_SHARP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Position_marker_argContext ------------------------------------------------------------------

ExplorerScriptParser::Position_marker_argContext::Position_marker_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Position_marker_argContext::INTEGER() {
  return getToken(ExplorerScriptParser::INTEGER, 0);
}

tree::TerminalNode* ExplorerScriptParser::Position_marker_argContext::DECIMAL() {
  return getToken(ExplorerScriptParser::DECIMAL, 0);
}


size_t ExplorerScriptParser::Position_marker_argContext::getRuleIndex() const {
  return ExplorerScriptParser::RulePosition_marker_arg;
}

void ExplorerScriptParser::Position_marker_argContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPosition_marker_arg(this);
}

void ExplorerScriptParser::Position_marker_argContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPosition_marker_arg(this);
}


std::any ExplorerScriptParser::Position_marker_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitPosition_marker_arg(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Position_marker_argContext* ExplorerScriptParser::position_marker_arg() {
  Position_marker_argContext *_localctx = _tracker.createInstance<Position_marker_argContext>(_ctx, getState());
  enterRule(_localctx, 116, ExplorerScriptParser::RulePosition_marker_arg);
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
    setState(599);
    _la = _input->LA(1);
    if (!(_la == ExplorerScriptParser::INTEGER

    || _la == ExplorerScriptParser::DECIMAL)) {
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

ExplorerScriptParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::LabelContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExplorerScriptParser::LabelContext::PARAGRAPH() {
  return getToken(ExplorerScriptParser::PARAGRAPH, 0);
}

tree::TerminalNode* ExplorerScriptParser::LabelContext::AT() {
  return getToken(ExplorerScriptParser::AT, 0);
}


size_t ExplorerScriptParser::LabelContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleLabel;
}

void ExplorerScriptParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void ExplorerScriptParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
}


std::any ExplorerScriptParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::LabelContext* ExplorerScriptParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 118, ExplorerScriptParser::RuleLabel);
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
    setState(601);
    _la = _input->LA(1);
    if (!(_la == ExplorerScriptParser::AT

    || _la == ExplorerScriptParser::PARAGRAPH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(602);
    match(ExplorerScriptParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

ExplorerScriptParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::String_valueContext* ExplorerScriptParser::StringContext::string_value() {
  return getRuleContext<ExplorerScriptParser::String_valueContext>(0);
}

ExplorerScriptParser::Lang_stringContext* ExplorerScriptParser::StringContext::lang_string() {
  return getRuleContext<ExplorerScriptParser::Lang_stringContext>(0);
}


size_t ExplorerScriptParser::StringContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleString;
}

void ExplorerScriptParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void ExplorerScriptParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


std::any ExplorerScriptParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::StringContext* ExplorerScriptParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 120, ExplorerScriptParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(606);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(604);
        string_value();
        break;
      }

      case ExplorerScriptParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(605);
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

ExplorerScriptParser::Lang_stringContext::Lang_stringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Lang_stringContext::OPEN_BRACE() {
  return getToken(ExplorerScriptParser::OPEN_BRACE, 0);
}

std::vector<ExplorerScriptParser::Lang_string_argumentContext *> ExplorerScriptParser::Lang_stringContext::lang_string_argument() {
  return getRuleContexts<ExplorerScriptParser::Lang_string_argumentContext>();
}

ExplorerScriptParser::Lang_string_argumentContext* ExplorerScriptParser::Lang_stringContext::lang_string_argument(size_t i) {
  return getRuleContext<ExplorerScriptParser::Lang_string_argumentContext>(i);
}

tree::TerminalNode* ExplorerScriptParser::Lang_stringContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

std::vector<tree::TerminalNode *> ExplorerScriptParser::Lang_stringContext::COMMA() {
  return getTokens(ExplorerScriptParser::COMMA);
}

tree::TerminalNode* ExplorerScriptParser::Lang_stringContext::COMMA(size_t i) {
  return getToken(ExplorerScriptParser::COMMA, i);
}


size_t ExplorerScriptParser::Lang_stringContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleLang_string;
}

void ExplorerScriptParser::Lang_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLang_string(this);
}

void ExplorerScriptParser::Lang_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLang_string(this);
}


std::any ExplorerScriptParser::Lang_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitLang_string(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Lang_stringContext* ExplorerScriptParser::lang_string() {
  Lang_stringContext *_localctx = _tracker.createInstance<Lang_stringContext>(_ctx, getState());
  enterRule(_localctx, 122, ExplorerScriptParser::RuleLang_string);
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
    setState(608);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(609);
    lang_string_argument();
    setState(614);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(610);
        match(ExplorerScriptParser::COMMA);
        setState(611);
        lang_string_argument(); 
      }
      setState(616);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
    }
    setState(618);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::COMMA) {
      setState(617);
      match(ExplorerScriptParser::COMMA);
    }
    setState(620);
    match(ExplorerScriptParser::CLOSE_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Lang_string_argumentContext ------------------------------------------------------------------

ExplorerScriptParser::Lang_string_argumentContext::Lang_string_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Lang_string_argumentContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExplorerScriptParser::Lang_string_argumentContext::ASSIGN() {
  return getToken(ExplorerScriptParser::ASSIGN, 0);
}

ExplorerScriptParser::String_valueContext* ExplorerScriptParser::Lang_string_argumentContext::string_value() {
  return getRuleContext<ExplorerScriptParser::String_valueContext>(0);
}


size_t ExplorerScriptParser::Lang_string_argumentContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleLang_string_argument;
}

void ExplorerScriptParser::Lang_string_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLang_string_argument(this);
}

void ExplorerScriptParser::Lang_string_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLang_string_argument(this);
}


std::any ExplorerScriptParser::Lang_string_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitLang_string_argument(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Lang_string_argumentContext* ExplorerScriptParser::lang_string_argument() {
  Lang_string_argumentContext *_localctx = _tracker.createInstance<Lang_string_argumentContext>(_ctx, getState());
  enterRule(_localctx, 124, ExplorerScriptParser::RuleLang_string_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(622);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(623);
    match(ExplorerScriptParser::ASSIGN);
    setState(624);
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

ExplorerScriptParser::String_valueContext::String_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::String_valueContext::MULTILINE_STRING_LITERAL() {
  return getToken(ExplorerScriptParser::MULTILINE_STRING_LITERAL, 0);
}

tree::TerminalNode* ExplorerScriptParser::String_valueContext::STRING_LITERAL() {
  return getToken(ExplorerScriptParser::STRING_LITERAL, 0);
}


size_t ExplorerScriptParser::String_valueContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleString_value;
}

void ExplorerScriptParser::String_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString_value(this);
}

void ExplorerScriptParser::String_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString_value(this);
}


std::any ExplorerScriptParser::String_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitString_value(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::String_valueContext* ExplorerScriptParser::string_value() {
  String_valueContext *_localctx = _tracker.createInstance<String_valueContext>(_ctx, getState());
  enterRule(_localctx, 126, ExplorerScriptParser::RuleString_value);
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
    setState(626);
    _la = _input->LA(1);
    if (!(_la == ExplorerScriptParser::STRING_LITERAL

    || _la == ExplorerScriptParser::MULTILINE_STRING_LITERAL)) {
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

ExplorerScriptParser::Ctx_headerContext::Ctx_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Ctx_headerContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

ExplorerScriptParser::Integer_likeContext* ExplorerScriptParser::Ctx_headerContext::integer_like() {
  return getRuleContext<ExplorerScriptParser::Integer_likeContext>(0);
}


size_t ExplorerScriptParser::Ctx_headerContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCtx_header;
}

void ExplorerScriptParser::Ctx_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCtx_header(this);
}

void ExplorerScriptParser::Ctx_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCtx_header(this);
}


std::any ExplorerScriptParser::Ctx_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCtx_header(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Ctx_headerContext* ExplorerScriptParser::ctx_header() {
  Ctx_headerContext *_localctx = _tracker.createInstance<Ctx_headerContext>(_ctx, getState());
  enterRule(_localctx, 128, ExplorerScriptParser::RuleCtx_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(628);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(629);
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

ExplorerScriptParser::For_target_def_targetContext::For_target_def_targetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::For_target_def_targetContext::FOR() {
  return getToken(ExplorerScriptParser::FOR, 0);
}

tree::TerminalNode* ExplorerScriptParser::For_target_def_targetContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExplorerScriptParser::For_target_def_targetContext::FOR_TARGET() {
  return getToken(ExplorerScriptParser::FOR_TARGET, 0);
}


size_t ExplorerScriptParser::For_target_def_targetContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleFor_target_def_target;
}

void ExplorerScriptParser::For_target_def_targetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_target_def_target(this);
}

void ExplorerScriptParser::For_target_def_targetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExplorerScriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_target_def_target(this);
}


std::any ExplorerScriptParser::For_target_def_targetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFor_target_def_target(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::For_target_def_targetContext* ExplorerScriptParser::for_target_def_target() {
  For_target_def_targetContext *_localctx = _tracker.createInstance<For_target_def_targetContext>(_ctx, getState());
  enterRule(_localctx, 130, ExplorerScriptParser::RuleFor_target_def_target);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(634);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::FOR: {
        enterOuterAlt(_localctx, 1);
        setState(631);
        match(ExplorerScriptParser::FOR);
        setState(632);
        match(ExplorerScriptParser::IDENTIFIER);
        break;
      }

      case ExplorerScriptParser::FOR_TARGET: {
        enterOuterAlt(_localctx, 2);
        setState(633);
        match(ExplorerScriptParser::FOR_TARGET);
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

void ExplorerScriptParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  explorerscriptParserInitialize();
#else
  ::antlr4::internal::call_once(explorerscriptParserOnceFlag, explorerscriptParserInitialize);
#endif
}
