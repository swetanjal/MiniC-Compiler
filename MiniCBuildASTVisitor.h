#include <bits/stdc++.h>
#include "ast.h"
#include "MiniCVisitor.h"
#include "symboltable.h"
using namespace std;

void add(ASTVarDecl* node)
{
    if(curr_table->method_decl.find(node->id->name) != curr_table->method_decl.end() || curr_table->var_decl.find(node->id->name) != curr_table->var_decl.end()){
        cout << "Semantic Error: Variable " << node->id->name << " is being redeclared.\n"; 
    }
    else{
        curr_table->var_decl[node->id->name].push_back(NULL);
        curr_table->dims[node->id->name] = node->id->addrs.size();
    }
}

void add(ASTMethodDecl* node)
{
    if(curr_table->method_decl.find(node->name) != curr_table->method_decl.end() || curr_table->var_decl.find(node->name) != curr_table->var_decl.end()){
        cout << "Semantic Error: Method " << node->name << " is being redeclared.\n"; 
    }
    else{
        curr_table->method_decl[node->name] = node;
    }
}

class MiniCBuildASTVisitor : public MiniCVisitor
{
    public:
    virtual antlrcpp::Any visitProgram(MiniCParser::ProgramContext *context) override
    {
        ASTProg *node = new ASTProg();
        for(auto decl: context->decl()){
            vector <ASTDecl*> vec = visit(decl);
            for(auto it: vec){
                node->declarations.push_back(it);
            }
        }
        return node;
    }

    virtual antlrcpp::Any visitVarDecl(MiniCParser::VarDeclContext *ctx) override {
        return visit(ctx->var_decl());
    }

    virtual antlrcpp::Any visitMethodDecl(MiniCParser::MethodDeclContext *ctx) override {
        return visit(ctx->method_decl());
    }

    virtual antlrcpp::Any visitVar_decl(MiniCParser::Var_declContext *ctx) override {
        vector <ASTDecl*> vec;
        int c = 0;
        while(ctx->identifier(c) != NULL){
            ASTVarDecl *node = new ASTVarDecl();
            node -> type = "var";
            node->dat = visit(ctx->type());

            node->id = visit(ctx->identifier(c));
            
            add(node);

            vec.push_back(node);
            c++;
        }
        return vec;
        // return (ASTDecl *)node;
    }

    virtual antlrcpp::Any visitMethod_decl_type(MiniCParser::Method_decl_typeContext *context) override
    {
        vector <ASTDecl*> vec;
        ASTMethodDecl *node = new ASTMethodDecl();
        node -> type = "meth";
        node->return_type = visit(context->type(0));
        node->name = context->ID()->getText();

        int c = 1;
        while(context->type(c) != NULL){
            ASTVarDecl *node_tmp = new ASTVarDecl;
            node_tmp->type = "var";
            node_tmp->dat = visit(context->type(c));
            node_tmp->id = visit(context->identifier(c - 1));

            add(node_tmp);


            node->args.push_back(node_tmp);
            c++;
        }
        node->block = visit(context->block());

        add(node);

        vec.push_back(node);
        return vec;
        // return (ASTDecl *)node;
    }

    virtual antlrcpp::Any visitMethod_decl_void(MiniCParser::Method_decl_voidContext *context) override
    {
        vector <ASTDecl*> vec;
        ASTMethodDecl *node = new ASTMethodDecl();
        node -> type = "meth";
        node->return_type = NULL;
        node->name = context->ID()->getText();

        int c = 0;
        while(context->type(c) != NULL){
            ASTVarDecl *node_tmp = new ASTVarDecl;
            node_tmp->type = "var";
            node_tmp->dat = visit(context->type(c));
            node_tmp->id = visit(context->identifier(c));
            
            add(node_tmp);
            
            node->args.push_back(node_tmp);
            c++;
        }

        node->block = visit(context->block());
        
        add(node);

        vec.push_back(node);
        return vec;
        // return (ASTDecl *)node;
    }

    virtual antlrcpp::Any visitBlock(MiniCParser::BlockContext *ctx) override {
        ASTBlock *node = new ASTBlock();

        int c = 0;
        while(ctx->var_decl(c) != NULL){
            vector <ASTDecl*> vec = visit(ctx->var_decl(c));
            for(auto it: vec)
                node->var_declarations.push_back(it);
            c++;
        }
        // cout << node->var_declarations.size() << " declarations\n";
        c = 0;
        while(ctx->statement(c) != NULL){
            node->statements.push_back(visit(ctx->statement(c)));
            c++;
        }
        // cout << node->statements.size() << " statements\n";
        return (ASTBlock *)node;
    }

    virtual antlrcpp::Any visitTypeInt(MiniCParser::TypeIntContext *ctx) override {
        ASTDtype *node = new ASTDtype();
        node->dtype = "int";
        return (ASTDtype *)node;
    }

