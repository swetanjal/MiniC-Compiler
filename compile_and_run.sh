./MiniC $1
clang -emit-llvm -c -g stdlib.c
llvm-link llvmir.bc stdlib.bc -o a.bc
lli a.bc

#echo "Finished compiling and running code."