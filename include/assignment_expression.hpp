#ifndef ast_assignment_expression
#define ast_assignment_expression

#include "ast.hpp"

// assignment_expression
// 	: conditional_expression                                             {$$ = new assignment_expression($1); std::cerr << "assignment expression 1" << std::endl;}
// 	| unary_expression assignment_operator assignment_expression         {$$ = new assignment_expression($1, $2, $3); std::cerr << "assignment expression 2" << std::endl;}
// 	;
//
// assignment_operator
// 	: '='                {$$ = 0; std::cerr << "assignment operator 1" << std::endl;}
// 	| MUL_ASSIGN         {$$ = 1; std::cerr << "assignment operator 2" << std::endl;}
// 	| DIV_ASSIGN         {$$ = 2; std::cerr << "assignment operator 3" << std::endl;}
// 	| MOD_ASSIGN         {$$ = 3; std::cerr << "assignment operator 4" << std::endl;}
// 	| ADD_ASSIGN         {$$ = 4; std::cerr << "assignment operator 5" << std::endl;}
// 	| SUB_ASSIGN         {$$ = 5; std::cerr << "assignment operator 6" << std::endl;}
// 	| LEFT_ASSIGN        {$$ = 6; std::cerr << "assignment operator 7" << std::endl;}
// 	| RIGHT_ASSIGN       {$$ = 7; std::cerr << "assignment operator 8" << std::endl;}
// 	| AND_ASSIGN         {$$ = 8; std::cerr << "assignment operator 9" << std::endl;}
// 	| XOR_ASSIGN         {$$ = 9; std::cerr << "assignment operator 10" << std::endl;}
// 	| OR_ASSIGN          {$$ = 10; std::cerr << "assignment operator 11" << std::endl;}

class assignment_expression : public expression{
public:
  assignment_expression(treeptr o, int type_in, treeptr f){p_one = o; type = type_in; p_five = f;}
  assignment_expression(treeptr o){p_one = o;}
  ~assignment_expression(){delete p_one; delete p_five;};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr p_one = NULL;
  treeptr p_five = NULL;
  string cname = "assignment_expression";
};

// void assignment_expression::compile(mips& mp)
// {
//   //no unary expression
//   if(p_five == NULL)
//   {
//     p_one->compile(mp);
//   }
//   else
//   {
//     p_one->compile(mp);
//     mips another_mp;
//     p_five->compile(another_mp);
//
//     switch(type)
//     {
//       case 0://=
//       lw(3, another_mp.temp_result.var_index, 30); // TODO make var_index extern?
//       nop();
//       sw(3, mp.temp_result.var_index, 30);
//       break;
//
//       case 1://"*="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       mult(2, 3);
//       mflo(2);
//       sw(2, mp.temp_result.var_index, 30);
//       break;
//
//       case 2://"/="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       div(2, 3);
//       mflo(2);
//       sw(2, mp.temp_result.var_index, 30);
//       break;
//
//       case 3://"%="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       div(2, 3);
//       mfhi(2);
//       sw(2, mp.temp_result.var_index, 30);
//       break;
//
//       case 4://"+="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       add(2, 2, 3);
//       sw(2, mp.temp_result.var_index, 30);
//       break;
//
//       case 5://"-="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       sub(2, 2, 3);
//       sw(2, mp.temp_result.var_index, 30);
//       break;
//
//       case 6://"<<="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       sll(2, 2, 3);
//       sw(2, mp.temp_result.var_index, 30);
//       break;
//
//       case 7://">>="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       sra(2, 2, 3);
//       sw(2, mp.temp_result.var_index, 30);
//       break;
//
//       case 8://"&="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       and(2, 2, 3);
//       sw(2, mp.temp_result.var_index, 30);
//       break;
//
//       case 9://"^="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       xor(2, 2, 3);
//       sw(2, mp.temp_result.var_index, 30);
//       break;
//
//       case 10://"|="
//       lw(2, mp.temp_result.var_index, 30);
//       lw(3, another_mp.temp_result.var_index, 30);
//       nop();
//       (2, 2, 3);
//       or(2, mp.temp_result.var_index, 30);
//       break;
//     }
//
//   }
// }


// void assignment_expression::translate(string& pyout)const{
//   debug(cname);
//   string one;
//   string five;
//   if(p_five == NULL){
//       p_one->translate(pyout);
//   }
//   else{
//     p_one->translate(one);
//     p_five->translate(five);
//     switch (type)
//     {
//       case 0:
//       pyout = one + "=" + five;
//       break;
//
//       case 1:
//       pyout = one + "*=" + five;
//       break;
//
//       case 2:
//       pyout = one + "/=" + five;
//       break;
//
//       case 3:
//       pyout = one + "%=" + five;
//       break;
//
//       case 4:
//       pyout = one + "+=" + five;
//       break;
//
//       case 5:
//       pyout = one + "-=" + five;
//       break;
//
//       case 6:
//       pyout = one + "<<=" + five;
//       break;
//
//       case 7:
//       pyout = one + ">>=" + five;
//       break;
//
//       case 8:
//       pyout = one + "&=" + five;
//       break;
//
//       case 9:
//       pyout = one + "^=" + five;
//       break;
//
//       case 10:
//       pyout = one + "|=" + five;
//       break;
//
//     }
//   }
// }

#endif
