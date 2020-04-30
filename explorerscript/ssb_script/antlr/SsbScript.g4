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
grammar SsbScript;

/*
 * parser rules
 */

start: funcdef* EOF;

funcdef: coro_def | simple_def | for_target_def;
simple_def: DEF INTEGER func_suite;
coro_def: CORO IDENTIFIER func_suite;
for_target_def: DEF INTEGER FOR_TARGET OPEN_PAREN integer_like CLOSE_PAREN func_suite;

integer_like: INTEGER | IDENTIFIER;

stmt: (operation | label) ';';
operation: IDENTIFIER OPEN_PAREN arglist? CLOSE_PAREN;

func_suite: OPEN_BRACE (stmt+ | func_alias) CLOSE_BRACE;
func_alias: ALIAS PREVIOUS ';';

arglist: pos_argument (',' pos_argument)*  (',')?;
pos_argument: integer_like | string | position_marker | jump_marker;

position_marker: POSITION OPEN_SHARP STRING_LITERAL ',' position_marker_arg ',' position_marker_arg CLOSE_SHARP;
position_marker_arg: INTEGER POINT_FIVE?;

jump_marker: AT IDENTIFIER;
label: PARAGRAPH IDENTIFIER;

string: STRING_LITERAL | lang_string;
lang_string: OPEN_BRACE lang_string_argument (',' lang_string_argument)* (',')? CLOSE_BRACE;
lang_string_argument: IDENTIFIER ASSIGN STRING_LITERAL;

/*
 * lexer rules
 */

STRING_LITERAL
 : '\'' ( STRING_ESCAPE_SEQ | ~[\\\r\n\f'] )* '\''
 | '"' ( STRING_ESCAPE_SEQ | ~[\\\r\n\f"] )* '"'
 ;

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
PREVIOUS: 'previous';
POSITION: 'Position';

IDENTIFIER
 : [$]?[a-zA-Z_][0-9a-zA-Z_]*
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
POINT_FIVE : '.5';

SKIP_
 : ( SPACES | LINE_JOINING ) -> skip
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
