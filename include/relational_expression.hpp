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
// equality_expression
// 	: relational_expression                              {$$ = $1; std::cerr << "equality_expression 1" << std::endl;}
// 	| equality_expression EQ_OP relational_expression    {$$ = new relational_expression(4, $1, $3); std::cerr << "equality_expression 2" << std::endl;}
// 	| equality_expression NE_OP relational_expression    {$$ = new relational_expression(5, $1, $3); std::cerr << "equality_expression 3" << std::endl;}
// 	;
//
// and_expression
// 	: equality_expression                                {$$ = $1; std::cerr << "and_expression 1" << std::endl;}
// 	| and_expression '&' equality_expression             {$$ = new relational_expression(6, $1, $3); std::cerr << "and_expression 2" << std::endl;}
// 	;
//
// exclusive_or_expression
// 	: and_expression                                     {$$ = $1; std::cerr << "exclusive_or_expression 1" << std::endl;}
// 	| exclusive_or_expression '^' and_expression         {$$ = new relational_expression(7, $1, $3); std::cerr << "exclusive_or_expression 2" << std::endl;}
// 	;
//
// inclusive_or_expression
// 	: exclusive_or_expression                                {$$ = $1; std::cerr << "inclusive_or_expression 1" << std::endl;}
// 	| inclusive_or_expression '|' exclusive_or_expression    {$$ = new relational_expression(8, $1, $3); std::cerr << "inclusive_or_expression 2" << std::endl;}
// 	;
//
// logical_and_expression
// 	: inclusive_or_expression                                {$$ = $1; std::cerr << "logical_and_expression 1" << std::endl;}
// 	| logical_and_expression AND_OP inclusive_or_expression  {$$ = new relational_expression(9, $1, $3); std::cerr << "logical_and_expression 2" << std::endl;}
// 	;
//
// logical_or_expression
// 	: logical_and_expression                                 {$$ = $1; std::cerr << "logical_or_expression 1" << std::endl;}
// 	| logical_or_expression OR_OP logical_and_expression     {$$ = new relational_expression(10, $1, $3); std::cerr << "logical_or_expression 2" << std::endl;}
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


// void relational_expression::compile(mips& mp)const{
//   int l_index;
//   int r_index;
//   add->compile(mp);
//   l_index = result_offset();
//   mips another_mp;
//   mul->compile(another_mp);
//   r_index = result_offset();
//   mp.comment("load right index from memory");
//   mp.lw(3,r_index,30);
//   mp.comment("load left index from memory");
//   mp.lw(2,l_index,30);
//   switch (type) {
//     case 0:
//     mp.slt(2,2,3);
//     break;
//     case 1:
//     mp.slt(2,3,2);//simply swap 2 and 3 registers
//     break;
//     case 2: //<=
//     mp.sle(2,2,3);
//     break;
//     case 3: //>=
//     mp.sge(2,2,3)
//     break;
//     case 4: // ==
//     mp.seq(2,2,3);
//     break;
//     case 5:
//     mp.sne(2,2,3);
//     break;
//     case 6: //& (pointer dereference)
//     mp._and(2,2,3);
//     break;
//     case 7:
//     mp._xor(2,2,3);
//     break;
//     case 8:
//     mp._or(2,2,3);
//     break;
//     case 9:// and
//     mp._and(3,2,3);//if eitehr $2,$3 is zero, will be evaluated as zero
//     mp.li(8,'2');
//     mp.li(9,'0');
//     mp.sne(2,2,9);
//     mp.sne(3,3,9);
//     mp.add(2,2,3);//if $2 add up to 2, then both unequal to 0
//     mp.seq(2,2,8);
//     break;
//
//     case 10: // or
//     mp._or(3,2,3);//only both $2,$3 is zero, will be evaluated as zero
//     mp.li(2,'0');
//     mp.sne(2,2,3);
//     break;
//   }
// }

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
