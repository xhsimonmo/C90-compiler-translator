#ifndef ast_translation_unit
#define ast_translation_unit

#include "ast.hpp"

// translation_unit
// 	: external_declaration                     {g_root = $1;std::cout << " translation_unit 1" << std::endl;}
// 	| translation_unit external_declaration    {std::cout << "translation_unit 2" << std::endl;g_root = new translation_unit($1, $2);}
// 	;

class translation_unit : public definition{
public:
  translation_unit(treeptr o, treeptr t){p_yi = o; p_er = t;}
  translation_unit(treeptr o){p_yi = o;}
  ~translation_unit(){delete p_yi; delete p_er;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  treeptr p_yi = NULL;
  treeptr p_er = NULL;
  string cname = "translation_unit";
};

// void translation_unit::translate(string& pyout) const{
//   debug(cname);
//   string unit;
//   string declaration;
//   if(p_er != NULL){
//     std::cerr << "enter translation_unit left" << '\n';
//     p_yi->translate(unit);
//     std::cerr << "finish left of translation_unit" << '\n';
//     p_er->translate(declaration);
//     pyout = unit + "\n" + declaration;
//   }
//   else{
//     p_yi->translate(unit);
//     pyout = unit + "\n" ;
//   }
// }

#endif
