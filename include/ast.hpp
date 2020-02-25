


#include <iostream>
#include <vector>

using namespace std;

typedef std::shared_ptr<astnode> treeptr;

class ast_node{
public:
  virtual astnode();

  virtual translate();
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
