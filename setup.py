from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

ext_modules = [
    Pybind11Extension(
        "explorerscript_parser",
        [
            "explorerscript_parser/ExplorerScriptLexer.cpp",
            "explorerscript_parser/ExplorerScriptParser.cpp",
            "explorerscript_parser/ExplorerScriptVisitor.cpp",
            "explorerscript_parser/parser_wrapper.cpp",
            "explorerscript_parser/pybind_explorerscript_parser.cpp",
        ],
        define_macros=[],
        include_dirs=["/opt/homebrew/include", "/opt/homebrew/include/antlr4-runtime"],
        library_dirs=["/opt/homebrew/lib"],
        libraries=["antlr4-runtime"]
    ),
]

setup(ext_modules=ext_modules, cmdclass={"build_ext": build_ext}, zip_safe=False)
