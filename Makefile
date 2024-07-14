# Makefile for generating files.
# Does NOT install the Python package or dependencies.
# Make sure to install those first.
# Make sure the Antlr4 version used matches the one of the runtime package!

.PHONY := all exps ssbscript explorerscript-installed
.DEFAULT_GOAL := all

explorerscript_parser/ExplorerScript.interp explorerscript_parser/ExplorerScript.tokens explorerscript_parser/ExplorerScriptLexer.interp explorerscript_parser/ExplorerScriptLexer.h explorerscript_parser/ExplorerScriptLexer.cpp explorerscript_parser/ExplorerScriptLexer.tokens explorerscript_parser/ExplorerScriptListener.h explorerscript_parser/ExplorerScriptListener.cpp explorerscript_parser/ExplorerScriptParser.h explorerscript_parser/ExplorerScriptParser.cpp explorerscript_parser/ExplorerScriptVisitor.h explorerscript_parser/ExplorerScriptVisitor.cpp: explorerscript_parser/ExplorerScript.g4 explorerscript_parser/SsbCommon.g4
	cd explorerscript_parser && antlr4 -Dlanguage=Cpp -visitor ExplorerScript.g4

explorerscript_parser/SsbScript.interp explorerscript_parser/SsbScript.tokens explorerscript_parser/SsbScriptLexer.interp explorerscript_parser/SsbScriptLexer.h explorerscript_parser/SsbScriptLexer.cpp explorerscript_parser/SsbScriptLexer.tokens explorerscript_parser/SsbScriptListener.h explorerscript_parser/SsbScriptListener.cpp explorerscript_parser/SsbScriptParser.h explorerscript_parser/SsbScriptParser.cpp: explorerscript_parser/SsbScript.g4 explorerscript_parser/SsbCommon.g4
	cd explorerscript_parser && antlr4 -Dlanguage=Cpp SsbScript.g4

exps: explorerscript_parser/ExplorerScriptParser.cpp

ssbscript: explorerscript_parser/SsbScriptParser.cpp

explorerscript_parser/pybind_explorerscript_parser.cpp: explorerscript_parser/ExplorerScriptLexer.h explorerscript_parser/ExplorerScriptListener.h explorerscript_parser/ExplorerScriptParser.h explorerscript_parser/ExplorerScriptVisitor.h explorerscript_parser/SsbScriptLexer.h explorerscript_parser/SsbScriptListener.h explorerscript_parser/SsbScriptParser.h generate_parser_bindings.py
	./generate_parser_bindings.py

explorerscript-installed: explorerscript_parser/pybind_explorerscript_parser.cpp ExternalAntlr4Cpp.cmake CMakeLists.txt pyproject.toml setup.py
	touch explorerscript_parser/__init__.pyi
	pip install .

explorerscript_parser/__init__.pyi: explorerscript_parser/pybind_explorerscript_parser.cpp explorerscript-installed
	pybind11-stubgen -o explorerscript_parser explorerscript_parser
	rm -rf explorerscript_parser/__init__.pyi
	mv explorerscript_parser/explorerscript_parser.pyi explorerscript_parser/__init__.pyi

all: exps ssbscript explorerscript_parser/pybind_explorerscript_parser.cpp explorerscript_parser/__init__.pyi
