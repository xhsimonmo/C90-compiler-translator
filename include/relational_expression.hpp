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
  relational_expression(int type_in, treeptr p, treeptr o){type = type_in; left = p; right = o;}
  ~relational_expression(){delete left; delete right;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr left = NULL;
  treeptr right = NULL;
  string cname = "relational_expression";
};

void relational_expression::compile(mips& mp)const{
  mips another_mp;
  switch (type) {
    case 0:
    left->compile(mp);
    mp.move(3,2);
    right -> compile(another_mp);
    mp.slt(2,3,2);
    break;
    case 1:
    left->compile(mp);
    mp.move(3,2);
    right -> compile(another_mp);
    mp.slt(2,2,3);//simply swap 2 and 3 registers
    break;
    case 2: //<=
    left->compile(mp);
    mp.move(3,2);
    right -> compile(another_mp);


  }
}

// void relational_expression::translate(string& pyout) const{
//   debug(cname);
//   std::string one,op;
//   //std::cerr << "right of <" << '\n';
//   right->translate(op);
//   //std::cerr << "left of <" << '\n';
//   left->translate(one);
//   switch (type)
// {
//   case 0:
//   pyout = one + "<" + op;
//   break;
//
//   case 1:
//   pyout = one + ">" + op;
//   break;
//
//   case 2:
//   pyout = pyout + "<=" + op;
//   break;
//
//   case 3:
//   pyout = pyout + ">=" + op;
//   break;
//
//   case 4:
//   pyout = pyout + "==" + op;
//   break;
//
//   case 5:
//   pyout = pyout + "!=" + op;
//   break;
//
//   case 6:
//   pyout = pyout + "&" + op;
//   break;
//
//   case 7:
//   pyout = pyout + "^" + op;
//   break;
//
//   case 8:
//   pyout = pyout + "|" + op;
//   break;
//
//   case 9:
//   pyout = pyout + "and" + op;
//   break;
//
//   case 10:
//   pyout = pyout + "or" + op;
//   break;
//
//
//   default:
//   NotImplemented();
// }
// }

#endif
