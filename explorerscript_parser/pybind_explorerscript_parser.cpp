#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "antlr4-runtime.h"
#include "ExplorerScriptLexer.h"
#include "ExplorerScriptParser.h"
#include "ExplorerScriptVisitor.h"
#include "parser_wrapper.h"
            
using namespace antlr4;
namespace py = pybind11;
            
class PyExplorerScriptVisitor : public ExplorerScriptVisitor {
public:
    /* Inherit the constructors */
    using ExplorerScriptVisitor::ExplorerScriptVisitor;

    pybind11::object visitStart__wrapper(ExplorerScriptParser::StartContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitStart,
            context
        );
    }
    std::any visitStart(ExplorerScriptParser::StartContext *context) override {
        return visitStart__wrapper(context);
    }
    pybind11::object visitImport_stmt__wrapper(ExplorerScriptParser::Import_stmtContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitImport_stmt,
            context
        );
    }
    std::any visitImport_stmt(ExplorerScriptParser::Import_stmtContext *context) override {
        return visitImport_stmt__wrapper(context);
    }
    pybind11::object visitMacrodef__wrapper(ExplorerScriptParser::MacrodefContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitMacrodef,
            context
        );
    }
    std::any visitMacrodef(ExplorerScriptParser::MacrodefContext *context) override {
        return visitMacrodef__wrapper(context);
    }
    pybind11::object visitStmt__wrapper(ExplorerScriptParser::StmtContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitStmt,
            context
        );
    }
    std::any visitStmt(ExplorerScriptParser::StmtContext *context) override {
        return visitStmt__wrapper(context);
    }
    pybind11::object visitSimple_stmt__wrapper(ExplorerScriptParser::Simple_stmtContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSimple_stmt,
            context
        );
    }
    std::any visitSimple_stmt(ExplorerScriptParser::Simple_stmtContext *context) override {
        return visitSimple_stmt__wrapper(context);
    }
    pybind11::object visitCntrl_stmt__wrapper(ExplorerScriptParser::Cntrl_stmtContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCntrl_stmt,
            context
        );
    }
    std::any visitCntrl_stmt(ExplorerScriptParser::Cntrl_stmtContext *context) override {
        return visitCntrl_stmt__wrapper(context);
    }
    pybind11::object visitJump__wrapper(ExplorerScriptParser::JumpContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitJump,
            context
        );
    }
    std::any visitJump(ExplorerScriptParser::JumpContext *context) override {
        return visitJump__wrapper(context);
    }
    pybind11::object visitCall__wrapper(ExplorerScriptParser::CallContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCall,
            context
        );
    }
    std::any visitCall(ExplorerScriptParser::CallContext *context) override {
        return visitCall__wrapper(context);
    }
    pybind11::object visitMacro_call__wrapper(ExplorerScriptParser::Macro_callContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitMacro_call,
            context
        );
    }
    std::any visitMacro_call(ExplorerScriptParser::Macro_callContext *context) override {
        return visitMacro_call__wrapper(context);
    }
    pybind11::object visitCtx_block__wrapper(ExplorerScriptParser::Ctx_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCtx_block,
            context
        );
    }
    std::any visitCtx_block(ExplorerScriptParser::Ctx_blockContext *context) override {
        return visitCtx_block__wrapper(context);
    }
    pybind11::object visitIf_block__wrapper(ExplorerScriptParser::If_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_block,
            context
        );
    }
    std::any visitIf_block(ExplorerScriptParser::If_blockContext *context) override {
        return visitIf_block__wrapper(context);
    }
    pybind11::object visitElseif_block__wrapper(ExplorerScriptParser::Elseif_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitElseif_block,
            context
        );
    }
    std::any visitElseif_block(ExplorerScriptParser::Elseif_blockContext *context) override {
        return visitElseif_block__wrapper(context);
    }
    pybind11::object visitElse_block__wrapper(ExplorerScriptParser::Else_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitElse_block,
            context
        );
    }
    std::any visitElse_block(ExplorerScriptParser::Else_blockContext *context) override {
        return visitElse_block__wrapper(context);
    }
    pybind11::object visitIf_header__wrapper(ExplorerScriptParser::If_headerContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_header,
            context
        );
    }
    std::any visitIf_header(ExplorerScriptParser::If_headerContext *context) override {
        return visitIf_header__wrapper(context);
    }
    pybind11::object visitIf_h_negatable__wrapper(ExplorerScriptParser::If_h_negatableContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_h_negatable,
            context
        );
    }
    std::any visitIf_h_negatable(ExplorerScriptParser::If_h_negatableContext *context) override {
        return visitIf_h_negatable__wrapper(context);
    }
    pybind11::object visitIf_h_op__wrapper(ExplorerScriptParser::If_h_opContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_h_op,
            context
        );
    }
    std::any visitIf_h_op(ExplorerScriptParser::If_h_opContext *context) override {
        return visitIf_h_op__wrapper(context);
    }
    pybind11::object visitIf_h_bit__wrapper(ExplorerScriptParser::If_h_bitContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_h_bit,
            context
        );
    }
    std::any visitIf_h_bit(ExplorerScriptParser::If_h_bitContext *context) override {
        return visitIf_h_bit__wrapper(context);
    }
    pybind11::object visitIf_h_scn__wrapper(ExplorerScriptParser::If_h_scnContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitIf_h_scn,
            context
        );
    }
    std::any visitIf_h_scn(ExplorerScriptParser::If_h_scnContext *context) override {
        return visitIf_h_scn__wrapper(context);
    }
    pybind11::object visitSwitch_block__wrapper(ExplorerScriptParser::Switch_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_block,
            context
        );
    }
    std::any visitSwitch_block(ExplorerScriptParser::Switch_blockContext *context) override {
        return visitSwitch_block__wrapper(context);
    }
    pybind11::object visitMessage_switch_block__wrapper(ExplorerScriptParser::Message_switch_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitMessage_switch_block,
            context
        );
    }
    std::any visitMessage_switch_block(ExplorerScriptParser::Message_switch_blockContext *context) override {
        return visitMessage_switch_block__wrapper(context);
    }
    pybind11::object visitSingle_case_block__wrapper(ExplorerScriptParser::Single_case_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSingle_case_block,
            context
        );
    }
    std::any visitSingle_case_block(ExplorerScriptParser::Single_case_blockContext *context) override {
        return visitSingle_case_block__wrapper(context);
    }
    pybind11::object visitDefault__wrapper(ExplorerScriptParser::DefaultContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitDefault,
            context
        );
    }
    std::any visitDefault(ExplorerScriptParser::DefaultContext *context) override {
        return visitDefault__wrapper(context);
    }
    pybind11::object visitSwitch_header__wrapper(ExplorerScriptParser::Switch_headerContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_header,
            context
        );
    }
    std::any visitSwitch_header(ExplorerScriptParser::Switch_headerContext *context) override {
        return visitSwitch_header__wrapper(context);
    }
    pybind11::object visitSwitch_h_scn__wrapper(ExplorerScriptParser::Switch_h_scnContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_h_scn,
            context
        );
    }
    std::any visitSwitch_h_scn(ExplorerScriptParser::Switch_h_scnContext *context) override {
        return visitSwitch_h_scn__wrapper(context);
    }
    pybind11::object visitSwitch_h_random__wrapper(ExplorerScriptParser::Switch_h_randomContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_h_random,
            context
        );
    }
    std::any visitSwitch_h_random(ExplorerScriptParser::Switch_h_randomContext *context) override {
        return visitSwitch_h_random__wrapper(context);
    }
    pybind11::object visitSwitch_h_dungeon_mode__wrapper(ExplorerScriptParser::Switch_h_dungeon_modeContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_h_dungeon_mode,
            context
        );
    }
    std::any visitSwitch_h_dungeon_mode(ExplorerScriptParser::Switch_h_dungeon_modeContext *context) override {
        return visitSwitch_h_dungeon_mode__wrapper(context);
    }
    pybind11::object visitSwitch_h_sector__wrapper(ExplorerScriptParser::Switch_h_sectorContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSwitch_h_sector,
            context
        );
    }
    std::any visitSwitch_h_sector(ExplorerScriptParser::Switch_h_sectorContext *context) override {
        return visitSwitch_h_sector__wrapper(context);
    }
    pybind11::object visitCase_header__wrapper(ExplorerScriptParser::Case_headerContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCase_header,
            context
        );
    }
    std::any visitCase_header(ExplorerScriptParser::Case_headerContext *context) override {
        return visitCase_header__wrapper(context);
    }
    pybind11::object visitCase_h_menu__wrapper(ExplorerScriptParser::Case_h_menuContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCase_h_menu,
            context
        );
    }
    std::any visitCase_h_menu(ExplorerScriptParser::Case_h_menuContext *context) override {
        return visitCase_h_menu__wrapper(context);
    }
    pybind11::object visitCase_h_menu2__wrapper(ExplorerScriptParser::Case_h_menu2Context *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCase_h_menu2,
            context
        );
    }
    std::any visitCase_h_menu2(ExplorerScriptParser::Case_h_menu2Context *context) override {
        return visitCase_h_menu2__wrapper(context);
    }
    pybind11::object visitCase_h_op__wrapper(ExplorerScriptParser::Case_h_opContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCase_h_op,
            context
        );
    }
    std::any visitCase_h_op(ExplorerScriptParser::Case_h_opContext *context) override {
        return visitCase_h_op__wrapper(context);
    }
    pybind11::object visitForever_block__wrapper(ExplorerScriptParser::Forever_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitForever_block,
            context
        );
    }
    std::any visitForever_block(ExplorerScriptParser::Forever_blockContext *context) override {
        return visitForever_block__wrapper(context);
    }
    pybind11::object visitFor_block__wrapper(ExplorerScriptParser::For_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFor_block,
            context
        );
    }
    std::any visitFor_block(ExplorerScriptParser::For_blockContext *context) override {
        return visitFor_block__wrapper(context);
    }
    pybind11::object visitWhile_block__wrapper(ExplorerScriptParser::While_blockContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitWhile_block,
            context
        );
    }
    std::any visitWhile_block(ExplorerScriptParser::While_blockContext *context) override {
        return visitWhile_block__wrapper(context);
    }
    pybind11::object visitAssignment__wrapper(ExplorerScriptParser::AssignmentContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment,
            context
        );
    }
    std::any visitAssignment(ExplorerScriptParser::AssignmentContext *context) override {
        return visitAssignment__wrapper(context);
    }
    pybind11::object visitAssignment_regular__wrapper(ExplorerScriptParser::Assignment_regularContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_regular,
            context
        );
    }
    std::any visitAssignment_regular(ExplorerScriptParser::Assignment_regularContext *context) override {
        return visitAssignment_regular__wrapper(context);
    }
    pybind11::object visitAssignment_clear__wrapper(ExplorerScriptParser::Assignment_clearContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_clear,
            context
        );
    }
    std::any visitAssignment_clear(ExplorerScriptParser::Assignment_clearContext *context) override {
        return visitAssignment_clear__wrapper(context);
    }
    pybind11::object visitAssignment_initial__wrapper(ExplorerScriptParser::Assignment_initialContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_initial,
            context
        );
    }
    std::any visitAssignment_initial(ExplorerScriptParser::Assignment_initialContext *context) override {
        return visitAssignment_initial__wrapper(context);
    }
    pybind11::object visitAssignment_reset__wrapper(ExplorerScriptParser::Assignment_resetContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_reset,
            context
        );
    }
    std::any visitAssignment_reset(ExplorerScriptParser::Assignment_resetContext *context) override {
        return visitAssignment_reset__wrapper(context);
    }
    pybind11::object visitAssignment_adv_log__wrapper(ExplorerScriptParser::Assignment_adv_logContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_adv_log,
            context
        );
    }
    std::any visitAssignment_adv_log(ExplorerScriptParser::Assignment_adv_logContext *context) override {
        return visitAssignment_adv_log__wrapper(context);
    }
    pybind11::object visitAssignment_dungeon_mode__wrapper(ExplorerScriptParser::Assignment_dungeon_modeContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_dungeon_mode,
            context
        );
    }
    std::any visitAssignment_dungeon_mode(ExplorerScriptParser::Assignment_dungeon_modeContext *context) override {
        return visitAssignment_dungeon_mode__wrapper(context);
    }
    pybind11::object visitAssignment_scn__wrapper(ExplorerScriptParser::Assignment_scnContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssignment_scn,
            context
        );
    }
    std::any visitAssignment_scn(ExplorerScriptParser::Assignment_scnContext *context) override {
        return visitAssignment_scn__wrapper(context);
    }
    pybind11::object visitValue_of__wrapper(ExplorerScriptParser::Value_ofContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitValue_of,
            context
        );
    }
    std::any visitValue_of(ExplorerScriptParser::Value_ofContext *context) override {
        return visitValue_of__wrapper(context);
    }
    pybind11::object visitScn_var__wrapper(ExplorerScriptParser::Scn_varContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitScn_var,
            context
        );
    }
    std::any visitScn_var(ExplorerScriptParser::Scn_varContext *context) override {
        return visitScn_var__wrapper(context);
    }
    pybind11::object visitConditional_operator__wrapper(ExplorerScriptParser::Conditional_operatorContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitConditional_operator,
            context
        );
    }
    std::any visitConditional_operator(ExplorerScriptParser::Conditional_operatorContext *context) override {
        return visitConditional_operator__wrapper(context);
    }
    pybind11::object visitAssign_operator__wrapper(ExplorerScriptParser::Assign_operatorContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitAssign_operator,
            context
        );
    }
    std::any visitAssign_operator(ExplorerScriptParser::Assign_operatorContext *context) override {
        return visitAssign_operator__wrapper(context);
    }
    pybind11::object visitFuncdef__wrapper(ExplorerScriptParser::FuncdefContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFuncdef,
            context
        );
    }
    std::any visitFuncdef(ExplorerScriptParser::FuncdefContext *context) override {
        return visitFuncdef__wrapper(context);
    }
    pybind11::object visitSimple_def__wrapper(ExplorerScriptParser::Simple_defContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitSimple_def,
            context
        );
    }
    std::any visitSimple_def(ExplorerScriptParser::Simple_defContext *context) override {
        return visitSimple_def__wrapper(context);
    }
    pybind11::object visitCoro_def__wrapper(ExplorerScriptParser::Coro_defContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCoro_def,
            context
        );
    }
    std::any visitCoro_def(ExplorerScriptParser::Coro_defContext *context) override {
        return visitCoro_def__wrapper(context);
    }
    pybind11::object visitFor_target_def__wrapper(ExplorerScriptParser::For_target_defContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFor_target_def,
            context
        );
    }
    std::any visitFor_target_def(ExplorerScriptParser::For_target_defContext *context) override {
        return visitFor_target_def__wrapper(context);
    }
    pybind11::object visitInteger_like__wrapper(ExplorerScriptParser::Integer_likeContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitInteger_like,
            context
        );
    }
    std::any visitInteger_like(ExplorerScriptParser::Integer_likeContext *context) override {
        return visitInteger_like__wrapper(context);
    }
    pybind11::object visitOperation__wrapper(ExplorerScriptParser::OperationContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitOperation,
            context
        );
    }
    std::any visitOperation(ExplorerScriptParser::OperationContext *context) override {
        return visitOperation__wrapper(context);
    }
    pybind11::object visitInline_ctx__wrapper(ExplorerScriptParser::Inline_ctxContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitInline_ctx,
            context
        );
    }
    std::any visitInline_ctx(ExplorerScriptParser::Inline_ctxContext *context) override {
        return visitInline_ctx__wrapper(context);
    }
    pybind11::object visitFunc_suite__wrapper(ExplorerScriptParser::Func_suiteContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFunc_suite,
            context
        );
    }
    std::any visitFunc_suite(ExplorerScriptParser::Func_suiteContext *context) override {
        return visitFunc_suite__wrapper(context);
    }
    pybind11::object visitFunc_alias__wrapper(ExplorerScriptParser::Func_aliasContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFunc_alias,
            context
        );
    }
    std::any visitFunc_alias(ExplorerScriptParser::Func_aliasContext *context) override {
        return visitFunc_alias__wrapper(context);
    }
    pybind11::object visitArglist__wrapper(ExplorerScriptParser::ArglistContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitArglist,
            context
        );
    }
    std::any visitArglist(ExplorerScriptParser::ArglistContext *context) override {
        return visitArglist__wrapper(context);
    }
    pybind11::object visitPos_argument__wrapper(ExplorerScriptParser::Pos_argumentContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitPos_argument,
            context
        );
    }
    std::any visitPos_argument(ExplorerScriptParser::Pos_argumentContext *context) override {
        return visitPos_argument__wrapper(context);
    }
    pybind11::object visitPosition_marker__wrapper(ExplorerScriptParser::Position_markerContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitPosition_marker,
            context
        );
    }
    std::any visitPosition_marker(ExplorerScriptParser::Position_markerContext *context) override {
        return visitPosition_marker__wrapper(context);
    }
    pybind11::object visitPosition_marker_arg__wrapper(ExplorerScriptParser::Position_marker_argContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitPosition_marker_arg,
            context
        );
    }
    std::any visitPosition_marker_arg(ExplorerScriptParser::Position_marker_argContext *context) override {
        return visitPosition_marker_arg__wrapper(context);
    }
    pybind11::object visitLabel__wrapper(ExplorerScriptParser::LabelContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitLabel,
            context
        );
    }
    std::any visitLabel(ExplorerScriptParser::LabelContext *context) override {
        return visitLabel__wrapper(context);
    }
    pybind11::object visitString__wrapper(ExplorerScriptParser::StringContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitString,
            context
        );
    }
    std::any visitString(ExplorerScriptParser::StringContext *context) override {
        return visitString__wrapper(context);
    }
    pybind11::object visitLang_string__wrapper(ExplorerScriptParser::Lang_stringContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitLang_string,
            context
        );
    }
    std::any visitLang_string(ExplorerScriptParser::Lang_stringContext *context) override {
        return visitLang_string__wrapper(context);
    }
    pybind11::object visitLang_string_argument__wrapper(ExplorerScriptParser::Lang_string_argumentContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitLang_string_argument,
            context
        );
    }
    std::any visitLang_string_argument(ExplorerScriptParser::Lang_string_argumentContext *context) override {
        return visitLang_string_argument__wrapper(context);
    }
    pybind11::object visitString_value__wrapper(ExplorerScriptParser::String_valueContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitString_value,
            context
        );
    }
    std::any visitString_value(ExplorerScriptParser::String_valueContext *context) override {
        return visitString_value__wrapper(context);
    }
    pybind11::object visitCtx_header__wrapper(ExplorerScriptParser::Ctx_headerContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitCtx_header,
            context
        );
    }
    std::any visitCtx_header(ExplorerScriptParser::Ctx_headerContext *context) override {
        return visitCtx_header__wrapper(context);
    }
    pybind11::object visitFor_target_def_target__wrapper(ExplorerScriptParser::For_target_def_targetContext *context) {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            visitFor_target_def_target,
            context
        );
    }
    std::any visitFor_target_def_target(ExplorerScriptParser::For_target_def_targetContext *context) override {
        return visitFor_target_def_target__wrapper(context);
    }
    std::any defaultResult() override {
        PYBIND11_OVERRIDE_PURE(
            pybind11::object,
            ExplorerScriptVisitor,
            defaultResult
        );
    }
};
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


