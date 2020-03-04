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

  switch (p_three)
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
