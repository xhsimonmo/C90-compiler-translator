#include "menu.hpp"

void unary_expression::compile(string& mp){
  switch(type)
  {
    case 0:
    ptr->compile(dst);
    mips.addi(dst, dst, "1");
    break;

    case 1:
    ptr->compile(dst);
    mips.addi(dst, dst, "-1");
    break;

    case 2:


  }

}


void function_definition::compile(mips& mp)
{
  // p_t->compile(declarator);
  p_f->compile(mp);

  string declarator = mp.info.func_name;
  declarator = declarator + ":";
  mpcode.push_back(declarator);
  add_frame();

  


}
