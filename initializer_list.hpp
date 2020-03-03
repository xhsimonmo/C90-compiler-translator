#ifndef ast_initializer_list
#define ast_initializer_list

#include "ast.hpp"

// initializer_list
// 	: initializer                            {$$ = new initializer_list(0, $1);}
// 	| initializer_list ',' initializer       {$$ = new initializer_list(1, $1, $3);}
// 	;

class initializer_list : public declaration{
public:
  initializer_list(int type_in, treeptr o, treeptr t){type = type_in; left = o; right = t;}
  initializer_list(int type_in, treeptr o){type = type_in; left = o}
  ~initializer_list(){delete left; delete right;};
  void translate(string& pyout);
private:
  int type;
  treeptr left;
  treeptr right;
};

void initializer_list::translate(string& pyout){
  string l;
  string r;
  left->translate(l);
  right->translate(r);

  switch(type)
  {
    case 0:
    pyout = l;
    break;

    case 1:
    NotImplemented();
    break;
  }
}

#endif
