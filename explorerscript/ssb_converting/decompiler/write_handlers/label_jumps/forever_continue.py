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

from igraph import Vertex

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler, FallbackToJump

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

logger = logging.getLogger(__name__)


class ForeverContinueWriteHandler(AbstractWriteHandler):
    """Handles writing loop continue statements."""

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)

    def write_content(self) -> Vertex | None:
        """Print a continue (if not implicit) and end"""
        logger.debug("Handling a continue; (%s)...", self.start_vertex["op"])
        if len(self.decompiler.forever_start_handler_stack) < 1:
            # We REALLY shouldn't land here, if we are outside of a loop, but sometimes loop detection still
            # raises some "false positives" and builds loops that have break statements reachable from outside
            # the loop
            logger.warning("While decompiling, tried to generate continue; outside loop!")
            raise FallbackToJump()
        if not self._continue_is_implicit():
            self.decompiler.source_map_add_opcode(self.start_vertex["op"].offset)
            self.decompiler.write_stmnt("continue;  // may be redundant")
        return None

    def _continue_is_implicit(self) -> bool:
        # TODO: Not implemented, is probably not really possible, unless we do a multi-pass solution.
        return False
