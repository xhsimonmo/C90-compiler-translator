#ifndef direct_declarator_h
#define direct_declarator_h
#include"ast.hpp"

// direct_declarator
// 	: IDENTIFIER   {$$ = new direct_declarator(0,*$1);}
// 	| '(' declarator ')'  {$$ = new direct_declarator(1,$2);}
// 	| direct_declarator '[' constant_expression ']'  {$$ = new direct_declarator(2,$1,$3);}  array declaration
// 	| direct_declarator '[' ']'   {$$ = new direct_declarator(3,$1);}   array declaration
// 	| direct_declarator '(' parameter_type_list ')'  {$$ = new direct_declarator(4,$1,$3);}  function declaration
// 	| direct_declarator '(' identifier_list ')'  {$$ = new direct_declarator(5,$1,$3);} function declaration
// 	| direct_declarator '(' ')'   {$$ = new direct_declarator(6,$1);} function declaration C90 page 67
// 	;

class direct_declarator : public astnode{
public:
  direct_declarator(int _type,string _id):type(_type),id(_id){};
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
  switch (case) {
    case 0:
    pyout = id; // directly output IDENTIFIER, as python doesn't have type
    break;
    case 1:
    one->translate(pyout); // parenthsis does not matter in IDENTIFIER
    break;
    case 2:
    NotImplemented(); // no array
    break;
    case 3:
    NotImplemented();
    break;
    case 4:


  }
}



#endif
