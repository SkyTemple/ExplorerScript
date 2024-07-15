import explorerscript_parser
import time

with open("_unionall.exps", "r") as f:
    text = f.read()

start = time.time()
parser = explorerscript_parser.ExplorerScriptParserWrapper(text)

class MyVisitor(explorerscript_parser.ExplorerScriptBaseVisitor):
    def __init__(self):
        super().__init__()

    def visitOperation(self, ctx):
        print(f"Visiting operation: {ctx.IDENTIFIER()}")
        pass

    def defaultResult(self):
        return []

    def aggregrateResult(self, aggregate, nextResult):
        return aggregate.append(nextResult)

parser.traverse(MyVisitor())

# end measure time
end = time.time()
print("time: ", (end - start))
