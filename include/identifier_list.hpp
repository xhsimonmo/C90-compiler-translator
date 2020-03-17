#ifndef ast_identifier_list
#define ast_identifier_list

#include "ast.hpp"

// identifier_list
// 	: IDENTIFIER                                     {$$ = new identifier_list(*$1);}
// 	| identifier_list ',' IDENTIFIER                 {$$ = new identifier_list($1, *$3);}
// 	;

class identifier_list : public astnode{
public:
  identifier_list(treeptr o, string _id){ptr = o; id = _id;}
  identifier_list(string _id){id = _id;}
  ~identifier_list(){delete ptr; }
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  treeptr ptr;
  string id;
  string cname = "identifier_list";
};

// void identifier_list::translate(string& pyout) const{
//   debug(cname);
//     NotImplemented();
//   }


#endif
