#!/usr/bin/env python3
import os.path

# TODO. Needs to generate explorerscript_parser/pybind_explorerscript_parser.cpp

with open(
    os.path.abspath(os.path.dirname(__file__) + "/explorerscript_parser/pybind_explorerscript_parser.cpp"), "w"
) as f:
    f.write("""#include <pybind11/pybind11.h>

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(explorerscript_parser, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
}
""")
