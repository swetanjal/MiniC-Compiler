- Copy paste the folders into llvm-project/llvm/lib/Transforms
- Modify CMakeLists.txt in llvm-project/llvm/lib/Transforms
- Add the following line: add_subdirectory(ExtendedBB)
- Add the following line: add_subdirectory(SuperLocalValueNo)
- Build llvm-project
- Run the following command to print Extended Basic Blocks in a program:
~/workspace/Repositories/llvm-project/build/bin/opt -load ~/workspace/Repositories/llvm-project/build/lib/LLVMExtendedBB.so -ExtendedBB < ~/workspace/Repositories/MiniC-Compiler/a.bc > /dev/null