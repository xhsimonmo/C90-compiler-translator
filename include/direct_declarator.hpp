#ifndef direct_declarator_h
#define direct_declarator_h
#include"ast.hpp"

// direct_declarator
// 	: IDENTIFIER   {$$ = new direct_declarator(*$1);}
// 	| '(' declarator ')'  {$$ = new direct_declarator(1,$2);}
// 	| direct_declarator '[' constant_expression ']'  {$$ = new direct_declarator(2,$1,$3);}
// 	| direct_declarator '[' ']'   {$$ = new direct_declarator(3,$1);}
// 	| direct_declarator '(' parameter_type_list ')'  {$$ = new direct_declarator(4,$1,$3);}
// 	| direct_declarator '(' identifier_list ')'  {$$ = new direct_declarator(5,$1,$3);}
// 	| direct_declarator '(' ')'   {$$ = new direct_declarator(6,$1);}
// 	;

class direct_declarator : public astnode{
public:
  direct_declarator(string _id):id(_id){};
  direct_declarator(int _type, treeptr _one):type(_type),one(_one){};
  direct_declarator(int _type, treeptr _one, treeptr _two):type(_type),one(_one),two(_two){};
  ~direct_declarator(){
    delete one;
    delete two;
  }
private:
  string id;
  int type;
  treeptr one = NULL;
  treeptr two = NULL;
};

void direct_declarator::translate(string& pyout){
  
}



#endif
