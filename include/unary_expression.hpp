#ifndef ast_unary_expression
#define ast_unary_expression

#include "ast.hpp"

class unary_expression : public expression{
public:
  unary_expression(string type_in, treeptr p){type = type_in; ptr = p;}
  ~unary_expression(){delete ptr;};
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
