#  MIT License
#
#  Copyright (c) 2020 Parakoopa
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
#
import os

from explorerscript.source_map_visualizer import SourceMapVisualizer
from explorerscript.ssb_converting.ssb_compiler import ExplorerScriptSsbCompiler

if __name__ == '__main__':
    # testing
    base = os.path.dirname(os.path.realpath(__file__))
    file_path = os.path.join(base, 'SCRIPT', 'base.exps')
    with open(file_path) as f:
        exps = f.read()
    c = ExplorerScriptSsbCompiler('$DUMMY_VAR', [os.path.join(base, 'macros')]).compile(exps, file_path)
    print("OPS:")
    for op in c.routine_ops[0]:
        print(f"{op.offset:10x}: ({op.op_code.id:3}) {op.op_code.name:45} - {op.params}")
    print(c.routine_infos)
    print(c.named_coroutines)
    print(c.source_map.serialize(pretty=True))
    print(c.imports)
    print("// SOURCE MAP FOR base.exps:")
    print(SourceMapVisualizer(exps, c.source_map).write())
    print("// SOURCE MAP FOR base.exps APPLIED FOR macros1.exps:")
    with open(os.path.join(base, 'macros', 'dir', 'macros1.exps')) as f:
        macros1_exps = f.read()
    print(SourceMapVisualizer(macros1_exps, c.source_map, apply_for_macro_calls=os.path.join(
        '..', 'macros', 'dir', 'macros1.exps'
    )).write())
    print("// SOURCE MAP FOR base.exps APPLIED FOR macros2.exps:")
    with open(os.path.join(base, 'macros', 'dir', 'macros2.exps')) as f:
        macros2_exps = f.read()
    print(SourceMapVisualizer(macros2_exps, c.source_map, apply_for_macro_calls=os.path.join(
        '..', 'macros', 'dir', 'macros2.exps'
    )).write())
