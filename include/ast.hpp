#ifndef ast_hpp_h
#define ast_hpp_h

//#include "menu.hpp" // include all the other header files
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using std::string;
using std::vector;

//extern int indentation ;//specify number of tab/"/t"


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
  //virtual void translate(string& pyout, vector<string> global_variables)const {};
  // virtual void compile(mips& mp)const{};//compiler
  //~astnode();
  const int testpoint()const{return 2;}
private:
  //vector<treeptr> branches;

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

string indent(string& source) //PLEASE WORK PLEASE
{ //add x number of "\t" after every '\n'
  //int indentation;
  //char delimiter = '\t';
  std::cerr << "indent:" <<source <<'\n';
  source.insert(0, 1,'\t'); //add /t to first line
  //string::size_type i = 0;
  for ( string::size_type it = 0; it < source.size(); it++)
  {
    if(source[it] == '\n' && it != source.size()-1){
      //std::cerr << "spot line breaker in indent" << '\n';
      source.insert(it+1,1, '\t');//add \t to every \t
      it ++;
    }
  }
  // for (auto it = source.begin(); it != source.end(); it++)
  // {
  //   if(*it == '\n'){
  //     std::cerr << "spot line breaker in indent" << '\n';
  //     source.insert(it+1,1, '\t');
  //     it ++;
  //   }
  // }
  return source;
}

void NotImplemented(){
  std::cerr << "Not Implemented." << '\n';//for function not needed to Implement
}

 void debug(string classname){
  std::cerr << "the name of the current class is: " << classname <<  '\n';
  std::cerr << "current global variable size: " << global_variables.size() << '\n';
}

////////////////////////////MIPS////////////////////////////////

#endif
