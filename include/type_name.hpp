#ifndef ast_type_name
#define ast_type_name

#include "ast.hpp"

// type_name
// 	: specifier_qualifier_list                       {$$ = $1;}
// 	| specifier_qualifier_list abstract_declarator   {$$ = new type_name();}
// 	;

class type_name : public astnode{
public:
  type_name(treeptr o, treeptr t){left = o; right = t;}
  ~type_name(){delete left; delete right;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  treeptr left;
  treeptr right;
  string cname = "type_name";
};
// 
// void type_name::compile(mips& mp)const{
//   left ->compile(mp);
//   mips another_mp;
//   right ->compile(another_mp);
// }

// void type_name::translate(string& pyout) const{
//     debug(cname);
//     NotImplemented();
//   }


#endif
