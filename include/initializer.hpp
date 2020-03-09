#ifndef ast_initializer
#define ast_initializer

#include "ast.hpp"

// initializer
// 	: assignment_expression                  {$$ = $1;}
// 	| '{' initializer_list '}'               {$$ = new initializer(0, $2);}
// 	| '{' initializer_list ',' '}'           {$$ = new initializer(1, $2);}
// 	;

class initializer : public astnode{
public:
  initializer(int type_in, treeptr o){type_in = type; p = o;}
  ~initializer(){delete p;}
  inline void translate(string& pyout);
private:
  int type;
  treeptr p;
};

void initializer::translate(string& pyout){
    NotImplemented();
  }


#endif
