#include "menu.hpp"


void function_definition::compile(mips& mp)
{
  // declarator;
  p_f->compile(mp);

  //add label
  string declarator = mp.info.func_name;
  declarator = declarator + ":";
  mpcode.push_back(declarator);

  //start function
  add_frame();

  //compound statement
  p_o->compile(mp);

  //finish function
  finish_frame();
}

void direct_declarator::compile(mips& mp)
{
  switch(type)
  {
    case 0:
    mp.info.func_type = id;
    break;

    case 1:
    one->compile(mp);
    break;

    case 2:
    break;

    case 3:
    /////???????

    case 4:
    break;

    case 5:
    one->compile(mp);
    ////?????????

    break;

  }



}

void unary_expression::compile(mips& mp)
{
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
