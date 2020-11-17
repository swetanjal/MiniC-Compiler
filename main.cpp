#include <bits/stdc++.h>

#include "antlr4-runtime.h"
#include "MiniCLexer.cpp"
#include "MiniCParser.cpp"

#include "MiniCBuildASTVisitor.h"

#include "PrettyPrint.h"
//#include "ast.h"
#include "common.h"
using namespace std;
using namespace antlr4;
int errors_IR = 0;
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
    ASTProg* root = new ASTProg();
    root->Codegen();
    if(errors_IR == 0)
        root->generateCodeDump();
    return 0;
}
