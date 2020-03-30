#include "menu.hpp"
#include "ast.hpp"
#include"mips.hpp"
#include <stdio.h>
#include <string.h>
void function_definition::compile(mips& mp)const
{
  // declarator;
  debug(cname);
  if(p_f == NULL){ // only two parts
      p_o->compile(mp);//compiler type specifier part; doesn't do anything yet? then add label, which is only known until compile direc_declarator
      string declarator = mp.info.func_name;
      //declarator = declarator + ":";
      declarator = mp.add_prefix(declarator);
      //std::cerr << "name of function:" << '\n';
      vector<string> current_stack;
      current_stack.push_back(declarator);
      mpcode_collection.push_back(current_stack);

      //start function
      mp.add_frame();

      //compound statement
      p_t->compile(mp);

      //finish function
      if(end_frame == true){
        mp.finish_frame();
      }
  }
  else{
    p_o -> compile(mp);// type_specifier

    current_frame = stack_collection.size();
    vector<stack_content> frame_stack; //with reference to FP at the top, variables arguments has positive address, local have negative
    stack_collection.push_back(frame_stack);
    initilise_arg(true);//all argument available at the beginning
    arg_overflow = 0;
    vector<string> current_stack;
    mpcode_collection.push_back(current_stack);
    string imm = "-12";
    mp.addiu(29,29,imm);
    mp.sw(30, 4,29);
    mp.sw(31,8,29);
    // this instruction is added at the end_frame: addiu(29,29,offset)
    mp.move(30,29);
    mp.nop();
    // initilise it before entering parameter
    p_t-> compile(mp); //function name + parameter
    //add label
    string declarator = mp.info.func_name;
    //std::cerr << "name of function:" << declarator <<'\n';
    declarator = mp.add_prefix(declarator);
    auto it = mpcode_collection[current_frame].begin();
    mpcode_collection[current_frame].insert(it, declarator);
    //start function
    mp.add_frame();
    //compound statement
    p_f->compile(mp);
    //finish function
    if(end_frame == true){
      mp.finish_frame();
    }
  }
}

void type_specifier::compile(mips& mp)const
{
  debug(cname);
  switch(type)
  {
    case 0:
    mp.info.func_type = "void";
    break;
    case 1:
    mp.info.func_type = "char";
    break;
    case 2:
    mp.info.func_type = "short";
    break;
    case 3:
    mp.info.func_type = "int";
    break;
    case 4:
    mp.info.func_type = "long";
    break;
    case 5:
    mp.info.func_type = "float";
    break;
    case 6:
    mp.info.func_type = "double";
    break;
    case 7:
    mp.info.func_type = "signed";
    break;
    case 8:
    mp.info.func_type = "unsigned";
    break;
    case 9:
    mp.info.func_type = "enum";
    break;
    case 10:
    mp.info.func_type = "type_name";
    break;
  }
  //don't do anything yet for type specifier, assume INT?
};

