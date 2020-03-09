#ifndef primary_expression_h
#define primary_expression_h

#include "ast.hpp"

// primary_expression
// 	: IDENTIFIER    {$$ = new primary_expression(0,*$1);}
// 	| CONSTANT      {$$ = new primary_expression(1,*$1);}
// 	| STRING_LITERAL {$$ = new primary_expression(2,*$1);}
// 	| '(' expression ')' {$$ = new primary_expression(3,$1);}
// 	;

class primary_expression : public expression{
public:
  ~primary_expression(){
    delete expre_ptr;
  };
  primary_expression(int type, string _element):element(_element){};
  primary_expression(int type, treeptr _ptr):expre_ptr(_ptr){};

  inline void translate(string& pyout);//translate to Python
private:
  int type;
  string element;//either IDENTIFIER, CONSTANT, OR STRING_LITERAL
  treeptr expre_ptr;//the case (expression)
};

void primary_expression::translate(string& pyout)
{
  switch(type){
    case 0:
      pyout = element;
      break;

    case 1://constant representation in c different from python
      pyout = element;
      break;

    case 2:
      pyout = element;
      break;

    case 3:
      expre_ptr->translate(pyout);//for "(" expression ")"
      break;
  }

}

// string c2pyconstant(string cconst)
// {
//
// }
#endif
