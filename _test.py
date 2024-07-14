import explorerscript_parser
import time

with open("_unionall.exps", "r") as f:
    text = f.read()

start = time.time()
parser = explorerscript_parser.ParserWrapper(text)

class BaseExplorerScriptVisitor(explorerscript_parser.ExplorerScriptVisitor):
    def __init__(self):
        super().__init__()
        self._auto_generate_methods()

    def _auto_generate_methods(self):
        for method_name in dir(self):
            if method_name.startswith("visit") and method_name != "visitChildren" and callable(getattr(self, method_name, None)):
                setattr(self, method_name, self._create_visit_method())

    def _create_visit_method(self):
        def visit_method(ctx):
            return self.visitChildren(ctx)
        return visit_method

    def defaultResult(self):
        return []
    
    def aggregrateResult(self, aggregate, nextResult):
        return aggregate.append(nextResult)

class MyVisitor(BaseExplorerScriptVisitor):
    def __init__(self):
        super().__init__()

    def visitOperation(self, ctx):
        print(f"Visiting operation: {ctx.IDENTIFIER()}")
        pass
        

parser.traverse(MyVisitor())

# end measure time
end = time.time()
print("time: ", (end - start))