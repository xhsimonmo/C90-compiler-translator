#ifndef parameter_declaration_h
#define parameter_declaration_h

#include "ast.hpp"

// parameter_declaration
// 	: declaration_specifiers declarator             {$$ = new parameter_declaration(0, $1, $2)}
// 	| declaration_specifiers abstract_declarator    {$$ = new parameter_declaration(1, $1, $2)}
// 	| declaration_specifiers/*喵喵喵*/                   {$$ = new parameter_declaration(2, $1)}
// 	;

class parameter_declaration : public astnode{
public:
  parameter_declaration(int type_in, treeptr o, treeptr t){type = type_in; left = o; right = t;}
  parameter_declaration(int type_in, treeptr o){type = type_in; left = o;}
  ~parameter_declaration(){delete left; delete right;}
  virtual void translate(string& pyout)const override;
private:
  int type;
  treeptr left = NULL;
  treeptr right = NULL;
  string cname = "parameter_declaration";
};

// void parameter_declaration::translate(string& pyout) const{
//   debug(cname);
//   string yi;
//   string er;
//   left -> translate(yi);
//   right -> translate(er);
//   switch(type)
//   {
//     case 0:
//     pyout = er;
//
//     case 1:
//     NotImplemented();
//
//     case 2:
//     NotImplemented();
//   }
// }

#endif
