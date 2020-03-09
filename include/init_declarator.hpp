#ifndef init_declarator_h
#define init_declarator_h
#include"ast.hpp"

// init_declarator
// 	: declarator   {$$ = $1}
// 	| declarator '=' initializer   {$$ = new init_declarator($1,$2);}
// 	;

class init_declarator : public astnode{
public:
  init_declarator(treeptr _one, treeptr _two):one(_one),two(_two){};
  inline void translate(string& pyout);
  ~init_declarator(){
    delete one;
    delete two;
  }
private:
  treeptr one = NULL;
  treeptr two = NULL;
};

void init_declarator::translate(string& pyout){
  string s1, s2;
  one-> translate(s1);
  two -> translate(s2);
  pyout = s1 + '=' + s2 + '\n';
}


#endif