py::class_<ExplorerScriptParser::StartContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::StartContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::StartContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::StartContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::StartContext::getRuleIndex)
    .def("EOF", &ExplorerScriptParser::StartContext::EOF)
    .def("import_stmt", py::overload_cast<>(&ExplorerScriptParser::StartContext::import_stmt))
    .def("import_stmt", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::import_stmt))
    .def("macrodef", py::overload_cast<>(&ExplorerScriptParser::StartContext::macrodef))
    .def("macrodef", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::macrodef))
    .def("funcdef", py::overload_cast<>(&ExplorerScriptParser::StartContext::funcdef))
    .def("funcdef", py::overload_cast<size_t>(&ExplorerScriptParser::StartContext::funcdef))
    .def("enterRule", &ExplorerScriptParser::StartContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::StartContext::exitRule)
    .def("accept", &ExplorerScriptParser::StartContext::accept)
;
py::class_<ExplorerScriptParser::Import_stmtContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Import_stmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Import_stmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Import_stmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Import_stmtContext::getRuleIndex)
    .def("IMPORT", &ExplorerScriptParser::Import_stmtContext::IMPORT)
    .def("STRING_LITERAL", &ExplorerScriptParser::Import_stmtContext::STRING_LITERAL)
    .def("enterRule", &ExplorerScriptParser::Import_stmtContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Import_stmtContext::exitRule)
    .def("accept", &ExplorerScriptParser::Import_stmtContext::accept)
