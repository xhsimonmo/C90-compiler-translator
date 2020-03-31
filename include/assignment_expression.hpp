#ifndef ast_assignment_expression
#define ast_assignment_expression

#include "ast.hpp"

// assignment_expression
// 	: conditional_expression                                             {$$ = new assignment_expression($1); std::cerr << "assignment expression 1" << std::endl;}
// 	| unary_expression assignment_operator assignment_expression         {$$ = new assignment_expression($1, $2, $3); std::cerr << "assignment expression 2" << std::endl;}
// 	;
//
// assignment_operator
// 	: '='                {$$ = 0; std::cerr << "assignment operator 1" << std::endl;}
// 	| MUL_ASSIGN         {$$ = 1; std::cerr << "assignment operator 2" << std::endl;}
// 	| DIV_ASSIGN         {$$ = 2; std::cerr << "assignment operator 3" << std::endl;}
// 	| MOD_ASSIGN         {$$ = 3; std::cerr << "assignment operator 4" << std::endl;}
// 	| ADD_ASSIGN         {$$ = 4; std::cerr << "assignment operator 5" << std::endl;}
// 	| SUB_ASSIGN         {$$ = 5; std::cerr << "assignment operator 6" << std::endl;}
// 	| LEFT_ASSIGN        {$$ = 6; std::cerr << "assignment operator 7" << std::endl;}
// 	| RIGHT_ASSIGN       {$$ = 7; std::cerr << "assignment operator 8" << std::endl;}
// 	| AND_ASSIGN         {$$ = 8; std::cerr << "assignment operator 9" << std::endl;}
// 	| XOR_ASSIGN         {$$ = 9; std::cerr << "assignment operator 10" << std::endl;}
// 	| OR_ASSIGN          {$$ = 10; std::cerr << "assignment operator 11" << std::endl;}

class assignment_expression : public expression{
public:
  assignment_expression(treeptr o, int type_in, treeptr f){p_one = o; type = type_in; p_five = f;}
  assignment_expression(treeptr o){p_one = o;}
  ~assignment_expression(){delete p_one; delete p_five;};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr p_one = NULL;
  treeptr p_five = NULL;
  string cname = "assignment_expression";
};

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
      mp.isunary = false; // used to check whether got an *x type in lvalue
      p_one->compile(mp); // *x or x, $2 store the, isunary will be set true if got *x
      int index = mp.info.var_index;
      another_mp.info.func_type = mp.info.func_type;
      another_mp.isunary = mp.isunary;
      std::cerr << "///////////////////func type: " << another_mp.info.func_type << '\n';
      p_five->compile(another_mp);
      mp.nop();
      if(!mp.isunary){
      //std::cerr << "current functype in assignment:" <<mp.info.func_type << '\n';
       // if(mp.info.func_type.find('*') != std::string::npos)
       // {
       //  //std::cerr << " pointer assignment" << '\n';
       // }
       // else{
        //std::cerr << "non pointer assignment" << '\n';
        if(mp.info.array_element_add == 0)//index is constant
        {
          mp.sw(2, mp.info.var_index, 30);//index is variable
        }
        else{
          mp.lw(3, mp.info.array_element_add, 30);
          mp.sw(2, 0, 3);
          mp.info.array_element_add = 0;
        }
       // }
     }
     else{
       mp.move(3,2);
       mp.lw(2,index, 30);
       mp.sw(3,0,2);
     }
     mp.isunary = false;
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
      // mp.sw(2, mp.info.var_index, 30);
      if(mp.info.array_element_add == 0)//index is constant
      {
        mp.sw(2, mp.info.var_index, 30);//index is variable
      }
      else{
        mp.lw(3, mp.info.array_element_add, 30);
        mp.sw(2, 0, 3);
        mp.info.array_element_add = 0;
      }
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
      // mp.sw(2, mp.info.var_index, 30);
      if(mp.info.array_element_add == 0)//index is constant
      {
        mp.sw(2, mp.info.var_index, 30);//index is variable
      }
      else{
        mp.lw(3, mp.info.array_element_add, 30);
        mp.sw(2, 0, 3);
        mp.info.array_element_add = 0;
      }
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


// void assignment_expression::translate(string& pyout)const{
//   debug(cname);
//   string one;
//   string five;
//   if(p_five == NULL){
//       p_one->translate(pyout);
//   }
//   else{
//     p_one->translate(one);
//     p_five->translate(five);
//     switch (type)
//     {
//       case 0:
//       pyout = one + "=" + five;
//       break;
//
//       case 1:
//       pyout = one + "*=" + five;
//       break;
//
//       case 2:
//       pyout = one + "/=" + five;
//       break;
//
//       case 3:
//       pyout = one + "%=" + five;
//       break;
//
//       case 4:
//       pyout = one + "+=" + five;
//       break;
//
//       case 5:
//       pyout = one + "-=" + five;
//       break;
//
//       case 6:
//       pyout = one + "<<=" + five;
//       break;
//
//       case 7:
//       pyout = one + ">>=" + five;
//       break;
//
//       case 8:
//       pyout = one + "&=" + five;
//       break;
//
//       case 9:
//       pyout = one + "^=" + five;
//       break;
//
//       case 10:
//       pyout = one + "|=" + five;
//       break;
//
//     }
//   }
// }

#endif
