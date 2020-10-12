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

class ASTvisitor
{
public:
    virtual void visit(ASTProg &node) = 0;
    virtual void visit(ASTDecl &node) = 0;
    virtual void visit(ASTVarDecl &node) = 0;
    virtual void visit(ASTMethodDecl &node) = 0;
    virtual void visit(ASTDtype &node) = 0;
    virtual void visit(ASTID &node) = 0;
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

class ASTID : public ASTnode{
    public:

    // vector <ASTExpr*> addrs;
    string name;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
};