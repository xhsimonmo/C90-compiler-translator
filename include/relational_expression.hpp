#ifndef ast_relational_expression
#define ast_relational_expression

#include "ast.hpp"

// relational_expression
// 	: shift_expression                                 {$$ = $1;}
// 	| relational_expression '<' shift_expression       {$$ = new relational_expression(0, $1, $3);}
// 	| relational_expression '>' shift_expression       {$$ = new relational_expression(1, $1, $3);}
// 	| relational_expression LE_OP shift_expression     {$$ = new relational_expression(2, $1, $3);}
// 	| relational_expression GE_OP shift_expression     {$$ = new relational_expression(3, $1, $3);}
// 	;

class relational_expression : public expression{
public:
  relational_expression(int type_in, treeptr p, treeptr o){type = type_in; ptr = p; opt = o;}
  ~relational_expression(){delete ptr; delete opt;}
  inline void translate(string& pyout);
private:
  int type;
  treeptr ptr;
  treeptr opt;
};

void relational_expression::translate(string& pyout){
std::string op;
ptr->translate(pyout);
opt->translate(op);
switch (type)
{
  case 0:
  pyout = pyout + "<" + op;
  break;

  case 1:
  pyout = pyout + ">" + op;
  break;

  case 2:
  pyout = pyout + "<=" + op;
  break;

  case 3:
  pyout = pyout + ">=" + op;
  break;

  case 4:
  pyout = pyout + "==" + op;
  break;

  case 5:
  pyout = pyout + "!=" + op;
  break;

  case 6:
  pyout = pyout + "&" + op;
  break;

  case 7:
  pyout = pyout + "^" + op;
  break;

  case 8:
  pyout = pyout + "|" + op;
  break;

  case 9:
  pyout = pyout + "and" + op;
  break;

  case 10:
  pyout = pyout + "or" + op;
  break;


  default:
  NotImplemented();
}
}

#endif
