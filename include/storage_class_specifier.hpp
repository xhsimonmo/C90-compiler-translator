#ifndef storage_class_specifier_h
#define storage_class_specifier_h

include "ast.hpp"

// storage_class_specifier
// 	: TYPEDEF  {$$ = new storage_class_specifier("TYPEDEF");}
// 	| EXTERN   {$$ = new storage_class_specifier("EXTERN");}

class storage_class_specifier : public declaration{
public:
  storage_class_specifier(int _type):type(_type){};
  ~storage_class_specifier(){}
  translate(string& pysource);
private:
  int type;
};

void storage_class_specifier::translate(string& pyout){
  NotImplemented(); // e.g typedef, so on... not in python
}
#endif
