# MiniC-Compiler

## Language Manual:
- Refer to 20171077_MiniC_Manual.pdf.

## Instructions to compile and run the code:
- ./compile_and_run.sh \<path to source code\>
- Eg: ./compile_and_run.sh testcases/1.mc

## Implementation Details:
- The Macro and Micro Syntax of the language is specified in MiniC.g4 file.
- ANTLR-4 is used as the parser generator.
- The code generation is done in LLVM IR and passed to LLVM Toolchain.
- LLVM Toolchain handles the machine code generation and hence forms the backend of the compiler.
- More details regarding the implementation to come!
- Throughout the implementation, interesting compiler ideas like Basic Blocks, control flow graphs, abstract syntax trees are used which consolidates the understanding of the theory taught in the course.
- Check out Bonus folder on details about how an LLVM pass can be written. It contains Analysis/Transformation pass for printing extended basic blocks in a  program and a pass which implements Super-local value numbering.
