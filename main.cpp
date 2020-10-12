#include <bits/stdc++.h>

#include "antlr4-runtime.h"
#include "MiniCLexer.cpp"
#include "MiniCParser.cpp"

#include "MiniCBuildASTVisitor.h"

// #include "PostfixVisitor.h"
//#include "ast.h"

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

    MiniCParser::ProgramContext *ctx = parser.program();

    MiniCVisitor *visitor = new MiniCBuildASTVisitor();

    ASTProg *program_root = visitor->visitProgram(ctx);
    
    /*PostFixVisitor *pv = new PostFixVisitor();
    pv->visit(*program_root);
    */
    return 0;
}
