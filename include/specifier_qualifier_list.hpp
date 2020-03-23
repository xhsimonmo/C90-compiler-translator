#ifndef specifier_qualifier_list_h
#define specifier_qualifier_list_h
#include "ast.hpp"

// specifier_qualifier_list
// 	: type_specifier specifier_qualifier_list {$$ = new specifier_qualifier_list($1,$2);}
// 	| type_specifier  {$$ = $1}

class specifier_qualifier_list : public astnode{
public:
  specifier_qualifier_list(treeptr _spec, treeptr _list):spec(_spec),list(_list){};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  ~specifier_qualifier_list(){
    delete spec;
    delete list;
  }
private:
  treeptr spec = NULL;
  treeptr list = NULL;
  string cname = "specifier_qualifier_list";
};

// void specifier_qualifier_list::compile(mips& mp)const{
//   spec->compile(mp);
//   mips another_mp;
//   list ->compile(another_mp);
// }

// void specifier_qualifier_list::translate(string& pyout) const
// {
//   debug(cname);
//   //skip, no type for python
// }

#endif
