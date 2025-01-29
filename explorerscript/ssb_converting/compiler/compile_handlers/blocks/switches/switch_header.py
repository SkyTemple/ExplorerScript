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

from typing import Union

from typing import TypeAlias

from explorerscript_parser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.primitive import PrimitiveCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.dungeon_mode import (
    SwitchHeaderDungeonModeCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.random import (
    SwitchHeaderRandomCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.scn import (
    SwitchHeaderScnCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.switch_headers.sector import (
    SwitchHeaderSectorCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.operations.operation import OperationCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOperation
from explorerscript.ssb_converting.ssb_special_ops import OP_SWITCH
from explorerscript.util import _

_SupportedHandlers: TypeAlias = Union[
    SwitchHeaderDungeonModeCompileHandler,
    SwitchHeaderRandomCompileHandler,
    SwitchHeaderScnCompileHandler,
    SwitchHeaderSectorCompileHandler,
    PrimitiveCompileHandler,
    OperationCompileHandler,
]


class SwitchHeaderCompileHandler(AbstractCompileHandler[ExplorerScriptParser.Switch_headerContext, _SupportedHandlers]):
    def __init__(self, ctx: ExplorerScriptParser.Switch_headerContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._header_cmplx_handler: _SupportedHandlers | None = None

    def collect(self) -> SsbOperation:
        # Complex branches
        if self._header_cmplx_handler:
            if isinstance(self._header_cmplx_handler, PrimitiveCompileHandler):
                # Switch
                return self._generate_operation(OP_SWITCH, [self._header_cmplx_handler.collect(allow_string=False)])
            elif isinstance(self._header_cmplx_handler, OperationCompileHandler):
                # An operation as condition
                ops = self._header_cmplx_handler.collect()
                if len(ops) != 1:
                    raise SsbCompilerError(_("Invalid content for a switch-header"))
                op = ops[0]
                return self._generate_operation(op.op_code.name, op.params)
            else:
                # A regular complex if condition
                return self._header_cmplx_handler.collect()

        raise SsbCompilerError(_("Unknown switch operation."))

    def add(self, obj: _SupportedHandlers) -> None:
        if (
            isinstance(obj, SwitchHeaderDungeonModeCompileHandler)
            or isinstance(obj, SwitchHeaderRandomCompileHandler)
            or isinstance(obj, SwitchHeaderScnCompileHandler)
            or isinstance(obj, SwitchHeaderSectorCompileHandler)
            or isinstance(obj, PrimitiveCompileHandler)
            or isinstance(obj, OperationCompileHandler)
        ):
            self._header_cmplx_handler = obj
            return
        self._raise_add_error(obj)
