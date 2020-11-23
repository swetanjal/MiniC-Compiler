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

int errors_IR = 0;
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
        ofstream out("llvmir.bc");
        out << Str;
        out.close();
        cerr << "Finished writing to llvmir.bc\n";
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

AllocaInst *allocateMemory(Function *TheFunction, string VarName, string type) {
    IRBuilder<> builder(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *alloca_instruction = nullptr;
    if (type == "int") {
        alloca_instruction = builder.CreateAlloca(Type::getInt32Ty(Context), 0, VarName);
    } else if (type == "bool") {
        alloca_instruction = builder.CreateAlloca(Type::getInt1Ty(Context), 0, VarName);
    }
    return alloca_instruction;
}


Value* ASTProg::Codegen()
{
    Value *V = ConstantInt::get(Context, APInt(32, 0));
    for(auto decl: declarations)
    {
        if(decl->type == "meth")
        {
            // Process methods
            V = decl->Codegen();
            
        }
        else{
            // Process global variables
        }
    }
    return V;
}
Value* ASTExpr::Codegen()
{
    return nullptr;
}
Value* ASTExprBinary::Codegen()
{
    return nullptr;
}
Value* ASTExprTernary::Codegen()
{
    return nullptr;
}
Value* ASTAssign::Codegen()
{
    Builder.CreateStore(expr->Codegen() ,NamedValues[id->name]);
    return ConstantInt::get(Context, APInt(32, 1));
}
Value* ASTBlock::Codegen()
{
    for(auto var_decl: var_declarations)
    {
        var_decl->Codegen();
    }
    for(auto statement: statements)
    {
        statement->Codegen();
    }
    return nullptr;
}
Value* ASTID::Codegen()
{
    return nullptr;
}
Value* ASTDecl::Codegen()
{
    return nullptr;
}
Value* ASTMethodDecl::Codegen()
{
    Type* ret_type;
    if(return_type == NULL)
    {
        ret_type = Type::getVoidTy(Context);
    }
    else if(return_type->dtype == "int")
    {
        ret_type = Type::getInt32Ty(Context);
    }
    else if(return_type->dtype == "bool")
    {
        ret_type = Type::getInt1Ty(Context);
    }
    std::vector<Type*> arguments;
    for(auto param: args)
    {
        if(param->dat->dtype == "int")
        {
            arguments.push_back(Type::getInt32Ty(Context));
        }
        else if(param->dat->dtype == "bool")
        {
            arguments.push_back(Type::getInt1Ty(Context));
        }
    }
    FunctionType *FT = FunctionType::get(ret_type, arguments, false);
    Function *F = Function::Create(FT, Function::ExternalLinkage, name, TheModule);
    unsigned Idx = 0;
    for(auto &Arg : F->args())
    {
        Arg.setName(args[Idx++]->id->name);
    }
    BasicBlock *BB = BasicBlock::Create(Context, "entry", F);
    Builder.SetInsertPoint(BB);

    Idx = 0;
    
    map <string, AllocaInst*> NamedValues_copy;
    NamedValues_copy = NamedValues;
    for(auto &Arg : F->args())
    {
        AllocaInst *Alloca = allocateMemory(F, args[Idx]->id->name, args[Idx]->dat->dtype);
        Builder.CreateStore(&Arg, Alloca);
        NamedValues[args[Idx]->id->name] = Alloca;
        Idx++;
    }

    Value* RetVal = block->Codegen();
    // Restore symbol table after coming out of function.
    
    NamedValues = NamedValues_copy;
    if(return_type == NULL)
    {
        Builder.CreateRetVoid();
    }
    else
    {
        Builder.CreateRet(RetVal);    
    }
    verifyFunction(*F);
    return F;
}
Value* ASTVarDecl::Codegen()
{
    // For the time being support only non arrays.
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    AllocaInst *allocaMem = allocateMemory(TheFunction, id->name, dat->dtype);
    NamedValues[id->name] = allocaMem;
    return ConstantInt::get(Context, APInt(32, 1));
}
Value* ASTStat::Codegen()
{
    return nullptr;
}
Value* ASTDtype::Codegen()
{
    return nullptr;
}
Value* ASTINTLIT::Codegen()
{
    return ConstantInt::get(Context, APInt(32, value));
}
Value* ASTFLOATLIT::Codegen()
{
    return nullptr;
}
Value* ASTSTRINGLIT::Codegen()
{
    return nullptr;
}
Value* ASTBOOLLIT::Codegen()
{
    if(value == "true")
    {
        return ConstantInt::get(Context, APInt(1, 1));
    }
    else if(value == "false")
    {
        return ConstantInt::get(Context, APInt(1, 0));
    }
    return nullptr;
}
Value* ASTCHARLIT::Codegen()
{
    return nullptr;
}
Value* ASTExprCall::Codegen()
{
    return nullptr;
}
Value* ASTStatCall::Codegen()
{
    return nullptr;
}
Value* ASTIFStat::Codegen()
{
    return nullptr;
}
Value* ASTNot::Codegen()
{
    return nullptr;
}
Value* ASTNeg::Codegen()
{
    return nullptr;
}
Value* Inp::Codegen()
{
    return nullptr;
}
Value* ASTPrint::Codegen()
{
    return nullptr;
}
Value* ASTPrintln::Codegen()
{
    return nullptr;
}
Value* ASTFor::Codegen()
{
    return nullptr;
}
Value* ASTWhile::Codegen()
{
    return nullptr;
}
Value* ASTBreak::Codegen()
{
    return nullptr;
}
Value* ASTContinue::Codegen()
{
    return nullptr;
}
Value* ASTReturn::Codegen()
{
    return nullptr;
}
Value* ASTCast::Codegen()
{
    return nullptr;
}
Value* ASTStatAssn::Codegen()
{
    for(auto assn: assignments)
    {
        assn->Codegen();
    }
    return ConstantInt::get(Context, APInt(32, 1));
}

Value* ASTnode::Codegen()
{
    return nullptr;
}