    virtual antlrcpp::Any visitTypeUint(MiniCParser::TypeUintContext *ctx) override {
        ASTDtype *node = new ASTDtype();
        node->dtype = "uint";
        return (ASTDtype *)node;
    }

    virtual antlrcpp::Any visitTypeBool(MiniCParser::TypeBoolContext *ctx) override {
        ASTDtype *node = new ASTDtype();
        node->dtype = "bool";
        return (ASTDtype *)node;
    }

    virtual antlrcpp::Any visitTypeChar(MiniCParser::TypeCharContext *ctx) override {
        ASTDtype *node = new ASTDtype();
        node->dtype = "char";
        return (ASTDtype *)node;
    }

    virtual antlrcpp::Any visitTypeFile(MiniCParser::TypeFileContext *ctx) override {
        ASTDtype *node = new ASTDtype();
        node->dtype = "file";
        return (ASTDtype *)node;
    }

    virtual antlrcpp::Any visitTypeString(MiniCParser::TypeStringContext *ctx) override {
        ASTDtype *node = new ASTDtype();
        node->dtype = "string";
        return (ASTDtype *)node;
    }

    virtual antlrcpp::Any visitTypeFloat(MiniCParser::TypeFloatContext *ctx) override {
        ASTDtype *node = new ASTDtype();
        node->dtype = "float";
        return (ASTDtype *)node;
    }

