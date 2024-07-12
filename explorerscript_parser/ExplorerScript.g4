/*
 * MIT License
 *
 * Copyright (c) 2020-2024 Capypara and the SkyTemple contributors
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */
grammar ExplorerScript;
import SsbCommon;

/*
 * parser rules
 */

start: import_stmt* (macrodef | funcdef | constant_assign)* EOF;

import_stmt: IMPORT STRING_LITERAL ';';
constant_assign: CONST IDENTIFIER ASSIGN primitive ';';

macrodef: MACRO IDENTIFIER OPEN_PAREN VARIABLE? (',' VARIABLE)* CLOSE_PAREN func_suite;

stmt: (constant_assign | simple_stmt | ctx_block | if_block | switch_block | message_switch_block | forever_block | for_block | while_block | macro_call );
simple_stmt: (operation | label | cntrl_stmt | jump | call | assignment) ';';

cntrl_stmt: RETURN | END | HOLD | CONTINUE | BREAK | BREAK_LOOP;
jump: JUMP AT IDENTIFIER;
call: CALL AT IDENTIFIER;
macro_call: MACRO_CALL OPEN_PAREN arglist? CLOSE_PAREN ';';

// warning: the parser also accepts labels, which isn't valid!
ctx_block: WITH OPEN_PAREN ctx_header CLOSE_PAREN OPEN_BRACE simple_stmt* CLOSE_BRACE;

if_block: IF NOT? OPEN_PAREN if_header (OR if_header)* CLOSE_PAREN OPEN_BRACE stmt* CLOSE_BRACE elseif_block* else_block?;
elseif_block: ELSEIF NOT? OPEN_PAREN if_header (OR if_header)* CLOSE_PAREN OPEN_BRACE stmt* CLOSE_BRACE;
else_block: ELSE OPEN_BRACE stmt* CLOSE_BRACE;
if_header: (if_h_op | if_h_bit | if_h_negatable | if_h_scn | operation);
if_h_negatable: NOT? (DEBUG | EDIT | VARIATION);
if_h_op: primitive conditional_operator ( value_of | primitive );
if_h_bit: NOT? primitive OPEN_BRACKET INTEGER CLOSE_BRACKET;
if_h_scn: scn_var conditional_operator OPEN_BRACKET INTEGER COMMA INTEGER CLOSE_BRACKET;

switch_block: SWITCH OPEN_PAREN switch_header CLOSE_PAREN OPEN_BRACE (default | single_case_block)* CLOSE_BRACE;
message_switch_block: (MESSAGE_SWITCH_TALK | MESSAGE_SWITCH_MONOLOGUE) OPEN_PAREN primitive CLOSE_PAREN OPEN_BRACE (default | single_case_block)* CLOSE_BRACE;
// Either a list of statements (regular switch+case/default) or just one string (message_Switch* + case/default)
single_case_block: CASE case_header COLON (stmt* | primitive);
default: DEFAULT COLON (stmt* | primitive);

switch_header: primitive | operation | switch_h_scn | switch_h_random | switch_h_dungeon_mode | switch_h_sector;
switch_h_scn: scn_var OPEN_BRACKET INTEGER CLOSE_BRACKET;
switch_h_random: RANDOM OPEN_PAREN primitive CLOSE_PAREN;
switch_h_dungeon_mode: DUNGEON_MODE OPEN_PAREN primitive CLOSE_PAREN;
switch_h_sector: SECTOR OPEN_PAREN CLOSE_PAREN;

case_header: primitive | case_h_menu | case_h_menu2 | case_h_op;
case_h_menu: MENU OPEN_PAREN primitive CLOSE_PAREN;
case_h_menu2: MENU2 OPEN_PAREN primitive CLOSE_PAREN;
case_h_op: conditional_operator ( value_of | primitive );

forever_block: FOREVER OPEN_BRACE stmt* CLOSE_BRACE;
for_block: FOR OPEN_PAREN simple_stmt if_header ';' simple_stmt CLOSE_PAREN OPEN_BRACE stmt* CLOSE_BRACE;
while_block: WHILE NOT? OPEN_PAREN if_header CLOSE_PAREN OPEN_BRACE stmt* CLOSE_BRACE;

assignment: assignment_regular | assignment_clear | assignment_initial | assignment_reset | assignment_adv_log | assignment_dungeon_mode | assignment_scn;
assignment_regular: primitive (OPEN_BRACKET INTEGER CLOSE_BRACKET)? assign_operator (primitive | value_of);
assignment_clear: CLEAR primitive;
assignment_initial: INIT primitive;
assignment_reset: RESET (DUNGEON_RESULT | scn_var);
assignment_adv_log: ADVENTURE_LOG ASSIGN primitive;
assignment_dungeon_mode: DUNGEON_MODE OPEN_PAREN primitive CLOSE_PAREN ASSIGN primitive;
assignment_scn: primitive ASSIGN SCN OPEN_BRACKET INTEGER COMMA INTEGER CLOSE_BRACKET;

value_of: VALUE OPEN_PAREN primitive CLOSE_PAREN;
scn_var: SCN OPEN_PAREN primitive CLOSE_PAREN;

conditional_operator
 : OP_FALSE
 | OP_TRUE
 | OP_EQ
 | OP_GE
 | OP_LE
 | OPEN_SHARP
 | CLOSE_SHARP
 | OP_NEQ
 | OP_AND
 | OP_XOR
 | OP_BICH
 ;

assign_operator
 : OP_MINUS
 | OP_PLUS
 | OP_MULTIPLY
 | OP_DIVIDE
 | ASSIGN
 ;

/*
 * lexer rules
 */

OP_FALSE: 'FALSE';
OP_TRUE: 'TRUE';
ASSIGN : '=';
OPEN_SHARP : '<';
CLOSE_SHARP : '>';
OP_EQ: '==';
OP_LE: '<=';
OP_GE: '>=';
OP_NEQ: '!=';
OP_AND: '&';
OP_XOR: '^';
OP_BICH: '&<<';

OP_MINUS: '-=';
OP_PLUS: '+=';
OP_MULTIPLY: '*=';
OP_DIVIDE: '/=';

OR: '||';
NOT: 'not';
JUMP: 'jump';
CALL: 'call';

IMPORT: 'import';
CONST: 'const';
MACRO: 'macro';
IF: 'if';
ELSEIF: 'elseif';
ELSE: 'else';
FOREVER: 'forever';
WITH: 'with';
SWITCH: 'switch';
RETURN: 'return';
END: 'end';
HOLD: 'hold';
CONTINUE: 'continue';
BREAK: 'break';
BREAK_LOOP: 'break_loop';
VALUE: 'value';
DEBUG: 'debug';
EDIT: 'edit';
VARIATION: 'variation';
RANDOM: 'random';
SECTOR: 'sector';
DUNGEON_MODE: 'dungeon_mode';
MENU2: 'menu2';
MENU: 'menu';
CASE: 'case';
DEFAULT: 'default';
CLEAR: 'clear';
RESET: 'reset';
INIT: 'init';
SCN: 'scn';
DUNGEON_RESULT: 'dungeon_result';
ADVENTURE_LOG: 'adventure_log';
MESSAGE_SWITCH_TALK: 'message_SwitchTalk';
MESSAGE_SWITCH_MONOLOGUE: 'message_SwitchMonologue';
WHILE: 'while';
OPEN_BRACKET : '[';
CLOSE_BRACKET : ']';
