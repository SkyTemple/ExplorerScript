/*
 * MIT License
 *
 * Copyright (c) 2020 Parakoopa
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

start: funcdef* EOF;

stmt: (simple_stmt | ctx_block | if_block | switch_block | message_switch_block | forever_block);
simple_stmt: (operation | label | cntrl_stmt | jump | assignment) ';';

cntrl_stmt: RETURN | END | HOLD | CONTINUE | BREAK | BREAK_FOREVER;
jump: JUMP AT IDENTIFIER;

// a ctx block needs exactly one simple statement, we enforce this on parser level.
// warning: the parser also accepts labels, which isn't valid!
ctx_block: WITH OPEN_PAREN ctx_header CLOSE_PAREN OPEN_BRACE simple_stmt CLOSE_BRACE;
ctx_header: CTX_TYPE integer_like;

if_block: IF OPEN_PAREN if_header (OR if_header)* CLOSE_PAREN OPEN_BRACE stmt* CLOSE_BRACE elseif_block* else_block?;
elseif_block: ELSEIF OPEN_PAREN if_header (OR if_header)* CLOSE_PAREN OPEN_BRACE stmt* CLOSE_BRACE;
else_block: ELSE OPEN_BRACE stmt* CLOSE_BRACE;
if_header: NOT? (if_h_op | if_h_bit | DEBUG | EDIT | VARIATION | if_h_scn | operation);
if_h_op: integer_like conditional_operator ( value_of | integer_like );
if_h_bit: integer_like OPEN_BRACKET INTEGER CLOSE_BRACKET;
if_h_scn: scn_var OPEN_BRACKET conditional_operator INTEGER COMMA conditional_operator INTEGER CLOSE_BRACKET;

switch_block: SWITCH OPEN_PAREN switch_header CLOSE_PAREN OPEN_BRACE (default | single_case_block)* CLOSE_BRACE;
message_switch_block: (MESSAGE_SWITCH_TALK | MESSAGE_SWITCH_MONOLOGUE) OPEN_PAREN integer_like CLOSE_PAREN OPEN_BRACE (default | single_case_block)* CLOSE_BRACE;
// Either a list of statements (regular switch+case/default) or just one string (message_Switch* + case/default)
single_case_block: CASE case_header COLON (stmt* | string);
default: DEFAULT COLON (stmt* | string);

switch_header: integer_like | operation | switch_h_scn | switch_h_random | switch_h_dungeon_mode | switch_h_sector;
switch_h_scn: scn_var OPEN_BRACKET INTEGER CLOSE_BRACKET;
switch_h_random: RANDOM OPEN_PAREN integer_like CLOSE_PAREN;
switch_h_dungeon_mode: DUNGEON_MODE OPEN_PAREN integer_like CLOSE_PAREN;
switch_h_sector: SECTOR OPEN_PAREN CLOSE_PAREN;

case_header: integer_like | case_h_menu | case_h_menu2 | case_h_op;
case_h_menu: MENU OPEN_PAREN string CLOSE_PAREN;
case_h_menu2: MENU2 OPEN_PAREN string CLOSE_PAREN;
case_h_op: conditional_operator ( value_of | integer_like );

forever_block: FOREVER OPEN_BRACE stmt* CLOSE_BRACE;

assignment: assignment_regular | assignment_clear | assignment_initial | assignment_reset | assignment_adv_log | assignment_dungeon_mode | assignment_scn;
assignment_regular: integer_like (OPEN_BRACKET INTEGER CLOSE_BRACKET)? assign_operator (integer_like | value_of);
assignment_clear: CLEAR integer_like;
assignment_initial: INIT integer_like;
assignment_reset: RESET (DUNGEON_RESULT | scn_var);
assignment_adv_log: ADVENTURE_LOG ASSIGN integer_like;
assignment_dungeon_mode: DUNGEON_MODE OPEN_PAREN integer_like CLOSE_PAREN ASSIGN integer_like;
assignment_scn: integer_like ASSIGN SCN OPEN_BRACKET INTEGER COMMA INTEGER CLOSE_BRACKET;

value_of: VALUE OPEN_PAREN integer_like CLOSE_PAREN;
scn_var: SCN OPEN_PAREN integer_like CLOSE_PAREN;

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

CTX_TYPE
 : ACTOR
 | OBJECT
 | PERFORMER
 ;

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
BREAK_FOREVER: 'break_forever';
ACTOR: 'actor';
OBJECT: 'object';
PERFORMER: 'performer';
VALUE: 'value';
DEBUG: 'debug';
EDIT: 'edit';
VARIATION: 'variation';
RANDOM: 'random';
SECTOR: 'sector';
DUNGEON_MODE: 'dungeon_mode';
SPECIAL_MENU: 'special_menu';
SPECIAL_PROCESS: 'special_process';
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
OPEN_BRACKET : '[';
CLOSE_BRACKET : ']';
