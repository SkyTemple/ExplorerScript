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
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractAssignmentCompileHandler,
    AbstractComplexStatementCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.primitive import PrimitiveCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.label import LabelCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.operation import OperationCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.statements.call import CallCompileHandler
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
    PrimitiveCompileHandler,
]


class CtxBlockCompileHandler(
    AbstractComplexStatementCompileHandler[ExplorerScriptParser.Ctx_blockContext, _SupportedHandlers]
):
    """
    Compiles a `with` block.
    The compiled code contains pairs of an lives/object/performer opcode and an opcode that reference the given actor/object/performer.
    """

    def __init__(self, ctx: ExplorerScriptParser.Ctx_blockContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._for_id: SsbOpParam | None = None
        self._sub_stmts: list[_SupportedHandlers] = []

    def collect(self) -> list[SsbOperation]:
        ops = []
        if self._for_id is None:
            raise SsbCompilerError(_("No target ID set for with(){} block."))

        if len(self._sub_stmts) == 0:
            raise SsbCompilerError(_("A with(){} block needs at least one statement."))

        for_type = str(self.ctx.ctx_header().IDENTIFIER())

        for sub_stmt in self._sub_stmts:
            if for_type == "actor":
                ops.append(self._generate_operation(OPS_CTX_LIVES, [self._for_id]))
            elif for_type == "object":
                ops.append(self._generate_operation(OPS_CTX_OBJECT, [self._for_id]))
            elif for_type == "performer":
                ops.append(self._generate_operation(OPS_CTX_PERFORMER, [self._for_id]))
            else:
                raise SsbCompilerError(f(_("Invalid with(){{}} target type '{for_type}'.")))

            assert not isinstance(sub_stmt, PrimitiveCompileHandler)
            sub_ops = sub_stmt.collect()
            if len(sub_ops) != 1:
                if isinstance(sub_stmt, OperationCompileHandler):
                    if sub_stmt.ctx.inline_ctx() is not None:
                        # Provide a more specific error when an inline context is used in the operation.
                        raise SsbCompilerError(
                            _(
                                "Operations inside with(){} blocks cannot contain an inline `actor`, `object` or `performer` context."
                            )
                        )

                assert not isinstance(sub_stmt, PrimitiveCompileHandler)
                sub_ops = sub_stmt.collect()
                if len(sub_ops) != 1:
                    raise SsbCompilerError(
                        _(
                            "Each statement inside a with(){} block needs to contain exactly one binary operation. "
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
            self._sub_stmts.append(obj)
            return
        if isinstance(obj, LabelCompileHandler):
            raise SsbCompilerError(_("A with(){} block can not contain labels."))

        # integer_like (for for_id)
        if isinstance(obj, PrimitiveCompileHandler):
            self._for_id = obj.collect(allow_string=False)
            return

        self._raise_add_error(obj)
