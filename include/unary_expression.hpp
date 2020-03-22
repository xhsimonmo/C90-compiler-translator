#ifndef ast_unary_expression
#define ast_unary_expression

#include "ast.hpp"

// unary_expression
// 	: postfix_expression               {$$ = $1;}
// 	| INC_OP unary_expression          {$$ = new unary_expression(0, $2);}
// 	| DEC_OP unary_expression          {$$ = new unary_expression(1, $2);}
// 	| unary_operator cast_expression   {$$ = new unary_expression($1, $2);}
// 	| SIZEOF unary_expression          {$$ = new unary_expression(2, $2);}
// 	| SIZEOF '(' type_name ')'         {$$ = new unary_expression(3, $2);}
// 	;


// unary_operator
// 	: '&'      {$$ = 4; std::cerr << "unary operator 1" << std::endl;}
// 	| '*'      {$$ = 5; std::cerr << "unary operator 2" << std::endl;}
// 	| '+'      {$$ = 6; std::cerr << "unary operator 3" << std::endl;}
// 	| '-'      {$$ = 7; std::cerr << "unary operator 4" << std::endl;}
// 	| '~'      {$$ = 8; std::cerr << "unary operator 5" << std::endl;}
// 	| '!'      {$$ = 9; std::cerr << "unary operator 6" << std::endl;}
// 	;

class unary_expression : public expression{
public:
  unary_expression(int type_in, treeptr p){type = type_in; ptr = p;}
  ~unary_expression(){delete ptr;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  // inline void compile(string& mpout);
private:
  int type;
  treeptr ptr = NULL;
  string cname = "unary_expression";
};

// void unary_expression::compile(mips& mp)const
// {
//   mp.switch(type)
//   {
//     case 0:
//     ptr->compile(mp);
//     mp.addiu(2, 2, 1);
//     mp.sw(2,mp.info.var_index,30);
//     break;
//
//     case 1:
//     ptr->compile(mp);
//     mp.addiu(2, 2, -1);
//     mp.sw(2,mp.info.var_index,30);
//     break;
//
//     case 2: //sizeof
//     NotImplemented();
//     break;
//     case 3: //sizeof ()
//     NotImplemented();
//     break;
//     case 4:// &
//     NotImplemented();
//     break;
//     case 5: // *
//     NotImplemented();
//     break;
//     case 6: // +
//     ptr->compile(mp);
//     break;
//     case 7: // -
//     ptr -> compile(mp);
//     mp.li(3,-1);
//     mp.mult(2,3)
//     mp.mflo(2);
//     mp.sw(2,mp.info.var_index,30);
//     break;
//     case 8: // ~ bit wise NOT
//     mp.li(3,-1); // -1 is 111111 for xor
//     mp._xor(2,2,3);
//     mp.sw(2,mp.info.var_index,30);
//     break;
//     case 9: // !
//     NotImplemented();
//     break;
//
//   }
// }

// void unary_expression::translate(string& pyout) const{
//   debug(cname);
//   switch (type)
//   {
//     case 0:
//     ptr->translate(pyout);
//     pyout = pyout + "+=1";
//     break;
//
//     case 1:
//     ptr->translate(pyout);
//     pyout = pyout + "-=1";
//     break;
//
//     // case "&":
//     // ptr->translate(pyout);
//     // pyout = "&" + pyout;
//     // break;
//
//     case 5:
//     ptr->translate(pyout);
//     pyout = "*" + pyout;
//     break;
//
//     case 6:
//     ptr->translate(pyout);
//     pyout = "+" + pyout;
//     break;
//
//     case 7:
//     ptr->translate(pyout);
//     pyout = "-" + pyout;
//     break;
//
//     // case "~":
//     // ptr->translate(pyout);
//     // pyout = "~" + pyout;
//     // break;
//     //
//     // case "!":
//     // ptr->translate(pyout);
//     // pyout = "!" + pyout;
//     // break;
//
//     case 2:
//     ptr->translate(pyout);
//     pyout = "sys.getsizeof(" + pyout + ")";
//     break;
//
//     case 3:
//     ptr->translate(pyout);
//     pyout = "sys.getsizeof(" + pyout + ")";
//     break;
//
//     default:
//     NotImplemented();
//   }
// }

// inline void unary_expression::compile(string& dst){
//   switch(type)
//   {
//     case 0:
//     ptr->compile(dst);
//     mips.addi(dst, dst, "1");
//     break;
//
//     case 1:
//     ptr->compile(dst);
//     mips.addi(dst, dst, "-1");
//     break;
//
//   }
//
// }



#endif
