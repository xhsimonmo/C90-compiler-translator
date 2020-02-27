#ifndef ast_hpp
#define ast_hpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

extern int indentation = 0;//specify number of tab/"/t"
//this basically indicate the difference between "{" and "}", which is the number of "\t" to add
//it will change dynamically during parsing

typedef std::shared_ptr<astnode> treeptr;

class astnode{
public:
  virtual astnode();
  virtual translate()=0;
  virtual compile();
  virtual ~astnode();
private:
  vector<treeptr> branches;

};

class expression : public astnode{
  virtual expression();
  virtual ~expression(){};

};

class declaration : public astnode{
  virtual declaration();
  virtual ~declaration(){};
};

class statement : public astnode{
  virtual statement();
  virtual ~statement(){};
};


extern void NotImplemented(){
  std::cerr << "Not Implemented." << '\n';//for function not needed to Implement
}

#endif
