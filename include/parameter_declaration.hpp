#ifndef ast_identifier_list
#define ast_identifier_list

#include "ast.hpp"

// identifier_list
// 	: IDENTIFIER                                     {$$ = $1;}
// 	| identifier_list ',' IDENTIFIER                 {$$ = new identifier_list($1, $3);}
// 	;
  
class identifier_list : public declaration{
public:
  identifier_list(int type_in, treeptr o, treeptr t){type = type_in; left = o; right = t;}
  ~identifier_list(){delete left; delete right;};
  void translate(string& pyout);
private:
  int type;
  treeptr left;
  treeptr right;
};

void identifier_list::translate(string& pyout){
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
