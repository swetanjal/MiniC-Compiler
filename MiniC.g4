grammar MiniC;

program: (decl)+ EOF ;

decl: var_decl;

var_decl: (HELLO ',')*(HELLO);

HELLO : [0-9]+;
WS: [ \n\t\r]+ -> skip;