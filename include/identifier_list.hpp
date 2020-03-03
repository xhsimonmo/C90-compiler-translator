#ifndef ast_identifier_list
#define ast_identifier_list

#include "ast.hpp"

// identifier_list
// 	: IDENTIFIER                                     {$$ = $1;}
// 	| identifier_list ',' IDENTIFIER                 {$$ = new identifier_list($1, $3);}
// 	;

class identifier_list : public declaration{
public:
  identifier_list(treeptr o, treeptr t){left = o; right = t;}
  ~identifier_list(){delete left; delete right;};
  void translate(string& pyout);
private:
  treeptr left;
  treeptr right;
};

void identifier_list::translate(string& pyout){
    NotImplemented();
  }
}

#endif
