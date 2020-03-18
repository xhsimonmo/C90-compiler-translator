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

void assignment_expression::compile(mips& mp)const
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

      mp.nop();
      mp.sw(3, mp.info.var_index, 30);
      break;

      case 1://"*="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      mp.mult(2, 3);
      mp.mflo(2);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 2://"/="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      div(2, 3);
      mp.mflo(2);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 3://"%="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      div(2, 3);
      mp.mfhi(2);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 4://"+="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      mp.add(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 5://"-="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      mp.sub(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 6://"<<="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      mp.sll(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 7://">>="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      mp.sra(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 8://"&="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      mp._and(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 9://"^="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      mp._xor(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 10://"|="
      mp.lw(2, mp.info.var_index, 30);
      mp.lw(3, another_mp.info.var_index, 30);
      mp.nop();
      (2, 2, 3);
      mp._or(2, mp.info.var_index, 30);
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
  switch (type) {
  case 1://"*"
  mp.lw(2, mp.info.var_index, 30);
  mp.lw(3, another_mp.info.var_index, 30);
  mp.nop();
  mp.mult(2, 3);
  mp.mflo(2);
  mp.sw(2, sp+4, 30);
  mp.info.var_index = sp + 4;
  break;

  case 2:
  mp.lw(2, mp.info.var_index, 30);
  mp.lw(3, another_mp.info.var_index, 30);
  mp.nop();
  mp.mult(2, 3);
  mp.mflo(2);
  mp.sw(2, sp+4, 30);
  mp.info.var_index = sp + 4;
  break;

  case 3:
  mp.lw(2, mp.info.var_index, 30);
  mp.lw(3, another_mp.info.var_index, 30);
  mp.nop();
  mp.mult(2, 3);
  mp.mfhi(2);
  mp.sw(2, sp+4, 30);
  mp.info.var_index = sp + 4;
  break;

  }
}

void additive_expression::compile(mips& mp) const
{
  add->compile(mp);
  mips another_mp;
  mul->compile(another_mp);
  switch (type) {
  case 1://"+"
  mp.lw(2, mp.info.var_index, 30);
  mp.lw(3, another_mp.info.var_index, 30);
  mp.nop();
  mp.add(2, 2, 3);
  mp.sw(2, sp+4, 30);
  mp.info.var_index = sp + 4;
  break;

  case 2://"-"
  mp.lw(2, mp.info.var_index, 30);
  mp.lw(3, another_mp.info.var_index, 30);
  mp.nop();
  mp.sub(2, 2, 3);
  mp.sw(2, sp+4, 30);
  mp.info.var_index = sp + 4;
  break;
  }
}

void shift_expression::compile(mips& mp) const
{
  l->compile(mp);
  mips another_mp;
  r->compile(another_mp);
  switch(type){
  case 1://"<<"
  mp.lw(2, mp.info.var_index, 30);
  mp.lw(3, another_mp.info.var_index, 30);
  mp.nop();
  mp.sll(2, 2, 3);
  mp.sw(2, sp+4, 30);
  mp.info.var_index = sp + 4;
  break;

  case 2://">>"
  mp.lw(2, mp.info.var_index, 30);
  mp.lw(3, another_mp.info.var_index, 30);
  mp.nop();
  mp.sra(2, 2, 3);
  mp.sw(2, sp+4, 30);
  mp.info.var_index = sp + 4;
  break;
  }
}

void unary_expression::compile(mips& mp) const
{
  switch(type)
  {
    case 0:
    ptr->compile(mp);
    mp.addi(dst, dst, "1");
    break;

    case 1:
    ptr->compile(dst);
    mp.addi(dst, dst, "-1");
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
  string below_if = "Selection" + to_string(mp.labelcounter);//make label
  mp.labelcounter++;
  mips expre_mp;
  expre_ptr->compile(expre_mp);

  string else_label = "Selection" + to_string(mp.labelcounter);//label when else start
  mp.labelcounter++;
  mips sta_mp;
  switch(type)
  {
    case 0:
    mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
    mp.beq(2, 0, below_if);//if false, skip if statement, jump to the content below if statement;
    mp.nop();
    //then make the if statement(if is true)
    // mips sta_mp;
    ifsta->compile(sta_mp);
    mp.add_label(below_if);
    break;

    case 1:
    mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
    mp.beq(2, 0, else_label);//if false f=go to else
    mp.nop();
    //then make the if statement(if is true)
    // mips sta_mp;
    ifsta->compile(sta_mp);
    b(below_if);

    //else statement
    mp.add_label(else_label);
    mips s_mp;
    s_mp->compile(s_mp);
    mp.add_label(below_if);
    break;

    case 2:
    //TODO:do we need that???
    break;


  }


}

void jump_statement::compile(mips& mp) const {
  switch (type) {
    case 0:
    NotImplemented();
    break;
    case 1:
    NotImplemented();
    break;
    case 2:
    NotImplemented();
    break;
    case 3: // simply "return; " gives error
    NotImplemented();
    break;
    case 4:
    mips mp_tmp;
    expre_ptr -> compile(mp_tmp);
    mp.li(2,mp_tmp.info.result)
    break;
  }
}

void primary_expression :: compile(mips& mp) const{
  debug(cname);
  switch (type) {
    case 0: // got IDENTIFIER
    // mp.var_index = mp.var_index + 4;
    // mp.func_variables.push_back(element,mp.var_index );
    //mp.var_index = mp.var_index + 4;
    mp.info.func_name = element;//update func_name, name of a variable
    mp.info.var_index = mp.find_variable(element);//fetch address of the variable
    break;

    case 1:

    mp.info.result = element;
    //mp.li(2,element);//element is the value to stored
    //mp.sw(2,mp.var_index,30)
    //mp.var_index = mp.var_index + 4;
    break;

    case 2:
    NotImplemented();
    break;

    case 3:
    expre_ptr -> compile(mp);
    break;

  }
}
