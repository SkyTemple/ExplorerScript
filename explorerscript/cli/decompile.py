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

import argparse
import json
import os
import sys
from typing import TypedDict, Any
from collections.abc import MutableSequence

if sys.version_info >= (3, 11):
    from typing import NotRequired
else:
    from typing_extensions import NotRequired

from explorerscript.cli import (
    check_settings,
    SETTINGS_PERFORMANCE_PROGRESS_LIST_VAR_NAME,
    SETTINGS,
    SETTINGS_DUNGEON_MODE_CONSTANTS,
    SETTINGS_DMC_OPEN,
    SETTINGS_DMC_CLOSED,
    SETTINGS_DMC_REQUEST,
    SETTINGS_DMC_OPEN_REQUEST,
)
from explorerscript.ssb_converting.compiler.utils import Counter
from explorerscript.ssb_converting.ssb_data_types import (
    SsbCoroutine,
    SsbOperation,
    SsbRoutineInfo,
    DungeonModeConstants,
    SsbRoutineType,
    SsbOpParamConstant,
    SsbOpParamConstString,
    SsbOpParamLanguageString,
    SsbOpParamPositionMarker,
    SsbOpCode,
    SsbOpParamFixedPoint,
    SsbOpParam,
)
from explorerscript.ssb_converting.ssb_decompiler import ExplorerScriptSsbDecompiler
from explorerscript.util import open_utf8, exps_int

counter = Counter()


class OpDict(TypedDict):
    params: list[ParamDict]
    opcode: str


class ParamDict(TypedDict):
    type: str
    value: Any  # TODO


class RoutineDict(TypedDict):
    type: str
    ops: list[OpDict]
    name: NotRequired[str]
    target_id: NotRequired[str]


def parse_pos_mark_arg(arg_str: str) -> tuple[int, int]:
    arg_str_arr = arg_str.split(".")
    if len(arg_str_arr) < 2:
        return exps_int(arg_str), 0
    if arg_str_arr[1] != "5" or len(arg_str_arr) > 2:
        raise ValueError("Invalid position mark")
    return exps_int(arg_str_arr[0]), 2


def read_ops(ops: list[OpDict]) -> list[SsbOperation]:
    out_ops: list[SsbOperation] = []

    for op in ops:
        if "params" not in op:
            raise ValueError("Params for an op not set.")
        if "opcode" not in op:
            raise ValueError("Opcode for an op not set.")
        params: list[SsbOpParam] = []
        for param in op["params"]:
            if isinstance(param, int):
                params.append(param)
            elif isinstance(param, dict):
                if "type" not in param or "value" not in param:
                    raise ValueError("Invalid param for op.")
                if param["type"] == "FIXED_POINT":
                    params.append(SsbOpParamFixedPoint.from_str(param["value"]))
                elif param["type"] == "CONSTANT":
                    params.append(SsbOpParamConstant(param["value"]))
                elif param["type"] == "CONST_STRING":
                    params.append(SsbOpParamConstString(param["value"]))
                elif param["type"] == "LANG_STRING":
                    params.append(SsbOpParamLanguageString(param["value"]))
                elif param["type"] == "POSITION_MARK":
                    x_relative, x_offset = parse_pos_mark_arg(param["value"]["x"])
                    y_relative, y_offset = parse_pos_mark_arg(param["value"]["y"])
                    params.append(
                        SsbOpParamPositionMarker(param["value"]["name"], x_offset, y_offset, x_relative, y_relative)
                    )
                else:
                    raise ValueError("Invalid param for op.")
            else:
                raise ValueError("Invalid param for op.")

        out_ops.append(SsbOperation(counter(), SsbOpCode(-1, op["opcode"]), params))

    return out_ops


