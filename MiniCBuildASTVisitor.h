#include <bits/stdc++.h>
#include "ast.h"
#include "MiniCVisitor.h"
#include "symboltable.h"
using namespace std;

bool insideMethod = false;
string datatype_method = "";
int insideLoop = 0;

void add(ASTVarDecl* node, int line)
{
    if(curr_table->method_decl.find(node->id->name) != curr_table->method_decl.end() || curr_table->var_decl.find(node->id->name) != curr_table->var_decl.end()){
        cout << "Semantic Error on line " << line << ": Variable " << node->id->name << " is being redeclared.\n"; 
    }
    else{
        curr_table->var_decl[node->id->name] = node;
        curr_table->dims[node->id->name] = node->id->addrs.size();
    }
}

void add(ASTMethodDecl* node, int line)
{
    if(curr_table->method_decl.find(node->name) != curr_table->method_decl.end() || curr_table->var_decl.find(node->name) != curr_table->var_decl.end()){
        cout << "Semantic Error on line " << line << ": Method " << node->name << " is being redeclared.\n"; 
    }
    else{
        curr_table->method_decl[node->name] = node;
    }
}

void create_table()
{
    SymbolTable *tmp = new SymbolTable();
    tmp->prev = curr_table;
    curr_table = tmp;
}

void parent_table()
{
    curr_table = curr_table -> prev;
}

ASTDtype* look_up_variable(ASTID* node, int line)
{
    SymbolTable *curr = new SymbolTable();
    curr = curr_table;
    //cout << node->name << " " << curr->method_decl.size() << endl;
    while(curr != NULL){
        if(curr->method_decl.find(node->name) != curr->method_decl.end()){
            cout << "Semantic Error on line " << line << ": Conflicting Method name " << node->name << endl;
            return NULL;
            break;
        }
        else if(curr->var_decl.find(node->name) != curr->var_decl.end()){
            // TO be changed
            return (curr->var_decl[node->name])->dat;
        }
        curr = curr->prev;
    }
    cout << "Semantic Error on line " << line << ": Variable " << node->name <<  " being used before declaration\n";
    return NULL;
}

int getDimensions(ASTID* node, int line)
{
    SymbolTable *curr = new SymbolTable();
    curr = curr_table;
    //cout << node->name << " " << curr->method_decl.size() << endl;
    while(curr != NULL){
        if(curr->method_decl.find(node->name) != curr->method_decl.end()){
            cout << "Semantic Error on line " << line << ": Conflicting Method name " << node->name << endl;
            return -1;
            break;
        }
        else if(curr->var_decl.find(node->name) != curr->var_decl.end()){
            // TO be changed
            return curr->dims[node->name];
        }
        curr = curr->prev;
    }
    cout << "Semantic Error on line " << line << ": Variable " << node->name <<  " being used before declaration\n";
    return -1;
}




bool foundMethod(string id, int line)
{
    SymbolTable *curr = new SymbolTable();
    curr = curr_table;
    while(curr != NULL){
        if(curr->var_decl.find(id) != curr->var_decl.end()){
            // TO be changed
            cout << "Semantic Error on line " << line << ": "<< id << "() cannot be used as a function." << endl;
            return false;
        }
        else if(curr->method_decl.find(id) != curr->method_decl.end()){
            return true;
        }
        
        curr = curr->prev;
    }
    cout << "Semantic Error on line " << line << ": Method " << id <<  "() being called before declaration\n";
    return false;
}

ASTDtype* look_up_method(string id, int line)
{
    SymbolTable *curr = new SymbolTable();
    curr = curr_table;
    while(curr != NULL){
        if(curr->var_decl.find(id) != curr->var_decl.end()){
            // TO be changed
            cout << "Semantic Error on line " << line << ": "<< id << "() cannot be used as a function." << endl;
            return NULL;
        }
        else if(curr->method_decl.find(id) != curr->method_decl.end()){
            return curr->method_decl[id]->return_type;
        }
        
        curr = curr->prev;
    }
    cout << "Semantic Error on line " << line << ": Method " << id <<  "() being called before declaration\n";
    return NULL;
}

