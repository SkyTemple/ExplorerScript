#pragma once

#include "antlr4-runtime.h"
#include "ExplorerScriptLexer.h"
#include "ExplorerScriptParser.h"
#include "ExplorerScriptBaseVisitor.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

class ExplorerScriptParserWrapper {
    antlr4::ANTLRInputStream* input;
    ExplorerScriptLexer* lexer;
    antlr4::CommonTokenStream* tokens;
    ExplorerScriptParser* parser;
public:
    ExplorerScriptParserWrapper(std::string& string);
    ~ExplorerScriptParserWrapper();

    ExplorerScriptParser::StartContext* tree();
    pybind11::object traverse(ExplorerScriptBaseVisitor& visitor);
};
