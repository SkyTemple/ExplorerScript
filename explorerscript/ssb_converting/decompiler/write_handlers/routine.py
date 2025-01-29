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

from igraph import Graph

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.block import BlockWriteHandler
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbRoutineType
from explorerscript.ssb_converting.util import Blk

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

logger = logging.getLogger(__name__)


class RoutineWriteHandler(AbstractWriteHandler):
    """
    Handles writing a single routine, with header.
    """

    def __init__(self, decompiler: ExplorerScriptSsbDecompiler, r_id: int, r_info: SsbRoutineInfo, r_graph: Graph):
        super().__init__(r_graph.vs[0] if len(r_graph.vs) > 0 else None, decompiler, None)  # type: ignore
        self.r_id = r_id
        self.r_info = r_info
        self.r_graph = r_graph

    def write_content(self) -> None:
        self._write_routine_header()
        logger.debug("Handling a routine...")
        with Blk(self.decompiler):
            if len(self.r_graph.vs) == 0:
                self.decompiler.write_stmnt("alias previous;")
            else:
                BlockWriteHandler(self.start_vertex, self.decompiler, self.parent, None).write_content()
        self.decompiler.write_line()

    def _write_routine_header(self) -> None:
        if self.r_info.type == SsbRoutineType.COROUTINE:
            if self.r_id in self.decompiler.named_coroutines:
                self.decompiler.write_stmnt(f"coro {self.decompiler.named_coroutines[self.r_id]}")
            else:
                raise ValueError(f"Unknown coroutine for: {self.r_id}, {self.r_info}")
        elif self.r_info.type == SsbRoutineType.ACTOR:
            self.decompiler.write_stmnt(f"def {self.r_id} for actor {self.r_info.linked_to_repr}")
        elif self.r_info.type == SsbRoutineType.OBJECT:
            self.decompiler.write_stmnt(f"def {self.r_id} for object {self.r_info.linked_to_repr}")
        elif self.r_info.type == SsbRoutineType.PERFORMER:
            self.decompiler.write_stmnt(f"def {self.r_id} for performer {self.r_info.linked_to_repr}")
        elif self.r_info.type == SsbRoutineType.GENERIC:
            self.decompiler.write_stmnt(f"def {self.r_id}")
        else:
            raise ValueError(f"Unknown routine type for: {self.r_id}, {self.r_info}")
