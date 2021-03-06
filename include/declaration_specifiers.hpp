#ifndef declaration_specifiers_h
#define declaration_specifiers_h
#include"ast.hpp"

// declaration_specifiers
// 	: storage_class_specifier    {$$ = $1}
// 	| storage_class_specifier declaration_specifiers   {$$ = new declaration_specifiers($1,$2);}
// 	| type_specifier   {$$ = $1}
// 	| type_specifier declaration_specifiers    {$$ = new declaration_specifiers($1,$2);}

class declaration_specifiers : public astnode{
public:
  declaration_specifiers(treeptr _one, treeptr _two):one(_one),two(_two){};
  virtual void translate(string& pyout)const override;
virtual void compile(mips& mp) const override;
  ~declaration_specifiers(){
    delete one;
    delete two;
  }
private:
  treeptr one = NULL;
  treeptr two = NULL;
  string cname = "declaration_specifiers";
};

// void declaration_specifiers::compile(mips& mp)const
// {
//   one ->compile(mp);
//   mips another_mp;
//   two ->compile(another_mp);
// }

// void declaration_specifiers::translate(string& pyout)const{
//   debug(cname);
//
//   //for struct, skip for translation
//   //translation would not be requied here
// }


#endif
