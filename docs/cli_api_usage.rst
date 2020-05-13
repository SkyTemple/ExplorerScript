CLI / API Usage
===============

In addition to the ExplorerScript specification, this repository also contains
a compiler and decompiler for Explorers of Sky's binary SSB scripts.

The (de)compiler works with structured components of the SSB scripts.
You will have to (dis)-assemble the SSB script using these components.

A reference implementation of the assembly process can be found in
`skytemple-files`_ (``script_compiler`` to create the model, ``writer`` to convert it
to binary).

This document mostly focuses on the CLI interface.

.. _skytemple-files: https://github.com/SkyTemple/skytemple-files/blob/master/skytemple_files/script/ssb

..  contents:: Index
    :depth: 3

SSB Data Structure
------------------
The compiler and decompiler work with a JSON-encoded structure to represent
the SSB data and settings. The decompiler takes it as input and the compiler
generates it as output.

General structure
~~~~~~~~~~~~~~~~~

.. code:: json

    {
        "settings": "<<SETTINGS>>",
        "routines": [{
            "type": "COROUTINE",
            "name": "NAME",
            "ops": ["<<OPERATION>>"]
        }, {
            "type": "GENERIC",
            "ops": ["<<OPERATION>>"]
        }, {
            "type": "ACTOR",
            "target_id": "<<ARG_INT or ARG_CONSTANT>>",
            "ops": ["<<OPERATION>>"]
        }]
    }

"routines" contains the routine specification. All routine types have
the "ops" field, which contains a list of SSB operations.
The ID of routines is the index in the list of routines.

Routine types
~~~~~~~~~~~~~

- COROUTINE: A coroutine, the name is in the "name" field.
- GENERIC: A simple generic routine.
- ACTOR: A routine for an actor, the target actor ID is in the "target_id" field and is either a string or integer argument data type.
- OBJECT: A routine for an object, see notes for ACTOR.
- PERFORMER: A routine for a performer, see notes for ACTOR.

Structure of settings
~~~~~~~~~~~~~~~~~~~~~
Contains an object with the following fields:

- "performance_progress_list_var_name": The constant used for the variable
  PERFORMANCE_PROGRESS_LIST.
- "dungeon_mode_constants": The constants that should be used for the dungeon mode states. This is an object::

  {"open": "DMODE_OPEN", "closed": "DMODE_CLOSED", "request": "DMODE_REQUEST", "open_request": "OPEN_AND_REQUEST"}

Structure of operations
~~~~~~~~~~~~~~~~~~~~~~~
An operation is an object with the following structure:

- "opcode": Name of the opcode to use (string).
- "params": A list of arguments, as described by "Argument types".

The index of the operations in the operation list is the opcode offset
plus the length of all previous routines. An assembler might need
to convert those offsets to proper binary offsets!

The indices start at 1!

Argument types
~~~~~~~~~~~~~~

Integer
#######
Is encoded as an integer.

Constant
########
Is encoded as a JSON object with "type" being "CONSTANT"
and the "value" field being the constant name.

.. code:: json

    {
        "type": "CONSTANT",
        "value": "LEVEL_XYZ"
    }

(Const) String
##############
Is encoded as a JSON object with "type" being "CONST_STRING"
and the "value" field being the string.

.. code:: json

    {
        "type": "CONST_STRING",
        "value": "Hello World"
    }

Language String
###############
Is encoded as a JSON object with "type" being "LANG_STRING"
and the keys of the object under "value"
being the language names and the values the string values.

.. code:: json

    {
        "type": "LANG_STRING",
        "value": {
            "english": "Hello World!",
            "german": "Hallo Welt!"
        }
    }

Position Mark
#############
Is encoded as a JSON object with "type" being "POSITION_MARK"
and the keys of the object under "value" being the data of the mark.

.. code:: json

    {
        "type": "POSITION_MARK",
        "value": {
            "name": "Name of the mark",
            "x": 10,
            "y": 20
        }
    }

Best practices for constants
----------------------------
If you are using the compiler for Explorers of Sky, you
should use the same prefixes SkyTemple uses for constants:

