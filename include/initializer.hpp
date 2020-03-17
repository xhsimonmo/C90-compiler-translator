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
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr p;
  string cname = "initializer";
};

// void initializer::translate(string& pyout) const{
//     debug(cname);
//     NotImplemented();
//   }


#endif
