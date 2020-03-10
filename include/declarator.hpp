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
  inline void translate(string& pyout)const;
  ~declarator(){
    delete ptr;
    delete direct_decla;
  }
private:
  treeptr ptr = NULL;
  treeptr direct_decla = NULL;
  string cname = "declarator";
};

void declarator :: translate(string& pyout) const{
  debug(cname);
  //std::cout << "declarator translate" << '\n';
  //skip for translation
}



#endif
