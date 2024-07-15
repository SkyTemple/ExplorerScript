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
    // TODO: freeing the memory leads to a segmentation fault if the
    // tree was ever referenced in Python :(
    // See https://pybind11.readthedocs.io/en/stable/advanced/functions.html#return-value-policies

    printf("Deleting parser wrapper\n");
    delete this->parser;
    delete this->tokens;
    delete this->lexer;
    delete this->input;
}

SsbScriptParser::StartContext* SsbScriptParserWrapper::tree() {
    return this->parser->start();
}

pybind11::object SsbScriptParserWrapper::traverse(SsbScriptVisitor& visitor) {
    auto ret = this->tree()->accept(&visitor);
    return std::any_cast<pybind11::object>(ret);
}
