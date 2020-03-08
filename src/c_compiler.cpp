#include "menu.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//using namespace std;


//bin/c_compiler -S [source-file.c] -o [dest-file.s]
//bin/c_compiler --translate [source-file.c] -o [dest-file.py]

// extern const astnode * parseAST(char* filename);
extern FILE *yyin; // pointer to input stream

int main(int argc, char *argv[]){
  if(argc != 5){
    std::cerr << "Totally 5 args are required, argument number not matched." << '\n';
  }
  //ifstream csource;//input ...c
  //csourse.open(argv[1]);//open input c, tokenise it, lex, and parse.
  //string filename = argv[2];
  yyin = fopen(argv[2], "r");
  const astnode* root = parseAST();

  if(argv[1] == "--translate"){
    std::cerr << "translator begin" << '\n';

    string pyout;
    root -> translate(pyout);
    string addmain;
    addmain = "\nif __name__ == \"__main__\":\nimport sys\nret=main()\nsys.exit(ret)"; // include in every python file to invoke main
    pyout = pyout + addmain;
    std::ofstream pyfile;//output ...py
    pyfile.open(argv[2]);
    pyfile << pyout;

  }
  else if(argv[1] == "-S"){

  }
  //fclose(yyin);
  return 0;

}
