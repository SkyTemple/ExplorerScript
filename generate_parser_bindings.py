#!/usr/bin/env python3
from __future__ import annotations

import itertools
import os.path
import re
from typing import TypedDict, TypeAlias, NotRequired


class MethodDef(TypedDict):
    return_type: NotRequired[str]
    method_name: str
    params: str
    is_overload: NotRequired[bool]


Classes: TypeAlias = dict[str, list[MethodDef]]


def extract_classes(header_file_content: str) -> Classes:
    class_regex = re.compile(r"class\s+(\w+)\s*:\s*public\s+antlr4::ParserRuleContext\s*{")
    method_regex = re.compile(r"^\s*(virtual)?\s*([\w:<>* ]+)\s+\*?([\w]+)\s*\(([^)]*)\)\s*(const)?\s*(override)?\s*;")
    end_class_regex = re.compile(r"^\s*};")

    classes: Classes = {}

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


def generate_bindings(target: str, classes: Classes, visitor_methods: list[MethodDef]) -> str:
    bindings = []

    for class_name, methods in classes.items():
        class_name = f"{target}Parser::{class_name}"
        bindings.append(f'py::class_<{class_name}, antlr4::ParserRuleContext>(m, "{class_name}")')
        bindings.append("    .def(py::init<antlr4::ParserRuleContext*, size_t>())")
        bindings.append(f'    .def("__str__", py::overload_cast<>(&{class_name}::toString))')
        bindings.append(f'    .def("to_string_tree", py::overload_cast<bool>(&{class_name}::toStringTree))')

        grouped_methods: dict[str, list[MethodDef]] = {}
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
                bindings.append(
                    f'    .def("{method_name}", &{class_name}::{method_name}, py::return_value_policy::automatic_reference)'
                )

        bindings.append(";")

    bindings.append(f'py::class_<{target}Visitor, Py{target}Visitor>(m, "{target}Visitor")')
    bindings.append("    .def(py::init<>())")
    bindings.append(f'    .def("visitChildren", []({target}Visitor& self, antlr4::tree::ParseTree* node) {{')
    bindings.append("        return std::any_cast<pybind11::object>(self.visitChildren(node));")
    bindings.append("    }, py::return_value_policy::automatic_reference)")
    bindings.append(f'    .def("defaultResult", []({target}Visitor& self) {{')
    bindings.append("        return std::any_cast<pybind11::object>(self.defaultResult());")
    bindings.append("    }, py::keep_alive<1, 2>())")
    for method in visitor_methods:
        bindings.append(
            f'    .def("{method["method_name"]}", &{target}Visitor::{method["method_name"]}, py::return_value_policy::reference_internal)'
        )
    bindings.append(";")

    return "\n".join(bindings)


def extract_visitor_methods(header_file_content: str) -> list[MethodDef]:
    method_regex = re.compile(r"\s+virtual\s+std::any\s+(\w+)\s*\(([^)]*)\)\s*=\s*0;")
    visitor_methods: list[MethodDef] = []

    for line in header_file_content.splitlines():
        method_match = method_regex.search(line)
        if method_match:
            method_name, params = method_match.groups()
            visitor_methods.append({"method_name": method_name, "params": params.strip()})

    return visitor_methods


def generate_trampoline_class(target: str, visitor_methods: list[MethodDef]) -> str:
    trampoline_class = []

    trampoline_class.append(f"class Py{target}Visitor : public {target}Visitor {{")
    trampoline_class.append("public:")
    trampoline_class.append("    /* Inherit the constructors */")
    trampoline_class.append(f"    using {target}Visitor::{target}Visitor;")
    trampoline_class.append("")

    for method in visitor_methods:
        method_name = method["method_name"]
        params = method["params"]
        trampoline_class.append(f"    std::any {method_name}({params}) override {{")
        trampoline_class.append("        PYBIND11_OVERRIDE_PURE(")
        trampoline_class.append("            pybind11::object,")  # Return type
        trampoline_class.append(f"            {target}Visitor,")  # Parent class
        trampoline_class.append(f"            {method_name},")
        trampoline_class.append(f'            {params.split(' ')[1].lstrip('*')}')
        trampoline_class.append("        );")
        trampoline_class.append("    }")

    trampoline_class.append("    std::any defaultResult() override {{")
    trampoline_class.append("        PYBIND11_OVERRIDE_PURE(")
    trampoline_class.append("            pybind11::object,")  # Return type
    trampoline_class.append(f"            {target}Visitor,")  # Parent class
    trampoline_class.append("            defaultResult")
    trampoline_class.append("        );")
    trampoline_class.append("    }}")

    trampoline_class.append("    std::any visitChildren(antlr4::tree::ParseTree *node) override {{")
    trampoline_class.append("        PYBIND11_OVERRIDE(")
    trampoline_class.append("            pybind11::object,")  # Return type
    trampoline_class.append(f"            {target}Visitor,")  # Parent class
    trampoline_class.append("            visitChildren,")
    trampoline_class.append("            node")
    trampoline_class.append("        );")
    trampoline_class.append("    }}")

    trampoline_class.append("};")

    return "\n".join(trampoline_class)


