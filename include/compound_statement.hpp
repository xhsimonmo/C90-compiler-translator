#ifndef ast.hpp
#define ast.hpp


#include <iostream>
#include <vector>

using namespace std;

// compound_statement
// 	: '{' '}'
// 	| '{' statement_list '}'
// 	| '{' declaration_list '}'
// 	| '{' declaration_list statement_list '}'
// 	;

class compound_statement : public statement
{
public:
  compound_statement
}
