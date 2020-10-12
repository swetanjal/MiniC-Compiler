
// Generated from MiniC.g4 by ANTLR 4.8


#include "MiniCVisitor.h"

#include "MiniCParser.h"


using namespace antlrcpp;
using namespace antlr4;

MiniCParser::MiniCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MiniCParser::~MiniCParser() {
  delete _interpreter;
}

std::string MiniCParser::getGrammarFileName() const {
  return "MiniC.g4";
}

const std::vector<std::string>& MiniCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MiniCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

MiniCParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::ProgramContext::EOF() {
  return getToken(MiniCParser::EOF, 0);
}

std::vector<MiniCParser::DeclContext *> MiniCParser::ProgramContext::decl() {
  return getRuleContexts<MiniCParser::DeclContext>();
}

MiniCParser::DeclContext* MiniCParser::ProgramContext::decl(size_t i) {
  return getRuleContext<MiniCParser::DeclContext>(i);
}


size_t MiniCParser::ProgramContext::getRuleIndex() const {
  return MiniCParser::RuleProgram;
}


antlrcpp::Any MiniCParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ProgramContext* MiniCParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MiniCParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(44);
      decl();
      setState(47); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniCParser::VOID)
      | (1ULL << MiniCParser::FLOAT)
      | (1ULL << MiniCParser::INT)
      | (1ULL << MiniCParser::FILE)
      | (1ULL << MiniCParser::STRING)
      | (1ULL << MiniCParser::CHAR)
      | (1ULL << MiniCParser::UINT)
      | (1ULL << MiniCParser::BOOL))) != 0));
    setState(49);
    match(MiniCParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

MiniCParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::DeclContext::getRuleIndex() const {
  return MiniCParser::RuleDecl;
}

void MiniCParser::DeclContext::copyFrom(DeclContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MethodDeclContext ------------------------------------------------------------------

MiniCParser::Method_declContext* MiniCParser::MethodDeclContext::method_decl() {
  return getRuleContext<MiniCParser::Method_declContext>(0);
}

MiniCParser::MethodDeclContext::MethodDeclContext(DeclContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::MethodDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitMethodDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDeclContext ------------------------------------------------------------------

MiniCParser::Var_declContext* MiniCParser::VarDeclContext::var_decl() {
  return getRuleContext<MiniCParser::Var_declContext>(0);
}

MiniCParser::VarDeclContext::VarDeclContext(DeclContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}
MiniCParser::DeclContext* MiniCParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, MiniCParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(53);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclContext *>(_tracker.createInstance<MiniCParser::VarDeclContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(51);
      var_decl();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclContext *>(_tracker.createInstance<MiniCParser::MethodDeclContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(52);
      method_decl();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declContext ------------------------------------------------------------------

MiniCParser::Var_declContext::Var_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::TypeContext* MiniCParser::Var_declContext::type() {
  return getRuleContext<MiniCParser::TypeContext>(0);
}

std::vector<MiniCParser::IdentifierContext *> MiniCParser::Var_declContext::identifier() {
  return getRuleContexts<MiniCParser::IdentifierContext>();
}

MiniCParser::IdentifierContext* MiniCParser::Var_declContext::identifier(size_t i) {
  return getRuleContext<MiniCParser::IdentifierContext>(i);
}


size_t MiniCParser::Var_declContext::getRuleIndex() const {
  return MiniCParser::RuleVar_decl;
}


antlrcpp::Any MiniCParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Var_declContext* MiniCParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 4, MiniCParser::RuleVar_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    type();
    setState(56);
    identifier();
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MiniCParser::T__0) {
      setState(57);
      match(MiniCParser::T__0);
      setState(58);
      identifier();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
    match(MiniCParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_declContext ------------------------------------------------------------------

MiniCParser::Method_declContext::Method_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Method_declContext::getRuleIndex() const {
  return MiniCParser::RuleMethod_decl;
}

void MiniCParser::Method_declContext::copyFrom(Method_declContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Method_decl_voidContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Method_decl_voidContext::VOID() {
  return getToken(MiniCParser::VOID, 0);
}

tree::TerminalNode* MiniCParser::Method_decl_voidContext::ID() {
  return getToken(MiniCParser::ID, 0);
}

MiniCParser::BlockContext* MiniCParser::Method_decl_voidContext::block() {
  return getRuleContext<MiniCParser::BlockContext>(0);
}

std::vector<MiniCParser::TypeContext *> MiniCParser::Method_decl_voidContext::type() {
  return getRuleContexts<MiniCParser::TypeContext>();
}

MiniCParser::TypeContext* MiniCParser::Method_decl_voidContext::type(size_t i) {
  return getRuleContext<MiniCParser::TypeContext>(i);
}

std::vector<MiniCParser::IdentifierContext *> MiniCParser::Method_decl_voidContext::identifier() {
  return getRuleContexts<MiniCParser::IdentifierContext>();
}

MiniCParser::IdentifierContext* MiniCParser::Method_decl_voidContext::identifier(size_t i) {
  return getRuleContext<MiniCParser::IdentifierContext>(i);
}

MiniCParser::Method_decl_voidContext::Method_decl_voidContext(Method_declContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Method_decl_voidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitMethod_decl_void(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Method_decl_typeContext ------------------------------------------------------------------

std::vector<MiniCParser::TypeContext *> MiniCParser::Method_decl_typeContext::type() {
  return getRuleContexts<MiniCParser::TypeContext>();
}

MiniCParser::TypeContext* MiniCParser::Method_decl_typeContext::type(size_t i) {
  return getRuleContext<MiniCParser::TypeContext>(i);
}

tree::TerminalNode* MiniCParser::Method_decl_typeContext::ID() {
  return getToken(MiniCParser::ID, 0);
}

MiniCParser::BlockContext* MiniCParser::Method_decl_typeContext::block() {
  return getRuleContext<MiniCParser::BlockContext>(0);
}

std::vector<MiniCParser::IdentifierContext *> MiniCParser::Method_decl_typeContext::identifier() {
  return getRuleContexts<MiniCParser::IdentifierContext>();
}

MiniCParser::IdentifierContext* MiniCParser::Method_decl_typeContext::identifier(size_t i) {
  return getRuleContext<MiniCParser::IdentifierContext>(i);
}

MiniCParser::Method_decl_typeContext::Method_decl_typeContext(Method_declContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Method_decl_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitMethod_decl_type(this);
  else
    return visitor->visitChildren(this);
}
MiniCParser::Method_declContext* MiniCParser::method_decl() {
  Method_declContext *_localctx = _tracker.createInstance<Method_declContext>(_ctx, getState());
  enterRule(_localctx, 6, MiniCParser::RuleMethod_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::FLOAT:
      case MiniCParser::INT:
      case MiniCParser::FILE:
      case MiniCParser::STRING:
      case MiniCParser::CHAR:
      case MiniCParser::UINT:
      case MiniCParser::BOOL: {
        _localctx = dynamic_cast<Method_declContext *>(_tracker.createInstance<MiniCParser::Method_decl_typeContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(66);
        type();
        setState(67);
        match(MiniCParser::ID);
        setState(68);
        match(MiniCParser::T__2);
        setState(80);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniCParser::FLOAT)
          | (1ULL << MiniCParser::INT)
          | (1ULL << MiniCParser::FILE)
          | (1ULL << MiniCParser::STRING)
          | (1ULL << MiniCParser::CHAR)
          | (1ULL << MiniCParser::UINT)
          | (1ULL << MiniCParser::BOOL))) != 0)) {
          setState(69);
          type();
          setState(70);
          identifier();
          setState(77);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MiniCParser::T__0) {
            setState(71);
            match(MiniCParser::T__0);
            setState(72);
            type();
            setState(73);
            identifier();
            setState(79);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(82);
        match(MiniCParser::T__3);
        setState(83);
        block();
        break;
      }

      case MiniCParser::VOID: {
        _localctx = dynamic_cast<Method_declContext *>(_tracker.createInstance<MiniCParser::Method_decl_voidContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(85);
        match(MiniCParser::VOID);
        setState(86);
        match(MiniCParser::ID);
        setState(87);
        match(MiniCParser::T__2);
        setState(99);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MiniCParser::FLOAT)
          | (1ULL << MiniCParser::INT)
          | (1ULL << MiniCParser::FILE)
          | (1ULL << MiniCParser::STRING)
          | (1ULL << MiniCParser::CHAR)
          | (1ULL << MiniCParser::UINT)
          | (1ULL << MiniCParser::BOOL))) != 0)) {
          setState(88);
          type();
          setState(89);
          identifier();
          setState(96);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == MiniCParser::T__0) {
            setState(90);
            match(MiniCParser::T__0);
            setState(91);
            type();
            setState(92);
            identifier();
            setState(98);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(101);
        match(MiniCParser::T__3);
        setState(102);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MiniCParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MiniCParser::Var_declContext *> MiniCParser::BlockContext::var_decl() {
  return getRuleContexts<MiniCParser::Var_declContext>();
}

MiniCParser::Var_declContext* MiniCParser::BlockContext::var_decl(size_t i) {
  return getRuleContext<MiniCParser::Var_declContext>(i);
}

std::vector<MiniCParser::StatementContext *> MiniCParser::BlockContext::statement() {
  return getRuleContexts<MiniCParser::StatementContext>();
}

MiniCParser::StatementContext* MiniCParser::BlockContext::statement(size_t i) {
  return getRuleContext<MiniCParser::StatementContext>(i);
}


size_t MiniCParser::BlockContext::getRuleIndex() const {
  return MiniCParser::RuleBlock;
}


antlrcpp::Any MiniCParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::BlockContext* MiniCParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 8, MiniCParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(MiniCParser::T__4);
    setState(109);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniCParser::FLOAT)
      | (1ULL << MiniCParser::INT)
      | (1ULL << MiniCParser::FILE)
      | (1ULL << MiniCParser::STRING)
      | (1ULL << MiniCParser::CHAR)
      | (1ULL << MiniCParser::UINT)
      | (1ULL << MiniCParser::BOOL))) != 0)) {
      setState(106);
      var_decl();
      setState(111);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniCParser::T__4)
      | (1ULL << MiniCParser::FOR)
      | (1ULL << MiniCParser::WHILE)
      | (1ULL << MiniCParser::IF)
      | (1ULL << MiniCParser::BREAK)
      | (1ULL << MiniCParser::CONTINUE)
      | (1ULL << MiniCParser::RETURN)
      | (1ULL << MiniCParser::PRINT)
      | (1ULL << MiniCParser::PRINTLN)
      | (1ULL << MiniCParser::ID))) != 0)) {
      setState(112);
      statement();
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(118);
    match(MiniCParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

MiniCParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::TypeContext::getRuleIndex() const {
  return MiniCParser::RuleType;
}

void MiniCParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TypeIntContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::TypeIntContext::INT() {
  return getToken(MiniCParser::INT, 0);
}

MiniCParser::TypeIntContext::TypeIntContext(TypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::TypeIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitTypeInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeFloatContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::TypeFloatContext::FLOAT() {
  return getToken(MiniCParser::FLOAT, 0);
}

MiniCParser::TypeFloatContext::TypeFloatContext(TypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::TypeFloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitTypeFloat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeUintContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::TypeUintContext::UINT() {
  return getToken(MiniCParser::UINT, 0);
}

MiniCParser::TypeUintContext::TypeUintContext(TypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::TypeUintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitTypeUint(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeCharContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::TypeCharContext::CHAR() {
  return getToken(MiniCParser::CHAR, 0);
}

MiniCParser::TypeCharContext::TypeCharContext(TypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::TypeCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitTypeChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeStringContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::TypeStringContext::STRING() {
  return getToken(MiniCParser::STRING, 0);
}

MiniCParser::TypeStringContext::TypeStringContext(TypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::TypeStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitTypeString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeBoolContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::TypeBoolContext::BOOL() {
  return getToken(MiniCParser::BOOL, 0);
}

MiniCParser::TypeBoolContext::TypeBoolContext(TypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::TypeBoolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitTypeBool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeFileContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::TypeFileContext::FILE() {
  return getToken(MiniCParser::FILE, 0);
}

MiniCParser::TypeFileContext::TypeFileContext(TypeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::TypeFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitTypeFile(this);
  else
    return visitor->visitChildren(this);
}
MiniCParser::TypeContext* MiniCParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 10, MiniCParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::INT: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<MiniCParser::TypeIntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(120);
        match(MiniCParser::INT);
        break;
      }

      case MiniCParser::UINT: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<MiniCParser::TypeUintContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(121);
        match(MiniCParser::UINT);
        break;
      }

      case MiniCParser::BOOL: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<MiniCParser::TypeBoolContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(122);
        match(MiniCParser::BOOL);
        break;
      }

      case MiniCParser::CHAR: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<MiniCParser::TypeCharContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(123);
        match(MiniCParser::CHAR);
        break;
      }

      case MiniCParser::FILE: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<MiniCParser::TypeFileContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(124);
        match(MiniCParser::FILE);
        break;
      }

      case MiniCParser::STRING: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<MiniCParser::TypeStringContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(125);
        match(MiniCParser::STRING);
        break;
      }

      case MiniCParser::FLOAT: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<MiniCParser::TypeFloatContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(126);
        match(MiniCParser::FLOAT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MiniCParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::StatementContext::getRuleIndex() const {
  return MiniCParser::RuleStatement;
}

void MiniCParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ContiueContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::ContiueContext::CONTINUE() {
  return getToken(MiniCParser::CONTINUE, 0);
}

MiniCParser::ContiueContext::ContiueContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::ContiueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitContiue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::PrintContext::PRINT() {
  return getToken(MiniCParser::PRINT, 0);
}

MiniCParser::ExprContext* MiniCParser::PrintContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

MiniCParser::PrintContext::PrintContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintlnContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::PrintlnContext::PRINTLN() {
  return getToken(MiniCParser::PRINTLN, 0);
}

MiniCParser::ExprContext* MiniCParser::PrintlnContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

MiniCParser::PrintlnContext::PrintlnContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::PrintlnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitPrintln(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::BreakContext::BREAK() {
  return getToken(MiniCParser::BREAK, 0);
}

MiniCParser::BreakContext::BreakContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::BreakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitBreak(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListAssnContext ------------------------------------------------------------------

std::vector<MiniCParser::AssignmentContext *> MiniCParser::ListAssnContext::assignment() {
  return getRuleContexts<MiniCParser::AssignmentContext>();
}

MiniCParser::AssignmentContext* MiniCParser::ListAssnContext::assignment(size_t i) {
  return getRuleContext<MiniCParser::AssignmentContext>(i);
}

MiniCParser::ListAssnContext::ListAssnContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::ListAssnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitListAssn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::ForContext::FOR() {
  return getToken(MiniCParser::FOR, 0);
}

MiniCParser::BlockContext* MiniCParser::ForContext::block() {
  return getRuleContext<MiniCParser::BlockContext>(0);
}

std::vector<MiniCParser::AssignmentContext *> MiniCParser::ForContext::assignment() {
  return getRuleContexts<MiniCParser::AssignmentContext>();
}

MiniCParser::AssignmentContext* MiniCParser::ForContext::assignment(size_t i) {
  return getRuleContext<MiniCParser::AssignmentContext>(i);
}

std::vector<MiniCParser::ExprContext *> MiniCParser::ForContext::expr() {
  return getRuleContexts<MiniCParser::ExprContext>();
}

MiniCParser::ExprContext* MiniCParser::ForContext::expr(size_t i) {
  return getRuleContext<MiniCParser::ExprContext>(i);
}

MiniCParser::ForContext::ForContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::ForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitFor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::WhileContext::WHILE() {
  return getToken(MiniCParser::WHILE, 0);
}

MiniCParser::ExprContext* MiniCParser::WhileContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

MiniCParser::BlockContext* MiniCParser::WhileContext::block() {
  return getRuleContext<MiniCParser::BlockContext>(0);
}

MiniCParser::WhileContext::WhileContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlckContext ------------------------------------------------------------------

MiniCParser::BlockContext* MiniCParser::BlckContext::block() {
  return getRuleContext<MiniCParser::BlockContext>(0);
}

MiniCParser::BlckContext::BlckContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::BlckContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitBlck(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::IfContext::IF() {
  return getToken(MiniCParser::IF, 0);
}

MiniCParser::ExprContext* MiniCParser::IfContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

std::vector<MiniCParser::BlockContext *> MiniCParser::IfContext::block() {
  return getRuleContexts<MiniCParser::BlockContext>();
}

MiniCParser::BlockContext* MiniCParser::IfContext::block(size_t i) {
  return getRuleContext<MiniCParser::BlockContext>(i);
}

tree::TerminalNode* MiniCParser::IfContext::ELSE() {
  return getToken(MiniCParser::ELSE, 0);
}

MiniCParser::IfContext::IfContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::IfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::ReturnContext::RETURN() {
  return getToken(MiniCParser::RETURN, 0);
}

MiniCParser::ExprContext* MiniCParser::ReturnContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

MiniCParser::ReturnContext::ReturnContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MethodCallContext ------------------------------------------------------------------

MiniCParser::Method_callContext* MiniCParser::MethodCallContext::method_call() {
  return getRuleContext<MiniCParser::Method_callContext>(0);
}

MiniCParser::MethodCallContext::MethodCallContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::MethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitMethodCall(this);
  else
    return visitor->visitChildren(this);
}
MiniCParser::StatementContext* MiniCParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 12, MiniCParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(215);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::ListAssnContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(129);
      assignment();
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MiniCParser::T__0) {
        setState(130);
        match(MiniCParser::T__0);
        setState(131);
        assignment();
        setState(136);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(137);
      match(MiniCParser::T__1);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::MethodCallContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(139);
      method_call();
      setState(140);
      match(MiniCParser::T__1);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::IfContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(142);
      match(MiniCParser::IF);
      setState(143);
      match(MiniCParser::T__2);
      setState(144);
      expr();
      setState(145);
      match(MiniCParser::T__3);
      setState(146);
      block();
      setState(149);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniCParser::ELSE) {
        setState(147);
        match(MiniCParser::ELSE);
        setState(148);
        block();
      }
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::ForContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(151);
      match(MiniCParser::FOR);
      setState(152);
      match(MiniCParser::T__2);
      setState(161);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniCParser::ID) {
        setState(153);
        assignment();
        setState(158);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MiniCParser::T__0) {
          setState(154);
          match(MiniCParser::T__0);
          setState(155);
          assignment();
          setState(160);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(163);
      match(MiniCParser::T__1);
      setState(172);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniCParser::T__2)
        | (1ULL << MiniCParser::FALSE)
        | (1ULL << MiniCParser::TRUE)
        | (1ULL << MiniCParser::NOT)
        | (1ULL << MiniCParser::SUB)
        | (1ULL << MiniCParser::READ_INT)
        | (1ULL << MiniCParser::READ_CHAR)
        | (1ULL << MiniCParser::READ_BOOL)
        | (1ULL << MiniCParser::INT_LIT)
        | (1ULL << MiniCParser::FLOAT_LIT)
        | (1ULL << MiniCParser::CHAR_LIT)
        | (1ULL << MiniCParser::ID)
        | (1ULL << MiniCParser::STRING_LIT))) != 0)) {
        setState(164);
        expr();
        setState(169);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MiniCParser::T__0) {
          setState(165);
          match(MiniCParser::T__0);
          setState(166);
          expr();
          setState(171);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(174);
      match(MiniCParser::T__1);
      setState(183);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MiniCParser::ID) {
        setState(175);
        assignment();
        setState(180);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MiniCParser::T__0) {
          setState(176);
          match(MiniCParser::T__0);
          setState(177);
          assignment();
          setState(182);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(185);
      match(MiniCParser::T__3);
      setState(186);
      block();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::WhileContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(187);
      match(MiniCParser::WHILE);
      setState(188);
      match(MiniCParser::T__2);
      setState(189);
      expr();
      setState(190);
      match(MiniCParser::T__3);
      setState(191);
      block();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::BreakContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(193);
      match(MiniCParser::BREAK);
      setState(194);
      match(MiniCParser::T__1);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::ContiueContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(195);
      match(MiniCParser::CONTINUE);
      setState(196);
      match(MiniCParser::T__1);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::BlckContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(197);
      block();
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::ReturnContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(198);
      match(MiniCParser::RETURN);
      setState(200);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MiniCParser::T__2)
        | (1ULL << MiniCParser::FALSE)
        | (1ULL << MiniCParser::TRUE)
        | (1ULL << MiniCParser::NOT)
        | (1ULL << MiniCParser::SUB)
        | (1ULL << MiniCParser::READ_INT)
        | (1ULL << MiniCParser::READ_CHAR)
        | (1ULL << MiniCParser::READ_BOOL)
        | (1ULL << MiniCParser::INT_LIT)
        | (1ULL << MiniCParser::FLOAT_LIT)
        | (1ULL << MiniCParser::CHAR_LIT)
        | (1ULL << MiniCParser::ID)
        | (1ULL << MiniCParser::STRING_LIT))) != 0)) {
        setState(199);
        expr();
      }
      setState(202);
      match(MiniCParser::T__1);
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::PrintContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(203);
      match(MiniCParser::PRINT);
      setState(204);
      match(MiniCParser::T__2);
      setState(205);
      expr();
      setState(206);
      match(MiniCParser::T__3);
      setState(207);
      match(MiniCParser::T__1);
      break;
    }

    case 11: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MiniCParser::PrintlnContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(209);
      match(MiniCParser::PRINTLN);
      setState(210);
      match(MiniCParser::T__2);
      setState(211);
      expr();
      setState(212);
      match(MiniCParser::T__3);
      setState(213);
      match(MiniCParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

MiniCParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::IdentifierContext* MiniCParser::AssignmentContext::identifier() {
  return getRuleContext<MiniCParser::IdentifierContext>(0);
}

tree::TerminalNode* MiniCParser::AssignmentContext::ASSIGN() {
  return getToken(MiniCParser::ASSIGN, 0);
}

MiniCParser::ExprContext* MiniCParser::AssignmentContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}


