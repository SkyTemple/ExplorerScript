#pragma once

#include "antlr4-runtime.h"
#include "ExplorerScriptLexer.h"
#include "ExplorerScriptParser.h"
#include "ExplorerScriptVisitor.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

class ParserWrapper {
    antlr4::ANTLRInputStream* input;
    ExplorerScriptLexer* lexer;
    antlr4::CommonTokenStream* tokens;
    ExplorerScriptParser* parser;
public:
    ParserWrapper(std::string& string);
    ~ParserWrapper();

    ExplorerScriptParser::StartContext* tree();
    pybind11::object traverse(ExplorerScriptVisitor& visitor);
};
