#ifndef ast_conditional_expression
#define ast_conditional_expression

#include "ast.hpp"

class conditional_expression : public expression{
public:
  conditional_expression(treeptr o, treeptr t, treeptr f){p_one = o; p_three = t; p_five = f;}
  ~conditional_expression(){delete p_one; delete p_three; delete p_five};
  void translate(string& pyout);
private:
  treeptr p_one;
  treeptr p_three;
  treeptr p_five;
};

void conditional_expression::translate(string& pyout){
  NotImplemented();
}

#endif
