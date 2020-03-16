#ifndef type_specifier_h
#define type_specifier_h
#include"ast.hpp"

// type_specifier
// 	: VOID   {$$ = new type_specifier(0); std::cout << "type_specifier void" << std::endl;}
// 	| CHAR   {$$ = new type_specifier(1); std::cout << "type_specifier char" << std::endl;}
// 	| SHORT   {$$ = new type_specifier(2); std::cout << "type_specifier short" << std::endl;}
// 	| INT   {$$ = new type_specifier(3); std::cout << "type_specifier int" << std::endl;}
// 	| LONG   {$$ = new type_specifier(4); std::cout << "type_specifier long 5" << std::endl;}
// 	| FLOAT   {$$ = new type_specifier(5); std::cout << "type_specifier float 6" << std::endl;}
// 	| DOUBLE   {$$ = new type_specifier(6); std::cout << "type_specifier double 7" << std::endl;}
// 	| SIGNED   {$$ = new type_specifier(7); std::cout << "type_specifier signed 8" << std::endl;}
// 	| UNSIGNED   {$$ = new type_specifier(8); std::cout << "type_specifier signed unsigned 9" << std::endl;}
// //	| struct_or_union_specifier   {$$ = new type_specifier("STRUCT");}
// //	| enum_specifier   {$$ = new type_specifier("ENUM");}
// 	| TYPE_NAME   {$$ = new type_specifier(9); std::cout << "type_name" << std::endl;}
// 	;

class type_specifier : public astnode{
public:
  type_specifier(int _type){
    type = _type;
  }
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp)const override;

private:
  int type;
  string cname = "type_specifier";
};

// void type_specifier::translate(string& pyout) const
// {
//   debug(cname);
//   //std::cout << "here is the type specifier. pyout is : "  << pyout << std::endl;
//   //skip, no type for python
// }


void type_specifier::compile(mips& mp)const
{
  debug(cname);
  //don't do anything yet?
  switch(type)
  {
    case 0:
    break;
    case 1:
    break;
    case 2:
    break;
    case 3:
    break;
    case 4:
    break;
  }
};



#endif