+-----------------+-------------------+--------------------------------------------------------------------------+
| Type            | Prefix            | Notes                                                                    |
+=================+===================+==========================================================================+
| Direction       | DIRECTION\_       | Uppercased, camel case replaced with _.                                  |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Special Process | PROCESS_SPECIAL\_ | Uppercased.                                                              |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Menu            | MENU\_            | Uppercased.                                                              |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Level           | LEVEL\_           | Uppercased.                                                              |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Face Position   | FACE_POS\_        | Uppercased.                                                              |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Face ID         | FACE              | Uppercased.                                                              |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Object          | OBJECT\_          | The object name is uppercased and the ID is suffixed: OBJECT_D01P11B2_12 |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Actor           | ACTOR\_           |                                                                          |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Coroutine       | CORO\_            |                                                                          |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Game Variable   | $                 |                                                                          |
+-----------------+-------------------+--------------------------------------------------------------------------+
| Dungeon Mode    | DMODE\_           | OPEN / CLOSED / REQUEST / OPEN_AND_REQUEST                               |
+-----------------+-------------------+--------------------------------------------------------------------------+

This guarantees maximum compatibility between different tools.

Decompiling
-----------
To decompile run the CLI module like so:

``python3 -m explorerscript.cli.decompile ssb_model.json``

Where ``ssb_model`` is the path to the JSON SSB model, including settings,
as described above.

You can specify the ``--source-map filename.exps.sm`` parameter to
output a source map at the given location.

The ExplorerScript source code is printed on stdout. Errors are printed on stderr. If
the process exits with exit code 0, it's successful.

Compiling
---------
To compile run the CLI module like so:

``python3 -m explorerscript.cli.compile source_file.exps --settings settings.json``

Where ``source_file.exps`` is the path to the ExplorerScript source
file and ``settings.json`` is the path to a JSON file, that contains
at least the settings block as described above.

You can specify the ``--source-map filename.exps.sm`` parameter to
output a source map at the given location.

You can specify the ``--lookup PATH`` parameter to specify lookup paths.
It can be added multiple times, for multiple lookup paths.

The SSB JSON is printed on stdout. Errors are printed on stderr. If
the process exits with exit code 0, it's successful.

Compiling an example
--------------------

Compiling the source code in the ``example`` directory::

  python -m explorerscript.cli.compile example/SCRIPT/base.exps --settings /tmp/settings.json --lookup example/macros

With ``/tmp/settings.json`` having the following content:

.. code:: json

    {
      "settings": {
        "performance_progress_list_var_name": "$PERFORMANCE_PROGRESS_LIST",
        "dungeon_mode_constants": {
          "open": "DMODE_OPEN",
          "closed": "DMODE_CLOSED",
          "request": "DMODE_REQUEST",
          "open_request": "OPEN_AND_REQUEST"
        }
      }
    }


Output:

