#include "menu.hpp"
// #include "ast.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>
//using namespace std;

//bin/c_compiler --translate a.c -o a.py
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
  std::ofstream pyfile;//output ...py
  pyfile.open(argv[4]);
  std::cout << "arg1 " <<argv[1] <<  '\n';

  if(strcmp(argv[1], "--translate") == 0 ){
    std::cerr << "translator begin" << '\n';
    int indentation = 0;
    std::string pyout;
    std::cout << "enter ast tree" << '\n';
    std::cerr << "first root : "  << root -> testpoint() << '\n';
    root->translate(pyout, {});

    std::string addmain;
    addmain = "\nif __name__ == \"__main__\":\n\timport sys\n\tret=main()\n\tsys.exit(ret)"; // include in every python file to invoke main
    std::cout << addmain << '\n';
    //pyout = pyout + addmain;
    pyout.append(addmain);
    pyfile << pyout;

  }
  else if(argv[1] == "-S"){
    // std::cerr << "compiler begin" << std::endl;
    // mips mp;
    // root -> compile(mp);


  }



  //fclose(yyin);
  pyfile.close();


  return 0;

}
