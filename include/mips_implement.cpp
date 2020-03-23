#include "menu.hpp"
#include "ast.hpp"
#include"mips.hpp"

void function_definition::compile(mips& mp)const
{
  // declarator;
  if(p_f == NULL){ // only two parts
      p_o->compile(mp);//compiler type specifier part; doesn't do anything yet? then add label, which is only known until compile direc_declarator
      string declarator = mp.info.func_name;
      declarator = declarator + ":";
      mpcode_collection[current_frame].push_back(declarator);

      //start function
      mp.add_frame();

      //compound statement
      p_t->compile(mp);

      //finish function
      mp.finish_frame();
  }
  else{
    p_o -> compile(mp);// type_specifier
    p_t-> compile(mp);
    //add label
    string declarator = mp.info.func_name;
    declarator = declarator + ":";
    mpcode_collection[current_frame].push_back(declarator);

    //start function
    mp.add_frame();

    //compound statement
    p_f->compile(mp);

    //finish function
    mp.finish_frame();

  }

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

void init_declarator::compile(mips& mp)const{
  if(two == NULL)
   {
     one -> compile(mp);
     string init_name = mp.info.func_name;
     int offset = -4 * (stack_collection[current_frame].size());
     stack_content tmp = {init_name,offset};
     stack_collection[current_frame].push_back(tmp);
   }
   else{
     one -> compile(mp);
     string init_name = mp.info.func_name;
     int offset = -4 * (stack_collection[current_frame].size());
     stack_content tmp = {init_name,offset};
     stack_collection[current_frame].push_back(tmp);
     two -> compile(mp);
     mp.sw(2,offset,30);
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
  mips another_mp;
  switch(type)
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
    one->compile(another_mp);//this should fill in the array name;
    string array_name = another_mp.info.array_name;
    //create a new array
    array_struct a;
    a.name = array_name;
    array_collection[current_frame].push_back(a);
    break;

    case 3:
    NotImplemented();// no Implement for array[]
    break;
    case 4:
    one->compile(mp); // eg:  f()
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

    switch(type)
    {
      case 0:
      p_one->compile(mp);
      p_five->compile(another_mp);
      mp.nop();
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 1://"*="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp.mult(2, 3);
      mp.mflo(2);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 2://"/="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp.div(2, 3);
      mp.mflo(2);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 3://"%="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp.div(2, 3);
      mp.mfhi(2);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 4://"+="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp.add(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 5://"-="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp.sub(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 6://"<<="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp.sll(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 7://">>="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp.sra(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 8://"&="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp._and(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 9://"^="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp._xor(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 10://"|="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp._or(2, 2, 3);
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
  int l_index;
  int r_index;

  switch (type) {

  case 1://"*"
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  cast->compile(another_mp);
  r_index = result_offset();
  //mp.move(3, 2);
  mul->compile(mp);
  l_index = result_offset();
  mp.lw(2,r_index,30);
  mp.lw(3,l_index,30)
  mp.nop();

  mp.mult(2, 3);
  mp.mflo(2);
  result_count = result_count -4;
  mp.sw(2, result_offset(), 30);//save the result in
  break;

  case 2:
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  cast->compile(another_mp);
  r_index = result_offset();
  mul->compile(mp);
  l_index = result_offset();
  mp.lw(3,r_index,30);
  mp.lw(2,l_index,30);
  mp.nop();

  mp.div(2, 3);
  mp.mflo(2);
  result_count = result_count -4;
  mp.sw(2, result_offset(), 30);//save the result in
  break;

  case 3:
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  cast->compile(another_mp);
  r_index = result_offset();
  mul->compile(mp);
  l_index = result_offset();
  mp.lw(3,r_index,30);
  mp.lw(2,l_index,30);
  mp.nop();

  mp.div(2, 3);
  mp.mfhi(2);
  result_count = result_count -4;
  mp.sw(2, result_offset(), 30);//save the result in
  break;
}
}


void additive_expression::compile(mips& mp)
{
  int l_index;
  int r_index;
  add->compile(mp);
  l_index = result_offset();
  mips another_mp;
  mul->compile(another_mp);
  r_index = result_offset();
  mp.lw(3,r_index,30);
  mp.lw(2,l_index,30);

  case 1://"+"
  // lw(2, mp.temp_result.var_index, 30);
  // lw(3, another_mp.temp_result.var_index, 30);
  nop();
  add(2, 2, 3);
  result_count = result_count - 4;
  mp.sw(2,result_offset(),30);
  break;

  case 2://"-"
  nop();
  sub(2, 2, 3);
  result_count = result_count - 4;
  mp.sw(2,result_offset(),30);
  break;

}

void shift_expression::compile(mips& mp)
{
  int l_index;
  int r_index;
  l->compile(mp);
  l_index = result_offset();
  mips another_mp;
  r->compile(another_mp);
  r_index = result_offset();
  mp.lw(3,r_index,30);
  mp.lw(2,l_index,30);

  case 1://"<<"

  sll(2, 2, 3);
  result_count = result_count -4;
  mp.sw(2, result_offset(), 30);//save the result in
  break;

  case 2://">>"
  sra(2, 2, 3);
  result_count = result_count -4;
  mp.sw(2, result_offset(), 30);//save the result in
  break;

}

void unary_expression::compile(mips& mp)const
{
  switch(type)
  {
    case 0:
    ptr->compile(mp);
    mp.addiu(2, 2, "1");
    mp.sw(2,mp.info.var_index,30);
    break;

    case 1:
    ptr->compile(mp);
    mp.addiu(2, 2, "-1");
    mp.sw(2,mp.info.var_index,30);
    break;

    case 2: //sizeof
    NotImplemented();
    break;
    case 3: //sizeof ()
    NotImplemented();
    break;
    case 4:// &
    NotImplemented();
    break;
    case 5: // *
    NotImplemented();
    break;
    case 6: // +
    ptr->compile(mp);
    break;
    case 7: // -
    ptr -> compile(mp);
    mp.li(3,"-1");
    mp.mult(2,3);
    mp.mflo(2);
    mp.sw(2,mp.info.var_index,30);
    break;
    case 8: // ~ bit wise NOT
    mp.li(3,"-1"); // -1 is 111111 for xor
    mp._xor(2,2,3);
    mp.sw(2,mp.info.var_index,30);
    break;
    case 9: // !
    NotImplemented();
    break;

  }
}

void selection_statement::compile(mips& mp)const
{
  string below_if = "Selection" + to_string(labelcounter);//make label
  labelcounter++;
  mips expre_mp;
  expre_ptr->compile(expre_mp);

  string else_label = "Selection" + to_string(labelcounter);//label when else start
  labelcounter++;
  mips sta_mp;
  mips s_mp;
  switch(type)
  {
    case 0:
    mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
    mp.beq(2, 0, below_if);//if false, skip if statement, jump to the content below if statement;
    mp.nop();
    //then make the if statement(if is true)
    //mips sta_mp;
    ifsta->compile(sta_mp);
    mp.add_label(below_if);
    break;

    case 1:
    mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
    mp.beq(2, 0, else_label);//if false f=go to else
    mp.nop();
    //then make the if statement(if is true)
    //mips sta_mp;
    ifsta->compile(sta_mp);
    mp.b(below_if);

    //else statement
    mp.add_label(else_label);
    // mips s_mp;
    elsesta->compile(s_mp);
    mp.add_label(below_if);
    break;

    case 2:
    //switch statement
    mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
    mp.beq(2, 0, below_if);//if false, skip if statement, jump to the content below if statement;
    mp.nop();
    //then make the if statement(if is true)
    //mips sta_mp;
    ifsta->compile(sta_mp);
    mp.add_label(below_if);
    break;

  }
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


    switch(type)
    {
      case 0:
      mp.b(condition);
      mp.nop();

      mp.add_label(statement);
      er->compile(state_expr);//get statement

      mp.add_label(condition);
      yi->compile(cond_expr);//get conidtion expression
      mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
      mp.bne(2, 0, statement);//if true go to statement
      mp.nop();

      case 1://same as case 0, but condition and statement are reversed.
      mp.b(statement);
      mp.nop();

      mp.add_label(condition);
      yi->compile(cond_expr);

      mp.add_label(statement);
      er->compile(state_expr);
      mp.lw(2, state_expr.info.result_index, 30);//store expression result in r2
      mp.bne(2, 0, condition);//if true go to statement
      mp.nop();

      case 2:
      yi->compile(cond_expr);//make init part
      mp.b(statement);
      mp.nop();

      //for loop statement branch
      mp.add_label(for_s1);
      san->compile(for_state1);

      //for loop condition!!!not statement
      mp.add_label(statement);
      er->compile(state_expr);//get statement
      mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
      mp.bne(2, 0, for_s1);//if true go to statement
      mp.nop();

      case 3:
      yi->compile(cond_expr);//make init part
      mp.b(statement);
      mp.nop();

      //for loop statement branch
      mp.add_label(for_s2);
      si->compile(for_state2);
      //iteration expression
      san->compile(for_state1);

      //for loop condition!!!not statement
      mp.add_label(statement);
      er->compile(state_expr);//get statement
      mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
      mp.bne(2, 0, for_s2);//if true go to statement
      mp.nop();
    }

  }




void jump_statement::compile(mips& mp) const {
  mips mp_tmp;
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
    //mips mp_tmp;
    expre_ptr -> compile(mp_tmp); // return value in $2
    //mp.li(2,mp_tmp.info.result)
    mp.finish_frame();
    break;
  }
}

void primary_expression :: compile(mips& mp) const{
  debug(cname);
  int var_index;
  switch (type) {
    case 0: // got IDENTIFIER
    mp.info.func_name = element;//update func_name, name of a variable
    var_index = mp.find_variable(element,stack_collection[current_frame]);//fetch address of the variable
    mp.info.var_index = var_index;
    if(var_index != -1) //this variable indeed has been saved
    {
      mp.lw(2,var_index,30);//load value to $2
    }
    result_count = result_count -4;
    sw(2,result_offset(),30);
    break;
    case 1:
    mp.info.result = element;
    mp.li(2,element);
    result_count = result_count -4;
    sw(2,result_offset(),30);

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
      stack_content stack = {variable_name, ((arg_reg-4)*4+12)};
      stack_collection[current_frame].push_back(stack);
    }
    else{ //case when more than 4 arguments
      stack_content stack = {variable_name, ((arg_reg-4)*4+12)};
      stack_collection[current_frame].push_back(stack);
      arg_overflow++;
    }
  }
}


void postfix_expression::compile(mips& mp)const{
  debug(cname);
  mips another_mp;
  string variable_name;
  string function_name;
  int offset;
  switch (type) {
    case 0://read from array
    ptr->compile(another_mp);//fill array name (in all frame arrays)
    string name = another_mp.info.call_array_name;
    int array_index = find_array(name);//index of array in all arrays of current frame

    opt->compile(mp);//should store index in $2; store index in info.result
    int index = stoi(mp.info.result);//array element index
    // mp.sll(2, 2, 2);//x4 to get byte increment
    int offset = array_collection[current_frame][array_index].array_add[0];
    int increment = stoi(offset) + index * 4;
    // mp.addi(2, 2, to_string(offset));
    mp.sw(2, increment, 30);//store the result in $2; $2 stores the address
    break;
    case 1:
    ptr->compile(mp);
    mp.jal(mp.info.func_name ); //maybe need to add f()?
    mp.nop();
    break;
    case 2: //postfix_expression '(' argument_expression_list ')'
    ptr->compile(mp);
    function_name = mp.info.func_name;
    // mips another_mp;
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
    variable_name = another_mp.info.func_name;
    //mp.lw(2,find_variable(variable_name, stack_collection[current_frame]),30)
    mp.addiu(2,2,"1");
    mp.sw(2,mp.find_variable(variable_name, stack_collection[current_frame]),30);
    break;
    case 6: // a--
    ptr -> compile(mp);
    variable_name = another_mp.info.func_name;
    //mp.lw(2,find_variable(variable_name, stack_collection[current_frame]),30)
    mp.addiu(2,2,"-1");
    mp.sw(2,mp.find_variable(variable_name, stack_collection[current_frame]),30);
    break;
  }
}

void argument_expression_list::compile(mips& mp)const{
  debug(cname);
  if(right == NULL){
    mips another_mp;
    left->compile(another_mp); // will reach a primary expression, either variable or number
    callee_value_process(another_mp);
  }
  else{
    mips another_mp;
    left -> compile(another_mp);
    mips tmp_mp;
    right -> compile(tmp_mp);
    callee_value_process(tmp_mp);
  }
}


void initializer::compile(mips& mp) const
{
  switch(type)
  {
    // array_collection[current_frame][array_index].array_add
    case 0:
    p->compile(mp);//this should store all identifier address in mp;
    int size = stoi(mp.info.result);//size of the array
    int element[size];
    //allocate space for array elements
    for(int i = 0; i < size(); i++)
    {
      mp.sw(0, offset, 30);//TODO:offset???
      element[i] = offset;
      offset = offset + 4;
    }
    //TODO: unsure about numbers: li instead of lw?
    //it's the last array in frame
    int index = array_collection[current_frame].size()-1;
    for(int i = 0; i < array_collection[current_frame][index].array_add.size(); i++)
    {
      mp.lw(2, array_collection[current_frame][index].array_add[i], 30);
      mp.nop();
      mp.sw(2, element[i], 30);
    }
    case 1:
    //same as above
    p->compile(mp);//this should store all identifier address in mp;
    int size = stoi(mp.info.result);//size of the array
    int element[size];
    //allocate space for array elements
    for(int i = 0; i < size(); i++)
    {
      mp.sw(0, offset, 30);//TODO:offset???
      element[i] = offset;
      offset = offset + 4;
    }
    //TODO: unsure about numbers: li instead of lw?
    //it's the last array in frame
    int index = array_collection[current_frame].size()-1;
    for(int i = 0; i < array_collection[current_frame][index].array_add.size(); i++)
    {
      mp.lw(2, array_collection[current_frame][index].array_add[i], 30);
      mp.nop();
      mp.sw(2, element[i], 30);
    }
  }
}

void initializer_list::compile(mips& mp) const
{
  mips another_mp;
  switch(type)
  {
    case 0:
    left->compile(mp);
    break;

    case 1:
    left->compile(another_mp);
    right->compile(mp);
  }
}
void type_name::compile(mips& mp)const{
  left ->compile(mp);
  mips another_mp;
  right ->compile(another_mp);
}

void translation_unit::compile(mips& mp)const{
  p_yi->compile(mp);
  mips another_mp;
  p_er->compile(another_mp);
}


void storage_class_specifier::compile(mips& mp)const{
   debug(cname);
   if(type == 0){
     std::cerr << "TYDEF!" << '\n';
   }

void statement_list::compile(mips& mp)const{
  l -> compile(mp);
  mips another_mp;
  r -> compile (another_mp);
}

void specifier_qualifier_list::compile(mips& mp)const{
  spec->compile(mp);
  mips another_mp;
  list ->compile(another_mp);
>>>>>>> 650badd1190c1755cd4756e388af26d990459557
}

void type_name::compile(mips& mp)const{
  left ->compile(mp);
  mips another_mp;
  right ->compile(another_mp);
}

void translation_unit::compile(mips& mp)const{
  p_yi->compile(mp);
  mips another_mp;
  p_er->compile(another_mp);
}


void storage_class_specifier::compile(mips& mp)const{
   debug(cname);
   if(type == 0){
     std::cerr << "TYDEF!" << '\n';
   }
}

void relational_expression::compile(mips& mp)const{
  mips another_mp;
  switch (type) {
    case 0:
    left->compile(mp);
    mp.move(3,2);
    right -> compile(another_mp);
    mp.slt(2,3,2);
    break;
    case 1:
    left->compile(mp);
    mp.move(3,2);
    right -> compile(another_mp);
    mp.slt(2,2,3);//simply swap 2 and 3 registers
    break;
    case 2: //<=
    break;
    case 3:
    break;

  }
}

void abstract_declarator::compile(mips& mp)const
{
  left ->compile(mp);
  mips another_mp;
  right -> compile(another_mp);
}

void base_expression::compile(mips& mp)const
{
  p_one -> compile(mp);
  mips another_mp;
  p_five ->compile(another_mp);
}

void conditional_expression::compile(mips& mp)const
{
  debug(cname);
  NotImplemented();
}

void declaration_list::compile(mips& mp)const{
  p_o -> compile(mp);
  mips another_mp;
  p_t ->compile(another_mp);
}

void declaration_specifiers::compile(mips& mp)const
{
  one ->compile(mp);
  mips another_mp;
  two ->compile(another_mp);
}


void declaration::compile(mips& mp)const
{
  if(lt == NULL)
   {
     spec -> compile(mp);
   }
   else{
     spec -> compile(mp);
     mips another_mp;
     list->compile(another_mp);
   }
}
