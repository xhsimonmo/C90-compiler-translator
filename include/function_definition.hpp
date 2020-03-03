#ifndef ast_function_defintion
#define ast_function_defintion

#include "ast.hpp"

// function_definition
// 	: declaration_specifiers declarator declaration_list compound_statement
// 	| declaration_specifiers declarator compound_statement
// 	| declarator declaration_list compound_statement
// 	| declarator compound_statement
// 	;

class function_defintion : public definition{
public:
  function_defintion(treeptr o, treeptr t, treeptr f){p_o = o; p_t = t; p_f = f;}
  ~function_defintion(){delete p_one; delete p_three; delete p_five;}
  void translate(string& pyout);
private:
  treeptr p_o;
  treeptr p_t;
  treeptr p_f;
};

void function_defintion::translate(string& pyout){
  string specify;
  string declarator;
  string statement;
  string global;

  p_t->py(declarator);
  p_f->py(statement;
  for (int i = 0; i < global_variable.size(); i++)
  {
    global = global + "global " + global_variable[i] + "\n";
  }
  pyout = "def" + declarator + ":/n" + global + statement + "/n";//喵喵喵
}

#endif
