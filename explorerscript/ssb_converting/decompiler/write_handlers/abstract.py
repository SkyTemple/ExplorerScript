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

from abc import ABC, abstractmethod
from typing import TYPE_CHECKING

from igraph import Vertex

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler


class AbstractWriteHandler(ABC):
    """
    Handles the writing of a single operation, statement, block, routine, etc.
    The start vertex is passed by the parent handler to specify where this handler should begin.
    """

    start_vertex: Vertex
    decompiler: ExplorerScriptSsbDecompiler
    # Parent write handler.
    parent: AbstractWriteHandler | None
    ended_on_jump: bool

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        self.start_vertex = start_vertex
        self.decompiler = decompiler
        self.parent = parent
        self.ended_on_jump = False

    @abstractmethod
    def write_content(self) -> Vertex | None:
        """
        Writes all operations that this handler is made for, and then
        returns the next vertex to process for the parent handler (if applicable).
        """
        pass


class NestedBlockDisallowedError(Exception):
    pass


class FallbackToJump(Exception):
    """Raised when a label jump write handler can not do
    it's task and the default jump handler should be used instead."""

    pass
