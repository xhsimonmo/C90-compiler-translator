#ifndef ast_base_expression
#define ast_base_expression

#include "ast.hpp"

// expression
// 	: assignment_expression                  {$$ = $1; std::cerr << "expression 1" << std::endl;}
// 	| expression ',' assignment_expression   {$$ = new base_expression($1, $3); std::cerr << "expression 2" << std::endl;}
// 	;


class base_expression : public expression{
public:
  base_expression(treeptr o, treeptr f){p_one = o; p_five = f;}
  ~base_expression(){delete p_one; delete p_five;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr p_one;
  treeptr p_five;
  string cname = "base_expression";
};

// void base_expression::compile(mips& mp)const
// {
//   p_one -> compile(mp);
//   mips another_mp;
//   p_five ->compile(another_mp);
// }
// void base_expression::translate(string& pyout){
//   debug(cname);
//   string one;
//   string five;
//   p_one->translate(one);
//   p_five->translate(five);
//   pyout = one + "," + five;
// }

#endif
