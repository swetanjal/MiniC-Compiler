#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "bits/stdc++.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/CFG.h"

using namespace llvm;
using namespace std;
namespace {
struct ExtendedBB : public FunctionPass {
  static char ID;
  ExtendedBB() : FunctionPass(ID) {}
  map < string, vector <string> > Successors;
  map < string, vector <string> > Predecessors;
  map < string, int > visited;
  queue <string> Q;
  void dfs(string node, int color)
  {
      if(visited.find(node) != visited.end())
        return;
      if(Predecessors[node].size() > 1){
          return;
      }
      visited[node] = color;
      errs() << node << ' ';
      int l = Successors[node].size();
      for(int i = 0; i < l; ++i){
          dfs(Successors[node][i], color);
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
        if(Predecessors[name].size() > 1 || Predecessors[name].size() == 0)
            Q.push(name);
    }
    map < string, vector <string> > :: iterator it;
    int color = 0;
    while(Q.empty() == false)
    {
        string node = Q.front();
        Q.pop();
        visited[node] = color;
        errs() << node << ' ';
        int l = Successors[node].size();
        for(int i = 0; i < l; ++i){
            dfs(Successors[node][i], color);
        }
        color++;
        errs() << '\n';
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