def convert_cpp_sig_to_py(target: str, inp: str) -> str:
    # XXX: This is very basic and will not catch any remotely complex case, but it should be fine here.
    args = inp.split(",")
    out_args = []
    for arg in args:
        arg = arg.strip()
        if arg == "":
            continue
        typ, name = arg.split(" ")
        if name.startswith("*"):
            name = name[1:]
        out_args.append(f"{name}: {convert_cpp_ty_to_py(target, typ)}")
    return ",".join(out_args)


def convert_cpp_ty_to_py(target: str, inp: str) -> str:
    inp = inp.strip()
    if inp == "std::any":
        return "Any"
    if inp == "size_t":
        return "int"
    if inp == "void":
        return "None"
    if inp == "antlr4::tree::TerminalNode":
        return "Antlr4TreeTerminalNode"
    if inp == "antlr4::tree::ParseTreeVisitor":
        return f"{target}Visitor"
    if inp == "antlr4::tree::ParseTreeListener":
        return "Unknown"
    vec_match = re.match(r"std::vector<(.*?)\s*\*?>", inp)
    if vec_match is not None:
        return f"list[{convert_cpp_ty_to_py(target, vec_match[1])}]"
    if inp.endswith("*"):
        return convert_cpp_ty_to_py(target, inp[:-1])
    if inp.endswith("Context") and "::" in inp:
        return inp.replace("::", ".")
    if inp.endswith("Context"):
        return f"{target}Parser.{inp[:-7]}Context"
    return inp


def generate_stubs(target: str, classes: Classes, visitor_methods: list[MethodDef]) -> str:
    bindings = []
    # Collect overloads
    for class_name, methods in classes.items():
        methods.sort(key=lambda m: m["method_name"])
        method_buckets: dict[str, list[MethodDef]] = {}
        for method in methods:
            if method["method_name"] not in method_buckets:
                method_buckets[method["method_name"]] = []
            method_buckets[method["method_name"]].append(method)

        for bucket in method_buckets.values():
            if len(bucket) > 1:
                for method in bucket:
                    method["is_overload"] = True
            else:
                bucket[0]["is_overload"] = False
        classes[class_name] = list(itertools.chain(*method_buckets.values()))

    bindings.append(f"class {target}Parser:")
    for class_name, methods in classes.items():
        bindings.append(f"    class {class_name}(Antlr4ParseTree):")
        for method in methods:
            return_type = method["return_type"] if "return_type" in method else "None"
            maybe_comma = ","
            if method["params"].strip() == "":
                maybe_comma = ""
            if method["is_overload"]:
                bindings.append("        @overload")
            bindings.append(
                f"        def {method['method_name']}(self{maybe_comma}{convert_cpp_sig_to_py(target, method['params'])}) -> {convert_cpp_ty_to_py(target, return_type)}: ..."
            )

    bindings.append(f"class {target}Visitor:")
    for method in visitor_methods:
        return_type = method["return_type"] if "return_type" in method else "None"
        maybe_comma = ","
        if method["params"].strip() == "":
            maybe_comma = ""
        bindings.append(
            f"    def {method['method_name']}(self{maybe_comma}{convert_cpp_sig_to_py(target, method['params'])}) -> {convert_cpp_ty_to_py(target, return_type)}: ..."
        )

    bindings.append("    def visitChildren(self, node: Antlr4ParseTree) -> Any: ...")
    bindings.append("    def defaultResult(self) -> Any: ...")

    bindings.append(f"class {target}ParserWrapper:")
    bindings.append(f"    def __init__(self, string: str) -> {target}ParserWrapper: ...")
    bindings.append(f"    def tree(self) -> {target}Parser.StartContext: ...")
    bindings.append(f"    def traverse(self, visitor: {target}Visitor) -> Any: ...")

    return "\n".join(bindings)


