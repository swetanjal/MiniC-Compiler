#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "bits/stdc++.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/InstrTypes.h"

using namespace llvm;
using namespace std;
namespace {
struct ExtendedBB : public FunctionPass {
  static char ID;
  ExtendedBB() : FunctionPass(ID) {}
  map < string, vector <string> > Successors;
  map < string, vector <string> > Predecessors;
  map < string, BasicBlock* > BasicBlocks;
  map < string, int > visited;
  queue <string> Q;
  void dfs(string node, int color, map < string, int > var_vn, map < int, vector <string> > vn_var,
  map < pair < string, pair < int, int > > , int > store_expr,int curr_vn)
  {
      if(visited.find(node) != visited.end())
        return;
      if(Predecessors[node].size() > 1){
          return;
      }
      visited[node] = color;
      errs() << node << ":" << '\n';


        // Do value numbering for current Basic Block
        
        BasicBlock* curr = BasicBlocks[node];
        for(Instruction &I: *curr){
            std::string instruction_str;
            llvm::raw_string_ostream(instruction_str) << I;
            errs() << I;
            if (auto* op = dyn_cast<BinaryOperator>(&I)) {
                string opcode = I.getOpcodeName();
                Value* lhs = op->getOperand(0);
                Value* rhs = op->getOperand(1);
                string var1 = string(lhs->getName());
                string var2 = string(rhs->getName());
                string dest = string((dyn_cast<Value>(&I))->getName());
                if (ConstantInt* CI = dyn_cast<ConstantInt>(lhs)) {
                    if (CI->getBitWidth() <= 32) {
                        var1 = to_string(CI->getSExtValue());
                    }
                }
                if (ConstantInt* CI = dyn_cast<ConstantInt>(rhs)) {
                    if (CI->getBitWidth() <= 32) {
                        var2 = to_string(CI->getSExtValue());
                    }
                }
                
                if(opcode == "add" || opcode == "sub" || opcode == "mul" || opcode == "sdiv" || opcode == "srem"){
                    if(var_vn.find(var1) == var_vn.end()){
                        var_vn[var1] = curr_vn++;
                    }
                    if(var_vn.find(var2) == var_vn.end()){
                        var_vn[var2] = curr_vn++;
                    }
                    if(var_vn.find(dest) != var_vn.end()){
                        // Delete entries already there.
                        int idx = -1;
                        for(int i = 0; i < (int)(vn_var[var_vn[dest]].size()); ++i){
                            if(vn_var[var_vn[dest]][i] == dest)
                                idx = i;
                        }
                        vn_var[var_vn[dest]].erase(vn_var[var_vn[dest]].begin() + idx);
                    }
                    int found = 0;
                    if(store_expr.find({opcode, {var_vn[var1], var_vn[var2]}}) != store_expr.end()){
                        found = 1;
                        var_vn[dest] = store_expr[{opcode, {var_vn[var1], var_vn[var2]}}];
                        vn_var[var_vn[dest]].push_back(dest);
                    }
                    else{
                        var_vn[dest] = curr_vn++;
                        if(vn_var.find(var_vn[dest]) != vn_var.end()){
                            vector <string> tmp;
                            vn_var[var_vn[dest]] = tmp;
                        }
                        vn_var[var_vn[dest]].push_back(dest);
                        store_expr[{opcode, {var_vn[var1], var_vn[var2]}}] = var_vn[dest];
                    }
                    //errs() << var1 << " " << var2 << " " << dest << " " << opcode << '\n';
                    for(int spaces = 0; spaces < (int)(60 - instruction_str.size()); ++spaces)
                        errs() << ' ';
                    errs() << "Value Numbering: " << var_vn[dest] << " = " << var_vn[var1] << " " << opcode << " " << var_vn[var2];
                    if(found)
                        errs() << "\tFound redundancy";
                }
            }
            errs() << '\n';
        }
        errs() << '\n';
        /********************************************/

      int l = Successors[node].size();
      for(int i = 0; i < l; ++i){
            dfs(Successors[node][i], color, var_vn, vn_var, store_expr, curr_vn);
      }
  }
  
