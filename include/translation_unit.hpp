#ifndef ast_translation_unit
#define ast_translation_unit

#include "ast.hpp"

class translation_unit : public definition{
public:
  translation_unit(treeptr o, treeptr t){p_yi = o; p_er = t;}
  ~translation_unit(){delete p_yi; delete p_er;};
  void translate(string& pyout);
private:
  treeptr p_yi;
  treeptr p_er;
};

void translation_unit::translate(string& pyout){
  string unit;
  string declaration;
  p_yi->translate(unit);
  p_er->translate(declaration);

  pyout = unit + "/n" + declaration;
}

#endif
