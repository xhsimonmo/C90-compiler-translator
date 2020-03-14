#ifndef primary_expression_h
#define primary_expression_h

#include "ast.hpp"

// primary_expression
// 	: IDENTIFIER    {$$ = new primary_expression(0,*$1); std::cerr << "primary expression 1, which is IDENTIFIER : " <<  *$1 << std::endl;}
// 	| CONSTANT      {$$ = new primary_expression(1,*$1); std::cerr << "primary expression 2, which is const with value: " << *$1 <<std::endl;}
// 	| STRING_LITERAL {$$ = new primary_expression(2,*$1); std::cerr << "primary expression 3,  which is string literal "<< std::endl;}
// 	| '(' expression ')' {$$ = new primary_expression(3,$2); std::cerr << "primary expression 4" << std::endl;}
// 	;


class primary_expression : public expression{
public:
  ~primary_expression(){
    delete expre_ptr;
  };
  primary_expression(int _type, string _element):type(_type),element(_element){};
  primary_expression(int _type, treeptr _ptr):type(_type),expre_ptr(_ptr){};

  virtual void translate(string& pyout)const override;//translate to Python
private:
  int type;
  string element;//either IDENTIFIER, CONSTANT, OR STRING_LITERAL
  treeptr expre_ptr;//the case (expression)
  string cname = "primary_expression";
};

// void primary_expression::translate(string& pyout) const
// {
//   debug(cname);
//   switch(type){
//     case 0:
//       pyout = element;
//       break;
//
//     case 1://constant representation in c different from python
//       pyout = element;
//       break;
//
//     case 2:
//       pyout = element;
//       break;
//
//     case 3:
//       string tmp;
//       expre_ptr->translate(tmp);
//       pyout = "(" + tmp + ")";//for "(" expression ")"
//       break;
//   }
// }

// string c2pyconstant(string cconst)
// {
//
// }
#endif
