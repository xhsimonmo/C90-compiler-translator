#ifndef ast_type_name
#define ast_type_name

#include "ast.hpp"

// type_name
// 	: specifier_qualifier_list                       {$$ = $1;}
// 	| specifier_qualifier_list abstract_declarator   {$$ = new type_name();}
// 	;

class type_name : public declaration{
public:
  type_name(treeptr o, treeptr t){left = o; right = t;}
  ~type_name(){delete left; delete right;};
  void translate(string& pyout);
private:
  treeptr left;
  treeptr right;
};

void type_name::translate(string& pyout){
    NotImplemented();
  }
}

#endif
