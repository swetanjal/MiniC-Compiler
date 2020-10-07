
// Generated from MiniC.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  MiniCLexer : public antlr4::Lexer {
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

  MiniCLexer(antlr4::CharStream *input);
  ~MiniCLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