size_t MiniCParser::AssignmentContext::getRuleIndex() const {
  return MiniCParser::RuleAssignment;
}


antlrcpp::Any MiniCParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::AssignmentContext* MiniCParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 14, MiniCParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    identifier();
    setState(218);
    match(MiniCParser::ASSIGN);
    setState(219);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Method_callContext ------------------------------------------------------------------

MiniCParser::Method_callContext::Method_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MiniCParser::Method_callContext::ID() {
  return getToken(MiniCParser::ID, 0);
}

std::vector<MiniCParser::ExprContext *> MiniCParser::Method_callContext::expr() {
  return getRuleContexts<MiniCParser::ExprContext>();
}

MiniCParser::ExprContext* MiniCParser::Method_callContext::expr(size_t i) {
  return getRuleContext<MiniCParser::ExprContext>(i);
}


size_t MiniCParser::Method_callContext::getRuleIndex() const {
  return MiniCParser::RuleMethod_call;
}


antlrcpp::Any MiniCParser::Method_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitMethod_call(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Method_callContext* MiniCParser::method_call() {
  Method_callContext *_localctx = _tracker.createInstance<Method_callContext>(_ctx, getState());
  enterRule(_localctx, 16, MiniCParser::RuleMethod_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(MiniCParser::ID);
    setState(222);
    match(MiniCParser::T__2);
    setState(231);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MiniCParser::T__2)
      | (1ULL << MiniCParser::FALSE)
      | (1ULL << MiniCParser::TRUE)
      | (1ULL << MiniCParser::NOT)
      | (1ULL << MiniCParser::SUB)
      | (1ULL << MiniCParser::READ_INT)
      | (1ULL << MiniCParser::READ_CHAR)
      | (1ULL << MiniCParser::READ_BOOL)
      | (1ULL << MiniCParser::INT_LIT)
      | (1ULL << MiniCParser::FLOAT_LIT)
      | (1ULL << MiniCParser::CHAR_LIT)
      | (1ULL << MiniCParser::ID)
      | (1ULL << MiniCParser::STRING_LIT))) != 0)) {
      setState(223);
      expr();
      setState(228);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MiniCParser::T__0) {
        setState(224);
        match(MiniCParser::T__0);
        setState(225);
        expr();
        setState(230);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(233);
    match(MiniCParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MiniCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MiniCParser::Expr8Context* MiniCParser::ExprContext::expr8() {
  return getRuleContext<MiniCParser::Expr8Context>(0);
}


size_t MiniCParser::ExprContext::getRuleIndex() const {
  return MiniCParser::RuleExpr;
}


antlrcpp::Any MiniCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::ExprContext* MiniCParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 18, MiniCParser::RuleExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    expr8(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr8Context ------------------------------------------------------------------

MiniCParser::Expr8Context::Expr8Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Expr8Context::getRuleIndex() const {
  return MiniCParser::RuleExpr8;
}

void MiniCParser::Expr8Context::copyFrom(Expr8Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expr8_7Context ------------------------------------------------------------------

MiniCParser::Expr7Context* MiniCParser::Expr8_7Context::expr7() {
  return getRuleContext<MiniCParser::Expr7Context>(0);
}

MiniCParser::Expr8_7Context::Expr8_7Context(Expr8Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Expr8_7Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr8_7(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Ternary_exprContext ------------------------------------------------------------------

std::vector<MiniCParser::Expr8Context *> MiniCParser::Ternary_exprContext::expr8() {
  return getRuleContexts<MiniCParser::Expr8Context>();
}

MiniCParser::Expr8Context* MiniCParser::Ternary_exprContext::expr8(size_t i) {
  return getRuleContext<MiniCParser::Expr8Context>(i);
}

tree::TerminalNode* MiniCParser::Ternary_exprContext::THEN() {
  return getToken(MiniCParser::THEN, 0);
}

tree::TerminalNode* MiniCParser::Ternary_exprContext::OTHERWISE() {
  return getToken(MiniCParser::OTHERWISE, 0);
}

MiniCParser::Ternary_exprContext::Ternary_exprContext(Expr8Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Ternary_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitTernary_expr(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Expr8Context* MiniCParser::expr8() {
   return expr8(0);
}

MiniCParser::Expr8Context* MiniCParser::expr8(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::Expr8Context *_localctx = _tracker.createInstance<Expr8Context>(_ctx, parentState);
  MiniCParser::Expr8Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, MiniCParser::RuleExpr8, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Expr8_7Context>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(238);
    expr7(0);
    _ctx->stop = _input->LT(-1);
    setState(248);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Ternary_exprContext>(_tracker.createInstance<Expr8Context>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleExpr8);
        setState(240);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(241);
        match(MiniCParser::THEN);
        setState(242);
        expr8(0);
        setState(243);
        match(MiniCParser::OTHERWISE);
        setState(244);
        expr8(3); 
      }
      setState(250);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr7Context ------------------------------------------------------------------

MiniCParser::Expr7Context::Expr7Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Expr7Context::getRuleIndex() const {
  return MiniCParser::RuleExpr7;
}

void MiniCParser::Expr7Context::copyFrom(Expr7Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expr7_6Context ------------------------------------------------------------------

MiniCParser::Expr6Context* MiniCParser::Expr7_6Context::expr6() {
  return getRuleContext<MiniCParser::Expr6Context>(0);
}

MiniCParser::Expr7_6Context::Expr7_6Context(Expr7Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Expr7_6Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr7_6(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Or_exprContext ------------------------------------------------------------------

MiniCParser::Expr7Context* MiniCParser::Or_exprContext::expr7() {
  return getRuleContext<MiniCParser::Expr7Context>(0);
}

tree::TerminalNode* MiniCParser::Or_exprContext::OR() {
  return getToken(MiniCParser::OR, 0);
}

MiniCParser::Expr6Context* MiniCParser::Or_exprContext::expr6() {
  return getRuleContext<MiniCParser::Expr6Context>(0);
}

MiniCParser::Or_exprContext::Or_exprContext(Expr7Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Or_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitOr_expr(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Expr7Context* MiniCParser::expr7() {
   return expr7(0);
}

MiniCParser::Expr7Context* MiniCParser::expr7(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::Expr7Context *_localctx = _tracker.createInstance<Expr7Context>(_ctx, parentState);
  MiniCParser::Expr7Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, MiniCParser::RuleExpr7, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Expr7_6Context>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(252);
    expr6(0);
    _ctx->stop = _input->LT(-1);
    setState(259);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Or_exprContext>(_tracker.createInstance<Expr7Context>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleExpr7);
        setState(254);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(255);
        match(MiniCParser::OR);
        setState(256);
        expr6(0); 
      }
      setState(261);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr6Context ------------------------------------------------------------------

MiniCParser::Expr6Context::Expr6Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Expr6Context::getRuleIndex() const {
  return MiniCParser::RuleExpr6;
}

void MiniCParser::Expr6Context::copyFrom(Expr6Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- And_exprContext ------------------------------------------------------------------

MiniCParser::Expr6Context* MiniCParser::And_exprContext::expr6() {
  return getRuleContext<MiniCParser::Expr6Context>(0);
}

tree::TerminalNode* MiniCParser::And_exprContext::AND() {
  return getToken(MiniCParser::AND, 0);
}

MiniCParser::Expr5Context* MiniCParser::And_exprContext::expr5() {
  return getRuleContext<MiniCParser::Expr5Context>(0);
}

MiniCParser::And_exprContext::And_exprContext(Expr6Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::And_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitAnd_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr6_5Context ------------------------------------------------------------------

MiniCParser::Expr5Context* MiniCParser::Expr6_5Context::expr5() {
  return getRuleContext<MiniCParser::Expr5Context>(0);
}

MiniCParser::Expr6_5Context::Expr6_5Context(Expr6Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Expr6_5Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr6_5(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Expr6Context* MiniCParser::expr6() {
   return expr6(0);
}

MiniCParser::Expr6Context* MiniCParser::expr6(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::Expr6Context *_localctx = _tracker.createInstance<Expr6Context>(_ctx, parentState);
  MiniCParser::Expr6Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, MiniCParser::RuleExpr6, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Expr6_5Context>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(263);
    expr5(0);
    _ctx->stop = _input->LT(-1);
    setState(270);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<And_exprContext>(_tracker.createInstance<Expr6Context>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleExpr6);
        setState(265);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(266);
        match(MiniCParser::AND);
        setState(267);
        expr5(0); 
      }
      setState(272);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr5Context ------------------------------------------------------------------

MiniCParser::Expr5Context::Expr5Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Expr5Context::getRuleIndex() const {
  return MiniCParser::RuleExpr5;
}

void MiniCParser::Expr5Context::copyFrom(Expr5Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Eq_exprContext ------------------------------------------------------------------

MiniCParser::Expr5Context* MiniCParser::Eq_exprContext::expr5() {
  return getRuleContext<MiniCParser::Expr5Context>(0);
}

tree::TerminalNode* MiniCParser::Eq_exprContext::EQ() {
  return getToken(MiniCParser::EQ, 0);
}

MiniCParser::Expr4Context* MiniCParser::Eq_exprContext::expr4() {
  return getRuleContext<MiniCParser::Expr4Context>(0);
}

MiniCParser::Eq_exprContext::Eq_exprContext(Expr5Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Eq_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitEq_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr5_4Context ------------------------------------------------------------------

MiniCParser::Expr4Context* MiniCParser::Expr5_4Context::expr4() {
  return getRuleContext<MiniCParser::Expr4Context>(0);
}

MiniCParser::Expr5_4Context::Expr5_4Context(Expr5Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Expr5_4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr5_4(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Ne_exprContext ------------------------------------------------------------------

MiniCParser::Expr5Context* MiniCParser::Ne_exprContext::expr5() {
  return getRuleContext<MiniCParser::Expr5Context>(0);
}

tree::TerminalNode* MiniCParser::Ne_exprContext::NE() {
  return getToken(MiniCParser::NE, 0);
}

MiniCParser::Expr4Context* MiniCParser::Ne_exprContext::expr4() {
  return getRuleContext<MiniCParser::Expr4Context>(0);
}

MiniCParser::Ne_exprContext::Ne_exprContext(Expr5Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Ne_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitNe_expr(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Expr5Context* MiniCParser::expr5() {
   return expr5(0);
}

MiniCParser::Expr5Context* MiniCParser::expr5(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::Expr5Context *_localctx = _tracker.createInstance<Expr5Context>(_ctx, parentState);
  MiniCParser::Expr5Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, MiniCParser::RuleExpr5, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Expr5_4Context>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(274);
    expr4(0);
    _ctx->stop = _input->LT(-1);
    setState(284);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(282);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Eq_exprContext>(_tracker.createInstance<Expr5Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr5);
          setState(276);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(277);
          match(MiniCParser::EQ);
          setState(278);
          expr4(0);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Ne_exprContext>(_tracker.createInstance<Expr5Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr5);
          setState(279);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(280);
          match(MiniCParser::NE);
          setState(281);
          expr4(0);
          break;
        }

        } 
      }
      setState(286);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr4Context ------------------------------------------------------------------

MiniCParser::Expr4Context::Expr4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Expr4Context::getRuleIndex() const {
  return MiniCParser::RuleExpr4;
}

void MiniCParser::Expr4Context::copyFrom(Expr4Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Ge_exprContext ------------------------------------------------------------------

MiniCParser::Expr4Context* MiniCParser::Ge_exprContext::expr4() {
  return getRuleContext<MiniCParser::Expr4Context>(0);
}

tree::TerminalNode* MiniCParser::Ge_exprContext::GE() {
  return getToken(MiniCParser::GE, 0);
}

MiniCParser::Expr3Context* MiniCParser::Ge_exprContext::expr3() {
  return getRuleContext<MiniCParser::Expr3Context>(0);
}

MiniCParser::Ge_exprContext::Ge_exprContext(Expr4Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Ge_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitGe_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Gt_exprContext ------------------------------------------------------------------

MiniCParser::Expr4Context* MiniCParser::Gt_exprContext::expr4() {
  return getRuleContext<MiniCParser::Expr4Context>(0);
}

tree::TerminalNode* MiniCParser::Gt_exprContext::GT() {
  return getToken(MiniCParser::GT, 0);
}

MiniCParser::Expr3Context* MiniCParser::Gt_exprContext::expr3() {
  return getRuleContext<MiniCParser::Expr3Context>(0);
}

MiniCParser::Gt_exprContext::Gt_exprContext(Expr4Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Gt_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitGt_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr4_3Context ------------------------------------------------------------------

MiniCParser::Expr3Context* MiniCParser::Expr4_3Context::expr3() {
  return getRuleContext<MiniCParser::Expr3Context>(0);
}

MiniCParser::Expr4_3Context::Expr4_3Context(Expr4Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Expr4_3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr4_3(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Expr4Context* MiniCParser::expr4() {
   return expr4(0);
}

MiniCParser::Expr4Context* MiniCParser::expr4(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::Expr4Context *_localctx = _tracker.createInstance<Expr4Context>(_ctx, parentState);
  MiniCParser::Expr4Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, MiniCParser::RuleExpr4, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Expr4_3Context>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(288);
    expr3(0);
    _ctx->stop = _input->LT(-1);
    setState(298);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(296);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Gt_exprContext>(_tracker.createInstance<Expr4Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr4);
          setState(290);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(291);
          match(MiniCParser::GT);
          setState(292);
          expr3(0);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Ge_exprContext>(_tracker.createInstance<Expr4Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr4);
          setState(293);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(294);
          match(MiniCParser::GE);
          setState(295);
          expr3(0);
          break;
        }

        } 
      }
      setState(300);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr3Context ------------------------------------------------------------------

MiniCParser::Expr3Context::Expr3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Expr3Context::getRuleIndex() const {
  return MiniCParser::RuleExpr3;
}

void MiniCParser::Expr3Context::copyFrom(Expr3Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Lt_exprContext ------------------------------------------------------------------

MiniCParser::Expr3Context* MiniCParser::Lt_exprContext::expr3() {
  return getRuleContext<MiniCParser::Expr3Context>(0);
}

tree::TerminalNode* MiniCParser::Lt_exprContext::LT() {
  return getToken(MiniCParser::LT, 0);
}

MiniCParser::Expr2Context* MiniCParser::Lt_exprContext::expr2() {
  return getRuleContext<MiniCParser::Expr2Context>(0);
}

MiniCParser::Lt_exprContext::Lt_exprContext(Expr3Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Lt_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitLt_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr3_2Context ------------------------------------------------------------------

MiniCParser::Expr2Context* MiniCParser::Expr3_2Context::expr2() {
  return getRuleContext<MiniCParser::Expr2Context>(0);
}

MiniCParser::Expr3_2Context::Expr3_2Context(Expr3Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Expr3_2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr3_2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Le_exprContext ------------------------------------------------------------------

MiniCParser::Expr3Context* MiniCParser::Le_exprContext::expr3() {
  return getRuleContext<MiniCParser::Expr3Context>(0);
}

tree::TerminalNode* MiniCParser::Le_exprContext::LE() {
  return getToken(MiniCParser::LE, 0);
}

MiniCParser::Expr2Context* MiniCParser::Le_exprContext::expr2() {
  return getRuleContext<MiniCParser::Expr2Context>(0);
}

MiniCParser::Le_exprContext::Le_exprContext(Expr3Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Le_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitLe_expr(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Expr3Context* MiniCParser::expr3() {
   return expr3(0);
}

MiniCParser::Expr3Context* MiniCParser::expr3(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::Expr3Context *_localctx = _tracker.createInstance<Expr3Context>(_ctx, parentState);
  MiniCParser::Expr3Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, MiniCParser::RuleExpr3, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Expr3_2Context>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(302);
    expr2(0);
    _ctx->stop = _input->LT(-1);
    setState(312);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(310);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Lt_exprContext>(_tracker.createInstance<Expr3Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr3);
          setState(304);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(305);
          match(MiniCParser::LT);
          setState(306);
          expr2(0);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Le_exprContext>(_tracker.createInstance<Expr3Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr3);
          setState(307);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(308);
          match(MiniCParser::LE);
          setState(309);
          expr2(0);
          break;
        }

        } 
      }
      setState(314);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr2Context ------------------------------------------------------------------

MiniCParser::Expr2Context::Expr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Expr2Context::getRuleIndex() const {
  return MiniCParser::RuleExpr2;
}

void MiniCParser::Expr2Context::copyFrom(Expr2Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Sub_exprContext ------------------------------------------------------------------

MiniCParser::Expr2Context* MiniCParser::Sub_exprContext::expr2() {
  return getRuleContext<MiniCParser::Expr2Context>(0);
}

tree::TerminalNode* MiniCParser::Sub_exprContext::SUB() {
  return getToken(MiniCParser::SUB, 0);
}

MiniCParser::Expr1Context* MiniCParser::Sub_exprContext::expr1() {
  return getRuleContext<MiniCParser::Expr1Context>(0);
}

MiniCParser::Sub_exprContext::Sub_exprContext(Expr2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Sub_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitSub_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Add_exprContext ------------------------------------------------------------------

MiniCParser::Expr2Context* MiniCParser::Add_exprContext::expr2() {
  return getRuleContext<MiniCParser::Expr2Context>(0);
}

tree::TerminalNode* MiniCParser::Add_exprContext::ADD() {
  return getToken(MiniCParser::ADD, 0);
}

MiniCParser::Expr1Context* MiniCParser::Add_exprContext::expr1() {
  return getRuleContext<MiniCParser::Expr1Context>(0);
}

MiniCParser::Add_exprContext::Add_exprContext(Expr2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Add_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitAdd_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr2_1Context ------------------------------------------------------------------

MiniCParser::Expr1Context* MiniCParser::Expr2_1Context::expr1() {
  return getRuleContext<MiniCParser::Expr1Context>(0);
}

MiniCParser::Expr2_1Context::Expr2_1Context(Expr2Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Expr2_1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr2_1(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Expr2Context* MiniCParser::expr2() {
   return expr2(0);
}

MiniCParser::Expr2Context* MiniCParser::expr2(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::Expr2Context *_localctx = _tracker.createInstance<Expr2Context>(_ctx, parentState);
  MiniCParser::Expr2Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, MiniCParser::RuleExpr2, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Expr2_1Context>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(316);
    expr1(0);
    _ctx->stop = _input->LT(-1);
    setState(326);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(324);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Add_exprContext>(_tracker.createInstance<Expr2Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr2);
          setState(318);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(319);
          match(MiniCParser::ADD);
          setState(320);
          expr1(0);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Sub_exprContext>(_tracker.createInstance<Expr2Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr2);
          setState(321);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(322);
          match(MiniCParser::SUB);
          setState(323);
          expr1(0);
          break;
        }

        } 
      }
      setState(328);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr1Context ------------------------------------------------------------------

MiniCParser::Expr1Context::Expr1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Expr1Context::getRuleIndex() const {
  return MiniCParser::RuleExpr1;
}

void MiniCParser::Expr1Context::copyFrom(Expr1Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Mod_exprContext ------------------------------------------------------------------

MiniCParser::Expr1Context* MiniCParser::Mod_exprContext::expr1() {
  return getRuleContext<MiniCParser::Expr1Context>(0);
}

tree::TerminalNode* MiniCParser::Mod_exprContext::MOD() {
  return getToken(MiniCParser::MOD, 0);
}

MiniCParser::Expr0Context* MiniCParser::Mod_exprContext::expr0() {
  return getRuleContext<MiniCParser::Expr0Context>(0);
}

MiniCParser::Mod_exprContext::Mod_exprContext(Expr1Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Mod_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitMod_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr1_0Context ------------------------------------------------------------------

MiniCParser::Expr0Context* MiniCParser::Expr1_0Context::expr0() {
  return getRuleContext<MiniCParser::Expr0Context>(0);
}

MiniCParser::Expr1_0Context::Expr1_0Context(Expr1Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Expr1_0Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitExpr1_0(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Div_exprContext ------------------------------------------------------------------

MiniCParser::Expr1Context* MiniCParser::Div_exprContext::expr1() {
  return getRuleContext<MiniCParser::Expr1Context>(0);
}

tree::TerminalNode* MiniCParser::Div_exprContext::DIV() {
  return getToken(MiniCParser::DIV, 0);
}

MiniCParser::Expr0Context* MiniCParser::Div_exprContext::expr0() {
  return getRuleContext<MiniCParser::Expr0Context>(0);
}

MiniCParser::Div_exprContext::Div_exprContext(Expr1Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Div_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitDiv_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Mul_exprContext ------------------------------------------------------------------

MiniCParser::Expr1Context* MiniCParser::Mul_exprContext::expr1() {
  return getRuleContext<MiniCParser::Expr1Context>(0);
}

tree::TerminalNode* MiniCParser::Mul_exprContext::MUL() {
  return getToken(MiniCParser::MUL, 0);
}

MiniCParser::Expr0Context* MiniCParser::Mul_exprContext::expr0() {
  return getRuleContext<MiniCParser::Expr0Context>(0);
}

MiniCParser::Mul_exprContext::Mul_exprContext(Expr1Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Mul_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitMul_expr(this);
  else
    return visitor->visitChildren(this);
}

MiniCParser::Expr1Context* MiniCParser::expr1() {
   return expr1(0);
}

MiniCParser::Expr1Context* MiniCParser::expr1(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MiniCParser::Expr1Context *_localctx = _tracker.createInstance<Expr1Context>(_ctx, parentState);
  MiniCParser::Expr1Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, MiniCParser::RuleExpr1, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Expr1_0Context>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(330);
    expr0();
    _ctx->stop = _input->LT(-1);
    setState(343);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(341);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Mul_exprContext>(_tracker.createInstance<Expr1Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr1);
          setState(332);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(333);
          match(MiniCParser::MUL);
          setState(334);
          expr0();
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Div_exprContext>(_tracker.createInstance<Expr1Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr1);
          setState(335);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(336);
          match(MiniCParser::DIV);
          setState(337);
          expr0();
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Mod_exprContext>(_tracker.createInstance<Expr1Context>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr1);
          setState(338);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(339);
          match(MiniCParser::MOD);
          setState(340);
          expr0();
          break;
        }

        } 
      }
      setState(345);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr0Context ------------------------------------------------------------------

MiniCParser::Expr0Context::Expr0Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Expr0Context::getRuleIndex() const {
  return MiniCParser::RuleExpr0;
}

void MiniCParser::Expr0Context::copyFrom(Expr0Context *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Not_exprContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Not_exprContext::NOT() {
  return getToken(MiniCParser::NOT, 0);
}

MiniCParser::ExprContext* MiniCParser::Not_exprContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

MiniCParser::Not_exprContext::Not_exprContext(Expr0Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Not_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitNot_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Inp_intContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Inp_intContext::READ_INT() {
  return getToken(MiniCParser::READ_INT, 0);
}

MiniCParser::Inp_intContext::Inp_intContext(Expr0Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Inp_intContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitInp_int(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Id_exprContext ------------------------------------------------------------------

MiniCParser::IdentifierContext* MiniCParser::Id_exprContext::identifier() {
  return getRuleContext<MiniCParser::IdentifierContext>(0);
}

MiniCParser::Id_exprContext::Id_exprContext(Expr0Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Id_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitId_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lit_exprContext ------------------------------------------------------------------

MiniCParser::LiteralContext* MiniCParser::Lit_exprContext::literal() {
  return getRuleContext<MiniCParser::LiteralContext>(0);
}

MiniCParser::Lit_exprContext::Lit_exprContext(Expr0Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Lit_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitLit_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Call_exprContext ------------------------------------------------------------------

MiniCParser::Method_callContext* MiniCParser::Call_exprContext::method_call() {
  return getRuleContext<MiniCParser::Method_callContext>(0);
}

MiniCParser::Call_exprContext::Call_exprContext(Expr0Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Call_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitCall_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Inp_charContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Inp_charContext::READ_CHAR() {
  return getToken(MiniCParser::READ_CHAR, 0);
}

MiniCParser::Inp_charContext::Inp_charContext(Expr0Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Inp_charContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitInp_char(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Negate_exprContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Negate_exprContext::SUB() {
  return getToken(MiniCParser::SUB, 0);
}

MiniCParser::ExprContext* MiniCParser::Negate_exprContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

MiniCParser::Negate_exprContext::Negate_exprContext(Expr0Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Negate_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitNegate_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Inp_boolContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Inp_boolContext::READ_BOOL() {
  return getToken(MiniCParser::READ_BOOL, 0);
}

MiniCParser::Inp_boolContext::Inp_boolContext(Expr0Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Inp_boolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitInp_bool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Bracket_exprContext ------------------------------------------------------------------

MiniCParser::ExprContext* MiniCParser::Bracket_exprContext::expr() {
  return getRuleContext<MiniCParser::ExprContext>(0);
}

MiniCParser::Bracket_exprContext::Bracket_exprContext(Expr0Context *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Bracket_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitBracket_expr(this);
  else
    return visitor->visitChildren(this);
}
MiniCParser::Expr0Context* MiniCParser::expr0() {
  Expr0Context *_localctx = _tracker.createInstance<Expr0Context>(_ctx, getState());
  enterRule(_localctx, 36, MiniCParser::RuleExpr0);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Expr0Context *>(_tracker.createInstance<MiniCParser::Id_exprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(346);
      identifier();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Expr0Context *>(_tracker.createInstance<MiniCParser::Lit_exprContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(347);
      literal();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Expr0Context *>(_tracker.createInstance<MiniCParser::Call_exprContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(348);
      method_call();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<Expr0Context *>(_tracker.createInstance<MiniCParser::Not_exprContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(349);
      match(MiniCParser::NOT);
      setState(350);
      expr();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<Expr0Context *>(_tracker.createInstance<MiniCParser::Negate_exprContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(351);
      match(MiniCParser::SUB);
      setState(352);
      expr();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<Expr0Context *>(_tracker.createInstance<MiniCParser::Bracket_exprContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(353);
      match(MiniCParser::T__2);
      setState(354);
      expr();
      setState(355);
      match(MiniCParser::T__3);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<Expr0Context *>(_tracker.createInstance<MiniCParser::Inp_intContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(357);
      match(MiniCParser::READ_INT);
      setState(358);
      match(MiniCParser::T__2);
      setState(359);
      match(MiniCParser::T__3);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<Expr0Context *>(_tracker.createInstance<MiniCParser::Inp_charContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(360);
      match(MiniCParser::READ_CHAR);
      setState(361);
      match(MiniCParser::T__2);
      setState(362);
      match(MiniCParser::T__3);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<Expr0Context *>(_tracker.createInstance<MiniCParser::Inp_boolContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(363);
      match(MiniCParser::READ_BOOL);
      setState(364);
      match(MiniCParser::T__2);
      setState(365);
      match(MiniCParser::T__3);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

MiniCParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::IdentifierContext::getRuleIndex() const {
  return MiniCParser::RuleIdentifier;
}

void MiniCParser::IdentifierContext::copyFrom(IdentifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::VarContext::ID() {
  return getToken(MiniCParser::ID, 0);
}

MiniCParser::VarContext::VarContext(IdentifierContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Var_arrayContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Var_arrayContext::ID() {
  return getToken(MiniCParser::ID, 0);
}

std::vector<MiniCParser::ExprContext *> MiniCParser::Var_arrayContext::expr() {
  return getRuleContexts<MiniCParser::ExprContext>();
}

MiniCParser::ExprContext* MiniCParser::Var_arrayContext::expr(size_t i) {
  return getRuleContext<MiniCParser::ExprContext>(i);
}

MiniCParser::Var_arrayContext::Var_arrayContext(IdentifierContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Var_arrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitVar_array(this);
  else
    return visitor->visitChildren(this);
}
MiniCParser::IdentifierContext* MiniCParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 38, MiniCParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(379);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<IdentifierContext *>(_tracker.createInstance<MiniCParser::VarContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(368);
      match(MiniCParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<IdentifierContext *>(_tracker.createInstance<MiniCParser::Var_arrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(369);
      match(MiniCParser::ID);
      setState(376);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(370);
          match(MiniCParser::T__6);
          setState(371);
          expr();
          setState(372);
          match(MiniCParser::T__7); 
        }
        setState(378);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

MiniCParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::LiteralContext::getRuleIndex() const {
  return MiniCParser::RuleLiteral;
}

void MiniCParser::LiteralContext::copyFrom(LiteralContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Int_litContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Int_litContext::INT_LIT() {
  return getToken(MiniCParser::INT_LIT, 0);
}

MiniCParser::Int_litContext::Int_litContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Int_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitInt_lit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Float_litContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Float_litContext::FLOAT_LIT() {
  return getToken(MiniCParser::FLOAT_LIT, 0);
}

MiniCParser::Float_litContext::Float_litContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Float_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitFloat_lit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Char_litContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Char_litContext::CHAR_LIT() {
  return getToken(MiniCParser::CHAR_LIT, 0);
}

MiniCParser::Char_litContext::Char_litContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Char_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitChar_lit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Str_litContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::Str_litContext::STRING_LIT() {
  return getToken(MiniCParser::STRING_LIT, 0);
}

MiniCParser::Str_litContext::Str_litContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Str_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitStr_lit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Bool_literalContext ------------------------------------------------------------------

MiniCParser::Bool_litContext* MiniCParser::Bool_literalContext::bool_lit() {
  return getRuleContext<MiniCParser::Bool_litContext>(0);
}

MiniCParser::Bool_literalContext::Bool_literalContext(LiteralContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::Bool_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitBool_literal(this);
  else
    return visitor->visitChildren(this);
}
MiniCParser::LiteralContext* MiniCParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 40, MiniCParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::INT_LIT: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MiniCParser::Int_litContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(381);
        match(MiniCParser::INT_LIT);
        break;
      }

      case MiniCParser::FLOAT_LIT: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MiniCParser::Float_litContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(382);
        match(MiniCParser::FLOAT_LIT);
        break;
      }

      case MiniCParser::CHAR_LIT: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MiniCParser::Char_litContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(383);
        match(MiniCParser::CHAR_LIT);
        break;
      }

      case MiniCParser::STRING_LIT: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MiniCParser::Str_litContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(384);
        match(MiniCParser::STRING_LIT);
        break;
      }

      case MiniCParser::FALSE:
      case MiniCParser::TRUE: {
        _localctx = dynamic_cast<LiteralContext *>(_tracker.createInstance<MiniCParser::Bool_literalContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(385);
        bool_lit();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_litContext ------------------------------------------------------------------

MiniCParser::Bool_litContext::Bool_litContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MiniCParser::Bool_litContext::getRuleIndex() const {
  return MiniCParser::RuleBool_lit;
}

void MiniCParser::Bool_litContext::copyFrom(Bool_litContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- True_litContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::True_litContext::TRUE() {
  return getToken(MiniCParser::TRUE, 0);
}

MiniCParser::True_litContext::True_litContext(Bool_litContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::True_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitTrue_lit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- False_litContext ------------------------------------------------------------------

tree::TerminalNode* MiniCParser::False_litContext::FALSE() {
  return getToken(MiniCParser::FALSE, 0);
}

MiniCParser::False_litContext::False_litContext(Bool_litContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MiniCParser::False_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MiniCVisitor*>(visitor))
    return parserVisitor->visitFalse_lit(this);
  else
    return visitor->visitChildren(this);
}
MiniCParser::Bool_litContext* MiniCParser::bool_lit() {
  Bool_litContext *_localctx = _tracker.createInstance<Bool_litContext>(_ctx, getState());
  enterRule(_localctx, 42, MiniCParser::RuleBool_lit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(390);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MiniCParser::TRUE: {
        _localctx = dynamic_cast<Bool_litContext *>(_tracker.createInstance<MiniCParser::True_litContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(388);
        match(MiniCParser::TRUE);
        break;
      }

      case MiniCParser::FALSE: {
        _localctx = dynamic_cast<Bool_litContext *>(_tracker.createInstance<MiniCParser::False_litContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(389);
        match(MiniCParser::FALSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MiniCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return expr8Sempred(dynamic_cast<Expr8Context *>(context), predicateIndex);
    case 11: return expr7Sempred(dynamic_cast<Expr7Context *>(context), predicateIndex);
    case 12: return expr6Sempred(dynamic_cast<Expr6Context *>(context), predicateIndex);
    case 13: return expr5Sempred(dynamic_cast<Expr5Context *>(context), predicateIndex);
    case 14: return expr4Sempred(dynamic_cast<Expr4Context *>(context), predicateIndex);
    case 15: return expr3Sempred(dynamic_cast<Expr3Context *>(context), predicateIndex);
    case 16: return expr2Sempred(dynamic_cast<Expr2Context *>(context), predicateIndex);
    case 17: return expr1Sempred(dynamic_cast<Expr1Context *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MiniCParser::expr8Sempred(Expr8Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MiniCParser::expr7Sempred(Expr7Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MiniCParser::expr6Sempred(Expr6Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MiniCParser::expr5Sempred(Expr5Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 3);
    case 4: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MiniCParser::expr4Sempred(Expr4Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MiniCParser::expr3Sempred(Expr3Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 3);
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MiniCParser::expr2Sempred(Expr2Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 3);
    case 10: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool MiniCParser::expr1Sempred(Expr1Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 4);
    case 12: return precpred(_ctx, 3);
    case 13: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MiniCParser::_decisionToDFA;
atn::PredictionContextCache MiniCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MiniCParser::_atn;
std::vector<uint16_t> MiniCParser::_serializedATN;

std::vector<std::string> MiniCParser::_ruleNames = {
  "program", "decl", "var_decl", "method_decl", "block", "type", "statement", 
  "assignment", "method_call", "expr", "expr8", "expr7", "expr6", "expr5", 
  "expr4", "expr3", "expr2", "expr1", "expr0", "identifier", "literal", 
  "bool_lit"
};

std::vector<std::string> MiniCParser::_literalNames = {
  "", "','", "';'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'false'", 
  "'true'", "'!'", "'~'", "'void'", "'float'", "'int'", "'FILE'", "'string'", 
  "'char'", "'uint'", "'bool'", "'?'", "':'", "'for'", "'while'", "'if'", 
  "'else'", "'break'", "'continue'", "'return'", "'+'", "'-'", "'*'", "'/'", 
  "'%'", "'<'", "'>'", "'<='", "'>='", "'&&'", "'||'", "'=='", "'!='", "'='", 
  "'print'", "'println'", "'read_int'", "'read_char'", "'read_bool'"
};

std::vector<std::string> MiniCParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "FALSE", "TRUE", "NOT", "NEGATE", 
  "VOID", "FLOAT", "INT", "FILE", "STRING", "CHAR", "UINT", "BOOL", "THEN", 
  "OTHERWISE", "FOR", "WHILE", "IF", "ELSE", "BREAK", "CONTINUE", "RETURN", 
  "ADD", "SUB", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", "AND", "OR", 
  "EQ", "NE", "ASSIGN", "PRINT", "PRINTLN", "READ_INT", "READ_CHAR", "READ_BOOL", 
  "INT_LIT", "FLOAT_LIT", "CHAR_LIT", "ID", "STRING_LIT", "WS"
};

dfa::Vocabulary MiniCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MiniCParser::_tokenNames;

MiniCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x38, 0x18b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x6, 
    0x2, 0x30, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x31, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x38, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x3e, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x41, 0xb, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x4e, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x51, 0xb, 0x5, 0x5, 0x5, 0x53, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x61, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x64, 0xb, 0x5, 0x5, 0x5, 0x66, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x6a, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x6e, 0xa, 0x6, 
    0xc, 0x6, 0xe, 0x6, 0x71, 0xb, 0x6, 0x3, 0x6, 0x7, 0x6, 0x74, 0xa, 0x6, 
    0xc, 0x6, 0xe, 0x6, 0x77, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x82, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x87, 0xa, 0x8, 0xc, 
    0x8, 0xe, 0x8, 0x8a, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x98, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x7, 0x8, 0x9f, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xa2, 0xb, 
    0x8, 0x5, 0x8, 0xa4, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x7, 0x8, 0xaa, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xad, 0xb, 0x8, 0x5, 0x8, 
    0xaf, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xb5, 
    0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xb8, 0xb, 0x8, 0x5, 0x8, 0xba, 0xa, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0xcb, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xda, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0xe5, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xe8, 0xb, 0xa, 0x5, 0xa, 
    0xea, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x7, 0xc, 0xf9, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xfc, 0xb, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x104, 
    0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x107, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x10f, 0xa, 0xe, 0xc, 0xe, 
    0xe, 0xe, 0x112, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x11d, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0x120, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 
    0x10, 0x12b, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x12e, 0xb, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x139, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 
    0x13c, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x147, 0xa, 0x12, 
    0xc, 0x12, 0xe, 0x12, 0x14a, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x158, 0xa, 0x13, 0xc, 0x13, 
    0xe, 0x13, 0x15b, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x171, 0xa, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x179, 
    0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x17c, 0xb, 0x15, 0x5, 0x15, 0x17e, 
    0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 
    0x16, 0x185, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x189, 0xa, 
    0x17, 0x3, 0x17, 0x2, 0xa, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x18, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2, 
    0x2, 0x2, 0x1b6, 0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x6b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x81, 0x3, 0x2, 0x2, 0x2, 0xe, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x12, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xed, 0x3, 0x2, 0x2, 0x2, 0x16, 0xef, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x108, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x113, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x22, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x14b, 0x3, 0x2, 0x2, 0x2, 0x26, 0x170, 0x3, 0x2, 0x2, 0x2, 0x28, 0x17d, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x184, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x188, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x4, 0x3, 0x2, 0x2f, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x33, 0x34, 0x7, 0x2, 0x2, 0x3, 0x34, 0x3, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x38, 0x5, 0x6, 0x4, 0x2, 0x36, 0x38, 0x5, 0x8, 0x5, 0x2, 0x37, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x3a, 0x5, 0xc, 0x7, 0x2, 0x3a, 0x3f, 0x5, 0x28, 
    0x15, 0x2, 0x3b, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x3c, 0x3e, 0x5, 0x28, 0x15, 
    0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 
    0x7, 0x4, 0x2, 0x2, 0x43, 0x7, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x5, 
    0xc, 0x7, 0x2, 0x45, 0x46, 0x7, 0x36, 0x2, 0x2, 0x46, 0x52, 0x7, 0x5, 
    0x2, 0x2, 0x47, 0x48, 0x5, 0xc, 0x7, 0x2, 0x48, 0x4f, 0x5, 0x28, 0x15, 
    0x2, 0x49, 0x4a, 0x7, 0x3, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0xc, 0x7, 0x2, 
    0x4b, 0x4c, 0x5, 0x28, 0x15, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x55, 0x7, 0x6, 0x2, 0x2, 0x55, 0x56, 0x5, 0xa, 0x6, 0x2, 
    0x56, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 0xf, 0x2, 0x2, 0x58, 
    0x59, 0x7, 0x36, 0x2, 0x2, 0x59, 0x65, 0x7, 0x5, 0x2, 0x2, 0x5a, 0x5b, 
    0x5, 0xc, 0x7, 0x2, 0x5b, 0x62, 0x5, 0x28, 0x15, 0x2, 0x5c, 0x5d, 0x7, 
    0x3, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0xc, 0x7, 0x2, 0x5e, 0x5f, 0x5, 0x28, 
    0x15, 0x2, 0x5f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5c, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x64, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x65, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 
    0x6, 0x2, 0x2, 0x68, 0x6a, 0x5, 0xa, 0x6, 0x2, 0x69, 0x44, 0x3, 0x2, 
    0x2, 0x2, 0x69, 0x57, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x6b, 0x6f, 0x7, 0x7, 0x2, 0x2, 0x6c, 0x6e, 0x5, 0x6, 0x4, 0x2, 
    0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x71, 0x3, 0x2, 0x2, 0x2, 0x6f, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x75, 
    0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x72, 0x74, 0x5, 
    0xe, 0x8, 0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x78, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x79, 0x7, 0x8, 0x2, 0x2, 0x79, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x82, 0x7, 0x11, 0x2, 0x2, 0x7b, 0x82, 0x7, 0x15, 0x2, 0x2, 0x7c, 0x82, 
    0x7, 0x16, 0x2, 0x2, 0x7d, 0x82, 0x7, 0x14, 0x2, 0x2, 0x7e, 0x82, 0x7, 
    0x12, 0x2, 0x2, 0x7f, 0x82, 0x7, 0x13, 0x2, 0x2, 0x80, 0x82, 0x7, 0x10, 
    0x2, 0x2, 0x81, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 
    0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0xd, 0x3, 0x2, 0x2, 0x2, 0x83, 0x88, 
    0x5, 0x10, 0x9, 0x2, 0x84, 0x85, 0x7, 0x3, 0x2, 0x2, 0x85, 0x87, 0x5, 
    0x10, 0x9, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x87, 0x8a, 0x3, 0x2, 
    0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 
    0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 
    0x8b, 0x8c, 0x7, 0x4, 0x2, 0x2, 0x8c, 0xda, 0x3, 0x2, 0x2, 0x2, 0x8d, 
    0x8e, 0x5, 0x12, 0xa, 0x2, 0x8e, 0x8f, 0x7, 0x4, 0x2, 0x2, 0x8f, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x7, 0x1b, 0x2, 0x2, 0x91, 0x92, 0x7, 
    0x5, 0x2, 0x2, 0x92, 0x93, 0x5, 0x14, 0xb, 0x2, 0x93, 0x94, 0x7, 0x6, 
    0x2, 0x2, 0x94, 0x97, 0x5, 0xa, 0x6, 0x2, 0x95, 0x96, 0x7, 0x1c, 0x2, 
    0x2, 0x96, 0x98, 0x5, 0xa, 0x6, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0xda, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x7, 0x19, 0x2, 0x2, 0x9a, 0xa3, 0x7, 0x5, 0x2, 0x2, 0x9b, 0xa0, 
    0x5, 0x10, 0x9, 0x2, 0x9c, 0x9d, 0x7, 0x3, 0x2, 0x2, 0x9d, 0x9f, 0x5, 
    0x10, 0x9, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 
    0xa3, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xae, 0x7, 0x4, 0x2, 0x2, 0xa6, 0xab, 
    0x5, 0x14, 0xb, 0x2, 0xa7, 0xa8, 0x7, 0x3, 0x2, 0x2, 0xa8, 0xaa, 0x5, 
    0x14, 0xb, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb9, 0x7, 0x4, 0x2, 0x2, 0xb1, 0xb6, 
    0x5, 0x10, 0x9, 0x2, 0xb2, 0xb3, 0x7, 0x3, 0x2, 0x2, 0xb3, 0xb5, 0x5, 
    0x10, 0x9, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb8, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x6, 0x2, 0x2, 0xbc, 0xda, 
    0x5, 0xa, 0x6, 0x2, 0xbd, 0xbe, 0x7, 0x1a, 0x2, 0x2, 0xbe, 0xbf, 0x7, 
    0x5, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x14, 0xb, 0x2, 0xc0, 0xc1, 0x7, 0x6, 
    0x2, 0x2, 0xc1, 0xc2, 0x5, 0xa, 0x6, 0x2, 0xc2, 0xda, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc4, 0x7, 0x1d, 0x2, 0x2, 0xc4, 0xda, 0x7, 0x4, 0x2, 0x2, 
    0xc5, 0xc6, 0x7, 0x1e, 0x2, 0x2, 0xc6, 0xda, 0x7, 0x4, 0x2, 0x2, 0xc7, 
    0xda, 0x5, 0xa, 0x6, 0x2, 0xc8, 0xca, 0x7, 0x1f, 0x2, 0x2, 0xc9, 0xcb, 
    0x5, 0x14, 0xb, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 
    0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xda, 0x7, 0x4, 
    0x2, 0x2, 0xcd, 0xce, 0x7, 0x2e, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x5, 0x2, 
    0x2, 0xcf, 0xd0, 0x5, 0x14, 0xb, 0x2, 0xd0, 0xd1, 0x7, 0x6, 0x2, 0x2, 
    0xd1, 0xd2, 0x7, 0x4, 0x2, 0x2, 0xd2, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd3, 
    0xd4, 0x7, 0x2f, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x5, 0x2, 0x2, 0xd5, 0xd6, 
    0x5, 0x14, 0xb, 0x2, 0xd6, 0xd7, 0x7, 0x6, 0x2, 0x2, 0xd7, 0xd8, 0x7, 
    0x4, 0x2, 0x2, 0xd8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xd9, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0x99, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0xd9, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xd9, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xda, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0xdb, 0xdc, 0x5, 0x28, 0x15, 0x2, 0xdc, 0xdd, 0x7, 0x2d, 
    0x2, 0x2, 0xdd, 0xde, 0x5, 0x14, 0xb, 0x2, 0xde, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xe0, 0x7, 0x36, 0x2, 0x2, 0xe0, 0xe9, 0x7, 0x5, 0x2, 0x2, 
    0xe1, 0xe6, 0x5, 0x14, 0xb, 0x2, 0xe2, 0xe3, 0x7, 0x3, 0x2, 0x2, 0xe3, 
    0xe5, 0x5, 0x14, 0xb, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe8, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x6, 0x2, 0x2, 
    0xec, 0x13, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x5, 0x16, 0xc, 0x2, 0xee, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x8, 0xc, 0x1, 0x2, 0xf0, 0xf1, 
    0x5, 0x18, 0xd, 0x2, 0xf1, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0xc, 
    0x4, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x17, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x16, 
    0xc, 0x2, 0xf5, 0xf6, 0x7, 0x18, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x16, 0xc, 
    0x5, 0xf7, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xf9, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0x17, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x8, 0xd, 0x1, 0x2, 0xfe, 0xff, 0x5, 
    0x1a, 0xe, 0x2, 0xff, 0x105, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0xc, 
    0x4, 0x2, 0x2, 0x101, 0x102, 0x7, 0x2a, 0x2, 0x2, 0x102, 0x104, 0x5, 
    0x1a, 0xe, 0x2, 0x103, 0x100, 0x3, 0x2, 0x2, 0x2, 0x104, 0x107, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x103, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x19, 0x3, 0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x109, 0x8, 0xe, 0x1, 0x2, 0x109, 0x10a, 0x5, 0x1c, 
    0xf, 0x2, 0x10a, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0xc, 0x4, 
    0x2, 0x2, 0x10c, 0x10d, 0x7, 0x29, 0x2, 0x2, 0x10d, 0x10f, 0x5, 0x1c, 
    0xf, 0x2, 0x10e, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0x114, 0x8, 0xf, 0x1, 0x2, 0x114, 0x115, 0x5, 0x1e, 0x10, 
    0x2, 0x115, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0xc, 0x5, 0x2, 
    0x2, 0x117, 0x118, 0x7, 0x2b, 0x2, 0x2, 0x118, 0x11d, 0x5, 0x1e, 0x10, 
    0x2, 0x119, 0x11a, 0xc, 0x4, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x2c, 0x2, 
    0x2, 0x11b, 0x11d, 0x5, 0x1e, 0x10, 0x2, 0x11c, 0x116, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 
    0x121, 0x122, 0x8, 0x10, 0x1, 0x2, 0x122, 0x123, 0x5, 0x20, 0x11, 0x2, 
    0x123, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0xc, 0x5, 0x2, 0x2, 
    0x125, 0x126, 0x7, 0x26, 0x2, 0x2, 0x126, 0x12b, 0x5, 0x20, 0x11, 0x2, 
    0x127, 0x128, 0xc, 0x4, 0x2, 0x2, 0x128, 0x129, 0x7, 0x28, 0x2, 0x2, 
    0x129, 0x12b, 0x5, 0x20, 0x11, 0x2, 0x12a, 0x124, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12f, 
    0x130, 0x8, 0x11, 0x1, 0x2, 0x130, 0x131, 0x5, 0x22, 0x12, 0x2, 0x131, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0xc, 0x5, 0x2, 0x2, 0x133, 
    0x134, 0x7, 0x25, 0x2, 0x2, 0x134, 0x139, 0x5, 0x22, 0x12, 0x2, 0x135, 
    0x136, 0xc, 0x4, 0x2, 0x2, 0x136, 0x137, 0x7, 0x27, 0x2, 0x2, 0x137, 
    0x139, 0x5, 0x22, 0x12, 0x2, 0x138, 0x132, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x135, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13a, 
    0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 
    0x8, 0x12, 0x1, 0x2, 0x13e, 0x13f, 0x5, 0x24, 0x13, 0x2, 0x13f, 0x148, 
    0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0xc, 0x5, 0x2, 0x2, 0x141, 0x142, 
    0x7, 0x20, 0x2, 0x2, 0x142, 0x147, 0x5, 0x24, 0x13, 0x2, 0x143, 0x144, 
    0xc, 0x4, 0x2, 0x2, 0x144, 0x145, 0x7, 0x21, 0x2, 0x2, 0x145, 0x147, 
    0x5, 0x24, 0x13, 0x2, 0x146, 0x140, 0x3, 0x2, 0x2, 0x2, 0x146, 0x143, 
    0x3, 0x2, 0x2, 0x2, 0x147, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x148, 0x146, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 0x149, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x8, 
    0x13, 0x1, 0x2, 0x14c, 0x14d, 0x5, 0x26, 0x14, 0x2, 0x14d, 0x159, 0x3, 
    0x2, 0x2, 0x2, 0x14e, 0x14f, 0xc, 0x6, 0x2, 0x2, 0x14f, 0x150, 0x7, 
    0x22, 0x2, 0x2, 0x150, 0x158, 0x5, 0x26, 0x14, 0x2, 0x151, 0x152, 0xc, 
    0x5, 0x2, 0x2, 0x152, 0x153, 0x7, 0x23, 0x2, 0x2, 0x153, 0x158, 0x5, 
    0x26, 0x14, 0x2, 0x154, 0x155, 0xc, 0x4, 0x2, 0x2, 0x155, 0x156, 0x7, 
    0x24, 0x2, 0x2, 0x156, 0x158, 0x5, 0x26, 0x14, 0x2, 0x157, 0x14e, 0x3, 
    0x2, 0x2, 0x2, 0x157, 0x151, 0x3, 0x2, 0x2, 0x2, 0x157, 0x154, 0x3, 
    0x2, 0x2, 0x2, 0x158, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x157, 0x3, 
    0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x171, 0x5, 0x28, 
    0x15, 0x2, 0x15d, 0x171, 0x5, 0x2a, 0x16, 0x2, 0x15e, 0x171, 0x5, 0x12, 
    0xa, 0x2, 0x15f, 0x160, 0x7, 0xd, 0x2, 0x2, 0x160, 0x171, 0x5, 0x14, 
    0xb, 0x2, 0x161, 0x162, 0x7, 0x21, 0x2, 0x2, 0x162, 0x171, 0x5, 0x14, 
    0xb, 0x2, 0x163, 0x164, 0x7, 0x5, 0x2, 0x2, 0x164, 0x165, 0x5, 0x14, 
    0xb, 0x2, 0x165, 0x166, 0x7, 0x6, 0x2, 0x2, 0x166, 0x171, 0x3, 0x2, 
    0x2, 0x2, 0x167, 0x168, 0x7, 0x30, 0x2, 0x2, 0x168, 0x169, 0x7, 0x5, 
    0x2, 0x2, 0x169, 0x171, 0x7, 0x6, 0x2, 0x2, 0x16a, 0x16b, 0x7, 0x31, 
    0x2, 0x2, 0x16b, 0x16c, 0x7, 0x5, 0x2, 0x2, 0x16c, 0x171, 0x7, 0x6, 
    0x2, 0x2, 0x16d, 0x16e, 0x7, 0x32, 0x2, 0x2, 0x16e, 0x16f, 0x7, 0x5, 
    0x2, 0x2, 0x16f, 0x171, 0x7, 0x6, 0x2, 0x2, 0x170, 0x15c, 0x3, 0x2, 
    0x2, 0x2, 0x170, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x170, 0x15e, 0x3, 0x2, 
    0x2, 0x2, 0x170, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x170, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x170, 0x163, 0x3, 0x2, 0x2, 0x2, 0x170, 0x167, 0x3, 0x2, 
    0x2, 0x2, 0x170, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16d, 0x3, 0x2, 
    0x2, 0x2, 0x171, 0x27, 0x3, 0x2, 0x2, 0x2, 0x172, 0x17e, 0x7, 0x36, 
    0x2, 0x2, 0x173, 0x17a, 0x7, 0x36, 0x2, 0x2, 0x174, 0x175, 0x7, 0x9, 
    0x2, 0x2, 0x175, 0x176, 0x5, 0x14, 0xb, 0x2, 0x176, 0x177, 0x7, 0xa, 
    0x2, 0x2, 0x177, 0x179, 0x3, 0x2, 0x2, 0x2, 0x178, 0x174, 0x3, 0x2, 
    0x2, 0x2, 0x179, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 0x3, 0x2, 
    0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17e, 0x3, 0x2, 
    0x2, 0x2, 0x17c, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x172, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x173, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x17f, 0x185, 0x7, 0x33, 0x2, 0x2, 0x180, 0x185, 0x7, 0x34, 0x2, 
    0x2, 0x181, 0x185, 0x7, 0x35, 0x2, 0x2, 0x182, 0x185, 0x7, 0x37, 0x2, 
    0x2, 0x183, 0x185, 0x5, 0x2c, 0x17, 0x2, 0x184, 0x17f, 0x3, 0x2, 0x2, 
    0x2, 0x184, 0x180, 0x3, 0x2, 0x2, 0x2, 0x184, 0x181, 0x3, 0x2, 0x2, 
    0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 0x184, 0x183, 0x3, 0x2, 0x2, 
    0x2, 0x185, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x186, 0x189, 0x7, 0xc, 0x2, 0x2, 
    0x187, 0x189, 0x7, 0xb, 0x2, 0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 
    0x188, 0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x31, 0x37, 0x3f, 0x4f, 0x52, 0x62, 0x65, 0x69, 0x6f, 0x75, 0x81, 0x88, 
    0x97, 0xa0, 0xa3, 0xab, 0xae, 0xb6, 0xb9, 0xca, 0xd9, 0xe6, 0xe9, 0xfa, 
    0x105, 0x110, 0x11c, 0x11e, 0x12a, 0x12c, 0x138, 0x13a, 0x146, 0x148, 
    0x157, 0x159, 0x170, 0x17a, 0x17d, 0x184, 0x188, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MiniCParser::Initializer MiniCParser::_init;
