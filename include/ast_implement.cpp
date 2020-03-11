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

void cast_expression::translate(string& pyout) const{
      debug(cname);
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

void compound_statement::translate(string& pyout) const{
  debug(cname);
  string ds, ss;
  switch (type) {
    case 0:
    break;//do nothing?
    case 1:
    // indentation++; //encounter "{"
    left->translate(pyout);
    // indentation--; //exit with "}"
    break;
    case 2:
    // indentation++; //encounter "{"
    left->translate(pyout);
    // indentation--; //exit with "}"
    break;
    case 3:
    // indentation++;
    left->translate(ds);
    right->translate(ss);
    // indentation--;
    pyout = ds + '\n' + ss;
    break;

  }
}

void conditional_expression::translate(string& pyout) const{
  debug(cname);
  NotImplemented();
}

void declaration_list::translate(string& pyout, vector<string> global_variables)const{
 debug(cname);
 string l;
 string r;

 p_o->translate(l);
 p_t->translate(r);
 pyout = l + "\n" + r;
}