;
py::class_<ExplorerScriptParser::MacrodefContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::MacrodefContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::MacrodefContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::MacrodefContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::MacrodefContext::getRuleIndex)
    .def("MACRO", &ExplorerScriptParser::MacrodefContext::MACRO)
    .def("IDENTIFIER", &ExplorerScriptParser::MacrodefContext::IDENTIFIER)
    .def("OPEN_PAREN", &ExplorerScriptParser::MacrodefContext::OPEN_PAREN)
    .def("CLOSE_PAREN", &ExplorerScriptParser::MacrodefContext::CLOSE_PAREN)
    .def("func_suite", &ExplorerScriptParser::MacrodefContext::func_suite)
    .def("VARIABLE", py::overload_cast<>(&ExplorerScriptParser::MacrodefContext::VARIABLE))
    .def("VARIABLE", py::overload_cast<size_t>(&ExplorerScriptParser::MacrodefContext::VARIABLE))
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::MacrodefContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::MacrodefContext::COMMA))
    .def("enterRule", &ExplorerScriptParser::MacrodefContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::MacrodefContext::exitRule)
    .def("accept", &ExplorerScriptParser::MacrodefContext::accept)
;
py::class_<ExplorerScriptParser::StmtContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::StmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::StmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::StmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::StmtContext::getRuleIndex)
    .def("simple_stmt", &ExplorerScriptParser::StmtContext::simple_stmt)
    .def("ctx_block", &ExplorerScriptParser::StmtContext::ctx_block)
    .def("if_block", &ExplorerScriptParser::StmtContext::if_block)
    .def("switch_block", &ExplorerScriptParser::StmtContext::switch_block)
    .def("message_switch_block", &ExplorerScriptParser::StmtContext::message_switch_block)
    .def("forever_block", &ExplorerScriptParser::StmtContext::forever_block)
    .def("for_block", &ExplorerScriptParser::StmtContext::for_block)
    .def("while_block", &ExplorerScriptParser::StmtContext::while_block)
    .def("macro_call", &ExplorerScriptParser::StmtContext::macro_call)
    .def("enterRule", &ExplorerScriptParser::StmtContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::StmtContext::exitRule)
    .def("accept", &ExplorerScriptParser::StmtContext::accept)
;
py::class_<ExplorerScriptParser::Simple_stmtContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Simple_stmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Simple_stmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Simple_stmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Simple_stmtContext::getRuleIndex)
    .def("operation", &ExplorerScriptParser::Simple_stmtContext::operation)
    .def("label", &ExplorerScriptParser::Simple_stmtContext::label)
    .def("cntrl_stmt", &ExplorerScriptParser::Simple_stmtContext::cntrl_stmt)
    .def("jump", &ExplorerScriptParser::Simple_stmtContext::jump)
    .def("call", &ExplorerScriptParser::Simple_stmtContext::call)
    .def("assignment", &ExplorerScriptParser::Simple_stmtContext::assignment)
    .def("enterRule", &ExplorerScriptParser::Simple_stmtContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Simple_stmtContext::exitRule)
    .def("accept", &ExplorerScriptParser::Simple_stmtContext::accept)
;
py::class_<ExplorerScriptParser::Cntrl_stmtContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Cntrl_stmtContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Cntrl_stmtContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Cntrl_stmtContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Cntrl_stmtContext::getRuleIndex)
    .def("RETURN", &ExplorerScriptParser::Cntrl_stmtContext::RETURN)
    .def("END", &ExplorerScriptParser::Cntrl_stmtContext::END)
    .def("HOLD", &ExplorerScriptParser::Cntrl_stmtContext::HOLD)
    .def("CONTINUE", &ExplorerScriptParser::Cntrl_stmtContext::CONTINUE)
    .def("BREAK", &ExplorerScriptParser::Cntrl_stmtContext::BREAK)
    .def("BREAK_LOOP", &ExplorerScriptParser::Cntrl_stmtContext::BREAK_LOOP)
    .def("enterRule", &ExplorerScriptParser::Cntrl_stmtContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Cntrl_stmtContext::exitRule)
    .def("accept", &ExplorerScriptParser::Cntrl_stmtContext::accept)
;
py::class_<ExplorerScriptParser::JumpContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::JumpContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::JumpContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::JumpContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::JumpContext::getRuleIndex)
    .def("JUMP", &ExplorerScriptParser::JumpContext::JUMP)
    .def("AT", &ExplorerScriptParser::JumpContext::AT)
    .def("IDENTIFIER", &ExplorerScriptParser::JumpContext::IDENTIFIER)
    .def("enterRule", &ExplorerScriptParser::JumpContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::JumpContext::exitRule)
    .def("accept", &ExplorerScriptParser::JumpContext::accept)
;
py::class_<ExplorerScriptParser::CallContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::CallContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::CallContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::CallContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::CallContext::getRuleIndex)
    .def("CALL", &ExplorerScriptParser::CallContext::CALL)
    .def("AT", &ExplorerScriptParser::CallContext::AT)
    .def("IDENTIFIER", &ExplorerScriptParser::CallContext::IDENTIFIER)
    .def("enterRule", &ExplorerScriptParser::CallContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::CallContext::exitRule)
    .def("accept", &ExplorerScriptParser::CallContext::accept)
;
py::class_<ExplorerScriptParser::Macro_callContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Macro_callContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Macro_callContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Macro_callContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Macro_callContext::getRuleIndex)
    .def("MACRO_CALL", &ExplorerScriptParser::Macro_callContext::MACRO_CALL)
    .def("OPEN_PAREN", &ExplorerScriptParser::Macro_callContext::OPEN_PAREN)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Macro_callContext::CLOSE_PAREN)
    .def("arglist", &ExplorerScriptParser::Macro_callContext::arglist)
    .def("enterRule", &ExplorerScriptParser::Macro_callContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Macro_callContext::exitRule)
    .def("accept", &ExplorerScriptParser::Macro_callContext::accept)
;
py::class_<ExplorerScriptParser::Ctx_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Ctx_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Ctx_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Ctx_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Ctx_blockContext::getRuleIndex)
    .def("WITH", &ExplorerScriptParser::Ctx_blockContext::WITH)
    .def("OPEN_PAREN", &ExplorerScriptParser::Ctx_blockContext::OPEN_PAREN)
    .def("ctx_header", &ExplorerScriptParser::Ctx_blockContext::ctx_header)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Ctx_blockContext::CLOSE_PAREN)
    .def("OPEN_BRACE", &ExplorerScriptParser::Ctx_blockContext::OPEN_BRACE)
    .def("simple_stmt", &ExplorerScriptParser::Ctx_blockContext::simple_stmt)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Ctx_blockContext::CLOSE_BRACE)
    .def("enterRule", &ExplorerScriptParser::Ctx_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Ctx_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::Ctx_blockContext::accept)
;
py::class_<ExplorerScriptParser::If_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_blockContext::getRuleIndex)
    .def("IF", &ExplorerScriptParser::If_blockContext::IF)
    .def("OPEN_PAREN", &ExplorerScriptParser::If_blockContext::OPEN_PAREN)
    .def("if_header", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::if_header))
    .def("if_header", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::if_header))
    .def("CLOSE_PAREN", &ExplorerScriptParser::If_blockContext::CLOSE_PAREN)
    .def("OPEN_BRACE", &ExplorerScriptParser::If_blockContext::OPEN_BRACE)
    .def("CLOSE_BRACE", &ExplorerScriptParser::If_blockContext::CLOSE_BRACE)
    .def("NOT", &ExplorerScriptParser::If_blockContext::NOT)
    .def("OR", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::OR))
    .def("OR", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::OR))
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::stmt))
    .def("elseif_block", py::overload_cast<>(&ExplorerScriptParser::If_blockContext::elseif_block))
    .def("elseif_block", py::overload_cast<size_t>(&ExplorerScriptParser::If_blockContext::elseif_block))
    .def("else_block", &ExplorerScriptParser::If_blockContext::else_block)
    .def("enterRule", &ExplorerScriptParser::If_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::If_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::If_blockContext::accept)
;
py::class_<ExplorerScriptParser::Elseif_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Elseif_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Elseif_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Elseif_blockContext::getRuleIndex)
    .def("ELSEIF", &ExplorerScriptParser::Elseif_blockContext::ELSEIF)
    .def("OPEN_PAREN", &ExplorerScriptParser::Elseif_blockContext::OPEN_PAREN)
    .def("if_header", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::if_header))
    .def("if_header", py::overload_cast<size_t>(&ExplorerScriptParser::Elseif_blockContext::if_header))
    .def("CLOSE_PAREN", &ExplorerScriptParser::Elseif_blockContext::CLOSE_PAREN)
    .def("OPEN_BRACE", &ExplorerScriptParser::Elseif_blockContext::OPEN_BRACE)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Elseif_blockContext::CLOSE_BRACE)
    .def("NOT", &ExplorerScriptParser::Elseif_blockContext::NOT)
    .def("OR", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::OR))
    .def("OR", py::overload_cast<size_t>(&ExplorerScriptParser::Elseif_blockContext::OR))
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Elseif_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Elseif_blockContext::stmt))
    .def("enterRule", &ExplorerScriptParser::Elseif_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Elseif_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::Elseif_blockContext::accept)
