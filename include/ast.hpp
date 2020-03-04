#ifndef ast_hpp
#define ast_hpp

//#include "menu.hpp" // include all the other header files
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

extern int indentation = 0;//specify number of tab/"/t"
//this basically indicate the difference between "{" and "}", which is the number of "\t" to add
//it will change dynamically during parsing
extern vector<string> global_variable;
class astnode;
// typedef std::shared_ptr<astnode> treeptr;
typedef astnode* treeptr;
extern treeptr parseAST(string& filename);
class astnode{
public:
  astnode(){};
  virtual void translate(string& pyout) = 0;
  //virtual compile();
  virtual void translate() = 0;//translator
  virtual void compile(string& mpout) = 0;//compiler
  virtual ~astnode();
private:
  //vector<treeptr> branches;

};

class expression : public astnode{
  expression(){};
  virtual ~expression(){};

};

class definition : public astnode{
  definition(){};
  virtual ~definition(){};
};

class declaration : public astnode{
  declaration();
  virtual ~declaration(){};
};

class statement : public astnode{
  statement(){};
  virtual ~statement(){};
};

// class declaration : public astnode{
//   virtual declaration();
//   virtual ~declaration(){};
// };

void indent(string& source) //PLEASE WORK PLEASE
{ //add x number of "\t" after every '\n'
  char delimiter = '/t';
  for (auto it = source.begin(); it != source.end(); it++)
  {
    if(*it == '\n'){
      for(int i = 0; i <= indentation; i++){
        source = delimiter + source;//add corresponding number of indentation
        it++;// wo nuo
      }
    }
  }
}

extern void NotImplemented(){
  std::cerr << "Not Implemented." << '\n';//for function not needed to Implement
}


////////////////////////////MIPS////////////////////////////////











#endif
