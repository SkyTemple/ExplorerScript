Source Maps
===========

The ExplorerScript (de)compiler implementation for Explorers of Sky
also create source maps. These can be used for debugging. The
`SkyTemple Script Engine Debugger`_ uses them.

Source Maps map the binary offsets of operations in a SSB model to
ExplorerScript source files (including line number and column).

.. _SkyTemple Script Engine Debugger: https://github.com/SkyTemple/skytemple-ssb-debugger

This documents the structue of these source maps.

They are serialized as JSON, documented is the serialized form.
The `Python model`_ is not documented here, but it should be clear how it works
from the JSON descriptions. The module that this model is in also contains
a builder class, to generate new source maps.

.. _Python model: https://github.com/SkyTemple/ExplorerScript/blob/master/explorerscript/source_map.py

Opcode Mappings
---------------
"map":

An object where the keys are the offsets of the opcodes and the values are a list (tuple)
with the following fields:

- Line number in source file
- Column number in source file

Position Marks
--------------
"pos_marks":

For introspection position marks are also written to the source map. A list of
lists (tuples) with the following fields:

- Line number in source file
- Column number in source file
- Argument index of the operation that the position mark is used in
- Name of the mark
- X offset value (2 or 4 when +0.5 should be added to the position)
- Y offset value (2 or 4 when +0.5 should be added to the position)
- X position without the offset
- Y position without the offset

Macro Opcode Mappings
---------------------
"marcos"."map":

Mapping of an opcode offset to an operation defined in a macro. List (tuple) with
the following fields:

- Path to the source file the macro was defined in, null if it's the base file (not imported).
  Relative to the base source file.
- Name of the macro.
- Line number in source file
- Column number in source file
- Calling information as tuple, if applicable, else null. See below.
- Return address, see below.
- Parameter mapping, see below.

Call information
################
If the opcode is the first opcode of a macro call, then this tuple contains
the information about where this macro was called:

- Path to the source file the macro was called in, null if it's the base file (not imported).
  Relative to the base source file.
- Line number in source file
- Column number in source file

Return Address
##############
This field contains the first opcode address after the macro call has ended.
This can be used for "stepping out" of a macro call in a debugger.

Parameter Mapping
#################
An object that has the parameter names as keys and the effective values as
values. This is for informational display / debugging only, the representation
of the argument types may be arbitrary.

Macro Position Marks
--------------------
"marcos"."pos_marks":

Position marks defined in macros. A list (tuple) with the following fields:

- Path to the source file the macro was defined in, null if it's the base file (not imported).
  Relative to the base source file.
- Name of the macro.
- A tuple as described under "Position Marks".

Remapping
---------
The compiler in this repository uses offsets relative to the number of the
operation in the generated operations list. If you use an assembler to convert
this into binary SSB, you need to remap the values for the offsets using the
method ``rewrite_offsets`` on the Python source map model.

Inclusion Maps
--------------
In addition to the source maps, ExplorerScript can also provide data
for generating inclusion maps. An inclusion map should be a file with one
JSON array in it, that contains strings for all SSB files that are affected
by this file, eg. all files that import it.

To generate these maps, the `IncludedUsageMap`_ class can be used. For a ExplorerScript
file it generates a list of all files that import it. Using this information you can
update the inclusion maps of all of those files.

.. _IncludedUsageMap: https://github.com/SkyTemple/ExplorerScript/blob/master/explorerscript/included_usage_map.py

`SkyTemple Script Engine Debugger`_ generates inclusion maps using this format.
The debugger only creates these maps for it's ExplorerScript macro files.
