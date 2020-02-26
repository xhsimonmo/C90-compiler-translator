#ifndef ast.hpp
#define ast.hpp

#include <iostream>
#include <vector>

using namespace std;

extern indentation;

typedef std::shared_ptr<astnode> treeptr;

class astnode{
public:
  virtual astnode();

  virtual translate()=0;
  virtual compile();
  virtual ~astnode() {};
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


void NotImplemented(){
  std::cerr << "Not Implemented." << '\n';//for function not needed to Implement
}
