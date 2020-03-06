#ifndef express_statement
#define express_statement
#include "ast.hpp"

// expression_statement
// 	: ';'
// 	| expression ';'
// 	;

class expression_statement : public statement{
 public:
  expression_statement(int _type):type(_type){};
  expression_statement(treeptr _ptr_expr):ptr_expr(_ptr_expr){};
  void translate(string& pyout);
  ~expression_statement(){
    delete ptr_expr;
  }
 private:
  int type;
  treeptr ptr_expr = NULL;
};

void expression_statement::translate(string& pyout){
  //string tmp;
  if(ptr_expr != NULL)
  {
    ptr_expr -> translate(pyout);
  }
  //if it is " ; ",we don't do anything, skip(not sure)
  // ";"suggest a null statement, do nothing
}



#endif
