"""Model representation of a single ExplorerScript macro function."""
#  MIT License
#
#  Copyright (c) 2020-2021 Parakoopa and the SkyTemple Contributors
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
from typing import Optional, List, Dict, Tuple

from explorerscript.source_map import SourceMap, SourceMapBuilder
from explorerscript.ssb_converting.compiler.utils import Counter
from explorerscript.ssb_converting.ssb_data_types import SsbOperation, SsbOpParam, SsbOpParamConstant, SsbOpCode
from explorerscript.ssb_converting.ssb_special_ops import SsbLabel, SsbLabelJump, OP_RETURN, OP_JUMP
from explorerscript.util import f, _


class MacroStartSsbLabel(SsbLabel):
    def __init__(self, id: int, routine_id: int, length_of_macro: int, parameter_mapping, debugging_note: str = None):
        super().__init__(id, routine_id, debugging_note)
        self.length_of_macro = length_of_macro
        self.parameter_mapping = parameter_mapping


class MacroEndSsbLabel(SsbLabel):
    pass


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

        # The relative path to this file from the file that includes it.
        # May not be set if not applicable (for macros in the originally requested file it is None).
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
                raise ValueError(f(_("Value for macro variable {var_name} not provided.")))

        # Macro callstack: Push our outer call
        len_real_ops_in_blueprints = len([o for o in self.blueprints if not isinstance(o, SsbLabel)]) + 1
        parameter_mapping = self._create_parameter_mapping(parameters)
        smb.macro_context__push(op_idx_counter.count + len_real_ops_in_blueprints, parameter_mapping)

        # Add the macro start label if we are processed later as a sub-macro, so that the parent macro can push
        # our ops to the callstack.
        out_ops: List[SsbOperation] = [MacroStartSsbLabel(
            lbl_idx_counter(), -1, len_real_ops_in_blueprints, parameter_mapping, f"Macro call {self.name} start label."
        )]

        # End label, also for sub-macros and when we are processing a return statement
        end_label = MacroEndSsbLabel(
            lbl_idx_counter(), -1, f"Macro call {self.name} end label."
        )

        # Maps blueprint label ids to new actual labels
        new_labels: Dict[int, SsbLabel] = {}

        for blueprint_op in self.blueprints:
            # If this a start / end of a macro, update the macro callstack
            if isinstance(blueprint_op, MacroStartSsbLabel):
                smb.macro_context__push(op_idx_counter.count + blueprint_op.length_of_macro,
                                        self._replace_in_param_mapping(blueprint_op.parameter_mapping, parameters))
            elif isinstance(blueprint_op, MacroEndSsbLabel):
                smb.macro_context__pop()

            if isinstance(blueprint_op, SsbLabel):
                if blueprint_op.id not in new_labels.keys():
                    # Copy the label with a new proper index
                    new_labels[blueprint_op.id] = self._copy_blueprint_label(
                        lbl_idx_counter, blueprint_op
                    )
                    new_labels[blueprint_op.id].markers = blueprint_op.markers.copy()
                out_ops.append(new_labels[blueprint_op.id])
            elif isinstance(blueprint_op, SsbLabelJump):
                if blueprint_op.label.id not in new_labels.keys():
                    # Copy the label with a new proper index
                    new_labels[blueprint_op.label.id] = self._copy_blueprint_label(
                        lbl_idx_counter, blueprint_op.label
                    )
                    new_labels[blueprint_op.label.id].markers = blueprint_op.label.markers.copy()
                new_root = self._build_op(op_idx_counter, blueprint_op.root, smb, parameters)
                new_jumps = SsbLabelJump(new_root, new_labels[blueprint_op.label.id])
                new_jumps.markers = blueprint_op.markers.copy()
                out_ops.append(new_jumps)
            elif blueprint_op.op_code.name == OP_RETURN:
                # Process return: Exit the macro instead
                replacement_blueprint_op = SsbOperation(blueprint_op.offset, SsbOpCode(-1, OP_JUMP), [])
                out_ops.append(SsbLabelJump(
                    self._build_op(
                        op_idx_counter, replacement_blueprint_op, smb, parameters
                    ), end_label
                ))
            else:
                out_ops.append(self._build_op(op_idx_counter, blueprint_op, smb, parameters))
        for pos_mark in self.source_map.get_position_marks__direct():
            smb.add_macro_position_mark(self.included__relative_path, self.name, pos_mark)
        # Also add the sub-macro position marks to the map
        for m in self.source_map.get_position_marks__macros():
            smb.add_macro_position_mark(*m)

        out_ops.append(end_label)

        # Macro callstack: Pop our return address
        smb.macro_context__pop()

        return out_ops

    def _build_op(self, op_idx_counter: Counter, blueprint_op: SsbOperation,
                  smb: SourceMapBuilder, params: Dict[str, SsbOpParam]):
        new_op_idx = op_idx_counter()
        # Maybe this op was also included through a macro, if so just relay the macro source map entry
        potential_macro_sm_entry = self.source_map.get_op_line_and_col__macros(blueprint_op.offset)
        if potential_macro_sm_entry:
            # If the file path was None in that entry, then it's OUR file. Correct the entry.
            file_path = potential_macro_sm_entry.relpath_included_file
            if file_path is None:
                file_path = self.included__relative_path
            # If the macro has a called_in field, add this to the current map with the correct data as well.
            if potential_macro_sm_entry.called_in:
                # Either our file called this...
                called_in_filename = self.included__relative_path
                if potential_macro_sm_entry.called_in[0] is not None:
                    # ... or the field was already set by another macro, we can just take it
                    called_in_filename = potential_macro_sm_entry.called_in[0]
                smb.next_macro_opcode_called_in(called_in_filename, *potential_macro_sm_entry.called_in[1:])
            smb.add_macro_opcode(new_op_idx, file_path,
                                 potential_macro_sm_entry.macro_name, potential_macro_sm_entry.line,
                                 potential_macro_sm_entry.column)
        else:
            # Nope, it wasn't:
            mapping = self.source_map.get_op_line_and_col__direct(blueprint_op.offset)
            smb.add_macro_opcode(new_op_idx, self.included__relative_path, self.name, mapping.line, mapping.column)
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

    def _create_parameter_mapping(self, parameters: Dict[str, SsbOpParam]):
        return {x: str(y) for x, y in parameters.items()}

    def _replace_in_param_mapping(self, parameter_mapping: Dict[str, Tuple[int, str]], our_parameters: Dict[str, SsbOpParam]):
        our_parameters = self._create_parameter_mapping(our_parameters)
        new_dict = {}
        for p_name, p_value in parameter_mapping.items():
            if p_value in our_parameters:
                new_dict[p_name] = our_parameters[p_value]
            else:
                new_dict[p_name] = p_value
        return new_dict

    def _copy_blueprint_label(self, lbl_idx_counter: Counter, blueprint_op: SsbLabel):
        if isinstance(blueprint_op, MacroStartSsbLabel):
            return MacroStartSsbLabel(
                lbl_idx_counter(), -1, blueprint_op.length_of_macro,
                blueprint_op.parameter_mapping,
                blueprint_op.debugging_note
            )
        elif isinstance(blueprint_op, MacroEndSsbLabel):
            return MacroEndSsbLabel(
                lbl_idx_counter(), -1, blueprint_op.debugging_note
            )
        else:
            return SsbLabel(
                lbl_idx_counter(), -1, blueprint_op.debugging_note
            )
