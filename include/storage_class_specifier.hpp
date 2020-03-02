#ifndef storage_class_specifier_h
#define storage_class_specifier_h

include "ast.hpp"

class storage_class_specifier : public declaration{
public:
  storage_class_specifier(string _type):type(_type){};
  ~storage_class_specifier(){};
  translate(string& pysource);
private:
  string type;
};

void storage_class_specifier::translate(string& pyout){
  NotImplemented();
}
#endif
