#ifndef ast_parameter_list
#define ast_parameter_list

#include "ast.hpp"

// parameter_list
// 	: parameter_declaration                        {$$ = $1;}
// 	| parameter_list ',' parameter_declaration     {$$ = new parameter_list($1, $3);}
// 	;

class parameter_list : public astnode{
public:
  parameter_list(treeptr o, treeptr t){left = o; right = t;}
  ~parameter_list(){delete left; delete right;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  treeptr left;
  treeptr right;
  string cname = "parameter_list";
};

// void parameter_list::translate(string& pyout) const{
//   debug(cname);
//   string yi;
//   string er;
//   left -> translate(yi);
//   right -> translate(er);
//   pyout = yi + "," + er;
// }

#endif
