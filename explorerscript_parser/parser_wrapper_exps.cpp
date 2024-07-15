#include "parser_wrapper_exps.h"

using namespace std;
using namespace antlr4;

ExplorerScriptParserWrapper::ExplorerScriptParserWrapper(std::string& string) {
    this->input = new ANTLRInputStream(string);
    this->lexer = new ExplorerScriptLexer(input);
    this->tokens = new CommonTokenStream(lexer);
    this->parser = new ExplorerScriptParser(tokens);
}

ExplorerScriptParserWrapper::~ExplorerScriptParserWrapper() {
    delete this->parser;
    delete this->tokens;
    delete this->lexer;
    delete this->input;
}

ExplorerScriptParser::StartContext* ExplorerScriptParserWrapper::tree() {
    return this->parser->start();
}

pybind11::object ExplorerScriptParserWrapper::traverse(ExplorerScriptBaseVisitor& visitor) {
    auto ret = this->tree()->accept(&visitor);
    return std::any_cast<pybind11::object>(ret);
}

void ExplorerScriptParserWrapper::addErrorListener(ANTLRErrorListener &listener) {
    this->parser->addErrorListener(&listener);
}
