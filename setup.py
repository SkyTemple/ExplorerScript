from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

ext_modules = [
    Pybind11Extension(
        "explorerscript_parser",
        ["explorerscript_parser/pybind_explorerscript_parser.cpp"],
        define_macros=[],
    ),
]

setup(ext_modules=ext_modules, cmdclass={"build_ext": build_ext}, zip_safe=False)
