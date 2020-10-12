
// Generated from MiniC.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MiniCParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MiniCParser.
 */
class  MiniCVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MiniCParser.
   */
    virtual antlrcpp::Any visitProgram(MiniCParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(MiniCParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitMethodDecl(MiniCParser::MethodDeclContext *context) = 0;

    virtual antlrcpp::Any visitVar_decl(MiniCParser::Var_declContext *context) = 0;

    virtual antlrcpp::Any visitMethod_decl_type(MiniCParser::Method_decl_typeContext *context) = 0;

    virtual antlrcpp::Any visitMethod_decl_void(MiniCParser::Method_decl_voidContext *context) = 0;

    virtual antlrcpp::Any visitBlock(MiniCParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitTypeInt(MiniCParser::TypeIntContext *context) = 0;

    virtual antlrcpp::Any visitTypeUint(MiniCParser::TypeUintContext *context) = 0;

    virtual antlrcpp::Any visitTypeBool(MiniCParser::TypeBoolContext *context) = 0;

    virtual antlrcpp::Any visitTypeChar(MiniCParser::TypeCharContext *context) = 0;

    virtual antlrcpp::Any visitTypeFile(MiniCParser::TypeFileContext *context) = 0;

    virtual antlrcpp::Any visitTypeString(MiniCParser::TypeStringContext *context) = 0;

    virtual antlrcpp::Any visitTypeFloat(MiniCParser::TypeFloatContext *context) = 0;

    virtual antlrcpp::Any visitListAssn(MiniCParser::ListAssnContext *context) = 0;

    virtual antlrcpp::Any visitMethodCall(MiniCParser::MethodCallContext *context) = 0;

    virtual antlrcpp::Any visitIf(MiniCParser::IfContext *context) = 0;

    virtual antlrcpp::Any visitFor(MiniCParser::ForContext *context) = 0;

    virtual antlrcpp::Any visitWhile(MiniCParser::WhileContext *context) = 0;

    virtual antlrcpp::Any visitBreak(MiniCParser::BreakContext *context) = 0;

    virtual antlrcpp::Any visitContiue(MiniCParser::ContiueContext *context) = 0;

    virtual antlrcpp::Any visitBlck(MiniCParser::BlckContext *context) = 0;

    virtual antlrcpp::Any visitReturn(MiniCParser::ReturnContext *context) = 0;

    virtual antlrcpp::Any visitPrint(MiniCParser::PrintContext *context) = 0;

    virtual antlrcpp::Any visitPrintln(MiniCParser::PrintlnContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(MiniCParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitMethod_call(MiniCParser::Method_callContext *context) = 0;

    virtual antlrcpp::Any visitExpr(MiniCParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitExpr8_7(MiniCParser::Expr8_7Context *context) = 0;

    virtual antlrcpp::Any visitTernary_expr(MiniCParser::Ternary_exprContext *context) = 0;

    virtual antlrcpp::Any visitExpr7_6(MiniCParser::Expr7_6Context *context) = 0;

    virtual antlrcpp::Any visitOr_expr(MiniCParser::Or_exprContext *context) = 0;

    virtual antlrcpp::Any visitAnd_expr(MiniCParser::And_exprContext *context) = 0;

    virtual antlrcpp::Any visitExpr6_5(MiniCParser::Expr6_5Context *context) = 0;

    virtual antlrcpp::Any visitEq_expr(MiniCParser::Eq_exprContext *context) = 0;

    virtual antlrcpp::Any visitExpr5_4(MiniCParser::Expr5_4Context *context) = 0;

    virtual antlrcpp::Any visitNe_expr(MiniCParser::Ne_exprContext *context) = 0;

    virtual antlrcpp::Any visitGe_expr(MiniCParser::Ge_exprContext *context) = 0;

    virtual antlrcpp::Any visitGt_expr(MiniCParser::Gt_exprContext *context) = 0;

    virtual antlrcpp::Any visitExpr4_3(MiniCParser::Expr4_3Context *context) = 0;

    virtual antlrcpp::Any visitLt_expr(MiniCParser::Lt_exprContext *context) = 0;

    virtual antlrcpp::Any visitExpr3_2(MiniCParser::Expr3_2Context *context) = 0;

    virtual antlrcpp::Any visitLe_expr(MiniCParser::Le_exprContext *context) = 0;

    virtual antlrcpp::Any visitSub_expr(MiniCParser::Sub_exprContext *context) = 0;

    virtual antlrcpp::Any visitAdd_expr(MiniCParser::Add_exprContext *context) = 0;

    virtual antlrcpp::Any visitExpr2_1(MiniCParser::Expr2_1Context *context) = 0;

    virtual antlrcpp::Any visitMod_expr(MiniCParser::Mod_exprContext *context) = 0;

    virtual antlrcpp::Any visitExpr1_0(MiniCParser::Expr1_0Context *context) = 0;

    virtual antlrcpp::Any visitDiv_expr(MiniCParser::Div_exprContext *context) = 0;

    virtual antlrcpp::Any visitMul_expr(MiniCParser::Mul_exprContext *context) = 0;

    virtual antlrcpp::Any visitId_expr(MiniCParser::Id_exprContext *context) = 0;

    virtual antlrcpp::Any visitLit_expr(MiniCParser::Lit_exprContext *context) = 0;

    virtual antlrcpp::Any visitCall_expr(MiniCParser::Call_exprContext *context) = 0;

    virtual antlrcpp::Any visitNot_expr(MiniCParser::Not_exprContext *context) = 0;

    virtual antlrcpp::Any visitNegate_expr(MiniCParser::Negate_exprContext *context) = 0;

    virtual antlrcpp::Any visitBracket_expr(MiniCParser::Bracket_exprContext *context) = 0;

    virtual antlrcpp::Any visitInp_int(MiniCParser::Inp_intContext *context) = 0;

    virtual antlrcpp::Any visitInp_char(MiniCParser::Inp_charContext *context) = 0;

    virtual antlrcpp::Any visitInp_bool(MiniCParser::Inp_boolContext *context) = 0;

    virtual antlrcpp::Any visitVar(MiniCParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitVar_array(MiniCParser::Var_arrayContext *context) = 0;

    virtual antlrcpp::Any visitInt_lit(MiniCParser::Int_litContext *context) = 0;

    virtual antlrcpp::Any visitFloat_lit(MiniCParser::Float_litContext *context) = 0;

    virtual antlrcpp::Any visitChar_lit(MiniCParser::Char_litContext *context) = 0;

    virtual antlrcpp::Any visitStr_lit(MiniCParser::Str_litContext *context) = 0;

    virtual antlrcpp::Any visitBool_literal(MiniCParser::Bool_literalContext *context) = 0;

    virtual antlrcpp::Any visitTrue_lit(MiniCParser::True_litContext *context) = 0;

    virtual antlrcpp::Any visitFalse_lit(MiniCParser::False_litContext *context) = 0;


};

