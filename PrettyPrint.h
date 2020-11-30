#include "bits/stdc++.h"
// #include "ast.h"
using namespace std;

int INDENT = 0;

class PrettyPrint : public ASTvisitor
{
    public:
    virtual void visit(ASTProg &node)
    {
        for(auto decl: node.declarations)
        {
            decl->accept(*this);
            if(decl->type == "var"){
                cout << ";";
            }
            cout << "\n";
        }
    };
    virtual void visit(ASTDecl &node)
    {

    };
    virtual void visit(ASTVarDecl &node)
    {
        node.dat->accept(*this);
        cout << " ";
        node.id->accept(*this);
    };
    virtual void visit(ASTMethodDecl &node)
    {
        if(node.return_type == NULL)
            cout << "void ";
        else
            node.return_type->accept(*this);
        
        cout << " " << node.name << "(";
        for(int i = 0; i < node.args.size(); ++i){
            node.args[i]->accept(*this);
            if(i != node.args.size() - 1)
                cout << ", ";
        }
        
        cout << ")";
        cout << "\n";
        node.block->accept(*this);
        //cout << "}\n";
    };
    virtual void visit(ASTDtype &node)
    {
        cout << node.dtype;
    };
    virtual void visit(ASTID &node)
    {
        cout << node.name;
        for(int i = 0; i < node.addrs.size(); ++i){
            cout << "[";
            node.addrs[i]->accept(*this);
            cout << "]";
        }
        // cout << " ";
    };
    virtual void visit(ASTAssign &node)
    {
        node.id->accept(*this);
        cout << " = ";
        node.expr->accept(*this);
    };
    virtual void visit(ASTStatAssn &node)
    {
        for(int i = 0; i < node.assignments.size(); ++i){
            node.assignments[i]->accept(*this);
            if(i != node.assignments.size() -1)
                cout << ",";
        }
        cout << ";";
    };
    virtual void visit(ASTExpr &node)
    {

    };
    virtual void visit(ASTExprBinary &node)
    {
        cout << "(";
        node.left->accept(*this);
        cout << " " << node.op << " ";
        node.right->accept(*this);
        cout << ")";
    };
    virtual void visit(ASTExprTernary &node)
    {
        cout << "( ";
        node.cond->accept(*this);
        cout << " ? ";
        node.true_expr->accept(*this);
        cout << " : ";
        node.false_expr->accept(*this);
        cout << " )";
    };
    virtual void visit(ASTStat &node)
    {

    };
    virtual void visit(ASTBlock &node)
    {
        for(int j = 0; j < 6 *INDENT; ++j)
            cout << " ";
        cout << "{\n";
        INDENT++;
        for(int i = 0; i < node.var_declarations.size(); ++i)
        {
            for(int j = 0; j < 6 * INDENT; ++j){
                cout << " ";
            }
            node.var_declarations[i]->accept(*this);
            cout << ";\n";
        }
        
        for(int i = 0; i < node.statements.size(); ++i)
        {
            for(int j = 0; j < 6 * INDENT; ++j){
                cout << " ";
            }
            
            node.statements[i]->accept(*this);
            cout << "\n";
        }
        INDENT--;
        for(int j = 0; j < 6 *INDENT; ++j)
            cout << " ";
        cout << "}";
        
    };
    virtual void visit(ASTStatCall &node)
    {
        node.expr->accept(*this);
        cout << ";";
    };
    virtual void visit(ASTINTLIT &node)
    {
        cout << node.value << "";
    };
    virtual void visit(ASTFLOATLIT &node)
    {
        cout << node.value << "";
    };
    virtual void visit(ASTCHARLIT &node)
    {
        cout << node.value << "";
    };
    virtual void visit(ASTSTRINGLIT &node)
    {
        cout << node.value << "";
    };
    virtual void visit(ASTBOOLLIT &node)
    {
        cout << node.value << "";
    };
    virtual void visit(ASTExprCall &node)
    {
        cout << node.name << "(";
        for(int i = 0; i < node.args.size(); ++i)
        {
            node.args[i]->accept(*this);
            if(i != node.args.size() -1)
            cout << ", ";
        }
        cout << ")";
    };
    virtual void visit(ASTIFStat &node)
    {
        cout << "if(";
        node.expr->accept(*this);
        cout << ")\n";
        if(node.if_block != NULL)
            node.if_block->accept(*this);
        if(node.else_block != NULL){
            cout << "\n";
            for(int j = 0; j < 6 * INDENT; ++j)
                cout << " ";
            cout << "else\n";
            node.else_block->accept(*this);
        }
            
    };
    virtual void visit(ASTNot &node)
    {
        cout << "!(";
        node.expr->accept(*this);
        cout << ")";
    };
    virtual void visit(ASTNeg &node)
    {
        cout << "-(";
        node.expr->accept(*this);
        cout << ")";
    };
    virtual void visit(Inp &node)
    {
        if(node.eval_type == "bool")
            cout << "read_bool()";
        else if(node.eval_type == "int")
            cout << "read_int()";
        else if(node.eval_type == "char")
            cout << "read_char()";
    };
    virtual void visit(ASTPrint &node)
    {
        cout << "print(";
        node.expr->accept(*this);
        cout << ");";
    };
    virtual void visit(ASTPrintln &node)
    {
        cout << "println(";
        node.expr->accept(*this);
        cout << ");";
    };
    virtual void visit(ASTFor &node)
    {
        cout << "for(";

        for(int i = 0; i < node.beg_assigns.size(); ++i){
            node.beg_assigns[i]->accept(*this);
            if(i != node.beg_assigns.size() - 1)
                cout << ", ";
        }

        cout << "; ";
        for(int i = 0; i < node.exprs.size(); ++i){
            node.exprs[i]->accept(*this);
            if(i != node.exprs.size() - 1)
                cout << ", ";
        }
        cout << "; ";
        for(int i = 0; i < node.assigns.size(); ++i){
            node.assigns[i]->accept(*this);
            if(i != node.assigns.size() - 1)
                cout << ", ";
        }

        cout << ")\n";
        node.block->accept(*this);
    };
    virtual void visit(ASTBreak &node)
    {
        cout << "break;";
    };
    virtual void visit(ASTContinue &node)
    {
        cout << "continue;";
    };
    virtual void visit(ASTWhile &node)
    {
        cout << "while(";
        node.expr->accept(*this);
        cout << ")\n";
        node.block->accept(*this);
    };
    virtual void visit(ASTReturn &node)
    {
        cout << "return";
        if(node.expr != NULL)
        cout << " (";
        if(node.expr != NULL)
            node.expr->accept(*this);
        if(node.expr != NULL)
        cout << ")";
        cout << ";";
    }
    virtual void visit(ASTCast &node)
    {
        cout << "(";
        node.dat->accept(*this);
        cout << ")";
        node.expr->accept(*this);
    };
};