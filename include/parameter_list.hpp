#ifndef ast_parameter_list
#define ast_parameter_list

#include "ast.hpp"

// parameter_list
// 	: parameter_declaration                        {$$ = $1;}
// 	| parameter_list ',' parameter_declaration     {$$ = new parameter_list($1, $3);}
// 	;

class parameter_list : public declaration{
public:
  parameter_list(treeptr o, treeptr t){left = o; right = t;}
  ~parameter_list(){delete left; delete right;}
  void translate(string& pyout);
private:
  treeptr left;
  treeptr right;
};

void parameter_list::translate(string& pyout){
  string yi;
  string er;
  left -> translate(yi);
  right -> translate(er);
  pyout = left + "," + right;
}

#endif
