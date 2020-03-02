#ifndef init_declarator_list_h
#define init_declarator_list_h
#include"ast.hpp"

// init_declarator_list
// 	: init_declarator   {$$ = $1}
// 	| init_declarator_list ',' init_declarator   {$$ = new init_declarator_list($1,$2);}
// 	;

class init_declarator_list : public declaration{
public:
  init_declarator_list(treeptr _one, treeptr _two):one(_one),two(_two){};
  ~init_declarator_list(){
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
  pyout = s1 + '\n' + s2 + '\n';
}


#endif
