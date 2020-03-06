#ifndef jump_statement_h
#define jump_statement_h

#include "ast.hpp"

// jump_statement
// 	: GOTO IDENTIFIER ';' ///no goto statement
// 	| CONTINUE ';'
// 	| BREAK ';'
// 	| RETURN ';' //return nothing is undefined in C90 standard
// 	| RETURN expression ';'
// 	;

class jump_statement : public statement{
public:
  jump_statement(int _type, string _id):type(_type),identifier(_id){};
  jump_statement(int _type, treeptr _ptr):type(_type),expre_ptr(_ptr){};
  void translate(string& pyout);
  ~jump_statement(){
    delete expre_ptr;
  }

private:
  int type;
  string identifier;
  treeptr expre_ptr;
};

void jump_statement::translate(string& pyout)
{
  string return_expression;
  switch (type) {
    case 4 ://return
    expre_ptr -> translate(return_expression);
    pyout = "return " + return_expression + "\n";
    break;
    
    default :
    NotImplemented();
  }
}



#endif
