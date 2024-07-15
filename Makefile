# Makefile for generating files.
# Does NOT install the Python package or dependencies.
# Make sure to install those first.
# Make sure the Antlr4 version used matches the one of the runtime package!

.PHONY := all exps ssbscript explorerscript-installed
.DEFAULT_GOAL := all

explorerscript_parser/ExplorerScript.interp explorerscript_parser/ExplorerScript.tokens explorerscript_parser/ExplorerScriptLexer.interp explorerscript_parser/ExplorerScriptLexer.h explorerscript_parser/ExplorerScriptLexer.cpp explorerscript_parser/ExplorerScriptLexer.tokens explorerscript_parser/ExplorerScriptParser.h explorerscript_parser/ExplorerScriptParser.cpp explorerscript_parser/ExplorerScriptVisitor.h explorerscript_parser/ExplorerScriptVisitor.cpp: explorerscript_parser/ExplorerScript.g4 explorerscript_parser/SsbCommon.g4
	cd explorerscript_parser && antlr4 -Dlanguage=Cpp -no-listener -visitor ExplorerScript.g4

explorerscript_parser/SsbScript.interp explorerscript_parser/SsbScript.tokens explorerscript_parser/SsbScriptLexer.interp explorerscript_parser/SsbScriptLexer.h explorerscript_parser/SsbScriptLexer.cpp explorerscript_parser/SsbScriptLexer.tokens explorerscript_parser/SsbScriptParser.h explorerscript_parser/SsbScriptParser.cpp: explorerscript_parser/SsbScript.g4 explorerscript_parser/SsbCommon.g4
	cd explorerscript_parser && antlr4 -Dlanguage=Cpp -no-listener -visitor SsbScript.g4

exps: explorerscript_parser/ExplorerScriptParser.cpp

ssbscript: explorerscript_parser/SsbScriptParser.cpp

explorerscript_parser/pybind_explorerscript_parser.cpp explorerscript_parser/__init__.pyi: explorerscript_parser/ExplorerScriptLexer.h explorerscript_parser/ExplorerScriptParser.h explorerscript_parser/ExplorerScriptVisitor.h explorerscript_parser/SsbScriptLexer.h explorerscript_parser/SsbScriptParser.h generate_parser_bindings.py
	./generate_parser_bindings.py
	ruff format explorerscript_parser/__init__.pyi

explorerscript-installed: explorerscript_parser/pybind_explorerscript_parser.cpp ExternalAntlr4Cpp.cmake CMakeLists.txt pyproject.toml setup.py
	pip install .

all: exps ssbscript explorerscript_parser/pybind_explorerscript_parser.cpp explorerscript_parser/__init__.pyi explorerscript-installed
