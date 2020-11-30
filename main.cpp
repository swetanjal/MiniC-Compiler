#include <bits/stdc++.h>

#include "antlr4-runtime.h"
#include "MiniCLexer.cpp"
#include "MiniCParser.cpp"
#include "ast.h"
#include "MiniCBuildASTVisitor.h"

#include "PrettyPrint.h"
//#include "ast.h"
#include "common.h"
using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;

    cout << "Processing input file " << argv[1] << endl;
    stream.open(argv[1]);
    
    ANTLRInputStream input(stream);

    MiniCLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MiniCParser parser(&tokens);    
    curr_table->prev = NULL;
    MiniCParser::ProgramContext *ctx = parser.program();
    MiniCVisitor *visitor = new MiniCBuildASTVisitor();

    ASTProg *program_root = visitor->visitProgram(ctx);
    cout << "********** Pretty Printing the program **********\n";    
    PrettyPrint *pv = new PrettyPrint();
    pv->visit(*program_root);
    // Time to generate LLVM IR
    
    if(errors_IR == 0){
        program_root->Codegen();
        program_root->generateCodeDump();
    }
        
    else
    {
        std::vector<Type*> Doubles(0,
                             Type::getDoubleTy(Context));
        FunctionType *FT = FunctionType::get(Type::getVoidTy(Context), Doubles, false);
        Function *F = Function::Create(FT, Function::ExternalLinkage, "main", TheModule);
        BasicBlock *BB = BasicBlock::Create(Context, "entry", F);
        Builder.SetInsertPoint(BB);
        AllocaInst *allocaMem = allocateMemory(F, "a", "int");
        NamedValues["a"] = allocaMem;
        Builder.CreateStore(ConstantInt::get(Context, APInt(32, 1)) ,allocaMem);
        Builder.CreateRetVoid();
        
        verifyFunction(*F);
        //cerr << "Generating LLVM IR Code\n\n";
        std::string Str;
        raw_string_ostream OS(Str);
        OS << *TheModule;
        OS.flush();
        ofstream out("llvmir.bc");
        out << Str;
        out.close();
        //cerr << "Finished writing to llvmir.bc\n";
    }
    return 0;
}
