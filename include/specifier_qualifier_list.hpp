#ifndef specifier_qualifier_list_h
#define specifier_qualifier_list_h
#include "ast.hpp"

// specifier_qualifier_list
// 	: type_specifier specifier_qualifier_list {$$ = new specifier_qualifier_list($1,$2);}
// 	| type_specifier  {$$ = $1}

class specifier_qualifier_list : public astnode{
public:
  specifier_qualifier_list(treeptr _spec, treeptr _list):spec(_spec),list(_list){};
  inline void translate(string& pyout);
  ~specifier_qualifier_list(){
    delete spec;
    delete list;
  }
private:
  treeptr spec = NULL;
  treeptr list = NULL;
};

void specifier_qualifier_list::translate(string& pyout)
{
  //skip, no type for python
}

#endif