;
py::class_<ExplorerScriptParser::Else_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Else_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Else_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Else_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Else_blockContext::getRuleIndex)
    .def("ELSE", &ExplorerScriptParser::Else_blockContext::ELSE)
    .def("OPEN_BRACE", &ExplorerScriptParser::Else_blockContext::OPEN_BRACE)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Else_blockContext::CLOSE_BRACE)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Else_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Else_blockContext::stmt))
    .def("enterRule", &ExplorerScriptParser::Else_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Else_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::Else_blockContext::accept)
;
py::class_<ExplorerScriptParser::If_headerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_headerContext::getRuleIndex)
    .def("if_h_op", &ExplorerScriptParser::If_headerContext::if_h_op)
    .def("if_h_bit", &ExplorerScriptParser::If_headerContext::if_h_bit)
    .def("if_h_negatable", &ExplorerScriptParser::If_headerContext::if_h_negatable)
    .def("if_h_scn", &ExplorerScriptParser::If_headerContext::if_h_scn)
    .def("operation", &ExplorerScriptParser::If_headerContext::operation)
    .def("enterRule", &ExplorerScriptParser::If_headerContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::If_headerContext::exitRule)
    .def("accept", &ExplorerScriptParser::If_headerContext::accept)
;
py::class_<ExplorerScriptParser::If_h_negatableContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_h_negatableContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_negatableContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_negatableContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_negatableContext::getRuleIndex)
    .def("DEBUG", &ExplorerScriptParser::If_h_negatableContext::DEBUG)
    .def("EDIT", &ExplorerScriptParser::If_h_negatableContext::EDIT)
    .def("VARIATION", &ExplorerScriptParser::If_h_negatableContext::VARIATION)
    .def("NOT", &ExplorerScriptParser::If_h_negatableContext::NOT)
    .def("enterRule", &ExplorerScriptParser::If_h_negatableContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::If_h_negatableContext::exitRule)
    .def("accept", &ExplorerScriptParser::If_h_negatableContext::accept)
;
py::class_<ExplorerScriptParser::If_h_opContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_h_opContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_opContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_opContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_opContext::getRuleIndex)
    .def("integer_like", py::overload_cast<>(&ExplorerScriptParser::If_h_opContext::integer_like))
    .def("integer_like", py::overload_cast<size_t>(&ExplorerScriptParser::If_h_opContext::integer_like))
    .def("conditional_operator", &ExplorerScriptParser::If_h_opContext::conditional_operator)
    .def("value_of", &ExplorerScriptParser::If_h_opContext::value_of)
    .def("enterRule", &ExplorerScriptParser::If_h_opContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::If_h_opContext::exitRule)
    .def("accept", &ExplorerScriptParser::If_h_opContext::accept)
;
py::class_<ExplorerScriptParser::If_h_bitContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_h_bitContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_bitContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_bitContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_bitContext::getRuleIndex)
    .def("integer_like", &ExplorerScriptParser::If_h_bitContext::integer_like)
    .def("OPEN_BRACKET", &ExplorerScriptParser::If_h_bitContext::OPEN_BRACKET)
    .def("INTEGER", &ExplorerScriptParser::If_h_bitContext::INTEGER)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::If_h_bitContext::CLOSE_BRACKET)
    .def("NOT", &ExplorerScriptParser::If_h_bitContext::NOT)
    .def("enterRule", &ExplorerScriptParser::If_h_bitContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::If_h_bitContext::exitRule)
    .def("accept", &ExplorerScriptParser::If_h_bitContext::accept)
;
py::class_<ExplorerScriptParser::If_h_scnContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::If_h_scnContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::If_h_scnContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::If_h_scnContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::If_h_scnContext::getRuleIndex)
    .def("scn_var", &ExplorerScriptParser::If_h_scnContext::scn_var)
    .def("conditional_operator", &ExplorerScriptParser::If_h_scnContext::conditional_operator)
    .def("OPEN_BRACKET", &ExplorerScriptParser::If_h_scnContext::OPEN_BRACKET)
    .def("INTEGER", py::overload_cast<>(&ExplorerScriptParser::If_h_scnContext::INTEGER))
    .def("INTEGER", py::overload_cast<size_t>(&ExplorerScriptParser::If_h_scnContext::INTEGER))
    .def("COMMA", &ExplorerScriptParser::If_h_scnContext::COMMA)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::If_h_scnContext::CLOSE_BRACKET)
    .def("enterRule", &ExplorerScriptParser::If_h_scnContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::If_h_scnContext::exitRule)
    .def("accept", &ExplorerScriptParser::If_h_scnContext::accept)
;
py::class_<ExplorerScriptParser::Switch_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_blockContext::getRuleIndex)
    .def("SWITCH", &ExplorerScriptParser::Switch_blockContext::SWITCH)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_blockContext::OPEN_PAREN)
    .def("switch_header", &ExplorerScriptParser::Switch_blockContext::switch_header)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_blockContext::CLOSE_PAREN)
    .def("OPEN_BRACE", &ExplorerScriptParser::Switch_blockContext::OPEN_BRACE)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Switch_blockContext::CLOSE_BRACE)
    .def("default_", py::overload_cast<>(&ExplorerScriptParser::Switch_blockContext::default_))
    .def("default_", py::overload_cast<size_t>(&ExplorerScriptParser::Switch_blockContext::default_))
    .def("single_case_block", py::overload_cast<>(&ExplorerScriptParser::Switch_blockContext::single_case_block))
    .def("single_case_block", py::overload_cast<size_t>(&ExplorerScriptParser::Switch_blockContext::single_case_block))
    .def("enterRule", &ExplorerScriptParser::Switch_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Switch_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::Switch_blockContext::accept)
;
py::class_<ExplorerScriptParser::Message_switch_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Message_switch_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Message_switch_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Message_switch_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Message_switch_blockContext::getRuleIndex)
    .def("OPEN_PAREN", &ExplorerScriptParser::Message_switch_blockContext::OPEN_PAREN)
    .def("integer_like", &ExplorerScriptParser::Message_switch_blockContext::integer_like)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Message_switch_blockContext::CLOSE_PAREN)
    .def("OPEN_BRACE", &ExplorerScriptParser::Message_switch_blockContext::OPEN_BRACE)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Message_switch_blockContext::CLOSE_BRACE)
    .def("MESSAGE_SWITCH_TALK", &ExplorerScriptParser::Message_switch_blockContext::MESSAGE_SWITCH_TALK)
    .def("MESSAGE_SWITCH_MONOLOGUE", &ExplorerScriptParser::Message_switch_blockContext::MESSAGE_SWITCH_MONOLOGUE)
    .def("default_", py::overload_cast<>(&ExplorerScriptParser::Message_switch_blockContext::default_))
    .def("default_", py::overload_cast<size_t>(&ExplorerScriptParser::Message_switch_blockContext::default_))
    .def("single_case_block", py::overload_cast<>(&ExplorerScriptParser::Message_switch_blockContext::single_case_block))
    .def("single_case_block", py::overload_cast<size_t>(&ExplorerScriptParser::Message_switch_blockContext::single_case_block))
    .def("enterRule", &ExplorerScriptParser::Message_switch_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Message_switch_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::Message_switch_blockContext::accept)
;
py::class_<ExplorerScriptParser::Single_case_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Single_case_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Single_case_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Single_case_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Single_case_blockContext::getRuleIndex)
    .def("CASE", &ExplorerScriptParser::Single_case_blockContext::CASE)
    .def("case_header", &ExplorerScriptParser::Single_case_blockContext::case_header)
    .def("COLON", &ExplorerScriptParser::Single_case_blockContext::COLON)
    .def("string", &ExplorerScriptParser::Single_case_blockContext::string)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Single_case_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Single_case_blockContext::stmt))
    .def("enterRule", &ExplorerScriptParser::Single_case_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Single_case_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::Single_case_blockContext::accept)
;
py::class_<ExplorerScriptParser::DefaultContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::DefaultContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::DefaultContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::DefaultContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::DefaultContext::getRuleIndex)
    .def("DEFAULT", &ExplorerScriptParser::DefaultContext::DEFAULT)
    .def("COLON", &ExplorerScriptParser::DefaultContext::COLON)
    .def("string", &ExplorerScriptParser::DefaultContext::string)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::DefaultContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::DefaultContext::stmt))
    .def("enterRule", &ExplorerScriptParser::DefaultContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::DefaultContext::exitRule)
    .def("accept", &ExplorerScriptParser::DefaultContext::accept)
;
py::class_<ExplorerScriptParser::Switch_headerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_headerContext::getRuleIndex)
    .def("integer_like", &ExplorerScriptParser::Switch_headerContext::integer_like)
    .def("operation", &ExplorerScriptParser::Switch_headerContext::operation)
    .def("switch_h_scn", &ExplorerScriptParser::Switch_headerContext::switch_h_scn)
    .def("switch_h_random", &ExplorerScriptParser::Switch_headerContext::switch_h_random)
    .def("switch_h_dungeon_mode", &ExplorerScriptParser::Switch_headerContext::switch_h_dungeon_mode)
    .def("switch_h_sector", &ExplorerScriptParser::Switch_headerContext::switch_h_sector)
    .def("enterRule", &ExplorerScriptParser::Switch_headerContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Switch_headerContext::exitRule)
    .def("accept", &ExplorerScriptParser::Switch_headerContext::accept)
;
py::class_<ExplorerScriptParser::Switch_h_scnContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_h_scnContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_scnContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_scnContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_scnContext::getRuleIndex)
    .def("scn_var", &ExplorerScriptParser::Switch_h_scnContext::scn_var)
    .def("OPEN_BRACKET", &ExplorerScriptParser::Switch_h_scnContext::OPEN_BRACKET)
    .def("INTEGER", &ExplorerScriptParser::Switch_h_scnContext::INTEGER)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::Switch_h_scnContext::CLOSE_BRACKET)
    .def("enterRule", &ExplorerScriptParser::Switch_h_scnContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Switch_h_scnContext::exitRule)
    .def("accept", &ExplorerScriptParser::Switch_h_scnContext::accept)