    virtual antlrcpp::Any visitListAssn(MiniCParser::ListAssnContext *ctx) override {
        ASTStatAssn *node = new ASTStatAssn();
        int c = 0;
        while(ctx->assignment(c) != NULL){
            node->assignments.push_back(visit(ctx->assignment(c)));
            c++;
        }
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitMethodCall(MiniCParser::MethodCallContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIf(MiniCParser::IfContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFor(MiniCParser::ForContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitWhile(MiniCParser::WhileContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitBreak(MiniCParser::BreakContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitContiue(MiniCParser::ContiueContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitBlck(MiniCParser::BlckContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitReturn(MiniCParser::ReturnContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPrint(MiniCParser::PrintContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPrintln(MiniCParser::PrintlnContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitAssignment(MiniCParser::AssignmentContext *ctx) override {
        ASTAssign *node = new ASTAssign();
        node->id = visit(ctx->identifier());
        node->expr = visit(ctx->expr());

        // cout << ((ASTINTLIT*)(node->expr))->value;
        return (ASTAssign *) node;
    }

    virtual antlrcpp::Any visitMethod_call(MiniCParser::Method_callContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitExpr(MiniCParser::ExprContext *ctx) override {
        return visit(ctx->expr8());
    }

    virtual antlrcpp::Any visitExpr8_7(MiniCParser::Expr8_7Context *ctx) override {
        return visit(ctx->expr7());
    }

    virtual antlrcpp::Any visitTernary_expr(MiniCParser::Ternary_exprContext *ctx) override {
        ASTExprTernary *node = new ASTExprTernary();
        node->cond = visit(ctx->expr8(0));
        node->true_expr = visit(ctx->expr8(1));
        node->false_expr = visit(ctx->expr8(2));
        node->type = "ter";
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr7_6(MiniCParser::Expr7_6Context *ctx) override {
        return visit(ctx->expr6());
    }

    virtual antlrcpp::Any visitOr_expr(MiniCParser::Or_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "|";
        node->type = "bin";
        node->left = visit(ctx->expr7());
        node->right = visit(ctx->expr6());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitAnd_expr(MiniCParser::And_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "&";
        node->type = "bin";
        node->left = visit(ctx->expr6());
        node->right = visit(ctx->expr5());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr6_5(MiniCParser::Expr6_5Context *ctx) override {
        return visit(ctx->expr5());
    }

    virtual antlrcpp::Any visitEq_expr(MiniCParser::Eq_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "==";
        node->type = "bin";
        node->left = visit(ctx->expr5());
        node->right = visit(ctx->expr4());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr5_4(MiniCParser::Expr5_4Context *ctx) override {
        return visit(ctx->expr4());
    }

    virtual antlrcpp::Any visitNe_expr(MiniCParser::Ne_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "!=";
        node->type = "bin";
        node->left = visit(ctx->expr5());
        node->right = visit(ctx->expr4());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitGe_expr(MiniCParser::Ge_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = ">=";
        node->type = "bin";
        node->left = visit(ctx->expr4());
        node->right = visit(ctx->expr3());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitGt_expr(MiniCParser::Gt_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = ">";
        node->type = "bin";
        node->left = visit(ctx->expr4());
        node->right = visit(ctx->expr3());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr4_3(MiniCParser::Expr4_3Context *ctx) override {
        return visit(ctx->expr3());
    }

    virtual antlrcpp::Any visitLt_expr(MiniCParser::Lt_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "<";
        node->type = "bin";
        node->left = visit(ctx->expr3());
        node->right = visit(ctx->expr2());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr3_2(MiniCParser::Expr3_2Context *ctx) override {
        return visit(ctx->expr2());
    }

    virtual antlrcpp::Any visitLe_expr(MiniCParser::Le_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "<=";
        node->type = "bin";
        node->left = visit(ctx->expr3());
        node->right = visit(ctx->expr2());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitSub_expr(MiniCParser::Sub_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "-";
        node->type = "bin";
        node->left = visit(ctx->expr2());
        node->right = visit(ctx->expr1());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitAdd_expr(MiniCParser::Add_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "+";
        node->type = "bin";
        node->left = visit(ctx->expr2());
        node->right = visit(ctx->expr1());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr2_1(MiniCParser::Expr2_1Context *ctx) override {
        return visit(ctx->expr1());
    }

    virtual antlrcpp::Any visitMod_expr(MiniCParser::Mod_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->type = "bin";
        node->op = "%";
        node->left = visit(ctx->expr1());
        node->right = visit(ctx->expr0());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr1_0(MiniCParser::Expr1_0Context *ctx) override {
        return visit(ctx->expr0());
    }

    virtual antlrcpp::Any visitDiv_expr(MiniCParser::Div_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->type = "bin";
        node->op = "/";
        node->left = visit(ctx->expr1());
        node->right = visit(ctx->expr0());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitMul_expr(MiniCParser::Mul_exprContext *ctx) override {
        ASTExprBinary *node = new ASTExprBinary();
        node->type = "bin";
        node->op = "*";
        node->left = visit(ctx->expr1());
        node->right = visit(ctx->expr0());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitId_expr(MiniCParser::Id_exprContext *ctx) override {
        return (ASTExpr *)visit(ctx->identifier());
    }

    virtual antlrcpp::Any visitLit_expr(MiniCParser::Lit_exprContext *ctx) override {
        return (ASTExpr *)visit(ctx->literal());
    }

    virtual antlrcpp::Any visitCall_expr(MiniCParser::Call_exprContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitNot_expr(MiniCParser::Not_exprContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitNegate_expr(MiniCParser::Negate_exprContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitBracket_expr(MiniCParser::Bracket_exprContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitInp_int(MiniCParser::Inp_intContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitInp_char(MiniCParser::Inp_charContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitInp_bool(MiniCParser::Inp_boolContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitVar(MiniCParser::VarContext *ctx) override {
        ASTID* node = new ASTID();
        node->name = ctx->ID()->getText();
        return (ASTID *)node;
    }

    virtual antlrcpp::Any visitVar_array(MiniCParser::Var_arrayContext *ctx) override {
        ASTID* node = new ASTID();
        node->name = ctx->ID()->getText();
        int c = 0;
        while(ctx->expr(c) != NULL){
            node->addrs.push_back(visit(ctx->expr(c)));
            c++;
        }
        return (ASTID *)node;
    }

    virtual antlrcpp::Any visitInt_lit(MiniCParser::Int_litContext *ctx) override {
        ASTINTLIT *node = new ASTINTLIT();
        node->type = "int_lit";
        node->eval_type = "int";
        node->value = stoi(ctx->INT_LIT()->getText());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitFloat_lit(MiniCParser::Float_litContext *ctx) override {
        ASTFLOATLIT *node = new ASTFLOATLIT();
        node->type = "float_lit";
        node->eval_type = "float";
        node->value = stof(ctx->FLOAT_LIT()->getText());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitChar_lit(MiniCParser::Char_litContext *ctx) override {
        ASTCHARLIT *node = new ASTCHARLIT();
        node->type = "char_lit";
        node->eval_type = "char";
        node->value = (ctx->CHAR_LIT()->getText())[0];
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitStr_lit(MiniCParser::Str_litContext *ctx) override {
        ASTSTRINGLIT *node = new ASTSTRINGLIT();
        node->type = "string_lit";
        node->eval_type = "string";
        node->value = (ctx->STRING_LIT()->getText());
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitBool_literal(MiniCParser::Bool_literalContext *ctx) override {
        return visit(ctx->bool_lit());
    }

    virtual antlrcpp::Any visitTrue_lit(MiniCParser::True_litContext *ctx) override {
        ASTBOOLLIT *node = new ASTBOOLLIT();
        node->type = "bool_lit";
        node->eval_type = "bool";
        node->value = "true";
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitFalse_lit(MiniCParser::False_litContext *ctx) override {
        ASTBOOLLIT *node = new ASTBOOLLIT();
        node->type = "bool_lit";
        node->value = "false";
        node->eval_type = "bool";
        return (ASTExpr *)node;
    }
};