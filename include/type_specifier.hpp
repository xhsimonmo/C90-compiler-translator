#ifndef type_specifier_h
#define type_specifier_h
#include"ast.hpp"

// type_specifier
// 	: VOID   {$$ = new type_specifier("VOID");}
// 	| CHAR   {$$ = new type_specifier("CHAR");}
// 	| SHORT   {$$ = new type_specifier("SHORT");}
// 	| INT   {$$ = new type_specifier("INT");}
// 	| LONG   {$$ = new type_specifier("LONG");}
// 	| FLOAT   {$$ = new type_specifier("FLOAT");}
// 	| DOUBLE   {$$ = new type_specifier("DOUBLE");}
// 	| SIGNED   {$$ = new type_specifier("SIGNED");}
// 	| UNSIGNED   {$$ = new type_specifier("UNSIGNED");}
// 	| struct_or_union_specifier   {$$ = new type_specifier("STRUCT");}
// 	| enum_specifier   {$$ = new type_specifier("ENUM");}
// 	| TYPE_NAME   {$$ = new type_specifier("TYPE_NAME");}
// 	;

class type_specifier : public astnode{
public:
  type_specifier(int _type){
    type = _type;
  }

private:
  int type;
};

void type_specifier::translate(string& pyout)
{
  //skip, no type for python
}




#endif
