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
  virtual void translate(string& pyout)const override;
  ~init_declarator(){
    delete one;
    delete two;
  }
private:
  treeptr one = NULL;
  treeptr two = NULL;
  string cname = "init_declarator";
};

// void init_declarator::translate(string& pyout) const{
//   debug(cname);
//   string s1, s2;
//   one-> translate(s1);
//   two -> translate(s2);
//   pyout = s1 + '=' + s2;// + '\n';
// }


#endif
