#include "bits/stdc++.h"
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
// #include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/raw_ostream.h>
#include "common.h"
using namespace std;
using namespace llvm;

static LLVMContext Context;
static Module *TheModule = new Module("MiniC compiler", Context); // Contains all functions and variables
static IRBuilder<> Builder(Context); // helps to generate LLVM IR with helper functions
static map <string, AllocaInst*>NamedValues; // keeps track of all the values defined in the current scope like a symbol table


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
class ASTExprCall;
class ASTStatCall;
class ASTIFStat;
class ASTNot;
class ASTNeg;
class Inp;
class ASTPrint;
class ASTPrintln;
class ASTFor;
class ASTWhile;
class ASTBreak;
class ASTContinue;
class ASTReturn;
class ASTCast;
class ASTStatAssn;
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
    virtual void visit(ASTStatCall &node) = 0;
    virtual void visit(ASTINTLIT &node) = 0;
    virtual void visit(ASTFLOATLIT &node) = 0;
    virtual void visit(ASTCHARLIT &node) = 0;
    virtual void visit(ASTSTRINGLIT &node) = 0;
    virtual void visit(ASTBOOLLIT &node) = 0;
    virtual void visit(ASTExprCall &node) = 0;
    virtual void visit(ASTIFStat &node) = 0;
    virtual void visit(ASTNot &node) = 0;
    virtual void visit(ASTNeg &node) = 0;
    virtual void visit(Inp &node) = 0;
    virtual void visit(ASTPrint &node) = 0;
    virtual void visit(ASTPrintln &node) = 0;
    virtual void visit(ASTFor &node) = 0;
    virtual void visit(ASTBreak &node) = 0;
    virtual void visit(ASTContinue &node) = 0;
    virtual void visit(ASTWhile &node) = 0;
    virtual void visit(ASTReturn &node) = 0;
    virtual void visit(ASTCast &node) = 0;
    virtual void visit(ASTStatAssn &node) = 0;
};

class ASTnode
{
public:
    virtual ~ASTnode()
    {
    }
    //  virtual void printPostFix() const = 0;
    virtual void accept(ASTvisitor &V) = 0;
    virtual Value* Codegen();
};

class ASTProg : public ASTnode
{
    public:
    vector <ASTDecl*> declarations;
    virtual void accept(ASTvisitor &V)
    {
        V.visit(*this);
    }
    virtual Value* Codegen();
    void generateCodeDump()
    {
        cerr << "Generating LLVM IR Code\n\n";
        std::string Str;
        raw_string_ostream OS(Str);
        OS << *TheModule;
        OS.flush();
        ofstream out("llvmir.txt");
        out << Str;
        out.close();
        cerr << "Finished writing to llvmir.txt\n";
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
    virtual Value* Codegen();
};

class ASTExpr : public ASTnode
{
    public:
    virtual ~ASTExpr()
    {

    }
    string eval_type; // Would be useful to do type checking. 
    string type; // "bin" "ter" "id" "*_lit" "call" "not" "neg" "inp_int" "inp_char" "inp_bool" "exp"
    virtual void accept(ASTvisitor &V) = 0;
    virtual Value* Codegen();
};

class ASTStat : public ASTnode
{
    public:
    virtual ~ASTStat()
    {

    }
    string type; // "assn_lst" "method_call" "if" "for" "while" "break" "continue" "block" "return" "print" "println"
    virtual void accept(ASTvisitor &V) = 0;
    virtual Value* Codegen();
};

class ASTWhile : public ASTStat
{
    public:
    ASTExpr* expr;
    ASTBlock* block;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTReturn : public ASTStat
{
    public:
    ASTExpr* expr;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTBreak : public ASTStat
{
    public:
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTCast : public ASTExpr
{
    public:
    ASTExpr* expr;
    ASTDtype* dat;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTContinue: public ASTStat
{
    public:
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTFor : public ASTStat
{
    public:
    vector <ASTAssign*> beg_assigns;
    vector <ASTAssign*> assigns;
    vector <ASTExpr*> exprs;
    ASTBlock* block;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};
class ASTStatAssn : public ASTStat
{
    public:
    vector <ASTAssign*> assignments;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};
class ASTStatCall : public ASTStat
{
    public:
    ASTExpr* expr;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTIFStat : public ASTStat
{
    public:
    ASTExpr* expr;
    ASTBlock* if_block;
    ASTBlock* else_block;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTPrint : public ASTStat
{
    public:
    ASTExpr* expr;
    virtual void accept(ASTvisitor &V)
    {
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTPrintln : public ASTStat
{
    public:
    ASTExpr* expr;
    virtual void accept(ASTvisitor &V)
    {
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTNot : public ASTExpr
{
    public:
    ASTExpr* expr;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTNeg : public ASTExpr
{
    public:
    ASTExpr* expr;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class Inp : public ASTExpr
{
    public:
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTVarDecl : public ASTDecl
{
    public:
    ASTDtype* dat;
    ASTID* id;
    ASTExpr* val;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTMethodDecl : public ASTDecl
{
    public:
    string name;
    ASTDtype* return_type;
    vector <ASTVarDecl*> args;
    ASTBlock* block;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTDtype : public ASTnode
{
    public:
    string dtype;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTID : public ASTExpr{
    public:

    vector <ASTExpr*> addrs;
    string name;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTINTLIT : public ASTExpr{
    public:
    int value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTFLOATLIT : public ASTExpr{
    public:
    float value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTCHARLIT : public ASTExpr{
    public:
    string value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTSTRINGLIT : public ASTExpr{
    public:
    string value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTBOOLLIT : public ASTExpr{
    public:
    string value;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTAssign : public ASTnode
{
    public:
    ASTID* id;
    ASTExpr* expr;

    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};

class ASTExprCall : public ASTExpr
{
    public:
    vector <ASTExpr*> args;
    string name;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
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
    virtual Value* Codegen();
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
    virtual Value* Codegen();
};

class ASTBlock : public ASTnode
{
    public:
    vector <ASTDecl*> var_declarations;
    vector <ASTStat*> statements;
    virtual void accept(ASTvisitor &V){
        V.visit(*this);
    }
    virtual Value* Codegen();
};