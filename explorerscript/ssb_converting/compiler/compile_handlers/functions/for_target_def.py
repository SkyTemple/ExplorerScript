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

from typing import Any

from explorerscript.common_syntax import parse_for_target
from explorerscript.error import SsbCompilerError
from explorerscript.ssb_converting.compiler.compile_handlers.abstract import (
    AbstractFuncdefCompileHandler,
    AbstractCompileHandler,
)
from explorerscript.ssb_converting.compiler.compile_handlers.atoms.primitive import PrimitiveCompileHandler
from explorerscript.ssb_converting.compiler.utils import CompilerCtx
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbRoutineType, SsbOpParam
from explorerscript.util import exps_int
from explorerscript_parser import ExplorerScriptParser, Antlr4ParserRuleContext


class ForTargetDefCompileHandler(AbstractFuncdefCompileHandler[ExplorerScriptParser.For_target_defContext]):
    _linked_to_target: SsbOpParam | None

    def __init__(self, ctx: ExplorerScriptParser.For_target_defContext, compiler_ctx: CompilerCtx) -> None:
        super().__init__(ctx, compiler_ctx)
        self._linked_to_target = None

    def collect(self) -> Any:
        """Collects routine info and operations."""
        assert self._linked_to_target is not None
        linked_to, linked_to_name = parse_for_target(self._linked_to_target)

        target: ExplorerScriptParser.For_target_def_targetContext = self.ctx.for_target_def_target()
        legacy_deprecated_target = target.FOR_TARGET()
        new_style_target = target.IDENTIFIER()
        if str(legacy_deprecated_target) == "for_actor" or str(new_style_target) == "actor":
            routine_info = SsbRoutineInfo(SsbRoutineType.ACTOR, linked_to, linked_to_name)
        elif str(legacy_deprecated_target) == "for_object" or str(new_style_target) == "object":
            routine_info = SsbRoutineInfo(SsbRoutineType.OBJECT, linked_to, linked_to_name)
        elif str(legacy_deprecated_target) == "for_performer" or str(new_style_target) == "performer":
            routine_info = SsbRoutineInfo(SsbRoutineType.PERFORMER, linked_to, linked_to_name)
        else:
            raise SsbCompilerError("A targeted routine must be 'for' an 'actor', 'object' or 'performer'.")

        with self.compiler_ctx.in_funcdef(linked_to_name if linked_to_name is not None else linked_to):
            ops = self.collect_ops()

        return routine_info, ops

    def get_new_routine_id(self, old_id: int) -> int:
        return exps_int(str(self.ctx.INTEGER()))

    def add(self, obj: PrimitiveCompileHandler | AbstractCompileHandler[Antlr4ParserRuleContext, Any]) -> None:
        if isinstance(obj, PrimitiveCompileHandler):
            try:
                self._linked_to_target = obj.collect(allow_string=False)
            except SsbCompilerError:
                raise SsbCompilerError("Invalid target for routine.")
            return
        super().add(obj)
