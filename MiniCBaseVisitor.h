
// Generated from MiniC.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MiniCVisitor.h"


/**
 * This class provides an empty implementation of MiniCVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MiniCBaseVisitor : public MiniCVisitor {
public:

  virtual antlrcpp::Any visitProgram(MiniCParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(MiniCParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodDecl(MiniCParser::MethodDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_decl(MiniCParser::Var_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_decl(MiniCParser::Method_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(MiniCParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeInt(MiniCParser::TypeIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeUint(MiniCParser::TypeUintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeBool(MiniCParser::TypeBoolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeChar(MiniCParser::TypeCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeFile(MiniCParser::TypeFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeString(MiniCParser::TypeStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeFloat(MiniCParser::TypeFloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListAssn(MiniCParser::ListAssnContext *ctx) override {
    return visitChildren(ctx);
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
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_call(MiniCParser::Method_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(MiniCParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr8_7(MiniCParser::Expr8_7Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTernary_expr(MiniCParser::Ternary_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr7_6(MiniCParser::Expr7_6Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOr_expr(MiniCParser::Or_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnd_expr(MiniCParser::And_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr6_5(MiniCParser::Expr6_5Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEq_expr(MiniCParser::Eq_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr5_4(MiniCParser::Expr5_4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNe_expr(MiniCParser::Ne_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGe_expr(MiniCParser::Ge_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGt_expr(MiniCParser::Gt_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr4_3(MiniCParser::Expr4_3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLt_expr(MiniCParser::Lt_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr3_2(MiniCParser::Expr3_2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLe_expr(MiniCParser::Le_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSub_expr(MiniCParser::Sub_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAdd_expr(MiniCParser::Add_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr2_1(MiniCParser::Expr2_1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMod_expr(MiniCParser::Mod_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr1_0(MiniCParser::Expr1_0Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiv_expr(MiniCParser::Div_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMul_expr(MiniCParser::Mul_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitId_expr(MiniCParser::Id_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLit_expr(MiniCParser::Lit_exprContext *ctx) override {
    return visitChildren(ctx);
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
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_array(MiniCParser::Var_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt_lit(MiniCParser::Int_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloat_lit(MiniCParser::Float_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChar_lit(MiniCParser::Char_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStr_lit(MiniCParser::Str_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool_literal(MiniCParser::Bool_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrue_lit(MiniCParser::True_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFalse_lit(MiniCParser::False_litContext *ctx) override {
    return visitChildren(ctx);
  }


};

