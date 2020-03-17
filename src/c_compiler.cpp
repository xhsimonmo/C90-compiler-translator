#include "menu.hpp"
// #include "ast.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>


//bin/c_compiler --translate a.c -o a.py
//bin/c_compiler -S [source-file.c] -o [dest-file.s]
//bin/c_compiler --translate [source-file.c] -o [dest-file.py]

// extern const astnode * parseAST(char* filename);//altenative method
extern FILE *yyin; // pointer to input stream
vector<string> global_variables;
//int indentation;
int main(int argc, char *argv[]){
  if(argc != 5){
    std::cerr << "Totally 5 args are required, argument number not matched." << '\n';
  }
  //ifstream csource;//input ...c
  //csourse.open(argv[1]);//open input c, tokenise it, lex, and parse.
  //string filename = argv[2];
  yyin = fopen(argv[2], "r");
  const astnode* root = parseAST();
  std::ofstream outfile;//output ...py
  outfile.open(argv[4]);

  if(strcmp(argv[1], "--translate") == 0 ){
    std::cerr << "\ntranslator begin" << '\n';
    //indentation = 0;
    std::string pyout;
    std::cerr  << '\n';
    root->translate(pyout);
    std::string addmain;
    addmain = "\nif __name__ == \"__main__\":\n\timport sys\n\tret=main()\n\tsys.exit(ret)"; // include in every python file to invoke main
    //std::cerr << "\noutput python string: " << '\n';
    std::cerr << "pyout in main is \n\n" << pyout <<'\n';
    //pyout = pyout + addmain;
    pyout.append(addmain);
    outfile << pyout;

  }
  else if(argv[1] == "-S"){
     std::cerr << "compiler begin" << std::endl;
     mips mp;
     root -> compile(mp);
     string generated_mips;
     for(auto it = mp.mpcode.begin(); it !=mp.mpcode.end();it++ )
     {
       generated_mips.append(*it);
     }
     outfile << generated_mips;

  }

  else{
    std::cerr << "no valid flag is provided to operate." << '\n';
    std::exit(-1);
  }
  outfile.close();
  return 0;

}
