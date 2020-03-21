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


// void postfix::compile(mips& mp)const{
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



// void postfix_expression::translate(string& pyout) const{
//   debug(cname);
// std::string op;
// switch (type)
// {
//   case 0:
//   ptr->translate(pyout);
//   pyout = pyout + "()";
//   break;
//
//   case 1:
//   ptr->translate(pyout);
//   pyout = pyout + "()";
//   break;
//
//   case 2:
//   ptr->translate(pyout);
//   opt->translate(op);
//   pyout = pyout + "(" + op + ")";
//   break;
//
//   case 3:
//   ptr->translate(pyout);
//   opt->translate(op);
//   pyout = pyout + "." + op;
//   break;
//
//   // case 4:
//   // ptr->translate(pyout);
//   // pyout = pyout + "->7" + element;
//   // break;
//
//
//   case 5:
//   ptr->translate(pyout);
//   pyout = pyout + "+=1";
//   break;
//
//   case 6:
//   ptr->translate(pyout);
//   pyout = pyout + "-=1";
//   break;
//
//   default:
//   NotImplemented();
//  }
// }

#endif
