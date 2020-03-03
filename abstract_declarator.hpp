#ifndef ast_abstract_declarator
#define ast_abstract_declarator

#include "ast.hpp"

// abstract_declarator
// 	: pointer                                        {$$ = $1;}
// 	| direct_abstract_declarator                     {$$ = $1;}
// 	| pointer direct_abstract_declarator             {$$ = new abstract_declarator($1, $2);}
// 	;

class abstract_declarator : public declaration{
public:
  abstract_declarator(treeptr o, treeptr t){left = o; right = t;}
  ~abstract_declarator(){delete left; delete right;};
  void translate(string& pyout);
private:
  treeptr left;
  treeptr right;
};

void abstract_declarator::translate(string& pyout){
    NotImplemented();
  }
}

#endif
