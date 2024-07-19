ExplorerScript language specification
=====================================

This document contains the language specification for
ExplorerScript. ExplorerScript is a scripting language
that can be converted into the SSB script files of
Pokémon Mystery Dungeon Explorers of Sky. The language
is more flexible though, it can in it's core also be used
for other games or purposes.

The lexer and parser specifications can be found in the
``explorerscript.antlr`` package as an Antlr 4 grammar.

.. admonition:: EoS Compiler

   These blocks are used in the document to document things
   specific to the decompiler / compiler that are contained
   in this repository, they are specific to Explorers of Sky.

.. admonition:: SkyTemple

   These blocks contain notes on how the components of the
   `SkyTemple`_ project implement certain things.

   We recommend any tool that works with EoS to try to be comaptible
   with the SkyTemple implementation.

.. _`SkyTemple`: https://github.com/SkyTemple

Routines
--------
Every script file contains a collection of routines (and/or macros).

A routine contains a set of statements.

Coroutine
~~~~~~~~~
A coroutine is a named routine and is meant to be used
as a common routine used by other scripts.

The behaviour for having coroutines and other routines
in the same file is currently undefined.

.. code:: ExplorerScript

    coro NAME {
        /** Statements **/
    }

.. admonition:: SkyTemple

   A script file that contains coroutines can not contain any
   other routines. It must contain all of the coroutines that
   are specified in the game's list of coroutines. The only
   compiled script file that usually contains coroutines is
   ``SCRIPT/COMMON/unionall.ssb``. Operations exist to call
   coroutines.

Generic Routine
~~~~~~~~~~~~~~~
A generic routine, that has an ID. If a script file contains
routines their index must start at 0 and increment by one, there
must not be a gap.

.. code:: ExplorerScript

    def 1234 {
        /** Statements **/
    }

Targeted Routine
~~~~~~~~~~~~~~~~
A routine for an actor (``for actor``), an object (``for object``) or a performer (``for performer``) and an ID.

As identifiers for the actors, objects and performers any constant or integer can be used.

.. code:: ExplorerScript

    def 1234 for actor ACTOR_PLAYER {
        /** Statements **/
    }

Aliases
~~~~~~~
Instead of containing statements, a routine can contain the
keyword ``alias previous;``. It will then use the same operations
as the routine before it (by index number). In case of coroutines
the assembler decides what the routine before it is, based on an
index of names.


.. code:: ExplorerScript

    def 0 {
        /** Statements **/
    }

    def 1 {
        alias previous;
        /** Will use statements from def 0 **/
    }

Data Types
----------
ExplorerScript defines different data types. These are described below.

Integer
~~~~~~~
A whole number. The size of the integer is not restricted by the
language. Integers can be represented in different bases.

.. code:: ExplorerScript

    12      // base 10 (decimal)
    -12     // negative base 10
    0x12    // base 16 (hexadecimal)
    0o7     // base 8 (octal)
    0b110   // base 2 (binary)

.. admonition:: SkyTemple

   All integers are 15-bit signed integers.

Fixed Point Value
~~~~~~~~~~~~~~~~~
A non-integer number with decimal places. The size of the number is not restricted by the
language. Currently all fixed point values need to be written in base 10.

The language does not restrict the compiler to use actual fixed point values, the compiler may also store
them as floats, etc. Likewise the compiler does not guarantee any promises about the precision of the
compiled values. The compiler may error if a value can not be represented.

.. code:: ExplorerScript

    .12
    1.12
    -.12
    -1.12

.. admonition:: SkyTemple

   Valid value ranges are ~-64.0 - 63.996. Decimal values are rounded to the nearest 1/256 increment.
   This means the lowest values for decimal places is 0, the highest is ~.996 and precision for increments is ~.0039.

System Constants
~~~~~~~~~~~~~~~~
A system constant is a stand-in for an integer.
Their names are usually in uppercase.

.. admonition:: SkyTemple

    Variables that are used by the debugger are also actually
    system constants that represent a number! For example ``$SCENARIO_MAIN``
    is actually just a constant containing the number of a variable.
    This is because the conditional and assigment statements don't
    actually work with variables, they require the ID of variables
    instead.

    Please see the note and example on "Conditional check" for
    "if-Blocks".

    For a list of common constant prefixes, see the document
    on the CLI interface.

(Constant) Strings
~~~~~~~~~~~~~~~~~~
A simple string literal that has no translations available.

