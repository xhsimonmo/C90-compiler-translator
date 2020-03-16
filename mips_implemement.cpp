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
  //TODO: need to put return value in $2
  p_o->compile(mp);

  //finish function
  finish_frame();
}

void type_specifier::compile(mips& mp)const
{
  debug(cname);
  //don't do anything yet for type specifier, assume INT?
};

void external_declaration::compile(mips& mp)const
{
  debug(cname);
  //don't do anything yet
};

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
    //////??????

    case 4:
    //////??????


    case 5:
    break;

    case 6:
    //////??????

    break;

  }
}

void assignment_expression::compile(mips& mp)
{
  //no unary expression
  if(p_one == NULL)
  {
    p_five->compile(mp);
  }
  else
  {
    p_one->compile(mp);
    mips another_mp;
    p_five->compile(another_mp);

    switch(type)
    {
      case 0://=
      lw(3, another_mp.var_index, 30);
      nop();
      sw(3, mp.var_index, 30);
      break;

      case 1://"*="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      mult(2, 3);
      mflo(2);
      sw(2, mp.var_index, 30);
      break;

      case 2://"/="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      div(2, 3);
      mflo(2);
      sw(2, mp.var_index, 30);
      break;

      case 3://"%="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      div(2, 3);
      mfhi(2);
      sw(2, mp.var_index, 30);
      break;

      case 4://"+="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      add(2, 2, 3);
      sw(2, mp.var_index, 30);
      break;

      case 5://"-="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      sub(2, 2, 3);
      sw(2, mp.var_index, 30);
      break;

      case 6://"<<="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      sll(2, 2, 3);
      sw(2, mp.var_index, 30);
      break;

      case 7://">>="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      sra(2, 2, 3);
      sw(2, mp.var_index, 30);
      break;

      case 8://"&="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      and(2, 2, 3);
      sw(2, mp.var_index, 30);
      break;

      case 9://"^="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      xor(2, 2, 3);
      sw(2, mp.var_index, 30);
      break;

      case 10://"|="
      lw(2, mp.var_index, 30);
      lw(3, another_mp.var_index, 30);
      nop();
      (2, 2, 3);
      or(2, mp.var_index, 30);
      break;
    }

  }
}

void cast_expression::compile(mips& mp)
{
  if(ptr == NULL)
  {
    opt->compile(mp);
  }
  else
  {
    NotImplemented();
  }
}

void multiplicative_expression::compile(mips& mp)
{
  mul->compile(mp);
  mips another_mp;
  cast->compile(another_mp);

  case 1://"*"
  lw(2, mp.var_index, 30);
  lw(3, another_mp.var_index, 30);
  nop();
  mult(2, 3);
  mflo(2);
  sw(2, sp+4, 30);
  mp.var_index = sp + 4;
  break;

  case 2:
  lw(2, mp.var_index, 30);
  lw(3, another_mp.var_index, 30);
  nop();
  mult(2, 3);
  mflo(2);
  sw(2, sp+4, 30);
  mp.var_index = sp + 4;
  break;

  case 3:
  lw(2, mp.var_index, 30);
  lw(3, another_mp.var_index, 30);
  nop();
  mult(2, 3);
  mfhi(2);
  sw(2, sp+4, 30);
  mp.var_index = sp + 4;
  break;

}

void additive_expression::compile(mips& mp)
{
  add->compile(mp);
  mips another_mp;
  mul->compile(another_mp);

  case 1://"+"
  lw(2, mp.var_index, 30);
  lw(3, another_mp.var_index, 30);
  nop();
  add(2, 2, 3);
  sw(2, sp+4, 30);
  mp.var_index = sp + 4;
  break;

  case 2://"-"
  lw(2, mp.var_index, 30);
  lw(3, another_mp.var_index, 30);
  nop();
  sub(2, 2, 3);
  sw(2, sp+4, 30);
  mp.var_index = sp + 4;
  break;

}

void shift_expression::compile(mips& mp)
{
  l->compile(mp);
  mips another_mp;
  r->compile(another_mp);

  case 1://"<<"
  lw(2, mp.var_index, 30);
  lw(3, another_mp.var_index, 30);
  nop();
  sll(2, 2, 3);
  sw(2, sp+4, 30);
  mp.var_index = sp + 4;
  break;

  case 2://">>"
  lw(2, mp.var_index, 30);
  lw(3, another_mp.var_index, 30);
  nop();
  sra(2, 2, 3);
  sw(2, sp+4, 30);
  mp.var_index = sp + 4;
  break;

}

void unary_expression::compile(mips& mp)
{
  switch(type)
  {
    case 0:
    ptr->compile(mp);
    mips.addi(dst, dst, "1");
    break;

    case 1:
    ptr->compile(dst);
    mips.addi(dst, dst, "-1");
    break;

    case 2:


  }

}
