#  MIT License
#
#  Copyright (c) 2020-2024 Capypara and the SkyTemple Contributors
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

import sys
from typing import Union

if sys.version_info >= (3, 10):
    from typing import TypeAlias
else:
    from typing_extensions import TypeAlias

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractAssignmentCompileHandler,
    AbstractComplexStatementCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.integer_like import (
    IntegerLikeCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.label import (
    LabelCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.operations.operation import (
    OperationCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.statements.call import (
    CallCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.statements.control_statement import (
    ControlStatementCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.statements.jump import (
    JumpCompileHandler,
)
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam
from explorerscript.ssb_converting.ssb_special_ops import (
    OPS_CTX_LIVES,
    OPS_CTX_OBJECT,
    OPS_CTX_PERFORMER,
)
from explorerscript.util import _, f

_SupportedHandlers: TypeAlias = Union[
    OperationCompileHandler,
    ControlStatementCompileHandler,
    JumpCompileHandler,
    CallCompileHandler,
    IntegerLikeCompileHandler,
]


class CtxBlockCompileHandler(
    AbstractComplexStatementCompileHandler[ExplorerScriptParser.Ctx_blockContext, _SupportedHandlers]
):
    """Collects the lives/object/actor opcodes and the opcode after that"""

    def __init__(self, ctx: ExplorerScriptParser.Ctx_blockContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._for_id: SsbOpParam | None = None
        self._sub_stmt: _SupportedHandlers | None = None

    def collect(self) -> list[SsbOperation]:
        ops = []
        if self._for_id is None:
            raise SsbCompilerError(_("No target ID set for with(){} block."))
        if self._sub_stmt is None:
            raise SsbCompilerError(_("A with(){} block needs exactly one statement."))
        for_type = str(self.ctx.ctx_header().IDENTIFIER())

        if for_type == "actor":
            ops.append(self._generate_operation(OPS_CTX_LIVES, [self._for_id]))
        elif for_type == "object":
            ops.append(self._generate_operation(OPS_CTX_OBJECT, [self._for_id]))
        elif for_type == "performer":
            ops.append(self._generate_operation(OPS_CTX_PERFORMER, [self._for_id]))
        else:
            raise SsbCompilerError(f(_("Invalid with(){{}} target type '{for_type}'.")))

        assert not isinstance(self._sub_stmt, IntegerLikeCompileHandler)

        sub_ops = self._sub_stmt.collect()
        if len(sub_ops) != 1:
            if isinstance(self._sub_stmt, OperationCompileHandler):
                if self._sub_stmt.ctx.inline_ctx() is not None:
                    # Provide a more specific error when an inline context is used in the operation.
                    raise SsbCompilerError(
                        _(
                            "Operations inside with(){} blocks cannot contain an inline `actor`, `object` or `performer` context."
                        )
                    )

            raise SsbCompilerError(
                _(
                    "A with(){} block needs exactly one binary operation. "
                    "The handler for it generated multiple operations."
                )
            )
        ops += sub_ops

        return ops

    def add(self, obj: _SupportedHandlers) -> None:
        # supports:
        # simple_stmt := operation | cntrl_stmt | jump | call | assignment - For labels a logical error is raised.
        if (
            isinstance(obj, OperationCompileHandler)
            or isinstance(obj, ControlStatementCompileHandler)
            or isinstance(obj, JumpCompileHandler)
            or isinstance(obj, CallCompileHandler)
            or isinstance(obj, AbstractAssignmentCompileHandler)
        ):
            self._check_sub_stmt()
            self._sub_stmt = obj
            return
        if isinstance(obj, LabelCompileHandler):
            raise SsbCompilerError(_("A with(){} block can not contain labels."))

        # integer_like (for for_id)
        if isinstance(obj, IntegerLikeCompileHandler):
            self._for_id = obj.collect()
            return

        self._raise_add_error(obj)

    def _check_sub_stmt(self) -> None:
        if self._sub_stmt is not None:
            raise SsbCompilerError(_("A with(){} block needs exactly one statement."))
