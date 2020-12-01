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
#include "llvm/IR/InstrTypes.h"
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
map < string, vector <int> > array_sizes;
map < string, string > types; 
int required_extra_block = 0;
AllocaInst *allocateMemory(Function *TheFunction, string VarName, string type) {
    IRBuilder<> builder(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *alloca_instruction = nullptr;
    if (type == "int") {
        alloca_instruction = builder.CreateAlloca(Type::getInt32Ty(Context), 0, VarName);
        types[VarName] = type;
    } else if (type == "bool") {
        alloca_instruction = builder.CreateAlloca(Type::getInt1Ty(Context), 0, VarName);
        types[VarName] = type;
    }
    else if(type == "float"){
        alloca_instruction = builder.CreateAlloca(Type::getFloatTy(Context), 0, VarName);
        types[VarName] = type;
    }
    else if(type == "char")
    {
        alloca_instruction = builder.CreateAlloca(Type::getInt8Ty(Context), 0, VarName);
        types[VarName] = type;
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
            else if(d->dat->dtype == "float")
                ty = Type::getFloatTy(Context);
            else if(d->dat->dtype == "char")
                ty = Type::getInt8Ty(Context);
            
            types[d->id->name] = d->dat->dtype;

            if(d->id->addrs.size() > 0){
                // It is an array
                int size = 1;
                vector <int> tmp_addrs;
                
                for(auto add: d->id->addrs){
                    ASTINTLIT* t = (ASTINTLIT*)(add);
                    size *= t->value;
                    tmp_addrs.push_back(t->value);
                }
                array_sizes[d->id->name] = tmp_addrs;
                ArrayType *arrType = ArrayType::get(ty, size);
                GlobalVariable *gv = new GlobalVariable(*(TheModule), arrType, false, GlobalValue::ExternalLinkage, nullptr, d->id->name);
                gv->setInitializer(ConstantAggregateZero::get(arrType));
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

Value* cast(Value* v, string type, string expected)
{
    if(type == expected)
        return v;
    if(type == "bool" && expected == "char")
        return CastInst::CreateIntegerCast(v, Type::getInt8Ty(Context), false, "", Builder.GetInsertBlock());
    if((type == "char" || type == "bool") && expected == "int")
        return CastInst::CreateIntegerCast(v, Type::getInt32Ty(Context), false, "", Builder.GetInsertBlock());
    if((type == "char" || type == "bool") && expected == "float"){
        return Builder.CreateUIToFP(v, Type::getFloatTy(Context));
        // return CastInst::CreateIntegerCast(v, Type::getFloatTy(Context), true, "", Builder.GetInsertBlock());
    }
    if(type == "int" && expected == "float")
        return Builder.CreateSIToFP(v, Type::getFloatTy(Context));
    if(type == "char" && expected == "bool")
        return CastInst::CreateIntegerCast(v, Type::getInt1Ty(Context), false, "", Builder.GetInsertBlock());
    if(type == "int" && expected == "char")
        return CastInst::CreateIntegerCast(v, Type::getInt8Ty(Context), false, "", Builder.GetInsertBlock());
    if(type == "int" && expected == "bool")
        return CastInst::CreateIntegerCast(v, Type::getInt1Ty(Context), false, "", Builder.GetInsertBlock());
    if(type == "char" && expected == "bool")
        return CastInst::CreateIntegerCast(v, Type::getInt1Ty(Context), false, "", Builder.GetInsertBlock());        
    if(type == "float" && expected == "int")
    {
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("float_to_int", Builder.getInt32Ty(), Builder.getFloatTy());
        return Builder.CreateCall(Fn, v);
    }
    if(type == "float" && expected == "char")
    {
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("float_to_char", Builder.getInt8Ty(), Builder.getFloatTy());
        return Builder.CreateCall(Fn, v);
    }
    if(type == "float" && expected == "bool")
    {
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("float_to_bool", Builder.getInt1Ty(), Builder.getFloatTy());
        return Builder.CreateCall(Fn, v);
    }
    return v;
}

int getKey2(string x)
{
    if(x == "bool")
        return 0;
    if(x == "char")
        return 1;
    if(x == "unint")
        return 2;
    if(x == "int")
        return 3;
    if(x == "float")
        return 4;
    if(x == "string")
        return 5;
    if(x == "file")
        return 6;
    return -1;
}

string getTypeString2(int v)
{
    if(v == 0)
        return "bool";
    if(v == 1)
        return "char";
    if(v == 2)
        return "uint";
    if(v == 3)
        return "int";
    if(v == 4)
        return "float";
    if(v == 5)
        return "string";
    if(v == 6)
        return "file";
    return "";
}

string getCastedType2(string a, string b)
{
    int x = getKey2(a);
    int y = getKey2(b);

    int t1 = min(x, y);
    int t2 = max(x, y);
    if(t1 == -1)
        return "";
    //if(t1 == 1 && t2 == 5)
    //    return getTypeString(t2);
    if(t2 == 5)
        return getTypeString2(t2);

    if((t1 == 5 || t2 == 5 || t1 == 6 || t2 == 6) && (t1 != t2))
        return "";

    return getTypeString2(t2); 

    //if(a == "bool" && b == "int")
    //    return "int";
    //if(a == "bool" && b == "float")
    //    return "float";
    //if(a == "bool" && )
}


Value* ASTExprBinary::Codegen()
{
    Value* operand1 = left->Codegen();
    Value* operand2 = right->Codegen();
    

    if(eval_type == "int" || eval_type == "char" || eval_type == "bool"){
        if(op == "+")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateAdd(operand1, operand2, "add");
        }
        else if(op == "-")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateSub(operand1, operand2, "sub");
        }
        else if(op == "*")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateMul(operand1, operand2, "mult");
        }
        else if(op == "/")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateSDiv(operand1, operand2, "div");
        }
        else if(op == "%")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateSRem(operand1, operand2, "mod");
        }
        else if(op == "<"){
            string exp = getCastedType2(left->eval_type, right->eval_type);
            operand1 = cast(operand1, left->eval_type, exp);
            operand2 = cast(operand2, right->eval_type, exp);
            if(exp == "float")
                return Builder.CreateFCmpULT(operand1, operand2, "ltcompare");
            else
                return Builder.CreateICmpSLT(operand1, operand2, "ltcompare");
        }
        else if(op == "<="){
            string exp = getCastedType2(left->eval_type, right->eval_type);
            operand1 = cast(operand1, left->eval_type, exp);
            operand2 = cast(operand2, right->eval_type, exp);
            if(exp == "float")
                return Builder.CreateFCmpULE(operand1, operand2, "lecompare");
            else
                return Builder.CreateICmpSLE(operand1, operand2, "lecompare");
        }
        else if(op == ">")
        {
            string exp = getCastedType2(left->eval_type, right->eval_type);
            operand1 = cast(operand1, left->eval_type, exp);
            operand2 = cast(operand2, right->eval_type, exp);
            if(exp == "float")
                return Builder.CreateFCmpUGT(operand1, operand2, "gtcompare");
            else
                return Builder.CreateICmpSGT(operand1, operand2, "gtcompare");
        }
        else if(op == ">=")
        {
            string exp = getCastedType2(left->eval_type, right->eval_type);
            operand1 = cast(operand1, left->eval_type, exp);
            operand2 = cast(operand2, right->eval_type, exp);
            if(exp == "float")
                return Builder.CreateFCmpUGE(operand1, operand2, "gecompare");        
            else
                return Builder.CreateICmpSGE(operand1, operand2, "gecompare");
        }
        else if(op == "!="){
            string exp = getCastedType2(left->eval_type, right->eval_type);
            operand1 = cast(operand1, left->eval_type, exp);
            operand2 = cast(operand2, right->eval_type, exp);
            if(exp == "float")
                return Builder.CreateFCmpUNE(operand1, operand2, "notequalcompare");
            else
                return Builder.CreateICmpNE(operand1, operand2, "notequalcompare");
        }
        else if(op == "==")
        {
            string exp = getCastedType2(left->eval_type, right->eval_type);
            operand1 = cast(operand1, left->eval_type, exp);
            operand2 = cast(operand2, right->eval_type, exp);
            if(exp == "float")
                return Builder.CreateFCmpUEQ(operand1, operand2, "equalcompare");
            else
                return Builder.CreateICmpEQ(operand1, operand2, "equalcompare");
        }
        else if(op == "||")
        {
            if(left->eval_type == "int")
                operand1 = Builder.CreateICmpNE(operand1, ConstantInt::get(Context, APInt(32, 0)), "ifcond");
            else if(left->eval_type == "char")
                operand1 = Builder.CreateICmpNE(operand1, ConstantInt::get(Context, APInt(8, 0)), "ifcond");                
            else if(left->eval_type == "bool")
                operand1 = operand1;
            else if(left->eval_type == "float")
                operand1 = Builder.CreateFCmpUNE(operand1, ConstantFP::get(Context, APFloat(0.0)), "ifcond");
            
            if(right->eval_type == "int")
                operand2 = Builder.CreateICmpNE(operand2, ConstantInt::get(Context, APInt(32, 0)), "ifcond");
            else if(right->eval_type == "char")
                operand2 = Builder.CreateICmpNE(operand2, ConstantInt::get(Context, APInt(8, 0)), "ifcond");                
            else if(right->eval_type == "bool")
                operand2 = operand2;
            else if(right->eval_type == "float")
                operand2 = Builder.CreateFCmpUNE(operand2, ConstantFP::get(Context, APFloat(0.0)), "ifcond");
            
            
            return Builder.Insert(BinaryOperator::Create(Instruction::Or, operand1, operand2, "doubleor"));
        }
        else if(op == "&&")
        {
            if(left->eval_type == "int")
                operand1 = Builder.CreateICmpNE(operand1, ConstantInt::get(Context, APInt(32, 0)), "ifcond");
            else if(left->eval_type == "char")
                operand1 = Builder.CreateICmpNE(operand1, ConstantInt::get(Context, APInt(8, 0)), "ifcond");                
            else if(left->eval_type == "bool")
                operand1 = operand1;
            else if(left->eval_type == "float")
                operand1 = Builder.CreateFCmpUNE(operand1, ConstantFP::get(Context, APFloat(0.0)), "ifcond");
            
            if(right->eval_type == "int")
                operand2 = Builder.CreateICmpNE(operand2, ConstantInt::get(Context, APInt(32, 0)), "ifcond");
            else if(right->eval_type == "char")
                operand2 = Builder.CreateICmpNE(operand2, ConstantInt::get(Context, APInt(8, 0)), "ifcond");                
            else if(right->eval_type == "bool")
                operand2 = operand2;
            else if(right->eval_type == "float")
                operand2 = Builder.CreateFCmpUNE(operand2, ConstantFP::get(Context, APFloat(0.0)), "ifcond");
            
            return Builder.Insert(BinaryOperator::Create(Instruction::And, operand1, operand2, "doubleand"));   
        }
    }
    else if(eval_type == "float")
    {
        if(op == "+")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateFAdd(operand1, operand2, "add");
        }
        else if(op == "-")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateFSub(operand1, operand2, "sub");
        }
        else if(op == "*")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateFMul(operand1, operand2, "mult");
        }
        else if(op == "/")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateFDiv(operand1, operand2, "div");
        }
        else if(op == "%")
        {
            operand1 = cast(operand1, left->eval_type, eval_type);
            operand2 = cast(operand2, right->eval_type, eval_type);
            return Builder.CreateFRem(operand1, operand2, "mod");
        }
    }
    return nullptr;
}
Value* ASTExprTernary::Codegen()
{
    Value *CondV = cond->Codegen();
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(Context, "true_block", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(Context, "false_block");
    BasicBlock *MergeBB = BasicBlock::Create(Context, "mergeBB");

    if(cond->eval_type == "int")
    {
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(32, 0)), "ifcond"); 
    }
    else if(cond->eval_type == "bool")
    {
        CondV = CondV;
    }
    else if(cond->eval_type == "float")
    {
        CondV = Builder.CreateFCmpUNE(CondV, ConstantFP::get(Context, APFloat(0.0)), "ifcond");
    }
    else if(cond->eval_type == "char")
    {
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(8, 0)), "ifcond");
    }
    

    Builder.CreateCondBr(CondV, ifBlock, elseBlock);
    
    
    Builder.SetInsertPoint(ifBlock);
    //required_extra_block += 1;
    Value *ThenV = true_expr->Codegen();
    //required_extra_block -= 1;
    Builder.CreateBr(MergeBB);
    ifBlock = Builder.GetInsertBlock();

    
    TheFunction->getBasicBlockList().push_back(elseBlock);
    Builder.SetInsertPoint(elseBlock);
    //required_extra_block += 1;
    Value *ElseV = false_expr->Codegen();
    //required_extra_block -= 1;
    Builder.CreateBr(MergeBB);
    // codegen of 'Else' can change the current block, update ElseBB for the PHI.
    elseBlock = Builder.GetInsertBlock();

    TheFunction->getBasicBlockList().push_back(MergeBB);
    Builder.SetInsertPoint(MergeBB);

    PHINode *PN;
    if(false_expr->eval_type == "int")
        PN = Builder.CreatePHI(Type::getInt32Ty(Context), 2, "iftmp");
    else if(false_expr->eval_type == "char")
        PN = Builder.CreatePHI(Type::getInt8Ty(Context), 2, "iftmp");
    else if(false_expr->eval_type == "bool")
        PN = Builder.CreatePHI(Type::getInt1Ty(Context), 2, "iftmp");
    else if(false_expr->eval_type == "float")
        PN = Builder.CreatePHI(Type::getFloatTy(Context), 2, "iftmp");
    PN->addIncoming(ThenV, ifBlock);
    PN->addIncoming(ElseV, elseBlock);
    return PN;
}
Value* ASTAssign::Codegen()
{
    if(NamedValues.find(id->name) == NamedValues.end()){
        if(id->addrs.size() > 0){
            // Array element.
            vector<Value *> array_index;
            array_index.push_back(Builder.getInt32(0));
            int l = array_sizes[id->name].size();
            Value* index = Builder.getInt32(0);
            for(int i = 0; i < l; ++i){
                Value *factor = id->addrs[i]->Codegen();
                for(int j = i + 1; j < l; ++j){
                    factor = Builder.CreateMul(factor, Builder.getInt32(array_sizes[id->name][j]));
                }
                index = Builder.CreateAdd(index, factor);
            }
            // index = Builder.CreateAdd(index, addrs[l - 1]->Codegen());
            Value *V = TheModule->getNamedGlobal(id->name);
            array_index.push_back(index);
            Builder.CreateStore(cast(expr->Codegen(), expr->eval_type, types[id->name]), Builder.CreateGEP(V, array_index, id->name + "_Index"));
        }
        else
            Builder.CreateStore(cast(expr->Codegen(), expr->eval_type, types[id->name]), TheModule->getNamedGlobal(id->name));
    }
    else
        Builder.CreateStore(cast(expr->Codegen(), expr->eval_type, types[id->name]) ,NamedValues[id->name]);
    return ConstantInt::get(Context, APInt(32, 1));
}
Value* ASTBlock::Codegen()
{
    //map <string, vector <int> > array_sizes_copy;
    map <string, AllocaInst*> NamedValues_copy;
    map < string, string > types_copy;
    NamedValues_copy = NamedValues;
    types_copy = types;
    //array_sizes_copy = array_sizes;
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
    types = types_copy;
    //array_sizes = array_sizes_copy;
    return V;
}
Value* ASTID::Codegen()
{
    if(NamedValues.find(name) == NamedValues.end()){
        if(addrs.size() > 0){
            // Array
            vector<Value *> array_index;
            array_index.push_back(Builder.getInt32(0));
            int l = array_sizes[name].size();
            Value* index = Builder.getInt32(0);
            for(int i = 0; i < l; ++i){
                Value *factor = addrs[i]->Codegen();
                for(int j = i + 1; j < l; ++j){
                    factor = Builder.CreateMul(factor, Builder.getInt32(array_sizes[name][j]));
                }
                index = Builder.CreateAdd(index, factor);
            }
            // index = Builder.CreateAdd(index, addrs[l - 1]->Codegen());
            Value *V = TheModule->getNamedGlobal(name);
            array_index.push_back(index);
            return Builder.CreateLoad(Builder.CreateGEP(V, array_index, name + "_Index"));
        }
        else{
            Value* V = TheModule->getNamedGlobal(name);
            return Builder.CreateLoad(V);
        }
        
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
    else if(return_type->dtype == "char")
    {
        ret_type = Type::getInt8Ty(Context);
    }
    else if(return_type->dtype == "float")
    {
        ret_type = Type::getFloatTy(Context);
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
        else if(param->dat->dtype == "char"){
            arguments.push_back(Type::getInt32Ty(Context));
        }
        else if(param->dat->dtype == "float"){
            arguments.push_back(Type::getFloatTy(Context));
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
    
    //map <string, vector<int> > array_sizes_copy;
    map <string, AllocaInst*> NamedValues_copy;
    map < string, string > types_copy;
    NamedValues_copy = NamedValues;
    types_copy = types;
    //array_sizes_copy = array_sizes;
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
    types = types_copy;
    //array_sizes = array_sizes_copy;
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
    if(id->addrs.size() > 0){
        // It it an array.
        // Should be caught in semantic analysis phase.
    }
    else{
        AllocaInst *allocaMem = allocateMemory(TheFunction, id->name, dat->dtype);
        NamedValues[id->name] = allocaMem;
    }
    
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
    return ConstantFP::get(Context, APFloat(value));
}
Value* ASTSTRINGLIT::Codegen()
{
    string v = "";
    for(int i = 1; i < value.size() - 1; ++i){
        if(value[i] == '\\' && value[i - 1] == '\\')
            v = v + '\\';
        else if(value[i] == 'n' && value[i - 1] == '\\')
            v = v + '\n';
        else if(value[i] == 't' && value[i - 1] == '\\')
            v = v + '\t';
        else if(value[i] == '\\')
            continue;
        else
            v = v + value[i];
    }
        
    return Builder.CreateGlobalStringPtr(StringRef(v));
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
    if(value.size() == 3)
        return ConstantInt::get(Context, APInt(8, (int)(value[1])));
    else if(value[2] == 'n')
        return ConstantInt::get(Context, APInt(8, (int)(10)));
    else if(value[2] == 't')
        return ConstantInt::get(Context, APInt(8, (int)(9)));
    else if(value[2] == '0')
        return ConstantInt::get(Context, APInt(8, (int)(0)));
}
Value* ASTExprCall::Codegen()
{
    Function *CalleeF = TheModule->getFunction(name);
    if(name == "fileGetChar"){
        //cout << "Hi\n";
        std::vector<Value *> ArgsV;
        for (unsigned i = 0, e = args.size(); i != e; ++i) {
            ArgsV.push_back(args[i]->Codegen());
        }        
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("fileGetChar", Builder.getInt8Ty(), Builder.getInt8PtrTy(), Builder.getInt32Ty());
        return Builder.CreateCall(Fn, ArgsV);
    }
    if (!CalleeF){
        // cout << "Unknown function referenced\n";
        
    }
        

    // If argument mismatch error.
    if (CalleeF->arg_size() != args.size())
        cout << "Incorrect # arguments passed\n";
    std::vector<Value *> ArgsV;
    for (unsigned i = 0, e = args.size(); i != e; ++i) {
        ArgsV.push_back(args[i]->Codegen());
    }
    return Builder.CreateCall(CalleeF, ArgsV);
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
    else if(expr->eval_type == "float")
    {
        CondV = Builder.CreateFCmpUNE(CondV, ConstantFP::get(Context, APFloat(0.0)), "ifcond");
    }
    else if(expr->eval_type == "char")
    {
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(8, 0)), "ifcond");
    }
    
    if(else_block != NULL)
        Builder.CreateCondBr(CondV, ifBlock, elseBlock);
    else
        Builder.CreateCondBr(CondV, ifBlock, MergeBB);
    
    Builder.SetInsertPoint(ifBlock);
    required_extra_block += 1;
    Value *ThenV = if_block->Codegen();
    required_extra_block -= 1;
    Builder.CreateBr(MergeBB);
    ifBlock = Builder.GetInsertBlock();

    if(else_block != NULL){
        TheFunction->getBasicBlockList().push_back(elseBlock);
        Builder.SetInsertPoint(elseBlock);
        required_extra_block += 1;
        Value *ElseV = else_block->Codegen();
        required_extra_block -= 1;
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
    Value* v = expr->Codegen();
    return Builder.CreateNot(v, "not");
}
Value* ASTNeg::Codegen()
{
    Value* v = expr->Codegen();
    if(expr->eval_type == "float")
        return Builder.CreateFNeg(v, "negation");
    else
        return Builder.CreateNeg(v, "negation");
}
Value* Inp::Codegen()
{
    if(eval_type == "int")
    {
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("readint", Builder.getInt32Ty());
        return Builder.CreateCall(Fn);
    }
    else if(eval_type == "bool")
    {
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("readchar", Builder.getInt1Ty());
        return Builder.CreateCall(Fn);
    }
    else if(eval_type == "char")
    {
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("readchar", Builder.getInt8Ty());
        return Builder.CreateCall(Fn);
    }
    else if(eval_type == "float")
    {
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("readfloat", Builder.getFloatTy());
        return Builder.CreateCall(Fn);
    }
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
    else if(expr->eval_type == "bool"){
        Value* Version = expr->Codegen();
        auto Int1Ty = Builder.getInt1Ty();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printbool", Builder.getVoidTy(), Int1Ty);
        return Builder.CreateCall(Fn, Version);
    }
    else if(expr->eval_type == "char"){
        Value* Version = expr->Codegen();
        auto Int8Ty = Builder.getInt8Ty();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printchar", Builder.getVoidTy(), Int8Ty);
        return Builder.CreateCall(Fn, Version);
    }
    else if(expr->eval_type == "float")
    {
        Value* Version = expr->Codegen();
        auto FloatTy = Builder.getFloatTy();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printfloat", Builder.getVoidTy(), FloatTy);
        return Builder.CreateCall(Fn, Version);
    }
    else if(expr->eval_type == "string")
    {
        Value* Version = expr->Codegen();
        auto FloatTy = Builder.getInt8PtrTy();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printstring", Builder.getVoidTy(), FloatTy);
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
    else if(expr->eval_type == "bool"){
        Value* Version = expr->Codegen();
        auto Int1Ty = Builder.getInt1Ty();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printlnbool", Builder.getVoidTy(), Int1Ty);
        return Builder.CreateCall(Fn, Version);
    }
    else if(expr->eval_type == "char"){
        Value* Version = expr->Codegen();
        auto Int8Ty = Builder.getInt8Ty();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printlnchar", Builder.getVoidTy(), Int8Ty);
        return Builder.CreateCall(Fn, Version);
    }
    else if(expr->eval_type == "float")
    {
        Value* Version = expr->Codegen();
        auto FloatTy = Builder.getFloatTy();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printlnfloat", Builder.getVoidTy(), FloatTy);
        return Builder.CreateCall(Fn, Version);
    }
    else if(expr->eval_type == "string")
    {
        Value* Version = expr->Codegen();
        auto FloatTy = Builder.getInt8PtrTy();
        auto M = Builder.GetInsertBlock()->getModule();
        auto Fn = M->getOrInsertFunction("printlnstring", Builder.getVoidTy(), FloatTy);
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
    else if(exprs[0]->eval_type == "char")
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(8, 0)), "for_cond");
    else if(exprs[0]->eval_type == "float")
        CondV = Builder.CreateFCmpUNE(CondV, ConstantFP::get(Context, APFloat(0.0)), "for_cond");
    Builder.CreateCondBr(CondV, loopBB, afterLoopBB);
    
    TheFunction->getBasicBlockList().push_back(loopBB);
    Builder.SetInsertPoint(loopBB);

    BasicBlock *prevBreak = Break;
    BasicBlock *prevContinue = Continue;
    Continue = endAssnBB;
    Break = afterLoopBB;
    required_extra_block += 1;
    Value* v = block->Codegen();
    required_extra_block -= 1;
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
    else if(expr->eval_type == "char")
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(8, 0)), "for_cond");
    else if(expr->eval_type == "float")
        CondV = Builder.CreateFCmpUNE(CondV, ConstantFP::get(Context, APFloat(0.0)), "for_cond");
    Builder.CreateCondBr(CondV, loopBB, afterLoopBB);
    Builder.SetInsertPoint(loopBB);

    BasicBlock *prevBreak = Break;
    BasicBlock *prevContinue = Continue;
    Continue = endAssnBB;
    Break = afterLoopBB;
    required_extra_block += 1;
    Value* v = block->Codegen();
    required_extra_block -= 1;
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
    else if(expr->eval_type == "char")
        CondV = Builder.CreateICmpNE(CondV, ConstantInt::get(Context, APInt(8, 0)), "for_cond");
    else if(expr->eval_type == "float")
        CondV = Builder.CreateFCmpUNE(CondV, ConstantFP::get(Context, APFloat(0.0)), "for_cond");
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
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    BasicBlock *returnBB = BasicBlock::Create(Context, "return", TheFunction);
    BasicBlock *afterReturn = BasicBlock::Create(Context, "after_return");
    Builder.CreateBr(returnBB);
    Builder.SetInsertPoint(returnBB);
    
    if(expr == NULL)
        Builder.CreateRetVoid();
    else
        Builder.CreateRet(expr->Codegen());

    if(required_extra_block > 0){
        TheFunction->getBasicBlockList().push_back(afterReturn);
        Builder.SetInsertPoint(afterReturn);
    }
    
    return ConstantInt::get(Context, APInt(32, 1));
}
Value* ASTCast::Codegen()
{
    Value *v = expr->Codegen();
    return cast(v, expr->eval_type, dat->dtype);
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