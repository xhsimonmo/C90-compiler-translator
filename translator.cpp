
#include "compiler.y"
#include "lexer.flex"
#include"ast.hpp"

///include every hpp file


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
  string addmain;
  addmain = "if __name__ == \"__main__\":\nimport sys\nret=main()\nsys.exit(ret)" // include in every python file to invoke main
  pyout = pyout + addmain;
  ofstream pyfile;//output ...py
  pyfile.open(argv[1]);

}
