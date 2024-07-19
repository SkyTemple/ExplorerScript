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

/*
 * parser rules
 */

grammar SsbCommon;

start: funcdef* EOF;

funcdef: coro_def | simple_def | for_target_def;
simple_def: DEF INTEGER func_suite;
coro_def: CORO IDENTIFIER func_suite;
for_target_def: DEF INTEGER for_target_def_target OPEN_PAREN? primitive CLOSE_PAREN? func_suite;

// In SSBScript identifiers and variables are not distinguished.
// For ExplorerScript:
//   Variables and identifier are treated the same in funcdefs but may or may not be different things
//   in macros, depending on if they are defined in the header or not.
primitive: DECIMAL | INTEGER | IDENTIFIER | VARIABLE | string;

stmt: (operation | label) ';';
operation: IDENTIFIER inline_ctx? OPEN_PAREN arglist? CLOSE_PAREN;
inline_ctx: OPEN_SHARP ctx_header CLOSE_SHARP;

func_suite: OPEN_BRACE (stmt+ | func_alias) CLOSE_BRACE;
func_alias: ALIAS PREVIOUS ';';

arglist: pos_argument (',' pos_argument)*  (',')?;
pos_argument: primitive | position_marker;

position_marker: POSITION OPEN_SHARP STRING_LITERAL ',' position_marker_arg ',' position_marker_arg CLOSE_SHARP;
position_marker_arg: INTEGER | DECIMAL;

label: (PARAGRAPH | AT) IDENTIFIER;

string: string_value | lang_string;
lang_string: OPEN_BRACE lang_string_argument (',' lang_string_argument)* (',')? CLOSE_BRACE;
lang_string_argument: IDENTIFIER ASSIGN string_value;
string_value: MULTILINE_STRING_LITERAL | STRING_LITERAL;

ctx_header: IDENTIFIER primitive;

for_target_def_target
  : (FOR IDENTIFIER)
  | (FOR_TARGET)  // DEPRECATED, use syntax above instead.
  ;

/*
 * lexer rules
 */

STRING_LITERAL
 : '\'' ( STRING_ESCAPE_SEQ | ~[\\\r\n\f'] )* '\''
 | '"' ( STRING_ESCAPE_SEQ | ~[\\\r\n\f"] )* '"'
 ;

MULTILINE_STRING_LITERAL
 : '\'\'\'' .*? '\'\'\''
 | '"""' .*? '"""'
 ;

// DEPRECATED since 0.2, see for_target_def_target
FOR_TARGET
 : FOR_ACTOR
 | FOR_OBJECT
 | FOR_PERFORMER
 ;

CORO : 'coro';
DEF : 'def';
FOR_ACTOR : 'for_actor';
FOR_OBJECT: 'for_object';
FOR_PERFORMER: 'for_performer';
ALIAS: 'alias';
FOR: 'for';
PREVIOUS: 'previous';
POSITION: 'Position';

IDENTIFIER
 : IDENTIFIER_BASE
 ;

VARIABLE
 : [$%] IDENTIFIER_BASE
 ;

MACRO_CALL
 : [~] IDENTIFIER_BASE
 ;

INTEGER
 : DECIMAL_INTEGER
 | OCT_INTEGER
 | HEX_INTEGER
 | BIN_INTEGER
 ;

DECIMAL_INTEGER
 : '-'? NON_ZERO_DIGIT DIGIT*
 | '-'? '0'+
 ;

OCT_INTEGER
 : '-'? '0' [oO] OCT_DIGIT+
 ;

HEX_INTEGER
 : '-'? '0' [xX] HEX_DIGIT+
 ;

BIN_INTEGER
 : '-'? '0' [bB] BIN_DIGIT+
 ;

OPEN_PAREN : '(';
CLOSE_PAREN : ')';
COMMA : ',';
COLON : ':';
ASSIGN : '=';
PLUS : '+';
AT : '@';
PARAGRAPH : '§';
OPEN_BRACE : '{';
CLOSE_BRACE : '}';
OPEN_SHARP : '<';
CLOSE_SHARP : '>';

DECIMAL
 : '-'? DIGIT+ '.' DIGIT+
 | '-'? '.' DIGIT+
 ;

SKIP_
 : ( LINE_COMMENT | BLOCK_COMMENT | SPACES | LINE_JOINING ) -> skip
 ;

UNKNOWN_CHAR
 : .
 ;

/*
 * fragments
 */

/// stringescapeseq ::=  "\" <any source character>
fragment STRING_ESCAPE_SEQ
 : '\\' .
 ;

/// nonzerodigit   ::=  "1"..."9"
fragment NON_ZERO_DIGIT
 : [1-9]
 ;

/// digit          ::=  "0"..."9"
fragment DIGIT
 : [0-9]
 ;

/// octdigit       ::=  "0"..."7"
fragment OCT_DIGIT
 : [0-7]
 ;

/// hexdigit       ::=  digit | "a"..."f" | "A"..."F"
fragment HEX_DIGIT
 : [0-9a-fA-F]
 ;

/// bindigit       ::=  "0" | "1"
fragment BIN_DIGIT
 : [01]
 ;

fragment SPACES
 : [ \t\n\r]+
 ;

fragment LINE_JOINING
 : '\\' SPACES? ( '\r'? '\n' | '\r' | '\f')
 ;

fragment BLOCK_COMMENT
   : '/*' .*? ('*/' | EOF)
   ;

fragment LINE_COMMENT
   : '//' ~ [\r\n]*
   ;

fragment IDENTIFIER_BASE
   : [a-zA-Z_][0-9a-zA-Z_]*
   ;
