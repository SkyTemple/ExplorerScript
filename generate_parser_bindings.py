#!/usr/bin/env python3
import os.path
import re


def extract_classes(header_file_content):
    class_regex = re.compile(r"class\s+(\w+)\s*:\s*public\s+antlr4::ParserRuleContext\s*{")
    method_regex = re.compile(r"^\s*(virtual)?\s*([\w:<>* ]+)\s+\*?([\w]+)\s*\(([^)]*)\)\s*(const)?\s*(override)?\s*;")
    end_class_regex = re.compile(r"^\s*};")

    classes = {}

    current_class = None
    for line in header_file_content.splitlines():
        if current_class:
            end_class_match = end_class_regex.search(line)
            if end_class_match:
                current_class = None
                continue

        class_match = class_regex.search(line)
        if class_match:
            current_class = class_match.group(1)
            classes[current_class] = []
        elif current_class:
            method_match = method_regex.search(line)
            if method_match:
                _, return_type, method_name, params, _, _ = method_match.groups()
                if method_name != current_class:
                    classes[current_class].append(
                        {
                            "return_type": return_type,
                            "method_name": method_name,
                            "params": params.strip(),
                        }
                    )

    return classes


def generate_bindings(classes, visitor_methods):
    bindings = []

    for class_name, methods in classes.items():
        class_name = f"ExplorerScriptParser::{class_name}"
        bindings.append(f'py::class_<{class_name}, antlr4::ParserRuleContext>(m, "{class_name}")')
        bindings.append("    .def(py::init<antlr4::ParserRuleContext*, size_t>())")
        bindings.append(f'    .def("__str__", py::overload_cast<>(&{class_name}::toString))')
        bindings.append(f'    .def("to_string_tree", py::overload_cast<bool>(&{class_name}::toStringTree))')

        grouped_methods = {}
        for method in methods:
            if method["method_name"] not in grouped_methods:
                grouped_methods[method["method_name"]] = []
            grouped_methods[method["method_name"]].append(method)

        for method_name, overloads in grouped_methods.items():
            if len(overloads) > 1:
                for method in overloads:
                    if method["params"]:
                        bindings.append(
                            f'    .def("{method_name}", py::overload_cast<{method["params"].split(' ')[0]}>(&{class_name}::{method_name}))'
                        )
                    else:
                        bindings.append(f'    .def("{method_name}", py::overload_cast<>(&{class_name}::{method_name}))')
            else:
                method = overloads[0]
                bindings.append(f'    .def("{method_name}", &{class_name}::{method_name})')

        bindings.append(";")

    bindings.append('py::class_<ExplorerScriptVisitor, PyExplorerScriptVisitor>(m, "ExplorerScriptVisitor")')
    bindings.append("    .def(py::init<>())")
    bindings.append(
        '    .def("visitChildren", [](ExplorerScriptVisitor& self, antlr4::tree::ParseTree* node) {'
    )  # todo
    bindings.append("        return std::any_cast<pybind11::object>(self.visitChildren(node));")
    bindings.append("    })")
    bindings.append('    .def("defaultResult", [](ExplorerScriptVisitor& self) {')
    bindings.append("        return std::any_cast<pybind11::object>(self.defaultResult());")
    bindings.append("    })")
    for method in visitor_methods:
        bindings.append(f'    .def("{method["method_name"]}", &ExplorerScriptVisitor::{method["method_name"]})')
    bindings.append(";")

    return "\n".join(bindings)


def extract_visitor_methods(header_file_content):
    method_regex = re.compile(r"\s+virtual\s+std::any\s+(\w+)\s*\(([^)]*)\)\s*=\s*0;")
    visitor_methods = []

    for line in header_file_content.splitlines():
        method_match = method_regex.search(line)
        if method_match:
            method_name, params = method_match.groups()
            visitor_methods.append({"method_name": method_name, "params": params.strip()})

    return visitor_methods


