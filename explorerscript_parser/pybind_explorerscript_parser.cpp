#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "antlr4-runtime.h"
#include "ExplorerScriptLexer.h"
#include "ExplorerScriptParser.h"
#include "ExplorerScriptBaseVisitor.h"
#include "SsbScriptLexer.h"
#include "SsbScriptParser.h"
#include "SsbScriptBaseVisitor.h"
#include "parser_wrapper_exps.h"
#include "parser_wrapper_ssbs.h"

using namespace antlr4;
namespace py = pybind11;

class PyErrorListener : public ANTLRErrorListener {
public:
    PyErrorListener() {}

    void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override {
        PYBIND11_OVERRIDE_PURE(
            void,
            ANTLRErrorListener,
            syntaxError,
            recognizer, offendingSymbol, line, charPositionInLine, msg, e
        );
    }
    
    void reportAmbiguity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, bool exact, const antlrcpp::BitSet &ambigAlts, atn::ATNConfigSet *configs) override {}
    void reportAttemptingFullContext(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, const antlrcpp::BitSet &conflictingAlts, atn::ATNConfigSet *configs) override {}
    void reportContextSensitivity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, size_t prediction, atn::ATNConfigSet *configs) override {}
};
class PyExplorerScriptBaseVisitor : public ExplorerScriptBaseVisitor {
public:
    /* Inherit the constructors */
    using ExplorerScriptBaseVisitor::ExplorerScriptBaseVisitor;

