#ifndef express_statement
#define express_statement
#include "ast.hpp"

// expression_statement
// 	: ';'    {$$ = new expression_statement(0);std::cerr << "expression_statement 0" << std::endl;}
// 	| expression ';'   {$$ = new expression_statement($1);std::cerr << "expression_statement 1" << std::endl;}
// 	;

class expression_statement : public statement{
 public:
  expression_statement(int _type):type(_type){};
  expression_statement(treeptr _ptr_expr):ptr_expr(_ptr_expr){};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  ~expression_statement(){
    delete ptr_expr;
  }
 private:
  int type;
  treeptr ptr_expr = NULL;
  string cname = "express_statement";
};



// void expression_statement::translate(string& pyout) const{
//   debug(cname);
//   //string tmp;
//   if(ptr_expr != NULL)
//   {
//     ptr_expr -> translate(pyout);
//   }
//   //if it is " ; ",we don't do anything, skip(not sure)
//   // ";"suggest a null statement, do nothing
// }



#endif
