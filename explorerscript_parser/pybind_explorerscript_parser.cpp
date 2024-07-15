#include <pybind11/pybind11.h>
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

class PyExplorerScriptVisitor : public ExplorerScriptVisitor {
public:
    /* Inherit the constructors */
    using ExplorerScriptVisitor::ExplorerScriptVisitor;

    std::any visitStart(ExplorerScriptParser::StartContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitStart,
            context
        );
    }
    std::any visitImport_stmt(ExplorerScriptParser::Import_stmtContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitImport_stmt,
            context
        );
    }
    std::any visitMacrodef(ExplorerScriptParser::MacrodefContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitMacrodef,
            context
        );
    }
    std::any visitStmt(ExplorerScriptParser::StmtContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitStmt,
            context
        );
    }
    std::any visitSimple_stmt(ExplorerScriptParser::Simple_stmtContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSimple_stmt,
            context
        );
    }
    std::any visitCntrl_stmt(ExplorerScriptParser::Cntrl_stmtContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCntrl_stmt,
            context
        );
    }
    std::any visitJump(ExplorerScriptParser::JumpContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitJump,
            context
        );
    }
    std::any visitCall(ExplorerScriptParser::CallContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCall,
            context
        );
    }
    std::any visitMacro_call(ExplorerScriptParser::Macro_callContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitMacro_call,
            context
        );
    }
    std::any visitCtx_block(ExplorerScriptParser::Ctx_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCtx_block,
            context
        );
    }
    std::any visitIf_block(ExplorerScriptParser::If_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_block,
            context
        );
    }
    std::any visitElseif_block(ExplorerScriptParser::Elseif_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitElseif_block,
            context
        );
    }
    std::any visitElse_block(ExplorerScriptParser::Else_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitElse_block,
            context
        );
    }
    std::any visitIf_header(ExplorerScriptParser::If_headerContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_header,
            context
        );
    }
    std::any visitIf_h_negatable(ExplorerScriptParser::If_h_negatableContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_h_negatable,
            context
        );
    }
    std::any visitIf_h_op(ExplorerScriptParser::If_h_opContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_h_op,
            context
        );
    }
    std::any visitIf_h_bit(ExplorerScriptParser::If_h_bitContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_h_bit,
            context
        );
    }
    std::any visitIf_h_scn(ExplorerScriptParser::If_h_scnContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_h_scn,
            context
        );
    }
    std::any visitSwitch_block(ExplorerScriptParser::Switch_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_block,
            context
        );
    }
    std::any visitMessage_switch_block(ExplorerScriptParser::Message_switch_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitMessage_switch_block,
            context
        );
    }
    std::any visitSingle_case_block(ExplorerScriptParser::Single_case_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSingle_case_block,
            context
        );
    }
    std::any visitDefault(ExplorerScriptParser::DefaultContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitDefault,
            context
        );
    }
    std::any visitSwitch_header(ExplorerScriptParser::Switch_headerContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_header,
            context
        );
    }
    std::any visitSwitch_h_scn(ExplorerScriptParser::Switch_h_scnContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_h_scn,
            context
        );
    }
    std::any visitSwitch_h_random(ExplorerScriptParser::Switch_h_randomContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_h_random,
            context
        );
    }
    std::any visitSwitch_h_dungeon_mode(ExplorerScriptParser::Switch_h_dungeon_modeContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_h_dungeon_mode,
            context
        );
    }
    std::any visitSwitch_h_sector(ExplorerScriptParser::Switch_h_sectorContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_h_sector,
            context
        );
    }
    std::any visitCase_header(ExplorerScriptParser::Case_headerContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCase_header,
            context
        );
    }
    std::any visitCase_h_menu(ExplorerScriptParser::Case_h_menuContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCase_h_menu,
            context
        );
    }
    std::any visitCase_h_menu2(ExplorerScriptParser::Case_h_menu2Context *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCase_h_menu2,
            context
        );
    }
    std::any visitCase_h_op(ExplorerScriptParser::Case_h_opContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCase_h_op,
            context
        );
    }
    std::any visitForever_block(ExplorerScriptParser::Forever_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitForever_block,
            context
        );
    }
    std::any visitFor_block(ExplorerScriptParser::For_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFor_block,
            context
        );
    }
    std::any visitWhile_block(ExplorerScriptParser::While_blockContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitWhile_block,
            context
        );
    }
    std::any visitAssignment(ExplorerScriptParser::AssignmentContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment,
            context
        );
    }
    std::any visitAssignment_regular(ExplorerScriptParser::Assignment_regularContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_regular,
            context
        );
    }
    std::any visitAssignment_clear(ExplorerScriptParser::Assignment_clearContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_clear,
            context
        );
    }
    std::any visitAssignment_initial(ExplorerScriptParser::Assignment_initialContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_initial,
            context
        );
    }
    std::any visitAssignment_reset(ExplorerScriptParser::Assignment_resetContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_reset,
            context
        );
    }
    std::any visitAssignment_adv_log(ExplorerScriptParser::Assignment_adv_logContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_adv_log,
            context
        );
    }
    std::any visitAssignment_dungeon_mode(ExplorerScriptParser::Assignment_dungeon_modeContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_dungeon_mode,
            context
        );
    }
    std::any visitAssignment_scn(ExplorerScriptParser::Assignment_scnContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_scn,
            context
        );
    }
    std::any visitValue_of(ExplorerScriptParser::Value_ofContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitValue_of,
            context
        );
    }
    std::any visitScn_var(ExplorerScriptParser::Scn_varContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitScn_var,
            context
        );
    }
    std::any visitConditional_operator(ExplorerScriptParser::Conditional_operatorContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitConditional_operator,
            context
        );
    }
    std::any visitAssign_operator(ExplorerScriptParser::Assign_operatorContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssign_operator,
            context
        );
    }
    std::any visitFuncdef(ExplorerScriptParser::FuncdefContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFuncdef,
            context
        );
    }
    std::any visitSimple_def(ExplorerScriptParser::Simple_defContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSimple_def,
            context
        );
    }
    std::any visitCoro_def(ExplorerScriptParser::Coro_defContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCoro_def,
            context
        );
    }
    std::any visitFor_target_def(ExplorerScriptParser::For_target_defContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFor_target_def,
            context
        );
    }
    std::any visitInteger_like(ExplorerScriptParser::Integer_likeContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitInteger_like,
            context
        );
    }
    std::any visitOperation(ExplorerScriptParser::OperationContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitOperation,
            context
        );
    }
    std::any visitInline_ctx(ExplorerScriptParser::Inline_ctxContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitInline_ctx,
            context
        );
    }
    std::any visitFunc_suite(ExplorerScriptParser::Func_suiteContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFunc_suite,
            context
        );
    }
    std::any visitFunc_alias(ExplorerScriptParser::Func_aliasContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFunc_alias,
            context
        );
    }
    std::any visitArglist(ExplorerScriptParser::ArglistContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitArglist,
            context
        );
    }
    std::any visitPos_argument(ExplorerScriptParser::Pos_argumentContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitPos_argument,
            context
        );
    }
    std::any visitPosition_marker(ExplorerScriptParser::Position_markerContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitPosition_marker,
            context
        );
    }
    std::any visitPosition_marker_arg(ExplorerScriptParser::Position_marker_argContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitPosition_marker_arg,
            context
        );
    }
    std::any visitLabel(ExplorerScriptParser::LabelContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitLabel,
            context
        );
    }
    std::any visitString(ExplorerScriptParser::StringContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitString,
            context
        );
    }
    std::any visitLang_string(ExplorerScriptParser::Lang_stringContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitLang_string,
            context
        );
    }
    std::any visitLang_string_argument(ExplorerScriptParser::Lang_string_argumentContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitLang_string_argument,
            context
        );
    }
    std::any visitString_value(ExplorerScriptParser::String_valueContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitString_value,
            context
        );
    }
    std::any visitCtx_header(ExplorerScriptParser::Ctx_headerContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCtx_header,
            context
        );
    }
    std::any visitFor_target_def_target(ExplorerScriptParser::For_target_def_targetContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFor_target_def_target,
            context
        );
    }
    std::any defaultResult() override {{
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            defaultResult
        );
    }}
    std::any visitChildren(antlr4::tree::ParseTree *node) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitChildren,
            node
        );
    }}
};class PySsbScriptVisitor : public SsbScriptVisitor {
public:
    /* Inherit the constructors */
    using SsbScriptVisitor::SsbScriptVisitor;

    std::any visitPos_argument(SsbScriptParser::Pos_argumentContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitPos_argument,
            context
        );
    }
    std::any visitJump_marker(SsbScriptParser::Jump_markerContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitJump_marker,
            context
        );
    }
    std::any visitStart(SsbScriptParser::StartContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitStart,
            context
        );
    }
    std::any visitFuncdef(SsbScriptParser::FuncdefContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitFuncdef,
            context
        );
    }
    std::any visitSimple_def(SsbScriptParser::Simple_defContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitSimple_def,
            context
        );
    }
    std::any visitCoro_def(SsbScriptParser::Coro_defContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitCoro_def,
            context
        );
    }
    std::any visitFor_target_def(SsbScriptParser::For_target_defContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitFor_target_def,
            context
        );
    }
    std::any visitInteger_like(SsbScriptParser::Integer_likeContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitInteger_like,
            context
        );
    }
    std::any visitStmt(SsbScriptParser::StmtContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitStmt,
            context
        );
    }
    std::any visitOperation(SsbScriptParser::OperationContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitOperation,
            context
        );
    }
    std::any visitInline_ctx(SsbScriptParser::Inline_ctxContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitInline_ctx,
            context
        );
    }
    std::any visitFunc_suite(SsbScriptParser::Func_suiteContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitFunc_suite,
            context
        );
    }
    std::any visitFunc_alias(SsbScriptParser::Func_aliasContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitFunc_alias,
            context
        );
    }
    std::any visitArglist(SsbScriptParser::ArglistContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitArglist,
            context
        );
    }
    std::any visitPosition_marker(SsbScriptParser::Position_markerContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitPosition_marker,
            context
        );
    }
    std::any visitPosition_marker_arg(SsbScriptParser::Position_marker_argContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitPosition_marker_arg,
            context
        );
    }
    std::any visitLabel(SsbScriptParser::LabelContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitLabel,
            context
        );
    }
    std::any visitString(SsbScriptParser::StringContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitString,
            context
        );
    }
    std::any visitLang_string(SsbScriptParser::Lang_stringContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitLang_string,
            context
        );
    }
    std::any visitLang_string_argument(SsbScriptParser::Lang_string_argumentContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitLang_string_argument,
            context
        );
    }
    std::any visitString_value(SsbScriptParser::String_valueContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitString_value,
            context
        );
    }
    std::any visitCtx_header(SsbScriptParser::Ctx_headerContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitCtx_header,
            context
        );
    }
    std::any visitFor_target_def_target(SsbScriptParser::For_target_def_targetContext *context) override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            visitFor_target_def_target,
            context
        );
    }
    std::any defaultResult() override {{
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            SsbScriptVisitor,
            defaultResult
        );
    }}
    std::any visitChildren(antlr4::tree::ParseTree *node) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptVisitor,
            visitChildren,
            node
        );
    }}
};
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


