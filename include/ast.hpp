#ifndef ast_hpp
#define ast_hpp

#include "*.hpp" // include all the other header files
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

extern int indentation = 0;//specify number of tab/"/t"
//this basically indicate the difference between "{" and "}", which is the number of "\t" to add
//it will change dynamically during parsing


typedef std::shared_ptr<astnode> treeptr;

class astnode{
public:
  virtual astnode();
  virtual translate(string& pyout) = 0;
  virtual compile();
  virtual ~astnode();
private:
  vector<treeptr> branches;

};

class expression : public astnode{
  virtual expression();
  virtual ~expression(){};

};

class definition : public astnode{
  virtual definition();
  virtual ~definition(){};
};

class declaration : public astnode{
  virtual declaration();
  virtual ~declaration(){};
};

class statement : public astnode{
  virtual statement();
  virtual ~statement(){};
};

// class declaration : public astnode{
//   virtual declaration();
//   virtual ~declaration(){};
// };

void indent(string& source) //PLEASE WORK PLEASE
{ //add x number of "\t" after every '\n'
  string delimiter = '/t';
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

#endif
