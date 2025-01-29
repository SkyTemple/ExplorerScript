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
from typing import TypedDict

if sys.version_info >= (3, 11):
    from typing import NotRequired
else:
    from typing_extensions import NotRequired

from explorerscript.cli import SETTINGS_PERFORMANCE_PROGRESS_LIST_VAR_NAME, check_settings, SETTINGS
from explorerscript.ssb_converting.ssb_compiler import ExplorerScriptSsbCompiler
from explorerscript.ssb_converting.ssb_data_types import (
    SsbRoutineInfo,
    SsbOperation,
    SsbRoutineType,
    SsbOpParamConstant,
    SsbOpParamConstString,
    SsbOpParamLanguageString,
    SsbOpParamPositionMarker,
    SsbOpParamFixedPoint,
)
from explorerscript.util import open_utf8


class SsbParamDict(TypedDict):
    type: str
    value: int | float | str | dict[str, str]


class OpDict(TypedDict):
    opcode: str
    params: list[int | SsbParamDict]


class RoutineDict(TypedDict):
    type: str
    name: NotRequired[str]
    target_id: NotRequired[int | str | None]
    ops: list[OpDict]


def build_ops(ops: list[SsbOperation]) -> list[OpDict]:
    out_ops: list[OpDict] = []
    for op in ops:
        out_op: OpDict = {"opcode": op.op_code.name, "params": []}
        for param in op.params:
            if isinstance(param, int):
                out_op["params"].append(param)
            elif isinstance(param, SsbOpParamFixedPoint):
                out_op["params"].append({"type": "FIXED_POINT", "value": param.value})
            elif isinstance(param, SsbOpParamConstant):
                out_op["params"].append({"type": "CONSTANT", "value": param.name})
            elif isinstance(param, SsbOpParamConstString):
                out_op["params"].append({"type": "CONST_STRING", "value": param.name})
            elif isinstance(param, SsbOpParamLanguageString):
                out_op["params"].append({"type": "LANG_STRING", "value": param.strings})
            elif isinstance(param, SsbOpParamPositionMarker):
                out_op["params"].append(
                    {"type": "POSITION_MARK", "value": {"name": param.name, "x": param.x_final, "y": param.y_final}}
                )
            else:
                raise ValueError("Invalid parameter.")
        out_ops.append(out_op)
    return out_ops


def build_routines_json(
    routine_infos: list[SsbRoutineInfo], named_coroutines: list[str], routine_ops: list[list[SsbOperation]]
) -> list[RoutineDict]:
    routines: list[RoutineDict] = []
    for info, name, ops in zip(routine_infos, named_coroutines, routine_ops):
        routine: RoutineDict
        if info.type == SsbRoutineType.COROUTINE:
            routine = {"type": "COROUTINE", "name": name, "ops": build_ops(ops)}
        elif info.type == SsbRoutineType.GENERIC:
            routine = {"type": "GENERIC", "ops": build_ops(ops)}
        elif info.type == SsbRoutineType.ACTOR:
            routine = {
                "type": "ACTOR",
                "target_id": info.linked_to if info.linked_to is not -1 else info.linked_to_name,
                "ops": build_ops(ops),
            }
        elif info.type == SsbRoutineType.OBJECT:
            routine = {
                "type": "OBJECT",
                "target_id": info.linked_to if info.linked_to is not -1 else info.linked_to_name,
                "ops": build_ops(ops),
            }
        elif info.type == SsbRoutineType.PERFORMER:
            routine = {
                "type": "PERFORMER",
                "target_id": info.linked_to if info.linked_to is not -1 else info.linked_to_name,
                "ops": build_ops(ops),
            }
        else:
            raise ValueError(f"invalid routine type {info.type}")
        routines.append(routine)
    return routines


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Compile ExplorerScript to a JSON representation of PMD EoS SSB.")
    parser.add_argument("exps_source", metavar="SOURCE_FILE", help="ExplorerScript source file to compile.")
    parser.add_argument(
        "--settings",
        dest="settings",
        metavar="PATH",
        required=True,
        help="The JSON file containing the settings for the compiler.",
    )
    parser.add_argument("--lookup", dest="lookup_paths", nargs="*", metavar="PATH", help="Lookup paths.")
    parser.add_argument(
        "--source-map",
        dest="source_map",
        default=None,
        metavar="PATH",
        help="If specified, output a source map at that location.",
    )

    args = parser.parse_args()

    if not os.path.exists(args.settings):
        print("Settings file does not exist.", file=sys.stderr)
        exit(1)

    with open_utf8(args.settings, "r") as f:
        settings = json.load(f)

    check_settings(settings)
    settings = settings[SETTINGS]

    if not os.path.exists(args.exps_source):
        print("ExplorerScript source file does not exist.", file=sys.stderr)
        exit(1)

    with open_utf8(args.exps_source, "r") as f:
        exps_source = f.read()

    lookup_paths = args.lookup_paths
    if lookup_paths is None:
        lookup_paths = []

    compiler = ExplorerScriptSsbCompiler(
        settings[SETTINGS_PERFORMANCE_PROGRESS_LIST_VAR_NAME],
        [os.path.abspath(os.path.join(os.getcwd(), p)) for p in lookup_paths],
    )

    compiler.compile(exps_source, os.path.abspath(os.path.join(os.getcwd(), args.exps_source)))

    assert compiler.routine_infos is not None
    assert compiler.named_coroutines is not None
    assert compiler.routine_ops is not None
    assert compiler.source_map is not None
    output_dict = {
        "settings": settings,
        "routines": build_routines_json(compiler.routine_infos, compiler.named_coroutines, compiler.routine_ops),
    }

    if args.source_map is not None:
        with open_utf8(args.source_map, "w") as f:
            f.write(compiler.source_map.serialize())

    print(json.dumps(output_dict))