py::class_<ExplorerScriptParser::StartContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::StartContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::StartContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::StartContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::StartContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("EOF", &ExplorerScriptParser::StartContext::EOF, py::return_value_policy::automatic_reference)
    .def("import_stmt", py::overload_cast<>(&ExplorerScriptParser::StartContext::import_stmt))
    .def("import_stmt", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::import_stmt))
    .def("macrodef", py::overload_cast<>(&ExplorerScriptParser::StartContext::macrodef))
    .def("macrodef", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::macrodef))
    .def("funcdef", py::overload_cast<>(&ExplorerScriptParser::StartContext::funcdef))
    .def("funcdef", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::funcdef))
    .def("accept", &ExplorerScriptParser::StartContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Import_stmtContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Import_stmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Import_stmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Import_stmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Import_stmtContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IMPORT", &ExplorerScriptParser::Import_stmtContext::IMPORT, py::return_value_policy::automatic_reference)
    .def("STRING_LITERAL", &ExplorerScriptParser::Import_stmtContext::STRING_LITERAL, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Import_stmtContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::MacrodefContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::MacrodefContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::MacrodefContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::MacrodefContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::MacrodefContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("MACRO", &ExplorerScriptParser::MacrodefContext::MACRO, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::MacrodefContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::MacrodefContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::MacrodefContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("func_suite", &ExplorerScriptParser::MacrodefContext::func_suite, py::return_value_policy::automatic_reference)
    .def("VARIABLE", py::overload_cast<>(&ExplorerScriptParser::MacrodefContext::VARIABLE))
    .def("VARIABLE", py::overload_cast<size_t>(&ExplorerScriptParser::MacrodefContext::VARIABLE))
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::MacrodefContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::MacrodefContext::COMMA))
    .def("accept", &ExplorerScriptParser::MacrodefContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::StmtContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::StmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::StmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::StmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::StmtContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("simple_stmt", &ExplorerScriptParser::StmtContext::simple_stmt, py::return_value_policy::automatic_reference)
    .def("ctx_block", &ExplorerScriptParser::StmtContext::ctx_block, py::return_value_policy::automatic_reference)
    .def("if_block", &ExplorerScriptParser::StmtContext::if_block, py::return_value_policy::automatic_reference)
    .def("switch_block", &ExplorerScriptParser::StmtContext::switch_block, py::return_value_policy::automatic_reference)
    .def("message_switch_block", &ExplorerScriptParser::StmtContext::message_switch_block, py::return_value_policy::automatic_reference)
    .def("forever_block", &ExplorerScriptParser::StmtContext::forever_block, py::return_value_policy::automatic_reference)
    .def("for_block", &ExplorerScriptParser::StmtContext::for_block, py::return_value_policy::automatic_reference)
    .def("while_block", &ExplorerScriptParser::StmtContext::while_block, py::return_value_policy::automatic_reference)
    .def("macro_call", &ExplorerScriptParser::StmtContext::macro_call, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::StmtContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Simple_stmtContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Simple_stmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Simple_stmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Simple_stmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Simple_stmtContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("operation", &ExplorerScriptParser::Simple_stmtContext::operation, py::return_value_policy::automatic_reference)
    .def("label", &ExplorerScriptParser::Simple_stmtContext::label, py::return_value_policy::automatic_reference)
    .def("cntrl_stmt", &ExplorerScriptParser::Simple_stmtContext::cntrl_stmt, py::return_value_policy::automatic_reference)
    .def("jump", &ExplorerScriptParser::Simple_stmtContext::jump, py::return_value_policy::automatic_reference)
    .def("call", &ExplorerScriptParser::Simple_stmtContext::call, py::return_value_policy::automatic_reference)
    .def("assignment", &ExplorerScriptParser::Simple_stmtContext::assignment, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Simple_stmtContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Cntrl_stmtContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Cntrl_stmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Cntrl_stmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Cntrl_stmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Cntrl_stmtContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("RETURN", &ExplorerScriptParser::Cntrl_stmtContext::RETURN, py::return_value_policy::automatic_reference)
    .def("END", &ExplorerScriptParser::Cntrl_stmtContext::END, py::return_value_policy::automatic_reference)
    .def("HOLD", &ExplorerScriptParser::Cntrl_stmtContext::HOLD, py::return_value_policy::automatic_reference)
    .def("CONTINUE", &ExplorerScriptParser::Cntrl_stmtContext::CONTINUE, py::return_value_policy::automatic_reference)
    .def("BREAK", &ExplorerScriptParser::Cntrl_stmtContext::BREAK, py::return_value_policy::automatic_reference)
    .def("BREAK_LOOP", &ExplorerScriptParser::Cntrl_stmtContext::BREAK_LOOP, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Cntrl_stmtContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::JumpContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::JumpContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::JumpContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::JumpContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::JumpContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("JUMP", &ExplorerScriptParser::JumpContext::JUMP, py::return_value_policy::automatic_reference)
    .def("AT", &ExplorerScriptParser::JumpContext::AT, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::JumpContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::JumpContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::CallContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::CallContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::CallContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::CallContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::CallContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("CALL", &ExplorerScriptParser::CallContext::CALL, py::return_value_policy::automatic_reference)
    .def("AT", &ExplorerScriptParser::CallContext::AT, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::CallContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::CallContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Macro_callContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Macro_callContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Macro_callContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Macro_callContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Macro_callContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("MACRO_CALL", &ExplorerScriptParser::Macro_callContext::MACRO_CALL, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Macro_callContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Macro_callContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("arglist", &ExplorerScriptParser::Macro_callContext::arglist, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Macro_callContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Ctx_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Ctx_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Ctx_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Ctx_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Ctx_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("WITH", &ExplorerScriptParser::Ctx_blockContext::WITH, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Ctx_blockContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("ctx_header", &ExplorerScriptParser::Ctx_blockContext::ctx_header, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Ctx_blockContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::Ctx_blockContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("simple_stmt", &ExplorerScriptParser::Ctx_blockContext::simple_stmt, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Ctx_blockContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Ctx_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::If_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IF", &ExplorerScriptParser::If_blockContext::IF, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::If_blockContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("if_header", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::if_header))
    .def("if_header", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::if_header))
    .def("CLOSE_PAREN", &ExplorerScriptParser::If_blockContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::If_blockContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::If_blockContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("NOT", &ExplorerScriptParser::If_blockContext::NOT, py::return_value_policy::automatic_reference)
    .def("OR", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::OR))
    .def("OR", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::OR))
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::stmt))
    .def("elseif_block", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::elseif_block))
    .def("elseif_block", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::elseif_block))
    .def("else_block", &ExplorerScriptParser::If_blockContext::else_block, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::If_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Elseif_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Elseif_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Elseif_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Elseif_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("ELSEIF", &ExplorerScriptParser::Elseif_blockContext::ELSEIF, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Elseif_blockContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("if_header", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::if_header))
    .def("if_header", py::overload_cast<size_t>(&ExplorerScriptParser::Elseif_blockContext::if_header))
    .def("CLOSE_PAREN", &ExplorerScriptParser::Elseif_blockContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::Elseif_blockContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Elseif_blockContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("NOT", &ExplorerScriptParser::Elseif_blockContext::NOT, py::return_value_policy::automatic_reference)
    .def("OR", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::OR))
    .def("OR", py::overload_cast<size_t>(&ExplorerScriptParser::Elseif_blockContext::OR))
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Elseif_blockContext::stmt))
    .def("accept", &ExplorerScriptParser::Elseif_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Else_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Else_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Else_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Else_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Else_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("ELSE", &ExplorerScriptParser::Else_blockContext::ELSE, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::Else_blockContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Else_blockContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Else_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Else_blockContext::stmt))
    .def("accept", &ExplorerScriptParser::Else_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::If_headerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_headerContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("if_h_op", &ExplorerScriptParser::If_headerContext::if_h_op, py::return_value_policy::automatic_reference)
    .def("if_h_bit", &ExplorerScriptParser::If_headerContext::if_h_bit, py::return_value_policy::automatic_reference)
    .def("if_h_negatable", &ExplorerScriptParser::If_headerContext::if_h_negatable, py::return_value_policy::automatic_reference)
    .def("if_h_scn", &ExplorerScriptParser::If_headerContext::if_h_scn, py::return_value_policy::automatic_reference)
    .def("operation", &ExplorerScriptParser::If_headerContext::operation, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::If_headerContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::If_h_negatableContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_h_negatableContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_negatableContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_negatableContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_negatableContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DEBUG", &ExplorerScriptParser::If_h_negatableContext::DEBUG, py::return_value_policy::automatic_reference)
    .def("EDIT", &ExplorerScriptParser::If_h_negatableContext::EDIT, py::return_value_policy::automatic_reference)
    .def("VARIATION", &ExplorerScriptParser::If_h_negatableContext::VARIATION, py::return_value_policy::automatic_reference)
    .def("NOT", &ExplorerScriptParser::If_h_negatableContext::NOT, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::If_h_negatableContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::If_h_opContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_h_opContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_opContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_opContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_opContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("integer_like", py::overload_cast<>(&ExplorerScriptParser::If_h_opContext::integer_like))
    .def("integer_like", py::overload_cast<size_t>(&ExplorerScriptParser::If_h_opContext::integer_like))
    .def("conditional_operator", &ExplorerScriptParser::If_h_opContext::conditional_operator, py::return_value_policy::automatic_reference)
    .def("value_of", &ExplorerScriptParser::If_h_opContext::value_of, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::If_h_opContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::If_h_bitContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_h_bitContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_bitContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_bitContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_bitContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::If_h_bitContext::integer_like, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACKET", &ExplorerScriptParser::If_h_bitContext::OPEN_BRACKET, py::return_value_policy::automatic_reference)
    .def("INTEGER", &ExplorerScriptParser::If_h_bitContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::If_h_bitContext::CLOSE_BRACKET, py::return_value_policy::automatic_reference)
    .def("NOT", &ExplorerScriptParser::If_h_bitContext::NOT, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::If_h_bitContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::If_h_scnContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_h_scnContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_scnContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_scnContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_scnContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("scn_var", &ExplorerScriptParser::If_h_scnContext::scn_var, py::return_value_policy::automatic_reference)
    .def("conditional_operator", &ExplorerScriptParser::If_h_scnContext::conditional_operator, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACKET", &ExplorerScriptParser::If_h_scnContext::OPEN_BRACKET, py::return_value_policy::automatic_reference)
    .def("INTEGER", py::overload_cast<>(&ExplorerScriptParser::If_h_scnContext::INTEGER))
    .def("INTEGER", py::overload_cast<size_t>(&ExplorerScriptParser::If_h_scnContext::INTEGER))
    .def("COMMA", &ExplorerScriptParser::If_h_scnContext::COMMA, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::If_h_scnContext::CLOSE_BRACKET, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::If_h_scnContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Switch_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("SWITCH", &ExplorerScriptParser::Switch_blockContext::SWITCH, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_blockContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("switch_header", &ExplorerScriptParser::Switch_blockContext::switch_header, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_blockContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::Switch_blockContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Switch_blockContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("default_", py::overload_cast<>(&ExplorerScriptParser::Switch_blockContext::default_))
    .def("default_", py::overload_cast<size_t>(&ExplorerScriptParser::Switch_blockContext::default_))
    .def("single_case_block", py::overload_cast<>(&ExplorerScriptParser::Switch_blockContext::single_case_block))
    .def("single_case_block", py::overload_cast<size_t>(&ExplorerScriptParser::Switch_blockContext::single_case_block))
    .def("accept", &ExplorerScriptParser::Switch_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Message_switch_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Message_switch_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Message_switch_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Message_switch_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Message_switch_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Message_switch_blockContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Message_switch_blockContext::integer_like, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Message_switch_blockContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::Message_switch_blockContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Message_switch_blockContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("MESSAGE_SWITCH_TALK", &ExplorerScriptParser::Message_switch_blockContext::MESSAGE_SWITCH_TALK, py::return_value_policy::automatic_reference)
    .def("MESSAGE_SWITCH_MONOLOGUE", &ExplorerScriptParser::Message_switch_blockContext::MESSAGE_SWITCH_MONOLOGUE, py::return_value_policy::automatic_reference)
    .def("default_", py::overload_cast<>(&ExplorerScriptParser::Message_switch_blockContext::default_))
    .def("default_", py::overload_cast<size_t>(&ExplorerScriptParser::Message_switch_blockContext::default_))
    .def("single_case_block", py::overload_cast<>(&ExplorerScriptParser::Message_switch_blockContext::single_case_block))
    .def("single_case_block", py::overload_cast<size_t>(&ExplorerScriptParser::Message_switch_blockContext::single_case_block))
    .def("accept", &ExplorerScriptParser::Message_switch_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Single_case_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Single_case_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Single_case_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Single_case_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Single_case_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("CASE", &ExplorerScriptParser::Single_case_blockContext::CASE, py::return_value_policy::automatic_reference)
    .def("case_header", &ExplorerScriptParser::Single_case_blockContext::case_header, py::return_value_policy::automatic_reference)
    .def("COLON", &ExplorerScriptParser::Single_case_blockContext::COLON, py::return_value_policy::automatic_reference)
    .def("string", &ExplorerScriptParser::Single_case_blockContext::string, py::return_value_policy::automatic_reference)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Single_case_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Single_case_blockContext::stmt))
    .def("accept", &ExplorerScriptParser::Single_case_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::DefaultContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::DefaultContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::DefaultContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::DefaultContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::DefaultContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DEFAULT", &ExplorerScriptParser::DefaultContext::DEFAULT, py::return_value_policy::automatic_reference)
    .def("COLON", &ExplorerScriptParser::DefaultContext::COLON, py::return_value_policy::automatic_reference)
    .def("string", &ExplorerScriptParser::DefaultContext::string, py::return_value_policy::automatic_reference)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::DefaultContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::DefaultContext::stmt))
    .def("accept", &ExplorerScriptParser::DefaultContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Switch_headerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_headerContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Switch_headerContext::integer_like, py::return_value_policy::automatic_reference)
    .def("operation", &ExplorerScriptParser::Switch_headerContext::operation, py::return_value_policy::automatic_reference)
    .def("switch_h_scn", &ExplorerScriptParser::Switch_headerContext::switch_h_scn, py::return_value_policy::automatic_reference)
    .def("switch_h_random", &ExplorerScriptParser::Switch_headerContext::switch_h_random, py::return_value_policy::automatic_reference)
    .def("switch_h_dungeon_mode", &ExplorerScriptParser::Switch_headerContext::switch_h_dungeon_mode, py::return_value_policy::automatic_reference)
    .def("switch_h_sector", &ExplorerScriptParser::Switch_headerContext::switch_h_sector, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Switch_headerContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Switch_h_scnContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_h_scnContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_scnContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_scnContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_scnContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("scn_var", &ExplorerScriptParser::Switch_h_scnContext::scn_var, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACKET", &ExplorerScriptParser::Switch_h_scnContext::OPEN_BRACKET, py::return_value_policy::automatic_reference)
    .def("INTEGER", &ExplorerScriptParser::Switch_h_scnContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::Switch_h_scnContext::CLOSE_BRACKET, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Switch_h_scnContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Switch_h_randomContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_h_randomContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_randomContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_randomContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_randomContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("RANDOM", &ExplorerScriptParser::Switch_h_randomContext::RANDOM, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_h_randomContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Switch_h_randomContext::integer_like, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_h_randomContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Switch_h_randomContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Switch_h_dungeon_modeContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_h_dungeon_modeContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_dungeon_modeContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_dungeon_modeContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_dungeon_modeContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DUNGEON_MODE", &ExplorerScriptParser::Switch_h_dungeon_modeContext::DUNGEON_MODE, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_h_dungeon_modeContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Switch_h_dungeon_modeContext::integer_like, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_h_dungeon_modeContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Switch_h_dungeon_modeContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Switch_h_sectorContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_h_sectorContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_sectorContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_sectorContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_sectorContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("SECTOR", &ExplorerScriptParser::Switch_h_sectorContext::SECTOR, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_h_sectorContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_h_sectorContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Switch_h_sectorContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Case_headerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Case_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_headerContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Case_headerContext::integer_like, py::return_value_policy::automatic_reference)
    .def("case_h_menu", &ExplorerScriptParser::Case_headerContext::case_h_menu, py::return_value_policy::automatic_reference)
    .def("case_h_menu2", &ExplorerScriptParser::Case_headerContext::case_h_menu2, py::return_value_policy::automatic_reference)
    .def("case_h_op", &ExplorerScriptParser::Case_headerContext::case_h_op, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Case_headerContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Case_h_menuContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Case_h_menuContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_h_menuContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_h_menuContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_h_menuContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("MENU", &ExplorerScriptParser::Case_h_menuContext::MENU, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Case_h_menuContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("string", &ExplorerScriptParser::Case_h_menuContext::string, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Case_h_menuContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Case_h_menuContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Case_h_menu2Context, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Case_h_menu2Context")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_h_menu2Context::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_h_menu2Context::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_h_menu2Context::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("MENU2", &ExplorerScriptParser::Case_h_menu2Context::MENU2, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Case_h_menu2Context::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Case_h_menu2Context::integer_like, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Case_h_menu2Context::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Case_h_menu2Context::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Case_h_opContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Case_h_opContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_h_opContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_h_opContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_h_opContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("conditional_operator", &ExplorerScriptParser::Case_h_opContext::conditional_operator, py::return_value_policy::automatic_reference)
    .def("value_of", &ExplorerScriptParser::Case_h_opContext::value_of, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Case_h_opContext::integer_like, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Case_h_opContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Forever_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Forever_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Forever_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Forever_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Forever_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("FOREVER", &ExplorerScriptParser::Forever_blockContext::FOREVER, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::Forever_blockContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Forever_blockContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Forever_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Forever_blockContext::stmt))
    .def("accept", &ExplorerScriptParser::Forever_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::For_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::For_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::For_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::For_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::For_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("FOR", &ExplorerScriptParser::For_blockContext::FOR, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::For_blockContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("simple_stmt", py::overload_cast<>(&ExplorerScriptParser::For_blockContext::simple_stmt))
    .def("simple_stmt", py::overload_cast<size_t>(&ExplorerScriptParser::For_blockContext::simple_stmt))
    .def("if_header", &ExplorerScriptParser::For_blockContext::if_header, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::For_blockContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::For_blockContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::For_blockContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::For_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::For_blockContext::stmt))
    .def("accept", &ExplorerScriptParser::For_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::While_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::While_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::While_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::While_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::While_blockContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("WHILE", &ExplorerScriptParser::While_blockContext::WHILE, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::While_blockContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("if_header", &ExplorerScriptParser::While_blockContext::if_header, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::While_blockContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::While_blockContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::While_blockContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("NOT", &ExplorerScriptParser::While_blockContext::NOT, py::return_value_policy::automatic_reference)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::While_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::While_blockContext::stmt))
    .def("accept", &ExplorerScriptParser::While_blockContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::AssignmentContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::AssignmentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::AssignmentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::AssignmentContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::AssignmentContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("assignment_regular", &ExplorerScriptParser::AssignmentContext::assignment_regular, py::return_value_policy::automatic_reference)
    .def("assignment_clear", &ExplorerScriptParser::AssignmentContext::assignment_clear, py::return_value_policy::automatic_reference)
    .def("assignment_initial", &ExplorerScriptParser::AssignmentContext::assignment_initial, py::return_value_policy::automatic_reference)
    .def("assignment_reset", &ExplorerScriptParser::AssignmentContext::assignment_reset, py::return_value_policy::automatic_reference)
    .def("assignment_adv_log", &ExplorerScriptParser::AssignmentContext::assignment_adv_log, py::return_value_policy::automatic_reference)
    .def("assignment_dungeon_mode", &ExplorerScriptParser::AssignmentContext::assignment_dungeon_mode, py::return_value_policy::automatic_reference)
    .def("assignment_scn", &ExplorerScriptParser::AssignmentContext::assignment_scn, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::AssignmentContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Assignment_regularContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_regularContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_regularContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_regularContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_regularContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("integer_like", py::overload_cast<>(&ExplorerScriptParser::Assignment_regularContext::integer_like))
    .def("integer_like", py::overload_cast<size_t>(&ExplorerScriptParser::Assignment_regularContext::integer_like))
    .def("assign_operator", &ExplorerScriptParser::Assignment_regularContext::assign_operator, py::return_value_policy::automatic_reference)
    .def("value_of", &ExplorerScriptParser::Assignment_regularContext::value_of, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACKET", &ExplorerScriptParser::Assignment_regularContext::OPEN_BRACKET, py::return_value_policy::automatic_reference)
    .def("INTEGER", &ExplorerScriptParser::Assignment_regularContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::Assignment_regularContext::CLOSE_BRACKET, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Assignment_regularContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Assignment_clearContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_clearContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_clearContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_clearContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_clearContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("CLEAR", &ExplorerScriptParser::Assignment_clearContext::CLEAR, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Assignment_clearContext::integer_like, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Assignment_clearContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Assignment_initialContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_initialContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_initialContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_initialContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_initialContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("INIT", &ExplorerScriptParser::Assignment_initialContext::INIT, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Assignment_initialContext::integer_like, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Assignment_initialContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Assignment_resetContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_resetContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_resetContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_resetContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_resetContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("RESET", &ExplorerScriptParser::Assignment_resetContext::RESET, py::return_value_policy::automatic_reference)
    .def("DUNGEON_RESULT", &ExplorerScriptParser::Assignment_resetContext::DUNGEON_RESULT, py::return_value_policy::automatic_reference)
    .def("scn_var", &ExplorerScriptParser::Assignment_resetContext::scn_var, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Assignment_resetContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Assignment_adv_logContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_adv_logContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_adv_logContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_adv_logContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_adv_logContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("ADVENTURE_LOG", &ExplorerScriptParser::Assignment_adv_logContext::ADVENTURE_LOG, py::return_value_policy::automatic_reference)
    .def("ASSIGN", &ExplorerScriptParser::Assignment_adv_logContext::ASSIGN, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Assignment_adv_logContext::integer_like, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Assignment_adv_logContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Assignment_dungeon_modeContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_dungeon_modeContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_dungeon_modeContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_dungeon_modeContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_dungeon_modeContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DUNGEON_MODE", &ExplorerScriptParser::Assignment_dungeon_modeContext::DUNGEON_MODE, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Assignment_dungeon_modeContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("integer_like", py::overload_cast<>(&ExplorerScriptParser::Assignment_dungeon_modeContext::integer_like))
    .def("integer_like", py::overload_cast<size_t>(&ExplorerScriptParser::Assignment_dungeon_modeContext::integer_like))
    .def("CLOSE_PAREN", &ExplorerScriptParser::Assignment_dungeon_modeContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("ASSIGN", &ExplorerScriptParser::Assignment_dungeon_modeContext::ASSIGN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Assignment_dungeon_modeContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Assignment_scnContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_scnContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_scnContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_scnContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_scnContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Assignment_scnContext::integer_like, py::return_value_policy::automatic_reference)
    .def("ASSIGN", &ExplorerScriptParser::Assignment_scnContext::ASSIGN, py::return_value_policy::automatic_reference)
    .def("SCN", &ExplorerScriptParser::Assignment_scnContext::SCN, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACKET", &ExplorerScriptParser::Assignment_scnContext::OPEN_BRACKET, py::return_value_policy::automatic_reference)
    .def("INTEGER", py::overload_cast<>(&ExplorerScriptParser::Assignment_scnContext::INTEGER))
    .def("INTEGER", py::overload_cast<size_t>(&ExplorerScriptParser::Assignment_scnContext::INTEGER))
    .def("COMMA", &ExplorerScriptParser::Assignment_scnContext::COMMA, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::Assignment_scnContext::CLOSE_BRACKET, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Assignment_scnContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Value_ofContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Value_ofContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Value_ofContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Value_ofContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Value_ofContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("VALUE", &ExplorerScriptParser::Value_ofContext::VALUE, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Value_ofContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Value_ofContext::integer_like, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Value_ofContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Value_ofContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Scn_varContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Scn_varContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Scn_varContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Scn_varContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Scn_varContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("SCN", &ExplorerScriptParser::Scn_varContext::SCN, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::Scn_varContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Scn_varContext::integer_like, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Scn_varContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Scn_varContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Conditional_operatorContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Conditional_operatorContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Conditional_operatorContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Conditional_operatorContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Conditional_operatorContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("OP_FALSE", &ExplorerScriptParser::Conditional_operatorContext::OP_FALSE, py::return_value_policy::automatic_reference)
    .def("OP_TRUE", &ExplorerScriptParser::Conditional_operatorContext::OP_TRUE, py::return_value_policy::automatic_reference)
    .def("OP_EQ", &ExplorerScriptParser::Conditional_operatorContext::OP_EQ, py::return_value_policy::automatic_reference)
    .def("OP_GE", &ExplorerScriptParser::Conditional_operatorContext::OP_GE, py::return_value_policy::automatic_reference)
    .def("OP_LE", &ExplorerScriptParser::Conditional_operatorContext::OP_LE, py::return_value_policy::automatic_reference)
    .def("OPEN_SHARP", &ExplorerScriptParser::Conditional_operatorContext::OPEN_SHARP, py::return_value_policy::automatic_reference)
    .def("CLOSE_SHARP", &ExplorerScriptParser::Conditional_operatorContext::CLOSE_SHARP, py::return_value_policy::automatic_reference)
    .def("OP_NEQ", &ExplorerScriptParser::Conditional_operatorContext::OP_NEQ, py::return_value_policy::automatic_reference)
    .def("OP_AND", &ExplorerScriptParser::Conditional_operatorContext::OP_AND, py::return_value_policy::automatic_reference)
    .def("OP_XOR", &ExplorerScriptParser::Conditional_operatorContext::OP_XOR, py::return_value_policy::automatic_reference)
    .def("OP_BICH", &ExplorerScriptParser::Conditional_operatorContext::OP_BICH, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Conditional_operatorContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Assign_operatorContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assign_operatorContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assign_operatorContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assign_operatorContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assign_operatorContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("OP_MINUS", &ExplorerScriptParser::Assign_operatorContext::OP_MINUS, py::return_value_policy::automatic_reference)
    .def("OP_PLUS", &ExplorerScriptParser::Assign_operatorContext::OP_PLUS, py::return_value_policy::automatic_reference)
    .def("OP_MULTIPLY", &ExplorerScriptParser::Assign_operatorContext::OP_MULTIPLY, py::return_value_policy::automatic_reference)
    .def("OP_DIVIDE", &ExplorerScriptParser::Assign_operatorContext::OP_DIVIDE, py::return_value_policy::automatic_reference)
    .def("ASSIGN", &ExplorerScriptParser::Assign_operatorContext::ASSIGN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Assign_operatorContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::FuncdefContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::FuncdefContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::FuncdefContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::FuncdefContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::FuncdefContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("coro_def", &ExplorerScriptParser::FuncdefContext::coro_def, py::return_value_policy::automatic_reference)
    .def("simple_def", &ExplorerScriptParser::FuncdefContext::simple_def, py::return_value_policy::automatic_reference)
    .def("for_target_def", &ExplorerScriptParser::FuncdefContext::for_target_def, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::FuncdefContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Simple_defContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Simple_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Simple_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Simple_defContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Simple_defContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DEF", &ExplorerScriptParser::Simple_defContext::DEF, py::return_value_policy::automatic_reference)
    .def("INTEGER", &ExplorerScriptParser::Simple_defContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("func_suite", &ExplorerScriptParser::Simple_defContext::func_suite, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Simple_defContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Coro_defContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Coro_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Coro_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Coro_defContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Coro_defContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("CORO", &ExplorerScriptParser::Coro_defContext::CORO, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::Coro_defContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("func_suite", &ExplorerScriptParser::Coro_defContext::func_suite, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Coro_defContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::For_target_defContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::For_target_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::For_target_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::For_target_defContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::For_target_defContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DEF", &ExplorerScriptParser::For_target_defContext::DEF, py::return_value_policy::automatic_reference)
    .def("INTEGER", &ExplorerScriptParser::For_target_defContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("for_target_def_target", &ExplorerScriptParser::For_target_defContext::for_target_def_target, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::For_target_defContext::integer_like, py::return_value_policy::automatic_reference)
    .def("func_suite", &ExplorerScriptParser::For_target_defContext::func_suite, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::For_target_defContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::For_target_defContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::For_target_defContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Integer_likeContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Integer_likeContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Integer_likeContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Integer_likeContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Integer_likeContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DECIMAL", &ExplorerScriptParser::Integer_likeContext::DECIMAL, py::return_value_policy::automatic_reference)
    .def("INTEGER", &ExplorerScriptParser::Integer_likeContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::Integer_likeContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("VARIABLE", &ExplorerScriptParser::Integer_likeContext::VARIABLE, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Integer_likeContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::OperationContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::OperationContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::OperationContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::OperationContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::OperationContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::OperationContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &ExplorerScriptParser::OperationContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &ExplorerScriptParser::OperationContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("inline_ctx", &ExplorerScriptParser::OperationContext::inline_ctx, py::return_value_policy::automatic_reference)
    .def("arglist", &ExplorerScriptParser::OperationContext::arglist, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::OperationContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Inline_ctxContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Inline_ctxContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Inline_ctxContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Inline_ctxContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Inline_ctxContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("OPEN_SHARP", &ExplorerScriptParser::Inline_ctxContext::OPEN_SHARP, py::return_value_policy::automatic_reference)
    .def("ctx_header", &ExplorerScriptParser::Inline_ctxContext::ctx_header, py::return_value_policy::automatic_reference)
    .def("CLOSE_SHARP", &ExplorerScriptParser::Inline_ctxContext::CLOSE_SHARP, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Inline_ctxContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Func_suiteContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Func_suiteContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Func_suiteContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Func_suiteContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Func_suiteContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::Func_suiteContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Func_suiteContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("func_alias", &ExplorerScriptParser::Func_suiteContext::func_alias, py::return_value_policy::automatic_reference)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Func_suiteContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Func_suiteContext::stmt))
    .def("accept", &ExplorerScriptParser::Func_suiteContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Func_aliasContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Func_aliasContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Func_aliasContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Func_aliasContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Func_aliasContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("ALIAS", &ExplorerScriptParser::Func_aliasContext::ALIAS, py::return_value_policy::automatic_reference)
    .def("PREVIOUS", &ExplorerScriptParser::Func_aliasContext::PREVIOUS, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Func_aliasContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::ArglistContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::ArglistContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::ArglistContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::ArglistContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::ArglistContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("pos_argument", py::overload_cast<>(&ExplorerScriptParser::ArglistContext::pos_argument))
    .def("pos_argument", py::overload_cast<size_t>(&ExplorerScriptParser::ArglistContext::pos_argument))
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::ArglistContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::ArglistContext::COMMA))
    .def("accept", &ExplorerScriptParser::ArglistContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Pos_argumentContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Pos_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Pos_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Pos_argumentContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Pos_argumentContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Pos_argumentContext::integer_like, py::return_value_policy::automatic_reference)
    .def("string", &ExplorerScriptParser::Pos_argumentContext::string, py::return_value_policy::automatic_reference)
    .def("position_marker", &ExplorerScriptParser::Pos_argumentContext::position_marker, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Pos_argumentContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Position_markerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Position_markerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Position_markerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Position_markerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Position_markerContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("POSITION", &ExplorerScriptParser::Position_markerContext::POSITION, py::return_value_policy::automatic_reference)
    .def("OPEN_SHARP", &ExplorerScriptParser::Position_markerContext::OPEN_SHARP, py::return_value_policy::automatic_reference)
    .def("STRING_LITERAL", &ExplorerScriptParser::Position_markerContext::STRING_LITERAL, py::return_value_policy::automatic_reference)
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::Position_markerContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::Position_markerContext::COMMA))
    .def("position_marker_arg", py::overload_cast<>(&ExplorerScriptParser::Position_markerContext::position_marker_arg))
    .def("position_marker_arg", py::overload_cast<size_t>(&ExplorerScriptParser::Position_markerContext::position_marker_arg))
    .def("CLOSE_SHARP", &ExplorerScriptParser::Position_markerContext::CLOSE_SHARP, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Position_markerContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Position_marker_argContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Position_marker_argContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Position_marker_argContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Position_marker_argContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Position_marker_argContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("INTEGER", &ExplorerScriptParser::Position_marker_argContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("DECIMAL", &ExplorerScriptParser::Position_marker_argContext::DECIMAL, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Position_marker_argContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::LabelContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::LabelContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::LabelContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::LabelContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::LabelContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::LabelContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("PARAGRAPH", &ExplorerScriptParser::LabelContext::PARAGRAPH, py::return_value_policy::automatic_reference)
    .def("AT", &ExplorerScriptParser::LabelContext::AT, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::LabelContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::StringContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::StringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::StringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::StringContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::StringContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("string_value", &ExplorerScriptParser::StringContext::string_value, py::return_value_policy::automatic_reference)
    .def("lang_string", &ExplorerScriptParser::StringContext::lang_string, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::StringContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Lang_stringContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Lang_stringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Lang_stringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Lang_stringContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Lang_stringContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &ExplorerScriptParser::Lang_stringContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("lang_string_argument", py::overload_cast<>(&ExplorerScriptParser::Lang_stringContext::lang_string_argument))
    .def("lang_string_argument", py::overload_cast<size_t>(&ExplorerScriptParser::Lang_stringContext::lang_string_argument))
    .def("CLOSE_BRACE", &ExplorerScriptParser::Lang_stringContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::Lang_stringContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::Lang_stringContext::COMMA))
    .def("accept", &ExplorerScriptParser::Lang_stringContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Lang_string_argumentContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Lang_string_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Lang_string_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Lang_string_argumentContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Lang_string_argumentContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::Lang_string_argumentContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("ASSIGN", &ExplorerScriptParser::Lang_string_argumentContext::ASSIGN, py::return_value_policy::automatic_reference)
    .def("string_value", &ExplorerScriptParser::Lang_string_argumentContext::string_value, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Lang_string_argumentContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::String_valueContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::String_valueContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::String_valueContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::String_valueContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::String_valueContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("MULTILINE_STRING_LITERAL", &ExplorerScriptParser::String_valueContext::MULTILINE_STRING_LITERAL, py::return_value_policy::automatic_reference)
    .def("STRING_LITERAL", &ExplorerScriptParser::String_valueContext::STRING_LITERAL, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::String_valueContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::Ctx_headerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Ctx_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Ctx_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Ctx_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Ctx_headerContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::Ctx_headerContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("integer_like", &ExplorerScriptParser::Ctx_headerContext::integer_like, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::Ctx_headerContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptParser::For_target_def_targetContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::For_target_def_targetContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::For_target_def_targetContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::For_target_def_targetContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::For_target_def_targetContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("FOR", &ExplorerScriptParser::For_target_def_targetContext::FOR, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &ExplorerScriptParser::For_target_def_targetContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("FOR_TARGET", &ExplorerScriptParser::For_target_def_targetContext::FOR_TARGET, py::return_value_policy::automatic_reference)
    .def("accept", &ExplorerScriptParser::For_target_def_targetContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<ExplorerScriptVisitor, PyExplorerScriptVisitor>(m, "ExplorerScriptVisitor")
    .def(py::init<>())
    .def("visitChildren", [](ExplorerScriptVisitor& self, antlr4::tree::ParseTree* node) {
        return std::any_cast<pybind11::object>(self.visitChildren(node));
    }, py::return_value_policy::automatic_reference)
    .def("defaultResult", [](ExplorerScriptVisitor& self) {
        return std::any_cast<pybind11::object>(self.defaultResult());
    }, py::keep_alive<1, 2>())
    .def("visitStart", &ExplorerScriptVisitor::visitStart, py::return_value_policy::reference_internal)
    .def("visitImport_stmt", &ExplorerScriptVisitor::visitImport_stmt, py::return_value_policy::reference_internal)
    .def("visitMacrodef", &ExplorerScriptVisitor::visitMacrodef, py::return_value_policy::reference_internal)
    .def("visitStmt", &ExplorerScriptVisitor::visitStmt, py::return_value_policy::reference_internal)
    .def("visitSimple_stmt", &ExplorerScriptVisitor::visitSimple_stmt, py::return_value_policy::reference_internal)
    .def("visitCntrl_stmt", &ExplorerScriptVisitor::visitCntrl_stmt, py::return_value_policy::reference_internal)
    .def("visitJump", &ExplorerScriptVisitor::visitJump, py::return_value_policy::reference_internal)
    .def("visitCall", &ExplorerScriptVisitor::visitCall, py::return_value_policy::reference_internal)
    .def("visitMacro_call", &ExplorerScriptVisitor::visitMacro_call, py::return_value_policy::reference_internal)
    .def("visitCtx_block", &ExplorerScriptVisitor::visitCtx_block, py::return_value_policy::reference_internal)
    .def("visitIf_block", &ExplorerScriptVisitor::visitIf_block, py::return_value_policy::reference_internal)
    .def("visitElseif_block", &ExplorerScriptVisitor::visitElseif_block, py::return_value_policy::reference_internal)
    .def("visitElse_block", &ExplorerScriptVisitor::visitElse_block, py::return_value_policy::reference_internal)
    .def("visitIf_header", &ExplorerScriptVisitor::visitIf_header, py::return_value_policy::reference_internal)
    .def("visitIf_h_negatable", &ExplorerScriptVisitor::visitIf_h_negatable, py::return_value_policy::reference_internal)
    .def("visitIf_h_op", &ExplorerScriptVisitor::visitIf_h_op, py::return_value_policy::reference_internal)
    .def("visitIf_h_bit", &ExplorerScriptVisitor::visitIf_h_bit, py::return_value_policy::reference_internal)
    .def("visitIf_h_scn", &ExplorerScriptVisitor::visitIf_h_scn, py::return_value_policy::reference_internal)
    .def("visitSwitch_block", &ExplorerScriptVisitor::visitSwitch_block, py::return_value_policy::reference_internal)
    .def("visitMessage_switch_block", &ExplorerScriptVisitor::visitMessage_switch_block, py::return_value_policy::reference_internal)
    .def("visitSingle_case_block", &ExplorerScriptVisitor::visitSingle_case_block, py::return_value_policy::reference_internal)
    .def("visitDefault", &ExplorerScriptVisitor::visitDefault, py::return_value_policy::reference_internal)
    .def("visitSwitch_header", &ExplorerScriptVisitor::visitSwitch_header, py::return_value_policy::reference_internal)
    .def("visitSwitch_h_scn", &ExplorerScriptVisitor::visitSwitch_h_scn, py::return_value_policy::reference_internal)
    .def("visitSwitch_h_random", &ExplorerScriptVisitor::visitSwitch_h_random, py::return_value_policy::reference_internal)
    .def("visitSwitch_h_dungeon_mode", &ExplorerScriptVisitor::visitSwitch_h_dungeon_mode, py::return_value_policy::reference_internal)
    .def("visitSwitch_h_sector", &ExplorerScriptVisitor::visitSwitch_h_sector, py::return_value_policy::reference_internal)
    .def("visitCase_header", &ExplorerScriptVisitor::visitCase_header, py::return_value_policy::reference_internal)
    .def("visitCase_h_menu", &ExplorerScriptVisitor::visitCase_h_menu, py::return_value_policy::reference_internal)
    .def("visitCase_h_menu2", &ExplorerScriptVisitor::visitCase_h_menu2, py::return_value_policy::reference_internal)
    .def("visitCase_h_op", &ExplorerScriptVisitor::visitCase_h_op, py::return_value_policy::reference_internal)
    .def("visitForever_block", &ExplorerScriptVisitor::visitForever_block, py::return_value_policy::reference_internal)
    .def("visitFor_block", &ExplorerScriptVisitor::visitFor_block, py::return_value_policy::reference_internal)
    .def("visitWhile_block", &ExplorerScriptVisitor::visitWhile_block, py::return_value_policy::reference_internal)
    .def("visitAssignment", &ExplorerScriptVisitor::visitAssignment, py::return_value_policy::reference_internal)
    .def("visitAssignment_regular", &ExplorerScriptVisitor::visitAssignment_regular, py::return_value_policy::reference_internal)
    .def("visitAssignment_clear", &ExplorerScriptVisitor::visitAssignment_clear, py::return_value_policy::reference_internal)
    .def("visitAssignment_initial", &ExplorerScriptVisitor::visitAssignment_initial, py::return_value_policy::reference_internal)
    .def("visitAssignment_reset", &ExplorerScriptVisitor::visitAssignment_reset, py::return_value_policy::reference_internal)
    .def("visitAssignment_adv_log", &ExplorerScriptVisitor::visitAssignment_adv_log, py::return_value_policy::reference_internal)
    .def("visitAssignment_dungeon_mode", &ExplorerScriptVisitor::visitAssignment_dungeon_mode, py::return_value_policy::reference_internal)
    .def("visitAssignment_scn", &ExplorerScriptVisitor::visitAssignment_scn, py::return_value_policy::reference_internal)
    .def("visitValue_of", &ExplorerScriptVisitor::visitValue_of, py::return_value_policy::reference_internal)
    .def("visitScn_var", &ExplorerScriptVisitor::visitScn_var, py::return_value_policy::reference_internal)
    .def("visitConditional_operator", &ExplorerScriptVisitor::visitConditional_operator, py::return_value_policy::reference_internal)
    .def("visitAssign_operator", &ExplorerScriptVisitor::visitAssign_operator, py::return_value_policy::reference_internal)
    .def("visitFuncdef", &ExplorerScriptVisitor::visitFuncdef, py::return_value_policy::reference_internal)
    .def("visitSimple_def", &ExplorerScriptVisitor::visitSimple_def, py::return_value_policy::reference_internal)
    .def("visitCoro_def", &ExplorerScriptVisitor::visitCoro_def, py::return_value_policy::reference_internal)
    .def("visitFor_target_def", &ExplorerScriptVisitor::visitFor_target_def, py::return_value_policy::reference_internal)
    .def("visitInteger_like", &ExplorerScriptVisitor::visitInteger_like, py::return_value_policy::reference_internal)
    .def("visitOperation", &ExplorerScriptVisitor::visitOperation, py::return_value_policy::reference_internal)
    .def("visitInline_ctx", &ExplorerScriptVisitor::visitInline_ctx, py::return_value_policy::reference_internal)
    .def("visitFunc_suite", &ExplorerScriptVisitor::visitFunc_suite, py::return_value_policy::reference_internal)
    .def("visitFunc_alias", &ExplorerScriptVisitor::visitFunc_alias, py::return_value_policy::reference_internal)
    .def("visitArglist", &ExplorerScriptVisitor::visitArglist, py::return_value_policy::reference_internal)
    .def("visitPos_argument", &ExplorerScriptVisitor::visitPos_argument, py::return_value_policy::reference_internal)
    .def("visitPosition_marker", &ExplorerScriptVisitor::visitPosition_marker, py::return_value_policy::reference_internal)
    .def("visitPosition_marker_arg", &ExplorerScriptVisitor::visitPosition_marker_arg, py::return_value_policy::reference_internal)
    .def("visitLabel", &ExplorerScriptVisitor::visitLabel, py::return_value_policy::reference_internal)
    .def("visitString", &ExplorerScriptVisitor::visitString, py::return_value_policy::reference_internal)
    .def("visitLang_string", &ExplorerScriptVisitor::visitLang_string, py::return_value_policy::reference_internal)
    .def("visitLang_string_argument", &ExplorerScriptVisitor::visitLang_string_argument, py::return_value_policy::reference_internal)
    .def("visitString_value", &ExplorerScriptVisitor::visitString_value, py::return_value_policy::reference_internal)
    .def("visitCtx_header", &ExplorerScriptVisitor::visitCtx_header, py::return_value_policy::reference_internal)
    .def("visitFor_target_def_target", &ExplorerScriptVisitor::visitFor_target_def_target, py::return_value_policy::reference_internal)
;py::class_<SsbScriptParser::Pos_argumentContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Pos_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Pos_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Pos_argumentContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Pos_argumentContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("integer_like", &SsbScriptParser::Pos_argumentContext::integer_like, py::return_value_policy::automatic_reference)
    .def("string", &SsbScriptParser::Pos_argumentContext::string, py::return_value_policy::automatic_reference)
    .def("position_marker", &SsbScriptParser::Pos_argumentContext::position_marker, py::return_value_policy::automatic_reference)
    .def("jump_marker", &SsbScriptParser::Pos_argumentContext::jump_marker, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Pos_argumentContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Jump_markerContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Jump_markerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Jump_markerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Jump_markerContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Jump_markerContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("AT", &SsbScriptParser::Jump_markerContext::AT, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &SsbScriptParser::Jump_markerContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Jump_markerContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::StartContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::StartContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::StartContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::StartContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::StartContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("EOF", &SsbScriptParser::StartContext::EOF, py::return_value_policy::automatic_reference)
    .def("funcdef", py::overload_cast<>(&SsbScriptParser::StartContext::funcdef))
    .def("funcdef", py::overload_cast<size_t>(&SsbScriptParser::StartContext::funcdef))
    .def("accept", &SsbScriptParser::StartContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::FuncdefContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::FuncdefContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::FuncdefContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::FuncdefContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::FuncdefContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("coro_def", &SsbScriptParser::FuncdefContext::coro_def, py::return_value_policy::automatic_reference)
    .def("simple_def", &SsbScriptParser::FuncdefContext::simple_def, py::return_value_policy::automatic_reference)
    .def("for_target_def", &SsbScriptParser::FuncdefContext::for_target_def, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::FuncdefContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Simple_defContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Simple_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Simple_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Simple_defContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Simple_defContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DEF", &SsbScriptParser::Simple_defContext::DEF, py::return_value_policy::automatic_reference)
    .def("INTEGER", &SsbScriptParser::Simple_defContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("func_suite", &SsbScriptParser::Simple_defContext::func_suite, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Simple_defContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Coro_defContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Coro_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Coro_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Coro_defContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Coro_defContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("CORO", &SsbScriptParser::Coro_defContext::CORO, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &SsbScriptParser::Coro_defContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("func_suite", &SsbScriptParser::Coro_defContext::func_suite, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Coro_defContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::For_target_defContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::For_target_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::For_target_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::For_target_defContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::For_target_defContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DEF", &SsbScriptParser::For_target_defContext::DEF, py::return_value_policy::automatic_reference)
    .def("INTEGER", &SsbScriptParser::For_target_defContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("for_target_def_target", &SsbScriptParser::For_target_defContext::for_target_def_target, py::return_value_policy::automatic_reference)
    .def("integer_like", &SsbScriptParser::For_target_defContext::integer_like, py::return_value_policy::automatic_reference)
    .def("func_suite", &SsbScriptParser::For_target_defContext::func_suite, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &SsbScriptParser::For_target_defContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &SsbScriptParser::For_target_defContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::For_target_defContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Integer_likeContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Integer_likeContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Integer_likeContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Integer_likeContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Integer_likeContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("DECIMAL", &SsbScriptParser::Integer_likeContext::DECIMAL, py::return_value_policy::automatic_reference)
    .def("INTEGER", &SsbScriptParser::Integer_likeContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &SsbScriptParser::Integer_likeContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("VARIABLE", &SsbScriptParser::Integer_likeContext::VARIABLE, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Integer_likeContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::StmtContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::StmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::StmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::StmtContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::StmtContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("operation", &SsbScriptParser::StmtContext::operation, py::return_value_policy::automatic_reference)
    .def("label", &SsbScriptParser::StmtContext::label, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::StmtContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::OperationContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::OperationContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::OperationContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::OperationContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::OperationContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &SsbScriptParser::OperationContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("OPEN_PAREN", &SsbScriptParser::OperationContext::OPEN_PAREN, py::return_value_policy::automatic_reference)
    .def("CLOSE_PAREN", &SsbScriptParser::OperationContext::CLOSE_PAREN, py::return_value_policy::automatic_reference)
    .def("inline_ctx", &SsbScriptParser::OperationContext::inline_ctx, py::return_value_policy::automatic_reference)
    .def("arglist", &SsbScriptParser::OperationContext::arglist, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::OperationContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Inline_ctxContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Inline_ctxContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Inline_ctxContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Inline_ctxContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Inline_ctxContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("OPEN_SHARP", &SsbScriptParser::Inline_ctxContext::OPEN_SHARP, py::return_value_policy::automatic_reference)
    .def("ctx_header", &SsbScriptParser::Inline_ctxContext::ctx_header, py::return_value_policy::automatic_reference)
    .def("CLOSE_SHARP", &SsbScriptParser::Inline_ctxContext::CLOSE_SHARP, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Inline_ctxContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Func_suiteContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Func_suiteContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Func_suiteContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Func_suiteContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Func_suiteContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &SsbScriptParser::Func_suiteContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("CLOSE_BRACE", &SsbScriptParser::Func_suiteContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("func_alias", &SsbScriptParser::Func_suiteContext::func_alias, py::return_value_policy::automatic_reference)
    .def("stmt", py::overload_cast<>(&SsbScriptParser::Func_suiteContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&SsbScriptParser::Func_suiteContext::stmt))
    .def("accept", &SsbScriptParser::Func_suiteContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Func_aliasContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Func_aliasContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Func_aliasContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Func_aliasContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Func_aliasContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("ALIAS", &SsbScriptParser::Func_aliasContext::ALIAS, py::return_value_policy::automatic_reference)
    .def("PREVIOUS", &SsbScriptParser::Func_aliasContext::PREVIOUS, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Func_aliasContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::ArglistContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::ArglistContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::ArglistContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::ArglistContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::ArglistContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("pos_argument", py::overload_cast<>(&SsbScriptParser::ArglistContext::pos_argument))
    .def("pos_argument", py::overload_cast<size_t>(&SsbScriptParser::ArglistContext::pos_argument))
    .def("COMMA", py::overload_cast<>(&SsbScriptParser::ArglistContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&SsbScriptParser::ArglistContext::COMMA))
    .def("accept", &SsbScriptParser::ArglistContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Position_markerContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Position_markerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Position_markerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Position_markerContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Position_markerContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("POSITION", &SsbScriptParser::Position_markerContext::POSITION, py::return_value_policy::automatic_reference)
    .def("OPEN_SHARP", &SsbScriptParser::Position_markerContext::OPEN_SHARP, py::return_value_policy::automatic_reference)
    .def("STRING_LITERAL", &SsbScriptParser::Position_markerContext::STRING_LITERAL, py::return_value_policy::automatic_reference)
    .def("COMMA", py::overload_cast<>(&SsbScriptParser::Position_markerContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&SsbScriptParser::Position_markerContext::COMMA))
    .def("position_marker_arg", py::overload_cast<>(&SsbScriptParser::Position_markerContext::position_marker_arg))
    .def("position_marker_arg", py::overload_cast<size_t>(&SsbScriptParser::Position_markerContext::position_marker_arg))
    .def("CLOSE_SHARP", &SsbScriptParser::Position_markerContext::CLOSE_SHARP, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Position_markerContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Position_marker_argContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Position_marker_argContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Position_marker_argContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Position_marker_argContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Position_marker_argContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("INTEGER", &SsbScriptParser::Position_marker_argContext::INTEGER, py::return_value_policy::automatic_reference)
    .def("DECIMAL", &SsbScriptParser::Position_marker_argContext::DECIMAL, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Position_marker_argContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::LabelContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::LabelContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::LabelContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::LabelContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::LabelContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &SsbScriptParser::LabelContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("PARAGRAPH", &SsbScriptParser::LabelContext::PARAGRAPH, py::return_value_policy::automatic_reference)
    .def("AT", &SsbScriptParser::LabelContext::AT, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::LabelContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::StringContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::StringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::StringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::StringContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::StringContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("string_value", &SsbScriptParser::StringContext::string_value, py::return_value_policy::automatic_reference)
    .def("lang_string", &SsbScriptParser::StringContext::lang_string, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::StringContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Lang_stringContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Lang_stringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Lang_stringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Lang_stringContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Lang_stringContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("OPEN_BRACE", &SsbScriptParser::Lang_stringContext::OPEN_BRACE, py::return_value_policy::automatic_reference)
    .def("lang_string_argument", py::overload_cast<>(&SsbScriptParser::Lang_stringContext::lang_string_argument))
    .def("lang_string_argument", py::overload_cast<size_t>(&SsbScriptParser::Lang_stringContext::lang_string_argument))
    .def("CLOSE_BRACE", &SsbScriptParser::Lang_stringContext::CLOSE_BRACE, py::return_value_policy::automatic_reference)
    .def("COMMA", py::overload_cast<>(&SsbScriptParser::Lang_stringContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&SsbScriptParser::Lang_stringContext::COMMA))
    .def("accept", &SsbScriptParser::Lang_stringContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Lang_string_argumentContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Lang_string_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Lang_string_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Lang_string_argumentContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Lang_string_argumentContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &SsbScriptParser::Lang_string_argumentContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("ASSIGN", &SsbScriptParser::Lang_string_argumentContext::ASSIGN, py::return_value_policy::automatic_reference)
    .def("string_value", &SsbScriptParser::Lang_string_argumentContext::string_value, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Lang_string_argumentContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::String_valueContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::String_valueContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::String_valueContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::String_valueContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::String_valueContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("MULTILINE_STRING_LITERAL", &SsbScriptParser::String_valueContext::MULTILINE_STRING_LITERAL, py::return_value_policy::automatic_reference)
    .def("STRING_LITERAL", &SsbScriptParser::String_valueContext::STRING_LITERAL, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::String_valueContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::Ctx_headerContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::Ctx_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Ctx_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Ctx_headerContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Ctx_headerContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &SsbScriptParser::Ctx_headerContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("integer_like", &SsbScriptParser::Ctx_headerContext::integer_like, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::Ctx_headerContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptParser::For_target_def_targetContext, antlr4::ParserRuleContext>(m, "SsbScriptParser::For_target_def_targetContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::For_target_def_targetContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::For_target_def_targetContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::For_target_def_targetContext::getRuleIndex, py::return_value_policy::automatic_reference)
    .def("FOR", &SsbScriptParser::For_target_def_targetContext::FOR, py::return_value_policy::automatic_reference)
    .def("IDENTIFIER", &SsbScriptParser::For_target_def_targetContext::IDENTIFIER, py::return_value_policy::automatic_reference)
    .def("FOR_TARGET", &SsbScriptParser::For_target_def_targetContext::FOR_TARGET, py::return_value_policy::automatic_reference)
    .def("accept", &SsbScriptParser::For_target_def_targetContext::accept, py::return_value_policy::automatic_reference)
;
py::class_<SsbScriptVisitor, PySsbScriptVisitor>(m, "SsbScriptVisitor")
    .def(py::init<>())
    .def("visitChildren", [](SsbScriptVisitor& self, antlr4::tree::ParseTree* node) {
        return std::any_cast<pybind11::object>(self.visitChildren(node));
    }, py::return_value_policy::automatic_reference)
    .def("defaultResult", [](SsbScriptVisitor& self) {
        return std::any_cast<pybind11::object>(self.defaultResult());
    }, py::keep_alive<1, 2>())
    .def("visitPos_argument", &SsbScriptVisitor::visitPos_argument, py::return_value_policy::reference_internal)
    .def("visitJump_marker", &SsbScriptVisitor::visitJump_marker, py::return_value_policy::reference_internal)
    .def("visitStart", &SsbScriptVisitor::visitStart, py::return_value_policy::reference_internal)
    .def("visitFuncdef", &SsbScriptVisitor::visitFuncdef, py::return_value_policy::reference_internal)
    .def("visitSimple_def", &SsbScriptVisitor::visitSimple_def, py::return_value_policy::reference_internal)
    .def("visitCoro_def", &SsbScriptVisitor::visitCoro_def, py::return_value_policy::reference_internal)
    .def("visitFor_target_def", &SsbScriptVisitor::visitFor_target_def, py::return_value_policy::reference_internal)
    .def("visitInteger_like", &SsbScriptVisitor::visitInteger_like, py::return_value_policy::reference_internal)
    .def("visitStmt", &SsbScriptVisitor::visitStmt, py::return_value_policy::reference_internal)
    .def("visitOperation", &SsbScriptVisitor::visitOperation, py::return_value_policy::reference_internal)
    .def("visitInline_ctx", &SsbScriptVisitor::visitInline_ctx, py::return_value_policy::reference_internal)
    .def("visitFunc_suite", &SsbScriptVisitor::visitFunc_suite, py::return_value_policy::reference_internal)
    .def("visitFunc_alias", &SsbScriptVisitor::visitFunc_alias, py::return_value_policy::reference_internal)
    .def("visitArglist", &SsbScriptVisitor::visitArglist, py::return_value_policy::reference_internal)
    .def("visitPosition_marker", &SsbScriptVisitor::visitPosition_marker, py::return_value_policy::reference_internal)
    .def("visitPosition_marker_arg", &SsbScriptVisitor::visitPosition_marker_arg, py::return_value_policy::reference_internal)
    .def("visitLabel", &SsbScriptVisitor::visitLabel, py::return_value_policy::reference_internal)
    .def("visitString", &SsbScriptVisitor::visitString, py::return_value_policy::reference_internal)
    .def("visitLang_string", &SsbScriptVisitor::visitLang_string, py::return_value_policy::reference_internal)
    .def("visitLang_string_argument", &SsbScriptVisitor::visitLang_string_argument, py::return_value_policy::reference_internal)
    .def("visitString_value", &SsbScriptVisitor::visitString_value, py::return_value_policy::reference_internal)
    .def("visitCtx_header", &SsbScriptVisitor::visitCtx_header, py::return_value_policy::reference_internal)
    .def("visitFor_target_def_target", &SsbScriptVisitor::visitFor_target_def_target, py::return_value_policy::reference_internal)
;}