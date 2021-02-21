#  MIT License
#
#  Copyright (c) 2020-2021 Parakoopa and the SkyTemple Contributors
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
import logging
from typing import Dict, Type, Optional

from igraph import Vertex

from explorerscript.ssb_converting.decompiler.write_handlers.abstract import AbstractWriteHandler, FallbackToJump
from explorerscript.ssb_converting.decompiler.write_handlers.label_jumps.call import CallWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.label_jumps.forever_break import ForeverBreakWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.label_jumps.forever_continue import \
    ForeverContinueWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.label_jumps.if_start import IfWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.label_jumps.jump import JumpWriteHandler
from explorerscript.ssb_converting.decompiler.write_handlers.label_jumps.switch_start import SwitchWriteHandler
from explorerscript.ssb_converting.ssb_special_ops import LabelJumpMarker, MultiIfStart, IfStart, \
    SwitchStart, ForeverContinue, ForeverBreak, SsbLabelJump, OP_JUMP, CallJump

logger = logging.getLogger(__name__)


class LabelJumpWriteHandler(AbstractWriteHandler):
    """Handles writing label jumps (ifs, switches, loops, jumps etc.)."""

    _label_jump_marker_handlers: Dict[LabelJumpMarker, Type[Optional[AbstractWriteHandler]]] = {
        MultiIfStart: IfWriteHandler,
        IfStart: IfWriteHandler,
        SwitchStart: SwitchWriteHandler,
        ForeverContinue: ForeverContinueWriteHandler,
        ForeverBreak: ForeverBreakWriteHandler,
        CallJump: CallWriteHandler,
        type(None): JumpWriteHandler,
    }

    def __init__(self, start_vertex: Vertex, decompiler, parent):
        super().__init__(start_vertex, decompiler, parent)
        m = self.start_vertex['op'].get_marker()
        self.ended_on_jump = type(m) in self._label_jump_marker_handlers and self._label_jump_marker_handlers[type(m)] == JumpWriteHandler

    def write_content(self):
        """Delegates to the handlers in .label_jump"""
        op: SsbLabelJump = self.start_vertex['op']
        logger.debug("Handling a label jump (%s)...", op)
        m = op.get_marker()
        if type(m) in self._label_jump_marker_handlers:
            try:
                return self._label_jump_marker_handlers[type(m)](self.start_vertex, self.decompiler, self).write_content()
            except FallbackToJump:
                return self._label_jump_marker_handlers[type(None)](self.start_vertex, self.decompiler, self).write_content()
        else:
            raise ValueError(f"Unknown label marker type ({type(m)}) for {op}: {m}")
