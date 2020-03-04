//#include "compiler.y"
//#include "lexer.flex"
#include"ast.hpp"

///include every hpp file
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
extern indentation;//specify number of tab/"/t"
typedef std::shared_ptr<astnode> treeptr;
//invoke by :
//bin/c_compiler -S [source-file.c] -o [dest-file.s]

//bin/c_compiler --translate [source-file.c] -o [dest-file.py]

int main(int argc, argv*[]){
  if(argc != 5){
    std::cerr << "Totally 5 args are required, argument number not matched." << '\n';
  }
  ifstream csource;//input ...c
  //csourse.open(argv[1]);//open input c, tokenise it, lex, and parse.
  const treeptr root = parseAST(argv[1]);

  if(argv[1] == "--translate"){
    std::cerr << "translator begin" << '\n';
    treeptr root;
    string pyout;
    root-> translate(pyout);
    string addmain;
    addmain = "\nif __name__ == \"__main__\":\nimport sys\nret=main()\nsys.exit(ret)" // include in every python file to invoke main
    pyout = pyout + addmain;
    ofstream pyfile;//output ...py
    pyfile.open(argv[1]);
    pyfile << pyout;

  }
  else if(argv[1] == "-S"){

  }

}
