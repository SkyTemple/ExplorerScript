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

import re
from typing import Any


class ExpsMetaAttributes:
    IsSsbScript = "is-ssb-script"


def parse_exps_meta_attributes(explorerscript_src: str) -> dict[str, Any]:
    """Parse the attributes of the script. ("//?: attr: value#")"""
    attributes = {}
    attribute_reader_line = 0
    lines = explorerscript_src.splitlines()
    if len(lines) < 1:
        return {}
    regex_attr_line = re.compile(r"//\?:\s*(.*?):\s*(.*)")
    while lines[attribute_reader_line].strip().startswith("//?:"):
        try:
            line = lines[attribute_reader_line]
            match = regex_attr_line.search(line)
            if match:
                key = match.group(1).strip()
                value = match.group(2).strip()
                attributes[key] = value
            else:
                break
        except Exception:
            pass
        attribute_reader_line += 1
    return attributes
