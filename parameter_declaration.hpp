#ifndef ast_parameter_list
#define ast_parameter_list

#include "ast.hpp"

// parameter_list
// 	: parameter_declaration                        {$$ = $1;}
// 	| parameter_list ',' parameter_declaration     {$$ = new parameter_list($1, $3);}
// 	;

class parameter_list : public declaration{
public:
  parameter_list(int type_in, treeptr o, treeptr t){type = type_in; left = o; right = t;}
  ~parameter_list(){delete left; delete right;};
  void translate(string& pyout);
private:
  int type;
  treeptr left;
  treeptr right;
};

void parameter_list::translate(string& pyout){
  string yi;
  string er;
  left -> translate(yi);
  right -> translate(er);
  switch(type)
  {
    case 0:
    pyout = right;

    case 1:
    NotImplemented();

    case 2:
    NotImplemented();
  }
}

#endif
