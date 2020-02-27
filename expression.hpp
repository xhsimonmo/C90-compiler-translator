#ifndef ast_expression
#define ast_expression

#include "ast.hpp"

class expression : public expression{
public:
  expression(treeptr o, treeptr f){p_one = o; p_five = f;}
  ~expression(){delete p_one; delete p_five};
  void translate(string& pyout);
private:
  int type;
  treeptr p_one;
  treeptr p_five;
};

void expression::translate(string& pyout){
  string one;
  string five;
  p_one->translate(one);
  p_five->translate(five);
  pyout = one + "," + five;
}

#endif
