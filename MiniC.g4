grammar MiniC;

/*
Macro Syntax
*/

// Rule 1
program: (decl)+ EOF ;

// Rule 2
decl: var_decl    #varDecl 
    | method_decl #methodDecl
    ;

// Rule 3
var_decl: type identifier (',' identifier)* ';' ;

// Rule 4
method_decl: type ID '(' (type identifier (',' type identifier)*)? ')' block   #method_decl_type
        | VOID ID '(' (type identifier (',' type identifier)*)? ')' block      #method_decl_void
        ;

// Rule 5
block: '{' (var_decl)* (statement)* '}';
// Rule 6
type: INT     #typeInt 
    | UINT    #typeUint
    | BOOL    #typeBool
    | CHAR    #typeChar
    | FILE    #typeFile
    | STRING  #typeString
    | FLOAT   #typeFloat
    ; 

// Rule 7
statement: assignment (',' assignment)* ';'    #listAssn 
        | method_call ';'                      #methodCall
        | IF '(' expr ')' block (ELSE block)?  #if
        | FOR '(' (assignment (',' assignment)* )? ';' (expr (',' expr)*)? ';' (assignment (',' assignment)*)? ')' block #for
        | WHILE '(' expr ')' block             #while
        | BREAK ';'                            #break
        | CONTINUE ';'                         #contiue
        | block                                #blck
        | RETURN (expr)? ';'                   #return
        | PRINT '(' expr ')' ';'               #print
        | PRINTLN '(' expr ')' ';'             #println
        ;

// Rule 8
assignment: identifier ASSIGN expr;

// Rule 9
method_call: ID '(' (expr (',' expr)*)? ')';

// Rule 10
expr: expr8;

expr8: expr8 THEN expr8 OTHERWISE expr8 #ternary_expr
    | expr7                             #expr8_7
    ;
expr7: expr7 OR expr6                   #or_expr
    | expr6                             #expr7_6
    ;
expr6: expr6 AND expr5                  #and_expr
    | expr5                             #expr6_5
    ;
expr5: expr5 EQ expr4                   #eq_expr
    | expr5 NE expr4                    #ne_expr
    | expr4                             #expr5_4
    ;
expr4: expr4 GT expr3                   #gt_expr
    | expr4 GE expr3                    #ge_expr
    | expr3                             #expr4_3
    ;
expr3: expr3 LT expr2                   #lt_expr
    | expr3 LE expr2                    #le_expr
    | expr2                             #expr3_2
    ;
expr2: expr2 ADD expr1                  #add_expr
    | expr2 SUB expr1                   #sub_expr
    | expr1                             #expr2_1
    ;
expr1: expr1 MUL expr0                  #mul_expr
    | expr1 DIV expr0                   #div_expr
    | expr1 MOD expr0                   #mod_expr
    | expr0                             #expr1_0
    ;

expr0: identifier                        #id_expr
    | literal                            #lit_expr
    | method_call                        #call_expr
    | NOT expr                           #not_expr
    | SUB expr                           #negate_expr
    | '(' expr ')'                       #bracket_expr
    | READ_INT'(' ')'                    #inp_int
    | READ_CHAR'(' ')'                   #inp_char
    | READ_BOOL'(' ')'                   #inp_bool
    | '(' type ')' expr                  #cast
    ;               

// Rule 11
identifier: ID                     #var 
        | ID('[' expr ']')*        #var_array
        ;

// Rule 12
literal: INT_LIT          #int_lit
    | FLOAT_LIT           #float_lit
    | CHAR_LIT            #char_lit
    | STRING_LIT          #str_lit
    | bool_lit            #bool_literal
    ;

// Rule 13
bool_lit: TRUE            #true_lit 
    | FALSE               #false_lit
    ;   

// Rule 14
// arithmetic_op: ADD | SUB | MUL | DIV | MOD;

// Rule 15
// relational_op: LT | GT | LE | GE;

// Rule 16
// conditional_op: AND | OR;

// Rule 17
// equality_op: EQ | NE;

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
FLOAT: 'float';
INT: 'int';
FILE: 'FILE';
STRING: 'string';
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
PRINTLN: 'println';
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
FLOAT_LIT: [0-9][0-9]*('.'[0-9][0-9]*)?;

// Rule 45
CHAR_LIT: '\''[a-zA-Z0-9 _.,;]'\'' | '\'' '\\'[nt] '\'' ;
// Rule 46
ID : [a-zA-Z_][a-zA-Z0-9_]*;

// Rule 47
STRING_LIT: '"'[a-zA-Z0-9 _.,;\\]*'"';
// Additional Rule to skip white spaces in ANTLR4.
WS: [ \n\t\r]+ -> skip;