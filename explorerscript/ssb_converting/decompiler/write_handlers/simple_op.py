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
from explorerscript.ssb_converting.decompiler.write_handlers.simple_ops.ctx import CtxSimpleOpWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.simple_ops.flag import FlagSimpleOpWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.simple_ops.keyword import KeywordSimpleOpWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.simple_ops.message_switches import (
    MesageSwitchSimpleOpWriteHandler,
)
from explorerscript.ssb_converting.decompiler.write_handlers.simple_ops.message_switches_cases import (
    MesageSwitchCasesSimpleOpWriteHandler,
)
from explorerscript.ssb_converting.decompiler.write_handlers.simple_ops.simple import SimpleSimpleOpWriteHandler
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import (
    OPS_CTX,
    OP_JUMP,
    OP_RETURN,
    OP_END,
    OP_HOLD,
    OPS_SWITCH_TEXT_CASE_MAP,
    OPS_SWITCH_TEXT_CASE_CASES_LIST,
    OPS_FLAG_ALL,
    OP_CALL,
)

if TYPE_CHECKING:
    from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler

logger = logging.getLogger(__name__)


class SimpleOperationWriteHandler(AbstractWriteHandler):
    """Handles writing regular operations and a few special cases."""

    _ssb_operations_special_cases_handlers: dict[str | None, type[AbstractWriteHandler]] = {
        None: SimpleSimpleOpWriteHandler
    }
    for x in [OP_JUMP, OP_CALL, OP_RETURN, OP_END, OP_HOLD]:
        _ssb_operations_special_cases_handlers[x] = KeywordSimpleOpWriteHandler
    for x in OPS_CTX:
        _ssb_operations_special_cases_handlers[x] = CtxSimpleOpWriteHandler
    for x in OPS_SWITCH_TEXT_CASE_MAP:
        _ssb_operations_special_cases_handlers[x] = MesageSwitchSimpleOpWriteHandler
    for x in OPS_SWITCH_TEXT_CASE_CASES_LIST:
        _ssb_operations_special_cases_handlers[x] = MesageSwitchCasesSimpleOpWriteHandler
    for x in OPS_FLAG_ALL:
        _ssb_operations_special_cases_handlers[x] = FlagSimpleOpWriteHandler

    def __init__(
        self, start_vertex: Vertex, decompiler: ExplorerScriptSsbDecompiler, parent: AbstractWriteHandler | None
    ):
        super().__init__(start_vertex, decompiler, parent)

    def write_content(self) -> Vertex | None:
        """Delegate to specific simple op handler"""
        return self.get_real_handler()(self.start_vertex, self.decompiler, self).write_content()

    def get_real_handler(self) -> type[AbstractWriteHandler]:
        op: SsbOperation = self.start_vertex["op"]
        logger.debug("Writing a simple operation (%s)...", op)
        handler = self._ssb_operations_special_cases_handlers[None]
        for h_types, h in self._ssb_operations_special_cases_handlers.items():
            if op.op_code.name == h_types:
                handler = h
        return handler
