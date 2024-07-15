#include "parser_wrapper_ssbs.h"

using namespace std;
using namespace antlr4;

SsbScriptParserWrapper::SsbScriptParserWrapper(std::string& string) {
    this->input = new ANTLRInputStream(string);
    this->lexer = new SsbScriptLexer(input);
    this->tokens = new CommonTokenStream(lexer);
    this->parser = new SsbScriptParser(tokens);
}

SsbScriptParserWrapper::~SsbScriptParserWrapper() {
    delete this->parser;
    delete this->tokens;
    delete this->lexer;
    delete this->input;
}

SsbScriptParser::StartContext* SsbScriptParserWrapper::tree() {
    return this->parser->start();
}

pybind11::object SsbScriptParserWrapper::traverse(SsbScriptBaseVisitor& visitor) {
    auto ret = this->tree()->accept(&visitor);
    return std::any_cast<pybind11::object>(ret);
}

void SsbScriptParserWrapper::addErrorListener(ANTLRErrorListener &listener) {
    this->parser->addErrorListener(&listener);
}
