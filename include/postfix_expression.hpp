#include ast.hpp
#include <iostream>
#include <string>
using namespace std;


class postfix_expression : public expression{
public:
  postfix_expression(int type_in, treeptr p, treeptr o){type = type_in; ptr = p; opt = o;}
  postfix_expression(int type_in, treeptr p){type = type_in; ptr = p;}
  ~postfix_expression(){delete ptr; delete opt};
  void translate(string& pyout);
private:
  int type;
  treeptr ptr;
  treeptr opt;
};

void postfix_expression::translate(string& pyout){
std::string op;
switch (type)
{
  case 0:
  ptr->translate(pyout);
  pyout = pyout + "()";
  break;

  case 1:
  ptr->translate(pyout);
  pyout = pyout + "()";
  break;

  case 2:
  ptr->translate(pyout);
  opt->translate(op);
  pyout = pyout + "(" + op + ")";
  break;

  case 3:
  ptr->translate(pyout);
  pyout = pyout + "." + element;
  break;

  // case 4:
  // ptr->translate(pyout);
  // pyout = pyout + "->7" + element;
  // break;


  case 5:
  ptr->translate(pyout);
  pyout = pyout + "+=1";
  break;

  case 6:
  ptr->translate(pyout);
  pyout = pyout + "-=1";
  break;

  default:
  NotImplemented();
}
}
