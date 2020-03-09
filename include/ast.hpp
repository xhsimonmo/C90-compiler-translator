#ifndef ast_hpp_h
#define ast_hpp_h

//#include "menu.hpp" // include all the other header files
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using std::string;
using std::vector;

<<<<<<< HEAD
extern int indentation = 0;//specify number of tab/"/t"
=======
int indentation;//specify number of tab/"/t"

>>>>>>> 6c2c45763cda1344fb813d7770ab1dc79492c8ad
//this basically indicate the difference between "{" and "}", which is the number of "\t" to add
//it will change dynamically during parsing
vector<string> global_variables;
class astnode;
<<<<<<< HEAD
=======
inline void NotImplemented();
inline string indent(string& source);
>>>>>>> 6c2c45763cda1344fb813d7770ab1dc79492c8ad
// typedef std::shared_ptr<astnode> treeptr;
typedef astnode* treeptr;


class astnode{
public:
  astnode(){};
  virtual void translate(string& pyout)const{};
  virtual void translate(string& pyout, vector<string> global_variables)const {};
  //virtual compile();
  //virtual void translate() = 0;//translator
<<<<<<< HEAD
  virtual void compile(string& mpout){};//compiler
=======
<<<<<<< HEAD
  virtual void compile(string& mpout)const{};//compiler
=======
  virtual void compile(string& mpout) const{};//compiler
>>>>>>> 593c429621acf69a4aa4047d6d0b3bfd2a082195
>>>>>>> 6c2c45763cda1344fb813d7770ab1dc79492c8ad
  //~astnode();
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
