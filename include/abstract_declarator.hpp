#ifndef ast_abstract_declarator
#define ast_abstract_declarator

#include "ast.hpp"

// abstract_declarator
// 	: pointer                                        {$$ = $1;}
// 	| direct_abstract_declarator                     {$$ = $1;}
// 	| pointer direct_abstract_declarator             {$$ = new abstract_declarator($1, $2);}
// 	;

class abstract_declarator : public astnode {
public:
  abstract_declarator(treeptr o, treeptr t){left = o; right = t;}
  ~abstract_declarator(){delete left; delete right;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  treeptr left;
  treeptr right;
  string cname = "abstract_declarator";
};
// void abstract_declarator::compile(mips& mp)const
// {
//   left ->compile(mp);
//   mips another_mp;
//   right -> compile(another_mp);
// }
// void abstract_declarator::translate(string& pyout){
//     debug(cname);
//     NotImplemented();
// }



#endif