.. code:: json

    {
      "settings": {
        "performance_progress_list_var_name": "$PERFORMANCE_PROGRESS_LIST",
        "dungeon_mode_constants": {
          "open": "DMODE_OPEN",
          "closed": "DMODE_CLOSED",
          "request": "DMODE_REQUEST",
          "open_request": "OPEN_AND_REQUEST"
        }
      },
      "routines": [
        {
          "type": "GENERIC",
          "ops": [
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "Before Macro"
                }
              ]
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "Begin LocalMacro"
                }
              ]
            },
            {
              "opcode": "vars",
              "params": [
                {
                  "type": "POSITION_MARK",
                  "value": {
                    "name": "PositionName",
                    "x": "10",
                    "y": "10.5"
                  }
                },
                2,
                3,
                {
                  "type": "CONST_STRING",
                  "value": "String"
                }
              ]
            },
            {
              "opcode": "vars_in_remote_macro",
              "params": [
                2,
                {
                  "type": "CONST_STRING",
                  "value": "String"
                },
                {
                  "type": "CONSTANT",
                  "value": "$notAvailable"
                }
              ]
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "BELOW IS A TEST RETURN"
                }
              ]
            },
            {
              "opcode": "BranchValue",
              "params": [
                {
                  "type": "CONSTANT",
                  "value": "$TEST_VAR"
                },
                4,
                3,
                8
              ]
            },
            {
              "opcode": "Jump",
              "params": [
                10
              ]
            },
            {
              "opcode": "print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "The variable is smaller"
                }
              ]
            },
            {
              "opcode": "Jump",
              "params": [
                11
              ]
            },
            {
              "opcode": "vars_in_remote_macro2",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "from remote_macro"
                },
                {
                  "type": "CONST_STRING",
                  "value": "String"
                },
                {
                  "type": "CONSTANT",
                  "value": "$notAvailable"
                }
              ]
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "REMOTE2 SHOULD END HERE"
                }
              ]
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "macro_in_macros_2"
                }
              ]
            },
            {
              "opcode": "NUMBER_TWO_im_in_macros_2",
              "params": []
            },
            {
              "opcode": "NUMBER_ONE_im_in_macros_2",
              "params": []
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "End LocalMacro"
                }
              ]
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "Begin LocalMacro"
                }
              ]
            },
            {
              "opcode": "vars",
              "params": [
                10,
                9,
                8,
                {
                  "type": "CONST_STRING",
                  "value": "Another one"
                }
              ]
            },
            {
              "opcode": "vars_in_remote_macro",
              "params": [
                9,
                {
                  "type": "CONST_STRING",
                  "value": "Another one"
                },
                {
                  "type": "CONSTANT",
                  "value": "$notAvailable"
                }
              ]
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "BELOW IS A TEST RETURN"
                }
              ]
            },
            {
              "opcode": "BranchValue",
              "params": [
                {
                  "type": "CONSTANT",
                  "value": "$TEST_VAR"
                },
                4,
                3,
                22
              ]
            },
            {
              "opcode": "Jump",
              "params": [
                24
              ]
            },
            {
              "opcode": "print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "The variable is smaller"
                }
              ]
            },
            {
              "opcode": "Jump",
              "params": [
                25
              ]
            },
            {
              "opcode": "vars_in_remote_macro2",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "from remote_macro"
                },
                {
                  "type": "CONST_STRING",
                  "value": "Another one"
                },
                {
                  "type": "CONSTANT",
                  "value": "$notAvailable"
                }
              ]
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "REMOTE2 SHOULD END HERE"
                }
              ]
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "macro_in_macros_2"
                }
              ]
            },
            {
              "opcode": "NUMBER_TWO_im_in_macros_2",
              "params": []
            },
            {
              "opcode": "NUMBER_ONE_im_in_macros_2",
              "params": []
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "End LocalMacro"
                }
              ]
            },
            {
              "opcode": "debug_Print",
              "params": [
                {
                  "type": "CONST_STRING",
                  "value": "After Macro"
                }
              ]
            }
          ]
        },
        {
          "type": "ACTOR",
          "target_id": "TEST",
          "ops": [
            {
              "opcode": "test_actor",
              "params": []
            }
          ]
        },
        {
          "type": "ACTOR",
          "target_id": 2,
          "ops": [
            {
              "opcode": "test_actor_id",
              "params": []
            }
          ]
        }
      ]
    }

Python API
----------

The Python API mostly works the same way as the CLI interface.

However the settings are provided as arguments to the compiling/decompiling
classes and the routine data is split into three separate lists:

- Named coroutines: The names of the coroutines on the indexed position, None
  for all regular routines.
- Routine Info: ``SsbRoutineInfo`` objects describing the type and target of the routine.
- Routine Ops: A list of ``SsbOperation``. Each operation has a named opcode
  with it's ID field being ignored (-1 generated by compiler). The parameter
  list contains objects of the types described by ``SsbOpParam``, they correspond
  to the JSON types described above.

The indices of the lists are the routine IDs.

The compiler is at ``explorerscript.ssb_converting.ssb_compiler.ExplorerScriptSsbCompiler``
and the decompiler at ``explorerscript.ssb_converting.ssb_decompiler.ExplorerScriptSsbDecompiler``.
