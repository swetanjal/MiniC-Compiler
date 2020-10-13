#include "bits/stdc++.h"
using namespace std;
struct SymbolTable{
    map < string, ASTVarDecl* > var_decl;
    map < string, int> dims;
    map < string , ASTMethodDecl* > method_decl;
    SymbolTable* prev;
};

SymbolTable* curr_table = new SymbolTable();