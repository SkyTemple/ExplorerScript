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

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, SsbForeignLabel, SsbLabelJump

logger = logging.getLogger(__name__)

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler


class WriteHandlerManager:
    """Class that retrieves the handlers for vertices in a ExplorerScript graph."""

    @classmethod
    def get_for(
        cls,
        v: Vertex,
        decompiler: ExplorerScriptSsbDecompiler,
        parent: AbstractWriteHandler,
        vertex_that_started_block: Vertex | None,
        is_first_vertex_of_block: bool,
    ) -> AbstractWriteHandler:
        from explorerscript.ssb_converting.decompiler.write_handlers.foreign_label import ForeignLabelWriteHandler
        from explorerscript.ssb_converting.decompiler.write_handlers.label import LabelWriteHandler
        from explorerscript.ssb_converting.decompiler.write_handlers.label_jump import LabelJumpWriteHandler
        from explorerscript.ssb_converting.decompiler.write_handlers.simple_op import SimpleOperationWriteHandler

        if "op" not in v.attributes():
            raise ValueError(f"Invalid Ssb vertex: {v}")
        op: SsbOperation = v["op"]
        if isinstance(op, SsbLabel):
            return LabelWriteHandler(v, decompiler, parent, vertex_that_started_block, is_first_vertex_of_block)
        if isinstance(op, SsbForeignLabel):
            return ForeignLabelWriteHandler(v, decompiler, parent, vertex_that_started_block, is_first_vertex_of_block)
        if isinstance(op, SsbLabelJump):
            return LabelJumpWriteHandler(v, decompiler, parent)
        return SimpleOperationWriteHandler(v, decompiler, parent)
