#ifndef ast_translation_unit
#define ast_translation_unit

#include "ast.hpp"

class translation_unit : public definition{
public:
  translation_unit(treeptr o, treeptr t){p_yi = o; p_er = t;}
  ~translation_unit(){delete p_yi; delete p_er;}
  virtual void translate(string& pyout)const override;
private:
  treeptr p_yi;
  treeptr p_er;
  string cname = "translation_unit";
};

// void translation_unit::translate(string& pyout) const{
//   debug(cname);
//   std::cout << "In translation unit->translate " << std::endl;
//   string unit;
//   string declaration;
//   std::cout << "inside translation unit" << '\n';
//   p_yi->translate(unit);
//   p_er->translate(declaration);
//
//   pyout = unit + "/n" + declaration;
// }

#endif