    std::any visitStart(ExplorerScriptParser::StartContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitStart,
            context
        );
    }
    std::any visitImport_stmt(ExplorerScriptParser::Import_stmtContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitImport_stmt,
            context
        );
    }
    std::any visitConstant_assign(ExplorerScriptParser::Constant_assignContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitConstant_assign,
            context
        );
    }
    std::any visitMacrodef(ExplorerScriptParser::MacrodefContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitMacrodef,
            context
        );
    }
    std::any visitStmt(ExplorerScriptParser::StmtContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitStmt,
            context
        );
    }
    std::any visitSimple_stmt(ExplorerScriptParser::Simple_stmtContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitSimple_stmt,
            context
        );
    }
    std::any visitCntrl_stmt(ExplorerScriptParser::Cntrl_stmtContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitCntrl_stmt,
            context
        );
    }
    std::any visitJump(ExplorerScriptParser::JumpContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitJump,
            context
        );
    }
    std::any visitCall(ExplorerScriptParser::CallContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitCall,
            context
        );
    }
    std::any visitMacro_call(ExplorerScriptParser::Macro_callContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitMacro_call,
            context
        );
    }
    std::any visitCtx_block(ExplorerScriptParser::Ctx_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitCtx_block,
            context
        );
    }
    std::any visitIf_block(ExplorerScriptParser::If_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitIf_block,
            context
        );
    }
    std::any visitElseif_block(ExplorerScriptParser::Elseif_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitElseif_block,
            context
        );
    }
    std::any visitElse_block(ExplorerScriptParser::Else_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitElse_block,
            context
        );
    }
    std::any visitIf_header(ExplorerScriptParser::If_headerContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitIf_header,
            context
        );
    }
    std::any visitIf_h_negatable(ExplorerScriptParser::If_h_negatableContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitIf_h_negatable,
            context
        );
    }
    std::any visitIf_h_op(ExplorerScriptParser::If_h_opContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitIf_h_op,
            context
        );
    }
    std::any visitIf_h_bit(ExplorerScriptParser::If_h_bitContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitIf_h_bit,
            context
        );
    }
    std::any visitIf_h_scn(ExplorerScriptParser::If_h_scnContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitIf_h_scn,
            context
        );
    }
    std::any visitSwitch_block(ExplorerScriptParser::Switch_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitSwitch_block,
            context
        );
    }
    std::any visitMessage_switch_block(ExplorerScriptParser::Message_switch_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitMessage_switch_block,
            context
        );
    }
    std::any visitSingle_case_block(ExplorerScriptParser::Single_case_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitSingle_case_block,
            context
        );
    }
    std::any visitDefault(ExplorerScriptParser::DefaultContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitDefault,
            context
        );
    }
    std::any visitSwitch_header(ExplorerScriptParser::Switch_headerContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitSwitch_header,
            context
        );
    }
    std::any visitSwitch_h_scn(ExplorerScriptParser::Switch_h_scnContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitSwitch_h_scn,
            context
        );
    }
    std::any visitSwitch_h_random(ExplorerScriptParser::Switch_h_randomContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitSwitch_h_random,
            context
        );
    }
    std::any visitSwitch_h_dungeon_mode(ExplorerScriptParser::Switch_h_dungeon_modeContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitSwitch_h_dungeon_mode,
            context
        );
    }
    std::any visitSwitch_h_sector(ExplorerScriptParser::Switch_h_sectorContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitSwitch_h_sector,
            context
        );
    }
    std::any visitCase_header(ExplorerScriptParser::Case_headerContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitCase_header,
            context
        );
    }
    std::any visitCase_h_menu(ExplorerScriptParser::Case_h_menuContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitCase_h_menu,
            context
        );
    }
    std::any visitCase_h_menu2(ExplorerScriptParser::Case_h_menu2Context *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitCase_h_menu2,
            context
        );
    }
    std::any visitCase_h_op(ExplorerScriptParser::Case_h_opContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitCase_h_op,
            context
        );
    }
    std::any visitForever_block(ExplorerScriptParser::Forever_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitForever_block,
            context
        );
    }
    std::any visitFor_block(ExplorerScriptParser::For_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitFor_block,
            context
        );
    }
    std::any visitWhile_block(ExplorerScriptParser::While_blockContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitWhile_block,
            context
        );
    }
    std::any visitAssignment(ExplorerScriptParser::AssignmentContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitAssignment,
            context
        );
    }
    std::any visitAssignment_regular(ExplorerScriptParser::Assignment_regularContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitAssignment_regular,
            context
        );
    }
    std::any visitAssignment_clear(ExplorerScriptParser::Assignment_clearContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitAssignment_clear,
            context
        );
    }
    std::any visitAssignment_initial(ExplorerScriptParser::Assignment_initialContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitAssignment_initial,
            context
        );
    }
    std::any visitAssignment_reset(ExplorerScriptParser::Assignment_resetContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitAssignment_reset,
            context
        );
    }
    std::any visitAssignment_adv_log(ExplorerScriptParser::Assignment_adv_logContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitAssignment_adv_log,
            context
        );
    }
    std::any visitAssignment_dungeon_mode(ExplorerScriptParser::Assignment_dungeon_modeContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitAssignment_dungeon_mode,
            context
        );
    }
    std::any visitAssignment_scn(ExplorerScriptParser::Assignment_scnContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitAssignment_scn,
            context
        );
    }
    std::any visitValue_of(ExplorerScriptParser::Value_ofContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitValue_of,
            context
        );
    }
    std::any visitScn_var(ExplorerScriptParser::Scn_varContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitScn_var,
            context
        );
    }
    std::any visitConditional_operator(ExplorerScriptParser::Conditional_operatorContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitConditional_operator,
            context
        );
    }
    std::any visitAssign_operator(ExplorerScriptParser::Assign_operatorContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitAssign_operator,
            context
        );
    }
    std::any visitFuncdef(ExplorerScriptParser::FuncdefContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitFuncdef,
            context
        );
    }
    std::any visitSimple_def(ExplorerScriptParser::Simple_defContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitSimple_def,
            context
        );
    }
    std::any visitCoro_def(ExplorerScriptParser::Coro_defContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitCoro_def,
            context
        );
    }
    std::any visitFor_target_def(ExplorerScriptParser::For_target_defContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitFor_target_def,
            context
        );
    }
    std::any visitPrimitive(ExplorerScriptParser::PrimitiveContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitPrimitive,
            context
        );
    }
    std::any visitOperation(ExplorerScriptParser::OperationContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitOperation,
            context
        );
    }
    std::any visitInline_ctx(ExplorerScriptParser::Inline_ctxContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitInline_ctx,
            context
        );
    }
    std::any visitFunc_suite(ExplorerScriptParser::Func_suiteContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitFunc_suite,
            context
        );
    }
    std::any visitFunc_alias(ExplorerScriptParser::Func_aliasContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitFunc_alias,
            context
        );
    }
    std::any visitArglist(ExplorerScriptParser::ArglistContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitArglist,
            context
        );
    }
    std::any visitPos_argument(ExplorerScriptParser::Pos_argumentContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitPos_argument,
            context
        );
    }
    std::any visitPosition_marker(ExplorerScriptParser::Position_markerContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitPosition_marker,
            context
        );
    }
    std::any visitPosition_marker_arg(ExplorerScriptParser::Position_marker_argContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitPosition_marker_arg,
            context
        );
    }
    std::any visitLabel(ExplorerScriptParser::LabelContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitLabel,
            context
        );
    }
    std::any visitString(ExplorerScriptParser::StringContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitString,
            context
        );
    }
    std::any visitLang_string(ExplorerScriptParser::Lang_stringContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitLang_string,
            context
        );
    }
    std::any visitLang_string_argument(ExplorerScriptParser::Lang_string_argumentContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitLang_string_argument,
            context
        );
    }
    std::any visitString_value(ExplorerScriptParser::String_valueContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitString_value,
            context
        );
    }
    std::any visitCtx_header(ExplorerScriptParser::Ctx_headerContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitCtx_header,
            context
        );
    }
    std::any visitFor_target_def_target(ExplorerScriptParser::For_target_def_targetContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitFor_target_def_target,
            context
        );
    }
    std::any defaultResult() override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            defaultResult
        );
    }}
    std::any visitChildren(antlr4::tree::ParseTree *node) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitChildren,
            node
        );
    }}
    std::any aggregateResult(std::any aggregate, std::any nextResult) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            aggregateResult,
            std::any_cast<pybind11::object>(aggregate), std::any_cast<pybind11::object>(nextResult)
        );
    }}
    std::any visitTerminal(antlr4::tree::TerminalNode * node) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visitTerminal,
            node
        );
    }}
    std::any visit(antlr4::tree::ParseTree *tree) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            ExplorerScriptBaseVisitor,
            visit,
            tree
        );
    }}
};class PySsbScriptBaseVisitor : public SsbScriptBaseVisitor {
public:
    /* Inherit the constructors */
    using SsbScriptBaseVisitor::SsbScriptBaseVisitor;

    std::any visitPos_argument(SsbScriptParser::Pos_argumentContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitPos_argument,
            context
        );
    }
    std::any visitJump_marker(SsbScriptParser::Jump_markerContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitJump_marker,
            context
        );
    }
    std::any visitStart(SsbScriptParser::StartContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitStart,
            context
        );
    }
    std::any visitFuncdef(SsbScriptParser::FuncdefContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitFuncdef,
            context
        );
    }
    std::any visitSimple_def(SsbScriptParser::Simple_defContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitSimple_def,
            context
        );
    }
    std::any visitCoro_def(SsbScriptParser::Coro_defContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitCoro_def,
            context
        );
    }
    std::any visitFor_target_def(SsbScriptParser::For_target_defContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitFor_target_def,
            context
        );
    }
    std::any visitPrimitive(SsbScriptParser::PrimitiveContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitPrimitive,
            context
        );
    }
    std::any visitStmt(SsbScriptParser::StmtContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitStmt,
            context
        );
    }
    std::any visitOperation(SsbScriptParser::OperationContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitOperation,
            context
        );
    }
    std::any visitInline_ctx(SsbScriptParser::Inline_ctxContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitInline_ctx,
            context
        );
    }
    std::any visitFunc_suite(SsbScriptParser::Func_suiteContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitFunc_suite,
            context
        );
    }
    std::any visitFunc_alias(SsbScriptParser::Func_aliasContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitFunc_alias,
            context
        );
    }
    std::any visitArglist(SsbScriptParser::ArglistContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitArglist,
            context
        );
    }
    std::any visitPosition_marker(SsbScriptParser::Position_markerContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitPosition_marker,
            context
        );
    }
    std::any visitPosition_marker_arg(SsbScriptParser::Position_marker_argContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitPosition_marker_arg,
            context
        );
    }
    std::any visitLabel(SsbScriptParser::LabelContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitLabel,
            context
        );
    }
    std::any visitString(SsbScriptParser::StringContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitString,
            context
        );
    }
    std::any visitLang_string(SsbScriptParser::Lang_stringContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitLang_string,
            context
        );
    }
    std::any visitLang_string_argument(SsbScriptParser::Lang_string_argumentContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitLang_string_argument,
            context
        );
    }
    std::any visitString_value(SsbScriptParser::String_valueContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitString_value,
            context
        );
    }
    std::any visitCtx_header(SsbScriptParser::Ctx_headerContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitCtx_header,
            context
        );
    }
    std::any visitFor_target_def_target(SsbScriptParser::For_target_def_targetContext *context) override {
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitFor_target_def_target,
            context
        );
    }
    std::any defaultResult() override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            defaultResult
        );
    }}
    std::any visitChildren(antlr4::tree::ParseTree *node) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitChildren,
            node
        );
    }}
    std::any aggregateResult(std::any aggregate, std::any nextResult) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            aggregateResult,
            std::any_cast<pybind11::object>(aggregate), std::any_cast<pybind11::object>(nextResult)
        );
    }}
    std::any visitTerminal(antlr4::tree::TerminalNode * node) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visitTerminal,
            node
        );
    }}
    std::any visit(antlr4::tree::ParseTree *tree) override {{
        PYBIND11_OVERRIDE(
            pybind11::object,
            SsbScriptBaseVisitor,
            visit,
            tree
        );
    }}
};
PYBIND11_MODULE(explorerscript_parser, m) {

py::class_<antlr4::tree::ParseTreeVisitor>(m, "Antlr4TreeParseTreeVisitor");

py::class_<ANTLRErrorListener, PyErrorListener>(m, "Antlr4ErrorListener")
    .def(py::init<>())
    .def("syntaxError", &ANTLRErrorListener::syntaxError, py::return_value_policy::reference_internal);

py::class_<ExplorerScriptParserWrapper>(m, "ExplorerScriptParserWrapper")
    .def(py::init<std::string&, ANTLRErrorListener*>(), py::keep_alive<1, 3>())
    .def_property_readonly("tree", &ExplorerScriptParserWrapper::getTree, py::return_value_policy::reference_internal)
    .def("traverse", &ExplorerScriptParserWrapper::traverse, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal);
py::class_<SsbScriptParserWrapper>(m, "SsbScriptParserWrapper")
    .def(py::init<std::string&, ANTLRErrorListener*>(), py::keep_alive<1, 3>())
    .def_property_readonly("tree", &SsbScriptParserWrapper::getTree, py::return_value_policy::reference_internal)
    .def("traverse", &SsbScriptParserWrapper::traverse, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal);

py::class_<antlr4::tree::TerminalNode>(m, "Antlr4TreeTerminalNode")
    .def("__str__", &antlr4::tree::TerminalNode::toString)
    .def_property_readonly("symbol", &antlr4::tree::TerminalNode::getSymbol, py::return_value_policy::reference_internal);

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

py::class_<std::exception_ptr>(m, "CppExceptionPtr");
py::class_<antlr4::Recognizer>(m, "Antlr4Recognizer");
py::class_<antlr4::tree::ParseTree>(m, "Antlr4ParseTree");
py::class_<antlr4::RuleContext, antlr4::tree::ParseTree>(m, "Antlr4RuleContext");
py::class_<antlr4::ParserRuleContext, antlr4::RuleContext>(m, "Antlr4ParserRuleContext")
    .def(py::init<>())
    .def_property_readonly("start", &antlr4::ParserRuleContext::getStart, py::return_value_policy::reference_internal)
    .def_property_readonly("stop", &antlr4::ParserRuleContext::getStop, py::return_value_policy::reference_internal);


auto m_parser_sub_ExplorerScript = m.def_submodule("ExplorerScriptParser");
py::class_<ExplorerScriptParser::StartContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "StartContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::StartContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::StartContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::StartContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("EOF", &ExplorerScriptParser::StartContext::EOF, py::return_value_policy::reference_internal)
    .def("import_stmt", py::overload_cast<>(&ExplorerScriptParser::StartContext::import_stmt), py::return_value_policy::reference_internal)
    .def("import_stmt", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::import_stmt), py::return_value_policy::reference_internal)
    .def("macrodef", py::overload_cast<>(&ExplorerScriptParser::StartContext::macrodef), py::return_value_policy::reference_internal)
    .def("macrodef", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::macrodef), py::return_value_policy::reference_internal)
    .def("funcdef", py::overload_cast<>(&ExplorerScriptParser::StartContext::funcdef), py::return_value_policy::reference_internal)
    .def("funcdef", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::funcdef), py::return_value_policy::reference_internal)
    .def("constant_assign", py::overload_cast<>(&ExplorerScriptParser::StartContext::constant_assign), py::return_value_policy::reference_internal)
    .def("constant_assign", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::constant_assign), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::StartContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Import_stmtContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Import_stmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Import_stmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Import_stmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Import_stmtContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IMPORT", &ExplorerScriptParser::Import_stmtContext::IMPORT, py::return_value_policy::reference_internal)
    .def("STRING_LITERAL", &ExplorerScriptParser::Import_stmtContext::STRING_LITERAL, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Import_stmtContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Constant_assignContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Constant_assignContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Constant_assignContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Constant_assignContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Constant_assignContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("CONST", &ExplorerScriptParser::Constant_assignContext::CONST, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::Constant_assignContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("ASSIGN", &ExplorerScriptParser::Constant_assignContext::ASSIGN, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Constant_assignContext::primitive, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Constant_assignContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::MacrodefContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "MacrodefContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::MacrodefContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::MacrodefContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::MacrodefContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("MACRO", &ExplorerScriptParser::MacrodefContext::MACRO, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::MacrodefContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::MacrodefContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::MacrodefContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("func_suite", &ExplorerScriptParser::MacrodefContext::func_suite, py::return_value_policy::reference_internal)
    .def("VARIABLE", py::overload_cast<>(&ExplorerScriptParser::MacrodefContext::VARIABLE), py::return_value_policy::reference_internal)
    .def("VARIABLE", py::overload_cast<size_t>(&ExplorerScriptParser::MacrodefContext::VARIABLE), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::MacrodefContext::COMMA), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::MacrodefContext::COMMA), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::MacrodefContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::StmtContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "StmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::StmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::StmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::StmtContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("constant_assign", &ExplorerScriptParser::StmtContext::constant_assign, py::return_value_policy::reference_internal)
    .def("simple_stmt", &ExplorerScriptParser::StmtContext::simple_stmt, py::return_value_policy::reference_internal)
    .def("ctx_block", &ExplorerScriptParser::StmtContext::ctx_block, py::return_value_policy::reference_internal)
    .def("if_block", &ExplorerScriptParser::StmtContext::if_block, py::return_value_policy::reference_internal)
    .def("switch_block", &ExplorerScriptParser::StmtContext::switch_block, py::return_value_policy::reference_internal)
    .def("message_switch_block", &ExplorerScriptParser::StmtContext::message_switch_block, py::return_value_policy::reference_internal)
    .def("forever_block", &ExplorerScriptParser::StmtContext::forever_block, py::return_value_policy::reference_internal)
    .def("for_block", &ExplorerScriptParser::StmtContext::for_block, py::return_value_policy::reference_internal)
    .def("while_block", &ExplorerScriptParser::StmtContext::while_block, py::return_value_policy::reference_internal)
    .def("macro_call", &ExplorerScriptParser::StmtContext::macro_call, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::StmtContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Simple_stmtContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Simple_stmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Simple_stmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Simple_stmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Simple_stmtContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("operation", &ExplorerScriptParser::Simple_stmtContext::operation, py::return_value_policy::reference_internal)
    .def("label", &ExplorerScriptParser::Simple_stmtContext::label, py::return_value_policy::reference_internal)
    .def("cntrl_stmt", &ExplorerScriptParser::Simple_stmtContext::cntrl_stmt, py::return_value_policy::reference_internal)
    .def("jump", &ExplorerScriptParser::Simple_stmtContext::jump, py::return_value_policy::reference_internal)
    .def("call", &ExplorerScriptParser::Simple_stmtContext::call, py::return_value_policy::reference_internal)
    .def("assignment", &ExplorerScriptParser::Simple_stmtContext::assignment, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Simple_stmtContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Cntrl_stmtContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Cntrl_stmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Cntrl_stmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Cntrl_stmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Cntrl_stmtContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("RETURN", &ExplorerScriptParser::Cntrl_stmtContext::RETURN, py::return_value_policy::reference_internal)
    .def("END", &ExplorerScriptParser::Cntrl_stmtContext::END, py::return_value_policy::reference_internal)
    .def("HOLD", &ExplorerScriptParser::Cntrl_stmtContext::HOLD, py::return_value_policy::reference_internal)
    .def("CONTINUE", &ExplorerScriptParser::Cntrl_stmtContext::CONTINUE, py::return_value_policy::reference_internal)
    .def("BREAK", &ExplorerScriptParser::Cntrl_stmtContext::BREAK, py::return_value_policy::reference_internal)
    .def("BREAK_LOOP", &ExplorerScriptParser::Cntrl_stmtContext::BREAK_LOOP, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Cntrl_stmtContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::JumpContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "JumpContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::JumpContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::JumpContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::JumpContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("JUMP", &ExplorerScriptParser::JumpContext::JUMP, py::return_value_policy::reference_internal)
    .def("AT", &ExplorerScriptParser::JumpContext::AT, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::JumpContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::JumpContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::CallContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "CallContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::CallContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::CallContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::CallContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("CALL", &ExplorerScriptParser::CallContext::CALL, py::return_value_policy::reference_internal)
    .def("AT", &ExplorerScriptParser::CallContext::AT, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::CallContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::CallContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Macro_callContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Macro_callContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Macro_callContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Macro_callContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Macro_callContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("MACRO_CALL", &ExplorerScriptParser::Macro_callContext::MACRO_CALL, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Macro_callContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Macro_callContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("arglist", &ExplorerScriptParser::Macro_callContext::arglist, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Macro_callContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Ctx_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Ctx_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Ctx_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Ctx_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Ctx_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("WITH", &ExplorerScriptParser::Ctx_blockContext::WITH, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Ctx_blockContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("ctx_header", &ExplorerScriptParser::Ctx_blockContext::ctx_header, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Ctx_blockContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::Ctx_blockContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Ctx_blockContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("simple_stmt", py::overload_cast<>(&ExplorerScriptParser::Ctx_blockContext::simple_stmt), py::return_value_policy::reference_internal)
    .def("simple_stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Ctx_blockContext::simple_stmt), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Ctx_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::If_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "If_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IF", &ExplorerScriptParser::If_blockContext::IF, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::If_blockContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("if_header", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::if_header), py::return_value_policy::reference_internal)
    .def("if_header", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::if_header), py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::If_blockContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::If_blockContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::If_blockContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("NOT", &ExplorerScriptParser::If_blockContext::NOT, py::return_value_policy::reference_internal)
    .def("OR", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::OR), py::return_value_policy::reference_internal)
    .def("OR", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::OR), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("elseif_block", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::elseif_block), py::return_value_policy::reference_internal)
    .def("elseif_block", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::elseif_block), py::return_value_policy::reference_internal)
    .def("else_block", &ExplorerScriptParser::If_blockContext::else_block, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::If_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Elseif_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Elseif_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Elseif_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Elseif_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("ELSEIF", &ExplorerScriptParser::Elseif_blockContext::ELSEIF, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Elseif_blockContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("if_header", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::if_header), py::return_value_policy::reference_internal)
    .def("if_header", py::overload_cast<size_t>(&ExplorerScriptParser::Elseif_blockContext::if_header), py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Elseif_blockContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::Elseif_blockContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Elseif_blockContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("NOT", &ExplorerScriptParser::Elseif_blockContext::NOT, py::return_value_policy::reference_internal)
    .def("OR", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::OR), py::return_value_policy::reference_internal)
    .def("OR", py::overload_cast<size_t>(&ExplorerScriptParser::Elseif_blockContext::OR), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Elseif_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Elseif_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Else_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Else_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Else_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Else_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Else_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("ELSE", &ExplorerScriptParser::Else_blockContext::ELSE, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::Else_blockContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Else_blockContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Else_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Else_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Else_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::If_headerContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "If_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_headerContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("if_h_op", &ExplorerScriptParser::If_headerContext::if_h_op, py::return_value_policy::reference_internal)
    .def("if_h_bit", &ExplorerScriptParser::If_headerContext::if_h_bit, py::return_value_policy::reference_internal)
    .def("if_h_negatable", &ExplorerScriptParser::If_headerContext::if_h_negatable, py::return_value_policy::reference_internal)
    .def("if_h_scn", &ExplorerScriptParser::If_headerContext::if_h_scn, py::return_value_policy::reference_internal)
    .def("operation", &ExplorerScriptParser::If_headerContext::operation, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::If_headerContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::If_h_negatableContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "If_h_negatableContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_negatableContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_negatableContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_negatableContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DEBUG", &ExplorerScriptParser::If_h_negatableContext::DEBUG, py::return_value_policy::reference_internal)
    .def("EDIT", &ExplorerScriptParser::If_h_negatableContext::EDIT, py::return_value_policy::reference_internal)
    .def("VARIATION", &ExplorerScriptParser::If_h_negatableContext::VARIATION, py::return_value_policy::reference_internal)
    .def("NOT", &ExplorerScriptParser::If_h_negatableContext::NOT, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::If_h_negatableContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::If_h_opContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "If_h_opContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_opContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_opContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_opContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("primitive", py::overload_cast<>(&ExplorerScriptParser::If_h_opContext::primitive), py::return_value_policy::reference_internal)
    .def("primitive", py::overload_cast<size_t>(&ExplorerScriptParser::If_h_opContext::primitive), py::return_value_policy::reference_internal)
    .def("conditional_operator", &ExplorerScriptParser::If_h_opContext::conditional_operator, py::return_value_policy::reference_internal)
    .def("value_of", &ExplorerScriptParser::If_h_opContext::value_of, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::If_h_opContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::If_h_bitContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "If_h_bitContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_bitContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_bitContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_bitContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::If_h_bitContext::primitive, py::return_value_policy::reference_internal)
    .def("OPEN_BRACKET", &ExplorerScriptParser::If_h_bitContext::OPEN_BRACKET, py::return_value_policy::reference_internal)
    .def("INTEGER", &ExplorerScriptParser::If_h_bitContext::INTEGER, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::If_h_bitContext::CLOSE_BRACKET, py::return_value_policy::reference_internal)
    .def("NOT", &ExplorerScriptParser::If_h_bitContext::NOT, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::If_h_bitContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::If_h_scnContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "If_h_scnContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_scnContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_scnContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_scnContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("scn_var", &ExplorerScriptParser::If_h_scnContext::scn_var, py::return_value_policy::reference_internal)
    .def("conditional_operator", &ExplorerScriptParser::If_h_scnContext::conditional_operator, py::return_value_policy::reference_internal)
    .def("OPEN_BRACKET", &ExplorerScriptParser::If_h_scnContext::OPEN_BRACKET, py::return_value_policy::reference_internal)
    .def("INTEGER", py::overload_cast<>(&ExplorerScriptParser::If_h_scnContext::INTEGER), py::return_value_policy::reference_internal)
    .def("INTEGER", py::overload_cast<size_t>(&ExplorerScriptParser::If_h_scnContext::INTEGER), py::return_value_policy::reference_internal)
    .def("COMMA", &ExplorerScriptParser::If_h_scnContext::COMMA, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::If_h_scnContext::CLOSE_BRACKET, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::If_h_scnContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Switch_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Switch_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("SWITCH", &ExplorerScriptParser::Switch_blockContext::SWITCH, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_blockContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("switch_header", &ExplorerScriptParser::Switch_blockContext::switch_header, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_blockContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::Switch_blockContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Switch_blockContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("default_", py::overload_cast<>(&ExplorerScriptParser::Switch_blockContext::default_), py::return_value_policy::reference_internal)
    .def("default_", py::overload_cast<size_t>(&ExplorerScriptParser::Switch_blockContext::default_), py::return_value_policy::reference_internal)
    .def("single_case_block", py::overload_cast<>(&ExplorerScriptParser::Switch_blockContext::single_case_block), py::return_value_policy::reference_internal)
    .def("single_case_block", py::overload_cast<size_t>(&ExplorerScriptParser::Switch_blockContext::single_case_block), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Switch_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Message_switch_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Message_switch_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Message_switch_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Message_switch_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Message_switch_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Message_switch_blockContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Message_switch_blockContext::primitive, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Message_switch_blockContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::Message_switch_blockContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Message_switch_blockContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("MESSAGE_SWITCH_TALK", &ExplorerScriptParser::Message_switch_blockContext::MESSAGE_SWITCH_TALK, py::return_value_policy::reference_internal)
    .def("MESSAGE_SWITCH_MONOLOGUE", &ExplorerScriptParser::Message_switch_blockContext::MESSAGE_SWITCH_MONOLOGUE, py::return_value_policy::reference_internal)
    .def("default_", py::overload_cast<>(&ExplorerScriptParser::Message_switch_blockContext::default_), py::return_value_policy::reference_internal)
    .def("default_", py::overload_cast<size_t>(&ExplorerScriptParser::Message_switch_blockContext::default_), py::return_value_policy::reference_internal)
    .def("single_case_block", py::overload_cast<>(&ExplorerScriptParser::Message_switch_blockContext::single_case_block), py::return_value_policy::reference_internal)
    .def("single_case_block", py::overload_cast<size_t>(&ExplorerScriptParser::Message_switch_blockContext::single_case_block), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Message_switch_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Single_case_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Single_case_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Single_case_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Single_case_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Single_case_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("CASE", &ExplorerScriptParser::Single_case_blockContext::CASE, py::return_value_policy::reference_internal)
    .def("case_header", &ExplorerScriptParser::Single_case_blockContext::case_header, py::return_value_policy::reference_internal)
    .def("COLON", &ExplorerScriptParser::Single_case_blockContext::COLON, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Single_case_blockContext::primitive, py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Single_case_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Single_case_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Single_case_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::DefaultContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "DefaultContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::DefaultContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::DefaultContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::DefaultContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DEFAULT", &ExplorerScriptParser::DefaultContext::DEFAULT, py::return_value_policy::reference_internal)
    .def("COLON", &ExplorerScriptParser::DefaultContext::COLON, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::DefaultContext::primitive, py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::DefaultContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::DefaultContext::stmt), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::DefaultContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Switch_headerContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Switch_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_headerContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Switch_headerContext::primitive, py::return_value_policy::reference_internal)
    .def("operation", &ExplorerScriptParser::Switch_headerContext::operation, py::return_value_policy::reference_internal)
    .def("switch_h_scn", &ExplorerScriptParser::Switch_headerContext::switch_h_scn, py::return_value_policy::reference_internal)
    .def("switch_h_random", &ExplorerScriptParser::Switch_headerContext::switch_h_random, py::return_value_policy::reference_internal)
    .def("switch_h_dungeon_mode", &ExplorerScriptParser::Switch_headerContext::switch_h_dungeon_mode, py::return_value_policy::reference_internal)
    .def("switch_h_sector", &ExplorerScriptParser::Switch_headerContext::switch_h_sector, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Switch_headerContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Switch_h_scnContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Switch_h_scnContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_scnContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_scnContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_scnContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("scn_var", &ExplorerScriptParser::Switch_h_scnContext::scn_var, py::return_value_policy::reference_internal)
    .def("OPEN_BRACKET", &ExplorerScriptParser::Switch_h_scnContext::OPEN_BRACKET, py::return_value_policy::reference_internal)
    .def("INTEGER", &ExplorerScriptParser::Switch_h_scnContext::INTEGER, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::Switch_h_scnContext::CLOSE_BRACKET, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Switch_h_scnContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Switch_h_randomContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Switch_h_randomContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_randomContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_randomContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_randomContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("RANDOM", &ExplorerScriptParser::Switch_h_randomContext::RANDOM, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_h_randomContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Switch_h_randomContext::primitive, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_h_randomContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Switch_h_randomContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Switch_h_dungeon_modeContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Switch_h_dungeon_modeContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_dungeon_modeContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_dungeon_modeContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_dungeon_modeContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DUNGEON_MODE", &ExplorerScriptParser::Switch_h_dungeon_modeContext::DUNGEON_MODE, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_h_dungeon_modeContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Switch_h_dungeon_modeContext::primitive, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_h_dungeon_modeContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Switch_h_dungeon_modeContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Switch_h_sectorContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Switch_h_sectorContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_sectorContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_sectorContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_sectorContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("SECTOR", &ExplorerScriptParser::Switch_h_sectorContext::SECTOR, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_h_sectorContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_h_sectorContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Switch_h_sectorContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Case_headerContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Case_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_headerContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Case_headerContext::primitive, py::return_value_policy::reference_internal)
    .def("case_h_menu", &ExplorerScriptParser::Case_headerContext::case_h_menu, py::return_value_policy::reference_internal)
    .def("case_h_menu2", &ExplorerScriptParser::Case_headerContext::case_h_menu2, py::return_value_policy::reference_internal)
    .def("case_h_op", &ExplorerScriptParser::Case_headerContext::case_h_op, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Case_headerContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Case_h_menuContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Case_h_menuContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_h_menuContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_h_menuContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_h_menuContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("MENU", &ExplorerScriptParser::Case_h_menuContext::MENU, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Case_h_menuContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Case_h_menuContext::primitive, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Case_h_menuContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Case_h_menuContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Case_h_menu2Context, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Case_h_menu2Context")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_h_menu2Context::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_h_menu2Context::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_h_menu2Context::getRuleIndex, py::return_value_policy::reference_internal)
    .def("MENU2", &ExplorerScriptParser::Case_h_menu2Context::MENU2, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Case_h_menu2Context::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Case_h_menu2Context::primitive, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Case_h_menu2Context::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Case_h_menu2Context::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Case_h_opContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Case_h_opContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_h_opContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_h_opContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_h_opContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("conditional_operator", &ExplorerScriptParser::Case_h_opContext::conditional_operator, py::return_value_policy::reference_internal)
    .def("value_of", &ExplorerScriptParser::Case_h_opContext::value_of, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Case_h_opContext::primitive, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Case_h_opContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Forever_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Forever_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Forever_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Forever_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Forever_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("FOREVER", &ExplorerScriptParser::Forever_blockContext::FOREVER, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::Forever_blockContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Forever_blockContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Forever_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Forever_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Forever_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::For_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "For_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::For_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::For_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::For_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("FOR", &ExplorerScriptParser::For_blockContext::FOR, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::For_blockContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("simple_stmt", py::overload_cast<>(&ExplorerScriptParser::For_blockContext::simple_stmt), py::return_value_policy::reference_internal)
    .def("simple_stmt", py::overload_cast<size_t>(&ExplorerScriptParser::For_blockContext::simple_stmt), py::return_value_policy::reference_internal)
    .def("if_header", &ExplorerScriptParser::For_blockContext::if_header, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::For_blockContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::For_blockContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::For_blockContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::For_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::For_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::For_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::While_blockContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "While_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::While_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::While_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::While_blockContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("WHILE", &ExplorerScriptParser::While_blockContext::WHILE, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::While_blockContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("if_header", &ExplorerScriptParser::While_blockContext::if_header, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::While_blockContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::While_blockContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::While_blockContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("NOT", &ExplorerScriptParser::While_blockContext::NOT, py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::While_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::While_blockContext::stmt), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::While_blockContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::AssignmentContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "AssignmentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::AssignmentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::AssignmentContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::AssignmentContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("assignment_regular", &ExplorerScriptParser::AssignmentContext::assignment_regular, py::return_value_policy::reference_internal)
    .def("assignment_clear", &ExplorerScriptParser::AssignmentContext::assignment_clear, py::return_value_policy::reference_internal)
    .def("assignment_initial", &ExplorerScriptParser::AssignmentContext::assignment_initial, py::return_value_policy::reference_internal)
    .def("assignment_reset", &ExplorerScriptParser::AssignmentContext::assignment_reset, py::return_value_policy::reference_internal)
    .def("assignment_adv_log", &ExplorerScriptParser::AssignmentContext::assignment_adv_log, py::return_value_policy::reference_internal)
    .def("assignment_dungeon_mode", &ExplorerScriptParser::AssignmentContext::assignment_dungeon_mode, py::return_value_policy::reference_internal)
    .def("assignment_scn", &ExplorerScriptParser::AssignmentContext::assignment_scn, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::AssignmentContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Assignment_regularContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Assignment_regularContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_regularContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_regularContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_regularContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("primitive", py::overload_cast<>(&ExplorerScriptParser::Assignment_regularContext::primitive), py::return_value_policy::reference_internal)
    .def("primitive", py::overload_cast<size_t>(&ExplorerScriptParser::Assignment_regularContext::primitive), py::return_value_policy::reference_internal)
    .def("assign_operator", &ExplorerScriptParser::Assignment_regularContext::assign_operator, py::return_value_policy::reference_internal)
    .def("value_of", &ExplorerScriptParser::Assignment_regularContext::value_of, py::return_value_policy::reference_internal)
    .def("OPEN_BRACKET", &ExplorerScriptParser::Assignment_regularContext::OPEN_BRACKET, py::return_value_policy::reference_internal)
    .def("INTEGER", &ExplorerScriptParser::Assignment_regularContext::INTEGER, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::Assignment_regularContext::CLOSE_BRACKET, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Assignment_regularContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Assignment_clearContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Assignment_clearContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_clearContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_clearContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_clearContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("CLEAR", &ExplorerScriptParser::Assignment_clearContext::CLEAR, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Assignment_clearContext::primitive, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Assignment_clearContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Assignment_initialContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Assignment_initialContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_initialContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_initialContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_initialContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("INIT", &ExplorerScriptParser::Assignment_initialContext::INIT, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Assignment_initialContext::primitive, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Assignment_initialContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Assignment_resetContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Assignment_resetContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_resetContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_resetContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_resetContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("RESET", &ExplorerScriptParser::Assignment_resetContext::RESET, py::return_value_policy::reference_internal)
    .def("DUNGEON_RESULT", &ExplorerScriptParser::Assignment_resetContext::DUNGEON_RESULT, py::return_value_policy::reference_internal)
    .def("scn_var", &ExplorerScriptParser::Assignment_resetContext::scn_var, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Assignment_resetContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Assignment_adv_logContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Assignment_adv_logContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_adv_logContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_adv_logContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_adv_logContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("ADVENTURE_LOG", &ExplorerScriptParser::Assignment_adv_logContext::ADVENTURE_LOG, py::return_value_policy::reference_internal)
    .def("ASSIGN", &ExplorerScriptParser::Assignment_adv_logContext::ASSIGN, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Assignment_adv_logContext::primitive, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Assignment_adv_logContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Assignment_dungeon_modeContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Assignment_dungeon_modeContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_dungeon_modeContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_dungeon_modeContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_dungeon_modeContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DUNGEON_MODE", &ExplorerScriptParser::Assignment_dungeon_modeContext::DUNGEON_MODE, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Assignment_dungeon_modeContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("primitive", py::overload_cast<>(&ExplorerScriptParser::Assignment_dungeon_modeContext::primitive), py::return_value_policy::reference_internal)
    .def("primitive", py::overload_cast<size_t>(&ExplorerScriptParser::Assignment_dungeon_modeContext::primitive), py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Assignment_dungeon_modeContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("ASSIGN", &ExplorerScriptParser::Assignment_dungeon_modeContext::ASSIGN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Assignment_dungeon_modeContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Assignment_scnContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Assignment_scnContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_scnContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_scnContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_scnContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Assignment_scnContext::primitive, py::return_value_policy::reference_internal)
    .def("ASSIGN", &ExplorerScriptParser::Assignment_scnContext::ASSIGN, py::return_value_policy::reference_internal)
    .def("SCN", &ExplorerScriptParser::Assignment_scnContext::SCN, py::return_value_policy::reference_internal)
    .def("OPEN_BRACKET", &ExplorerScriptParser::Assignment_scnContext::OPEN_BRACKET, py::return_value_policy::reference_internal)
    .def("INTEGER", py::overload_cast<>(&ExplorerScriptParser::Assignment_scnContext::INTEGER), py::return_value_policy::reference_internal)
    .def("INTEGER", py::overload_cast<size_t>(&ExplorerScriptParser::Assignment_scnContext::INTEGER), py::return_value_policy::reference_internal)
    .def("COMMA", &ExplorerScriptParser::Assignment_scnContext::COMMA, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::Assignment_scnContext::CLOSE_BRACKET, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Assignment_scnContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Value_ofContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Value_ofContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Value_ofContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Value_ofContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Value_ofContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("VALUE", &ExplorerScriptParser::Value_ofContext::VALUE, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Value_ofContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Value_ofContext::primitive, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Value_ofContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Value_ofContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Scn_varContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Scn_varContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Scn_varContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Scn_varContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Scn_varContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("SCN", &ExplorerScriptParser::Scn_varContext::SCN, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::Scn_varContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Scn_varContext::primitive, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Scn_varContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Scn_varContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Conditional_operatorContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Conditional_operatorContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Conditional_operatorContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Conditional_operatorContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Conditional_operatorContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("OP_FALSE", &ExplorerScriptParser::Conditional_operatorContext::OP_FALSE, py::return_value_policy::reference_internal)
    .def("OP_TRUE", &ExplorerScriptParser::Conditional_operatorContext::OP_TRUE, py::return_value_policy::reference_internal)
    .def("OP_EQ", &ExplorerScriptParser::Conditional_operatorContext::OP_EQ, py::return_value_policy::reference_internal)
    .def("OP_GE", &ExplorerScriptParser::Conditional_operatorContext::OP_GE, py::return_value_policy::reference_internal)
    .def("OP_LE", &ExplorerScriptParser::Conditional_operatorContext::OP_LE, py::return_value_policy::reference_internal)
    .def("OPEN_SHARP", &ExplorerScriptParser::Conditional_operatorContext::OPEN_SHARP, py::return_value_policy::reference_internal)
    .def("CLOSE_SHARP", &ExplorerScriptParser::Conditional_operatorContext::CLOSE_SHARP, py::return_value_policy::reference_internal)
    .def("OP_NEQ", &ExplorerScriptParser::Conditional_operatorContext::OP_NEQ, py::return_value_policy::reference_internal)
    .def("OP_AND", &ExplorerScriptParser::Conditional_operatorContext::OP_AND, py::return_value_policy::reference_internal)
    .def("OP_XOR", &ExplorerScriptParser::Conditional_operatorContext::OP_XOR, py::return_value_policy::reference_internal)
    .def("OP_BICH", &ExplorerScriptParser::Conditional_operatorContext::OP_BICH, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Conditional_operatorContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Assign_operatorContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Assign_operatorContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assign_operatorContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assign_operatorContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assign_operatorContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("OP_MINUS", &ExplorerScriptParser::Assign_operatorContext::OP_MINUS, py::return_value_policy::reference_internal)
    .def("OP_PLUS", &ExplorerScriptParser::Assign_operatorContext::OP_PLUS, py::return_value_policy::reference_internal)
    .def("OP_MULTIPLY", &ExplorerScriptParser::Assign_operatorContext::OP_MULTIPLY, py::return_value_policy::reference_internal)
    .def("OP_DIVIDE", &ExplorerScriptParser::Assign_operatorContext::OP_DIVIDE, py::return_value_policy::reference_internal)
    .def("ASSIGN", &ExplorerScriptParser::Assign_operatorContext::ASSIGN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Assign_operatorContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::FuncdefContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "FuncdefContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::FuncdefContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::FuncdefContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::FuncdefContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("coro_def", &ExplorerScriptParser::FuncdefContext::coro_def, py::return_value_policy::reference_internal)
    .def("simple_def", &ExplorerScriptParser::FuncdefContext::simple_def, py::return_value_policy::reference_internal)
    .def("for_target_def", &ExplorerScriptParser::FuncdefContext::for_target_def, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::FuncdefContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Simple_defContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Simple_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Simple_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Simple_defContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Simple_defContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DEF", &ExplorerScriptParser::Simple_defContext::DEF, py::return_value_policy::reference_internal)
    .def("INTEGER", &ExplorerScriptParser::Simple_defContext::INTEGER, py::return_value_policy::reference_internal)
    .def("func_suite", &ExplorerScriptParser::Simple_defContext::func_suite, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Simple_defContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Coro_defContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Coro_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Coro_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Coro_defContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Coro_defContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("CORO", &ExplorerScriptParser::Coro_defContext::CORO, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::Coro_defContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("func_suite", &ExplorerScriptParser::Coro_defContext::func_suite, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Coro_defContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::For_target_defContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "For_target_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::For_target_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::For_target_defContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::For_target_defContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DEF", &ExplorerScriptParser::For_target_defContext::DEF, py::return_value_policy::reference_internal)
    .def("INTEGER", &ExplorerScriptParser::For_target_defContext::INTEGER, py::return_value_policy::reference_internal)
    .def("for_target_def_target", &ExplorerScriptParser::For_target_defContext::for_target_def_target, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::For_target_defContext::primitive, py::return_value_policy::reference_internal)
    .def("func_suite", &ExplorerScriptParser::For_target_defContext::func_suite, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::For_target_defContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::For_target_defContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::For_target_defContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::PrimitiveContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "PrimitiveContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::PrimitiveContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::PrimitiveContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::PrimitiveContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DECIMAL", &ExplorerScriptParser::PrimitiveContext::DECIMAL, py::return_value_policy::reference_internal)
    .def("INTEGER", &ExplorerScriptParser::PrimitiveContext::INTEGER, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::PrimitiveContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("VARIABLE", &ExplorerScriptParser::PrimitiveContext::VARIABLE, py::return_value_policy::reference_internal)
    .def("string", &ExplorerScriptParser::PrimitiveContext::string, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::PrimitiveContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::OperationContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "OperationContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::OperationContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::OperationContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::OperationContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::OperationContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &ExplorerScriptParser::OperationContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &ExplorerScriptParser::OperationContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("inline_ctx", &ExplorerScriptParser::OperationContext::inline_ctx, py::return_value_policy::reference_internal)
    .def("arglist", &ExplorerScriptParser::OperationContext::arglist, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::OperationContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Inline_ctxContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Inline_ctxContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Inline_ctxContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Inline_ctxContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Inline_ctxContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("OPEN_SHARP", &ExplorerScriptParser::Inline_ctxContext::OPEN_SHARP, py::return_value_policy::reference_internal)
    .def("ctx_header", &ExplorerScriptParser::Inline_ctxContext::ctx_header, py::return_value_policy::reference_internal)
    .def("CLOSE_SHARP", &ExplorerScriptParser::Inline_ctxContext::CLOSE_SHARP, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Inline_ctxContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Func_suiteContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Func_suiteContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Func_suiteContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Func_suiteContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Func_suiteContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::Func_suiteContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Func_suiteContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("func_alias", &ExplorerScriptParser::Func_suiteContext::func_alias, py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Func_suiteContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Func_suiteContext::stmt), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Func_suiteContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Func_aliasContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Func_aliasContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Func_aliasContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Func_aliasContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Func_aliasContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("ALIAS", &ExplorerScriptParser::Func_aliasContext::ALIAS, py::return_value_policy::reference_internal)
    .def("PREVIOUS", &ExplorerScriptParser::Func_aliasContext::PREVIOUS, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Func_aliasContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::ArglistContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "ArglistContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::ArglistContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::ArglistContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::ArglistContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("pos_argument", py::overload_cast<>(&ExplorerScriptParser::ArglistContext::pos_argument), py::return_value_policy::reference_internal)
    .def("pos_argument", py::overload_cast<size_t>(&ExplorerScriptParser::ArglistContext::pos_argument), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::ArglistContext::COMMA), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::ArglistContext::COMMA), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::ArglistContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Pos_argumentContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Pos_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Pos_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Pos_argumentContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Pos_argumentContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Pos_argumentContext::primitive, py::return_value_policy::reference_internal)
    .def("position_marker", &ExplorerScriptParser::Pos_argumentContext::position_marker, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Pos_argumentContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Position_markerContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Position_markerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Position_markerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Position_markerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Position_markerContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("POSITION", &ExplorerScriptParser::Position_markerContext::POSITION, py::return_value_policy::reference_internal)
    .def("OPEN_SHARP", &ExplorerScriptParser::Position_markerContext::OPEN_SHARP, py::return_value_policy::reference_internal)
    .def("STRING_LITERAL", &ExplorerScriptParser::Position_markerContext::STRING_LITERAL, py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::Position_markerContext::COMMA), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::Position_markerContext::COMMA), py::return_value_policy::reference_internal)
    .def("position_marker_arg", py::overload_cast<>(&ExplorerScriptParser::Position_markerContext::position_marker_arg), py::return_value_policy::reference_internal)
    .def("position_marker_arg", py::overload_cast<size_t>(&ExplorerScriptParser::Position_markerContext::position_marker_arg), py::return_value_policy::reference_internal)
    .def("CLOSE_SHARP", &ExplorerScriptParser::Position_markerContext::CLOSE_SHARP, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Position_markerContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Position_marker_argContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Position_marker_argContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Position_marker_argContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Position_marker_argContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Position_marker_argContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("INTEGER", &ExplorerScriptParser::Position_marker_argContext::INTEGER, py::return_value_policy::reference_internal)
    .def("DECIMAL", &ExplorerScriptParser::Position_marker_argContext::DECIMAL, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Position_marker_argContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::LabelContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "LabelContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::LabelContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::LabelContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::LabelContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::LabelContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("PARAGRAPH", &ExplorerScriptParser::LabelContext::PARAGRAPH, py::return_value_policy::reference_internal)
    .def("AT", &ExplorerScriptParser::LabelContext::AT, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::LabelContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::StringContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "StringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::StringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::StringContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::StringContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("string_value", &ExplorerScriptParser::StringContext::string_value, py::return_value_policy::reference_internal)
    .def("lang_string", &ExplorerScriptParser::StringContext::lang_string, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::StringContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Lang_stringContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Lang_stringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Lang_stringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Lang_stringContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Lang_stringContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &ExplorerScriptParser::Lang_stringContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("lang_string_argument", py::overload_cast<>(&ExplorerScriptParser::Lang_stringContext::lang_string_argument), py::return_value_policy::reference_internal)
    .def("lang_string_argument", py::overload_cast<size_t>(&ExplorerScriptParser::Lang_stringContext::lang_string_argument), py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Lang_stringContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::Lang_stringContext::COMMA), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::Lang_stringContext::COMMA), py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Lang_stringContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Lang_string_argumentContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Lang_string_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Lang_string_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Lang_string_argumentContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Lang_string_argumentContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::Lang_string_argumentContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("ASSIGN", &ExplorerScriptParser::Lang_string_argumentContext::ASSIGN, py::return_value_policy::reference_internal)
    .def("string_value", &ExplorerScriptParser::Lang_string_argumentContext::string_value, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Lang_string_argumentContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::String_valueContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "String_valueContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::String_valueContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::String_valueContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::String_valueContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("MULTILINE_STRING_LITERAL", &ExplorerScriptParser::String_valueContext::MULTILINE_STRING_LITERAL, py::return_value_policy::reference_internal)
    .def("STRING_LITERAL", &ExplorerScriptParser::String_valueContext::STRING_LITERAL, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::String_valueContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::Ctx_headerContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "Ctx_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Ctx_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Ctx_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Ctx_headerContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::Ctx_headerContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("primitive", &ExplorerScriptParser::Ctx_headerContext::primitive, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::Ctx_headerContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptParser::For_target_def_targetContext, antlr4::ParserRuleContext>(m_parser_sub_ExplorerScript, "For_target_def_targetContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::For_target_def_targetContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::For_target_def_targetContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::For_target_def_targetContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("FOR", &ExplorerScriptParser::For_target_def_targetContext::FOR, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &ExplorerScriptParser::For_target_def_targetContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("FOR_TARGET", &ExplorerScriptParser::For_target_def_targetContext::FOR_TARGET, py::return_value_policy::reference_internal)
    .def("accept", &ExplorerScriptParser::For_target_def_targetContext::accept, py::return_value_policy::reference_internal)
;
py::class_<ExplorerScriptBaseVisitor, PyExplorerScriptBaseVisitor, antlr4::tree::ParseTreeVisitor>(m, "ExplorerScriptBaseVisitor")
    .def(py::init<>())
    .def("visitChildren", [](ExplorerScriptBaseVisitor& self, antlr4::tree::ParseTree* node) {
        return std::any_cast<pybind11::object>(self.visitChildren(node));
    }, py::return_value_policy::reference_internal, py::keep_alive<1, 2>())
    .def("defaultResult", [](ExplorerScriptBaseVisitor& self) {
        return std::any_cast<pybind11::object>(self.defaultResult());
    }, py::keep_alive<1, 2>())
    .def("visitTerminal", [](ExplorerScriptBaseVisitor& self, antlr4::tree::TerminalNode * node) {
        return std::any_cast<pybind11::object>(self.visitTerminal(node));
    }, py::return_value_policy::reference_internal, py::keep_alive<1, 2>())
    .def("aggregateResult", [](ExplorerScriptBaseVisitor& self, pybind11::object aggregate, pybind11::object nextResult) {
        return std::any_cast<pybind11::object>(self.aggregateResult(aggregate, nextResult));
    }, py::return_value_policy::reference_internal)
    .def("visit", [](ExplorerScriptBaseVisitor& self, antlr4::tree::ParseTree* tree) {
        return std::any_cast<pybind11::object>(self.visit(tree));
    }, py::return_value_policy::reference_internal, py::keep_alive<1, 2>())
    .def("visitStart", &ExplorerScriptBaseVisitor::visitStart, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitImport_stmt", &ExplorerScriptBaseVisitor::visitImport_stmt, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitConstant_assign", &ExplorerScriptBaseVisitor::visitConstant_assign, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitMacrodef", &ExplorerScriptBaseVisitor::visitMacrodef, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitStmt", &ExplorerScriptBaseVisitor::visitStmt, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSimple_stmt", &ExplorerScriptBaseVisitor::visitSimple_stmt, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCntrl_stmt", &ExplorerScriptBaseVisitor::visitCntrl_stmt, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitJump", &ExplorerScriptBaseVisitor::visitJump, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCall", &ExplorerScriptBaseVisitor::visitCall, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitMacro_call", &ExplorerScriptBaseVisitor::visitMacro_call, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCtx_block", &ExplorerScriptBaseVisitor::visitCtx_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitIf_block", &ExplorerScriptBaseVisitor::visitIf_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitElseif_block", &ExplorerScriptBaseVisitor::visitElseif_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitElse_block", &ExplorerScriptBaseVisitor::visitElse_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitIf_header", &ExplorerScriptBaseVisitor::visitIf_header, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitIf_h_negatable", &ExplorerScriptBaseVisitor::visitIf_h_negatable, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitIf_h_op", &ExplorerScriptBaseVisitor::visitIf_h_op, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitIf_h_bit", &ExplorerScriptBaseVisitor::visitIf_h_bit, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitIf_h_scn", &ExplorerScriptBaseVisitor::visitIf_h_scn, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSwitch_block", &ExplorerScriptBaseVisitor::visitSwitch_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitMessage_switch_block", &ExplorerScriptBaseVisitor::visitMessage_switch_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSingle_case_block", &ExplorerScriptBaseVisitor::visitSingle_case_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitDefault", &ExplorerScriptBaseVisitor::visitDefault, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSwitch_header", &ExplorerScriptBaseVisitor::visitSwitch_header, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSwitch_h_scn", &ExplorerScriptBaseVisitor::visitSwitch_h_scn, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSwitch_h_random", &ExplorerScriptBaseVisitor::visitSwitch_h_random, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSwitch_h_dungeon_mode", &ExplorerScriptBaseVisitor::visitSwitch_h_dungeon_mode, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSwitch_h_sector", &ExplorerScriptBaseVisitor::visitSwitch_h_sector, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCase_header", &ExplorerScriptBaseVisitor::visitCase_header, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCase_h_menu", &ExplorerScriptBaseVisitor::visitCase_h_menu, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCase_h_menu2", &ExplorerScriptBaseVisitor::visitCase_h_menu2, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCase_h_op", &ExplorerScriptBaseVisitor::visitCase_h_op, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitForever_block", &ExplorerScriptBaseVisitor::visitForever_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFor_block", &ExplorerScriptBaseVisitor::visitFor_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitWhile_block", &ExplorerScriptBaseVisitor::visitWhile_block, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitAssignment", &ExplorerScriptBaseVisitor::visitAssignment, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitAssignment_regular", &ExplorerScriptBaseVisitor::visitAssignment_regular, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitAssignment_clear", &ExplorerScriptBaseVisitor::visitAssignment_clear, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitAssignment_initial", &ExplorerScriptBaseVisitor::visitAssignment_initial, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitAssignment_reset", &ExplorerScriptBaseVisitor::visitAssignment_reset, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitAssignment_adv_log", &ExplorerScriptBaseVisitor::visitAssignment_adv_log, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitAssignment_dungeon_mode", &ExplorerScriptBaseVisitor::visitAssignment_dungeon_mode, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitAssignment_scn", &ExplorerScriptBaseVisitor::visitAssignment_scn, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitValue_of", &ExplorerScriptBaseVisitor::visitValue_of, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitScn_var", &ExplorerScriptBaseVisitor::visitScn_var, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitConditional_operator", &ExplorerScriptBaseVisitor::visitConditional_operator, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitAssign_operator", &ExplorerScriptBaseVisitor::visitAssign_operator, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFuncdef", &ExplorerScriptBaseVisitor::visitFuncdef, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSimple_def", &ExplorerScriptBaseVisitor::visitSimple_def, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCoro_def", &ExplorerScriptBaseVisitor::visitCoro_def, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFor_target_def", &ExplorerScriptBaseVisitor::visitFor_target_def, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitPrimitive", &ExplorerScriptBaseVisitor::visitPrimitive, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitOperation", &ExplorerScriptBaseVisitor::visitOperation, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitInline_ctx", &ExplorerScriptBaseVisitor::visitInline_ctx, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFunc_suite", &ExplorerScriptBaseVisitor::visitFunc_suite, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFunc_alias", &ExplorerScriptBaseVisitor::visitFunc_alias, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitArglist", &ExplorerScriptBaseVisitor::visitArglist, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitPos_argument", &ExplorerScriptBaseVisitor::visitPos_argument, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitPosition_marker", &ExplorerScriptBaseVisitor::visitPosition_marker, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitPosition_marker_arg", &ExplorerScriptBaseVisitor::visitPosition_marker_arg, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitLabel", &ExplorerScriptBaseVisitor::visitLabel, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitString", &ExplorerScriptBaseVisitor::visitString, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitLang_string", &ExplorerScriptBaseVisitor::visitLang_string, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitLang_string_argument", &ExplorerScriptBaseVisitor::visitLang_string_argument, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitString_value", &ExplorerScriptBaseVisitor::visitString_value, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCtx_header", &ExplorerScriptBaseVisitor::visitCtx_header, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFor_target_def_target", &ExplorerScriptBaseVisitor::visitFor_target_def_target, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
;auto m_parser_sub_SsbScript = m.def_submodule("SsbScriptParser");
py::class_<SsbScriptParser::Pos_argumentContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Pos_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Pos_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Pos_argumentContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Pos_argumentContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("primitive", &SsbScriptParser::Pos_argumentContext::primitive, py::return_value_policy::reference_internal)
    .def("position_marker", &SsbScriptParser::Pos_argumentContext::position_marker, py::return_value_policy::reference_internal)
    .def("jump_marker", &SsbScriptParser::Pos_argumentContext::jump_marker, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Pos_argumentContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Jump_markerContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Jump_markerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Jump_markerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Jump_markerContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Jump_markerContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("AT", &SsbScriptParser::Jump_markerContext::AT, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &SsbScriptParser::Jump_markerContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Jump_markerContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::StartContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "StartContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::StartContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::StartContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::StartContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("EOF", &SsbScriptParser::StartContext::EOF, py::return_value_policy::reference_internal)
    .def("funcdef", py::overload_cast<>(&SsbScriptParser::StartContext::funcdef), py::return_value_policy::reference_internal)
    .def("funcdef", py::overload_cast<size_t>(&SsbScriptParser::StartContext::funcdef), py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::StartContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::FuncdefContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "FuncdefContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::FuncdefContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::FuncdefContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::FuncdefContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("coro_def", &SsbScriptParser::FuncdefContext::coro_def, py::return_value_policy::reference_internal)
    .def("simple_def", &SsbScriptParser::FuncdefContext::simple_def, py::return_value_policy::reference_internal)
    .def("for_target_def", &SsbScriptParser::FuncdefContext::for_target_def, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::FuncdefContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Simple_defContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Simple_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Simple_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Simple_defContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Simple_defContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DEF", &SsbScriptParser::Simple_defContext::DEF, py::return_value_policy::reference_internal)
    .def("INTEGER", &SsbScriptParser::Simple_defContext::INTEGER, py::return_value_policy::reference_internal)
    .def("func_suite", &SsbScriptParser::Simple_defContext::func_suite, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Simple_defContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Coro_defContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Coro_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Coro_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Coro_defContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Coro_defContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("CORO", &SsbScriptParser::Coro_defContext::CORO, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &SsbScriptParser::Coro_defContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("func_suite", &SsbScriptParser::Coro_defContext::func_suite, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Coro_defContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::For_target_defContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "For_target_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::For_target_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::For_target_defContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::For_target_defContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DEF", &SsbScriptParser::For_target_defContext::DEF, py::return_value_policy::reference_internal)
    .def("INTEGER", &SsbScriptParser::For_target_defContext::INTEGER, py::return_value_policy::reference_internal)
    .def("for_target_def_target", &SsbScriptParser::For_target_defContext::for_target_def_target, py::return_value_policy::reference_internal)
    .def("primitive", &SsbScriptParser::For_target_defContext::primitive, py::return_value_policy::reference_internal)
    .def("func_suite", &SsbScriptParser::For_target_defContext::func_suite, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &SsbScriptParser::For_target_defContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &SsbScriptParser::For_target_defContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::For_target_defContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::PrimitiveContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "PrimitiveContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::PrimitiveContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::PrimitiveContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::PrimitiveContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("DECIMAL", &SsbScriptParser::PrimitiveContext::DECIMAL, py::return_value_policy::reference_internal)
    .def("INTEGER", &SsbScriptParser::PrimitiveContext::INTEGER, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &SsbScriptParser::PrimitiveContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("VARIABLE", &SsbScriptParser::PrimitiveContext::VARIABLE, py::return_value_policy::reference_internal)
    .def("string", &SsbScriptParser::PrimitiveContext::string, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::PrimitiveContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::StmtContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "StmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::StmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::StmtContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::StmtContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("operation", &SsbScriptParser::StmtContext::operation, py::return_value_policy::reference_internal)
    .def("label", &SsbScriptParser::StmtContext::label, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::StmtContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::OperationContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "OperationContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::OperationContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::OperationContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::OperationContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &SsbScriptParser::OperationContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("OPEN_PAREN", &SsbScriptParser::OperationContext::OPEN_PAREN, py::return_value_policy::reference_internal)
    .def("CLOSE_PAREN", &SsbScriptParser::OperationContext::CLOSE_PAREN, py::return_value_policy::reference_internal)
    .def("inline_ctx", &SsbScriptParser::OperationContext::inline_ctx, py::return_value_policy::reference_internal)
    .def("arglist", &SsbScriptParser::OperationContext::arglist, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::OperationContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Inline_ctxContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Inline_ctxContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Inline_ctxContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Inline_ctxContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Inline_ctxContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("OPEN_SHARP", &SsbScriptParser::Inline_ctxContext::OPEN_SHARP, py::return_value_policy::reference_internal)
    .def("ctx_header", &SsbScriptParser::Inline_ctxContext::ctx_header, py::return_value_policy::reference_internal)
    .def("CLOSE_SHARP", &SsbScriptParser::Inline_ctxContext::CLOSE_SHARP, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Inline_ctxContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Func_suiteContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Func_suiteContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Func_suiteContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Func_suiteContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Func_suiteContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &SsbScriptParser::Func_suiteContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &SsbScriptParser::Func_suiteContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("func_alias", &SsbScriptParser::Func_suiteContext::func_alias, py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<>(&SsbScriptParser::Func_suiteContext::stmt), py::return_value_policy::reference_internal)
    .def("stmt", py::overload_cast<size_t>(&SsbScriptParser::Func_suiteContext::stmt), py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Func_suiteContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Func_aliasContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Func_aliasContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Func_aliasContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Func_aliasContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Func_aliasContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("ALIAS", &SsbScriptParser::Func_aliasContext::ALIAS, py::return_value_policy::reference_internal)
    .def("PREVIOUS", &SsbScriptParser::Func_aliasContext::PREVIOUS, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Func_aliasContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::ArglistContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "ArglistContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::ArglistContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::ArglistContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::ArglistContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("pos_argument", py::overload_cast<>(&SsbScriptParser::ArglistContext::pos_argument), py::return_value_policy::reference_internal)
    .def("pos_argument", py::overload_cast<size_t>(&SsbScriptParser::ArglistContext::pos_argument), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<>(&SsbScriptParser::ArglistContext::COMMA), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<size_t>(&SsbScriptParser::ArglistContext::COMMA), py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::ArglistContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Position_markerContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Position_markerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Position_markerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Position_markerContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Position_markerContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("POSITION", &SsbScriptParser::Position_markerContext::POSITION, py::return_value_policy::reference_internal)
    .def("OPEN_SHARP", &SsbScriptParser::Position_markerContext::OPEN_SHARP, py::return_value_policy::reference_internal)
    .def("STRING_LITERAL", &SsbScriptParser::Position_markerContext::STRING_LITERAL, py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<>(&SsbScriptParser::Position_markerContext::COMMA), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<size_t>(&SsbScriptParser::Position_markerContext::COMMA), py::return_value_policy::reference_internal)
    .def("position_marker_arg", py::overload_cast<>(&SsbScriptParser::Position_markerContext::position_marker_arg), py::return_value_policy::reference_internal)
    .def("position_marker_arg", py::overload_cast<size_t>(&SsbScriptParser::Position_markerContext::position_marker_arg), py::return_value_policy::reference_internal)
    .def("CLOSE_SHARP", &SsbScriptParser::Position_markerContext::CLOSE_SHARP, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Position_markerContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Position_marker_argContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Position_marker_argContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Position_marker_argContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Position_marker_argContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Position_marker_argContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("INTEGER", &SsbScriptParser::Position_marker_argContext::INTEGER, py::return_value_policy::reference_internal)
    .def("DECIMAL", &SsbScriptParser::Position_marker_argContext::DECIMAL, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Position_marker_argContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::LabelContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "LabelContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::LabelContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::LabelContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::LabelContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &SsbScriptParser::LabelContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("PARAGRAPH", &SsbScriptParser::LabelContext::PARAGRAPH, py::return_value_policy::reference_internal)
    .def("AT", &SsbScriptParser::LabelContext::AT, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::LabelContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::StringContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "StringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::StringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::StringContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::StringContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("string_value", &SsbScriptParser::StringContext::string_value, py::return_value_policy::reference_internal)
    .def("lang_string", &SsbScriptParser::StringContext::lang_string, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::StringContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Lang_stringContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Lang_stringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Lang_stringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Lang_stringContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Lang_stringContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("OPEN_BRACE", &SsbScriptParser::Lang_stringContext::OPEN_BRACE, py::return_value_policy::reference_internal)
    .def("lang_string_argument", py::overload_cast<>(&SsbScriptParser::Lang_stringContext::lang_string_argument), py::return_value_policy::reference_internal)
    .def("lang_string_argument", py::overload_cast<size_t>(&SsbScriptParser::Lang_stringContext::lang_string_argument), py::return_value_policy::reference_internal)
    .def("CLOSE_BRACE", &SsbScriptParser::Lang_stringContext::CLOSE_BRACE, py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<>(&SsbScriptParser::Lang_stringContext::COMMA), py::return_value_policy::reference_internal)
    .def("COMMA", py::overload_cast<size_t>(&SsbScriptParser::Lang_stringContext::COMMA), py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Lang_stringContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Lang_string_argumentContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Lang_string_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Lang_string_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Lang_string_argumentContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Lang_string_argumentContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &SsbScriptParser::Lang_string_argumentContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("ASSIGN", &SsbScriptParser::Lang_string_argumentContext::ASSIGN, py::return_value_policy::reference_internal)
    .def("string_value", &SsbScriptParser::Lang_string_argumentContext::string_value, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Lang_string_argumentContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::String_valueContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "String_valueContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::String_valueContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::String_valueContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::String_valueContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("MULTILINE_STRING_LITERAL", &SsbScriptParser::String_valueContext::MULTILINE_STRING_LITERAL, py::return_value_policy::reference_internal)
    .def("STRING_LITERAL", &SsbScriptParser::String_valueContext::STRING_LITERAL, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::String_valueContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::Ctx_headerContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "Ctx_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::Ctx_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::Ctx_headerContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::Ctx_headerContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &SsbScriptParser::Ctx_headerContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("primitive", &SsbScriptParser::Ctx_headerContext::primitive, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::Ctx_headerContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptParser::For_target_def_targetContext, antlr4::ParserRuleContext>(m_parser_sub_SsbScript, "For_target_def_targetContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&SsbScriptParser::For_target_def_targetContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&SsbScriptParser::For_target_def_targetContext::toStringTree))
    .def("getRuleIndex", &SsbScriptParser::For_target_def_targetContext::getRuleIndex, py::return_value_policy::reference_internal)
    .def("FOR", &SsbScriptParser::For_target_def_targetContext::FOR, py::return_value_policy::reference_internal)
    .def("IDENTIFIER", &SsbScriptParser::For_target_def_targetContext::IDENTIFIER, py::return_value_policy::reference_internal)
    .def("FOR_TARGET", &SsbScriptParser::For_target_def_targetContext::FOR_TARGET, py::return_value_policy::reference_internal)
    .def("accept", &SsbScriptParser::For_target_def_targetContext::accept, py::return_value_policy::reference_internal)
;
py::class_<SsbScriptBaseVisitor, PySsbScriptBaseVisitor, antlr4::tree::ParseTreeVisitor>(m, "SsbScriptBaseVisitor")
    .def(py::init<>())
    .def("visitChildren", [](SsbScriptBaseVisitor& self, antlr4::tree::ParseTree* node) {
        return std::any_cast<pybind11::object>(self.visitChildren(node));
    }, py::return_value_policy::reference_internal, py::keep_alive<1, 2>())
    .def("defaultResult", [](SsbScriptBaseVisitor& self) {
        return std::any_cast<pybind11::object>(self.defaultResult());
    }, py::keep_alive<1, 2>())
    .def("visitTerminal", [](SsbScriptBaseVisitor& self, antlr4::tree::TerminalNode * node) {
        return std::any_cast<pybind11::object>(self.visitTerminal(node));
    }, py::return_value_policy::reference_internal, py::keep_alive<1, 2>())
    .def("aggregateResult", [](SsbScriptBaseVisitor& self, pybind11::object aggregate, pybind11::object nextResult) {
        return std::any_cast<pybind11::object>(self.aggregateResult(aggregate, nextResult));
    }, py::return_value_policy::reference_internal)
    .def("visit", [](SsbScriptBaseVisitor& self, antlr4::tree::ParseTree* tree) {
        return std::any_cast<pybind11::object>(self.visit(tree));
    }, py::return_value_policy::reference_internal, py::keep_alive<1, 2>())
    .def("visitPos_argument", &SsbScriptBaseVisitor::visitPos_argument, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitJump_marker", &SsbScriptBaseVisitor::visitJump_marker, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitStart", &SsbScriptBaseVisitor::visitStart, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFuncdef", &SsbScriptBaseVisitor::visitFuncdef, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitSimple_def", &SsbScriptBaseVisitor::visitSimple_def, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCoro_def", &SsbScriptBaseVisitor::visitCoro_def, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFor_target_def", &SsbScriptBaseVisitor::visitFor_target_def, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitPrimitive", &SsbScriptBaseVisitor::visitPrimitive, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitStmt", &SsbScriptBaseVisitor::visitStmt, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitOperation", &SsbScriptBaseVisitor::visitOperation, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitInline_ctx", &SsbScriptBaseVisitor::visitInline_ctx, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFunc_suite", &SsbScriptBaseVisitor::visitFunc_suite, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFunc_alias", &SsbScriptBaseVisitor::visitFunc_alias, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitArglist", &SsbScriptBaseVisitor::visitArglist, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitPosition_marker", &SsbScriptBaseVisitor::visitPosition_marker, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitPosition_marker_arg", &SsbScriptBaseVisitor::visitPosition_marker_arg, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitLabel", &SsbScriptBaseVisitor::visitLabel, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitString", &SsbScriptBaseVisitor::visitString, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitLang_string", &SsbScriptBaseVisitor::visitLang_string, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitLang_string_argument", &SsbScriptBaseVisitor::visitLang_string_argument, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitString_value", &SsbScriptBaseVisitor::visitString_value, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitCtx_header", &SsbScriptBaseVisitor::visitCtx_header, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
    .def("visitFor_target_def_target", &SsbScriptBaseVisitor::visitFor_target_def_target, py::keep_alive<1, 2>(), py::return_value_policy::reference_internal)
;}