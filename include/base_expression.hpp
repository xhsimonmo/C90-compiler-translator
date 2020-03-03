#ifndef ast_base_expression
#define ast_base_expression

#include "ast.hpp"

class base_expression : public expression{
public:
  base_expression(treeptr o, treeptr f){p_one = o; p_five = f;}
  ~base_expression(){delete p_one; delete p_five}
  void translate(string& pyout);
private:
  int type;
  treeptr p_one;
  treeptr p_five;
};

void base_expression::translate(string& pyout){
  string one;
  string five;
  p_one->translate(one);
  p_five->translate(five);
  pyout = one + "," + five;
}

#endif