  virtual bool runOnFunction(Function &F) override {
    errs() << "Printing Extended Basic Block for Function " << F.getName() << ":\n" << '\n';
    for(Function::iterator bb = F.begin(), e = F.end(); bb != e; ++bb)
    {
        BasicBlock* BB = &*bb;
        string name = string(BB->getName());
        vector <string> tmp;
        Successors[name] = tmp;
        Predecessors[name] = tmp;

        for(BasicBlock *Pred: predecessors(BB)){
            Predecessors[name].push_back(string(Pred->getName()));    
        }
        for(BasicBlock *Succ: successors(BB))
            Successors[name].push_back(string(Succ->getName()));
        BasicBlocks[name] = BB;
        if(Predecessors[name].size() > 1 || Predecessors[name].size() == 0)
            Q.push(name);
    }
    map < string, vector <string> > :: iterator it;
    int color = 0;
    while(Q.empty() == false)
    {
        errs() << "Extended Basic Block " << color << ":\n\n";
        map < string, int > var_vn;
        map < int, vector <string> > vn_var;
        map < pair < string, pair < int, int > > , int > store_expr;
        int curr_vn = 1;

        string node = Q.front();
        Q.pop();
        visited[node] = color;

        errs() << node << ":" << '\n';
        // Do value numbering for current Basic Block
        
        BasicBlock* curr = BasicBlocks[node];
        for(Instruction &I: *curr){
            std::string instruction_str;
            llvm::raw_string_ostream(instruction_str) << I;
            errs() << I;
            if (auto* op = dyn_cast<BinaryOperator>(&I)) {
                string opcode = I.getOpcodeName();
                Value* lhs = op->getOperand(0);
                Value* rhs = op->getOperand(1);
                string var1 = string(lhs->getName());
                string var2 = string(rhs->getName());
                string dest = string((dyn_cast<Value>(&I))->getName());
                if (ConstantInt* CI = dyn_cast<ConstantInt>(lhs)) {
                    if (CI->getBitWidth() <= 32) {
                        var1 = to_string(CI->getSExtValue());
                    }
                }
                if (ConstantInt* CI = dyn_cast<ConstantInt>(rhs)) {
                    if (CI->getBitWidth() <= 32) {
                        var2 = to_string(CI->getSExtValue());
                    }
                }
                
                if(opcode == "add" || opcode == "sub" || opcode == "mul" || opcode == "sdiv" || opcode == "srem"){
                    if(var_vn.find(var1) == var_vn.end()){
                        var_vn[var1] = curr_vn++;
                    }
                    if(var_vn.find(var2) == var_vn.end()){
                        var_vn[var2] = curr_vn++;
                    }
                    if(var_vn.find(dest) != var_vn.end()){
                        // Delete entries already there.
                        int idx = -1;
                        for(int i = 0; i < (int)(vn_var[var_vn[dest]].size()); ++i){
                            if(vn_var[var_vn[dest]][i] == dest)
                                idx = i;
                        }
                        vn_var[var_vn[dest]].erase(vn_var[var_vn[dest]].begin() + idx);
                    }
                    int found = 0;
                    if(store_expr.find({opcode, {var_vn[var1], var_vn[var2]}}) != store_expr.end()){
                        var_vn[dest] = store_expr[{opcode, {var_vn[var1], var_vn[var2]}}];
                        vn_var[var_vn[dest]].push_back(dest);
                        found = 1;
                    }
                    else{
                        
                        var_vn[dest] = curr_vn++;
                        if(vn_var.find(var_vn[dest]) != vn_var.end()){
                            vector <string> tmp;
                            vn_var[var_vn[dest]] = tmp;
                        }
                        vn_var[var_vn[dest]].push_back(dest);
                        store_expr[{opcode, {var_vn[var1], var_vn[var2]}}] = var_vn[dest];
                    }
                    for(int spaces = 0; spaces < (int)(60 - instruction_str.size()); ++spaces)
                        errs() << ' ';
                    errs() << "Value Numbering: " << var_vn[dest] << " = " << var_vn[var1] << " " << opcode << " " << var_vn[var2];
                    if(found)
                        errs() << "\tFound redundancy";
                }
            }
            errs() << '\n';
        }
        errs() << '\n';
        /********************************************/
        //
        int l = Successors[node].size();
        for(int i = 0; i < l; ++i){
            dfs(Successors[node][i], color, var_vn, vn_var, store_expr, curr_vn);
        }
        color++;
        errs() << '\n' << '\n';
    }
    errs() << '\n';
    return false;
  }
};
}

char ExtendedBB::ID = 0;
static RegisterPass<ExtendedBB> X("ExtendedBB", "Print Extended Basic Blocks",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);