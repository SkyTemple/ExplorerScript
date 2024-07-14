#include "parser_wrapper.h"

using namespace std;
using namespace antlr4;
using namespace chrono;

ParserWrapper::ParserWrapper(std::string& string) {
    this->input = new ANTLRInputStream(string);
    this->lexer = new ExplorerScriptLexer(input);
    this->tokens = new CommonTokenStream(lexer);
    this->parser = new ExplorerScriptParser(tokens);
}

ParserWrapper::~ParserWrapper() {
    // TODO: freeing the memory leads to a segmentation fault if the
    // tree was ever referenced in Python :(
    // See https://pybind11.readthedocs.io/en/stable/advanced/functions.html#return-value-policies

    printf("Deleting parser wrapper\n");
    delete this->parser;
    delete this->tokens;
    delete this->lexer;
    delete this->input;
}

ExplorerScriptParser::StartContext* ParserWrapper::tree() {
    return this->parser->start();
}

void ParserWrapper::traverse(ExplorerScriptVisitor& visitor) {
    this->tree()->accept(&visitor);
}
