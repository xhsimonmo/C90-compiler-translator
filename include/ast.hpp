#ifndef ast_hpp_h
#define ast_hpp_h

//#include "menu.hpp" // include all the other header files
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using std::string;
using std::vector;

extern int indentation ;//specify number of tab/"/t"


//this basically indicate the difference between "{" and "}", which is the number of "\t" to add
//it will change dynamically during parsing
extern vector<string> global_variables;
class astnode;
inline void NotImplemented();
inline void debug(string classname);
inline string indent(string& source);
// typedef std::shared_ptr<astnode> treeptr;
typedef const astnode* treeptr;

class astnode{
public:
  astnode(){};
  virtual void translate(string& pyout)const{};
  virtual void translate(string& pyout, vector<string> global_variables)const {};
  virtual void compile(mips& mp)const{};//compiler
  //~astnode();
  const int testpoint()const{return 2;}
private:
  //vector<treeptr> branches;

};

class expression : public astnode{
public:
  expression(){};
  virtual void translate(string& pyout){};
  virtual ~expression(){};
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


inline string indent(string& source) //PLEASE WORK PLEASE
{ //add x number of "\t" after every '\n'
  int indentation;
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

void NotImplemented(){
  std::cerr << "Not Implemented." << '\n';//for function not needed to Implement
}

 void debug(string classname){
  std::cerr << "the name of the current class is: " << classname <<  '\n';
}

////////////////////////////MIPS////////////////////////////////

#endif