vector <ASTDtype*> getArgTypes(string id, int line){
    SymbolTable *curr = new SymbolTable();
    curr = curr_table;

    vector <ASTDtype*> dummy;
    while(curr != NULL){
        if(curr->var_decl.find(id) != curr->var_decl.end()){
            // TO be changed
            cout << "Semantic Error on line " << line << ": "<< id << "() cannot be used as a function." << endl;
            return dummy;
        }
        else if(curr->method_decl.find(id) != curr->method_decl.end()){
            ASTMethodDecl* tmp = curr->method_decl[id];
            vector <ASTDtype* > vec;
            for(auto el: tmp->args)
            {
                vec.push_back(el->dat);
            }
            return vec;
        }
        
        curr = curr->prev;
    }
    cout << "Semantic Error on line " << line << ": Method " << id <<  "() being called before declaration\n";
    return dummy;
}

int getKey(string x)
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

string getTypeString(int v)
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

string getCastedType(string a, string b)
{
    int x = getKey(a);
    int y = getKey(b);

    int t1 = min(x, y);
    int t2 = max(x, y);
    if(t1 == -1)
        return "";
    //if(t1 == 1 && t2 == 5)
    //    return getTypeString(t2);
    if(t2 == 5)
        return getTypeString(t2);

    if((t1 == 5 || t2 == 5 || t1 == 6 || t2 == 6) && (t1 != t2))
        return "";

    return getTypeString(t2); 

    //if(a == "bool" && b == "int")
    //    return "int";
    //if(a == "bool" && b == "float")
    //    return "float";
    //if(a == "bool" && )
}

string addSubMulDivCompatible(string a)
{
    if(a == "int")
        return "int";
    if(a == "float")
        return "float";
    if(a == "string")
        return "";
    if(a == "char")
        return "int";
    if(a == "unit")
        return "int";
    if(a == "bool")
        return "int";
    if(a == "file")
        return "";
    return "";
}

string modCompatible(string a)
{
    if(a == "int")
        return "int";
    return "";
}

string logicalCompatible(string a)
{
    if(a == "")
        return "";
    if(a == "bool")
        return "bool";
    if(a == "int")
        return "bool";
    
    if(a == "char")
        return "bool";
    if(a == "string")
        return "bool";
    if(a == "uint")
        return "bool";
    if(a == "float")
        return "bool";
    return "";
}

string relationalCompatible(string a)
{
    if(a == "")
        return "";
    if(a == "int")
        return "bool";
    if(a == "float")
        return "bool";
    if(a == "string")
        return "";
    if(a == "char")
        return "bool";
    if(a == "unit")
        return "bool";
    if(a == "bool")
        return "bool";
    if(a == "file")
        return "";
    return "";
}

bool canBeAssigned(string a, string b)
{
    // Can be assigned to a.
    int exp = getKey(a);
    int got = getKey(b);

    if(exp == 5 && got != 5)
        return false;
    if(exp == 6 && got != 6)
        return false;
    
    if(a == "bool" && b == "bool")
        return true;
    if(a == "bool" && b == "char")
        return false;
    if(a == "bool" && b == "uint")
        return false;
    if(a == "bool" && b == "int")
        return false;
    if(a == "bool" && b == "float")
        return false;

    if(a == "char" && b == "bool")
        return true;
    if(a == "char" && b == "char")
        return true;
    if(a == "char" && b == "uint")
        return false;
    if(a == "char" && b == "int")
        return false;
    if(a == "char" && b == "float")
        return false;
    
    if(a == "uint" && b == "bool")
        return true;
    if(a == "uint" && b == "char")
        return true;
    if(a == "uint" && b == "uint")
        return true;
    if(a == "uint" && b == "int")
        return false;
    if(a == "uint" && b == "float")
        return false;


    if(a == "int" && b == "bool")
        return true;
    if(a == "int" && b == "char")
        return true;
    if(a == "int" && b == "uint")
        return true;
    if(a == "int" && b == "int")
        return true;
    if(a == "int" && b == "float")
        return false;

    if(a == "float")
        return true;
    if(a == "string" && b == "string")
        return true;
    if(a == "file" && b == "file")
        return true;
    return false;
}

