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

import sys

SETTINGS_PERFORMANCE_PROGRESS_LIST_VAR_NAME = "performance_progress_list_var_name"
SETTINGS_DUNGEON_MODE_CONSTANTS = "dungeon_mode_constants"
SETTINGS = "settings"
SETTINGS_DMC_OPEN = "open"
SETTINGS_DMC_CLOSED = "closed"
SETTINGS_DMC_REQUEST = "request"
SETTINGS_DMC_OPEN_REQUEST = "open_request"


def check_settings(settings):  # type: ignore
    if SETTINGS not in settings:
        print("Settings missing.", file=sys.stderr)
        exit(1)
    settings = settings[SETTINGS]

    if SETTINGS_PERFORMANCE_PROGRESS_LIST_VAR_NAME not in settings:
        print(f"'{SETTINGS_PERFORMANCE_PROGRESS_LIST_VAR_NAME}' missing in settings.", file=sys.stderr)
        exit(1)

    if SETTINGS_DUNGEON_MODE_CONSTANTS not in settings or not all(
        x in settings[SETTINGS_DUNGEON_MODE_CONSTANTS]
        for x in [SETTINGS_DMC_OPEN, SETTINGS_DMC_CLOSED, SETTINGS_DMC_REQUEST, SETTINGS_DMC_OPEN_REQUEST]
    ):
        print(f"'{SETTINGS_DUNGEON_MODE_CONSTANTS}' missing in settings or malformed.", file=sys.stderr)
        exit(1)
