#include "bits/stdc++.h"
using namespace std;
struct SymbolTable{
    map < string, vector <ASTDecl*> > var_decl;
    map < string, int> dims;
    map < string , ASTDecl* > method_decl;
    SymbolTable* next;
    SymbolTable* prev;
};

SymbolTable* curr_table = new SymbolTable();