#include "menu.hpp"
// #include "ast.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <string.h>

int current_frame = 0;
int labelcounter;
vector<vector<stack_content>>stack_collection;
vector<vector<string>> mpcode_collection;
vector<int> arg_count_collection;
vector<vector<array_struct>> array_collection;
bool in_frame = false;

bool arg_reg[4];
int arg_overflow;
int caller_arg_count;
int result_count;
int array_index;

bool in_frame;
bool end_frame;

extern FILE *yyin; // pointer to input stream
vector<string> global_variables;

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
  else if(strcmp(argv[1], "-S") == 0 ){
     std::cerr << "compiler begin" << std::endl;
     mips mp;

     vector<array_struct>global_array;
     array_collection.push_back(global_array);//0 index of array_collection is global arrays

     root -> compile(mp);
     string generated_mips;
     for(int i = 0; i < mpcode_collection.size();i++)
     {
       for(auto it = mpcode_collection[i].begin(); it !=mpcode_collection[i].end();it++ )
       {
         generated_mips.append(*it);
         generated_mips += '\n';
       }
     }
     outfile << generated_mips;
  }

  else{
    std::cerr << "no valid flag is provided to operate." << '\n';
    std::exit(-1);
  }
  outfile.close();
  std::cerr << "////operation end.///////" << '\n';
  return 0;

}