;
py::class_<ExplorerScriptParser::Switch_h_randomContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_h_randomContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_randomContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_randomContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_randomContext::getRuleIndex)
    .def("RANDOM", &ExplorerScriptParser::Switch_h_randomContext::RANDOM)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_h_randomContext::OPEN_PAREN)
    .def("integer_like", &ExplorerScriptParser::Switch_h_randomContext::integer_like)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_h_randomContext::CLOSE_PAREN)
    .def("enterRule", &ExplorerScriptParser::Switch_h_randomContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Switch_h_randomContext::exitRule)
    .def("accept", &ExplorerScriptParser::Switch_h_randomContext::accept)
;
py::class_<ExplorerScriptParser::Switch_h_dungeon_modeContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_h_dungeon_modeContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_dungeon_modeContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_dungeon_modeContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_dungeon_modeContext::getRuleIndex)
    .def("DUNGEON_MODE", &ExplorerScriptParser::Switch_h_dungeon_modeContext::DUNGEON_MODE)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_h_dungeon_modeContext::OPEN_PAREN)
    .def("integer_like", &ExplorerScriptParser::Switch_h_dungeon_modeContext::integer_like)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_h_dungeon_modeContext::CLOSE_PAREN)
    .def("enterRule", &ExplorerScriptParser::Switch_h_dungeon_modeContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Switch_h_dungeon_modeContext::exitRule)
    .def("accept", &ExplorerScriptParser::Switch_h_dungeon_modeContext::accept)
;
py::class_<ExplorerScriptParser::Switch_h_sectorContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Switch_h_sectorContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Switch_h_sectorContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Switch_h_sectorContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Switch_h_sectorContext::getRuleIndex)
    .def("SECTOR", &ExplorerScriptParser::Switch_h_sectorContext::SECTOR)
    .def("OPEN_PAREN", &ExplorerScriptParser::Switch_h_sectorContext::OPEN_PAREN)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Switch_h_sectorContext::CLOSE_PAREN)
    .def("enterRule", &ExplorerScriptParser::Switch_h_sectorContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Switch_h_sectorContext::exitRule)
    .def("accept", &ExplorerScriptParser::Switch_h_sectorContext::accept)
;
py::class_<ExplorerScriptParser::Case_headerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Case_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_headerContext::getRuleIndex)
    .def("integer_like", &ExplorerScriptParser::Case_headerContext::integer_like)
    .def("case_h_menu", &ExplorerScriptParser::Case_headerContext::case_h_menu)
    .def("case_h_menu2", &ExplorerScriptParser::Case_headerContext::case_h_menu2)
    .def("case_h_op", &ExplorerScriptParser::Case_headerContext::case_h_op)
    .def("enterRule", &ExplorerScriptParser::Case_headerContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Case_headerContext::exitRule)
    .def("accept", &ExplorerScriptParser::Case_headerContext::accept)
;
py::class_<ExplorerScriptParser::Case_h_menuContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Case_h_menuContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_h_menuContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_h_menuContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_h_menuContext::getRuleIndex)
    .def("MENU", &ExplorerScriptParser::Case_h_menuContext::MENU)
    .def("OPEN_PAREN", &ExplorerScriptParser::Case_h_menuContext::OPEN_PAREN)
    .def("string", &ExplorerScriptParser::Case_h_menuContext::string)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Case_h_menuContext::CLOSE_PAREN)
    .def("enterRule", &ExplorerScriptParser::Case_h_menuContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Case_h_menuContext::exitRule)
    .def("accept", &ExplorerScriptParser::Case_h_menuContext::accept)
;
py::class_<ExplorerScriptParser::Case_h_menu2Context, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Case_h_menu2Context")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_h_menu2Context::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_h_menu2Context::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_h_menu2Context::getRuleIndex)
    .def("MENU2", &ExplorerScriptParser::Case_h_menu2Context::MENU2)
    .def("OPEN_PAREN", &ExplorerScriptParser::Case_h_menu2Context::OPEN_PAREN)
    .def("integer_like", &ExplorerScriptParser::Case_h_menu2Context::integer_like)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Case_h_menu2Context::CLOSE_PAREN)
    .def("enterRule", &ExplorerScriptParser::Case_h_menu2Context::enterRule)
    .def("exitRule", &ExplorerScriptParser::Case_h_menu2Context::exitRule)
    .def("accept", &ExplorerScriptParser::Case_h_menu2Context::accept)
;
py::class_<ExplorerScriptParser::Case_h_opContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Case_h_opContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Case_h_opContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Case_h_opContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Case_h_opContext::getRuleIndex)
    .def("conditional_operator", &ExplorerScriptParser::Case_h_opContext::conditional_operator)
    .def("value_of", &ExplorerScriptParser::Case_h_opContext::value_of)
    .def("integer_like", &ExplorerScriptParser::Case_h_opContext::integer_like)
    .def("enterRule", &ExplorerScriptParser::Case_h_opContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Case_h_opContext::exitRule)
    .def("accept", &ExplorerScriptParser::Case_h_opContext::accept)
;
py::class_<ExplorerScriptParser::Forever_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Forever_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Forever_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Forever_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Forever_blockContext::getRuleIndex)
    .def("FOREVER", &ExplorerScriptParser::Forever_blockContext::FOREVER)
    .def("OPEN_BRACE", &ExplorerScriptParser::Forever_blockContext::OPEN_BRACE)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Forever_blockContext::CLOSE_BRACE)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Forever_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Forever_blockContext::stmt))
    .def("enterRule", &ExplorerScriptParser::Forever_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Forever_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::Forever_blockContext::accept)
;
py::class_<ExplorerScriptParser::For_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::For_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::For_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::For_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::For_blockContext::getRuleIndex)
    .def("FOR", &ExplorerScriptParser::For_blockContext::FOR)
    .def("OPEN_PAREN", &ExplorerScriptParser::For_blockContext::OPEN_PAREN)
    .def("simple_stmt", py::overload_cast<>(&ExplorerScriptParser::For_blockContext::simple_stmt))
    .def("simple_stmt", py::overload_cast<size_t>(&ExplorerScriptParser::For_blockContext::simple_stmt))
    .def("if_header", &ExplorerScriptParser::For_blockContext::if_header)
    .def("CLOSE_PAREN", &ExplorerScriptParser::For_blockContext::CLOSE_PAREN)
    .def("OPEN_BRACE", &ExplorerScriptParser::For_blockContext::OPEN_BRACE)
    .def("CLOSE_BRACE", &ExplorerScriptParser::For_blockContext::CLOSE_BRACE)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::For_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::For_blockContext::stmt))
    .def("enterRule", &ExplorerScriptParser::For_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::For_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::For_blockContext::accept)
;
py::class_<ExplorerScriptParser::While_blockContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::While_blockContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::While_blockContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::While_blockContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::While_blockContext::getRuleIndex)
    .def("WHILE", &ExplorerScriptParser::While_blockContext::WHILE)
    .def("OPEN_PAREN", &ExplorerScriptParser::While_blockContext::OPEN_PAREN)
    .def("if_header", &ExplorerScriptParser::While_blockContext::if_header)
    .def("CLOSE_PAREN", &ExplorerScriptParser::While_blockContext::CLOSE_PAREN)
    .def("OPEN_BRACE", &ExplorerScriptParser::While_blockContext::OPEN_BRACE)
    .def("CLOSE_BRACE", &ExplorerScriptParser::While_blockContext::CLOSE_BRACE)
    .def("NOT", &ExplorerScriptParser::While_blockContext::NOT)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::While_blockContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::While_blockContext::stmt))
    .def("enterRule", &ExplorerScriptParser::While_blockContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::While_blockContext::exitRule)
    .def("accept", &ExplorerScriptParser::While_blockContext::accept)
;
py::class_<ExplorerScriptParser::AssignmentContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::AssignmentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::AssignmentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::AssignmentContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::AssignmentContext::getRuleIndex)
    .def("assignment_regular", &ExplorerScriptParser::AssignmentContext::assignment_regular)
    .def("assignment_clear", &ExplorerScriptParser::AssignmentContext::assignment_clear)
    .def("assignment_initial", &ExplorerScriptParser::AssignmentContext::assignment_initial)
    .def("assignment_reset", &ExplorerScriptParser::AssignmentContext::assignment_reset)
    .def("assignment_adv_log", &ExplorerScriptParser::AssignmentContext::assignment_adv_log)
    .def("assignment_dungeon_mode", &ExplorerScriptParser::AssignmentContext::assignment_dungeon_mode)
    .def("assignment_scn", &ExplorerScriptParser::AssignmentContext::assignment_scn)
    .def("enterRule", &ExplorerScriptParser::AssignmentContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::AssignmentContext::exitRule)
    .def("accept", &ExplorerScriptParser::AssignmentContext::accept)
;
py::class_<ExplorerScriptParser::Assignment_regularContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_regularContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_regularContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_regularContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_regularContext::getRuleIndex)
    .def("integer_like", py::overload_cast<>(&ExplorerScriptParser::Assignment_regularContext::integer_like))
    .def("integer_like", py::overload_cast<size_t>(&ExplorerScriptParser::Assignment_regularContext::integer_like))
    .def("assign_operator", &ExplorerScriptParser::Assignment_regularContext::assign_operator)
    .def("value_of", &ExplorerScriptParser::Assignment_regularContext::value_of)
    .def("OPEN_BRACKET", &ExplorerScriptParser::Assignment_regularContext::OPEN_BRACKET)
    .def("INTEGER", &ExplorerScriptParser::Assignment_regularContext::INTEGER)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::Assignment_regularContext::CLOSE_BRACKET)
    .def("enterRule", &ExplorerScriptParser::Assignment_regularContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Assignment_regularContext::exitRule)
    .def("accept", &ExplorerScriptParser::Assignment_regularContext::accept)