void external_declaration::compile(mips& mp)const
{
  debug(cname);
  switch(type){
    case 0:
    ptr->compile(mp);
    break;
    case 1:
    ptr->compile(mp);
    break;
  }
}

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
  debug(cname);
  if(two == NULL)
   {
     one -> compile(mp);
     string init_name = mp.info.func_name;
     result_count = result_count -4;
     int offset = result_offset();
     stack_content tmp = {init_name,offset,"int"};
     stack_collection[current_frame].push_back(tmp);
   }
   else{
     one -> compile(mp);
     string init_name = mp.info.func_name;
     //int offset = -4 * (stack_collection[current_frame].size() + -1*result_count);
     result_count = result_count -4;
     int offset = result_offset();
     //mp.comment("result_offset in init_declarator: " + to_string(offset));
     stack_content tmp = {init_name,offset,"int"};
     stack_collection[current_frame].push_back(tmp);
     mips another_mp;
     two -> compile(another_mp);
     mp.sw(2,offset,30);
     std::cerr << "init_declarator: " << mp.info.func_type << '\n';
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
  debug(cname);
  mips another_mp;
  string array_name;
  //create a new array
  array_struct a;
  int temp_current_frame = current_frame;
  int size;

  switch(type)
  {
    case 0:
    mp.info.func_name = id;
    break;

    case 1:
    one->compile(mp);
    break;

    case 2:
    if(in_frame == false)//if global
    {
      current_frame = -1;
    }
    //it uses const expression so size is constant
    two->compile(mp);//this should store result to $2
    size = stoi(mp.info.result);//size of the array
    one->compile(another_mp);//this should fill in the array name;
    array_name = another_mp.info.func_name;
    std::cerr<<"Array declaration with name: " << array_name << std::endl;
    a.name = array_name;
    a.size = size;
    std::cerr<<"Array coll size: " << array_collection.size() << std::endl;

    if(in_frame == false)//if global
    {
      //mp.global(array_name);
    }

    //array initialisation:initialise all to 0
    if(in_frame == true)
    {
      for (int i = 0; i < size; i++)
      {
        result_count = result_count - 4;
        mp.sw(0, result_offset(), 30);//initialise all with 0
        a.array_add.push_back(result_offset());//store array content address
      }
    }

    array_collection[current_frame+1].push_back(a);//for all array, we use current fram+1 as index (because index 0 is left for global
    current_frame = temp_current_frame;

    break;

    case 3:
    NotImplemented();// no Implement for array[]
    break;

    case 4:
    one->compile(mp); // eg:  f()
    //std::cerr << "to compile parameter" << '\n';
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
  if(p_five == NULL)
  {
    p_one->compile(mp);
  }
  else
  {
    mips another_mp;

    switch(type)
    {
      case 0:{ // =
      mp.comment("Assignment!!!!!");
      mp.unary_type = false; // used to check whether got an *x type in lvalue
      p_one->compile(mp); // *x or x, $2 store the, unary_type will be set true if got *x
      int index = mp.info.var_index;
      p_five->compile(another_mp);
      mp.nop();
      if(!mp.unary_type){
      //std::cerr << "current functype in assignment:" <<mp.info.func_type << '\n';
       // if(mp.info.func_type.find('*') != std::string::npos)
       // {
       //  //std::cerr << " pointer assignment" << '\n';
       // }
       // else{
        //std::cerr << "non pointer assignment" << '\n';
        mp.sw(2, mp.info.var_index, 30);
       // }
     }
     else{
       mp.move(3,2);
       mp.lw(2,index, 30);
       mp.sw(3,0,2);
     }
     mp.unary_type = false;
      break;
    }
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
      mp.sllv(2, 2, 3);
      mp.sw(2, mp.info.var_index, 30);
      break;

      case 7://">>="
      // mp.lw(2, mp.info.var_index, 30);
      // mp.lw(3, another_mp.info.var_index, 30);
      p_five->compile(another_mp);
      mp.move(3, 2);
      p_one->compile(mp);
      mp.nop();
      mp.srav(2, 2, 3);
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
  mp.lw(3,l_index,30);
  mp.nop();

  mp.mult(2, 3);
  mp.mflo(2);
  result_count = result_count -4;
  mp.sw(2, result_offset(), 30);//save the result in
  break;

  case 2:
  // mp.mp.lw(2, mp.info.var_index, 30);
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


void additive_expression::compile(mips& mp)const
{
  int l_index;
  int r_index;
  add->compile(mp);
  l_index = result_offset();
  mips another_mp;
  mul->compile(another_mp);
  r_index = result_offset();
  mp.comment("load right index from memory");
  mp.lw(3,r_index,30);
  mp.comment("load left index from memory");
  mp.lw(2,l_index,30);
  switch (type) {

  case 1://"+"
  mp.comment("additive expression");
  mp.add(2, 2, 3);
  result_count = result_count - 4;
  mp.sw(2,result_offset(),30);
  break;

  case 2://"-"
  mp.sub(2, 2, 3);
  result_count = result_count - 4;
  mp.sw(2,result_offset(),30);
  break;
 }
}


void shift_expression::compile(mips& mp)const
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
  switch (type) {
  case 1://"<<"

  mp.sllv(2, 2, 3);
  //mp.sw(2, mp.info.var_index, 30);
   result_count = result_count -4;
   mp.sw(2, result_offset(), 30);//save the result in
  break;

  case 2://">>"
  mp.srav(2, 2, 3);
  //mp.sw(2, mp.info.var_index, 30);
   result_count = result_count -4;
   mp.sw(2, result_offset(), 30);//save the result in
  break;
 }
}

void unary_expression::compile(mips& mp)const
{
  debug(cname);
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
    ptr ->compile(mp);
    sizeof_process(mp);
    break;
    case 3: //sizeof ()
    ptr ->compile(mp);
    sizeof_process(mp);
    break;
    case 4:// & address of
    ptr ->compile(mp);
    mp.addiu(2,30,to_string(mp.info.var_index)); // FP + offset
    result_count = result_count - 4;
    mp.sw(2,result_offset(),30);
    break;
    case 5: // *
    ptr ->compile(mp); // address stored in $2
    mp.unary_type = true;
    mp.lw(2,0,2); // load the content of address in $2 to $2
    result_count = result_count - 4;
    mp.sw(2,result_offset(),30);
    break;
    case 6: // +
    ptr->compile(mp);
    result_count = result_count - 4;
    mp.sw(2,result_offset(),30);
    break;
    case 7: // -
    ptr -> compile(mp);
    mp.li(3,"-1");
    mp.mult(2,3);
    mp.mflo(2);
    //mp.sw(2,mp.info.var_index,30);
    result_count = result_count - 4;
    mp.sw(2,result_offset(),30);
    break;
    case 8: // ~ bit wise NOT
    mp.li(3,"-1"); // -1 is 111111 for xor
    mp._xor(2,2,3);
    //mp.sw(2,mp.info.var_index,30);
    result_count = result_count - 4;
    mp.sw(2,result_offset(),30);
    break;
    case 9: // !
    ptr->compile(mp);
    mp.li(3, "0");
    mp.seq(2,2,3);//set to 1 if equal to 0; otherwise 0
    result_count = result_count - 4;
    mp.sw(2,result_offset(),30);
    break;
  }
}

// selection_statement
// 	: IF '(' expression ')' statement    {$$ = new selection_statement(0, $3, $5);std::cerr << "selection_statement 0" << std::endl;}
// 	| IF '(' expression ')' statement ELSE statement   {$$ = new selection_statement(1, $3, $5, $7);std::cerr << "selection_statement 1" << std::endl;}
// 	| SWITCH '(' expression ')' statement    {$$ = new selection_statement(2, $3, $5);std::cerr << "selection_statement 2" << std::endl;}
// 	;
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

  string switch_label = "end_switch" + to_string(labelcounter);
  string case_number;

  switch(type)
  {
    case 0:
    mp.comment("ifelse ssstart!");
    // mp.lw(2, expre_mp.info.result, 30);//store expression result in r2
    mp.beq(2, 0, below_if);//if false, skip if statement, jump to the content below if statement;
    mp.nop();
    //then make the if statement(if is true)
    //mips sta_mp;
    ifsta->compile(sta_mp);
    //in_frame = true;//still in the frame
    mp.add_label(below_if);
    break;

    case 1:
    mp.comment("ifelse ssstart!");
    // mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
    mp.beq(2, 0, else_label);//if false f=go to else
    mp.nop();
    //then make the if statement(if is true)
    //mips sta_mp;
    ifsta->compile(sta_mp);
    //in_frame = true;//still in the frame
    mp.b(below_if);

    //else statement
    mp.add_label(else_label);
    // mips s_mp;
    elsesta->compile(s_mp);
    mp.add_label(below_if);
    break;

    case 2:
    //switch statement

    //initialise vector
    vector<switch_content>switch_temp;
    mp.switch_info = switch_temp;

    //add label to be the first element
    switch_content info;
    info.label = switch_label;
    mp.switch_info.push_back(info);

    mp.lw(2, expre_mp.info.result_index, 30);//store switch variable's value in $2
    ifsta->compile(mp);//obtain all case information!

    //start from 1 to avoid the label (index 0)
    for(int i = 1; i < mp.switch_info.size(); i++)
    {
      if(mp.switch_info[i].case_num != "defalut")
      {
        case_number = mp.switch_info[i].case_num;
        mp.addi(3, 3, case_number);//load case number into $3
        mp.beq(2, 3, mp.switch_info[i].label);//if same jump to the corresponding label
        mp.nop();
      }
      else
      {
        //find default case
        //TODO: may not work: default doesn't have to be at the end
        mp.beq(0, 0, mp.switch_info[i].label);
      }
    }
    mp.add_label(switch_label);
    break;

  }
}

// iteration_statement
// 	: WHILE '(' expression ')' statement   {$$ = new iteration_statement(0, $3, $5); std::cerr << "iteration_statement 0 " << std::endl;}
// 	| DO statement WHILE '(' expression ')' ';'    {$$ = new iteration_statement(1, $2, $5);std::cerr << "iteration_statement 1 " << std::endl;}
// 	| FOR '(' expression_statement expression_statement ')' statement    {$$ = new iteration_statement(2, $3, $4, $6);std::cerr << "iteration_statement 2 " << std::endl;}
// 	| FOR '(' expression_statement expression_statement expression ')' statement   {$$ = new iteration_statement(0, $3, $4, $5, $7);std::cerr << "iteration_statement 3 " << std::endl;}
// 	;
void iteration_statement::compile(mips& mp)const{

    mp.comment("In Iteration!");

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

    string for_increment = "for_increment" + to_string(labelcounter);
    labelcounter++;

    string for_end = "for_end" + to_string(labelcounter);
    labelcounter++;

    string for_start = "for_start" + to_string(labelcounter);
    labelcounter++;

    string third_part = "label" + to_string(labelcounter);
    labelcounter++;

    string while_end = "while_end" + to_string(labelcounter);
    labelcounter++;




    switch(type)
    {
      case 0:
      mp.b(condition);
      mp.nop();

      state_expr.info.continue_jump_label = third_part;//if meet continue jump to this
      state_expr.info.break_jump_label = while_end;//if meet break jump to this

      mp.add_label(statement);
      er->compile(state_expr);//get statement

      mp.add_label(third_part);
      mp.b(condition);

      mp.add_label(condition);
      yi->compile(cond_expr);//get conidtion expression
      //std::cerr << "finish compiling condition" << '\n';
      //mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
      //std::cerr << "bne" << '\n';
      mp.bne(2, 0, statement);//if true go to statement
      mp.nop();
      break;
      //end of while looop
      mp.add_label(while_end);

      case 1://same as case 0, but condition and statement are reversed.
      mp.b(statement);
      mp.nop();

      cond_expr.info.continue_jump_label = third_part;//if meet continue jump to this
      cond_expr.info.break_jump_label = while_end;//if meet break jump to this

      mp.add_label(condition);
      yi->compile(cond_expr);

      mp.add_label(third_part);
      mp.b(statement);

      mp.add_label(statement);
      er->compile(state_expr);
      // mp.lw(2, state_expr.info.result_index, 30);//store expression result in r2
      mp.bne(2, 0, condition);//if true go to statement
      mp.nop();

      //end of while looop
      mp.add_label(while_end);
      break;

      case 2:
      mp.comment("it's a for loop!");
      yi->compile(cond_expr);//make init part(int i = 0)
      //start of for loop
      mp.add_label(for_start);

      mp.b(statement);
      mp.nop();

      //for loop statement branch
      mp.add_label(for_s1);
      for_state1.info.continue_jump_label = third_part;//if meet continue jump to this
      for_state1.info.break_jump_label = for_end;//if meet break jump to this
      san->compile(for_state1);

      mp.add_label(third_part);
      mp.b(for_start);

      //for loop condition!!!not statement
      mp.add_label(statement);
      er->compile(state_expr);//get statement
      // mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
      mp.bne(2, 0, for_s1);//if true go to statement
      mp.nop();

      //end of for loop
      mp.add_label(for_end);
      break;

      case 3:
      mp.comment("it's a for loop!");
      yi->compile(cond_expr);//make init part
      //start of for loop
      mp.add_label(for_start);

      mp.b(statement);
      mp.nop();

      //for loop statement branch
      mp.add_label(for_s2);
      for_state2.info.continue_jump_label = third_part;//if meet continue jump to this
      for_state2.info.break_jump_label = for_end;//if meet break jump to this
      si->compile(for_state2);
      // if(for_state2.info._continue == true)
      // {
      //   mp.b(for_increment);
      //   mp.nop();
      //   mp.add_label(for_increment);
      // }
      mp.add_label(third_part);
      san->compile(for_state1);
      mp.b(for_start);
      // if(for_state2.info._break == true)
      // {
      //   mp.nop();
      // }

      //for loop condition!!!not statement
      mp.add_label(statement);
      er->compile(state_expr);//get statement
      //mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
      // mp.lw(2, cond_expr.info.result_index, 30);//store expression result in r2
      mp.bne(2, 0, for_s2);//if true go to statement
      mp.nop();

      //end of for loop
      mp.add_label(for_end);
      break;
    }
  }

// jump_statement
// 	 //GOTO IDENTIFIER ';'   {$$ = new jump_statement(0, "GOTO");}  // no need to Implement this
// 	: CONTINUE ';'   {$$ = new jump_statement(1, "CONTINUE");std::cout << "jump_statement 1 " << std::endl;}
// 	| BREAK ';'    {$$ = new jump_statement(2, "BREAK");std::cout << "jump_statement 2 " << std::endl;}
// 	| RETURN ';'   {$$ = new jump_statement(3, "RETURN");std::cout << "jump_statement 3 " << std::endl;}
// 	| RETURN expression ';'    {$$ = new jump_statement(4, $2);std::cout << "jump_statement 4 " << std::endl;}
// 	;
void jump_statement::compile(mips& mp) const {
  mips mp_tmp;
  switch (type) {
    case 0:
    NotImplemented();
    break;
    case 1:
    //CONTINUE
    mp.b(mp.info.continue_jump_label);//there is a continue waiting to be sloved!
    mp.nop();
    break;
    case 2:
    //BREAK
    mp.b(mp.info.break_jump_label);//there is a break waiting to be sloved!
    mp.nop();
    break;
    case 3: // simply "return; " gives error
    mp.finish_frame();
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
    std::cerr << "IDENTIFIER:" << element << '\n';
    mp.info.func_name = element;//update func_name, name of a variable
    var_index = mp.find_variable(element,stack_collection[current_frame]);//fetch address of the variable
    mp.info.var_index = var_index;
    mp.info.func_type = mp.find_variable_type(element,stack_collection[current_frame]);
    if(var_index != -1 and var_index != -3) //this variable indeed has been saved,not a funciton name and stuff like that
    {
      mp.lw(2,var_index,30);//load value to $2
      result_count = result_count - 4;
      mp.sw(2,result_offset(),30);
    }
    else if(var_index == -3)
    {
      for(int j = 0; j < enum_var.size();j++)
      {
        if(enum_var[j].name == element){
          mp.info.result = to_string(enum_var[j].address);
        }
      }
      mp.li(2,mp.info.result);
      result_count = result_count - 4;
      mp.sw(2,result_offset(),30);
    }
    break;
    case 1:
    std::cerr << "get a primary expression as number :" << element<< '\n';
    mp.info.result = element;
    //mp.comment("get a primary expression as number : "+element);
    if(!in_enum){ // we don't do it in enum
      //std::cerr << "inframe!" << '\n';
      mp.li(2,element);
      result_count = result_count -4;
      mp.sw(2,result_offset(),30);
    }
    break;

    case 2:{ // STRING_LITERAL
    char character = element[1];
    int ascii = int(character);
    mp.li(2,to_string(ascii));
    result_count = result_count -4;
    mp.sw(2,result_offset(),30);
    break;
    }

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
  debug(cname);
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
    // std::cerr << "current register in parameter:" << arg_reg<<'\n';
    // std::cerr << "current frame in parameter:" << current_frame<<'\n';
    // std::cerr << "stack_collection size: " <<stack_collection.size() <<'\n';
    if(arg_reg >= 4){
      int offset = (arg_reg-4)*4+12;
      mp.sw(arg_reg, offset,30);//point upwards add 12 because we have ra and sp stored in beginning
      //std::cerr << "less than 4 parameters, current offset: " << offset<<  '\n';
      stack_content stack = {variable_name, ((arg_reg-4)*4+12), "int"};
      stack_collection[current_frame].push_back(stack);

    }
    else{ //case when more than 4 arguments
      //std::cerr << "more than 4 parameter: current offset: " << (arg_reg+arg_overflow+1)*4+12 <<'\n';
      stack_content stack = {variable_name, ((arg_reg+arg_overflow+1)*4+12), "int"};
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

  string name;
  int array_index;
  int index;

  int temp_current_frame = current_frame;
  bool global_array = false;//to see if it is global array

  switch (type) {
    case 0://read from array
    mp.comment("read from array!");
    ptr->compile(another_mp);//fill array name (in all frame arrays)
    name = another_mp.info.func_name;
    mp.comment("array name: " + name);
    array_index = mp.find_array(name, global_array);//index of array in all arrays of current frame
    mp.comment("1");
    if(global_array == true)//if it is reading from a global array
    {
      mp.comment("global array");
      current_frame = -1;
    }
    mp.comment("2");
    opt->compile(mp);//should store index in $2; store index in info.result
    index = stoi(mp.info.result);//array element index
    mp.comment("3");
    std::cerr << "index is " << index << std::endl;
    // mp.sll(2, 2, 2);//x4 to get byte increment
    mp.comment("4");
    offset = array_collection[current_frame+1][array_index].array_add[index];
    mp.comment("offset: " + to_string(offset));
    mp.comment("5");
    mp.lw(2, offset, 30);//store the result in $2; $2 stores the address
    mp.info.var_index = offset;
    current_frame = temp_current_frame;
    break;

    case 1:
    ptr->compile(mp);
    mp.jal(mp.info.func_name ); //maybe need to add f()?
    mp.nop();
    result_count = result_count - 4;
    mp.sw(2,result_offset(),30);
    break;

    case 2: //postfix_expression '(' argument_expression_list ')'
    ptr->compile(mp);
    function_name = mp.info.func_name;
    // mips another_mp;
    caller_arg_count = 0;
    opt -> compile(another_mp);
    mp.jal(function_name);
    if(arg_count_collection[current_frame] < caller_arg_count)
    {
      arg_count_collection[current_frame] = caller_arg_count;
    }
    mp.nop();
    result_count = result_count - 4;
    mp.sw(2,result_offset(),30);
    caller_arg_count = 0; // reset
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
    variable_name = mp.info.func_name;
    //mp.lw(2,find_variable(variable_name, stack_collection[current_frame]),30)
    mp.addiu(2,2,"1");
    mp.sw(2,mp.find_variable(variable_name, stack_collection[current_frame]),30);
    break;
    case 6: // a--
    ptr -> compile(mp);
    variable_name = mp.info.func_name;
    mp.comment("variable name: " + variable_name);
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

// initializer
// 	: assignment_expression                  {$$ = $1;}
// 	| '{' initializer_list '}'               {$$ = new initializer(0, $2);}
// 	| '{' initializer_list ',' '}'           {$$ = new initializer(1, $2);}
// 	;
void initializer::compile(mips& mp) const
{
  debug(cname);
  // int size;
  // int element[size];
  // int index;
  // int offset;
  // int last_index;
  // int temp_current_frame = current_frame;
  p->compile(mp);

    // case 0:
    // //array initialisation
    // if(in_frame == false)//if global
    // {
    //   current_frame = 0;
    //   p->compile(mp);//this should store all identifier address in mp;
    //   for(int i = 0; i < array_collection[current_frame][index].array_add.size(); i++)
    //   {
    //     mp._word("TO:unknown");
    //   }
    // }
    // else
    // {
    //   p->compile(mp);//this should store all identifier address in mp;
    //   size = stoi(mp.info.result);//size of the array
    //   last_index = array_collection[current_frame+1].size() - 1;
    //   offset = array_collection[current_frame+1][last_index].array_add[0];
    //   //allocate space for array elements
    //   for(int i = 0; i < size; i++)
    //   {
    //     mp.sw(0, offset, 30);
    //     element[i] = offset;
    //     offset = offset + 4;
    //   }
    //   //TODO: unsure about numbers: li instead of lw?
    //   //it's the last array in frame
    //   index = array_collection[current_frame+1].size()-1;
    //   for(int i = 0; i < array_collection[current_frame+1][index].array_add.size(); i++)
    //   {
    //     mp.lw(2, array_collection[current_frame+1][index].array_add[i], 30);
    //     mp.nop();
    //     mp.sw(2, element[i], 30);
    //   }
    // }
    // current_frame = temp_current_frame;
}

// initializer_list
// 	: initializer                            {$$ = new initializer_list(0, $1); std::cerr << "initializer_list 0" << std::endl;}
// 	| initializer_list ',' initializer       {$$ = new initializer_list(1, $1, $3); std::cerr << "initializer_list 1" << std::endl;}
// 	;
void initializer_list::compile(mips& mp) const
{
  int index;
  int offset;
  int temp_current_frame = current_frame;//save current frame value(in case it changes in global)
  debug(cname);

  switch(type)
  {
    case 0:
    if(in_frame == false)//if global
    {
      mp.comment("Global!!");
      current_frame = 0;
      left->compile(mp);//this should store all identifier address in mp;
      mp._word(mp.info.result);

      current_frame = temp_current_frame;
    }
    else
    {
      mp.comment("not Global!!");
      left->compile(mp);
      mp.comment("here?");

      //it's the last array in frame
      index = array_collection[current_frame+1].size() - 1;
      mp.comment("current array index: " + to_string(index));
      // array_size = array_collection[current_frame+1][index].size;
      offset = array_collection[current_frame+1][index].array_add[mp.info.array_init_counter];
      mp.comment("offset: " + to_string(offset));
      mp.comment("counter: " + to_string(mp.info.array_init_counter));
      mp.comment("Number" + mp.info.result);
      mp.sw(2, offset, 30);
      mp.info.array_init_counter++;
    }
    break;

    case 1:
    left->compile(mp);//should add up previous counter
    if(in_frame == false)//if global
    {
      mp.comment("Global!!");
      current_frame = 0;
      right->compile(mp);//this should store all identifier address in mp;
      mp._word(mp.info.result);

      current_frame = temp_current_frame;
    }
    else
    {
      mp.comment("not Global!!");
      right->compile(mp);
      mp.comment("here?");

      //it's the last array in frame
      index = array_collection[current_frame+1].size() - 1;
      mp.comment("current array index: " + to_string(index));
      // array_size = array_collection[current_frame+1][index].size;
      offset = array_collection[current_frame+1][index].array_add[mp.info.array_init_counter];
      mp.comment("offset: " + to_string(offset));
      mp.comment("counter: " + to_string(mp.info.array_init_counter));
      mp.comment("Number" + mp.info.result);
      mp.sw(2, offset, 30);
      mp.info.array_init_counter++;
    }
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
}

void pointer::compile(mips& mp)const
{
  if(ptr == NULL)
  {

    mp.info.func_type = "*";
    // std::cerr << "/////////////inside pointer: " <<mp.info.func_type  <<'\n';
  }
  else{
    ptr -> compile(mp);
  }
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
  debug(cname);
  if(lt == NULL)
   {
     spec -> compile(mp);
   }
   else{
     spec -> compile(mp); // declaration_spec
     if(in_frame){
       mips another_mp;
       lt->compile(another_mp); // eg. a = 1;
       std::cerr << "another_mp.info.func_type: " << another_mp.info.func_type <<'\n';
       if(another_mp.info.func_type == "*") // got a pointer type
       {
         std::cerr << "pointer detected." << '\n';
         string pointer_type = mp.info.func_type + another_mp.info.func_type;
         std::cerr << "pointer type for pointer: " << pointer_type <<'\n';
         stack_collection[current_frame].back().type = pointer_type;
       }
       else{
         std::cerr << "pointer not detected." << '\n';
         stack_collection[current_frame].back().type = mp.info.func_type;//update type of variable
       }
     }
   }
}

void declarator::compile(mips&mp)const   // 	: pointer direct_declarator
{
    direct_decla -> compile(mp);
    std::cerr << "declarator 2: " << mp.info.func_type << '\n';
    ptr ->compile(mp);
    std::cerr << "declarator 1: " << mp.info.func_type << '\n';
    //mips another_mp;
    // direct_decla -> compile(mp);
}

void direct_abstract_declarator :: compile(mips& mp)const
{
  debug(cname);
  NotImplemented();
}

void expression_statement::compile(mips& mp)const
{
  ptr_expr->compile(mp);
}

void identifier_list::compile(mips& mp)const // should never be called ,KR style?
{
  NotImplemented();
}

void init_declarator_list::compile(mips& mp)const
{
  debug(cname);
  one -> compile(mp);
  mips another_mp;
  two -> compile(another_mp);
}

void relational_expression::compile(mips& mp)const{
  int l_index;
  int r_index;
  left->compile(mp);
  l_index = result_offset();
  mips another_mp;
  right->compile(another_mp);
  r_index = result_offset();
  mp.comment("load right index from memory");
  mp.lw(3,r_index,30);
  mp.comment("load left index from memory");
  mp.lw(2,l_index,30);
  switch (type) {
    case 0:
    mp.slt(2,2,3);
    break;
    case 1:
    mp.slt(2,3,2);//simply swap 2 and 3 registers
    break;
    case 2: //<=
    mp.sle(2,2,3);
    break;
    case 3: //>=
    mp.sge(2,2,3);
    break;
    case 4: // ==
    mp.seq(2,2,3);
    break;
    case 5: //!=
    mp.sne(2,2,3);
    break;
    case 6: //&
    mp._and(2,2,3);
    break;
    case 7:
    mp._xor(2,2,3);
    break;
    case 8:
    mp._or(2,2,3);
    break;
    case 9:// and
    //mp._and(3,2,3);//if eitehr $2,$3 is zero, will be evaluated as zero
    mp.li(8,"2");
    mp.li(9,"0");
    mp.sne(2,2,9);
    mp.sne(3,3,9);
    mp.add(2,2,3);//if $2 add up to 2, then both unequal to 0
    mp.seq(2,2,8);
    break;

    case 10: // or
    mp._or(3,2,3);//only both $2,$3 is zero, will be evaluated as zero
    mp.li(2,"0");
    mp.sne(2,2,3);
    break;
  }
  result_count = result_count - 4;
  mp.sw(2,result_offset(),30);
}

void conditional_expression::compile(mips& mp)const
{
  debug(cname);
  NotImplemented();
}

void base_expression::compile(mips& mp)const
{
  p_one -> compile(mp);
  mips another_mp;
  p_five ->compile(another_mp);
}

void abstract_declarator::compile(mips& mp)const
{
  left ->compile(mp);
  mips another_mp;
  right -> compile(another_mp);
}

// labeled_statement
// 	: IDENTIFIER ':' statement
// 	| CASE constant_expression ':' statement
// 	| DEFAULT ':' statement
// 	;
void labeled_statement::compile(mips& mp)const{
  debug(cname);
  string case_number;
  mips another_mp;
  string case_label = "Label " + to_string(labelcounter);
  string end_label;
  switch_content info;

  switch(type)
  {
    case 0:
    NotImplemented();//goto statement
    break;

    case 1:
    //get switch finish label
    end_label = mp.switch_info[0].case_num;

    mp.add_label(case_label);
    one->compile(another_mp);//obtain case number(in $2)
    case_number = another_mp.info.result;
    two->compile(mp);//evaluate statement

    mp.b(end_label);
    mp.nop();

    //store info for this case
    info.case_num = case_number;
    info.label = case_label;
    mp.switch_info.push_back(info);

    labelcounter++;

    case 2:
    mp.add_label(case_label);
    one->compile(mp);//evaluate statement
    mp.b(end_label);
    mp.nop();

    //store info for this case
    info.case_num = "default";
    info.label = case_label;
    mp.switch_info.push_back(info);

    labelcounter++;

  }
}

void enum_specifier :: compile(mips& mp)const
{
  debug(cname);
  mp.enum_count = 0;
  in_enum = true;
  debug(cname);
  switch (type) {
    case 0:
    ptr ->compile(mp);
    break;
    case 1:
    ptr ->compile(mp);
    mp.info.func_name = enum_name;//what to do with this name, in doubt
    break;
    case 2:
    mp.info.func_name = enum_name;//don't do anything,just a declaration, what about implementation
    break;
  }
  in_enum = false;
}

void enumerator_list :: compile(mips& mp)const
{
  debug(cname);
  left -> compile(mp);
  //mips another_mp;
  right -> compile(mp);
}

void enumerator :: compile(mips& mp)const
{ // special case of use for enum, address field used to store the value
  debug(cname);
  if(ptr == NULL){
    stack_content tmp = {id, mp.enum_count, "int"};
    enum_var.push_back(tmp);
    mp.enum_count++;
  }
  else{
    ptr -> compile(mp);
    mp.enum_count = std::stoi(mp.info.result);
    stack_content tmp = {id, mp.enum_count, "int"};
    enum_var.push_back(tmp);
    mp.enum_count++;
  }
}
