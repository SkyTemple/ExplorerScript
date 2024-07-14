import explorerscript_parser
import time

with open("_unionall.exps", "r") as f:
    text = f.read()

# measure time 

start = time.time()
parser = explorerscript_parser.ParserWrapper(text)

class MyVisitor(explorerscript_parser.ExplorerScriptVisitor):
    def __init__(self):
        super().__init__()

    def visitOperation(self, ctx):
        print(f"Visiting operation: {ctx.IDENTIFIER()}")
        pass

    def visitStart(self, ctx):
        return self.visitChildren(ctx)

    def visitFuncdef(self, ctx):
        return self.visitChildren(ctx)

    def visitCoro_def(self, ctx):
        return self.visitChildren(ctx)

    def visitFunc_suite(self, ctx):
        return self.visitChildren(ctx)

    def visitStmt(self, ctx):
        return self.visitChildren(ctx)
    
    def visitSimple_stmt(self, ctx):
        return self.visitChildren(ctx)

    def visitCntrl_stmt(self, ctx):
        return self.visitChildren(ctx)

    def visitCtx_block(self, ctx):
        return self.visitChildren(ctx)
    
    def visitCtx_header(self, ctx):
        return self.visitChildren(ctx)

    def visitIf_block(self, ctx):
        return self.visitChildren(ctx)

    def visitInteger_like(self, ctx):
        return self.visitChildren(ctx)
    
    def visitIf_header(self, ctx):
        return self.visitChildren(ctx)

    def visitIf_h_op(self, ctx):
        return self.visitChildren(ctx)

    def visitConditional_operator(self, ctx):
        return self.visitChildren(ctx)

    def visitLabel(self, ctx):
        return self.visitChildren(ctx)

    def visitElse_block(self, ctx):
        return self.visitChildren(ctx)

    def visitSwitch_block(self, ctx):
        return self.visitChildren(ctx)

    def visitSwitch_header(self, ctx):
        return self.visitChildren(ctx)

    def visitSwitch_h_scn(self, ctx):
        return self.visitChildren(ctx)

    def visitScn_var(self, ctx):
        return self.visitChildren(ctx)

    def visitSingle_case_block(self, ctx):
        return self.visitChildren(ctx)

    def visitCase_header(self, ctx):
        return self.visitChildren(ctx)

    def visitCase_h_op(self, ctx):
        return self.visitChildren(ctx)

    def visitDefault(self, ctx):
        return self.visitChildren(ctx)

    def visitJump(self, ctx):
        return self.visitChildren(ctx)

    def visitIf_h_scn(self, ctx):
        return self.visitChildren(ctx)

    def visitElseif_block(self, ctx):
        return self.visitChildren(ctx)

    def visitIf_h_bit(self, ctx):
        return self.visitChildren(ctx)

    def visitForever_block(self, ctx):
        return self.visitChildren(ctx)

    def visitAssignment(self, ctx):
        return self.visitChildren(ctx)

    def visitAssignment_reset(self, ctx):
        return self.visitChildren(ctx)

    def visitAssignment_regular(self, ctx):
        return self.visitChildren(ctx)

    def visitAssign_operator(self, ctx):
        return self.visitChildren(ctx)

    def visitCase_h_menu(self, ctx):
        return self.visitChildren(ctx)

    def visitString(self, ctx):
        return self.visitChildren(ctx)

    def visitLang_string(self, ctx):
        return self.visitChildren(ctx)
    
    def visitLang_string_argument(self, ctx):
        return self.visitChildren(ctx)
    
    def visitString_value(self, ctx):
        return self.visitChildren(ctx)
    
    def visitFunc_alias(self, ctx):
        return self.visitChildren(ctx)
    
    def visitValue_of(self, ctx):
        return self.visitChildren(ctx)
    
    def visitAssignment_scn(self, ctx):
        return self.visitChildren(ctx)
    
    def visitIf_h_negatable(self, ctx):
        return self.visitChildren(ctx)
    
    def visitAssignment_clear(self, ctx):
        return self.visitChildren(ctx)
    
    def visitAssignment_dungeon_mode(self, ctx):
        return self.visitChildren(ctx)
    
    def visitSwitch_h_random(self, ctx):
        return self.visitChildren(ctx)
    
    def visitAssignment_adv_log(self, ctx):
        return self.visitChildren(ctx)
    
    def visitSwitch_h_dungeon_mode(self, ctx):
        return self.visitChildren(ctx)
        
    def defaultResult(self):
        return []
    
    def aggregrateResult(self, aggregate, nextResult):
        return aggregate.append(nextResult)

parser.traverse(MyVisitor())

# end measure time
end = time.time()
print("time: ", (end - start))