;
py::class_<ExplorerScriptParser::Assignment_clearContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_clearContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_clearContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_clearContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_clearContext::getRuleIndex)
    .def("CLEAR", &ExplorerScriptParser::Assignment_clearContext::CLEAR)
    .def("integer_like", &ExplorerScriptParser::Assignment_clearContext::integer_like)
    .def("enterRule", &ExplorerScriptParser::Assignment_clearContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Assignment_clearContext::exitRule)
    .def("accept", &ExplorerScriptParser::Assignment_clearContext::accept)
;
py::class_<ExplorerScriptParser::Assignment_initialContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_initialContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_initialContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_initialContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_initialContext::getRuleIndex)
    .def("INIT", &ExplorerScriptParser::Assignment_initialContext::INIT)
    .def("integer_like", &ExplorerScriptParser::Assignment_initialContext::integer_like)
    .def("enterRule", &ExplorerScriptParser::Assignment_initialContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Assignment_initialContext::exitRule)
    .def("accept", &ExplorerScriptParser::Assignment_initialContext::accept)
;
py::class_<ExplorerScriptParser::Assignment_resetContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_resetContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_resetContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_resetContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_resetContext::getRuleIndex)
    .def("RESET", &ExplorerScriptParser::Assignment_resetContext::RESET)
    .def("DUNGEON_RESULT", &ExplorerScriptParser::Assignment_resetContext::DUNGEON_RESULT)
    .def("scn_var", &ExplorerScriptParser::Assignment_resetContext::scn_var)
    .def("enterRule", &ExplorerScriptParser::Assignment_resetContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Assignment_resetContext::exitRule)
    .def("accept", &ExplorerScriptParser::Assignment_resetContext::accept)
;
py::class_<ExplorerScriptParser::Assignment_adv_logContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_adv_logContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_adv_logContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_adv_logContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_adv_logContext::getRuleIndex)
    .def("ADVENTURE_LOG", &ExplorerScriptParser::Assignment_adv_logContext::ADVENTURE_LOG)
    .def("ASSIGN", &ExplorerScriptParser::Assignment_adv_logContext::ASSIGN)
    .def("integer_like", &ExplorerScriptParser::Assignment_adv_logContext::integer_like)
    .def("enterRule", &ExplorerScriptParser::Assignment_adv_logContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Assignment_adv_logContext::exitRule)
    .def("accept", &ExplorerScriptParser::Assignment_adv_logContext::accept)
;
py::class_<ExplorerScriptParser::Assignment_dungeon_modeContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_dungeon_modeContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_dungeon_modeContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_dungeon_modeContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_dungeon_modeContext::getRuleIndex)
    .def("DUNGEON_MODE", &ExplorerScriptParser::Assignment_dungeon_modeContext::DUNGEON_MODE)
    .def("OPEN_PAREN", &ExplorerScriptParser::Assignment_dungeon_modeContext::OPEN_PAREN)
    .def("integer_like", py::overload_cast<>(&ExplorerScriptParser::Assignment_dungeon_modeContext::integer_like))
    .def("integer_like", py::overload_cast<size_t>(&ExplorerScriptParser::Assignment_dungeon_modeContext::integer_like))
    .def("CLOSE_PAREN", &ExplorerScriptParser::Assignment_dungeon_modeContext::CLOSE_PAREN)
    .def("ASSIGN", &ExplorerScriptParser::Assignment_dungeon_modeContext::ASSIGN)
    .def("enterRule", &ExplorerScriptParser::Assignment_dungeon_modeContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Assignment_dungeon_modeContext::exitRule)
    .def("accept", &ExplorerScriptParser::Assignment_dungeon_modeContext::accept)
;
py::class_<ExplorerScriptParser::Assignment_scnContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assignment_scnContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assignment_scnContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assignment_scnContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assignment_scnContext::getRuleIndex)
    .def("integer_like", &ExplorerScriptParser::Assignment_scnContext::integer_like)
    .def("ASSIGN", &ExplorerScriptParser::Assignment_scnContext::ASSIGN)
    .def("SCN", &ExplorerScriptParser::Assignment_scnContext::SCN)
    .def("OPEN_BRACKET", &ExplorerScriptParser::Assignment_scnContext::OPEN_BRACKET)
    .def("INTEGER", py::overload_cast<>(&ExplorerScriptParser::Assignment_scnContext::INTEGER))
    .def("INTEGER", py::overload_cast<size_t>(&ExplorerScriptParser::Assignment_scnContext::INTEGER))
    .def("COMMA", &ExplorerScriptParser::Assignment_scnContext::COMMA)
    .def("CLOSE_BRACKET", &ExplorerScriptParser::Assignment_scnContext::CLOSE_BRACKET)
    .def("enterRule", &ExplorerScriptParser::Assignment_scnContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Assignment_scnContext::exitRule)
    .def("accept", &ExplorerScriptParser::Assignment_scnContext::accept)
;
py::class_<ExplorerScriptParser::Value_ofContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Value_ofContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Value_ofContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Value_ofContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Value_ofContext::getRuleIndex)
    .def("VALUE", &ExplorerScriptParser::Value_ofContext::VALUE)
    .def("OPEN_PAREN", &ExplorerScriptParser::Value_ofContext::OPEN_PAREN)
    .def("integer_like", &ExplorerScriptParser::Value_ofContext::integer_like)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Value_ofContext::CLOSE_PAREN)
    .def("enterRule", &ExplorerScriptParser::Value_ofContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Value_ofContext::exitRule)
    .def("accept", &ExplorerScriptParser::Value_ofContext::accept)
;
py::class_<ExplorerScriptParser::Scn_varContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Scn_varContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Scn_varContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Scn_varContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Scn_varContext::getRuleIndex)
    .def("SCN", &ExplorerScriptParser::Scn_varContext::SCN)
    .def("OPEN_PAREN", &ExplorerScriptParser::Scn_varContext::OPEN_PAREN)
    .def("integer_like", &ExplorerScriptParser::Scn_varContext::integer_like)
    .def("CLOSE_PAREN", &ExplorerScriptParser::Scn_varContext::CLOSE_PAREN)
    .def("enterRule", &ExplorerScriptParser::Scn_varContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Scn_varContext::exitRule)
    .def("accept", &ExplorerScriptParser::Scn_varContext::accept)
;
py::class_<ExplorerScriptParser::Conditional_operatorContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Conditional_operatorContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Conditional_operatorContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Conditional_operatorContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Conditional_operatorContext::getRuleIndex)
    .def("OP_FALSE", &ExplorerScriptParser::Conditional_operatorContext::OP_FALSE)
    .def("OP_TRUE", &ExplorerScriptParser::Conditional_operatorContext::OP_TRUE)
    .def("OP_EQ", &ExplorerScriptParser::Conditional_operatorContext::OP_EQ)
    .def("OP_GE", &ExplorerScriptParser::Conditional_operatorContext::OP_GE)
    .def("OP_LE", &ExplorerScriptParser::Conditional_operatorContext::OP_LE)
    .def("OPEN_SHARP", &ExplorerScriptParser::Conditional_operatorContext::OPEN_SHARP)
    .def("CLOSE_SHARP", &ExplorerScriptParser::Conditional_operatorContext::CLOSE_SHARP)
    .def("OP_NEQ", &ExplorerScriptParser::Conditional_operatorContext::OP_NEQ)
    .def("OP_AND", &ExplorerScriptParser::Conditional_operatorContext::OP_AND)
    .def("OP_XOR", &ExplorerScriptParser::Conditional_operatorContext::OP_XOR)
    .def("OP_BICH", &ExplorerScriptParser::Conditional_operatorContext::OP_BICH)
    .def("enterRule", &ExplorerScriptParser::Conditional_operatorContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Conditional_operatorContext::exitRule)
    .def("accept", &ExplorerScriptParser::Conditional_operatorContext::accept)
;
py::class_<ExplorerScriptParser::Assign_operatorContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Assign_operatorContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Assign_operatorContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Assign_operatorContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Assign_operatorContext::getRuleIndex)
    .def("OP_MINUS", &ExplorerScriptParser::Assign_operatorContext::OP_MINUS)
    .def("OP_PLUS", &ExplorerScriptParser::Assign_operatorContext::OP_PLUS)
    .def("OP_MULTIPLY", &ExplorerScriptParser::Assign_operatorContext::OP_MULTIPLY)
    .def("OP_DIVIDE", &ExplorerScriptParser::Assign_operatorContext::OP_DIVIDE)
    .def("ASSIGN", &ExplorerScriptParser::Assign_operatorContext::ASSIGN)
    .def("enterRule", &ExplorerScriptParser::Assign_operatorContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Assign_operatorContext::exitRule)
    .def("accept", &ExplorerScriptParser::Assign_operatorContext::accept)
;
py::class_<ExplorerScriptParser::FuncdefContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::FuncdefContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::FuncdefContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::FuncdefContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::FuncdefContext::getRuleIndex)
    .def("coro_def", &ExplorerScriptParser::FuncdefContext::coro_def)
    .def("simple_def", &ExplorerScriptParser::FuncdefContext::simple_def)
    .def("for_target_def", &ExplorerScriptParser::FuncdefContext::for_target_def)
    .def("enterRule", &ExplorerScriptParser::FuncdefContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::FuncdefContext::exitRule)
    .def("accept", &ExplorerScriptParser::FuncdefContext::accept)
;
py::class_<ExplorerScriptParser::Simple_defContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Simple_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Simple_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Simple_defContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Simple_defContext::getRuleIndex)
    .def("DEF", &ExplorerScriptParser::Simple_defContext::DEF)
    .def("INTEGER", &ExplorerScriptParser::Simple_defContext::INTEGER)
    .def("func_suite", &ExplorerScriptParser::Simple_defContext::func_suite)
    .def("enterRule", &ExplorerScriptParser::Simple_defContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Simple_defContext::exitRule)
    .def("accept", &ExplorerScriptParser::Simple_defContext::accept)
