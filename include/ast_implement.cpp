#include "menu.hpp"

void abstract_declarator::translate(string& pyout)const{
    debug(cname);
    NotImplemented();
}

void argument_expression_list::translate(string& pyout)const{
    debug(cname);
    NotImplemented();
}

void assignment_expression::translate(string& pyout)const{
  debug(cname);
  string one;
  string five;
  p_one->translate(one);
  p_five->translate(five);

  switch (type)
  {
    case 0:
    pyout = one + "=" + five;
    break;

    case 1:
    pyout = one + "*=" + five;
    break;

    case 2:
    pyout = one + "/=" + five;
    break;

    case 3:
    pyout = one + "%=" + five;
    break;

    case 4:
    pyout = one + "+=" + five;
    break;

    case 5:
    pyout = one + "-=" + five;
    break;

    case 6:
    pyout = one + "<<=" + five;
    break;

    case 7:
    pyout = one + ">>=" + five;
    break;

    case 8:
    pyout = one + "&=" + five;
    break;

    case 9:
    pyout = one + "^=" + five;
    break;

    case 10:
    pyout = one + "|=" + five;
    break;
  }
}

void base_expression::translate(string& pyout)const{
  debug(cname);
  string one;
  string five;
  p_one->translate(one);
  p_five->translate(five);
  pyout = one + "," + five;
}
