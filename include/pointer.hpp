#ifndef pointer_h
#define pointer_h
#include "ast.hpp"

// pointer
// 	: '*'  {$$ = new pointer(0);}
// 	| '*' pointer {$$ = new pointer(1,$1);}

class pointer : public astnode{
public:
  pointer(int _type):type(_type){};
  pointer(int _type, treeptr _ptr):type(_type),ptr(_ptr){};
  inline void translate(string& pyout);
  ~pointer(){
    delete ptr;
  }
private:
  int type;
  treeptr ptr = NULL;
};

void pointer::translate(string& pyout){
  NotImplemented();
}

#endif
