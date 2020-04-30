#  MIT License
#
#  Copyright (c) 2020 Parakoopa
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
from typing import List, Dict

from explorerscript.antlr.ExplorerScriptListener import ExplorerScriptListener
from explorerscript.source_map import SourceMapBuilder
from explorerscript.ssb_converting.ssb_data_types import SsbRoutineInfo, SsbOperation


class ExplorerScriptCompilerListener(ExplorerScriptListener):
    """Builds the SSB data structures while listening for parsing events."""
    def __init__(self):
        # The information about routines stored in the ssb.
        self.routine_infos: List[SsbRoutineInfo] = []
        self.routine_ops: List[List[SsbOperation]] = []
        self.named_coroutines: List[str] = []
        # A dict that assigns all collected labels their next opcode id.
        self.label_offsets: Dict[int, int] = {}
        # Source map
        self.source_map_builder: SourceMapBuilder = SourceMapBuilder()

