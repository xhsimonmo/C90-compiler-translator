#include "menu.hpp"
#include "ast.hpp"


void function_definition::compile(mips& mp)const
{
  // declarator;
  if(p_o != NULL){
      p_o->compile(mp);//compiler type specifier part; doesn't do anything yet? then add label, which is only known until compile direc_declarator
  }
  p_t-> compile(mp);
  //add label
  string declarator = mp.info.func_name;
  declarator = declarator + ":";
  mp.mpcode.push_back(declarator);

  //start function
  mp.add_frame();

  //compound statement
  p_f->compile(mp);

  //finish function
  mp.finish_frame();
}

void type_specifier::compile(mips& mp)const
{
  debug(cname);
  //don't do anything yet?
  switch(type)
  {
    case 0:
    break;
    case 1:
    break;
    case 2:
    break;
    case 3:
    break;
    case 4:
    break;
  }
};


void external_declaration::compile(mips& mp)const
{
  debug(cname);
  //don't do anything yet
};

void compound_statement::compile(mips& mp)const{
  debug(cname);
  //dont do things yet;
  switch (type) {
    case 0:
    break;
    case 1:
    left -> compile(mp);
    break;
    case 2:
    left -> compile(mp);
    break;
    case 3:
    left -> compile(mp);
    right -> compile(mp);
    break;
  }
}

void direct_declarator::compile(mips& mp)const
{
  switch(type)
  {
    case 0:
    mp.info.func_name = id;
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
      if(mp.info.result.empty())
      {
        mp.lw(3, another_mp.info.var_index, 30); // TODO make var_index extern?
      } // we have an identifier not a number
      else{
        mp.li(3, another_mp.info.result);//got a number
      }

      nop();
      sw(3, mp.temp_result.var_index, 30);
      break;

      case 1://"*="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      mult(2, 3);
      mflo(2);
      sw(2, mp.temp_result.var_index, 30);
      break;

      case 2://"/="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      div(2, 3);
      mflo(2);
      sw(2, mp.temp_result.var_index, 30);
      break;

      case 3://"%="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      div(2, 3);
      mfhi(2);
      sw(2, mp.temp_result.var_index, 30);
      break;

      case 4://"+="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      add(2, 2, 3);
      sw(2, mp.temp_result.var_index, 30);
      break;

      case 5://"-="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      sub(2, 2, 3);
      sw(2, mp.temp_result.var_index, 30);
      break;

      case 6://"<<="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      sll(2, 2, 3);
      sw(2, mp.temp_result.var_index, 30);
      break;

      case 7://">>="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      sra(2, 2, 3);
      sw(2, mp.temp_result.var_index, 30);
      break;

      case 8://"&="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      and(2, 2, 3);
      sw(2, mp.temp_result.var_index, 30);
      break;

      case 9://"^="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      xor(2, 2, 3);
      sw(2, mp.temp_result.var_index, 30);
      break;

      case 10://"|="
      lw(2, mp.temp_result.var_index, 30);
      lw(3, another_mp.temp_result.var_index, 30);
      nop();
      (2, 2, 3);
      or(2, mp.temp_result.var_index, 30);
      break;
    }

  }
}

void cast_expression::compile(mips& mp) const
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

void multiplicative_expression::compile(mips& mp) const
{
  mul->compile(mp);
  mips another_mp;
  cast->compile(another_mp);

  case 1://"*"
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  mult(2, 3);
  mflo(2);
  sw(2, sp+4, 30);
  mp.temp_result.var_index = sp + 4;
  break;

  case 2:
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  mult(2, 3);
  mflo(2);
  sw(2, sp+4, 30);
  mp.temp_result.var_index = sp + 4;
  break;

  case 3:
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  mult(2, 3);
  mfhi(2);
  sw(2, sp+4, 30);
  mp.temp_result.var_index = sp + 4;
  break;

}

void additive_expression::compile(mips& mp) const
{
  add->compile(mp);
  mips another_mp;
  mul->compile(another_mp);

  case 1://"+"
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  add(2, 2, 3);
  sw(2, sp+4, 30);
  mp.temp_result.var_index = sp + 4;
  break;

  case 2://"-"
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  sub(2, 2, 3);
  sw(2, sp+4, 30);
  mp.temp_result.var_index = sp + 4;
  break;

}

void shift_expression::compile(mips& mp) const
{
  l->compile(mp);
  mips another_mp;
  r->compile(another_mp);

  case 1://"<<"
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  sll(2, 2, 3);
  sw(2, sp+4, 30);
  mp.temp_result.var_index = sp + 4;
  break;

  case 2://">>"
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  sra(2, 2, 3);
  sw(2, sp+4, 30);
  mp.var_index = sp + 4;
  break;

}

void unary_expression::compile(mips& mp) const
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

// selection_statement
// 	: IF '(' expression ')' statement
// 	| IF '(' expression ')' statement ELSE statement
// 	| SWITCH '(' expression ')' statement //no translation for switch
// 	;
void selection_statement::compile(mips& mp) const
{
  string below_if = "Selection" + to_string(labelcounter);//make label
  labelcounter++;
  mips expre_mp;
  expre_ptr->compile(expre_mp);

  string else_label = "Selection" + to_string(labelcounter);//label when else start
  labelcounter++;

  switch(type)
  {
    case 0:
    lw(2, expre_mp.temp_result.result_index, 30);//store expression result in r2
    beq(2, 0, below_if);//if false, skip if statement, jump to the content below if statement;
    nop();
    //then make the if statement(if is true)
    mips sta_mp;
    ifsta->compile(sta_mp);
    add_label(below_if);
    break;

    case 1:
    lw(2, expre_mp.temp_result.result_index, 30);//store expression result in r2
    beq(2, 0, else_label);//if false f=go to else
    nop();
    //then make the if statement(if is true)
    mips sta_mp;
    ifsta->compile(sta_mp);
    b(below_if);

    //else statement
    add_label(else_label);
    mips s_mp;
    s_mp->compile(s_mp);
    add_label(below_if);
    break;

    case 2:
    //TODO:do we need that???
    break;


  }





}