;
py::class_<ExplorerScriptParser::Coro_defContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Coro_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Coro_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Coro_defContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Coro_defContext::getRuleIndex)
    .def("CORO", &ExplorerScriptParser::Coro_defContext::CORO)
    .def("IDENTIFIER", &ExplorerScriptParser::Coro_defContext::IDENTIFIER)
    .def("func_suite", &ExplorerScriptParser::Coro_defContext::func_suite)
    .def("enterRule", &ExplorerScriptParser::Coro_defContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Coro_defContext::exitRule)
    .def("accept", &ExplorerScriptParser::Coro_defContext::accept)
;
py::class_<ExplorerScriptParser::For_target_defContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::For_target_defContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::For_target_defContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::For_target_defContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::For_target_defContext::getRuleIndex)
    .def("DEF", &ExplorerScriptParser::For_target_defContext::DEF)
    .def("INTEGER", &ExplorerScriptParser::For_target_defContext::INTEGER)
    .def("for_target_def_target", &ExplorerScriptParser::For_target_defContext::for_target_def_target)
    .def("integer_like", &ExplorerScriptParser::For_target_defContext::integer_like)
    .def("func_suite", &ExplorerScriptParser::For_target_defContext::func_suite)
    .def("OPEN_PAREN", &ExplorerScriptParser::For_target_defContext::OPEN_PAREN)
    .def("CLOSE_PAREN", &ExplorerScriptParser::For_target_defContext::CLOSE_PAREN)
    .def("enterRule", &ExplorerScriptParser::For_target_defContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::For_target_defContext::exitRule)
    .def("accept", &ExplorerScriptParser::For_target_defContext::accept)
;
py::class_<ExplorerScriptParser::Integer_likeContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Integer_likeContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Integer_likeContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Integer_likeContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Integer_likeContext::getRuleIndex)
    .def("DECIMAL", &ExplorerScriptParser::Integer_likeContext::DECIMAL)
    .def("INTEGER", &ExplorerScriptParser::Integer_likeContext::INTEGER)
    .def("IDENTIFIER", &ExplorerScriptParser::Integer_likeContext::IDENTIFIER)
    .def("VARIABLE", &ExplorerScriptParser::Integer_likeContext::VARIABLE)
    .def("enterRule", &ExplorerScriptParser::Integer_likeContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Integer_likeContext::exitRule)
    .def("accept", &ExplorerScriptParser::Integer_likeContext::accept)
;
py::class_<ExplorerScriptParser::OperationContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::OperationContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::OperationContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::OperationContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::OperationContext::getRuleIndex)
    .def("IDENTIFIER", &ExplorerScriptParser::OperationContext::IDENTIFIER)
    .def("OPEN_PAREN", &ExplorerScriptParser::OperationContext::OPEN_PAREN)
    .def("CLOSE_PAREN", &ExplorerScriptParser::OperationContext::CLOSE_PAREN)
    .def("inline_ctx", &ExplorerScriptParser::OperationContext::inline_ctx)
    .def("arglist", &ExplorerScriptParser::OperationContext::arglist)
    .def("enterRule", &ExplorerScriptParser::OperationContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::OperationContext::exitRule)
    .def("accept", &ExplorerScriptParser::OperationContext::accept)
;
py::class_<ExplorerScriptParser::Inline_ctxContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Inline_ctxContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Inline_ctxContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Inline_ctxContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Inline_ctxContext::getRuleIndex)
    .def("OPEN_SHARP", &ExplorerScriptParser::Inline_ctxContext::OPEN_SHARP)
    .def("ctx_header", &ExplorerScriptParser::Inline_ctxContext::ctx_header)
    .def("CLOSE_SHARP", &ExplorerScriptParser::Inline_ctxContext::CLOSE_SHARP)
    .def("enterRule", &ExplorerScriptParser::Inline_ctxContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Inline_ctxContext::exitRule)
    .def("accept", &ExplorerScriptParser::Inline_ctxContext::accept)
;
py::class_<ExplorerScriptParser::Func_suiteContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Func_suiteContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Func_suiteContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Func_suiteContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Func_suiteContext::getRuleIndex)
    .def("OPEN_BRACE", &ExplorerScriptParser::Func_suiteContext::OPEN_BRACE)
    .def("CLOSE_BRACE", &ExplorerScriptParser::Func_suiteContext::CLOSE_BRACE)
    .def("func_alias", &ExplorerScriptParser::Func_suiteContext::func_alias)
    .def("stmt", py::overload_cast<>(&ExplorerScriptParser::Func_suiteContext::stmt))
    .def("stmt", py::overload_cast<size_t>(&ExplorerScriptParser::Func_suiteContext::stmt))
    .def("enterRule", &ExplorerScriptParser::Func_suiteContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Func_suiteContext::exitRule)
    .def("accept", &ExplorerScriptParser::Func_suiteContext::accept)
;
py::class_<ExplorerScriptParser::Func_aliasContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Func_aliasContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Func_aliasContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Func_aliasContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Func_aliasContext::getRuleIndex)
    .def("ALIAS", &ExplorerScriptParser::Func_aliasContext::ALIAS)
    .def("PREVIOUS", &ExplorerScriptParser::Func_aliasContext::PREVIOUS)
    .def("enterRule", &ExplorerScriptParser::Func_aliasContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Func_aliasContext::exitRule)
    .def("accept", &ExplorerScriptParser::Func_aliasContext::accept)
;
py::class_<ExplorerScriptParser::ArglistContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::ArglistContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::ArglistContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::ArglistContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::ArglistContext::getRuleIndex)
    .def("pos_argument", py::overload_cast<>(&ExplorerScriptParser::ArglistContext::pos_argument))
    .def("pos_argument", py::overload_cast<size_t>(&ExplorerScriptParser::ArglistContext::pos_argument))
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::ArglistContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::ArglistContext::COMMA))
    .def("enterRule", &ExplorerScriptParser::ArglistContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::ArglistContext::exitRule)
    .def("accept", &ExplorerScriptParser::ArglistContext::accept)
;
py::class_<ExplorerScriptParser::Pos_argumentContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Pos_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Pos_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Pos_argumentContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Pos_argumentContext::getRuleIndex)
    .def("integer_like", &ExplorerScriptParser::Pos_argumentContext::integer_like)
    .def("string", &ExplorerScriptParser::Pos_argumentContext::string)
    .def("position_marker", &ExplorerScriptParser::Pos_argumentContext::position_marker)
    .def("enterRule", &ExplorerScriptParser::Pos_argumentContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Pos_argumentContext::exitRule)
    .def("accept", &ExplorerScriptParser::Pos_argumentContext::accept)
;
py::class_<ExplorerScriptParser::Position_markerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Position_markerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Position_markerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Position_markerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Position_markerContext::getRuleIndex)
    .def("POSITION", &ExplorerScriptParser::Position_markerContext::POSITION)
    .def("OPEN_SHARP", &ExplorerScriptParser::Position_markerContext::OPEN_SHARP)
    .def("STRING_LITERAL", &ExplorerScriptParser::Position_markerContext::STRING_LITERAL)
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::Position_markerContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::Position_markerContext::COMMA))
    .def("position_marker_arg", py::overload_cast<>(&ExplorerScriptParser::Position_markerContext::position_marker_arg))
    .def("position_marker_arg", py::overload_cast<size_t>(&ExplorerScriptParser::Position_markerContext::position_marker_arg))
    .def("CLOSE_SHARP", &ExplorerScriptParser::Position_markerContext::CLOSE_SHARP)
    .def("enterRule", &ExplorerScriptParser::Position_markerContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Position_markerContext::exitRule)
    .def("accept", &ExplorerScriptParser::Position_markerContext::accept)
;
py::class_<ExplorerScriptParser::Position_marker_argContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Position_marker_argContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Position_marker_argContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Position_marker_argContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Position_marker_argContext::getRuleIndex)
    .def("INTEGER", &ExplorerScriptParser::Position_marker_argContext::INTEGER)
    .def("DECIMAL", &ExplorerScriptParser::Position_marker_argContext::DECIMAL)
    .def("enterRule", &ExplorerScriptParser::Position_marker_argContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Position_marker_argContext::exitRule)
    .def("accept", &ExplorerScriptParser::Position_marker_argContext::accept)
;
py::class_<ExplorerScriptParser::LabelContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::LabelContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::LabelContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::LabelContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::LabelContext::getRuleIndex)
    .def("IDENTIFIER", &ExplorerScriptParser::LabelContext::IDENTIFIER)
    .def("PARAGRAPH", &ExplorerScriptParser::LabelContext::PARAGRAPH)
    .def("AT", &ExplorerScriptParser::LabelContext::AT)
    .def("enterRule", &ExplorerScriptParser::LabelContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::LabelContext::exitRule)
    .def("accept", &ExplorerScriptParser::LabelContext::accept)
;
py::class_<ExplorerScriptParser::StringContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::StringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::StringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::StringContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::StringContext::getRuleIndex)
    .def("string_value", &ExplorerScriptParser::StringContext::string_value)
    .def("lang_string", &ExplorerScriptParser::StringContext::lang_string)
    .def("enterRule", &ExplorerScriptParser::StringContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::StringContext::exitRule)
    .def("accept", &ExplorerScriptParser::StringContext::accept)
;
py::class_<ExplorerScriptParser::Lang_stringContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Lang_stringContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Lang_stringContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Lang_stringContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Lang_stringContext::getRuleIndex)
    .def("OPEN_BRACE", &ExplorerScriptParser::Lang_stringContext::OPEN_BRACE)
    .def("lang_string_argument", py::overload_cast<>(&ExplorerScriptParser::Lang_stringContext::lang_string_argument))
    .def("lang_string_argument", py::overload_cast<size_t>(&ExplorerScriptParser::Lang_stringContext::lang_string_argument))
    .def("CLOSE_BRACE", &ExplorerScriptParser::Lang_stringContext::CLOSE_BRACE)
    .def("COMMA", py::overload_cast<>(&ExplorerScriptParser::Lang_stringContext::COMMA))
    .def("COMMA", py::overload_cast<size_t>(&ExplorerScriptParser::Lang_stringContext::COMMA))
    .def("enterRule", &ExplorerScriptParser::Lang_stringContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Lang_stringContext::exitRule)
    .def("accept", &ExplorerScriptParser::Lang_stringContext::accept)