def read_routines(
    routines: list[RoutineDict],
) -> tuple[list[SsbRoutineInfo], list[SsbCoroutine], MutableSequence[MutableSequence[SsbOperation]]]:
    routine_infos = []
    named_coroutines = []
    routine_ops: MutableSequence[MutableSequence[SsbOperation]] = []
    for r in routines:
        if "ops" not in r:
            raise ValueError("Ops for a routine not set.")
        if "type" not in r:
            raise ValueError("Type for a routine not set.")
        if r["type"] == "COROUTINE":
            if "name" not in r:
                raise ValueError("Target for a routine not set.")
            named_coroutines.append(SsbCoroutine(-1, r["name"]))
            routine_infos.append(SsbRoutineInfo(SsbRoutineType.COROUTINE, -1))
            routine_ops.append(read_ops(r["ops"]))
        elif r["type"] == "GENERIC":
            named_coroutines.append(SsbCoroutine(-1, "n/a"))
            routine_infos.append(SsbRoutineInfo(SsbRoutineType.GENERIC, -1))
            routine_ops.append(read_ops(r["ops"]))
        elif r["type"] == "ACTOR":
            if "target_id" not in r:
                raise ValueError("Target for a routine not set.")
            linked_to = -1
            linked_to_name = None
            if isinstance(r["target_id"], int):
                linked_to = r["target_id"]
            else:
                linked_to_name = str(r["target_id"])
            named_coroutines.append(SsbCoroutine(-1, "n/a"))
            routine_infos.append(SsbRoutineInfo(SsbRoutineType.ACTOR, linked_to, linked_to_name))
            routine_ops.append(read_ops(r["ops"]))
        elif r["type"] == "OBJECT":
            if "target_id" not in r:
                raise ValueError("Target for a routine not set.")
            linked_to = -1
            linked_to_name = None
            if isinstance(r["target_id"], int):
                linked_to = r["target_id"]
            else:
                linked_to_name = str(r["target_id"])
            named_coroutines.append(SsbCoroutine(-1, "n/a"))
            routine_infos.append(SsbRoutineInfo(SsbRoutineType.OBJECT, linked_to, linked_to_name))
            routine_ops.append(read_ops(r["ops"]))
        elif r["type"] == "PERFORMER":
            if "target_id" not in r:
                raise ValueError("Target for a routine not set.")
            linked_to = -1
            linked_to_name = None
            if isinstance(r["target_id"], int):
                linked_to = r["target_id"]
            else:
                linked_to_name = str(r["target_id"])
            named_coroutines.append(SsbCoroutine(-1, "n/a"))
            routine_infos.append(SsbRoutineInfo(SsbRoutineType.PERFORMER, linked_to, linked_to_name))
            routine_ops.append(read_ops(r["ops"]))
        else:
            raise ValueError(f"Invalid type for a routine: {r['type']}.")

    return routine_infos, named_coroutines, routine_ops


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Decompile a JSON representation of PMD EoS SSB into ExplorerScript.")
    parser.add_argument(
        "ssb_path", metavar="SSB_JSON_PATH", help="SSB JSON to decompile, including the compiler settings."
    )
    parser.add_argument(
        "--source-map",
        dest="source_map",
        default=None,
        metavar="PATH",
        help="If specified, output a source map at that location.",
    )

    args = parser.parse_args()

    if not os.path.exists(args.ssb_path):
        print("JSON file does not exist.", file=sys.stderr)
        exit(1)

    with open_utf8(args.ssb_path, "r") as f:
        ssb_file = json.load(f)

    check_settings(ssb_file)

    routine_infos, named_coroutines, routine_ops = read_routines(ssb_file["routines"])

    dmodes = ssb_file[SETTINGS][SETTINGS_DUNGEON_MODE_CONSTANTS]
    decompiler = ExplorerScriptSsbDecompiler(
        routine_infos,
        routine_ops,
        named_coroutines,
        ssb_file[SETTINGS][SETTINGS_PERFORMANCE_PROGRESS_LIST_VAR_NAME],
        DungeonModeConstants(
            dmodes[SETTINGS_DMC_CLOSED],
            dmodes[SETTINGS_DMC_OPEN],
            dmodes[SETTINGS_DMC_REQUEST],
            dmodes[SETTINGS_DMC_OPEN_REQUEST],
        ),
    )

    exps_src, source_map = decompiler.convert()

    if args.source_map is not None:
        with open_utf8(args.source_map, "w") as f:
            f.write(source_map.serialize())

    print(exps_src)
