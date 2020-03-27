#ifndef type_specifier_h
#define type_specifier_h
#include"ast.hpp"

// type_specifier
// 	: VOID   {$$ = new type_specifier(0); std::cerr << "type_specifier void" << std::endl;}
// 	| CHAR   {$$ = new type_specifier(1); std::cerr << "type_specifier char" << std::endl;}
// 	| SHORT   {$$ = new type_specifier(2); std::cerr << "type_specifier short" << std::endl;}
// 	| INT   {$$ = new type_specifier(3); std::cerr << "type_specifier int" << std::endl;}
// 	| LONG   {$$ = new type_specifier(4); std::cerr << "type_specifier long 5" << std::endl;}
// 	| FLOAT   {$$ = new type_specifier(5); std::cerr << "type_specifier float 6" << std::endl;}
// 	| DOUBLE   {$$ = new type_specifier(6); std::cerr << "type_specifier double 7" << std::endl;}
// 	| SIGNED   {$$ = new type_specifier(7); std::cerr << "type_specifier signed 8" << std::endl;}
// 	| UNSIGNED   {$$ = new type_specifier(8); std::cerr << "type_specifier signed unsigned 9" << std::endl;}
// //	| struct_or_union_specifier   {$$ = new type_specifier("STRUCT");}
// 	| ENUM   {$$ = new type_specifier(9); std::cerr << "enum" << std::endl;}
// 	| TYPE_NAME   {$$ = new type_specifier(10); std::cerr << "type_name" << std::endl;}
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


// void type_specifier::compile(mips& mp)const
// {
//   debug(cname);
//   //don't do anything yet?
//   switch(type)
//   {
//     case 0:
//     mp.info.func_type = "void";
//     break;
//     case 1:
//     mp.info.func_type = "char";
//     break;
//     case 2:
//     mp.info.func_type = "short";
//     break;
//     case 3:
//     mp.info.func_type = "int";
//     break;
//     case 4:
//     mp.info.func_type = "long";
//     break;
//     case 5:
//     mp.info.func_type = "float";
//     break;
//     case 6:
//     mp.info.func_type = "double";
//     break;
//     case 7:
//     mp.info.func_type = "signed";
//     break;
//     case 8:
//     mp.info.func_type = "unsigned";
//     break;
//     case 9:
//     mp.info.func_type = "enum";
//     break;
//     case 10:
//     mp.info.func_type = "type_name";
//     break;
//   }
// };


// void type_specifier::translate(string& pyout) const
// {
//   debug(cname);
//   //std::cout << "here is the type specifier. pyout is : "  << pyout << std::endl;
//   //skip, no type for python
// }

#endif
