#include "parser_wrapper_exps.h"

using namespace std;
using namespace antlr4;

ExplorerScriptParserWrapper::ExplorerScriptParserWrapper(std::string& string, ANTLRErrorListener* listener) {
    this->input = new ANTLRInputStream(string);
    this->lexer = new ExplorerScriptLexer(input);
    this->tokens = new CommonTokenStream(lexer);
    this->parser = new ExplorerScriptParser(tokens);
    this->parser->getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);
    this->parser->removeErrorListeners();
    this->parser->addErrorListener(listener);
    this->tree = this->parser->start();
}

ExplorerScriptParserWrapper::~ExplorerScriptParserWrapper() {
    delete this->parser;
    delete this->tokens;
    delete this->lexer;
    delete this->input;
}

ExplorerScriptParser::StartContext* ExplorerScriptParserWrapper::getTree() {
    return this->tree;
}

pybind11::object ExplorerScriptParserWrapper::traverse(ExplorerScriptBaseVisitor& visitor) {
    auto ret = this->tree->accept(&visitor);
    return std::any_cast<pybind11::object>(ret);
}
