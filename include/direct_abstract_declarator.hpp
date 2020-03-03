#ifndef ast_direct_abstract_declarator
#define ast_direct_abstract_declarator

#include "ast.hpp"

// direct_abstract_declarator
// 	: '(' abstract_declarator ')'                                {$$ = $2;}
// 	| '[' ']'                                                    {$$ = new direct_abstract_declarator(0, $2);}
// 	| '[' constant_expression ']'                                {$$ = new direct_abstract_declarator(1, $2);}
// 	| direct_abstract_declarator '[' ']'                         {$$ = new direct_abstract_declarator(2, $1);}
// 	| direct_abstract_declarator '[' constant_expression ']'     {$$ = new direct_abstract_declarator(3, $1, $3);}
// 	| '(' ')'                                                    {$$ = new direct_abstract_declarator(4, $2);}
// 	| '(' parameter_type_list ')'                                {$$ = new direct_abstract_declarator(5, $2);}
// 	| direct_abstract_declarator '(' ')'                         {$$ = new direct_abstract_declarator(6, $1);}
// 	| direct_abstract_declarator '(' parameter_type_list ')'     {$$ = new direct_abstract_declarator(7, $1, $3);}
// 	;

class direct_abstract_declarator : public declaration{
public:
  direct_abstract_declarator(int type_in, treeptr o, treeptr t){type = type_in; left = o; right = t;}
  ~direct_abstract_declarator(){delete left; delete right;};
  void translate(string& pyout);
private:
  int type;
  treeptr left;
  treeptr right;
};

void direct_abstract_declarator::translate(string& pyout){
  NotImplemented();
}

#endif