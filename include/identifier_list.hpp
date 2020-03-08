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
  void translate(string& pyout);
private:
  treeptr ptr;
  string id;
};

void identifier_list::translate(string& pyout){
    NotImplemented();
  }


#endif
