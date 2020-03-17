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
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  ~labeled_statement(){
    delete one;
    delete two;
  };
private:
  int type;
  treeptr one = NULL;
  treeptr two = NULL;
  string cname = "labeled_statement";
};

// void labeled_statement::translate(string& pyout) const{
//   debug(cname);
//   NotImplemented();
// }

//no tranlation to python required?

#endif
