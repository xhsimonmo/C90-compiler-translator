#ifndef ast_hpp_h
#define ast_hpp_h

//#include "menu.hpp" // include all the other header files
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using std::string;
using std::vector;


extern int labelcounter;//make unique label by number
extern int frame_counter;//make unique number for frame: as the stack index!
//remember the locations of each variable (offset relative to the frame pointer, which is a register)
extern struct stack_content
{
  string name;//variable name: i
  int address;//variable (relative)locations: add 0, 4(0/4+fp)
};
//collection of stack vector for each frame(two-dimension);
extern vector<vector<stack_content>>stack_collection;
extern vector<vector<string>> mpcode_collection;//store generated mips code
extern vector<string>mpcode;//final mips code collection

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
  virtual void compile(mips& mp) const {};
  //virtual void translate(string& pyout, vector<string> global_variables)const {};
  // virtual void compile(mips& mp)const{};//compiler
  //~astnode();
  const int testpoint()const{return 2;}
private:
};

class expression : public astnode{
public:
  expression(){};
  virtual void translate(string& pyout)const{};
  virtual ~expression(){};
private:
};

class definition : public astnode{
public:
  definition(){};
  virtual void translate(string& pyout)const{};
  virtual ~definition(){};
private:

};


class statement : public astnode{
public:
  statement(){};
  virtual void translate(string& pyout){};
  virtual ~statement(){};
private:
};

string indent(string& source) //PLEASE WORK PLEASE
{ //add x number of "\t" after every '\n'
  //std::cerr << "indent message:\n" << source <<'\n';
  if(source.empty()){
    return source;
  }
  source.insert(0, 1,'\t'); //add /t to first line
  for ( string::size_type it = 0; it < source.size(); it++)
  {
    if(source[it] == '\n' && it != source.size()-1){
      //std::cerr << "spot line breaker in indent" << '\n';
      source.insert(it+1,1, '\t');//add \t to every \t
      it ++;
    }
  }
  return source;
}

void NotImplemented(){
  std::cerr << "Not Implemented." << '\n';//for function not needed to Implement
}

 void debug(string classname){
  std::cerr << "the name of the current class is: " << classname <<  '\n';
  //std::cerr << "current global variable size: " << global_variables.size() << '\n';
}

////////////////////////////MIPS////////////////////////////////

#endif
