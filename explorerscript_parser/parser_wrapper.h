#pragma once

#include "antlr4-runtime/antlr4-runtime.h"
#include "ExplorerScriptLexer.h"
#include "ExplorerScriptParser.h"
#include "ExplorerScriptVisitor.h"

class ParserWrapper {
    antlr4::ANTLRInputStream* input;
    ExplorerScriptLexer* lexer;
    antlr4::CommonTokenStream* tokens;
    ExplorerScriptParser* parser;
public:
    ParserWrapper(std::string& string);
    ~ParserWrapper();

    ExplorerScriptParser::StartContext* tree();
    void traverse(ExplorerScriptVisitor& visitor);
};
