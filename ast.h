#include "bits/stdc++.h"
using namespace std;

class ASTProg;
class ASTExpr;
class ASTExprBinary;
class ASTExprTernary;
class ASTAssign;
class ASTBlock;
class ASTID;
class ASTDecl;
class ASTMethodDecl;
class ASTVarDecl;
class ASTStat;
class ASTDtype;
class ASTINTLIT;
class ASTFLOATLIT;
class ASTSTRINGLIT;
class ASTBOOLLIT;
class ASTCHARLIT;

class ASTvisitor
{
public:
    virtual void visit(ASTProg &node) = 0;
    virtual void visit(ASTDecl &node) = 0;
    virtual void visit(ASTVarDecl &node) = 0;
    virtual void visit(ASTMethodDecl &node) = 0;
    virtual void visit(ASTDtype &node) = 0;
    virtual void visit(ASTID &node) = 0;
    virtual void visit(ASTAssign &node) = 0;
    virtual void visit(ASTExpr &node) = 0;
    virtual void visit(ASTExprBinary &node) = 0;
    virtual void visit(ASTExprTernary &node) = 0;
    virtual void visit(ASTStat &node) = 0;
    virtual void visit(ASTBlock &node) = 0;

    virtual void visit(ASTINTLIT &node) = 0;
    virtual void visit(ASTFLOATLIT &node) = 0;
    virtual void visit(ASTCHARLIT &node) = 0;
    virtual void visit(ASTSTRINGLIT &node) = 0;
    virtual void visit(ASTBOOLLIT &node) = 0;
};

class ASTnode
{
public:
    virtual ~ASTnode()
    {
    }
    //  virtual void printPostFix() const = 0;
    virtual void accept(ASTvisitor &V) = 0;
};

class ASTProg : public ASTnode
{
    public:
    vector <ASTDecl*> declarations;
    virtual void accept(ASTvisitor &V)
    {
        V.visit(*this);
    }
};

class ASTDecl : public ASTnode
{
    public:
    virtual ~ASTDecl()
    {

    }
    string type; // Type can be "var" or "meth"
    virtual void accept(ASTvisitor &V) = 0;
};

class ASTExpr : public ASTnode
{
    public:
    virtual ~ASTExpr()
    {

    }
    string type; // "bin" "ter" "id" "*_lit" "call" "not" "neg" "inp_int" "inp_char" "inp_bool" "exp"
    virtual void accept(ASTvisitor &V) = 0;
};

class ASTStat : public ASTnode
{
    public:
    virtual ~ASTStat()
    {

    }
    string type; // "assn_lst" "method_call" "if" "for" "while" "break" "continue" "block" "return" "print" "println"
    virtual void accept(ASTvisitor &V) = 0;
};

class ASTStatAssn : public ASTStat
{
    public:
    vector <ASTAssign*> assignments;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};



class ASTVarDecl : public ASTDecl
{
    public:
    ASTDtype* dat;
    vector <ASTID*> ids;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTMethodDecl : public ASTDecl
{
    public:
    ASTDtype* return_type;
    vector <ASTVarDecl*> args;
    ASTBlock* block;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTDtype : public ASTnode
{
    public:
    string dtype;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTID : public ASTExpr{
    public:

    vector <ASTExpr*> addrs;
    string name;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTINTLIT : public ASTExpr{
    public:
    int value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTFLOATLIT : public ASTExpr{
    public:
    float value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTCHARLIT : public ASTExpr{
    public:
    char value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTSTRINGLIT : public ASTExpr{
    public:
    string value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTBOOLLIT : public ASTExpr{
    public:
    bool value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTAssign : public ASTnode
{
    public:
    ASTID* id;
    ASTExpr* expr;

    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTExprBinary : public ASTExpr
{
    public:
    string op;
    ASTExpr* left;
    ASTExpr* right;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTExprTernary : public ASTExpr
{
    public:
    ASTExpr* cond;
    ASTExpr* true_expr;
    ASTExpr* false_expr;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};

class ASTBlock : public ASTnode
{
    public:
    vector <ASTDecl*> var_declarations;
    vector <ASTStat*> statements;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};