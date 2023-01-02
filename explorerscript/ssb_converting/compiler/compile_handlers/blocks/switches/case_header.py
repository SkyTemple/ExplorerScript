#  MIT License
#
#  Copyright (c) 2020-2023 Capypara and the SkyTemple Contributors
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
from typing import Optional

from explorerscript.antlr.ExplorerScriptParser import ExplorerScriptParser
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import AbstractCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.integer_like import IntegerLikeCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_headers.menu import \
    CaseHeaderMenuCompileHandler
from explorerscript.ssb_converting.compiler.compile_handlers.blocks.switches.case_headers.op import \
    CaseHeaderOpCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx, SsbLabelJumpBlueprint
from explorerscript.ssb_converting.ssb_special_ops import OP_CASE
from explorerscript.util import _


class CaseHeaderCompileHandler(AbstractCompileHandler):
    def __init__(self, ctx, compiler_ctx: CompilerCtx):
        super().__init__(ctx, compiler_ctx)
        self._header_cmplx_handler: Optional[AbstractCompileHandler] = None

    def collect(self) -> SsbLabelJumpBlueprint:
        self.ctx: ExplorerScriptParser.Case_headerContext

        # Complex branches
        if self._header_cmplx_handler:
            if isinstance(self._header_cmplx_handler, IntegerLikeCompileHandler):
                # Case
                return SsbLabelJumpBlueprint(
                   self.compiler_ctx, self.ctx,
                   OP_CASE, [self._header_cmplx_handler.collect()]
                )
            else:
                # A regular complex if condition
                return self._header_cmplx_handler.collect()

        raise SsbCompilerError(_("Unknown case operation."))

    def get_header_handler_type(self) -> type(AbstractCompileHandler):
        return type(self._header_cmplx_handler)

    def add(self, obj: any):
        if isinstance(obj, CaseHeaderMenuCompileHandler) or isinstance(obj, CaseHeaderOpCompileHandler) \
                or isinstance(obj, IntegerLikeCompileHandler):
            self._header_cmplx_handler = obj
            return
        self._raise_add_error(obj)
