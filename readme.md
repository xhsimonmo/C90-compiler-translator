C90 Compiler and Translator
==============================

There is a language processing project in Imperial College third year, it contains two components:

- [*C-translator*](spec/c_translator.md) : Your compiler will be able to translate a subset of C into equivalent Python. This allows each submission to demonstrate lexing and parsing functionality, even if the code generation is weak.

- [*C-compiler*](spec/c_compiler.md) : This is a compiler from C to MIPS assembly.
  
In all cases, the source language is pre-processed C90. The target environment is Ubuntu 16.04, so the lab Ubuntu distribution, or equivalently an Ubuntu 16.04 VM as configured in the attached Vagrantfile.
