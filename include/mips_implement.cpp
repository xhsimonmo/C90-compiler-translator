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
  mpcode.push_back(declarator);

  //make a new vector for mips code when start a new frame_stack
  vector<string>mips_code;
  mpcode_collection.push_back(mips_code);
  //start function
  add_frame(declarator, mips_code);

  //compound statement
  p_f->compile(mp);

  //finish function
  finish_frame(mips_code);
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

void compound_statement::compile(mips& mp)const{
  debug(name);
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





void direct_declarator::compile(mips& mp)
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
    p_five->compile(another_mp); another_mp->b:24


    switch(type)
    {
      case 0://=   a=b -> int a = 2; int b = 3; mp
      lw(3, another_mp.temp_result.var_index, 30);//b
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
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  mult(2, 3);
  mflo(2);
  sw(2, mp.temp_result.var_index, 30);//load to a's stack position
  break;

  case 2:
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  mult(2, 3);
  mflo(2);
  sw(2, mp.temp_result.var_index, 30);//load to a's stack position
  break;

  case 3:
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  mult(2, 3);
  mfhi(2);
  sw(2, mp.temp_result.var_index, 30);//load to a's stack position
  break;

}

void additive_expression::compile(mips& mp)
{
  add->compile(mp);
  mips another_mp;
  mul->compile(another_mp);

  case 1://"+"
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  add(2, 2, 3);
  sw(2, mp.temp_result.var_index, 30);//load to a's stack position
  break;

  case 2://"-"
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  sub(2, 2, 3);
  sw(2, mp.temp_result.var_index, 30);//load to a's stack position
  break;

}

void shift_expression::compile(mips& mp)
{
  l->compile(mp);
  mips another_mp;
  r->compile(another_mp);

  case 1://"<<"
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  sll(2, 2, 3);
  sw(2, mp.temp_result.var_index, 30);//load to a's stack position
  break;

  case 2://">>"
  lw(2, mp.temp_result.var_index, 30);
  lw(3, another_mp.temp_result.var_index, 30);
  nop();
  sra(2, 2, 3);
  sw(2, mp.temp_result.var_index, 30);//load to a's stack position
  break;

}

// void unary_expression::compile(mips& mp)
// {
//   switch(type)
//   {
//     case 0:
//     ptr->compile(mp);
//     mips.addi(dst, dst, "1");
//     break;
//
//     case 1:
//     ptr->compile(dst);
//     mips.addi(dst, dst, "-1");
//     break;
//
//     case 2:
//
//   }
// }

void selection_statement::compile(mips& mp)
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


  //     : WHILE '(' expression ')' statement
  //     | DO statement WHILE '(' expression ')' ';'
  //     | FOR '(' expression_statement expression_statement ')' statement
  //     | FOR '(' expression_statement expression_statement expression ')' statement
  //     ;

  void iteration_statement::compile(mips& mp)const{

    string condition = "condition" + to_string(labelcounter);
    labelcounter++;
    mips cond_expr;

    string statement = "statement" + to_string(labelcounter);
    labelcounter++;
    mips state_expr;

    string for_s1 = "for_state" + to_string(labelcounter);
    labelcounter++;
    mips for_state1;//san

    string for_s2 = "for_state" + to_string(labelcounter);
    labelcounter++;
    mips for_state2;//si


    switch(type)
    {
      case 0:
      b(condition);
      nop();

      add_label(statement);
      er->compile(state_expr);//get statement

      add_label(condition);
      yi->compile(cond_expr);//get conidtion expression
      lw(2, cond_expr.temp_result.result_index, 30);//store expression result in r2
      bne(2, 0, statement);//if true go to statement
      nop();

      case 1://same as case 0, but condition and statement are reversed.
      b(statement);
      nop();

      add_label(condition);
      yi->compile(cond_expr);

      add_label(statement);
      er->compile(state_expr);
      lw(2, state_expr.temp_result.result_index, 30);//store expression result in r2
      bne(2, 0, condition);//if true go to statement
      nop();

      case 2:
      yi->compile(cond_expr);//make init part
      b();
      nop();

      //for loop statement branch
      add_label(for_s1);
      san->compile(for_state1);

      //for loop condition!!!not statement
      add_label(statement);
      er->compile(state_expr);//get statement
      lw(2, cond_expr.temp_result.result_index, 30);//store expression result in r2
      bne(2, 0, for_s1);//if true go to statement
      nop();

      case 3:
      yi->compile(cond_expr);//make init part
      b();
      nop();

      //for loop statement branch
      add_label(for_s2);
      si->compile(for_state2);
      //iteration expression
      san->compile(for_state1);

      //for loop condition!!!not statement
      add_label(statement);
      er->compile(state_expr);//get statement
      lw(2, cond_expr.temp_result.result_index, 30);//store expression result in r2
      bne(2, 0, for_s2);//if true go to statement
      nop();
    }

  }



}