def generate_trampoline_class(visitor_methods):
    trampoline_class = []

    trampoline_class.append("class PyExplorerScriptVisitor : public ExplorerScriptVisitor {")
    trampoline_class.append("public:")
    trampoline_class.append("    /* Inherit the constructors */")
    trampoline_class.append("    using ExplorerScriptVisitor::ExplorerScriptVisitor;")
    trampoline_class.append("")

    for method in visitor_methods:
        method_name = method["method_name"]
        params = method["params"]
        trampoline_class.append(f"    pybind11::object {method_name}__wrapper({params}) {{")
        trampoline_class.append("        PYBIND11_OVERRIDE_PURE(")
        trampoline_class.append("            pybind11::object,")  # Return type
        trampoline_class.append("            ExplorerScriptVisitor,")  # Parent class
        trampoline_class.append(f"            {method_name},")
        trampoline_class.append(f'            {params.split(' ')[1].lstrip('*')}')
        trampoline_class.append("        );")
        trampoline_class.append("    }")
        trampoline_class.append(f"    std::any {method_name}({params}) override {{")
        trampoline_class.append(f'        return {method_name}__wrapper({params.split(' ')[1].lstrip('*')});')
        trampoline_class.append("    }")

    trampoline_class.append("    std::any defaultResult() override {")
    trampoline_class.append("        PYBIND11_OVERRIDE_PURE(")
    trampoline_class.append("            pybind11::object,")  # Return type
    trampoline_class.append("            ExplorerScriptVisitor,")  # Parent class
    trampoline_class.append("            defaultResult")
    trampoline_class.append("        );")
    trampoline_class.append("    }")

    trampoline_class.append("};")

    return "\n".join(trampoline_class)


with open("explorerscript_parser/ExplorerScriptParser.h", "r") as f:
    header_file_content = f.read()

classes = extract_classes(header_file_content)

with open("explorerscript_parser/ExplorerScriptVisitor.h", "r") as f:
    header_file_content = f.read()

visitor_methods = extract_visitor_methods(header_file_content)
bindings = generate_bindings(classes, visitor_methods)
trampoline_class = generate_trampoline_class(visitor_methods)

with open(
    os.path.abspath(os.path.dirname(__file__) + "/explorerscript_parser/pybind_explorerscript_parser.cpp"), "w"
) as f:
    f.write(
        """#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "antlr4-runtime.h"
#include "ExplorerScriptLexer.h"
#include "ExplorerScriptParser.h"
#include "ExplorerScriptVisitor.h"
#include "parser_wrapper.h"
            
using namespace antlr4;
namespace py = pybind11;
            
"""
        + trampoline_class
        + """
PYBIND11_MODULE(explorerscript_parser, m) {

py::class_<ParserWrapper>(m, "ParserWrapper")
    .def(py::init<std::string&>())
    .def("tree", &ParserWrapper::tree, py::keep_alive<1, 2>())
    .def("traverse", &ParserWrapper::traverse, py::keep_alive<1, 2>());

py::class_<antlr4::tree::TerminalNode>(m, "Antlr4TreeTerminalNode")
    .def("__str__", &antlr4::tree::TerminalNode::toString)
    .def_property_readonly("symbol", &antlr4::tree::TerminalNode::getSymbol);

py::class_<antlr4::Token>(m, "Antlr4Token")
    .def("__str__", &antlr4::Token::toString)
    .def_property_readonly("type", &antlr4::Token::getType)
    .def_property_readonly("line", &antlr4::Token::getLine)
    .def_property_readonly("charPositionInLine", &antlr4::Token::getCharPositionInLine)
    .def_property_readonly("channel", &antlr4::Token::getChannel)
    .def_property_readonly("tokenIndex", &antlr4::Token::getTokenIndex)
    .def_property_readonly("tokenIndex", &antlr4::Token::getStartIndex)
    .def_property_readonly("stopIndex", &antlr4::Token::getStopIndex)
    .def_property_readonly("text", &antlr4::Token::getText);
            
py::class_<antlr4::tree::ParseTree>(m, "Antlr4ParseTree");
py::class_<antlr4::RuleContext, antlr4::tree::ParseTree>(m, "Antlr4RuleContext");
py::class_<antlr4::ParserRuleContext, antlr4::RuleContext>(m, "Antlr4ParserRuleContext");


"""
        + bindings
        + "}"
    )
