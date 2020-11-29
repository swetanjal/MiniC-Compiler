- Copy paste the folders into llvm-project/llvm/lib/Transforms
- Modify CMakeLists.txt in llvm-project/llvm/lib/Transforms
- Add the following line: add_subdirectory(ExtendedBB)
- Build llvm-project from build dir:
	cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ../llvm/
	cmake --build .
- Remember to promote memory variables to registers: opt -mem2reg -S llvmir.bc -o mem.bc
- Run the following command:
~/workspace/Repositories/llvm-project/build/bin/opt -load ~/workspace/Repositories/llvm-project/build/lib/LLVMExtendedBB.so -ExtendedBB < ~/workspace/Repositories/MiniC-Compiler/mem.bc > /dev/null
