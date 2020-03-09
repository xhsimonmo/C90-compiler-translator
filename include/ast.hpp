#ifndef ast_hpp_h
#define ast_hpp_h

//#include "menu.hpp" // include all the other header files
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using std::string;
using std::vector;

inline int indentation;//specify number of tab/"/t"

//this basically indicate the difference between "{" and "}", which is the number of "\t" to add
//it will change dynamically during parsing
inline vector<string> global_variables;
class astnode;
inline void NotImplemented();
inline string indent(string& source);
// typedef std::shared_ptr<astnode> treeptr;
typedef astnode* treeptr;


class astnode{
public:
  astnode(){};
  virtual void translate(string& pyout)const{};
  virtual void translate(string& pyout, vector<string> global_variables)const {};
  //virtual compile();
  //virtual void translate() = 0;//translator
  virtual void compile(string& mpout)const{};//compiler
  //~astnode();
private:
  //vector<treeptr> branches;

};

class expression : public astnode{
public:
  expression(){};
  virtual void translate(string& pyout){};
  virtual ~expression(){};
  virtual void compile(string& mpout)const{};//compiler
private:
};

class definition : public astnode{
public:
  definition(){};
  virtual void translate(string& pyout){};
  virtual ~definition(){};
private:

};

// class declaration : public astnode{
// public:
//   declaration();
//   virtual ~declaration(){};
// };

class statement : public astnode{
public:
  statement(){};
  virtual void translate(string& pyout){};
  virtual ~statement(){};
private:
};

// class declaration : public astnode{
//   virtual declaration();
//   virtual ~declaration(){};
// };

string indent(string& source) //PLEASE WORK PLEASE
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
  return source;
}

extern void NotImplemented(){
  std::cerr << "Not Implemented." << '\n';//for function not needed to Implement
}


////////////////////////////MIPS////////////////////////////////








#endif
