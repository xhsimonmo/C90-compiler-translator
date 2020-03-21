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
  //add to the final code collection first, then modify it
  mpcode_collection.push_back(mips_code);
  //start function
  mp.add_frame(declarator, mips_code);

  //compound statement
  p_f->compile(mp);

  //finish function
  mp.finish_frame(mpcode_collection[current_frame]);
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
  mp.switch (type) {
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




// direct_declarator
// 	: IDENTIFIER   {$$ = new direct_declarator(0,*$1);}
// 	| '(' declarator ')'  {$$ = new direct_declarator(1,$2);}
// 	| direct_declarator '[' constant_expression ']'  {$$ = new direct_declarator(2,$1,$3);}  array declaration
// 	| direct_declarator '[' ']'   {$$ = new direct_declarator(3,$1);}   array declaration
// 	| direct_declarator '(' parameter_type_list ')'  {$$ = new direct_declarator(4,$1,$3);}  function declaration
// 	| direct_declarator '(' identifier_list ')'  {$$ = new direct_declarator(5,$1,$3);} function declaration
// 	| direct_declarator '(' ')'   {$$ = new direct_declarator(6,$1);} function declaration C90 page 67
// 	;
void direct_declarator::compile(mips& mp)const
{
  mp.switch(type)
  {
    case 0:
    mp.info.func_name = id;
    break;

    case 1:
    one->compile(mp);
    break;

    case 2:
    //it uses const expression so size is constant
    two->compile(mp);//this should store result to $2

    break;

    case 3:
    NotImplemented();// no Implement for array[]
    break;
    case 4:
    one->compile(mp); // eg:  f()
    mips another_mp;
    two->compile(another_mp);//parameter!
    break;

    case 5:
    NotImplemented(); //never reach, KR style.
    break;

    case 6:
    one->compile(mp);
    break;
  }
}

void assignment_expression::compile(mips& mp)const
{
  //no unary expression
  if(p_five == NULL)
  {
    p_one->compile(mp);
  }
  else
  {
    mips another_mp;

    mp.switch(type)
    {
      case 0:
      p_one->compile(mp);
      p_five->compile(another_mp);
      nop();
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 1://"*="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      mult(2, 3);
      mflo(2);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 2://"/="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      div(2, 3);
      mflo(2);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 3://"%="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      div(2, 3);
      mfhi(2);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 4://"+="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      add(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 5://"-="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      sub(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 6://"<<="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      sll(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 7://">>="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      sra(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 8://"&="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      _and(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 9://"^="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      _xor(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 10://"|="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      move(3, 2);
      p_one->compile(mp);
      nop();
      _or(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;
    }

  }
}

void cast_expression::compile(mips& mp)const
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

void multiplicative_expression::compile(mips& mp)const
{
  mips another_mp;

  case 1://"*"
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  cast->compile(another_mp);
  move(3, 2);
  mul->compile(mp);
  nop();
  mult(2, 3);
  mflo(2);
  // mp.sw(2, mp.info.var_index, 30);//load to a's stack position
  break;

  case 2:
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  cast->compile(another_mp);
  move(3, 2);
  mul->compile(mp);
  nop();
  div(2, 3);
  mflo(2);
  // mp.sw(2, mp.info.var_index, 30);//load to a's stack position
  break;

  case 3:
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  cast->compile(another_mp);
  move(3, 2);
  mul->compile(mp);
  nop();
  div(2, 3);
  mfhi(2);
  // mp.sw(2, mp.info.var_index, 30);//load to a's stack position
  break;
}

void additive_expression::compile(mips& mp)const
{
  mips another_mp;

  case 1://"+"
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  mul->compile(another_mp);
  move(3, 2);
  add->compile(mp);
  nop();
  add(2, 2, 3);
  // mp.sw(2, mp.info.var_index, 30);//load to a's stack position
  break;

  case 2://"-"
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  mul->compile(another_mp);
  move(3, 2);
  add->compile(mp);
  nop();
  sub(2, 2, 3);
  // mp.sw(2, mp.info.var_index, 30);//load to a's stack position
  break;

}

void shift_expression::compile(mips& mp)const
{

  mips another_mp;

  case 1://"<<"
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  r->compile(another_mp);
  move(3, 2);
  l->compile(mp);
  nop();
  sll(2, 2, 3);
  // mp.sw(2, mp.info.var_index, 30);//load to a's stack position
  break;

  case 2://">>"
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  r->compile(another_mp);
  move(3, 2);
  l->compile(mp);
  nop();
  sra(2, 2, 3);
  // mp.sw(2, mp.info.var_index, 30);//load to a's stack position
  break;

}

// void unary_expression::compile(mips& mp)
// {
//   mp.switch(type)
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

void selection_statement::compile(mips& mp)const
{
  string below_if = "Selection" + to_string(labelcounter);//make label
  labelcounter++;
  mips expre_mp;
  expre_ptr->compile(expre_mp);

  string else_label = "Selection" + to_string(labelcounter);//label when else start
  labelcounter++;

  mp.switch(type)
  {
    case 0:
    mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
    beq(2, 0, below_if);//if false, skip if statement, jump to the content below if statement;
    nop();
    //then make the if statement(if is true)
    mips sta_mp;
    ifsta->compile(sta_mp);
    add_label(below_if);
    break;

    case 1:
    mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
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
    //switch statement
    mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
    beq(2, 0, below_if);//if false, skip if statement, jump to the content below if statement;
    nop();
    //then make the if statement(if is true)
    mips sta_mp;
    ifsta->compile(sta_mp);
    add_label(below_if);
    break;

  }


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


    mp.switch(type)
    {
      case 0:
      b(condition);
      nop();

      add_label(statement);
      er->compile(state_expr);//get statement

      add_label(condition);
      yi->compile(cond_expr);//get conidtion expression
      mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
      bne(2, 0, statement);//if true go to statement
      nop();

      case 1://same as case 0, but condition and statement are reversed.
      b(statement);
      nop();

      add_label(condition);
      yi->compile(cond_expr);

      add_label(statement);
      er->compile(state_expr);
      mp.lw(2, state_expr.info.result_index, 30);//store expression result in r2
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
      mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
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
      mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
      bne(2, 0, for_s2);//if true go to statement
      nop();
    }

  }


}

void jump_statement::compile(mips& mp) const {
  mp.switch (type) {
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
    int var_index = mp.find_variable(element,stack_collection[current_frame]);//fetch address of the variable
    mp.info.var_index = var_index;
    mp.lw(2,var_index,30);//load value to $2
    break;

    case 1:

    mp.info.result = element;
    mp.li(2,element);
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

void parameter_list::compile(mips& mp)const{
  left -> compile(mp);
  mips another_mp;
  right -> compile(another_mp);
}

void parameter_declaration :: compile(mips& mp) const{
  if(right == NULL){
    left -> compile(mp); // e,g int
  }
  else{
    left -> compile(mp); // e,g int
    mips another_mp; // the get the name of declarator
    right -> compile(another_mp);
    string variable_name = another_mp.info.func_name;//get name of variable, like a;
    int availability = arg_check();
    int arg_reg = availability + 4;
    if(arg_reg >= 4){
      mp.sw(arg_reg, ((arg_reg-4)*4+12) , 30);//point upwards add 12 because we have ra and sp stored in beginning
      stack_collection[current_frame].push_back(variable_name, ((arg_reg-4)*4+12));
    }
    else{ //case when more than 4 arguments
        stack_collection[current_frame].push_back(variable_name, (12+16+4*arg_overflow));
        arg_overflow++;
    }
  }
}


void postfix::compile(mips& mp)const{
  debug(cname);
  mips another_mp;

  switch (type) {
    case 0://array?
    opt->compile(mp);//should store searching index in $2
    ptr->compile(another_mp);//fill array name in
    sll(2, 2, 2);//x4
    addi(3, 30, 8);
    add(2, 3, 2);
    lw(2, 20, 2);//last location index? not too sure how
    nop();
    sw(2, 24, 30);//last one + 4
    break;
    case 1:
    ptr->compile(mp);
    mp.jal(mp.info.func_name ); //maybe need to add f()?
    mp.nop();
    break;
    case 2: //postfix_expression '(' argument_expression_list ')'
    ptr->compile(mp);
    string function_name = mp.info.func_name;
    mips another_mp;
    opt -> compile(another_mp);
    mp.jal(function_name);
    mp.nop();
    break;
    case 3:
    NotImplemented();
    break;
    case 4:
    NotImplemented();
    break;
    case 5: // a++
    //mips another_mp; //start a new mips class so info.result is empty at first
    ptr -> compile(mp);
    string variable_name = another_mp.info.func_name;
    //mp.lw(2,find_variable(variable_name, stack_collection[current_frame]),30)
    mp.addiu(2,2,1);
    mp.sw(2,find_variable(variable_name, stack_collection[current_frame]),30);
    break;
    case 6: // a--
    ptr -> compile(mp);
    string variable_name = another_mp.info.func_name;
    //mp.lw(2,find_variable(variable_name, stack_collection[current_frame]),30)
    mp.addiu(2,2,-1);
    mp.sw(2,find_variable(variable_name, stack_collection[current_frame]),30);
    break;
  }
}

void argument_expression_list::compile(mips& mp)const{
  debug(cname);
  if(right == NULL){
    mips another_mp;
    left->compile(another_mp); // will reach a primary expression, either variable or number
    callee_value_process();
  }
  else{
    mips another_mp;
    left -> compile(another_mp);
    mips tmp_mp;
    right -> compile(tmp_mp);
    callee_value_process();
  }
}

// initializer
// 	: assignment_expression                  {$$ = $1;}
// 	| '{' initializer_list '}'               {$$ = new initializer(0, $2);}
// 	| '{' initializer_list ',' '}'           {$$ = new initializer(1, $2);}
// 	;
void initializer::compile(mips& mp) const
{
  switch(type)
  {
    case 0:
    p->compile(mp);//this should store all identifier address in mp
    int last_element = mp.array_info.array_add.size() - 1;
    int current_add = mp.array_info.array_add[last_element];
    current_add = current_add + 4;
    int element_add[mp.array_info.array_add.size()];
    for(int i = 0; i < mp.array_info.array_add.size(); i++)
    {
      sw(0, offset, 30);
      element[i] = current_add;
      current_add = current_add + 4;
    }
    //TODO: unsure about numbers: li instead of lw?
    for(int i = 0; i < mp.array_info.array_add.size(); i++)
    {
      lw(2, mp.array_info.array_add[i], 30);
      nop();
      sw(2, element[i], 30);
    }
    case 1:
    //same as above
    p->compile(mp);//this should store all identifier address in mp
    int last_element = mp.array_info.array_add.size() - 1;
    int current_add = mp.array_info.array_add[last_element];
    current_add = current_add + 4;
    int element_add[mp.array_info.array_add.size()];
    for(int i = 0; i < mp.array_info.array_add.size(); i++)
    {
      sw(0, offset, 30);
      element[i] = current_add;
      current_add = current_add + 4;
    }
    //TODO: unsure about numbers: li instead of lw?
    for(int i = 0; i < mp.array_info.array_add.size(); i++)
    {
      lw(2, mp.array_info.array_add[i], 30);
      nop();
      sw(2, element[i], 30);
    }
  }


}