def load_info(target: str, out_path: str) -> tuple[Classes, list[MethodDef], str, str]:
    with open(os.path.join(out_path, f"{target}Parser.h"), "r") as f:
        header_file_content = f.read()

    classes = extract_classes(header_file_content)

    with open(os.path.join(out_path, f"{target}Visitor.h"), "r") as f:
        header_file_content = f.read()

    visitor_methods = extract_visitor_methods(header_file_content)
    bindings = generate_bindings(target, classes, visitor_methods)
    trampoline_class = generate_trampoline_class(target, visitor_methods)

    return classes, visitor_methods, bindings, trampoline_class


def main() -> None:
    out_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "explorerscript_parser"))

    exps_classes, exps_visitor_methods, exps_bindings, exps_trampoline_class = load_info("ExplorerScript", out_path)
    ssbs_classes, ssbs_visitor_methods, ssbs_bindings, ssbs_trampoline_class = load_info("SsbScript", out_path)

    with open(os.path.join(out_path, "pybind_explorerscript_parser.cpp"), "w") as f:
        f.write(
            """#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "antlr4-runtime.h"
#include "ExplorerScriptLexer.h"
#include "ExplorerScriptParser.h"
#include "ExplorerScriptVisitor.h"
#include "SsbScriptLexer.h"
#include "SsbScriptParser.h"
#include "SsbScriptVisitor.h"
#include "parser_wrapper_exps.h"
#include "parser_wrapper_ssbs.h"

using namespace antlr4;
namespace py = pybind11;

"""
            + exps_trampoline_class
            + ssbs_trampoline_class
            + """
PYBIND11_MODULE(explorerscript_parser, m) {

py::class_<ExplorerScriptParserWrapper>(m, "ExplorerScriptParserWrapper")
    .def(py::init<std::string&>())
    .def("tree", &ExplorerScriptParserWrapper::tree, py::keep_alive<1, 2>())
    .def("traverse", &ExplorerScriptParserWrapper::traverse, py::keep_alive<1, 2>());
py::class_<SsbScriptParserWrapper>(m, "SsbScriptParserWrapper")
    .def(py::init<std::string&>())
    .def("tree", &SsbScriptParserWrapper::tree, py::keep_alive<1, 2>())
    .def("traverse", &SsbScriptParserWrapper::traverse, py::keep_alive<1, 2>());

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
            + exps_bindings
            + ssbs_bindings
            + "}"
        )

    with open(os.path.join(out_path, "__init__.pyi"), "w") as f:
        f.write(
            "\n".join(
                [
                    "from typing import Any, TypeAlias, overload",
                    "Unknown: TypeAlias = Any",
                    "class Antlr4ParseTree: ...",
                    "class Antlr4Token:",
                    "    def __str__(self) -> str: ...",
                    "    @property",
                    "    def type(self) -> int: ...",
                    "    @property",
                    "    def line(self) -> int: ...",
                    "    @property",
                    "    def charPositionInLine(self) -> int: ...",
                    "    @property",
                    "    def channel(self) -> int: ...",
                    "    @property",
                    "    def tokenIndex(self) -> int: ...",
                    "    @property",
                    "    def stopIndex(self) -> int: ...",
                    "    @property",
                    "    def text(self) -> str: ...",
                    "class Antlr4TreeTerminalNode:",
                    "    def __str__(self) -> str: ...",
                    "    @property",
                    "    def symbol(self) -> Antlr4Token: ...",
                    "",
                ]
            )
        )
        f.write(generate_stubs("ExplorerScript", exps_classes, exps_visitor_methods))
        f.write("\n")
        f.write(generate_stubs("SsbScript", ssbs_classes, ssbs_visitor_methods))


if __name__ == "__main__":
    main()
