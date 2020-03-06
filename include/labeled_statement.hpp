#ifndef labeled_statement_h
#define labeled_statement_h

#include "ast.hpp"

// labeled_statement
// 	: IDENTIFIER ':' statement
// 	| CASE constant_expression ':' statement
// 	| DEFAULT ':' statement
// 	;

class labeled_statement : public statement{
public:
  labeled_statement(int _type, treeptr _one):type(_type),one(_one){};
  labeled_statement(int _type, treeptr _one, treeptr _two):type(_type),one(_one),two(_two){};
  void translate(string& pyout);
  ~labeled_statement(){
    delete one;
    delete two;
  };
private:
  int type;
  treeptr one = NULL;
  treeptr two = NULL;
};

void labeled_statement::translate(string& pyout){
  NotImplemented();
}

//no tranlation to python required?

#endif