;
py::class_<ExplorerScriptParser::Lang_string_argumentContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Lang_string_argumentContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Lang_string_argumentContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Lang_string_argumentContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Lang_string_argumentContext::getRuleIndex)
    .def("IDENTIFIER", &ExplorerScriptParser::Lang_string_argumentContext::IDENTIFIER)
    .def("ASSIGN", &ExplorerScriptParser::Lang_string_argumentContext::ASSIGN)
    .def("string_value", &ExplorerScriptParser::Lang_string_argumentContext::string_value)
    .def("enterRule", &ExplorerScriptParser::Lang_string_argumentContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Lang_string_argumentContext::exitRule)
    .def("accept", &ExplorerScriptParser::Lang_string_argumentContext::accept)
;
py::class_<ExplorerScriptParser::String_valueContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::String_valueContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::String_valueContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::String_valueContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::String_valueContext::getRuleIndex)
    .def("MULTILINE_STRING_LITERAL", &ExplorerScriptParser::String_valueContext::MULTILINE_STRING_LITERAL)
    .def("STRING_LITERAL", &ExplorerScriptParser::String_valueContext::STRING_LITERAL)
    .def("enterRule", &ExplorerScriptParser::String_valueContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::String_valueContext::exitRule)
    .def("accept", &ExplorerScriptParser::String_valueContext::accept)
;
py::class_<ExplorerScriptParser::Ctx_headerContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::Ctx_headerContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::Ctx_headerContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::Ctx_headerContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::Ctx_headerContext::getRuleIndex)
    .def("IDENTIFIER", &ExplorerScriptParser::Ctx_headerContext::IDENTIFIER)
    .def("integer_like", &ExplorerScriptParser::Ctx_headerContext::integer_like)
    .def("enterRule", &ExplorerScriptParser::Ctx_headerContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::Ctx_headerContext::exitRule)
    .def("accept", &ExplorerScriptParser::Ctx_headerContext::accept)
;
py::class_<ExplorerScriptParser::For_target_def_targetContext, antlr4::ParserRuleContext>(m, "ExplorerScriptParser::For_target_def_targetContext")
    .def(py::init<antlr4::ParserRuleContext*, size_t>())
    .def("__str__", py::overload_cast<>(&ExplorerScriptParser::For_target_def_targetContext::toString))
    .def("to_string_tree", py::overload_cast<bool>(&ExplorerScriptParser::For_target_def_targetContext::toStringTree))
    .def("getRuleIndex", &ExplorerScriptParser::For_target_def_targetContext::getRuleIndex)
    .def("FOR", &ExplorerScriptParser::For_target_def_targetContext::FOR)
    .def("IDENTIFIER", &ExplorerScriptParser::For_target_def_targetContext::IDENTIFIER)
    .def("FOR_TARGET", &ExplorerScriptParser::For_target_def_targetContext::FOR_TARGET)
    .def("enterRule", &ExplorerScriptParser::For_target_def_targetContext::enterRule)
    .def("exitRule", &ExplorerScriptParser::For_target_def_targetContext::exitRule)
    .def("accept", &ExplorerScriptParser::For_target_def_targetContext::accept)
;
py::class_<ExplorerScriptVisitor, PyExplorerScriptVisitor>(m, "ExplorerScriptVisitor")
    .def(py::init<>())
    .def("visitChildren", [](ExplorerScriptVisitor& self, antlr4::tree::ParseTree* node) {
        return std::any_cast<pybind11::object>(self.visitChildren(node));
    })
    .def("defaultResult", [](ExplorerScriptVisitor& self) {
        return std::any_cast<pybind11::object>(self.defaultResult());
    })
    .def("visitStart", &ExplorerScriptVisitor::visitStart)
    .def("visitImport_stmt", &ExplorerScriptVisitor::visitImport_stmt)
    .def("visitMacrodef", &ExplorerScriptVisitor::visitMacrodef)
    .def("visitStmt", &ExplorerScriptVisitor::visitStmt)
    .def("visitSimple_stmt", &ExplorerScriptVisitor::visitSimple_stmt)
    .def("visitCntrl_stmt", &ExplorerScriptVisitor::visitCntrl_stmt)
    .def("visitJump", &ExplorerScriptVisitor::visitJump)
    .def("visitCall", &ExplorerScriptVisitor::visitCall)
    .def("visitMacro_call", &ExplorerScriptVisitor::visitMacro_call)
    .def("visitCtx_block", &ExplorerScriptVisitor::visitCtx_block)
    .def("visitIf_block", &ExplorerScriptVisitor::visitIf_block)
    .def("visitElseif_block", &ExplorerScriptVisitor::visitElseif_block)
    .def("visitElse_block", &ExplorerScriptVisitor::visitElse_block)
    .def("visitIf_header", &ExplorerScriptVisitor::visitIf_header)
    .def("visitIf_h_negatable", &ExplorerScriptVisitor::visitIf_h_negatable)
    .def("visitIf_h_op", &ExplorerScriptVisitor::visitIf_h_op)
    .def("visitIf_h_bit", &ExplorerScriptVisitor::visitIf_h_bit)
    .def("visitIf_h_scn", &ExplorerScriptVisitor::visitIf_h_scn)
    .def("visitSwitch_block", &ExplorerScriptVisitor::visitSwitch_block)
    .def("visitMessage_switch_block", &ExplorerScriptVisitor::visitMessage_switch_block)
    .def("visitSingle_case_block", &ExplorerScriptVisitor::visitSingle_case_block)
    .def("visitDefault", &ExplorerScriptVisitor::visitDefault)
    .def("visitSwitch_header", &ExplorerScriptVisitor::visitSwitch_header)
    .def("visitSwitch_h_scn", &ExplorerScriptVisitor::visitSwitch_h_scn)
    .def("visitSwitch_h_random", &ExplorerScriptVisitor::visitSwitch_h_random)
    .def("visitSwitch_h_dungeon_mode", &ExplorerScriptVisitor::visitSwitch_h_dungeon_mode)
    .def("visitSwitch_h_sector", &ExplorerScriptVisitor::visitSwitch_h_sector)
    .def("visitCase_header", &ExplorerScriptVisitor::visitCase_header)
    .def("visitCase_h_menu", &ExplorerScriptVisitor::visitCase_h_menu)
    .def("visitCase_h_menu2", &ExplorerScriptVisitor::visitCase_h_menu2)
    .def("visitCase_h_op", &ExplorerScriptVisitor::visitCase_h_op)
    .def("visitForever_block", &ExplorerScriptVisitor::visitForever_block)
    .def("visitFor_block", &ExplorerScriptVisitor::visitFor_block)
    .def("visitWhile_block", &ExplorerScriptVisitor::visitWhile_block)
    .def("visitAssignment", &ExplorerScriptVisitor::visitAssignment)
    .def("visitAssignment_regular", &ExplorerScriptVisitor::visitAssignment_regular)
    .def("visitAssignment_clear", &ExplorerScriptVisitor::visitAssignment_clear)
    .def("visitAssignment_initial", &ExplorerScriptVisitor::visitAssignment_initial)
    .def("visitAssignment_reset", &ExplorerScriptVisitor::visitAssignment_reset)
    .def("visitAssignment_adv_log", &ExplorerScriptVisitor::visitAssignment_adv_log)
    .def("visitAssignment_dungeon_mode", &ExplorerScriptVisitor::visitAssignment_dungeon_mode)
    .def("visitAssignment_scn", &ExplorerScriptVisitor::visitAssignment_scn)
    .def("visitValue_of", &ExplorerScriptVisitor::visitValue_of)
    .def("visitScn_var", &ExplorerScriptVisitor::visitScn_var)
    .def("visitConditional_operator", &ExplorerScriptVisitor::visitConditional_operator)
    .def("visitAssign_operator", &ExplorerScriptVisitor::visitAssign_operator)
    .def("visitFuncdef", &ExplorerScriptVisitor::visitFuncdef)
    .def("visitSimple_def", &ExplorerScriptVisitor::visitSimple_def)
    .def("visitCoro_def", &ExplorerScriptVisitor::visitCoro_def)
    .def("visitFor_target_def", &ExplorerScriptVisitor::visitFor_target_def)
    .def("visitInteger_like", &ExplorerScriptVisitor::visitInteger_like)
    .def("visitOperation", &ExplorerScriptVisitor::visitOperation)
    .def("visitInline_ctx", &ExplorerScriptVisitor::visitInline_ctx)
    .def("visitFunc_suite", &ExplorerScriptVisitor::visitFunc_suite)
    .def("visitFunc_alias", &ExplorerScriptVisitor::visitFunc_alias)
    .def("visitArglist", &ExplorerScriptVisitor::visitArglist)
    .def("visitPos_argument", &ExplorerScriptVisitor::visitPos_argument)
    .def("visitPosition_marker", &ExplorerScriptVisitor::visitPosition_marker)
    .def("visitPosition_marker_arg", &ExplorerScriptVisitor::visitPosition_marker_arg)
    .def("visitLabel", &ExplorerScriptVisitor::visitLabel)
    .def("visitString", &ExplorerScriptVisitor::visitString)
    .def("visitLang_string", &ExplorerScriptVisitor::visitLang_string)
    .def("visitLang_string_argument", &ExplorerScriptVisitor::visitLang_string_argument)
    .def("visitString_value", &ExplorerScriptVisitor::visitString_value)
    .def("visitCtx_header", &ExplorerScriptVisitor::visitCtx_header)
    .def("visitFor_target_def_target", &ExplorerScriptVisitor::visitFor_target_def_target)
;}