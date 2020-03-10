#ifndef ast_assignment_expression
#define ast_assignment_expression

#include "ast.hpp"

// assignment_expression
// 	: conditional_expression                                             {$$ = $1;}
// 	| unary_expression assignment_operator assignment_expression         {$$ = new assignment_expression($1, $2, $3);}
// 	;
//
// assignment_operator
// 	: '='                {$$ = "ASSIGN";}
// 	| MUL_ASSIGN         {$$ = "MUL";}
// 	| DIV_ASSIGN         {$$ = "DIV";}
// 	| MOD_ASSIGN         {$$ = "MOD";}
// 	| ADD_ASSIGN         {$$ = "ADD";}
// 	| SUB_ASSIGN         {$$ = "SUB";}
// 	| LEFT_ASSIGN        {$$ = "LEFT";}
// 	| RIGHT_ASSIGN       {$$ = "RIGHT";}
// 	| AND_ASSIGN         {$$ = "AND";}
// 	| XOR_ASSIGN         {$$ = "XOR";}
// 	| OR_ASSIGN          {$$ = "OR";}
// 	;

class assignment_expression : public expression{
public:
  assignment_expression(treeptr o, int type_in, treeptr f){p_one = o; type = type_in; p_five = f;}
  ~assignment_expression(){delete p_one; delete p_five;};
  inline void translate(string& pyout);
private:
  int type;
  treeptr p_one;
  treeptr p_five;
  string cname = "assignment_expression";
};

void assignment_expression::translate(string& pyout){
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

#endif
