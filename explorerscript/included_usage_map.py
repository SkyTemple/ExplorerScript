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
import os

from explorerscript.source_map import SourceMap

logger = logging.getLogger(__name__)


class IncludedUsageMap:
    """
    Utility class to find out which files are included by an ExplorerScript file.
    The data for this is retrieved from the source map and macro data.
    This is useful for knowing which files have to be re-compiled when saving an ExplorerScript and
    saving this information with the included ExplorerScript file.
    """

    def __init__(self, source_map: SourceMap, base_abs_file_path: str):
        """Initialise the list of included files from a source map."""
        # A set of <absolute file name of included file>
        self.included_files = set()
        dirname_base_abs_file_path = os.path.dirname(base_abs_file_path)
        for opcode_offset, mapping in source_map.collect_mappings__macros():
            if mapping.relpath_included_file is not None:
                self.included_files.add(
                    os.path.abspath(os.path.join(dirname_base_abs_file_path, mapping.relpath_included_file))
                )

    def __sub__(self, other: object) -> IncludedUsageMapDiff:
        """Subtract two maps. The result is IncludedUsageMapDiff."""
        if not isinstance(other, IncludedUsageMap):
            return NotImplemented
        return IncludedUsageMapDiff(self, other)


class IncludedUsageMapDiff:
    """
    The result of diffing two inclusion maps.
    The field 'removed' contains a set of files which are no longer included.
    The field 'added' contains a set of files which are now newly included.
    """

    def __init__(self, before: IncludedUsageMap, after: IncludedUsageMap):
        usage_files_before = before.included_files
        usage_files_after = after.included_files
        # 1. Remove from macro usage files that are no longer in the new list
        self.removed = usage_files_before - usage_files_after
        # 2. Add to the new macro usage files we were not in yet
        self.added = usage_files_after - usage_files_before
        logger.debug("Inclusion map diff result: Added<%s> - Removed<%s>", self.added, self.removed)
