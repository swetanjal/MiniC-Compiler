
// Generated from MiniC.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  MiniCParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, FALSE = 9, TRUE = 10, NOT = 11, NEGATE = 12, VOID = 13, FLOAT = 14, 
    INT = 15, FILE = 16, STRING = 17, CHAR = 18, UINT = 19, BOOL = 20, THEN = 21, 
    OTHERWISE = 22, FOR = 23, WHILE = 24, IF = 25, ELSE = 26, BREAK = 27, 
    CONTINUE = 28, RETURN = 29, ADD = 30, SUB = 31, MUL = 32, DIV = 33, 
    MOD = 34, LT = 35, GT = 36, LE = 37, GE = 38, AND = 39, OR = 40, EQ = 41, 
    NE = 42, ASSIGN = 43, PRINT = 44, PRINTLN = 45, READ_INT = 46, READ_CHAR = 47, 
    READ_BOOL = 48, INT_LIT = 49, FLOAT_LIT = 50, CHAR_LIT = 51, ID = 52, 
    STRING_LIT = 53, WS = 54
  };

  enum {
    RuleProgram = 0, RuleDecl = 1, RuleVar_decl = 2, RuleMethod_decl = 3, 
    RuleBlock = 4, RuleType = 5, RuleStatement = 6, RuleAssignmentbeg = 7, 
    RuleAssignment = 8, RuleMethod_call = 9, RuleExpr = 10, RuleExpr8 = 11, 
    RuleExpr7 = 12, RuleExpr6 = 13, RuleExpr5 = 14, RuleExpr4 = 15, RuleExpr3 = 16, 
    RuleExpr2 = 17, RuleExpr1 = 18, RuleExpr0 = 19, RuleIdentifier = 20, 
    RuleLiteral = 21, RuleBool_lit = 22
  };

  MiniCParser(antlr4::TokenStream *input);
  ~MiniCParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class DeclContext;
  class Var_declContext;
  class Method_declContext;
  class BlockContext;
  class TypeContext;
  class StatementContext;
  class AssignmentbegContext;
  class AssignmentContext;
  class Method_callContext;
  class ExprContext;
  class Expr8Context;
  class Expr7Context;
  class Expr6Context;
  class Expr5Context;
  class Expr4Context;
  class Expr3Context;
  class Expr2Context;
  class Expr1Context;
  class Expr0Context;
  class IdentifierContext;
  class LiteralContext;
  class Bool_litContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DeclContext() = default;
    void copyFrom(DeclContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MethodDeclContext : public DeclContext {
  public:
    MethodDeclContext(DeclContext *ctx);

    Method_declContext *method_decl();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarDeclContext : public DeclContext {
  public:
    VarDeclContext(DeclContext *ctx);

    Var_declContext *var_decl();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeclContext* decl();

  class  Var_declContext : public antlr4::ParserRuleContext {
  public:
    Var_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declContext* var_decl();

  class  Method_declContext : public antlr4::ParserRuleContext {
  public:
    Method_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Method_declContext() = default;
    void copyFrom(Method_declContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Method_decl_voidContext : public Method_declContext {
  public:
    Method_decl_voidContext(Method_declContext *ctx);

    antlr4::tree::TerminalNode *VOID();
    antlr4::tree::TerminalNode *ID();
    BlockContext *block();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Method_decl_typeContext : public Method_declContext {
  public:
    Method_decl_typeContext(Method_declContext *ctx);

    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *ID();
    BlockContext *block();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Method_declContext* method_decl();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Var_declContext *> var_decl();
    Var_declContext* var_decl(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TypeIntContext : public TypeContext {
  public:
    TypeIntContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeFloatContext : public TypeContext {
  public:
    TypeFloatContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeUintContext : public TypeContext {
  public:
    TypeUintContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *UINT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeCharContext : public TypeContext {
  public:
    TypeCharContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *CHAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeStringContext : public TypeContext {
  public:
    TypeStringContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *STRING();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeBoolContext : public TypeContext {
  public:
    TypeBoolContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *BOOL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeFileContext : public TypeContext {
  public:
    TypeFileContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *FILE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ContiueContext : public StatementContext {
  public:
    ContiueContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *CONTINUE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrintContext : public StatementContext {
  public:
    PrintContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *PRINT();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrintlnContext : public StatementContext {
  public:
    PrintlnContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *PRINTLN();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakContext : public StatementContext {
  public:
    BreakContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *BREAK();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListAssnContext : public StatementContext {
  public:
    ListAssnContext(StatementContext *ctx);

    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForContext : public StatementContext {
  public:
    ForContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    BlockContext *block();
    std::vector<AssignmentbegContext *> assignmentbeg();
    AssignmentbegContext* assignmentbeg(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileContext : public StatementContext {
  public:
    WhileContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    ExprContext *expr();
    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BlckContext : public StatementContext {
  public:
    BlckContext(StatementContext *ctx);

    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfContext : public StatementContext {
  public:
    IfContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *IF();
    ExprContext *expr();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnContext : public StatementContext {
  public:
    ReturnContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MethodCallContext : public StatementContext {
  public:
    MethodCallContext(StatementContext *ctx);

    Method_callContext *method_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  AssignmentbegContext : public antlr4::ParserRuleContext {
  public:
    AssignmentbegContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentContext *assignment();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentbegContext* assignmentbeg();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  Method_callContext : public antlr4::ParserRuleContext {
  public:
    Method_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_callContext* method_call();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr8Context *expr8();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  Expr8Context : public antlr4::ParserRuleContext {
  public:
    Expr8Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expr8Context() = default;
    void copyFrom(Expr8Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Expr8_7Context : public Expr8Context {
  public:
    Expr8_7Context(Expr8Context *ctx);

    Expr7Context *expr7();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Ternary_exprContext : public Expr8Context {
  public:
    Ternary_exprContext(Expr8Context *ctx);

    std::vector<Expr8Context *> expr8();
    Expr8Context* expr8(size_t i);
    antlr4::tree::TerminalNode *THEN();
    antlr4::tree::TerminalNode *OTHERWISE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr8Context* expr8();
  Expr8Context* expr8(int precedence);
  class  Expr7Context : public antlr4::ParserRuleContext {
  public:
    Expr7Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expr7Context() = default;
    void copyFrom(Expr7Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Expr7_6Context : public Expr7Context {
  public:
    Expr7_6Context(Expr7Context *ctx);

    Expr6Context *expr6();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Or_exprContext : public Expr7Context {
  public:
    Or_exprContext(Expr7Context *ctx);

    Expr7Context *expr7();
    antlr4::tree::TerminalNode *OR();
    Expr6Context *expr6();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr7Context* expr7();
  Expr7Context* expr7(int precedence);
  class  Expr6Context : public antlr4::ParserRuleContext {
  public:
    Expr6Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expr6Context() = default;
    void copyFrom(Expr6Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  And_exprContext : public Expr6Context {
  public:
    And_exprContext(Expr6Context *ctx);

    Expr6Context *expr6();
    antlr4::tree::TerminalNode *AND();
    Expr5Context *expr5();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr6_5Context : public Expr6Context {
  public:
    Expr6_5Context(Expr6Context *ctx);

    Expr5Context *expr5();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr6Context* expr6();
  Expr6Context* expr6(int precedence);
  class  Expr5Context : public antlr4::ParserRuleContext {
  public:
    Expr5Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expr5Context() = default;
    void copyFrom(Expr5Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Eq_exprContext : public Expr5Context {
  public:
    Eq_exprContext(Expr5Context *ctx);

    Expr5Context *expr5();
    antlr4::tree::TerminalNode *EQ();
    Expr4Context *expr4();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr5_4Context : public Expr5Context {
  public:
    Expr5_4Context(Expr5Context *ctx);

    Expr4Context *expr4();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Ne_exprContext : public Expr5Context {
  public:
    Ne_exprContext(Expr5Context *ctx);

    Expr5Context *expr5();
    antlr4::tree::TerminalNode *NE();
    Expr4Context *expr4();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr5Context* expr5();
  Expr5Context* expr5(int precedence);
  class  Expr4Context : public antlr4::ParserRuleContext {
  public:
    Expr4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expr4Context() = default;
    void copyFrom(Expr4Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Ge_exprContext : public Expr4Context {
  public:
    Ge_exprContext(Expr4Context *ctx);

    Expr4Context *expr4();
    antlr4::tree::TerminalNode *GE();
    Expr3Context *expr3();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Gt_exprContext : public Expr4Context {
  public:
    Gt_exprContext(Expr4Context *ctx);

    Expr4Context *expr4();
    antlr4::tree::TerminalNode *GT();
    Expr3Context *expr3();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr4_3Context : public Expr4Context {
  public:
    Expr4_3Context(Expr4Context *ctx);

    Expr3Context *expr3();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr4Context* expr4();
  Expr4Context* expr4(int precedence);
  class  Expr3Context : public antlr4::ParserRuleContext {
  public:
    Expr3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expr3Context() = default;
    void copyFrom(Expr3Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Lt_exprContext : public Expr3Context {
  public:
    Lt_exprContext(Expr3Context *ctx);

    Expr3Context *expr3();
    antlr4::tree::TerminalNode *LT();
    Expr2Context *expr2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr3_2Context : public Expr3Context {
  public:
    Expr3_2Context(Expr3Context *ctx);

    Expr2Context *expr2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Le_exprContext : public Expr3Context {
  public:
    Le_exprContext(Expr3Context *ctx);

    Expr3Context *expr3();
    antlr4::tree::TerminalNode *LE();
    Expr2Context *expr2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr3Context* expr3();
  Expr3Context* expr3(int precedence);
  class  Expr2Context : public antlr4::ParserRuleContext {
  public:
    Expr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expr2Context() = default;
    void copyFrom(Expr2Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Sub_exprContext : public Expr2Context {
  public:
    Sub_exprContext(Expr2Context *ctx);

    Expr2Context *expr2();
    antlr4::tree::TerminalNode *SUB();
    Expr1Context *expr1();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Add_exprContext : public Expr2Context {
  public:
    Add_exprContext(Expr2Context *ctx);

    Expr2Context *expr2();
    antlr4::tree::TerminalNode *ADD();
    Expr1Context *expr1();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr2_1Context : public Expr2Context {
  public:
    Expr2_1Context(Expr2Context *ctx);

    Expr1Context *expr1();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr2Context* expr2();
  Expr2Context* expr2(int precedence);
  class  Expr1Context : public antlr4::ParserRuleContext {
  public:
    Expr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expr1Context() = default;
    void copyFrom(Expr1Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Mod_exprContext : public Expr1Context {
  public:
    Mod_exprContext(Expr1Context *ctx);

    Expr1Context *expr1();
    antlr4::tree::TerminalNode *MOD();
    Expr0Context *expr0();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Expr1_0Context : public Expr1Context {
  public:
    Expr1_0Context(Expr1Context *ctx);

    Expr0Context *expr0();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Div_exprContext : public Expr1Context {
  public:
    Div_exprContext(Expr1Context *ctx);

    Expr1Context *expr1();
    antlr4::tree::TerminalNode *DIV();
    Expr0Context *expr0();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Mul_exprContext : public Expr1Context {
  public:
    Mul_exprContext(Expr1Context *ctx);

    Expr1Context *expr1();
    antlr4::tree::TerminalNode *MUL();
    Expr0Context *expr0();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr1Context* expr1();
  Expr1Context* expr1(int precedence);
  class  Expr0Context : public antlr4::ParserRuleContext {
  public:
    Expr0Context(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Expr0Context() = default;
    void copyFrom(Expr0Context *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Not_exprContext : public Expr0Context {
  public:
    Not_exprContext(Expr0Context *ctx);

    antlr4::tree::TerminalNode *NOT();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Inp_intContext : public Expr0Context {
  public:
    Inp_intContext(Expr0Context *ctx);

    antlr4::tree::TerminalNode *READ_INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CastContext : public Expr0Context {
  public:
    CastContext(Expr0Context *ctx);

    TypeContext *type();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Id_exprContext : public Expr0Context {
  public:
    Id_exprContext(Expr0Context *ctx);

    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lit_exprContext : public Expr0Context {
  public:
    Lit_exprContext(Expr0Context *ctx);

    LiteralContext *literal();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Call_exprContext : public Expr0Context {
  public:
    Call_exprContext(Expr0Context *ctx);

    Method_callContext *method_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Inp_charContext : public Expr0Context {
  public:
    Inp_charContext(Expr0Context *ctx);

    antlr4::tree::TerminalNode *READ_CHAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Negate_exprContext : public Expr0Context {
  public:
    Negate_exprContext(Expr0Context *ctx);

    antlr4::tree::TerminalNode *SUB();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Inp_boolContext : public Expr0Context {
  public:
    Inp_boolContext(Expr0Context *ctx);

    antlr4::tree::TerminalNode *READ_BOOL();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bracket_exprContext : public Expr0Context {
  public:
    Bracket_exprContext(Expr0Context *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Expr0Context* expr0();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IdentifierContext() = default;
    void copyFrom(IdentifierContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarContext : public IdentifierContext {
  public:
    VarContext(IdentifierContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Var_arrayContext : public IdentifierContext {
  public:
    Var_arrayContext(IdentifierContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IdentifierContext* identifier();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LiteralContext() = default;
    void copyFrom(LiteralContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Int_litContext : public LiteralContext {
  public:
    Int_litContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *INT_LIT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Float_litContext : public LiteralContext {
  public:
    Float_litContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *FLOAT_LIT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Char_litContext : public LiteralContext {
  public:
    Char_litContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *CHAR_LIT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Str_litContext : public LiteralContext {
  public:
    Str_litContext(LiteralContext *ctx);

    antlr4::tree::TerminalNode *STRING_LIT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Bool_literalContext : public LiteralContext {
  public:
    Bool_literalContext(LiteralContext *ctx);

    Bool_litContext *bool_lit();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LiteralContext* literal();

  class  Bool_litContext : public antlr4::ParserRuleContext {
  public:
    Bool_litContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Bool_litContext() = default;
    void copyFrom(Bool_litContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  True_litContext : public Bool_litContext {
  public:
    True_litContext(Bool_litContext *ctx);

    antlr4::tree::TerminalNode *TRUE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  False_litContext : public Bool_litContext {
  public:
    False_litContext(Bool_litContext *ctx);

    antlr4::tree::TerminalNode *FALSE();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Bool_litContext* bool_lit();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expr8Sempred(Expr8Context *_localctx, size_t predicateIndex);
  bool expr7Sempred(Expr7Context *_localctx, size_t predicateIndex);
  bool expr6Sempred(Expr6Context *_localctx, size_t predicateIndex);
  bool expr5Sempred(Expr5Context *_localctx, size_t predicateIndex);
  bool expr4Sempred(Expr4Context *_localctx, size_t predicateIndex);
  bool expr3Sempred(Expr3Context *_localctx, size_t predicateIndex);
  bool expr2Sempred(Expr2Context *_localctx, size_t predicateIndex);
  bool expr1Sempred(Expr1Context *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

