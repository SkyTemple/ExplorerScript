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

from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractComplexStatementCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.operations.arg_list import ArgListCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam
from explorerscript.util import _, f
from explorerscript_parser import ExplorerScriptParser


class MacroCallCompileHandler(
    AbstractComplexStatementCompileHandler[ExplorerScriptParser.Macro_callContext, ArgListCompileHandler]
):
    def __init__(self, ctx: ExplorerScriptParser.Macro_callContext, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self.arg_list_handler: ArgListCompileHandler | None = None

    def collect(self) -> list[SsbOperation]:
        name = str(self.ctx.MACRO_CALL())[1:]
        args: list[SsbOpParam] = []
        if self.arg_list_handler:
            args = self.arg_list_handler.collect()
        if name not in self.compiler_ctx.macros.keys():
            raise SsbCompilerError(f(_("Macro {name} not found.")))
        macro = self.compiler_ctx.macros[name]

        self.compiler_ctx.source_map_builder.next_macro_opcode_called_in(
            None, self.ctx.start.line - 1, self.ctx.start.charPositionInLine
        )
        return macro.build(
            self.compiler_ctx.counter_ops,
            self.compiler_ctx.counter_labels,
            dict(zip(macro.variables, args)),
            self.compiler_ctx.source_map_builder,
        )

    def add(self, obj: ArgListCompileHandler) -> None:
        if isinstance(obj, ArgListCompileHandler):
            self.arg_list_handler = obj
            return
        self._raise_add_error(obj)
