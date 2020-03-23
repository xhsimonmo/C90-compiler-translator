#ifndef storage_class_specifier_h
#define storage_class_specifier_h

#include "ast.hpp"

// storage_class_specifier
// 	: TYPEDEF  {$$ = new storage_class_specifier(0); std::cerr << "storage_class_specifier typedef 0 " << std::endl;}
// 	| EXTERN   {$$ = new storage_class_specifier(1);  std::cerr << "storage_class_specifier typedef 1 " << std::endl;}

class storage_class_specifier : public astnode{
public:
  storage_class_specifier(int _type):type(_type){};
  ~storage_class_specifier(){}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  string cname = "storage_class_specifier";
};

// void storage_class_specifier::compile(mips& mp)const{
//    debug(cname);
//    if(type == 0){
//      std::cerr << "TYDEF!" << '\n';
//    }
// }

//
// void storage_class_specifier::translate(string& pyout) const{
//   debug(cname);
//   NotImplemented(); // e.g typedef, so on... not in python
// }
#endif
