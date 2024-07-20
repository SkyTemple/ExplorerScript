
// Generated from ExplorerScript.g4 by ANTLR 4.13.0


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
      "start", "import_stmt", "constant_assign", "macrodef", "stmt", "simple_stmt", 
      "cntrl_stmt", "jump", "call", "macro_call", "ctx_block", "if_block", 
      "elseif_block", "else_block", "if_header", "if_h_negatable", "if_h_op", 
      "if_h_bit", "if_h_scn", "switch_block", "message_switch_block", "single_case_block", 
      "default", "switch_header", "switch_h_scn", "switch_h_random", "switch_h_dungeon_mode", 
      "switch_h_sector", "case_header", "case_h_menu", "case_h_menu2", "case_h_op", 
      "forever_block", "for_block", "while_block", "assignment", "assignment_regular", 
      "assignment_clear", "assignment_initial", "assignment_reset", "assignment_adv_log", 
      "assignment_dungeon_mode", "assignment_scn", "value_of", "scn_var", 
      "conditional_operator", "assign_operator", "funcdef", "simple_def", 
      "coro_def", "for_target_def", "primitive", "operation", "inline_ctx", 
      "func_suite", "func_alias", "arglist", "pos_argument", "position_marker", 
      "position_marker_arg", "label", "string", "lang_string", "lang_string_argument", 
      "string_value", "ctx_header", "for_target_def_target"
    },
    std::vector<std::string>{
      "", "';'", "'FALSE'", "'TRUE'", "'='", "'<'", "'>'", "'=='", "'<='", 
      "'>='", "'!='", "'&'", "'^'", "'&<<'", "'-='", "'+='", "'*='", "'/='", 
      "'||'", "'not'", "'jump'", "'call'", "'import'", "'const'", "'macro'", 
      "'if'", "'elseif'", "'else'", "'forever'", "'with'", "'switch'", "'return'", 
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
      "CALL", "IMPORT", "CONST", "MACRO", "IF", "ELSEIF", "ELSE", "FOREVER", 
      "WITH", "SWITCH", "RETURN", "END", "HOLD", "CONTINUE", "BREAK", "BREAK_LOOP", 
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
  	4,1,90,656,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,7,
  	63,2,64,7,64,2,65,7,65,2,66,7,66,1,0,5,0,136,8,0,10,0,12,0,139,9,0,1,
  	0,1,0,1,0,5,0,144,8,0,10,0,12,0,147,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,3,3,165,8,3,1,3,1,3,5,3,169,8,3,10,
  	3,12,3,172,9,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,
  	4,187,8,4,1,5,1,5,1,5,1,5,1,5,1,5,3,5,195,8,5,1,5,1,5,1,6,1,6,1,7,1,7,
  	1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,3,9,212,8,9,1,9,1,9,1,9,1,10,1,10,
  	1,10,1,10,1,10,1,10,5,10,223,8,10,10,10,12,10,226,9,10,1,10,1,10,1,11,
  	1,11,3,11,232,8,11,1,11,1,11,1,11,1,11,5,11,238,8,11,10,11,12,11,241,
  	9,11,1,11,1,11,1,11,5,11,246,8,11,10,11,12,11,249,9,11,1,11,1,11,5,11,
  	253,8,11,10,11,12,11,256,9,11,1,11,3,11,259,8,11,1,12,1,12,3,12,263,8,
  	12,1,12,1,12,1,12,1,12,5,12,269,8,12,10,12,12,12,272,9,12,1,12,1,12,1,
  	12,5,12,277,8,12,10,12,12,12,280,9,12,1,12,1,12,1,13,1,13,1,13,5,13,287,
  	8,13,10,13,12,13,290,9,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,3,14,299,
  	8,14,1,15,3,15,302,8,15,1,15,1,15,1,16,1,16,1,16,1,16,3,16,310,8,16,1,
  	17,3,17,313,8,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,
  	18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,335,8,19,10,19,12,
  	19,338,9,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,5,20,349,8,20,
  	10,20,12,20,352,9,20,1,20,1,20,1,21,1,21,1,21,1,21,5,21,360,8,21,10,21,
  	12,21,363,9,21,1,21,3,21,366,8,21,1,22,1,22,1,22,5,22,371,8,22,10,22,
  	12,22,374,9,22,1,22,3,22,377,8,22,1,23,1,23,1,23,1,23,1,23,1,23,3,23,
  	385,8,23,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,26,1,26,
  	1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,3,28,410,8,28,
  	1,29,1,29,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,31,1,31,1,31,3,31,
  	425,8,31,1,32,1,32,1,32,5,32,430,8,32,10,32,12,32,433,9,32,1,32,1,32,
  	1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,1,33,5,33,446,8,33,10,33,12,33,
  	449,9,33,1,33,1,33,1,34,1,34,3,34,455,8,34,1,34,1,34,1,34,1,34,1,34,5,
  	34,462,8,34,10,34,12,34,465,9,34,1,34,1,34,1,35,1,35,1,35,1,35,1,35,1,
  	35,1,35,3,35,476,8,35,1,36,1,36,1,36,1,36,3,36,482,8,36,1,36,1,36,1,36,
  	3,36,487,8,36,1,37,1,37,1,37,1,38,1,38,1,38,1,39,1,39,1,39,3,39,498,8,
  	39,1,40,1,40,1,40,1,40,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,42,1,42,1,
  	42,1,42,1,42,1,42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,43,1,44,1,44,1,
  	44,1,44,1,44,1,45,1,45,1,46,1,46,1,47,1,47,1,47,3,47,537,8,47,1,48,1,
  	48,1,48,1,48,1,49,1,49,1,49,1,49,1,50,1,50,1,50,1,50,3,50,551,8,50,1,
  	50,1,50,3,50,555,8,50,1,50,1,50,1,51,1,51,1,51,1,51,1,51,3,51,564,8,51,
  	1,52,1,52,3,52,568,8,52,1,52,1,52,3,52,572,8,52,1,52,1,52,1,53,1,53,1,
  	53,1,53,1,54,1,54,4,54,582,8,54,11,54,12,54,583,1,54,3,54,587,8,54,1,
  	54,1,54,1,55,1,55,1,55,1,55,1,56,1,56,1,56,5,56,598,8,56,10,56,12,56,
  	601,9,56,1,56,3,56,604,8,56,1,57,1,57,3,57,608,8,57,1,58,1,58,1,58,1,
  	58,1,58,1,58,1,58,1,58,1,58,1,59,1,59,1,60,1,60,1,60,1,61,1,61,3,61,626,
  	8,61,1,62,1,62,1,62,1,62,5,62,632,8,62,10,62,12,62,635,9,62,1,62,3,62,
  	638,8,62,1,62,1,62,1,63,1,63,1,63,1,63,1,64,1,64,1,65,1,65,1,65,1,66,
  	1,66,1,66,3,66,654,8,66,1,66,0,0,67,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,
  	72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,
  	114,116,118,120,122,124,126,128,130,132,0,8,1,0,31,36,1,0,38,40,1,0,54,
  	55,2,0,2,3,5,13,2,0,4,4,14,17,2,0,74,74,88,88,1,0,84,85,1,0,59,60,675,
  	0,137,1,0,0,0,2,150,1,0,0,0,4,154,1,0,0,0,6,160,1,0,0,0,8,186,1,0,0,0,
  	10,194,1,0,0,0,12,198,1,0,0,0,14,200,1,0,0,0,16,204,1,0,0,0,18,208,1,
  	0,0,0,20,216,1,0,0,0,22,229,1,0,0,0,24,260,1,0,0,0,26,283,1,0,0,0,28,
  	298,1,0,0,0,30,301,1,0,0,0,32,305,1,0,0,0,34,312,1,0,0,0,36,319,1,0,0,
  	0,38,327,1,0,0,0,40,341,1,0,0,0,42,355,1,0,0,0,44,367,1,0,0,0,46,384,
  	1,0,0,0,48,386,1,0,0,0,50,391,1,0,0,0,52,396,1,0,0,0,54,401,1,0,0,0,56,
  	409,1,0,0,0,58,411,1,0,0,0,60,416,1,0,0,0,62,421,1,0,0,0,64,426,1,0,0,
  	0,66,436,1,0,0,0,68,452,1,0,0,0,70,475,1,0,0,0,72,477,1,0,0,0,74,488,
  	1,0,0,0,76,491,1,0,0,0,78,494,1,0,0,0,80,499,1,0,0,0,82,503,1,0,0,0,84,
  	510,1,0,0,0,86,519,1,0,0,0,88,524,1,0,0,0,90,529,1,0,0,0,92,531,1,0,0,
  	0,94,536,1,0,0,0,96,538,1,0,0,0,98,542,1,0,0,0,100,546,1,0,0,0,102,563,
  	1,0,0,0,104,565,1,0,0,0,106,575,1,0,0,0,108,579,1,0,0,0,110,590,1,0,0,
  	0,112,594,1,0,0,0,114,607,1,0,0,0,116,609,1,0,0,0,118,618,1,0,0,0,120,
  	620,1,0,0,0,122,625,1,0,0,0,124,627,1,0,0,0,126,641,1,0,0,0,128,645,1,
  	0,0,0,130,647,1,0,0,0,132,653,1,0,0,0,134,136,3,2,1,0,135,134,1,0,0,0,
  	136,139,1,0,0,0,137,135,1,0,0,0,137,138,1,0,0,0,138,145,1,0,0,0,139,137,
  	1,0,0,0,140,144,3,6,3,0,141,144,3,94,47,0,142,144,3,4,2,0,143,140,1,0,
  	0,0,143,141,1,0,0,0,143,142,1,0,0,0,144,147,1,0,0,0,145,143,1,0,0,0,145,
  	146,1,0,0,0,146,148,1,0,0,0,147,145,1,0,0,0,148,149,5,0,0,1,149,1,1,0,
  	0,0,150,151,5,22,0,0,151,152,5,59,0,0,152,153,5,1,0,0,153,3,1,0,0,0,154,
  	155,5,23,0,0,155,156,5,71,0,0,156,157,5,4,0,0,157,158,3,102,51,0,158,
  	159,5,1,0,0,159,5,1,0,0,0,160,161,5,24,0,0,161,162,5,71,0,0,162,164,5,
  	79,0,0,163,165,5,72,0,0,164,163,1,0,0,0,164,165,1,0,0,0,165,170,1,0,0,
  	0,166,167,5,81,0,0,167,169,5,72,0,0,168,166,1,0,0,0,169,172,1,0,0,0,170,
  	168,1,0,0,0,170,171,1,0,0,0,171,173,1,0,0,0,172,170,1,0,0,0,173,174,5,
  	80,0,0,174,175,3,108,54,0,175,7,1,0,0,0,176,187,3,4,2,0,177,187,3,10,
  	5,0,178,187,3,20,10,0,179,187,3,22,11,0,180,187,3,38,19,0,181,187,3,40,
  	20,0,182,187,3,64,32,0,183,187,3,66,33,0,184,187,3,68,34,0,185,187,3,
  	18,9,0,186,176,1,0,0,0,186,177,1,0,0,0,186,178,1,0,0,0,186,179,1,0,0,
  	0,186,180,1,0,0,0,186,181,1,0,0,0,186,182,1,0,0,0,186,183,1,0,0,0,186,
  	184,1,0,0,0,186,185,1,0,0,0,187,9,1,0,0,0,188,195,3,104,52,0,189,195,
  	3,120,60,0,190,195,3,12,6,0,191,195,3,14,7,0,192,195,3,16,8,0,193,195,
  	3,70,35,0,194,188,1,0,0,0,194,189,1,0,0,0,194,190,1,0,0,0,194,191,1,0,
  	0,0,194,192,1,0,0,0,194,193,1,0,0,0,195,196,1,0,0,0,196,197,5,1,0,0,197,
  	11,1,0,0,0,198,199,7,0,0,0,199,13,1,0,0,0,200,201,5,20,0,0,201,202,5,
  	84,0,0,202,203,5,71,0,0,203,15,1,0,0,0,204,205,5,21,0,0,205,206,5,84,
  	0,0,206,207,5,71,0,0,207,17,1,0,0,0,208,209,5,73,0,0,209,211,5,79,0,0,
  	210,212,3,112,56,0,211,210,1,0,0,0,211,212,1,0,0,0,212,213,1,0,0,0,213,
  	214,5,80,0,0,214,215,5,1,0,0,215,19,1,0,0,0,216,217,5,29,0,0,217,218,
  	5,79,0,0,218,219,3,130,65,0,219,220,5,80,0,0,220,224,5,86,0,0,221,223,
  	3,10,5,0,222,221,1,0,0,0,223,226,1,0,0,0,224,222,1,0,0,0,224,225,1,0,
  	0,0,225,227,1,0,0,0,226,224,1,0,0,0,227,228,5,87,0,0,228,21,1,0,0,0,229,
  	231,5,25,0,0,230,232,5,19,0,0,231,230,1,0,0,0,231,232,1,0,0,0,232,233,
  	1,0,0,0,233,234,5,79,0,0,234,239,3,28,14,0,235,236,5,18,0,0,236,238,3,
  	28,14,0,237,235,1,0,0,0,238,241,1,0,0,0,239,237,1,0,0,0,239,240,1,0,0,
  	0,240,242,1,0,0,0,241,239,1,0,0,0,242,243,5,80,0,0,243,247,5,86,0,0,244,
  	246,3,8,4,0,245,244,1,0,0,0,246,249,1,0,0,0,247,245,1,0,0,0,247,248,1,
  	0,0,0,248,250,1,0,0,0,249,247,1,0,0,0,250,254,5,87,0,0,251,253,3,24,12,
  	0,252,251,1,0,0,0,253,256,1,0,0,0,254,252,1,0,0,0,254,255,1,0,0,0,255,
  	258,1,0,0,0,256,254,1,0,0,0,257,259,3,26,13,0,258,257,1,0,0,0,258,259,
  	1,0,0,0,259,23,1,0,0,0,260,262,5,26,0,0,261,263,5,19,0,0,262,261,1,0,
  	0,0,262,263,1,0,0,0,263,264,1,0,0,0,264,265,5,79,0,0,265,270,3,28,14,
  	0,266,267,5,18,0,0,267,269,3,28,14,0,268,266,1,0,0,0,269,272,1,0,0,0,
  	270,268,1,0,0,0,270,271,1,0,0,0,271,273,1,0,0,0,272,270,1,0,0,0,273,274,
  	5,80,0,0,274,278,5,86,0,0,275,277,3,8,4,0,276,275,1,0,0,0,277,280,1,0,
  	0,0,278,276,1,0,0,0,278,279,1,0,0,0,279,281,1,0,0,0,280,278,1,0,0,0,281,
  	282,5,87,0,0,282,25,1,0,0,0,283,284,5,27,0,0,284,288,5,86,0,0,285,287,
  	3,8,4,0,286,285,1,0,0,0,287,290,1,0,0,0,288,286,1,0,0,0,288,289,1,0,0,
  	0,289,291,1,0,0,0,290,288,1,0,0,0,291,292,5,87,0,0,292,27,1,0,0,0,293,
  	299,3,32,16,0,294,299,3,34,17,0,295,299,3,30,15,0,296,299,3,36,18,0,297,
  	299,3,104,52,0,298,293,1,0,0,0,298,294,1,0,0,0,298,295,1,0,0,0,298,296,
  	1,0,0,0,298,297,1,0,0,0,299,29,1,0,0,0,300,302,5,19,0,0,301,300,1,0,0,
  	0,301,302,1,0,0,0,302,303,1,0,0,0,303,304,7,1,0,0,304,31,1,0,0,0,305,
  	306,3,102,51,0,306,309,3,90,45,0,307,310,3,86,43,0,308,310,3,102,51,0,
  	309,307,1,0,0,0,309,308,1,0,0,0,310,33,1,0,0,0,311,313,5,19,0,0,312,311,
  	1,0,0,0,312,313,1,0,0,0,313,314,1,0,0,0,314,315,3,102,51,0,315,316,5,
  	57,0,0,316,317,5,74,0,0,317,318,5,58,0,0,318,35,1,0,0,0,319,320,3,88,
  	44,0,320,321,3,90,45,0,321,322,5,57,0,0,322,323,5,74,0,0,323,324,5,81,
  	0,0,324,325,5,74,0,0,325,326,5,58,0,0,326,37,1,0,0,0,327,328,5,30,0,0,
  	328,329,5,79,0,0,329,330,3,46,23,0,330,331,5,80,0,0,331,336,5,86,0,0,
  	332,335,3,44,22,0,333,335,3,42,21,0,334,332,1,0,0,0,334,333,1,0,0,0,335,
  	338,1,0,0,0,336,334,1,0,0,0,336,337,1,0,0,0,337,339,1,0,0,0,338,336,1,
  	0,0,0,339,340,5,87,0,0,340,39,1,0,0,0,341,342,7,2,0,0,342,343,5,79,0,
  	0,343,344,3,102,51,0,344,345,5,80,0,0,345,350,5,86,0,0,346,349,3,44,22,
  	0,347,349,3,42,21,0,348,346,1,0,0,0,348,347,1,0,0,0,349,352,1,0,0,0,350,
  	348,1,0,0,0,350,351,1,0,0,0,351,353,1,0,0,0,352,350,1,0,0,0,353,354,5,
  	87,0,0,354,41,1,0,0,0,355,356,5,46,0,0,356,357,3,56,28,0,357,365,5,82,
  	0,0,358,360,3,8,4,0,359,358,1,0,0,0,360,363,1,0,0,0,361,359,1,0,0,0,361,
  	362,1,0,0,0,362,366,1,0,0,0,363,361,1,0,0,0,364,366,3,102,51,0,365,361,
  	1,0,0,0,365,364,1,0,0,0,366,43,1,0,0,0,367,368,5,47,0,0,368,376,5,82,
  	0,0,369,371,3,8,4,0,370,369,1,0,0,0,371,374,1,0,0,0,372,370,1,0,0,0,372,
  	373,1,0,0,0,373,377,1,0,0,0,374,372,1,0,0,0,375,377,3,102,51,0,376,372,
  	1,0,0,0,376,375,1,0,0,0,377,45,1,0,0,0,378,385,3,102,51,0,379,385,3,104,
  	52,0,380,385,3,48,24,0,381,385,3,50,25,0,382,385,3,52,26,0,383,385,3,
  	54,27,0,384,378,1,0,0,0,384,379,1,0,0,0,384,380,1,0,0,0,384,381,1,0,0,
  	0,384,382,1,0,0,0,384,383,1,0,0,0,385,47,1,0,0,0,386,387,3,88,44,0,387,
  	388,5,57,0,0,388,389,5,74,0,0,389,390,5,58,0,0,390,49,1,0,0,0,391,392,
  	5,41,0,0,392,393,5,79,0,0,393,394,3,102,51,0,394,395,5,80,0,0,395,51,
  	1,0,0,0,396,397,5,43,0,0,397,398,5,79,0,0,398,399,3,102,51,0,399,400,
  	5,80,0,0,400,53,1,0,0,0,401,402,5,42,0,0,402,403,5,79,0,0,403,404,5,80,
  	0,0,404,55,1,0,0,0,405,410,3,102,51,0,406,410,3,58,29,0,407,410,3,60,
  	30,0,408,410,3,62,31,0,409,405,1,0,0,0,409,406,1,0,0,0,409,407,1,0,0,
  	0,409,408,1,0,0,0,410,57,1,0,0,0,411,412,5,45,0,0,412,413,5,79,0,0,413,
  	414,3,102,51,0,414,415,5,80,0,0,415,59,1,0,0,0,416,417,5,44,0,0,417,418,
  	5,79,0,0,418,419,3,102,51,0,419,420,5,80,0,0,420,61,1,0,0,0,421,424,3,
  	90,45,0,422,425,3,86,43,0,423,425,3,102,51,0,424,422,1,0,0,0,424,423,
  	1,0,0,0,425,63,1,0,0,0,426,427,5,28,0,0,427,431,5,86,0,0,428,430,3,8,
  	4,0,429,428,1,0,0,0,430,433,1,0,0,0,431,429,1,0,0,0,431,432,1,0,0,0,432,
  	434,1,0,0,0,433,431,1,0,0,0,434,435,5,87,0,0,435,65,1,0,0,0,436,437,5,
  	68,0,0,437,438,5,79,0,0,438,439,3,10,5,0,439,440,3,28,14,0,440,441,5,
  	1,0,0,441,442,3,10,5,0,442,443,5,80,0,0,443,447,5,86,0,0,444,446,3,8,
  	4,0,445,444,1,0,0,0,446,449,1,0,0,0,447,445,1,0,0,0,447,448,1,0,0,0,448,
  	450,1,0,0,0,449,447,1,0,0,0,450,451,5,87,0,0,451,67,1,0,0,0,452,454,5,
  	56,0,0,453,455,5,19,0,0,454,453,1,0,0,0,454,455,1,0,0,0,455,456,1,0,0,
  	0,456,457,5,79,0,0,457,458,3,28,14,0,458,459,5,80,0,0,459,463,5,86,0,
  	0,460,462,3,8,4,0,461,460,1,0,0,0,462,465,1,0,0,0,463,461,1,0,0,0,463,
  	464,1,0,0,0,464,466,1,0,0,0,465,463,1,0,0,0,466,467,5,87,0,0,467,69,1,
  	0,0,0,468,476,3,72,36,0,469,476,3,74,37,0,470,476,3,76,38,0,471,476,3,
  	78,39,0,472,476,3,80,40,0,473,476,3,82,41,0,474,476,3,84,42,0,475,468,
  	1,0,0,0,475,469,1,0,0,0,475,470,1,0,0,0,475,471,1,0,0,0,475,472,1,0,0,
  	0,475,473,1,0,0,0,475,474,1,0,0,0,476,71,1,0,0,0,477,481,3,102,51,0,478,
  	479,5,57,0,0,479,480,5,74,0,0,480,482,5,58,0,0,481,478,1,0,0,0,481,482,
  	1,0,0,0,482,483,1,0,0,0,483,486,3,92,46,0,484,487,3,102,51,0,485,487,
  	3,86,43,0,486,484,1,0,0,0,486,485,1,0,0,0,487,73,1,0,0,0,488,489,5,48,
  	0,0,489,490,3,102,51,0,490,75,1,0,0,0,491,492,5,50,0,0,492,493,3,102,
  	51,0,493,77,1,0,0,0,494,497,5,49,0,0,495,498,5,52,0,0,496,498,3,88,44,
  	0,497,495,1,0,0,0,497,496,1,0,0,0,498,79,1,0,0,0,499,500,5,53,0,0,500,
  	501,5,4,0,0,501,502,3,102,51,0,502,81,1,0,0,0,503,504,5,43,0,0,504,505,
  	5,79,0,0,505,506,3,102,51,0,506,507,5,80,0,0,507,508,5,4,0,0,508,509,
  	3,102,51,0,509,83,1,0,0,0,510,511,3,102,51,0,511,512,5,4,0,0,512,513,
  	5,51,0,0,513,514,5,57,0,0,514,515,5,74,0,0,515,516,5,81,0,0,516,517,5,
  	74,0,0,517,518,5,58,0,0,518,85,1,0,0,0,519,520,5,37,0,0,520,521,5,79,
  	0,0,521,522,3,102,51,0,522,523,5,80,0,0,523,87,1,0,0,0,524,525,5,51,0,
  	0,525,526,5,79,0,0,526,527,3,102,51,0,527,528,5,80,0,0,528,89,1,0,0,0,
  	529,530,7,3,0,0,530,91,1,0,0,0,531,532,7,4,0,0,532,93,1,0,0,0,533,537,
  	3,98,49,0,534,537,3,96,48,0,535,537,3,100,50,0,536,533,1,0,0,0,536,534,
  	1,0,0,0,536,535,1,0,0,0,537,95,1,0,0,0,538,539,5,63,0,0,539,540,5,74,
  	0,0,540,541,3,108,54,0,541,97,1,0,0,0,542,543,5,62,0,0,543,544,5,71,0,
  	0,544,545,3,108,54,0,545,99,1,0,0,0,546,547,5,63,0,0,547,548,5,74,0,0,
  	548,550,3,132,66,0,549,551,5,79,0,0,550,549,1,0,0,0,550,551,1,0,0,0,551,
  	552,1,0,0,0,552,554,3,102,51,0,553,555,5,80,0,0,554,553,1,0,0,0,554,555,
  	1,0,0,0,555,556,1,0,0,0,556,557,3,108,54,0,557,101,1,0,0,0,558,564,5,
  	88,0,0,559,564,5,74,0,0,560,564,5,71,0,0,561,564,5,72,0,0,562,564,3,122,
  	61,0,563,558,1,0,0,0,563,559,1,0,0,0,563,560,1,0,0,0,563,561,1,0,0,0,
  	563,562,1,0,0,0,564,103,1,0,0,0,565,567,5,71,0,0,566,568,3,106,53,0,567,
  	566,1,0,0,0,567,568,1,0,0,0,568,569,1,0,0,0,569,571,5,79,0,0,570,572,
  	3,112,56,0,571,570,1,0,0,0,571,572,1,0,0,0,572,573,1,0,0,0,573,574,5,
  	80,0,0,574,105,1,0,0,0,575,576,5,5,0,0,576,577,3,130,65,0,577,578,5,6,
  	0,0,578,107,1,0,0,0,579,586,5,86,0,0,580,582,3,8,4,0,581,580,1,0,0,0,
  	582,583,1,0,0,0,583,581,1,0,0,0,583,584,1,0,0,0,584,587,1,0,0,0,585,587,
  	3,110,55,0,586,581,1,0,0,0,586,585,1,0,0,0,587,588,1,0,0,0,588,589,5,
  	87,0,0,589,109,1,0,0,0,590,591,5,67,0,0,591,592,5,69,0,0,592,593,5,1,
  	0,0,593,111,1,0,0,0,594,599,3,114,57,0,595,596,5,81,0,0,596,598,3,114,
  	57,0,597,595,1,0,0,0,598,601,1,0,0,0,599,597,1,0,0,0,599,600,1,0,0,0,
  	600,603,1,0,0,0,601,599,1,0,0,0,602,604,5,81,0,0,603,602,1,0,0,0,603,
  	604,1,0,0,0,604,113,1,0,0,0,605,608,3,102,51,0,606,608,3,116,58,0,607,
  	605,1,0,0,0,607,606,1,0,0,0,608,115,1,0,0,0,609,610,5,70,0,0,610,611,
  	5,5,0,0,611,612,5,59,0,0,612,613,5,81,0,0,613,614,3,118,59,0,614,615,
  	5,81,0,0,615,616,3,118,59,0,616,617,5,6,0,0,617,117,1,0,0,0,618,619,7,
  	5,0,0,619,119,1,0,0,0,620,621,7,6,0,0,621,622,5,71,0,0,622,121,1,0,0,
  	0,623,626,3,128,64,0,624,626,3,124,62,0,625,623,1,0,0,0,625,624,1,0,0,
  	0,626,123,1,0,0,0,627,628,5,86,0,0,628,633,3,126,63,0,629,630,5,81,0,
  	0,630,632,3,126,63,0,631,629,1,0,0,0,632,635,1,0,0,0,633,631,1,0,0,0,
  	633,634,1,0,0,0,634,637,1,0,0,0,635,633,1,0,0,0,636,638,5,81,0,0,637,
  	636,1,0,0,0,637,638,1,0,0,0,638,639,1,0,0,0,639,640,5,87,0,0,640,125,
  	1,0,0,0,641,642,5,71,0,0,642,643,5,4,0,0,643,644,3,128,64,0,644,127,1,
  	0,0,0,645,646,7,7,0,0,646,129,1,0,0,0,647,648,5,71,0,0,648,649,3,102,
  	51,0,649,131,1,0,0,0,650,651,5,68,0,0,651,654,5,71,0,0,652,654,5,61,0,
  	0,653,650,1,0,0,0,653,652,1,0,0,0,654,133,1,0,0,0,56,137,143,145,164,
  	170,186,194,211,224,231,239,247,254,258,262,270,278,288,298,301,309,312,
  	334,336,348,350,361,365,372,376,384,409,424,431,447,454,463,475,481,486,
  	497,536,550,554,563,567,571,583,586,599,603,607,625,633,637,653
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

std::vector<ExplorerScriptParser::Constant_assignContext *> ExplorerScriptParser::StartContext::constant_assign() {
  return getRuleContexts<ExplorerScriptParser::Constant_assignContext>();
}

ExplorerScriptParser::Constant_assignContext* ExplorerScriptParser::StartContext::constant_assign(size_t i) {
  return getRuleContext<ExplorerScriptParser::Constant_assignContext>(i);
}


size_t ExplorerScriptParser::StartContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleStart;
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
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::IMPORT) {
      setState(134);
      import_stmt();
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(145);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -4611686018402222080) != 0)) {
      setState(143);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ExplorerScriptParser::MACRO: {
          setState(140);
          macrodef();
          break;
        }

        case ExplorerScriptParser::CORO:
        case ExplorerScriptParser::DEF: {
          setState(141);
          funcdef();
          break;
        }

        case ExplorerScriptParser::CONST: {
          setState(142);
          constant_assign();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(147);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(148);
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
    setState(150);
    match(ExplorerScriptParser::IMPORT);
    setState(151);
    match(ExplorerScriptParser::STRING_LITERAL);
    setState(152);
    match(ExplorerScriptParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_assignContext ------------------------------------------------------------------

ExplorerScriptParser::Constant_assignContext::Constant_assignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::Constant_assignContext::CONST() {
  return getToken(ExplorerScriptParser::CONST, 0);
}

tree::TerminalNode* ExplorerScriptParser::Constant_assignContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExplorerScriptParser::Constant_assignContext::ASSIGN() {
  return getToken(ExplorerScriptParser::ASSIGN, 0);
}

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Constant_assignContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}


size_t ExplorerScriptParser::Constant_assignContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleConstant_assign;
}


std::any ExplorerScriptParser::Constant_assignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitConstant_assign(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Constant_assignContext* ExplorerScriptParser::constant_assign() {
  Constant_assignContext *_localctx = _tracker.createInstance<Constant_assignContext>(_ctx, getState());
  enterRule(_localctx, 4, ExplorerScriptParser::RuleConstant_assign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(ExplorerScriptParser::CONST);
    setState(155);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(156);
    match(ExplorerScriptParser::ASSIGN);
    setState(157);
    primitive();
    setState(158);
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


std::any ExplorerScriptParser::MacrodefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitMacrodef(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::MacrodefContext* ExplorerScriptParser::macrodef() {
  MacrodefContext *_localctx = _tracker.createInstance<MacrodefContext>(_ctx, getState());
  enterRule(_localctx, 6, ExplorerScriptParser::RuleMacrodef);
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
    setState(160);
    match(ExplorerScriptParser::MACRO);
    setState(161);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(162);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::VARIABLE) {
      setState(163);
      match(ExplorerScriptParser::VARIABLE);
    }
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::COMMA) {
      setState(166);
      match(ExplorerScriptParser::COMMA);
      setState(167);
      match(ExplorerScriptParser::VARIABLE);
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(173);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(174);
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

ExplorerScriptParser::Constant_assignContext* ExplorerScriptParser::StmtContext::constant_assign() {
  return getRuleContext<ExplorerScriptParser::Constant_assignContext>(0);
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


std::any ExplorerScriptParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::StmtContext* ExplorerScriptParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 8, ExplorerScriptParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::CONST: {
        setState(176);
        constant_assign();
        break;
      }

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
      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::AT:
      case ExplorerScriptParser::PARAGRAPH:
      case ExplorerScriptParser::OPEN_BRACE:
      case ExplorerScriptParser::DECIMAL: {
        setState(177);
        simple_stmt();
        break;
      }

      case ExplorerScriptParser::WITH: {
        setState(178);
        ctx_block();
        break;
      }

      case ExplorerScriptParser::IF: {
        setState(179);
        if_block();
        break;
      }

      case ExplorerScriptParser::SWITCH: {
        setState(180);
        switch_block();
        break;
      }

      case ExplorerScriptParser::MESSAGE_SWITCH_TALK:
      case ExplorerScriptParser::MESSAGE_SWITCH_MONOLOGUE: {
        setState(181);
        message_switch_block();
        break;
      }

      case ExplorerScriptParser::FOREVER: {
        setState(182);
        forever_block();
        break;
      }

      case ExplorerScriptParser::FOR: {
        setState(183);
        for_block();
        break;
      }

      case ExplorerScriptParser::WHILE: {
        setState(184);
        while_block();
        break;
      }

      case ExplorerScriptParser::MACRO_CALL: {
        setState(185);
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


std::any ExplorerScriptParser::Simple_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSimple_stmt(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Simple_stmtContext* ExplorerScriptParser::simple_stmt() {
  Simple_stmtContext *_localctx = _tracker.createInstance<Simple_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, ExplorerScriptParser::RuleSimple_stmt);

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
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(188);
      operation();
      break;
    }

    case 2: {
      setState(189);
      label();
      break;
    }

    case 3: {
      setState(190);
      cntrl_stmt();
      break;
    }

    case 4: {
      setState(191);
      jump();
      break;
    }

    case 5: {
      setState(192);
      call();
      break;
    }

    case 6: {
      setState(193);
      assignment();
      break;
    }

    default:
      break;
    }
    setState(196);
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


std::any ExplorerScriptParser::Cntrl_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCntrl_stmt(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Cntrl_stmtContext* ExplorerScriptParser::cntrl_stmt() {
  Cntrl_stmtContext *_localctx = _tracker.createInstance<Cntrl_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, ExplorerScriptParser::RuleCntrl_stmt);
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
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 135291469824) != 0))) {
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


std::any ExplorerScriptParser::JumpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitJump(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::JumpContext* ExplorerScriptParser::jump() {
  JumpContext *_localctx = _tracker.createInstance<JumpContext>(_ctx, getState());
  enterRule(_localctx, 14, ExplorerScriptParser::RuleJump);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(ExplorerScriptParser::JUMP);
    setState(201);
    match(ExplorerScriptParser::AT);
    setState(202);
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


std::any ExplorerScriptParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::CallContext* ExplorerScriptParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 16, ExplorerScriptParser::RuleCall);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    match(ExplorerScriptParser::CALL);
    setState(205);
    match(ExplorerScriptParser::AT);
    setState(206);
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


std::any ExplorerScriptParser::Macro_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitMacro_call(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Macro_callContext* ExplorerScriptParser::macro_call() {
  Macro_callContext *_localctx = _tracker.createInstance<Macro_callContext>(_ctx, getState());
  enterRule(_localctx, 18, ExplorerScriptParser::RuleMacro_call);
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
    setState(208);
    match(ExplorerScriptParser::MACRO_CALL);
    setState(209);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(211);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 59) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 59)) & 671135747) != 0)) {
      setState(210);
      arglist();
    }
    setState(213);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(214);
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

tree::TerminalNode* ExplorerScriptParser::Ctx_blockContext::CLOSE_BRACE() {
  return getToken(ExplorerScriptParser::CLOSE_BRACE, 0);
}

std::vector<ExplorerScriptParser::Simple_stmtContext *> ExplorerScriptParser::Ctx_blockContext::simple_stmt() {
  return getRuleContexts<ExplorerScriptParser::Simple_stmtContext>();
}

ExplorerScriptParser::Simple_stmtContext* ExplorerScriptParser::Ctx_blockContext::simple_stmt(size_t i) {
  return getRuleContext<ExplorerScriptParser::Simple_stmtContext>(i);
}


size_t ExplorerScriptParser::Ctx_blockContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCtx_block;
}


