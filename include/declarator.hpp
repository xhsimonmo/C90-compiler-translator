#ifndef declarator_h
#define declarator_h
#include "ast.hpp"

// declarator
// 	: pointer direct_declarator  {$$ = new declarator($1, $2);}
// 	| direct_declarator    {$$ = $1}
// 	;

class declarator : public astnode{
public:
  declarator(treeptr _ptr, treeptr _direct_decla):ptr(_ptr), direct_decla(_direct_decla){};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  ~declarator(){
    delete ptr;
    delete direct_decla;
  }
private:
  treeptr ptr = NULL;
  treeptr direct_decla = NULL;
  string cname = "declarator";
};

// void declarator::compile(mips&mp)const
// {
//     ptr ->compile(mp);
//     mips another_mp;
//     direct_decla -> compile(another_mp);
// }

// void declarator :: translate(string& pyout) const{
//   debug(cname);
//   //std::cout << "declarator translate" << '\n';
//   //skip for translation
// }



#endif
