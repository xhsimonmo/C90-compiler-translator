#ifndef ast_assignment_expression
#define ast_assignment_expression

#include "ast.hpp"

class assignment_expression : public expression{
public:
  assignment_expression(treeptr o, string t, treeptr f){p_one = o; p_three = t; p_five = f;}
  ~assignment_expression(){delete p_one; delete p_five};
  void translate(string& pyout);
private:
  int type;
  treeptr p_one;
  string p_three;//operator
  treeptr p_five;
};

void assignment_expression::translate(string& pyout){
  string one;
  string five;
  p_one->translate(one);
  p_five->translate(five);

  switch (three)
  {
    case "ASSIGN":
    pyout = one + "=" + five;
    break;

    case "MUL":
    pyout = one + "*=" + five;
    break;

    case "DIV":
    pyout = one + "/=" + five;
    break;

    case "MOD":
    pyout = one + "%=" + five;
    break;

    case "ADD":
    pyout = one + "+=" + five;
    break;

    case "SUB":
    pyout = one + "-=" + five;
    break;

    case "LEFT":
    pyout = one + "<<=" + five;
    break;

    case "RIGHT":
    pyout = one + ">>=" + five;
    break;

    case "AND":
    pyout = one + "&=" + five;
    break;

    case "XOR":
    pyout = one + "^=" + five;
    break;

    case "OR":
    pyout = one + "|=" + five;
    break;
  }
}

#endif
