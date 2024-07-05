# Makefile for generating files.
# Does NOT install the Python package or dependencies.
# Make sure to install those first.
# Make sure the Antlr4 version used matches the one of the runtime package!

.PHONY := all exps ssbscript
.DEFAULT_GOAL := all

explorerscript/antlr/ExplorerScript.interp explorerscript/antlr/ExplorerScript.tokens explorerscript/antlr/ExplorerScriptLexer.interp explorerscript/antlr/ExplorerScriptLexer.py explorerscript/antlr/ExplorerScriptLexer.tokens explorerscript/antlr/ExplorerScriptListener.py explorerscript/antlr/ExplorerScriptParser.py explorerscript/antlr/ExplorerScriptVisitor.py: explorerscript/antlr/ExplorerScript.g4
	cd explorerscript/antlr && antlr4 -Dlanguage=Python3 -visitor ExplorerScript.g4

explorerscript/antlr/SsbScript.interp explorerscript/antlr/SsbScript.tokens explorerscript/antlr/SsbScriptLexer.interp explorerscript/antlr/SsbScriptLexer.py explorerscript/antlr/SsbScriptLexer.tokens explorerscript/antlr/SsbScriptListener.py explorerscript/antlr/SsbScriptParser.py: explorerscript/antlr/SsbScript.g4
	cd explorerscript/antlr && antlr4 -Dlanguage=Python3 SsbScript.g4

exps: explorerscript/antlr/ExplorerScriptParser.py

ssbscript: explorerscript/antlr/SsbScriptParser.py

all: exps ssbscript