std::any ExplorerScriptParser::Ctx_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCtx_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Ctx_blockContext* ExplorerScriptParser::ctx_block() {
  Ctx_blockContext *_localctx = _tracker.createInstance<Ctx_blockContext>(_ctx, getState());
  enterRule(_localctx, 20, ExplorerScriptParser::RuleCtx_block);
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
    setState(216);
    match(ExplorerScriptParser::WITH);
    setState(217);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(218);
    ctx_header();
    setState(219);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(220);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(224);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1740368712389623808) != 0) || ((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 188427) != 0)) {
      setState(221);
      simple_stmt();
      setState(226);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(227);
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


std::any ExplorerScriptParser::If_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_blockContext* ExplorerScriptParser::if_block() {
  If_blockContext *_localctx = _tracker.createInstance<If_blockContext>(_ctx, getState());
  enterRule(_localctx, 22, ExplorerScriptParser::RuleIf_block);
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
    setState(229);
    match(ExplorerScriptParser::IF);
    setState(231);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(230);
      match(ExplorerScriptParser::NOT);
    }
    setState(233);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(234);
    if_header();
    setState(239);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::OR) {
      setState(235);
      match(ExplorerScriptParser::OR);
      setState(236);
      if_header();
      setState(241);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(242);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(243);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(247);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1866469503876988928) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 1507449) != 0)) {
      setState(244);
      stmt();
      setState(249);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(250);
    match(ExplorerScriptParser::CLOSE_BRACE);
    setState(254);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::ELSEIF) {
      setState(251);
      elseif_block();
      setState(256);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(258);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::ELSE) {
      setState(257);
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


std::any ExplorerScriptParser::Elseif_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitElseif_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Elseif_blockContext* ExplorerScriptParser::elseif_block() {
  Elseif_blockContext *_localctx = _tracker.createInstance<Elseif_blockContext>(_ctx, getState());
  enterRule(_localctx, 24, ExplorerScriptParser::RuleElseif_block);
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
    setState(260);
    match(ExplorerScriptParser::ELSEIF);
    setState(262);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(261);
      match(ExplorerScriptParser::NOT);
    }
    setState(264);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(265);
    if_header();
    setState(270);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::OR) {
      setState(266);
      match(ExplorerScriptParser::OR);
      setState(267);
      if_header();
      setState(272);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(273);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(274);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(278);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1866469503876988928) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 1507449) != 0)) {
      setState(275);
      stmt();
      setState(280);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(281);
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


std::any ExplorerScriptParser::Else_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitElse_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Else_blockContext* ExplorerScriptParser::else_block() {
  Else_blockContext *_localctx = _tracker.createInstance<Else_blockContext>(_ctx, getState());
  enterRule(_localctx, 26, ExplorerScriptParser::RuleElse_block);
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
    setState(283);
    match(ExplorerScriptParser::ELSE);
    setState(284);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(288);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1866469503876988928) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 1507449) != 0)) {
      setState(285);
      stmt();
      setState(290);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(291);
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


std::any ExplorerScriptParser::If_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_header(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_headerContext* ExplorerScriptParser::if_header() {
  If_headerContext *_localctx = _tracker.createInstance<If_headerContext>(_ctx, getState());
  enterRule(_localctx, 28, ExplorerScriptParser::RuleIf_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(298);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(293);
      if_h_op();
      break;
    }

    case 2: {
      setState(294);
      if_h_bit();
      break;
    }

    case 3: {
      setState(295);
      if_h_negatable();
      break;
    }

    case 4: {
      setState(296);
      if_h_scn();
      break;
    }

    case 5: {
      setState(297);
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


std::any ExplorerScriptParser::If_h_negatableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_h_negatable(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_h_negatableContext* ExplorerScriptParser::if_h_negatable() {
  If_h_negatableContext *_localctx = _tracker.createInstance<If_h_negatableContext>(_ctx, getState());
  enterRule(_localctx, 30, ExplorerScriptParser::RuleIf_h_negatable);
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
    setState(301);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(300);
      match(ExplorerScriptParser::NOT);
    }
    setState(303);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1924145348608) != 0))) {
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

std::vector<ExplorerScriptParser::PrimitiveContext *> ExplorerScriptParser::If_h_opContext::primitive() {
  return getRuleContexts<ExplorerScriptParser::PrimitiveContext>();
}

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::If_h_opContext::primitive(size_t i) {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(i);
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


std::any ExplorerScriptParser::If_h_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_h_op(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_h_opContext* ExplorerScriptParser::if_h_op() {
  If_h_opContext *_localctx = _tracker.createInstance<If_h_opContext>(_ctx, getState());
  enterRule(_localctx, 32, ExplorerScriptParser::RuleIf_h_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
    primitive();
    setState(306);
    conditional_operator();
    setState(309);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::VALUE: {
        setState(307);
        value_of();
        break;
      }

      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::OPEN_BRACE:
      case ExplorerScriptParser::DECIMAL: {
        setState(308);
        primitive();
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::If_h_bitContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
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


std::any ExplorerScriptParser::If_h_bitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_h_bit(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_h_bitContext* ExplorerScriptParser::if_h_bit() {
  If_h_bitContext *_localctx = _tracker.createInstance<If_h_bitContext>(_ctx, getState());
  enterRule(_localctx, 34, ExplorerScriptParser::RuleIf_h_bit);
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
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(311);
      match(ExplorerScriptParser::NOT);
    }
    setState(314);
    primitive();
    setState(315);
    match(ExplorerScriptParser::OPEN_BRACKET);
    setState(316);
    match(ExplorerScriptParser::INTEGER);
    setState(317);
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


std::any ExplorerScriptParser::If_h_scnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitIf_h_scn(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::If_h_scnContext* ExplorerScriptParser::if_h_scn() {
  If_h_scnContext *_localctx = _tracker.createInstance<If_h_scnContext>(_ctx, getState());
  enterRule(_localctx, 36, ExplorerScriptParser::RuleIf_h_scn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    scn_var();
    setState(320);
    conditional_operator();
    setState(321);
    match(ExplorerScriptParser::OPEN_BRACKET);
    setState(322);
    match(ExplorerScriptParser::INTEGER);
    setState(323);
    match(ExplorerScriptParser::COMMA);
    setState(324);
    match(ExplorerScriptParser::INTEGER);
    setState(325);
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


std::any ExplorerScriptParser::Switch_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_blockContext* ExplorerScriptParser::switch_block() {
  Switch_blockContext *_localctx = _tracker.createInstance<Switch_blockContext>(_ctx, getState());
  enterRule(_localctx, 38, ExplorerScriptParser::RuleSwitch_block);
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
    setState(327);
    match(ExplorerScriptParser::SWITCH);
    setState(328);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(329);
    switch_header();
    setState(330);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(331);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(336);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::CASE

    || _la == ExplorerScriptParser::DEFAULT) {
      setState(334);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ExplorerScriptParser::DEFAULT: {
          setState(332);
          default_();
          break;
        }

        case ExplorerScriptParser::CASE: {
          setState(333);
          single_case_block();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(338);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(339);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Message_switch_blockContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
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


std::any ExplorerScriptParser::Message_switch_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitMessage_switch_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Message_switch_blockContext* ExplorerScriptParser::message_switch_block() {
  Message_switch_blockContext *_localctx = _tracker.createInstance<Message_switch_blockContext>(_ctx, getState());
  enterRule(_localctx, 40, ExplorerScriptParser::RuleMessage_switch_block);
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
    setState(341);
    _la = _input->LA(1);
    if (!(_la == ExplorerScriptParser::MESSAGE_SWITCH_TALK

    || _la == ExplorerScriptParser::MESSAGE_SWITCH_MONOLOGUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(342);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(343);
    primitive();
    setState(344);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(345);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(350);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExplorerScriptParser::CASE

    || _la == ExplorerScriptParser::DEFAULT) {
      setState(348);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ExplorerScriptParser::DEFAULT: {
          setState(346);
          default_();
          break;
        }

        case ExplorerScriptParser::CASE: {
          setState(347);
          single_case_block();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(352);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(353);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Single_case_blockContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
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


std::any ExplorerScriptParser::Single_case_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSingle_case_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Single_case_blockContext* ExplorerScriptParser::single_case_block() {
  Single_case_blockContext *_localctx = _tracker.createInstance<Single_case_blockContext>(_ctx, getState());
  enterRule(_localctx, 42, ExplorerScriptParser::RuleSingle_case_block);
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
    setState(355);
    match(ExplorerScriptParser::CASE);
    setState(356);
    case_header();
    setState(357);
    match(ExplorerScriptParser::COLON);
    setState(365);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(361);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1866469503876988928) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 1507449) != 0)) {
        setState(358);
        stmt();
        setState(363);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(364);
      primitive();
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::DefaultContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
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


std::any ExplorerScriptParser::DefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitDefault(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::DefaultContext* ExplorerScriptParser::default_() {
  DefaultContext *_localctx = _tracker.createInstance<DefaultContext>(_ctx, getState());
  enterRule(_localctx, 44, ExplorerScriptParser::RuleDefault);
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
    setState(367);
    match(ExplorerScriptParser::DEFAULT);
    setState(368);
    match(ExplorerScriptParser::COLON);
    setState(376);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(372);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1866469503876988928) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 68)) & 1507449) != 0)) {
        setState(369);
        stmt();
        setState(374);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(375);
      primitive();
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

//----------------- Switch_headerContext ------------------------------------------------------------------

ExplorerScriptParser::Switch_headerContext::Switch_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Switch_headerContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
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


std::any ExplorerScriptParser::Switch_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_header(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_headerContext* ExplorerScriptParser::switch_header() {
  Switch_headerContext *_localctx = _tracker.createInstance<Switch_headerContext>(_ctx, getState());
  enterRule(_localctx, 46, ExplorerScriptParser::RuleSwitch_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(378);
      primitive();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(379);
      operation();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(380);
      switch_h_scn();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(381);
      switch_h_random();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(382);
      switch_h_dungeon_mode();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(383);
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


std::any ExplorerScriptParser::Switch_h_scnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_h_scn(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_h_scnContext* ExplorerScriptParser::switch_h_scn() {
  Switch_h_scnContext *_localctx = _tracker.createInstance<Switch_h_scnContext>(_ctx, getState());
  enterRule(_localctx, 48, ExplorerScriptParser::RuleSwitch_h_scn);

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
    scn_var();
    setState(387);
    match(ExplorerScriptParser::OPEN_BRACKET);
    setState(388);
    match(ExplorerScriptParser::INTEGER);
    setState(389);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Switch_h_randomContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_randomContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Switch_h_randomContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSwitch_h_random;
}


std::any ExplorerScriptParser::Switch_h_randomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_h_random(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_h_randomContext* ExplorerScriptParser::switch_h_random() {
  Switch_h_randomContext *_localctx = _tracker.createInstance<Switch_h_randomContext>(_ctx, getState());
  enterRule(_localctx, 50, ExplorerScriptParser::RuleSwitch_h_random);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    match(ExplorerScriptParser::RANDOM);
    setState(392);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(393);
    primitive();
    setState(394);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Switch_h_dungeon_modeContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Switch_h_dungeon_modeContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Switch_h_dungeon_modeContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleSwitch_h_dungeon_mode;
}


std::any ExplorerScriptParser::Switch_h_dungeon_modeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_h_dungeon_mode(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_h_dungeon_modeContext* ExplorerScriptParser::switch_h_dungeon_mode() {
  Switch_h_dungeon_modeContext *_localctx = _tracker.createInstance<Switch_h_dungeon_modeContext>(_ctx, getState());
  enterRule(_localctx, 52, ExplorerScriptParser::RuleSwitch_h_dungeon_mode);

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
    match(ExplorerScriptParser::DUNGEON_MODE);
    setState(397);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(398);
    primitive();
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


std::any ExplorerScriptParser::Switch_h_sectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSwitch_h_sector(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Switch_h_sectorContext* ExplorerScriptParser::switch_h_sector() {
  Switch_h_sectorContext *_localctx = _tracker.createInstance<Switch_h_sectorContext>(_ctx, getState());
  enterRule(_localctx, 54, ExplorerScriptParser::RuleSwitch_h_sector);

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
    match(ExplorerScriptParser::SECTOR);
    setState(402);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(403);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Case_headerContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
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


std::any ExplorerScriptParser::Case_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCase_header(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Case_headerContext* ExplorerScriptParser::case_header() {
  Case_headerContext *_localctx = _tracker.createInstance<Case_headerContext>(_ctx, getState());
  enterRule(_localctx, 56, ExplorerScriptParser::RuleCase_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(409);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::OPEN_BRACE:
      case ExplorerScriptParser::DECIMAL: {
        enterOuterAlt(_localctx, 1);
        setState(405);
        primitive();
        break;
      }

      case ExplorerScriptParser::MENU: {
        enterOuterAlt(_localctx, 2);
        setState(406);
        case_h_menu();
        break;
      }

      case ExplorerScriptParser::MENU2: {
        enterOuterAlt(_localctx, 3);
        setState(407);
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
        setState(408);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Case_h_menuContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Case_h_menuContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Case_h_menuContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCase_h_menu;
}


std::any ExplorerScriptParser::Case_h_menuContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCase_h_menu(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Case_h_menuContext* ExplorerScriptParser::case_h_menu() {
  Case_h_menuContext *_localctx = _tracker.createInstance<Case_h_menuContext>(_ctx, getState());
  enterRule(_localctx, 58, ExplorerScriptParser::RuleCase_h_menu);

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
    match(ExplorerScriptParser::MENU);
    setState(412);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(413);
    primitive();
    setState(414);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Case_h_menu2Context::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Case_h_menu2Context::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Case_h_menu2Context::getRuleIndex() const {
  return ExplorerScriptParser::RuleCase_h_menu2;
}


std::any ExplorerScriptParser::Case_h_menu2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCase_h_menu2(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Case_h_menu2Context* ExplorerScriptParser::case_h_menu2() {
  Case_h_menu2Context *_localctx = _tracker.createInstance<Case_h_menu2Context>(_ctx, getState());
  enterRule(_localctx, 60, ExplorerScriptParser::RuleCase_h_menu2);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(ExplorerScriptParser::MENU2);
    setState(417);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(418);
    primitive();
    setState(419);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Case_h_opContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}


size_t ExplorerScriptParser::Case_h_opContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCase_h_op;
}


std::any ExplorerScriptParser::Case_h_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCase_h_op(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Case_h_opContext* ExplorerScriptParser::case_h_op() {
  Case_h_opContext *_localctx = _tracker.createInstance<Case_h_opContext>(_ctx, getState());
  enterRule(_localctx, 62, ExplorerScriptParser::RuleCase_h_op);

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
    conditional_operator();
    setState(424);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::VALUE: {
        setState(422);
        value_of();
        break;
      }

      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::OPEN_BRACE:
      case ExplorerScriptParser::DECIMAL: {
        setState(423);
        primitive();
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


std::any ExplorerScriptParser::Forever_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitForever_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Forever_blockContext* ExplorerScriptParser::forever_block() {
  Forever_blockContext *_localctx = _tracker.createInstance<Forever_blockContext>(_ctx, getState());
  enterRule(_localctx, 64, ExplorerScriptParser::RuleForever_block);
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
    setState(426);
    match(ExplorerScriptParser::FOREVER);
    setState(427);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(431);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1866469503876988928) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 1507449) != 0)) {
      setState(428);
      stmt();
      setState(433);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(434);
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


std::any ExplorerScriptParser::For_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFor_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::For_blockContext* ExplorerScriptParser::for_block() {
  For_blockContext *_localctx = _tracker.createInstance<For_blockContext>(_ctx, getState());
  enterRule(_localctx, 66, ExplorerScriptParser::RuleFor_block);
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
    setState(436);
    match(ExplorerScriptParser::FOR);
    setState(437);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(438);
    simple_stmt();
    setState(439);
    if_header();
    setState(440);
    match(ExplorerScriptParser::T__0);
    setState(441);
    simple_stmt();
    setState(442);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(443);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(447);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1866469503876988928) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 1507449) != 0)) {
      setState(444);
      stmt();
      setState(449);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(450);
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


std::any ExplorerScriptParser::While_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitWhile_block(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::While_blockContext* ExplorerScriptParser::while_block() {
  While_blockContext *_localctx = _tracker.createInstance<While_blockContext>(_ctx, getState());
  enterRule(_localctx, 68, ExplorerScriptParser::RuleWhile_block);
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
    setState(452);
    match(ExplorerScriptParser::WHILE);
    setState(454);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::NOT) {
      setState(453);
      match(ExplorerScriptParser::NOT);
    }
    setState(456);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(457);
    if_header();
    setState(458);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(459);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(463);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1866469503876988928) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 1507449) != 0)) {
      setState(460);
      stmt();
      setState(465);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(466);
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


std::any ExplorerScriptParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::AssignmentContext* ExplorerScriptParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 70, ExplorerScriptParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(475);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(468);
      assignment_regular();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(469);
      assignment_clear();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(470);
      assignment_initial();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(471);
      assignment_reset();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(472);
      assignment_adv_log();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(473);
      assignment_dungeon_mode();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(474);
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

std::vector<ExplorerScriptParser::PrimitiveContext *> ExplorerScriptParser::Assignment_regularContext::primitive() {
  return getRuleContexts<ExplorerScriptParser::PrimitiveContext>();
}

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Assignment_regularContext::primitive(size_t i) {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(i);
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


std::any ExplorerScriptParser::Assignment_regularContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_regular(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_regularContext* ExplorerScriptParser::assignment_regular() {
  Assignment_regularContext *_localctx = _tracker.createInstance<Assignment_regularContext>(_ctx, getState());
  enterRule(_localctx, 72, ExplorerScriptParser::RuleAssignment_regular);
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
    setState(477);
    primitive();
    setState(481);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::OPEN_BRACKET) {
      setState(478);
      match(ExplorerScriptParser::OPEN_BRACKET);
      setState(479);
      match(ExplorerScriptParser::INTEGER);
      setState(480);
      match(ExplorerScriptParser::CLOSE_BRACKET);
    }
    setState(483);
    assign_operator();
    setState(486);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::OPEN_BRACE:
      case ExplorerScriptParser::DECIMAL: {
        setState(484);
        primitive();
        break;
      }

      case ExplorerScriptParser::VALUE: {
        setState(485);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Assignment_clearContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}


size_t ExplorerScriptParser::Assignment_clearContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_clear;
}


std::any ExplorerScriptParser::Assignment_clearContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_clear(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_clearContext* ExplorerScriptParser::assignment_clear() {
  Assignment_clearContext *_localctx = _tracker.createInstance<Assignment_clearContext>(_ctx, getState());
  enterRule(_localctx, 74, ExplorerScriptParser::RuleAssignment_clear);

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
    match(ExplorerScriptParser::CLEAR);
    setState(489);
    primitive();
   
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Assignment_initialContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}


size_t ExplorerScriptParser::Assignment_initialContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_initial;
}


std::any ExplorerScriptParser::Assignment_initialContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_initial(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_initialContext* ExplorerScriptParser::assignment_initial() {
  Assignment_initialContext *_localctx = _tracker.createInstance<Assignment_initialContext>(_ctx, getState());
  enterRule(_localctx, 76, ExplorerScriptParser::RuleAssignment_initial);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(491);
    match(ExplorerScriptParser::INIT);
    setState(492);
    primitive();
   
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


std::any ExplorerScriptParser::Assignment_resetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_reset(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_resetContext* ExplorerScriptParser::assignment_reset() {
  Assignment_resetContext *_localctx = _tracker.createInstance<Assignment_resetContext>(_ctx, getState());
  enterRule(_localctx, 78, ExplorerScriptParser::RuleAssignment_reset);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(494);
    match(ExplorerScriptParser::RESET);
    setState(497);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::DUNGEON_RESULT: {
        setState(495);
        match(ExplorerScriptParser::DUNGEON_RESULT);
        break;
      }

      case ExplorerScriptParser::SCN: {
        setState(496);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Assignment_adv_logContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}


size_t ExplorerScriptParser::Assignment_adv_logContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleAssignment_adv_log;
}


std::any ExplorerScriptParser::Assignment_adv_logContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_adv_log(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_adv_logContext* ExplorerScriptParser::assignment_adv_log() {
  Assignment_adv_logContext *_localctx = _tracker.createInstance<Assignment_adv_logContext>(_ctx, getState());
  enterRule(_localctx, 80, ExplorerScriptParser::RuleAssignment_adv_log);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
    match(ExplorerScriptParser::ADVENTURE_LOG);
    setState(500);
    match(ExplorerScriptParser::ASSIGN);
    setState(501);
    primitive();
   
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

std::vector<ExplorerScriptParser::PrimitiveContext *> ExplorerScriptParser::Assignment_dungeon_modeContext::primitive() {
  return getRuleContexts<ExplorerScriptParser::PrimitiveContext>();
}

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Assignment_dungeon_modeContext::primitive(size_t i) {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(i);
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


std::any ExplorerScriptParser::Assignment_dungeon_modeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_dungeon_mode(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_dungeon_modeContext* ExplorerScriptParser::assignment_dungeon_mode() {
  Assignment_dungeon_modeContext *_localctx = _tracker.createInstance<Assignment_dungeon_modeContext>(_ctx, getState());
  enterRule(_localctx, 82, ExplorerScriptParser::RuleAssignment_dungeon_mode);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    match(ExplorerScriptParser::DUNGEON_MODE);
    setState(504);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(505);
    primitive();
    setState(506);
    match(ExplorerScriptParser::CLOSE_PAREN);
    setState(507);
    match(ExplorerScriptParser::ASSIGN);
    setState(508);
    primitive();
   
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Assignment_scnContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
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


std::any ExplorerScriptParser::Assignment_scnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssignment_scn(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assignment_scnContext* ExplorerScriptParser::assignment_scn() {
  Assignment_scnContext *_localctx = _tracker.createInstance<Assignment_scnContext>(_ctx, getState());
  enterRule(_localctx, 84, ExplorerScriptParser::RuleAssignment_scn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(510);
    primitive();
    setState(511);
    match(ExplorerScriptParser::ASSIGN);
    setState(512);
    match(ExplorerScriptParser::SCN);
    setState(513);
    match(ExplorerScriptParser::OPEN_BRACKET);
    setState(514);
    match(ExplorerScriptParser::INTEGER);
    setState(515);
    match(ExplorerScriptParser::COMMA);
    setState(516);
    match(ExplorerScriptParser::INTEGER);
    setState(517);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Value_ofContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Value_ofContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Value_ofContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleValue_of;
}


std::any ExplorerScriptParser::Value_ofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitValue_of(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Value_ofContext* ExplorerScriptParser::value_of() {
  Value_ofContext *_localctx = _tracker.createInstance<Value_ofContext>(_ctx, getState());
  enterRule(_localctx, 86, ExplorerScriptParser::RuleValue_of);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(519);
    match(ExplorerScriptParser::VALUE);
    setState(520);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(521);
    primitive();
    setState(522);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Scn_varContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}

tree::TerminalNode* ExplorerScriptParser::Scn_varContext::CLOSE_PAREN() {
  return getToken(ExplorerScriptParser::CLOSE_PAREN, 0);
}


size_t ExplorerScriptParser::Scn_varContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleScn_var;
}


std::any ExplorerScriptParser::Scn_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitScn_var(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Scn_varContext* ExplorerScriptParser::scn_var() {
  Scn_varContext *_localctx = _tracker.createInstance<Scn_varContext>(_ctx, getState());
  enterRule(_localctx, 88, ExplorerScriptParser::RuleScn_var);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(524);
    match(ExplorerScriptParser::SCN);
    setState(525);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(526);
    primitive();
    setState(527);
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


std::any ExplorerScriptParser::Conditional_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitConditional_operator(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Conditional_operatorContext* ExplorerScriptParser::conditional_operator() {
  Conditional_operatorContext *_localctx = _tracker.createInstance<Conditional_operatorContext>(_ctx, getState());
  enterRule(_localctx, 90, ExplorerScriptParser::RuleConditional_operator);
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
    setState(529);
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


std::any ExplorerScriptParser::Assign_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitAssign_operator(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Assign_operatorContext* ExplorerScriptParser::assign_operator() {
  Assign_operatorContext *_localctx = _tracker.createInstance<Assign_operatorContext>(_ctx, getState());
  enterRule(_localctx, 92, ExplorerScriptParser::RuleAssign_operator);
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


std::any ExplorerScriptParser::FuncdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFuncdef(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::FuncdefContext* ExplorerScriptParser::funcdef() {
  FuncdefContext *_localctx = _tracker.createInstance<FuncdefContext>(_ctx, getState());
  enterRule(_localctx, 94, ExplorerScriptParser::RuleFuncdef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(536);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(533);
      coro_def();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(534);
      simple_def();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(535);
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


std::any ExplorerScriptParser::Simple_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitSimple_def(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Simple_defContext* ExplorerScriptParser::simple_def() {
  Simple_defContext *_localctx = _tracker.createInstance<Simple_defContext>(_ctx, getState());
  enterRule(_localctx, 96, ExplorerScriptParser::RuleSimple_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    match(ExplorerScriptParser::DEF);
    setState(539);
    match(ExplorerScriptParser::INTEGER);
    setState(540);
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


std::any ExplorerScriptParser::Coro_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCoro_def(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Coro_defContext* ExplorerScriptParser::coro_def() {
  Coro_defContext *_localctx = _tracker.createInstance<Coro_defContext>(_ctx, getState());
  enterRule(_localctx, 98, ExplorerScriptParser::RuleCoro_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(542);
    match(ExplorerScriptParser::CORO);
    setState(543);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(544);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::For_target_defContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
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


std::any ExplorerScriptParser::For_target_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFor_target_def(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::For_target_defContext* ExplorerScriptParser::for_target_def() {
  For_target_defContext *_localctx = _tracker.createInstance<For_target_defContext>(_ctx, getState());
  enterRule(_localctx, 100, ExplorerScriptParser::RuleFor_target_def);
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
    setState(546);
    match(ExplorerScriptParser::DEF);
    setState(547);
    match(ExplorerScriptParser::INTEGER);
    setState(548);
    for_target_def_target();
    setState(550);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::OPEN_PAREN) {
      setState(549);
      match(ExplorerScriptParser::OPEN_PAREN);
    }
    setState(552);
    primitive();
    setState(554);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::CLOSE_PAREN) {
      setState(553);
      match(ExplorerScriptParser::CLOSE_PAREN);
    }
    setState(556);
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

ExplorerScriptParser::PrimitiveContext::PrimitiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExplorerScriptParser::PrimitiveContext::DECIMAL() {
  return getToken(ExplorerScriptParser::DECIMAL, 0);
}

tree::TerminalNode* ExplorerScriptParser::PrimitiveContext::INTEGER() {
  return getToken(ExplorerScriptParser::INTEGER, 0);
}

tree::TerminalNode* ExplorerScriptParser::PrimitiveContext::IDENTIFIER() {
  return getToken(ExplorerScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExplorerScriptParser::PrimitiveContext::VARIABLE() {
  return getToken(ExplorerScriptParser::VARIABLE, 0);
}

ExplorerScriptParser::StringContext* ExplorerScriptParser::PrimitiveContext::string() {
  return getRuleContext<ExplorerScriptParser::StringContext>(0);
}


size_t ExplorerScriptParser::PrimitiveContext::getRuleIndex() const {
  return ExplorerScriptParser::RulePrimitive;
}


std::any ExplorerScriptParser::PrimitiveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitPrimitive(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::primitive() {
  PrimitiveContext *_localctx = _tracker.createInstance<PrimitiveContext>(_ctx, getState());
  enterRule(_localctx, 102, ExplorerScriptParser::RulePrimitive);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(563);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::DECIMAL: {
        enterOuterAlt(_localctx, 1);
        setState(558);
        match(ExplorerScriptParser::DECIMAL);
        break;
      }

      case ExplorerScriptParser::INTEGER: {
        enterOuterAlt(_localctx, 2);
        setState(559);
        match(ExplorerScriptParser::INTEGER);
        break;
      }

      case ExplorerScriptParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(560);
        match(ExplorerScriptParser::IDENTIFIER);
        break;
      }

      case ExplorerScriptParser::VARIABLE: {
        enterOuterAlt(_localctx, 4);
        setState(561);
        match(ExplorerScriptParser::VARIABLE);
        break;
      }

      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 5);
        setState(562);
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


std::any ExplorerScriptParser::OperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitOperation(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::OperationContext* ExplorerScriptParser::operation() {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState());
  enterRule(_localctx, 104, ExplorerScriptParser::RuleOperation);
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
    setState(565);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(567);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::OPEN_SHARP) {
      setState(566);
      inline_ctx();
    }
    setState(569);
    match(ExplorerScriptParser::OPEN_PAREN);
    setState(571);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 59) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 59)) & 671135747) != 0)) {
      setState(570);
      arglist();
    }
    setState(573);
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


std::any ExplorerScriptParser::Inline_ctxContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitInline_ctx(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Inline_ctxContext* ExplorerScriptParser::inline_ctx() {
  Inline_ctxContext *_localctx = _tracker.createInstance<Inline_ctxContext>(_ctx, getState());
  enterRule(_localctx, 106, ExplorerScriptParser::RuleInline_ctx);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(575);
    match(ExplorerScriptParser::OPEN_SHARP);
    setState(576);
    ctx_header();
    setState(577);
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


std::any ExplorerScriptParser::Func_suiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFunc_suite(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Func_suiteContext* ExplorerScriptParser::func_suite() {
  Func_suiteContext *_localctx = _tracker.createInstance<Func_suiteContext>(_ctx, getState());
  enterRule(_localctx, 108, ExplorerScriptParser::RuleFunc_suite);
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
    setState(579);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(586);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::JUMP:
      case ExplorerScriptParser::CALL:
      case ExplorerScriptParser::CONST:
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
      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::FOR:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::MACRO_CALL:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::AT:
      case ExplorerScriptParser::PARAGRAPH:
      case ExplorerScriptParser::OPEN_BRACE:
      case ExplorerScriptParser::DECIMAL: {
        setState(581); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(580);
          stmt();
          setState(583); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1866469503876988928) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 68)) & 1507449) != 0));
        break;
      }

      case ExplorerScriptParser::ALIAS: {
        setState(585);
        func_alias();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(588);
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


std::any ExplorerScriptParser::Func_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFunc_alias(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Func_aliasContext* ExplorerScriptParser::func_alias() {
  Func_aliasContext *_localctx = _tracker.createInstance<Func_aliasContext>(_ctx, getState());
  enterRule(_localctx, 110, ExplorerScriptParser::RuleFunc_alias);

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
    match(ExplorerScriptParser::ALIAS);
    setState(591);
    match(ExplorerScriptParser::PREVIOUS);
    setState(592);
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


std::any ExplorerScriptParser::ArglistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitArglist(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::ArglistContext* ExplorerScriptParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 112, ExplorerScriptParser::RuleArglist);
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
    setState(594);
    pos_argument();
    setState(599);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(595);
        match(ExplorerScriptParser::COMMA);
        setState(596);
        pos_argument(); 
      }
      setState(601);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    }
    setState(603);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::COMMA) {
      setState(602);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Pos_argumentContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}

ExplorerScriptParser::Position_markerContext* ExplorerScriptParser::Pos_argumentContext::position_marker() {
  return getRuleContext<ExplorerScriptParser::Position_markerContext>(0);
}


size_t ExplorerScriptParser::Pos_argumentContext::getRuleIndex() const {
  return ExplorerScriptParser::RulePos_argument;
}


std::any ExplorerScriptParser::Pos_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitPos_argument(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Pos_argumentContext* ExplorerScriptParser::pos_argument() {
  Pos_argumentContext *_localctx = _tracker.createInstance<Pos_argumentContext>(_ctx, getState());
  enterRule(_localctx, 114, ExplorerScriptParser::RulePos_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(607);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL:
      case ExplorerScriptParser::IDENTIFIER:
      case ExplorerScriptParser::VARIABLE:
      case ExplorerScriptParser::INTEGER:
      case ExplorerScriptParser::OPEN_BRACE:
      case ExplorerScriptParser::DECIMAL: {
        enterOuterAlt(_localctx, 1);
        setState(605);
        primitive();
        break;
      }

      case ExplorerScriptParser::POSITION: {
        enterOuterAlt(_localctx, 2);
        setState(606);
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


std::any ExplorerScriptParser::Position_markerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitPosition_marker(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Position_markerContext* ExplorerScriptParser::position_marker() {
  Position_markerContext *_localctx = _tracker.createInstance<Position_markerContext>(_ctx, getState());
  enterRule(_localctx, 116, ExplorerScriptParser::RulePosition_marker);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(609);
    match(ExplorerScriptParser::POSITION);
    setState(610);
    match(ExplorerScriptParser::OPEN_SHARP);
    setState(611);
    match(ExplorerScriptParser::STRING_LITERAL);
    setState(612);
    match(ExplorerScriptParser::COMMA);
    setState(613);
    position_marker_arg();
    setState(614);
    match(ExplorerScriptParser::COMMA);
    setState(615);
    position_marker_arg();
    setState(616);
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


std::any ExplorerScriptParser::Position_marker_argContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitPosition_marker_arg(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Position_marker_argContext* ExplorerScriptParser::position_marker_arg() {
  Position_marker_argContext *_localctx = _tracker.createInstance<Position_marker_argContext>(_ctx, getState());
  enterRule(_localctx, 118, ExplorerScriptParser::RulePosition_marker_arg);
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
    setState(618);
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


std::any ExplorerScriptParser::LabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitLabel(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::LabelContext* ExplorerScriptParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 120, ExplorerScriptParser::RuleLabel);
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
    setState(620);
    _la = _input->LA(1);
    if (!(_la == ExplorerScriptParser::AT

    || _la == ExplorerScriptParser::PARAGRAPH)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(621);
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


std::any ExplorerScriptParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::StringContext* ExplorerScriptParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 122, ExplorerScriptParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(625);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::STRING_LITERAL:
      case ExplorerScriptParser::MULTILINE_STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(623);
        string_value();
        break;
      }

      case ExplorerScriptParser::OPEN_BRACE: {
        enterOuterAlt(_localctx, 2);
        setState(624);
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


std::any ExplorerScriptParser::Lang_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitLang_string(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Lang_stringContext* ExplorerScriptParser::lang_string() {
  Lang_stringContext *_localctx = _tracker.createInstance<Lang_stringContext>(_ctx, getState());
  enterRule(_localctx, 124, ExplorerScriptParser::RuleLang_string);
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
    setState(627);
    match(ExplorerScriptParser::OPEN_BRACE);
    setState(628);
    lang_string_argument();
    setState(633);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(629);
        match(ExplorerScriptParser::COMMA);
        setState(630);
        lang_string_argument(); 
      }
      setState(635);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
    }
    setState(637);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExplorerScriptParser::COMMA) {
      setState(636);
      match(ExplorerScriptParser::COMMA);
    }
    setState(639);
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


std::any ExplorerScriptParser::Lang_string_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitLang_string_argument(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Lang_string_argumentContext* ExplorerScriptParser::lang_string_argument() {
  Lang_string_argumentContext *_localctx = _tracker.createInstance<Lang_string_argumentContext>(_ctx, getState());
  enterRule(_localctx, 126, ExplorerScriptParser::RuleLang_string_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(641);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(642);
    match(ExplorerScriptParser::ASSIGN);
    setState(643);
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


std::any ExplorerScriptParser::String_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitString_value(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::String_valueContext* ExplorerScriptParser::string_value() {
  String_valueContext *_localctx = _tracker.createInstance<String_valueContext>(_ctx, getState());
  enterRule(_localctx, 128, ExplorerScriptParser::RuleString_value);
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
    setState(645);
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

ExplorerScriptParser::PrimitiveContext* ExplorerScriptParser::Ctx_headerContext::primitive() {
  return getRuleContext<ExplorerScriptParser::PrimitiveContext>(0);
}


size_t ExplorerScriptParser::Ctx_headerContext::getRuleIndex() const {
  return ExplorerScriptParser::RuleCtx_header;
}


std::any ExplorerScriptParser::Ctx_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitCtx_header(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::Ctx_headerContext* ExplorerScriptParser::ctx_header() {
  Ctx_headerContext *_localctx = _tracker.createInstance<Ctx_headerContext>(_ctx, getState());
  enterRule(_localctx, 130, ExplorerScriptParser::RuleCtx_header);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(647);
    match(ExplorerScriptParser::IDENTIFIER);
    setState(648);
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


std::any ExplorerScriptParser::For_target_def_targetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExplorerScriptVisitor*>(visitor))
    return parserVisitor->visitFor_target_def_target(this);
  else
    return visitor->visitChildren(this);
}

ExplorerScriptParser::For_target_def_targetContext* ExplorerScriptParser::for_target_def_target() {
  For_target_def_targetContext *_localctx = _tracker.createInstance<For_target_def_targetContext>(_ctx, getState());
  enterRule(_localctx, 132, ExplorerScriptParser::RuleFor_target_def_target);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(653);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExplorerScriptParser::FOR: {
        enterOuterAlt(_localctx, 1);
        setState(650);
        match(ExplorerScriptParser::FOR);
        setState(651);
        match(ExplorerScriptParser::IDENTIFIER);
        break;
      }

      case ExplorerScriptParser::FOR_TARGET: {
        enterOuterAlt(_localctx, 2);
        setState(652);
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
