#pragma once

#include "antlr4-runtime.h"
#include "SsbScriptLexer.h"
#include "SsbScriptParser.h"
#include "SsbScriptBaseVisitor.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

class SsbScriptParserWrapper {
    antlr4::ANTLRInputStream* input;
    SsbScriptLexer* lexer;
    antlr4::CommonTokenStream* tokens;
    SsbScriptParser* parser;
    SsbScriptParser::StartContext* tree;
public:
    SsbScriptParserWrapper(std::string& string, antlr4::ANTLRErrorListener* listener);
    ~SsbScriptParserWrapper();

    SsbScriptParser::StartContext* getTree();
    pybind11::object traverse(SsbScriptBaseVisitor& visitor);
};