It may be a single line string, enclosed in single- or double quotes.

.. code:: ExplorerScript

    // Single quotes string:
    'Hello World'
    // Double quotes string:
    "Hello World"

A single line string may contain ``\n`` to insert a newline in the resulting text.

A string literal may also be a multi line string, which is indicated by three quote characters (``'''`` or ``"""``).

.. code:: ExplorerScript

    """
    This is a multiline string.
    It can span multiple lines.
    """

New lines in a multi line string are kept and indentations (whitespace characters before the first non-whitespace
character in a line) are stripped in a way that makes writing these strings convenient:

- The indentation in the first line of the string literal (after the starting three quote characters) is preserved.
- The indentation in the last line of the string literal is fully removed if it only consists of whitespace characters.
- For all other lines, the least indentation among all of these lines is calculated and then the lines are dedented
  by that amount. If the last line does not fully consist of whitespace characters, this also applies to it.

If the first or last line would be empty after applying the rules above, they are removed from the resulting string.

Given this single line string literal...:

.. code:: ExplorerScript

    "First Line\nSecond Line\n  Some indentation in the third line\nFourth Line"

... all of these multi line string literals would be equivalent to it:

.. code:: ExplorerScript

    '''First Line
      Second Line
        Some indentation in the third line
      Fourth Line
                  '''

    """
      First Line
      Second Line
        Some indentation in the third line
      Fourth Line"""

``\n`` in multiline strings are kept as is, they are not converted to new lines.

Language Strings
~~~~~~~~~~~~~~~~
A collection of strings for different languages. It must have
at least one string defined. A language string's value can be a
single line or a multi line string literal, see above.

.. code:: ExplorerScript

    {
        languageA='String for lang A',
        languageB="String for lang B",
        languageC="""
          String for lang C
          on multiple lines
        """
    }

.. admonition:: SkyTemple

    What languages are required depends on the ROM. Either only
    one of the languages supported must be specified, or all of them.
    If only one is specified, it is also used for the other languages.

Position Marks
~~~~~~~~~~~~~~
Position marks mark a place on the map. They have a name (string literal)
and two position attributes for X and Y position. In addition these
attributes can have the suffix '.5' to place the position marks between
two coordinates.

.. code:: ExplorerScript

    Position<'Name', 20, 20.5>

.. admonition:: SkyTemple

    In SSB files Position marks are actually 4 parameters:

    - X Offset: 2 or 4 if the x position ends on '.5', otherwise 0.
    - Y Offset: 2 or 4 if the x position ends on '.5', otherwise 0.
    - X Position: The x position, with the decimal place stripped.
    - Y Position: The y position, with the decimal place stripped.

    The coordinates are in tiles.

Statements and Blocks
---------------------

Labels
~~~~~~
A label marks a statement that can be jumped to. Using the ``jump``
control statement you can make the execution jump to these statements.
A statement can be marked with multiple labels.

.. code:: ExplorerScript

    @hello_label;
    operation();

    @another_label;
    @and_another_one;
    another_operation();

.. admonition:: SkyTemple

    ``§label;`` can be used instead of ``@label;`` for backwards
    compatibility. You should use ``@label;`` in new scripts.

Control statements
~~~~~~~~~~~~~~~~~~
Control statements have special meaning to the control flow
of a script.

.. warning::
    The specfication of ``end``, ``hold`` and ``return``
    are based on the EoS SSB operations of the same name. The
    descriptions are speculations based on observed behaviour.

``end``
#######
Ends the script execution. Get's compiled as an instruction.

.. admonition:: EoS Compiler

   Compiles to an ``End`` operation.

``hold``
########
Ends the current script execution and holds it, waiting for
something external to cause a new instruction.
Get's compiled as an instruction.

.. admonition:: EoS Compiler

   Compiles to a ``Hold`` operation.

``return``
##########
If used in a macro ends the macro and resumes script execution
after the macro call.

If not used in a macro either returns from a coroutine or act's
the same as ``end``.

.. admonition:: EoS Compiler

   If used in a macro, a ``Jump`` operation is generated
   to the end of a macro call.
   Otherwise compiles to a ``Return`` operation.

``break``
#########
Can only be used in case-Blocks of switches.

Ends the case-Block and jumps to the end of the switch-Block.

``continue``
############
Can only be used in forever-Blocks, for-Blocks and while-Blocks.

Ends the current iteration of the loop and jumps back to the
beginning. In the case of while- and for-Loops the condition is
checked again, for for-loops the increment operation is run before.

``break_loop``
##############
Can only be used in forever-Blocks, for-Blocks and while-Blocks.

Exits the current loop and jumps to the end of the loop block.

``jump``
########
Jumps to a label.

.. code:: ExplorerScript

    // This will execute operation() in an endless loop.
    @hello_label;
    operation();
    jump @hello_label;

with-Blocks
~~~~~~~~~~~
Runs a statement in the context of an actor, an object or
a performer. Only simple statements are allowed, no blocks
or labels.
The keywords ``actor``, ``object`` or ``performer`` can be used
to specify the type. As identifiers for their IDs integers and
constants can be used.
``with`` blocks can contain multiple operations for convenience,
but unlike code in targeted routines, operations in the block are
not executed concurrently.

.. code:: ExplorerScript

    with (actor ACTOR_HELLO_WORLD) {
        operation1();
        operation2();
    }

if-Blocks
~~~~~~~~~
A conditional block. One or more conditions are checked and
if they are true, a block of code is executed.

An if-Block an also be extended with ``elseif`` statements
to specify alternative conditions and blocks and/or a single ``else``
block, that will be executed when neither the ``if`` conditions nor any
of the ``elseif`` conditions apply.

Conditions specifications for ``if`` and ``elseif`` can contain
a list of conditions as described below. These can be combined
with ``||``. If any of the conditions apply, the block is executed.

There is no syntax to specify that multiple conditions must apply ("and").
Use nested if-Blocks for this.

If conditions can be negated as a whole, by using the keyword ``not``.

.. code:: ExplorerScript

    if (CONDTION || CONDITION) {
        /** Statements **/
    } elseif not (CONDTION) {
        /** Statements **/
    } else {
        /** Statements **/
    }

if-Conditions
#############

Conditional check
.................
A simple conditional check, that checks if the first field
of a variable (identified by an integer or constant) matches a value
as specfied by the operator.

The value to compare against can be the value of a variable. In this
case ``value(X)`` must be used, where ``X`` is the id of the variable
to compare against.

.. code:: ExplorerScript

    if (VAR_A < 3) {}
    if (4 < 3) {}  // !!This checks if the variable with ID 4 is < 3!!
    if ($A == 3 || $A > value($B)) {}
    if ($VAR1 >= value(3)) {} // !! This checks if $VAR1 >= the variable with ID 3 !!

.. admonition:: SkyTemple

   As noted earlier, SkyTemple uses the ``$`` prefix
   for variable constants. We recommend only using this prefix.
   The rest of the documentation will use this prefix for everything
   related to variables.

.. admonition:: EoS Compiler

   If ``value(X)`` is used, this is compiled as a ``BranchVariable`` operation.
   Otherwise, if the operator is not ``==``, this is compiled as a ``BranchValue`` operation.
   Otherwise it is compiled as a ``Branch`` operation.

Bit check
.........
Checks if a bit in a bitfield variable is set. If the compiler
supports it, ``not`` can be used to check if the field is not set instead.

.. code:: ExplorerScript

    if (VAR_A[3]) {}
    if (not VAR_A[3]) {}
    if not (not VAR_A[3]) {} // Same as if (VAR_A[3]) {}

.. admonition:: EoS Compiler

   If the variable is the game variable ``PERFORMANCE_PROGRESS_LIST`` (see CLI docs),
   this gets compiled as a ``BranchPerformance``

   Else it gets compiled as ``BranchBit``.

   The ``not`` keyword is only allowed for ``PERFORMANCE_PROGRESS_LIST``!

Scenario check
..............
Checks the two fields of a scenario variable against a conditional
operator. Both values compared against must match the conditional operator.
As conditional operators only ``==,<,>,<=,>=`` can be used.

.. code:: ExplorerScript

    if (scn($SCENARIO_MAIN) > [30, 2]) {
        /** This only gets executed when
            field 0 of the variable is > 30 and
            field 1 of the variable is > 2 **/
    }

.. admonition:: EoS Compiler

   Depending on the operator, this gets compiled to
   ``BranchScenarioNow``, ``BranchScenarioNowAfter``, ``BranchScenarioNowBefore``,
   ``BranchScenarioAfter``, or ``BranchScenarioBefore``.

Special conditions
..................
Some special keywords can be checked against. All of these can
be negated using the keyword ``not``:

- debug: Branches if the debug mode is enabled.
- edit: Unknown, not implemented?
- variation: Branches if the ROM is a demo ROM.

.. admonition:: EoS Compiler

   These get compiled to ``BranchDebug``, ``BranchEdit`` and
   ``BranchVariation`` respectively.

.. admonition:: SkyTemple

   In the SkyTemple Script Engine Debugger, the debug mode
   can be enabled with the checkbox "Enable Debugging Mode".

Operations as conditions
........................
Any operations supported by the compiler may also be used as
if-Conditions.

.. admonition:: EoS Compiler

   The compiler supports no operations as if-Conditions.

switch-Blocks
~~~~~~~~~~~~~
(This works like switches in most programming languages).

Switch blocks have a switch-Header, which is a condition that
a set of case-Blocks check against.

Each case-Block has a case-Header with it's condition to check against
and a set of instructions. If the end of a case-Block's body is reached,
it will continue executing the next case body will be executed. The
execution of a case-Block can be stopped with the ``break`` statement.

A switch can have a ``default`` case, that gets executed when no
other case matches.

.. code:: ExplorerScript

    switch (SWITCH_HEADER) {
        CASE_HEADER:
            statement1;
            statement2;
            // Will continue with next block, beause no break.
        CASE_HEADER:  // Case headers can be combined like this.
        CASE_HEADER:
            statement1;
            statement2;
            break; // Will not continue with next block.
        CASE_HEADER:
        default:
            statement1;
            statement2;
    }

switch-Headers
##############

Variable
........
The cases of this switch check against the value of a variable
identified by the integer or constant provided.

.. code:: ExplorerScript

    switch($VAR) { /* ... */ }

.. admonition:: EoS Compiler

   Get's compiled as a ``Switch`` operation.

Scenario
........
The cases check the first field of a scenario variable. This is
effectively the same as the normal variable switch header.

.. code:: ExplorerScript

    switch(scn($VAR)) { /* ... */ }

.. admonition:: EoS Compiler

   Get's compiled as a ``SwitchScenario`` operation.

Random
......
The cases check against a randomly generated number. The value
in parenthesis is the upper bound of that number, the lower bound
is 0.

.. code:: ExplorerScript

    switch(random(1234)) { /* ... */ }

.. admonition:: EoS Compiler

   Get's compiled as a ``SwitchRandom`` operation.

Dungeon Mode
............
The cases check against the dungeon mode of a dungeon identified
by the integer or constant provided.

.. code:: ExplorerScript

    switch(dungeon_mode(DUNGEON_ABC)) { /* ... */ }

.. admonition:: EoS Compiler

   Get's compiled as a ``SwitchDungeonMode`` operation.

Sector
......
The cases check against whether or not a sector (or layer)
of the active scene is activated.

.. code:: ExplorerScript

    switch(sector()) { /* ... */ }

.. admonition:: EoS Compiler

   Get's compiled as a ``SwitchSector`` operation.

Operations as switch headers
............................
Operations that are supported by the compiler can also be used
as headers for switches.

.. admonition:: EoS Compiler

   The compiler supports all operations as switch headers, although
   please note, that it doesn't make sense to run all operations
   as such.

case-Headers
############

Value
.....
Check that the value provided by the switch header matches a value.

.. code:: ExplorerScript

    case 9:

.. admonition:: EoS Compiler

   This gets compiled as a ``Case`` operation.

Check against operator
......................
Check that the value provided by the switch header matches
a conditional operator and a value. ``value(X)`` can be used, to check
against the value of variable, specified by the integer or constant X,
instead.

.. code:: ExplorerScript

    case > 9:
    case == 12:
    case FALSE 3:
    case < value($VAR_TEST):

.. admonition:: EoS Compiler

   If ``value(X)`` is used, this gets compiled as a ``CaseVariable``
   operation. Else it gets compiled as a ``CaseValue`` operation.

Menu
....
Check that the value provided matches the index number of the string
of this case.

.. code:: ExplorerScript

    case menu("Hello"):
    case menu({
        english="Yes",
        french="Oui",
        german="Ja",
        italian="Sì",
        spanish="Sí",
    }):

.. admonition:: EoS Compiler

   Usually used with ``message_SwitchMenu``. This gets compiled
   as ``CaseMenu``.

Menu 2
......
Check that the value provided matches the index number of a special
menu option identified by an integer or constant.

.. code:: ExplorerScript

    case menu2(3):

.. admonition:: EoS Compiler

   Usually used with ``message_SwitchMenu``. This gets compiled
   as ``CaseMenu2``.

Message Switches
~~~~~~~~~~~~~~~~
Message switches check against a value to see what message to display.

The begin with either ``message_SwitchTalk`` or ``message_SwitchMonologue``.

As case-Header only "Value" headers are allowed. Instead of statements
the bodies of case-Blocks contain a single string.

.. code:: ExplorerScript

    message_SwitchTalk ($PARTNER_TALK_KIND) {
        case 1:
            " Oh, wow! What a pretty sight!"
        case 2:
            {
                english=" Oh, wow! What a pretty sight!"
            }
        default:
            {
                english=" Wow! What a beautiful sight!"
            }
    }

.. admonition:: EoS Compiler

   The switch statements get compiled as either ``message_SwitchTalk`` or ``message_SwitchMonologue``.
   The cases get compiled as ``CaseText`` and the default case gets compiled as ``DefaultText``.

forever-Loops
~~~~~~~~~~~~~
The statements in this block will loop forever,
unless broken out of using ``break_loop``.

.. code:: ExplorerScript

    forever {
        operation1();
        operation2();
        // Will repeat at beginning again.
    }

for-Loops
~~~~~~~~~
(Works like for-Loops in other programming languages).

Executes code until a condition is no longer met. Has an
initializing statement and an incrementing statement that is run
every iteration of the loop.

The for loop has the following syntax:

.. code:: ExplorerScript

    for (initial; condition; increment;) {
      /* Statements */
    }

"initial" is executed (one time) before the execution of the
code block. Any simple statement is allowed.

"condition" defines the condition for executing the code block.
Any if-Header is allowed (no "||").

"increment" is executed (every time) after the code block has
been executed, including when ``continue`` is used. Any simple statement is allowed.

while-Loops
~~~~~~~~~~~
(Works like while-Loops in other programming languages).

Loops until a condition is no longer true. Any if-Header
condition is allowed (no "||").

.. code:: ExplorerScript

    while (condition;) {
      /* Statements */
    }

.. admonition:: EoS Compiler

   The switch statements get compiled as either ``message_SwitchTalk`` or ``message_SwitchMonologue``.
   The cases get compiled as ``CaseText`` and the default case gets compiled as ``DefaultText``.


Assignments
~~~~~~~~~~~
Statements to assign values to variables (identified by integers or
constants).

.. warning::

   Assignments can NOT be used to assign values to macro variables.
   Game variables and macro variables are fundamentally different,
   please also see the section on macro variables.

   If you use a macro variable as the variable in an assignment,
   the variable with the ID of the macro variables current content
   will be set. In the following example ``$SCENARIO_MAIN`` will be set
   to 3.

    .. code:: ExplorerScript

        macro example(%var) {
            %var = 3; // $SCENARIO_MAIN is now 3.
        }

        def 0 {
            ~example($SCENARIO_MAIN);
        }

Simple
######
Assign a integer value or the value of another variable (with ``value(X)``)
to a variable. How the assignment is done depends on the assignment
operator used.

.. code:: ExplorerScript

    $VAR = 3;
    $VAR = value(3);
    $VAR += 3;

.. admonition:: EoS Compiler

   If ``value(X)`` is used, this gets compiled as ``flag_CalcVariable``.
   Else if, an assigment operator other than ``=`` is used, this gets compiled as ``flag_CalcValue``.
   Else, this gets compiled as ``flag_Set``.

Bit-Set
#######
Set a bit field in a bitfield variable.

Only 0 and 1 are allowed as values.

.. code:: ExplorerScript

    $VAR[3] = 1;

.. admonition:: EoS Compiler

   If the variable is the game variable ``PERFORMANCE_PROGRESS_LIST`` (see CLI docs),
   this gets compiled as a ``flag_SetPerformance``

   Else it gets compiled as ``flag_CalcBit``.

Scenario
########
Set's the two fields of a scenario variable

.. code:: ExplorerScript

    $VAR = scn[1, 2];

.. admonition:: EoS Compiler

   This gets compiled as ``flag_SetScenario``.

Clear
#####
Clears a variable (TODO: What exactly happens is not clear).

.. code:: ExplorerScript

    clear $VAR;

.. admonition:: EoS Compiler

   This gets compiled as ``flag_Clear``.

Reset
#####
Resets a scenario variable or the dungeon result
(TODO: What exactly happens is not clear).

.. code:: ExplorerScript

    reset $VAR;
    reset dungeon_result;

.. admonition:: EoS Compiler

   This gets compiled as ``flag_Reset`` or ``flag_ResetDungeonResult``.

Initial
#######
Set's a variable to it's initial value
(TODO: What exactly happens is not clear).

.. code:: ExplorerScript

    init $VAR;

.. admonition:: EoS Compiler

   This gets compiled as ``flag_Initial``.

Adventure Log
#############
Set's a value of the adventure log. Only ``=`` is allowed.

.. code:: ExplorerScript

    adventure_log = 3;

.. admonition:: EoS Compiler

   This gets compiled as ``flag_SetAdventureLog``.

Dungeon Mode
############
Set's the dungeon mode of a dungeon with it's ID specfied
by an integer or constant.

.. code:: ExplorerScript

    dungeon_mode(3) = 3;
    dungeon_mode(4) = DMODE_OPEN;

.. admonition:: EoS Compiler

   This gets compiled as ``flag_SetDungeonMode``.

Operations
~~~~~~~~~~
An operation can be any valid identifier and a list
of arguments. The arguments can have any data type.

The compiler usually compiles these directly as the specified
operations, it may raise errors for unknown operations.


.. code:: ExplorerScript

    MyOperation(3, "String", Position<'Name', 20, 20.5>);

Optionally, you may also pass a context (actor, object or
performer) to run the operation in.


.. code:: ExplorerScript

    MyOperation<actor ACTOR_HELLO_WORLD>(3, "String", Position<'Name', 20, 20.5>);

.. admonition:: SkyTemple

   A list of operations supported by Explorers of Sky
   can be found on this `Wiki page`_.
   Feel free to extend the list. Some of the opcodes are reserved
   for ExplorerScript specific syntax and should not be used
   (eg. the "Branch", "Switch", "Case" and "flag" operations).

.. _Wiki page: https://wiki.skytemple.org/index.php/List_of_Opcodes

Macro call
~~~~~~~~~~
A macro call calls a macro (duh!). See the documentation on macros
(below) for more information. Macro calls start with ``~``.

.. code:: ExplorerScript

    ~MyMacro(3, "String", Position<'Name', 20, 20.5>);

Conditional operators
---------------------
+----------+--------------------------------------------------------------------------------+
| Operator | Description                                                                    |
+==========+================================================================================+
| FALSE    | The condition always fails                                                     |
+----------+--------------------------------------------------------------------------------+
| TRUE     | The condition always succeeds.                                                 |
+----------+--------------------------------------------------------------------------------+
| ==       | Both must be equal.                                                            |
+----------+--------------------------------------------------------------------------------+
| >        | The value of the left side must be greater than the right side's value.        |
+----------+--------------------------------------------------------------------------------+
| <        | The value of the left side must be smaller than the right side's value.        |
+----------+--------------------------------------------------------------------------------+
| >=       | The value of the left side must be greater or equal to the right side's value. |
+----------+--------------------------------------------------------------------------------+
| <=       | The value of the left side must be smaller or equal to the right side's value. |
+----------+--------------------------------------------------------------------------------+
| !=       | Both must not be equal.                                                        |
+----------+--------------------------------------------------------------------------------+
| &        | Bitwise AND.                                                                   |
+----------+--------------------------------------------------------------------------------+
| ^        | Bitwise XOR.                                                                   |
+----------+--------------------------------------------------------------------------------+
| &<<      | True if the bit of the left side (as specified by the right side) is set.      |
+----------+--------------------------------------------------------------------------------+

Assigment operators
-------------------
+----------+--------------------------------------------------------------------------------------------------+
| Operator | Description                                                                                      |
+==========+==================================================================================================+
| =        | Set's the left side to the right side's value.                                                   |
+----------+--------------------------------------------------------------------------------------------------+
| -=       | Changes the left side's value to have the right side's value subtracted.                         |
+----------+--------------------------------------------------------------------------------------------------+
| +=       | Changes the left side's value to have the right side's value added.                              |
+----------+--------------------------------------------------------------------------------------------------+
| *=       | Changes the left side's value to be multiplied by the right side's value.                        |
+----------+--------------------------------------------------------------------------------------------------+
| /=       | Changes the left side's value to be divided by the right side's value. Warning: No floats exist! |
+----------+--------------------------------------------------------------------------------------------------+

User Constants
--------------
In addition to system constants, you may also specify your own (user) constants in your source code.

These constants can take on the value of any data type (including system constants).

If they are defined outside of routines, they are scoped to the entire file. If the file is the main script, it is also
scoped to all of the included files (see `Imports / Includes`_). If defined inside of a function or macro, they are
visible only within the function or macro they are defined in. User constants defined in functions or macros
take precedence over user constants in the global scope. All visible user constants take precedence over system
constants.

.. code:: ExplorerScript

    const MY_CONSTANT = 12;

    def 0 {
        const MY_INNER_CONSTANT = "Hello!";

        foobar(MY_CONSTANT); // = foobar(12);
        foobar(MY_INNER_CONSTANT); // = foobar("Hello!");

        // Constants can be used before they are defined.
        foobar(COPIED_CONSTANT); // = foobar(12);
        const COPIED_CONSTANT = MY_CONSTANT;

        foobar(ANOTHER_CONSTANT); // = foobar(A_SYSTEM_CONSTANT);
    }

    def 1 {
        const MY_INNER_CONSTANT = "Goodbye!";

        foobar(MY_INNER_CONSTANT); // = foobar("Goodbye!");

        // COPIED_CONSTANT is not a user constant in this scope, so a system constant
        // of that name is used instead.
        // If there is no system constant COPIED_CONSTANT, compilation will fail.
        foobar(COPIED_CONSTANT); // = foobar(COPIED_CONSTANT);
    }

    const ANOTHER_CONSTANT = A_SYSTEM_CONSTANT;

Imports / Includes
------------------
An ExplorerScript source file can imports other ExplorerScript
files. These files are merged together. Imports are always
at the top of source files, before any routine or macro.

Imports can be specified using:

- Relative paths to the source file (starting with './' or '../')
- Absolute paths (starting with '/').
- Paths relative to the include paths of the compiler (all other paths).

The path separator is always ``/``, even under Windows.

.. code:: ExplorerScript

    import "/xyz/abc.exps"; // Absolute
    import "./abc.exps"; // Relative
    import "../abc.exps"; // Relative
    import "abc.exps"; // In include path
    import "xyz/abc.exps"; // In include path

.. admonition:: SkyTemple

   SkyTemple Script Engine Debugger does not allow any imported
   files to contain routines, they must only contain macros.

   The include path for SkyTemple projects is the "Macros"
   directory inside the project's directory.

Macros
------
Macros are small functions that can be specified by the user.

They have a name and can take a list of arguments.
When called these arguments get filled with the values
of the parameters specified in the call and turn into
macro variables. Macro variables have the prefix ``%``.

When compiled, the entire content of a macro is copied to where
the call was in the source code, the actual compiled code does not
contain a function call. All references to the macro variables
are replaced with the values of the call.

Macros can call other macros but can not cause any form of recursion.

Using imports you can share macros across multiple source files.

.. code:: ExplorerScript

    macro another_example(%anotherVariable) {
        another_print(%anotherVariable);
    }

    macro example(%variable1, %variable2) {
        print(%variable1, %variable2);
        ~another_example(%variable1);
    }

    def 0 {
        ~example($SCENARIO_MAIN, 3);
        ~example(ANOTHER_CONSTANT, "A string");
        ~another_example("Another string");
    }

This example is equivalent to:

.. code:: ExplorerScript

    def 0 {
        print($SCENARIO_MAIN, 3);
        another_print($SCENARIO_MAIN);
        print(ANOTHER_CONSTANT, "A string");
        another_print(ANOTHER_CONSTANT);
        another_print("Another string");
    }

.. admonition:: SkyTemple

   Game variables and macro variables are not the same, they are
   not interchangeable. Game variables are actually constants for
   integers that refer to the variables and macro variables
   can have game variable constants as values!

   See the warning at the "Assignment" section for more info
   on this behaviour.

.. note::

   Macro variables can also use the prefix ``$`` for backwards-compatibility
   with old ExplorerScript releases. This prefix should not be used anymore,
   it is deprecated and support for it may be removed in future versions.

   Macro variables with the same name refer to the same variable regardless of
   prefix (``$foo`` or ``%foo`` would both refer to the variable named 'foo').
