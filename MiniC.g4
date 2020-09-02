grammar MiniC;

/*
Macro Syntax
*/

// Rule 1
program: (decl)+ EOF ;

// Rule 2
decl: var_decl | method_decl;

// Rule 3
var_decl: type identifier (',' identifier)* ';' ;

// Rule 4
method_decl: (type | VOID) ID '(' (type identifier (',' type identifier)*)? ')' block;

// Rule 5
block: '{' (var_decl)* (statement)* '}';
// Rule 6
type: INT | UINT | BOOL | CHAR;

// Rule 7
statement: assignment (',' assignment)* ';' 
        | method_call ';'
        | IF '(' expr ')' block (ELSE block)?
        | FOR '(' (assignment (',' assignment)* )? ';' (expr (',' expr)*)? ';' (assignment (',' assignment)*)? ')' block
        | WHILE '(' expr ')' block
        | BREAK ';'
        | CONTINUE ';'
        | block
        | RETURN expr ';'
        | PRINT '(' expr ')' ';'
        ;

// Rule 8
assignment: identifier ASSIGN expr;

// Rule 9
method_call: ID '(' (expr (',' expr)*)? ')';

// Rule 10
expr: expr8;

expr8: expr8 THEN expr8 OTHERWISE expr8 | expr7;
expr7: expr7 OR expr6 | expr6;
expr6: expr6 AND expr5 | expr5;
expr5: expr5 EQ expr4 | expr5 NE expr4 | expr4;
expr4: expr4 GT expr3 | expr4 GE expr3 | expr3;
expr3: expr3 LT expr2 | expr3 LE expr2 | expr2;
expr2: expr2 ADD expr1 | expr2 SUB expr1 | expr1;
expr1: expr1 MUL expr0 | expr1 DIV expr0 | expr1 MOD expr0 | expr0;

expr0: identifier
    | literal
    | method_call
    | NOT expr
    | NEGATE expr
    | '(' expr ')'
    | READ_INT'(' ')'
    | READ_CHAR'(' ')'
    | READ_BOOL'(' ')';

// Rule 11
identifier: ID | ID('[' expr ']');

// Rule 12
literal: INT_LIT | FLOAT_LIT | CHAR_LIT | STRING_LIT | bool_lit;

// Rule 13
bool_lit: TRUE | FALSE;

// Rule 14
arithmetic_op: ADD | SUB | MUL | DIV | MOD;

// Rule 15
relational_op: LT | GT | LE | GE;

// Rule 16
conditional_op: AND | OR;

// Rule 17
equality_op: EQ | NE;

/*
Micro Syntax
*/
// Rule 1
FALSE: 'false';

// Rule 2
TRUE: 'true';

// Rule 3
NOT: '!';

// Rule 4
NEGATE: '~';

// Rule 5
VOID: 'void';

// Rule 6
INT: 'int';

// Rule 7
CHAR: 'char';

// Rule 8
UINT: 'uint';

// Rule 9
BOOL: 'bool';

// Rule 10
THEN: '?';

// Rule 11
OTHERWISE: ':';

// Rule 12
FOR: 'for';

// RULE 13
WHILE: 'while';

// Rule 14
IF: 'if';

// Rule 15
ELSE: 'else';

// Rule 16
BREAK: 'break';

// Rule 17
CONTINUE: 'continue';

// Rule 18
RETURN: 'return';

// Rule 19
ADD: '+';

// Rule 20
SUB: '-';

// Rule 21
MUL: '*';

// Rule 22
DIV: '/';

// Rule 23
MOD: '%';

// Rule 24
LT: '<';

// Rule 25
GT: '>';

// Rule 26
LE: '<=';

// Rule 27
GE: '>=';

// Rule 28
AND: '&&';

// Rule 29
OR: '||';

// Rule 30
EQ: '==';

// Rule 31
NE: '!=';

// Rule 32
ASSIGN: '=';

// Rule 33
PRINT: 'print';

// Rule 34
READ_INT: 'read_int';

// Rule 35
READ_CHAR: 'read_char';

// Rule 36
READ_BOOL: 'read_bool';

// Rules 37-42 need not be specified.

// Rule 43
INT_LIT : [0-9][0-9]*;

// Rule 44
FLOAT_LIT: [0-9][0-9]*(.[0-9][0-9]*)?;

// Rule 45
CHAR_LIT: '\''[a-zA-Z0-9 _.,;]'\'';
// Rule 46
ID : [a-zA-Z_][a-zA-Z0-9_]*;

// Rule 47
STRING_LIT: '"'[a-zA-Z0-9 _.,;]*'"';
// Additional Rule to skip white spaces in ANTLR4.
WS: [ \n\t\r]+ -> skip;