# MiniC-Compiler

## Language Manual:
- Refer to 20171077_MiniC_Manual.pdf.

## Instructions to compile and run the code:
- ./compile_and_run.sh \<path to source code\>
- Eg: ./compile_and_run.sh testcases/1.mc

## Implementation Details:
- The Macro and Micro Syntax of the language is specified in MiniC.g4 file.
- ANTLR-4 is used as the parser generator.
- The code generation is done in LLVM IR.
- LLVM Toolchain handles the machine code generation and hence forms the backend of the compiler.
- More details reagrding the implementation to come!
