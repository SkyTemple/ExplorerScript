#include "parser_wrapper_ssbs.h"

using namespace std;
using namespace antlr4;

SsbScriptParserWrapper::SsbScriptParserWrapper(std::string& string, ANTLRErrorListener* listener) {
    this->input = new ANTLRInputStream(string);
    this->lexer = new SsbScriptLexer(input);
    this->tokens = new CommonTokenStream(lexer);
    this->parser = new SsbScriptParser(tokens);
    this->parser->getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);
    this->parser->removeErrorListeners();
    this->parser->addErrorListener(listener);
    this->tree = this->parser->start();
}

SsbScriptParserWrapper::~SsbScriptParserWrapper() {
    delete this->parser;
    delete this->tokens;
    delete this->lexer;
    delete this->input;
}

SsbScriptParser::StartContext* SsbScriptParserWrapper::getTree() {
    return this->tree;
}

pybind11::object SsbScriptParserWrapper::traverse(SsbScriptBaseVisitor& visitor) {
    auto ret = this->tree->accept(&visitor);
    return std::any_cast<pybind11::object>(ret);
}
