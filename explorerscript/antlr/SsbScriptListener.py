# Generated from SsbScript.g4 by ANTLR 4.13.0
from antlr4 import *
if "." in __name__:
    from .SsbScriptParser import SsbScriptParser
else:
    from SsbScriptParser import SsbScriptParser

# This class defines a complete listener for a parse tree produced by SsbScriptParser.
class SsbScriptListener(ParseTreeListener):

    # Enter a parse tree produced by SsbScriptParser#pos_argument.
    def enterPos_argument(self, ctx:SsbScriptParser.Pos_argumentContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#pos_argument.
    def exitPos_argument(self, ctx:SsbScriptParser.Pos_argumentContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#jump_marker.
    def enterJump_marker(self, ctx:SsbScriptParser.Jump_markerContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#jump_marker.
    def exitJump_marker(self, ctx:SsbScriptParser.Jump_markerContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#start.
    def enterStart(self, ctx:SsbScriptParser.StartContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#start.
    def exitStart(self, ctx:SsbScriptParser.StartContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#funcdef.
    def enterFuncdef(self, ctx:SsbScriptParser.FuncdefContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#funcdef.
    def exitFuncdef(self, ctx:SsbScriptParser.FuncdefContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#simple_def.
    def enterSimple_def(self, ctx:SsbScriptParser.Simple_defContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#simple_def.
    def exitSimple_def(self, ctx:SsbScriptParser.Simple_defContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#coro_def.
    def enterCoro_def(self, ctx:SsbScriptParser.Coro_defContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#coro_def.
    def exitCoro_def(self, ctx:SsbScriptParser.Coro_defContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#for_target_def.
    def enterFor_target_def(self, ctx:SsbScriptParser.For_target_defContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#for_target_def.
    def exitFor_target_def(self, ctx:SsbScriptParser.For_target_defContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#primitive.
    def enterPrimitive(self, ctx:SsbScriptParser.PrimitiveContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#primitive.
    def exitPrimitive(self, ctx:SsbScriptParser.PrimitiveContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#stmt.
    def enterStmt(self, ctx:SsbScriptParser.StmtContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#stmt.
    def exitStmt(self, ctx:SsbScriptParser.StmtContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#operation.
    def enterOperation(self, ctx:SsbScriptParser.OperationContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#operation.
    def exitOperation(self, ctx:SsbScriptParser.OperationContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#inline_ctx.
    def enterInline_ctx(self, ctx:SsbScriptParser.Inline_ctxContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#inline_ctx.
    def exitInline_ctx(self, ctx:SsbScriptParser.Inline_ctxContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#func_suite.
    def enterFunc_suite(self, ctx:SsbScriptParser.Func_suiteContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#func_suite.
    def exitFunc_suite(self, ctx:SsbScriptParser.Func_suiteContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#func_alias.
    def enterFunc_alias(self, ctx:SsbScriptParser.Func_aliasContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#func_alias.
    def exitFunc_alias(self, ctx:SsbScriptParser.Func_aliasContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#arglist.
    def enterArglist(self, ctx:SsbScriptParser.ArglistContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#arglist.
    def exitArglist(self, ctx:SsbScriptParser.ArglistContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#position_marker.
    def enterPosition_marker(self, ctx:SsbScriptParser.Position_markerContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#position_marker.
    def exitPosition_marker(self, ctx:SsbScriptParser.Position_markerContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#position_marker_arg.
    def enterPosition_marker_arg(self, ctx:SsbScriptParser.Position_marker_argContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#position_marker_arg.
    def exitPosition_marker_arg(self, ctx:SsbScriptParser.Position_marker_argContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#label.
    def enterLabel(self, ctx:SsbScriptParser.LabelContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#label.
    def exitLabel(self, ctx:SsbScriptParser.LabelContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#string.
    def enterString(self, ctx:SsbScriptParser.StringContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#string.
    def exitString(self, ctx:SsbScriptParser.StringContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#lang_string.
    def enterLang_string(self, ctx:SsbScriptParser.Lang_stringContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#lang_string.
    def exitLang_string(self, ctx:SsbScriptParser.Lang_stringContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#lang_string_argument.
    def enterLang_string_argument(self, ctx:SsbScriptParser.Lang_string_argumentContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#lang_string_argument.
    def exitLang_string_argument(self, ctx:SsbScriptParser.Lang_string_argumentContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#string_value.
    def enterString_value(self, ctx:SsbScriptParser.String_valueContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#string_value.
    def exitString_value(self, ctx:SsbScriptParser.String_valueContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#ctx_header.
    def enterCtx_header(self, ctx:SsbScriptParser.Ctx_headerContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#ctx_header.
    def exitCtx_header(self, ctx:SsbScriptParser.Ctx_headerContext):
        pass


    # Enter a parse tree produced by SsbScriptParser#for_target_def_target.
    def enterFor_target_def_target(self, ctx:SsbScriptParser.For_target_def_targetContext):
        pass

    # Exit a parse tree produced by SsbScriptParser#for_target_def_target.
    def exitFor_target_def_target(self, ctx:SsbScriptParser.For_target_def_targetContext):
        pass



del SsbScriptParser