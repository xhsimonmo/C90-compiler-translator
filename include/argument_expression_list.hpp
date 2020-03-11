#ifndef ast_argument_expression_list
#define ast_argument_expression_list

#include "ast.hpp"

// argument_expression_list
// 	: assignment_expression                                  {$$ = $1;}
// 	| argument_expression_list ',' assignment_expression     {$$ = new argument_expression_list($1, $3);}
// 	;

class argument_expression_list : public expression{
public:
  argument_expression_list(treeptr o, treeptr t){ left = o; right = t;}
  ~argument_expression_list(){delete left; delete right;}
  virtual void translate(string& pyout)const;
private:
  //int type;
  treeptr left;
  treeptr right;
  string cname = "argument_expression_list";
};

// void argument_expression_list::translate(string& pyout){
//     debug(cname);
//     NotImplemented();
// }

#endif