bool possibleToCast(string a, string b)
{
    // Can be assigned to a.
    int exp = getKey(a);
    int got = getKey(b);

    if(exp == 5 && got != 5)
        return false;
    if(exp == 6 && got != 6)
        return false;
    return true;
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
        int line = (ctx->start)->getLine();
        vector <ASTDecl*> vec;
        int c = 0;
        while(ctx->identifier(c) != NULL){
            ASTVarDecl *node = new ASTVarDecl();
            node -> type = "var";
            node->dat = visit(ctx->type());
            node->val = NULL;
            node->id = visit(ctx->identifier(c));
            
            add(node, line);

            vec.push_back(node);
            c++;
        }
        return vec;
        // return (ASTDecl *)node;
    }

    virtual antlrcpp::Any visitMethod_decl_type(MiniCParser::Method_decl_typeContext *context) override
    {
        int line = (context->start)->getLine();
        vector <ASTDecl*> vec;
        ASTMethodDecl *node = new ASTMethodDecl();
        node -> type = "meth";
        node->return_type = visit(context->type(0));
        node->name = context->ID()->getText();


        int c = 1;
        
        add(node, line);
        create_table();

        while(context->type(c) != NULL){
            ASTVarDecl *node_tmp = new ASTVarDecl;
            node_tmp->type = "var";
            node_tmp->dat = visit(context->type(c));
            node_tmp->id = visit(context->identifier(c - 1));
            node_tmp->val = NULL;
            add(node_tmp, line);


            node->args.push_back(node_tmp);
            c++;
        }
        datatype_method = node->return_type->dtype;
        node->block = visit(context->block());
        datatype_method = "";
        vec.push_back(node);
        parent_table();
        return vec;
        // return (ASTDecl *)node;
    }

    virtual antlrcpp::Any visitMethod_decl_void(MiniCParser::Method_decl_voidContext *context) override
    {
        int line = (context->start)->getLine();
        vector <ASTDecl*> vec;
        ASTMethodDecl *node = new ASTMethodDecl();
        node -> type = "meth";
        node->return_type = NULL;
        node->name = context->ID()->getText();

        

        int c = 0;

        add(node, line);

        create_table();

        while(context->type(c) != NULL){
            ASTVarDecl *node_tmp = new ASTVarDecl;
            node_tmp->type = "var";
            node_tmp->dat = visit(context->type(c));
            node_tmp->id = visit(context->identifier(c));
            node_tmp->val = NULL;
            add(node_tmp, line);
            
            node->args.push_back(node_tmp);
            c++;
        }
        datatype_method = "void";
        node->block = visit(context->block());
        datatype_method = "";
        vec.push_back(node);
        parent_table();
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
        node->type = "assn_lst";
        int c = 0;
        while(ctx->assignment(c) != NULL){
            node->assignments.push_back(visit(ctx->assignment(c)));
            c++;
        }
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitMethodCall(MiniCParser::MethodCallContext *ctx) override {
        auto tmp = visit(ctx->method_call());
        ASTStatCall *node = new ASTStatCall();
        node->type = "stat_call";
        node->expr = tmp;
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitIf(MiniCParser::IfContext *ctx) override {
        ASTIFStat *node = new ASTIFStat();
        node->type = "if";
        node->expr = visit(ctx->expr());
        node->if_block = visit(ctx->block(0));
        node->else_block = NULL;
        if(ctx->block(1) != NULL)
            node->else_block = visit(ctx->block(1));
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitFor(MiniCParser::ForContext *ctx) override {
        ASTFor *node = new ASTFor();
        node->type = "for";
        int c = 0;
        while(ctx->expr(c) != NULL){
            node->exprs.push_back(visit(ctx->expr(c)));
            c++;
        }
        
        c = 0;
        while(ctx->assignmentbeg(c) != NULL){
            node->beg_assigns.push_back(visit(ctx->assignmentbeg(c)));
            c++;
        }

        c = 0;
        while(ctx->assignment(c) != NULL){
            node->assigns.push_back(visit(ctx->assignment(c)));
            c++;
        }
        insideLoop++;
        node->block = visit(ctx->block());
        insideLoop--;
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitAssignmentbeg(MiniCParser::AssignmentbegContext *context)
    {
        return visit(context->assignment());
    };

    virtual antlrcpp::Any visitWhile(MiniCParser::WhileContext *ctx) override {
        ASTWhile *node = new ASTWhile();
        node->type = "while";
        node->expr = visit(ctx->expr());
        insideLoop++;
        node->block = visit(ctx->block());
        insideLoop--;
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitBreak(MiniCParser::BreakContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTBreak *node = new ASTBreak();
        node->type = "break";
        if(insideLoop == 0){
            cout << "Semantic Error on line " << line << ": Encountered break statement outside Loop block.\n";
        }
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitContiue(MiniCParser::ContiueContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTContinue *node = new ASTContinue();
        node->type = "continue";
        if(insideLoop == 0){
            cout << "Semantic Error on line " << line << ": Encountered continue statement outside Loop block.\n";
        }
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitBlck(MiniCParser::BlckContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitReturn(MiniCParser::ReturnContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTReturn *node = new ASTReturn();
        node->type = "return";
        int count = 0;
        if(ctx->expr() != NULL){
            
            count++;
        }
        if(count == 0 && datatype_method != "void"){    
            //cout << "hello\n";
            node->expr = NULL;
            cout << "Semantic Error on line " << line << ": Invalid returning value. Returning nothing but expected " << datatype_method << endl;            
            return (ASTStat*)node;
        }
        if(count == 0 && datatype_method == "void")
        {
            node->expr = NULL;
            return (ASTStat*)node;
        }

        node->expr = visit(ctx->expr());
        if(canBeAssigned(datatype_method, node->expr->eval_type) == true){

        }
        else if(node->expr->eval_type != ""){
            cout << "Semantic Error on line " << line << ": Return Type Mismatch. Invalid Conversion from " << node->expr->eval_type << " to " << datatype_method << endl;
        }
        return (ASTStat*)node;
    }

    virtual antlrcpp::Any visitPrint(MiniCParser::PrintContext *ctx) override {
        ASTPrint *node = new ASTPrint();
        node->expr = visit(ctx->expr());
        node->type = "print";
        return (ASTStat*) node;
    }

    virtual antlrcpp::Any visitPrintln(MiniCParser::PrintlnContext *ctx) override {
        ASTPrintln *node = new ASTPrintln();
        node->expr = visit(ctx->expr());
        node->type = "println";
        return (ASTStat*) node;
    }

    virtual antlrcpp::Any visitAssignment(MiniCParser::AssignmentContext *ctx) override {
        
        /* Semantic Checks:
            * Check whether variable being assigned to is same type as that of expr.
            * If expr is "", there was an error before only and no need to throw any error here to avoid redundancy.
        */
        int line = (ctx->start)->getLine();
        ASTAssign *node = new ASTAssign();
        node->id = visit(ctx->identifier());
        node->expr = visit(ctx->expr());

        ASTDtype* dat = look_up_variable(node->id, line);

        int addrs_dim = node->id->addrs.size();
        int org_dims = getDimensions(node->id, line);
        if(org_dims == -1){
            return (ASTAssign *) node;
        }
        if(org_dims != addrs_dim){
            cout << "Semantic Error on line " << line << ": Dimensions don't match. Expected " << org_dims << " dimensions but got " << addrs_dim << " dimensions\n";
            
        }


        if(dat!= NULL && canBeAssigned(dat->dtype, node->expr->eval_type) == false && node->expr->eval_type != ""){
            cout << "Semantic Error on line " << line << ": Expected " << dat->dtype << " but found " << node->expr->eval_type << " while assigning to variable " << node->id->name  << endl;
        }
        // cout << ((ASTINTLIT*)(node->expr))->value;
        return (ASTAssign *) node;
    }

    virtual antlrcpp::Any visitMethod_call(MiniCParser::Method_callContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprCall* node = new ASTExprCall();
        bool found = foundMethod(ctx->ID()->getText(), line);
        node->type = "call";
        node->name = ctx->ID()->getText();
        vector <ASTExpr*> dummy;
        node->args = dummy;
        if(found == false){
            // Issue
            node->eval_type = "";
        }
        else{
            ASTDtype* dat = look_up_method(ctx->ID()->getText(), line);
            if(dat == NULL)
                node->eval_type = "void";
            else
                node->eval_type = dat->dtype;
            vector <ASTDtype*> vec = getArgTypes(ctx->ID()->getText(), line);
            
            vector <ASTExpr*> express;
            int c = 0;
            while(ctx->expr(c) != NULL)
            {
                express.push_back(visit(ctx->expr(c)));
                c++;
            }
            
            if(express.size() != vec.size()){
                cout << "Semantic Error on line " << line << ": Number of arguments do not match definition of " << ctx->ID()->getText() << "()\n";
                node->eval_type = "";
            }
            else{
                int ok = 1;
                int cnt = 0;
                for(auto arg: vec)
                {
                    if(canBeAssigned(arg->dtype, express[cnt++]->eval_type) == true){

                    }
                    else{
                        cout << "Semantic Error on line " << line << ": Type of arguments at position " << cnt << " do not match definition of " << ctx->ID()->getText() << "(). Expected " << arg->dtype << " but found " << express[cnt- 1]->eval_type << endl;
                        ok = 0;
                    }
                    // cnt++;
                }
                if(ok == 0){
                    // cout << "Semantic Error: Type of arguments do not match definition of " << ctx->ID()->getText() << "()\n";
                    node->eval_type = "";
                }
            }
            node->args = express;
        }
        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitExpr(MiniCParser::ExprContext *ctx) override {
        return visit(ctx->expr8());
    }

    virtual antlrcpp::Any visitExpr8_7(MiniCParser::Expr8_7Context *ctx) override {
        return visit(ctx->expr7());
    }

    virtual antlrcpp::Any visitTernary_expr(MiniCParser::Ternary_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprTernary *node = new ASTExprTernary();
        node->cond = visit(ctx->expr8(0));
        node->true_expr = visit(ctx->expr8(1));
        node->false_expr = visit(ctx->expr8(2));
        node->type = "ter";
        
        node->eval_type = getCastedType(node->true_expr->eval_type, node->false_expr->eval_type);

        if(node->true_expr->eval_type == "" || node->false_expr->eval_type == ""){
        }
        else if(node->eval_type == "")
            cout << "Semantic Error on line " << line << ": Different data types for true and false expressions.\n";
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr7_6(MiniCParser::Expr7_6Context *ctx) override {
        return visit(ctx->expr6());
    }

    virtual antlrcpp::Any visitOr_expr(MiniCParser::Or_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "||";
        node->type = "bin";
        node->left = visit(ctx->expr7());
        node->right = visit(ctx->expr6());
        
        // cout << logicalCompatible(getCastedType(node->left->eval_type, node->right->eval_type)) << endl;
        node->eval_type = logicalCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        // cout << node->eval_type << endl;
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform || on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }
        
        
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitAnd_expr(MiniCParser::And_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "&&";
        node->type = "bin";
        node->left = visit(ctx->expr6());
        node->right = visit(ctx->expr5());

        node->eval_type = logicalCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform && on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }


        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr6_5(MiniCParser::Expr6_5Context *ctx) override {
        return visit(ctx->expr5());
    }

    virtual antlrcpp::Any visitEq_expr(MiniCParser::Eq_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "==";
        node->type = "bin";
        node->left = visit(ctx->expr5());
        node->right = visit(ctx->expr4());
        
        node->eval_type = relationalCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform == on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }
        
        
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr5_4(MiniCParser::Expr5_4Context *ctx) override {
        return visit(ctx->expr4());
    }

    virtual antlrcpp::Any visitNe_expr(MiniCParser::Ne_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "!=";
        node->type = "bin";
        node->left = visit(ctx->expr5());
        node->right = visit(ctx->expr4());

        node->eval_type = relationalCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform != on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }


        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitGe_expr(MiniCParser::Ge_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = ">=";
        node->type = "bin";
        node->left = visit(ctx->expr4());
        node->right = visit(ctx->expr3());

        node->eval_type = relationalCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform >= on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }



        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitGt_expr(MiniCParser::Gt_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = ">";
        node->type = "bin";
        node->left = visit(ctx->expr4());
        node->right = visit(ctx->expr3());

        node->eval_type = relationalCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform > on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }


        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr4_3(MiniCParser::Expr4_3Context *ctx) override {
        return visit(ctx->expr3());
    }

    virtual antlrcpp::Any visitLt_expr(MiniCParser::Lt_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "<";
        node->type = "bin";
        node->left = visit(ctx->expr3());
        node->right = visit(ctx->expr2());
        
        node->eval_type = relationalCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform < on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }        
        
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr3_2(MiniCParser::Expr3_2Context *ctx) override {
        return visit(ctx->expr2());
    }

    virtual antlrcpp::Any visitLe_expr(MiniCParser::Le_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "<=";
        node->type = "bin";
        node->left = visit(ctx->expr3());
        node->right = visit(ctx->expr2());

        node->eval_type = relationalCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform <= on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }

        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitSub_expr(MiniCParser::Sub_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "-";
        node->type = "bin";
        node->left = visit(ctx->expr2());
        node->right = visit(ctx->expr1());
        
        node->eval_type = addSubMulDivCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform subtraction on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }
        
        
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitAdd_expr(MiniCParser::Add_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->op = "+";
        node->type = "bin";
        node->left = visit(ctx->expr2());
        node->right = visit(ctx->expr1());
        
        
        node->eval_type = addSubMulDivCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform addition on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }
        
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr2_1(MiniCParser::Expr2_1Context *ctx) override {
        return visit(ctx->expr1());
    }

    virtual antlrcpp::Any visitMod_expr(MiniCParser::Mod_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->type = "bin";
        node->op = "%";
        node->left = visit(ctx->expr1());
        node->right = visit(ctx->expr0());

        node->eval_type = modCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform modulo on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }

        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitExpr1_0(MiniCParser::Expr1_0Context *ctx) override {
        return visit(ctx->expr0());
    }

    virtual antlrcpp::Any visitDiv_expr(MiniCParser::Div_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->type = "bin";
        node->op = "/";
        node->left = visit(ctx->expr1());
        node->right = visit(ctx->expr0());
        
        
        node->eval_type = addSubMulDivCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform division on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        } 
        
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitMul_expr(MiniCParser::Mul_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTExprBinary *node = new ASTExprBinary();
        node->type = "bin";
        node->op = "*";
        node->left = visit(ctx->expr1());
        node->right = visit(ctx->expr0());


        node->eval_type = addSubMulDivCompatible(getCastedType(node->left->eval_type, node->right->eval_type));
        if(node->left->eval_type == "" || node->right->eval_type == "")
        {
            // Already handled before.
        }
        else if(node->eval_type == ""){
            cout << "Semantic Error on line " << line << ": Type mismatch. Cannot perform multiplication on " << node->left->eval_type << " and " << node->right->eval_type << endl;
        }
        return (ASTExpr *)node;
    }

    virtual antlrcpp::Any visitId_expr(MiniCParser::Id_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTID* node = new ASTID();
        node = visit(ctx->identifier());
        node->type = "id";
        int addrs_dim = node->addrs.size();

        ASTDtype* dat = look_up_variable(node, line);
        int org_dims;
        if(dat != NULL){
            node->eval_type = dat->dtype;
            org_dims = getDimensions(node, line);
            if(org_dims != addrs_dim){
                cout << "Semantic Error on line " << line << ": Dimensions don't match. Expected " << org_dims << " dimensions but got " << addrs_dim << " dimensions\n";
                node->eval_type = "";
            }
        }
        else{
            node->eval_type = "";
        }
        return (ASTExpr*)node;
    }

    virtual antlrcpp::Any visitLit_expr(MiniCParser::Lit_exprContext *ctx) override {
        return (ASTExpr *)visit(ctx->literal());
    }

    virtual antlrcpp::Any visitCall_expr(MiniCParser::Call_exprContext *ctx) override {
        
        return visit(ctx->method_call());
    }

    virtual antlrcpp::Any visitNot_expr(MiniCParser::Not_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTNot *node = new ASTNot;
        node->type = "not";
        node->expr = visit(ctx->expr());

        node->eval_type = logicalCompatible(node->expr->eval_type);
        if(node->eval_type == "" && node->expr->eval_type != "")
            cout << "Semantic Error on line " << line << ": Cannot apply Not operator on " << node->expr->eval_type << endl;
        return (ASTExpr*) node;
    }

    virtual antlrcpp::Any visitNegate_expr(MiniCParser::Negate_exprContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTNeg *node = new ASTNeg;
        node->type = "neg";
        node->expr = visit(ctx->expr());
        node->eval_type = addSubMulDivCompatible(node->expr->eval_type);
        if(node->eval_type == "" && node->expr->eval_type != "")
            cout << "Semantic Error on line " << line << ": Cannot apply Negate operator on " << node->expr->eval_type << endl;
        return (ASTExpr*) node;
    }

    virtual antlrcpp::Any visitBracket_expr(MiniCParser::Bracket_exprContext *ctx) override {
        return visit(ctx->expr());
    }

    virtual antlrcpp::Any visitInp_int(MiniCParser::Inp_intContext *ctx) override {
        Inp *node = new Inp();
        node->eval_type = "int";
        node->type = "input";
        return (ASTExpr*) node;
    }

    virtual antlrcpp::Any visitInp_char(MiniCParser::Inp_charContext *ctx) override {
        Inp *node = new Inp();
        node->eval_type = "char";
        node->type = "input";
        return (ASTExpr*) node;
    }

    virtual antlrcpp::Any visitInp_bool(MiniCParser::Inp_boolContext *ctx) override {
        Inp *node = new Inp();
        node->eval_type = "bool";
        node->type = "input";
        return (ASTExpr*) node;
    }

    virtual antlrcpp::Any visitCast(MiniCParser::CastContext *ctx) override {
        int line = (ctx->start)->getLine();
        ASTCast* node = new ASTCast();
        node->type = "cast";
        node->expr = visit(ctx->expr());
        node->dat = visit(ctx->type());
        if(!possibleToCast(node->expr->eval_type, node->dat->dtype))
        {
            cout << "Semantic Error on line " << line << ": Bad Cast!\n";
            node->eval_type = "";
        }
        else{
            node->eval_type = node->dat->dtype;
        }
        
        return (ASTExpr*) node;
    }

    virtual antlrcpp::Any visitVar(MiniCParser::VarContext *ctx) override {
        ASTID* node = new ASTID();
        node->type = "id";
        node->name = ctx->ID()->getText();
        return (ASTID*)node;
    }

    virtual antlrcpp::Any visitVar_array(MiniCParser::Var_arrayContext *ctx) override {
        /* Semantic Checks:
           * addrs should be int
        */ 
        int line = (ctx->start)->getLine();
        ASTID* node = new ASTID();
        node->name = ctx->ID()->getText();
        node->type = "id";
        int c = 0;
        while(ctx->expr(c) != NULL){
            node->addrs.push_back(visit(ctx->expr(c)));

            if(node->addrs[c]->eval_type != "int" && node->addrs[c]->eval_type != "")
            {
                cout << "Semantic Error on line " << line << ": Address has to be of type int. Got " << node->addrs[c]->eval_type << endl;;
            }
            c++;
        }
        return (ASTID*)node;
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
        node->value = (ctx->CHAR_LIT()->getText());
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