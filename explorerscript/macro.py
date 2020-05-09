"""Model representation of a single ExplorerScript macro function."""
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
from typing import Optional, List, Dict

from explorerscript.source_map import SourceMap, SourceMapBuilder
from explorerscript.ssb_converting.compiler.utils import Counter
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam, SsbOpParamConstant
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, SsbLabelJump


class ExplorerScriptMacro:
    def __init__(self, name: str, variables: List[str],
                 blueprints: List[SsbOperation], source_map: SourceMap):
        """
        A model for a ExplorerScript macro. Contains the processed (= all sub-macros are already fully processed)
        opcodes by the MacroVisitor and some metadata.
        """

        # The name of the macro
        self.name: str = name

        # The names of the variables, in order of definition in the header.
        self.variables: List[str] = variables

        # The Ssb operations that act as a blueprint for this macro
        self.blueprints: List[SsbOperation] = blueprints

        # The absolute path to the ExplorerScript source file that this macro is in.
        # May be not set, if this macro is not in a physical file.
        self.included__absolute_path: Optional[str] = None

        # The original source map builder, that will be used to insert the proper macro source map entries
        # when building the macro
        self.source_map: SourceMap = source_map

        # The relative path of the ExplorerScript source file that was originally requested to be
        # compiled by the user (relative to self.included__absolute_path).
        # This can be used to know which files use this macro and where they are relative to this file.
        # May not be set if not applicable (for macros in the originally requested file it is None).
        self.included__used_by: Optional[str] = None

        # The opposite of self.included__used_by -> The relative path to THIS file from the file
        # that includes it.
        # This is useful for source maps, to know where the macro file lies relative to the original compiled file.
        self.included__relative_path: Optional[str] = None

    def build(self, op_idx_counter: Counter, lbl_idx_counter: Counter, parameters: Dict[str, SsbOpParam],
              smb: SourceMapBuilder) -> List[SsbOperation]:
        """
        Returns new built opcodes for this macro. SsbOpConstants in the blueprints, that have the names of variables,
        are replaced with the values from the parameter dict. The keys for the dict are the names of the variables,
        all must be defined.
        Also updates the source map with macro opcode / position mark entries.
        """
        # Check:
        for var_name in self.variables:
            if var_name not in parameters.keys():
                raise ValueError(f"Value for macro variable {var_name} not provided.")

        out_ops: List[SsbOperation] = []
        # Maps blueprint label ids to new actual labels
        new_labels: Dict[int, SsbLabel] = {}

        for blueprint_op in self.blueprints:
            if isinstance(blueprint_op, SsbLabel):
                if blueprint_op.id not in new_labels.keys():
                    # Copy the label with a new proper index
                    new_labels[blueprint_op.id] = SsbLabel(
                        lbl_idx_counter(), -1, blueprint_op.debugging_note
                    )
                    new_labels[blueprint_op.id].markers = blueprint_op.markers.copy()
                out_ops.append(new_labels[blueprint_op.id])
            elif isinstance(blueprint_op, SsbLabelJump):
                if blueprint_op.label.id not in new_labels.keys():
                    # Copy the label with a new proper index
                    new_labels[blueprint_op.label.id] = SsbLabel(
                        lbl_idx_counter(), -1, blueprint_op.label.debugging_note
                    )
                    new_labels[blueprint_op.label.id].markers = blueprint_op.label.markers.copy()
                new_root = self._build_op(op_idx_counter, blueprint_op.root, smb, parameters)
                new_jumps = SsbLabelJump(new_root, new_labels[blueprint_op.label.id])
                new_jumps.markers = blueprint_op.markers.copy()
                out_ops.append(new_jumps)
            else:
                out_ops.append(self._build_op(op_idx_counter, blueprint_op, smb, parameters))
        for pos_mark in self.source_map.get_position_marks__direct():
            smb.add_macro_position_mark(self.included__relative_path, self.name, pos_mark)
        # Also add the sub-macro position marks to the map
        for m in self.source_map.get_position_marks__macros():
            smb.add_macro_position_mark(*m)
        return out_ops

    def _build_op(self, op_idx_counter: Counter, blueprint_op: SsbOperation,
                  smb: SourceMapBuilder, params: Dict[str, SsbOpParam]):
        new_op_idx = op_idx_counter()
        # Maybe this op was also included through a macro, if so just relay the macro source map entry
        potential_macro_sm_entry = self.source_map.get_op_line_and_col__macros(blueprint_op.offset)
        if potential_macro_sm_entry:
            # If the file path was None in that entry, then it's OUR file. Correct the entry.
            file_path = potential_macro_sm_entry[0]
            if file_path is None:
                file_path = self.included__relative_path
            smb.add_macro_opcode(new_op_idx, file_path, *potential_macro_sm_entry[1:])
        else:
            # Nope, it wasn't:
            orig_ln, orig_col = self.source_map.get_op_line_and_col__direct(blueprint_op.offset)
            smb.add_macro_opcode(new_op_idx, self.included__relative_path, self.name, orig_ln, orig_col)
        return SsbOperation(
            new_op_idx, blueprint_op.op_code, self._process_parameters(blueprint_op.params, params)
        )

    def _process_parameters(self, original_params: List[SsbOpParam], macro_params: Dict[str, SsbOpParam]) -> List[SsbOpParam]:
        """
        Returns a copy of original_params,
        where SsbOpConstants that match keys of macro_params are
        replaced with the respective value from that dict.
        """
        new_params = []
        for p in original_params:
            if isinstance(p, SsbOpParamConstant):
                p_as_str = str(p)
                if p_as_str in macro_params:
                    new_params.append(macro_params[p_as_str])
                else:
                    new_params.append(p)
            else:
                new_params.append(p)
        return new_params
