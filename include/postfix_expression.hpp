#ifndef ast_postfix_expression
#define ast_postfix_expression

#include "ast.hpp"

// postfix_expression
// 	: primary_expression                                   {$$ = $1;}
// 	| postfix_expression '[' expression ']'                {$$ = new unary_expression(0, $1, $3);}
// 	| postfix_expression '(' ')'                           {$$ = new unary_expression(1, $1);}
// 	| postfix_expression '(' argument_expression_list ')'  {$$ = new unary_expression(2, $1, $3);}
// 	| postfix_expression '.' IDENTIFIER                    {$$ = new unary_expression(3, $1, $3);}
// 	| postfix_expression PTR_OP IDENTIFIER                 {$$ = new unary_expression(4, $1, *$3);}
// 	| postfix_expression INC_OP                            {$$ = new unary_expression(5, $1);}
// 	| postfix_expression DEC_OP                            {$$ = new unary_expression(6, $1);}
// 	;


class postfix_expression : public expression{
public:
  postfix_expression(int type_in, treeptr p, treeptr o){type = type_in; ptr = p; opt = o;}
  postfix_expression(int type_in, treeptr p){type = type_in; ptr = p;}
  postfix_expression(int type_in, treeptr p, string _id){type = type_in; ptr = p; id = _id;}
  ~postfix_expression(){delete ptr; delete opt;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  string id;
  treeptr ptr;
  treeptr opt;
  string cname = "postfix_expression";
};


// void postfix_expression::compile(mips& mp)const{
//   debug(cname);
//   switch (type) {
//     case 0://array?
//     std::cerr << "array" << '\n';
//     break;
//     case 1:
//     ptr->compile(mp);
//     mp.jal(mp.info.func_name ); //maybe need to add f()?
//     mp.nop();
//     break;
//     case 2: //postfix_expression '(' argument_expression_list ')'
//     ptr->compile(mp);
//     string function_name = mp.info.func_name;
//     mips another_mp;
//     opt -> compile(another_mp);
//     mp.jal(function_name);
//     if(caller_arg_count > arg_count_collection[current_frame]){
//       arg_count_collection[current_frame] = caller_arg_count;
//     }
//     caller_arg_count = 0; // set it back for next function callee
//     mp.nop();
//     break;
//     case 3:
//     NotImplemented();
//     break;
//     case 4:
//     NotImplemented();
//     break;
//     case 5: // a++
//     //mips another_mp; //start a new mips class so info.result is empty at first
//     ptr -> compile(mp);
//     string variable_name = another_mp.info.func_name;
//     //mp.lw(2,find_variable(variable_name, stack_collection[current_frame]),30)
//     mp.addiu(2,2,1);
//     mp.sw(2,find_variable(variable_name, stack_collection[current_frame]),30);
//     break;
//     case 6: // a--
//     ptr -> compile(mp);
//     string variable_name = another_mp.info.func_name;
//     //mp.lw(2,find_variable(variable_name, stack_collection[current_frame]),30)
//     mp.addiu(2,2,-1);
//     mp.sw(2,find_variable(variable_name, stack_collection[current_frame]),30);
//     break;
//   }
// }



// void postfix_expression::compile(mips& mp)const{
//   debug(cname);
//   mips another_mp;
//   string variable_name;
//   string function_name;
//   int offset;
//   switch (type) {
//     case 0://read from array
//     ptr->compile(another_mp);//fill array name (in all frame arrays)
//     string name = another_mp.info.call_array_name;
//     int array_index = find_array(name);//index of array in all arrays of current frame
//
//     opt->compile(mp);//should store index in $2; store index in info.result
//     int index = stoi(mp.info.result);//array element index
//     // mp.sll(2, 2, 2);//x4 to get byte increment
//     int offset = array_collection[current_frame][array_index].array_add[0];
//     int increment = stoi(offset) + index * 4;
//     // mp.addi(2, 2, to_string(offset));
//     mp.sw(2, increment, 30);//store the result in $2; $2 stores the address
//     break;
//     case 1:
//     ptr->compile(mp);
//     mp.jal(mp.info.func_name ); //maybe need to add f()?
//     mp.nop();
//     break;
//     case 2: //postfix_expression '(' argument_expression_list ')'
//     ptr->compile(mp);
//     function_name = mp.info.func_name;
//     // mips another_mp;
//     opt -> compile(another_mp);
//     mp.jal(function_name);
//     mp.nop();
//     break;
//     case 3:
//     NotImplemented();
//     break;
//     case 4:
//     NotImplemented();
//     break;
//     case 5: // a++
//     //mips another_mp; //start a new mips class so info.result is empty at first
//     ptr -> compile(mp);
//     variable_name = another_mp.info.func_name;
//     //mp.lw(2,find_variable(variable_name, stack_collection[current_frame]),30)
//     mp.addiu(2,2,"1");
//     mp.sw(2,find_variable(variable_name, stack_collection[current_frame]),30);
//     break;
//     case 6: // a--
//     ptr -> compile(mp);
//     variable_name = another_mp.info.func_name;
//     //mp.lw(2,find_variable(variable_name, stack_collection[current_frame]),30)
//     mp.addiu(2,2,"-1");
//     mp.sw(2,find_variable(variable_name, stack_collection[current_frame]),30);
//     break;
//   }
// }

#endif
