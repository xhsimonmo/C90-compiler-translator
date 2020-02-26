#ifndef ast.hpp
#define ast.hpp

#include "compiler.y"
#include "lexer.flex"

#include <iostream>
#include <vector>

using namespace std;

extern indentation;//specify number of tab/"/t"

typedef std::shared_ptr<astnode> treeptr;

int main(argc, argv[]){
  ifstream csource;//input ...c
  csourse.open(argv[0]);//open input c, tokenise it, lex, and parse.



  std::cerr << "translator begin" << '\n';
  treeptr root;
  string pyout;
  root-> translate(pyout);

  ofstream pyfile;//output ...py
  pyfile.open(argv[1]);

}
