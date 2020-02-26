#ifndef ast.hpp
#define ast.hpp


#include <iostream>
#include <vector>

using namespace std;

// labeled_statement
// 	: IDENTIFIER ':' statement
// 	| CASE constant_expression ':' statement
// 	| DEFAULT ':' statement
// 	;

class labeled_statement : public statement{
public:
  labeled_statement();//default constructor
  ~labeled_statement(){
  };
private:

};

void labeled_statement::translate(){
  NotImplemented;
}

//no tranlation to python required?
