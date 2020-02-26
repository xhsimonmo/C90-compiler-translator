#ifndef ast_cast_expression
#define ast_cast_expression
#include <iostream>
#include <string>
using namespace std;


class cast_expression : public expression{
public:
  cast_expression(int type_in, treeptr p, treeptr o){type = type_in; ptr = p; opt = o;}
  cast_expression(int type_in, treeptr p){type = type_in; ptr = p;}
  ~cast_expression(){delete ptr; delete opt};
  void translate(string& pyout);
private:
  int type;
  treeptr ptr;
  treeptr opt;
};

void cast_expression::translate(string& pyout){
std::string op;
  switch (type)
  {
    case 0:
    ptr->translate(pyout);
    opt->translate(op);
    pyout = pyout + "(" + op + ")";
    break;

    default:
    NotImplemented();
  }
}
