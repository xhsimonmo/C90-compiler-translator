#ifndef jump_statement_h
#define jump_statement_h

#include "ast.hpp"

// jump_statement
// 	 //GOTO IDENTIFIER ';'   {$$ = new jump_statement(0, "GOTO");}  // no need to Implement this
// 	: CONTINUE ';'   {$$ = new jump_statement(1, "CONTINUE");std::cout << "jump_statement 1 " << std::endl;}
// 	| BREAK ';'    {$$ = new jump_statement(2, "BREAK");std::cout << "jump_statement 2 " << std::endl;}
// 	| RETURN ';'   {$$ = new jump_statement(3, "RETURN");std::cout << "jump_statement 3 " << std::endl;}
// 	| RETURN expression ';'    {$$ = new jump_statement(4, $2);std::cout << "jump_statement 4 " << std::endl;}
// 	;

class jump_statement : public statement{
public:
  jump_statement(int _type, string _id):type(_type),identifier(_id){};
  jump_statement(int _type, treeptr _ptr):type(_type),expre_ptr(_ptr){};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  ~jump_statement(){
    delete expre_ptr;
  }

private:
  int type;
  string identifier;
  treeptr expre_ptr = NULL;
  string cname = "jump_statement";
};

// void jump_statement::compile(mips& mp) const {
//   switch (type) {
//     case 0:
//     NotImplemented();
//     break;
//     case 1:
//     NotImplemented();
//     break;
//     case 2:
//     NotImplemented();
//     break;
//     case 3: // simply "return; " gives error
//     NotImplemented();
//     break;
//     case 4:
//     mips mp_tmp;
//     expre_ptr -> compile(mp_tmp);
//     mp.li(2,mp_tmp.info.result)
//     break;
//   }
// }


// void jump_statement::translate(string& pyout) const
// {
//   debug(cname);
//   string return_expression;
//   switch (type) {
//     case 3:
//     pyout = "return ";
//     break;
//     case 4 ://return
//     expre_ptr -> translate(return_expression);
//     pyout = "return " + return_expression + "\n";
//     break;
//
//     default :
//     NotImplemented();
//   }
// }



#endif
