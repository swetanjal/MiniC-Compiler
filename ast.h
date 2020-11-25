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

BasicBlock *Continue = nullptr;
BasicBlock *Break = nullptr;

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
            ASTVarDecl* d = (ASTVarDecl*)decl;
            Type *ty = nullptr;
            if(d->dat->dtype == "int")
            {
                ty = Type::getInt32Ty(Context);
            }
            else if(d->dat->dtype == "bool")
            {
                ty = Type::getInt1Ty(Context);
            }

            if(d->id->addrs.size() > 0){
                // It is an array
            }
            else{
                Value* V_test = TheModule->getNamedGlobal(d->id->name);
                if(V_test != nullptr){
                    // This shoud not happen
                }
                GlobalVariable *gv = new GlobalVariable(*(TheModule), ty, false, GlobalValue::ExternalLinkage, nullptr, d->id->name);
                gv->setInitializer(Constant::getNullValue(ty));
            }
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
    Value* operand1 = left->Codegen();
    Value* operand2 = right->Codegen();
    if(op == "+")
    {
        return Builder.CreateAdd(operand1, operand2, "add");
    }
    else if(op == "-")
    {
        return Builder.CreateSub(operand1, operand2, "sub");
    }
    else if(op == "*")
    {
        return Builder.CreateMul(operand1, operand2, "mult");
    }
    else if(op == "/")
    {
        return Builder.CreateSDiv(operand1, operand2, "div");
    }
    else if(op == "%")
    {
        return Builder.CreateSRem(operand1, operand2, "mod");
    }
    return nullptr;
}
Value* ASTExprTernary::Codegen()
{
    return nullptr;
}
Value* ASTAssign::Codegen()
{
    if(NamedValues.find(id->name) == NamedValues.end())
        Builder.CreateStore(expr->Codegen(), TheModule->getNamedGlobal(id->name));
    else
        Builder.CreateStore(expr->Codegen() ,NamedValues[id->name]);
    return ConstantInt::get(Context, APInt(32, 1));
}
Value* ASTBlock::Codegen()
{
    map <string, AllocaInst*> NamedValues_copy;
    NamedValues_copy = NamedValues;
    Value* V;
    for(auto var_decl: var_declarations)
    {
        V = var_decl->Codegen();
    }
    for(auto statement: statements)
    {
        V = statement->Codegen();
    }
    NamedValues = NamedValues_copy;
    return V;
}
Value* ASTID::Codegen()
{
    if(NamedValues.find(name) == NamedValues.end()){
        Value* V = TheModule->getNamedGlobal(name);
        return Builder.CreateLoad(V);
    }
    return Builder.CreateLoad(NamedValues[name]);
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
    /*else
    {
        Builder.CreateRet(RetVal);    
    }*/
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
    Function *CalleeF = TheModule->getFunction(name);
    if (!CalleeF)
        cout << "Unknown function referenced\n";

    // If argument mismatch error.
    if (CalleeF->arg_size() != args.size())
        cout << "Incorrect # arguments passed\n";
    std::vector<Value *> ArgsV;
    for (unsigned i = 0, e = args.size(); i != e; ++i) {
        ArgsV.push_back(args[i]->Codegen());
    }
    return Builder.CreateCall(CalleeF, ArgsV, "calltmp");
}
Value* ASTStatCall::Codegen()
{
    return expr->Codegen();
}
Value* ASTIFStat::Codegen()
{
    Value *CondV = expr->Codegen();
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(Context, "if", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(Context, "else");
    BasicBlock *MergeBB = BasicBlock::Create(Context, "ifcont");

    if(expr->eval_type == "int")
    {
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(32, 0)), "ifcond"); 
    }
    else if(expr->eval_type == "bool")
    {
        CondV = CondV;
    }
    if(else_block != NULL)
        Builder.CreateCondBr(CondV, ifBlock, elseBlock);
    else
        Builder.CreateCondBr(CondV, ifBlock, MergeBB);
    
    Builder.SetInsertPoint(ifBlock);
    Value *ThenV = if_block->Codegen();
    Builder.CreateBr(MergeBB);
    ifBlock = Builder.GetInsertBlock();

    if(else_block != NULL){
        TheFunction->getBasicBlockList().push_back(elseBlock);
        Builder.SetInsertPoint(elseBlock);

        Value *ElseV = else_block->Codegen();
    
        Builder.CreateBr(MergeBB);
        // codegen of 'Else' can change the current block, update ElseBB for the PHI.
        elseBlock = Builder.GetInsertBlock();
    }
    TheFunction->getBasicBlockList().push_back(MergeBB);
    Builder.SetInsertPoint(MergeBB);

    return ConstantInt::get(Context, APInt(32, 1));;
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
    if(expr->eval_type == "int"){
        Value* Version = expr->Codegen();
        auto Int32Ty = Builder.getInt32Ty();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printint", Builder.getVoidTy(), Int32Ty);
        return Builder.CreateCall(Fn, Version);
    }
}
Value* ASTPrintln::Codegen()
{
    if(expr->eval_type == "int"){
        Value* Version = expr->Codegen();
        auto Int32Ty = Builder.getInt32Ty();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printlnint", Builder.getVoidTy(), Int32Ty);
        return Builder.CreateCall(Fn, Version);
    }
    return nullptr;
}
Value* ASTFor::Codegen()
{

    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *condBB = BasicBlock::Create(Context, "loop_cond", TheFunction);
    BasicBlock *loopBB = BasicBlock::Create(Context, "loop");
    BasicBlock *endAssnBB = BasicBlock::Create(Context, "end_assn");
    BasicBlock *afterLoopBB = BasicBlock::Create(Context, "after");

    
    Value* tmp = nullptr;
    for(auto assn: beg_assigns)
        tmp = assn->Codegen();
    
    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(condBB);
    Value* CondV = exprs[0]->Codegen();
    if(exprs[0]->eval_type == "int")
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(32, 0)), "for_cond"); 
    else if(exprs[0]->eval_type == "bool")
        CondV = CondV;
    Builder.CreateCondBr(CondV, loopBB, afterLoopBB);
    
    TheFunction->getBasicBlockList().push_back(loopBB);
    Builder.SetInsertPoint(loopBB);

    BasicBlock *prevBreak = Break;
    BasicBlock *prevContinue = Continue;
    Continue = endAssnBB;
    Break = afterLoopBB;
    Value* v = block->Codegen();
    Continue = prevContinue;
    Break = prevBreak;
    
    
    TheFunction->getBasicBlockList().push_back(endAssnBB);
    Builder.CreateBr(endAssnBB);
    Builder.SetInsertPoint(endAssnBB);
    // loopBB = Builder.GetInsertBlock();
    for(auto assn: assigns)
        tmp = assn->Codegen();
    Builder.CreateBr(condBB);

    TheFunction->getBasicBlockList().push_back(afterLoopBB);
    Builder.SetInsertPoint(afterLoopBB);

    return ConstantInt::get(Context, APInt(32, 1));
}
Value* ASTWhile::Codegen()
{
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *loopBB = BasicBlock::Create(Context, "loop", TheFunction);
    BasicBlock *endAssnBB = BasicBlock::Create(Context, "end_assn");
    BasicBlock *afterLoopBB = BasicBlock::Create(Context, "after");
    Value* CondV = expr->Codegen();
    if(expr->eval_type == "int")
    {
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(32, 0)), "while_cond"); 
    }
    else if(expr->eval_type == "bool")
    {
        CondV = CondV;
    }

    Builder.CreateCondBr(CondV, loopBB, afterLoopBB);
    Builder.SetInsertPoint(loopBB);

    BasicBlock *prevBreak = Break;
    BasicBlock *prevContinue = Continue;
    Continue = endAssnBB;
    Break = afterLoopBB;
    Value* v = block->Codegen();
    Continue = prevContinue;
    Break = prevBreak;

    Builder.CreateBr(endAssnBB);
    TheFunction->getBasicBlockList().push_back(endAssnBB);
    Builder.SetInsertPoint(endAssnBB);
    CondV = expr->Codegen();
    if(expr->eval_type == "int")
    {
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(32, 0)), "while_cond"); 
    }
    else if(expr->eval_type == "bool")
    {
        CondV = CondV;
    }
    Builder.CreateCondBr(CondV, loopBB, afterLoopBB);

    TheFunction->getBasicBlockList().push_back(afterLoopBB);
    Builder.SetInsertPoint(afterLoopBB);

    return ConstantInt::get(Context, APInt(32, 1));
}
Value* ASTBreak::Codegen()
{
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *breakBB = BasicBlock::Create(Context, "break", TheFunction);
    BasicBlock *afterBreak = BasicBlock::Create(Context, "after_break");
    Builder.CreateBr(breakBB);
    Builder.SetInsertPoint(breakBB);
    Builder.CreateBr(Break);
    TheFunction->getBasicBlockList().push_back(afterBreak);
    Builder.SetInsertPoint(afterBreak);
    return ConstantInt::get(Context, APInt(32, 1));
}
Value* ASTContinue::Codegen()
{
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *continueBB = BasicBlock::Create(Context, "continue", TheFunction);
    BasicBlock *afterContinue = BasicBlock::Create(Context, "after_continue");
    Builder.CreateBr(continueBB);
    Builder.SetInsertPoint(continueBB);
    Builder.CreateBr(Continue);
    TheFunction->getBasicBlockList().push_back(afterContinue);
    Builder.SetInsertPoint(afterContinue);
    return ConstantInt::get(Context, APInt(32, 1));
}
Value* ASTReturn::Codegen()
{
    if(expr == NULL)
        return Builder.CreateRetVoid();
    return Builder.CreateRet(expr->Codegen());
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