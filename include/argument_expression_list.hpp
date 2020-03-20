#ifndef ast_argument_expression_list
#define ast_argument_expression_list

#include "ast.hpp"

// argument_expression_list
// 	: assignment_expression                                  {$$ = new argument_expression_list($1); std::cerr << "argument expression 1" << std::endl;}
// 	| argument_expression_list ',' assignment_expression     {$$ = new argument_expression_list($1, $3); std::cerr << "argument expression 2" << std::endl;}
// 	;

class argument_expression_list : public expression{
public:
  argument_expression_list(treeptr o){ left = o;}
  argument_expression_list(treeptr o, treeptr t){ left = o; right = t;}
  ~argument_expression_list(){delete left; delete right;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  //int type;
  treeptr left = NULL;
  treeptr right = NULL;
  string cname = "argument_expression_list";
};

void argument_expression_list::compile(mips& mp)const{
  debug(cname);
  if(right == NULL){
    mips another_mp;
    left->compile(another_mp); // will reach a primary expression, either variable or number
    callee_value_process(another_mp);
  }
  else{
    mips another_mp;
    left -> compile(another_mp);
    mips tmp_mp;
    right -> compile(tmp_mp);
    callee_value_process(tmp_mp);
  }
}

// void argument_expression_list::translate(string& pyout) const{
//     debug(cname);
//     string a,b;
//     if(right != NULL){
//       left -> translate(a);
//       right -> translate(b);
//       pyout = a + ","+b;
//     }
//     else{
//       left -> translate(pyout);
//     }
// }

#endif
