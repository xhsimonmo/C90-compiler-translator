#ifndef ast_unary_expression
#define ast_unary_expression

#include "ast.hpp"

// unary_expression
// 	: postfix_expression               {$$ = $1;}
// 	| INC_OP unary_expression          {$$ = new unary_expression(0, $2);}
// 	| DEC_OP unary_expression          {$$ = new unary_expression(1, $2);}
// 	| unary_operator cast_expression   {$$ = new unary_expression($1, $2);}
// 	| SIZEOF unary_expression          {$$ = new unary_expression(2, $2);}
// 	| SIZEOF '(' type_name ')'         {$$ = new unary_expression(3, $2);}
// 	;

class unary_expression : public expression{
public:
  unary_expression(string type_in, treeptr p){type = type_in; ptr = p;}
  ~unary_expression(){delete ptr;}
  void translate(string& pyout);
private:
  string type;
  treeptr ptr;
};

void postfix_operator::translate(string& pyout){
  switch (type)
  {
    case "0":
    ptr->translate(pyout);
    pyout = pyout + “+=1”;
    break;

    case "1":
    ptr->translate(pyout);
    pyout = pyout + “-=1”;
    break;

    // case "&":
    // ptr->translate(pyout);
    // pyout = "&" + pyout;
    // break;

    case "*":
    ptr->translate(pyout);
    pyout = "*" + pyout;
    break;

    case "+":
    ptr->translate(pyout);
    pyout = "+" + pyout;
    break;

    case "-":
    ptr->translate(pyout);
    pyout = "-" + pyout;
    break;

    // case "~":
    // ptr->translate(pyout);
    // pyout = "~" + pyout;
    // break;
    //
    // case "!":
    // ptr->translate(pyout);
    // pyout = "!" + pyout;
    // break;

    case "2":
    ptr->translate(pyout);
    pyout = "sys.getsizeof(" + pyout + ")";
    break;

    case "3":
    ptr->translate(pyout);
    pyout = "sys.getsizeof(" + pyout + ")";
    break;

    default:
    NotImplemented();
  }
}

#endif
