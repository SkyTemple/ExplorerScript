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

from explorerscript_parser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractComplexStatementCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.primitive import PrimitiveCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.arg_list import (
    ArgListCompileHandler,
)
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam
from explorerscript.ssb_converting.ssb_special_ops import (
    OPS_CTX_LIVES,
    OPS_CTX_OBJECT,
    OPS_CTX_PERFORMER,
)
from explorerscript.util import _, f


class OperationCompileHandler(
    AbstractComplexStatementCompileHandler[
        ExplorerScriptParser.OperationContext, Union[ArgListCompileHandler, PrimitiveCompileHandler]
    ]
):
    def __init__(self, ctx: ExplorerScriptParser.OperationContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._for_id: SsbOpParam | None = None
        self.arg_list_handler: ArgListCompileHandler | None = None

    def collect(self) -> list[SsbOperation]:
        name = str(self.ctx.IDENTIFIER())
        args: list[SsbOpParam] = []

        ops = []
        inline_ctx = self.ctx.inline_ctx()
        if inline_ctx is not None:
            for_type = str(inline_ctx.ctx_header().IDENTIFIER())

            if self._for_id is None:
                raise SsbCompilerError(_("No target ID set for inline actor/object/performer context."))

            if for_type == "actor":
                ops.append(self._generate_operation(OPS_CTX_LIVES, [self._for_id]))
            elif for_type == "object":
                ops.append(self._generate_operation(OPS_CTX_OBJECT, [self._for_id]))
            elif for_type == "performer":
                ops.append(self._generate_operation(OPS_CTX_PERFORMER, [self._for_id]))
            else:
                raise SsbCompilerError(f(_("Invalid with(){{}} target type '{for_type}'.")))

        if self.arg_list_handler:
            args = self.arg_list_handler.collect()

        ops.append(self._generate_operation(name, args))
        return ops

    def add(self, obj: ArgListCompileHandler | PrimitiveCompileHandler) -> None:
        if isinstance(obj, ArgListCompileHandler):
            self.arg_list_handler = obj
            return

        if isinstance(obj, PrimitiveCompileHandler):
            self._for_id = obj.collect(allow_string=False)
            return

        self._raise_add_error(obj)
