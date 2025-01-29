#  MIT License
#
#  Copyright (c) 2020-2025 Capypara and the SkyTemple Contributors
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
from __future__ import annotations

import logging
from typing import TYPE_CHECKING
from collections.abc import Callable

from explorerscript.ssb_converting.decompiler.write_handler_manager import WriteHandlerManager

from typing import TypeAlias

from igraph import Vertex

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import (
    AbstractWriteHandler,
    NestedBlockDisallowedError,
)
from explorerscript.ssb_converting.ssb_special_ops import (
    OPS_THAT_END_CONTROL_FLOW,
    SsbLabel,
    SsbLabelJump,
    SsbForeignLabel,
    OP_HOLD,
    OP_END,
    OP_RETURN,
    OP_DUMMY_END,
)

logger = logging.getLogger(__name__)

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

CheckEndBlockCallable: TypeAlias = Callable[["BlockWriteHandler", "AbstractWriteHandler"], bool]


class BlockWriteHandler(AbstractWriteHandler):
    """Writes one block of output for ExplorerScript using an entry point vertex (the first in this block)."""

    _next_vertex: Vertex | None
    # Optional callback to check if the block should be ended
    # Please note, that the block will also end automatically, if the end of the
    # graph has no reachable vertices anymore.
    check_end_block: CheckEndBlockCallable | None
    # This will contain the handler for the last operation written by this block, after write_content.
    last_handler_in_block: AbstractWriteHandler | None
    # If True, an exception is raised if the block contains any opcodes that would start another sub-block
    _disallow_nested: bool

    vertex_that_started_block: Vertex | None
    last_vertex: Vertex | None

    def __init__(
        self,
        start_vertex: Vertex,
        decompiler: ExplorerScriptSsbDecompiler,
        parent: AbstractWriteHandler | None,
        vertex_that_started_block: Vertex | None,
        *,
        check_end_block: CheckEndBlockCallable | None = None,
        disallow_nested: bool = False,
    ) -> None:
        super().__init__(start_vertex, decompiler, parent)
        self._next_vertex = start_vertex
        self.check_end_block = check_end_block
        self.last_handler_in_block = None
        self._disallow_nested = disallow_nested

        self.vertex_that_started_block = vertex_that_started_block
        self.last_vertex = None

    def write_content(self) -> Vertex | None:
        from explorerscript.ssb_converting.decompiler.write_handlers.simple_op import SimpleOperationWriteHandler

        previous_vertex = None
        is_first_vertex = True
        while self._next_vertex is not None:
            # Write
            self.last_handler_in_block = WriteHandlerManager.get_for(
                self._next_vertex, self.decompiler, self, self.vertex_that_started_block, is_first_vertex
            )
            is_first_vertex = False

            if self.check_end_block:
                should_continue = self.check_end_block(self, self.last_handler_in_block)
                if not should_continue:
                    break

            if self._disallow_nested:
                # Make sure, that the _disallow_nested restriction is honored.
                # TODO: pretty hard-coded at the moment.
                if self.last_handler_in_block.__class__.__name__ != "SimpleOperationWriteHandler":
                    raise NestedBlockDisallowedError("A block was not expected to contain any sub-blocks.")
                # (last_handler_in_block must be SimpleOperationWriteHandler in this case)
                assert isinstance(self.last_handler_in_block, SimpleOperationWriteHandler)
                if self.last_handler_in_block.get_real_handler().__name__ == "CtxSimpleOpWriteHandler":
                    raise NestedBlockDisallowedError("A block was not expected to contain any sub-blocks.")

            previous_vertex = self._next_vertex
            self._next_vertex = self.last_handler_in_block.write_content()
            assert self._next_vertex is None or isinstance(self._next_vertex, Vertex)

        # Perform basic end-of-branch check (to see if we need an end, return or hold).
        # we don't need to do that on jumps or fallthrough
        assert self.last_handler_in_block is not None
        if self._next_vertex is None and not self.last_handler_in_block.ended_on_jump:
            if previous_vertex is None:
                # ???
                raise ValueError("Found end of branch, but no previous op...?")
            if (
                previous_vertex["op"].op_code.name not in OPS_THAT_END_CONTROL_FLOW
                and not isinstance(previous_vertex["op"], SsbLabelJump)
                and not isinstance(previous_vertex["op"], SsbLabel)
                and not isinstance(previous_vertex["op"], SsbForeignLabel)
            ):
                # All branches must end with something that ends their control flow
                logger.warning(
                    f"Had to insert a {OP_DUMMY_END} after {previous_vertex['op']}, because it was last in branch."
                )
                if OP_DUMMY_END == OP_RETURN:
                    self.decompiler.write_return()
                elif OP_DUMMY_END == OP_END:
                    self.decompiler.write_end()
                elif OP_DUMMY_END == OP_HOLD:
                    self.decompiler.write_hold()
                else:
                    # ?
                    self.decompiler.write_end()

        self.last_vertex = previous_vertex
        return self._next_vertex
