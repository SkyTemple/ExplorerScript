#  MIT License
#
#  Copyright (c) 2020-2023 Capypara and the SkyTemple Contributors
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

from igraph import Vertex

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler, \
    NestedBlockDisallowedError
from explorerscript.ssb_converting.decompiler.write_handlers.block import BlockWriteHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import OPS_CTX_LIVES, OPS_CTX_OBJECT, OPS_CTX_PERFORMER
from explorerscript.ssb_converting.util import Blk


class CtxSimpleOpWriteHandler(AbstractWriteHandler):
    """Handles writing lives, object and actor statements."""

    def __init__(self, start_vertex: Vertex, decompiler, parent):
        super().__init__(start_vertex, decompiler, parent)

    def write_content(self):
        op: SsbOperation = self.start_vertex['op']
        self.decompiler.source_map_add_opcode(op.offset)
        if len(op.params) != 1:
            raise ValueError(f"Error reading operation for {op.op_code.name} ({op}). Must have exactly one argument.")
        if op.op_code.name == OPS_CTX_LIVES:
            self.decompiler.write_stmnt(f"with (actor {op.params[0]})")
        elif op.op_code.name == OPS_CTX_OBJECT:
            self.decompiler.write_stmnt(f"with (object {op.params[0]})")
        elif op.op_code.name == OPS_CTX_PERFORMER:
            self.decompiler.write_stmnt(f"with (performer {op.params[0]})")
        else:
            raise ValueError(f"Unknown ctx opcode: {op}")

        exits = self.start_vertex.out_edges()
        assert len(exits) == 1, "After a lives/object/performer op, there must be exactly one op following."

        # Write the context opcode.
        with Blk(self.decompiler):
            try:
                next_vertex_after_blk = BlockWriteHandler(
                    exits[0].target_vertex, self.decompiler, self, self.start_vertex,
                    check_end_block=Once(),  # Only output one.
                    disallow_nested=True
                ).write_content()
            except NestedBlockDisallowedError:
                raise ValueError(f"lives/performer/object blocks must contain opcodes that don't start any "
                                 f"branching code.")

        return next_vertex_after_blk


class Once:
    def __init__(self):
        self.called = False

    def __call__(self, *args, **kwargs):
        called_before = self.called
        self.called = True
        return not called_before
