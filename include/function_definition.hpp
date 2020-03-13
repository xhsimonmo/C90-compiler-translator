#ifndef ast_function_definition
#define ast_function_definition

#include "ast.hpp"


// function_definition
// 	/*: declaration_specifiers declarator declaration_list compound_statement  喵喵喵*/
// 	: declaration_specifiers declarator compound_statement                   {$$ = new function_definition($1, $2, $3);}
// 	/*| declarator declaration_list compound_statement                      喵喵喵*/
// 	| declarator compound_statement                                          {$$ = new function_definition($1, $2);}
// 	;

class function_definition : public definition{
public:
  function_definition(treeptr o, treeptr t, treeptr f){p_o = o; p_t = t; p_f = f;}
  function_definition(treeptr o, treeptr t){p_o = o; p_t = t;}
  ~function_definition(){delete p_o; delete p_t; delete p_f;}
  //void translate(string& pyout);
 inline void translate(string& pyout, vector<string> global_variables);
 inline void function_definition::compile(mips& mp);

private:
  treeptr p_o;
  treeptr p_t;
  treeptr p_f;
  string cname = "function_definition";
};

 void function_definition::translate(string& pyout, vector<string> global_variables){
  debug(cname);
  string specify;
  string declarator;
  string statement;
  string global;

  p_t->translate(declarator);
  p_f->translate(statement);
  for (int i = 0; i < global_variables.size(); i++)
  {
    global = global + "global " + global_variables[i] + "\n";
  }
  pyout = "def" + declarator + ":/n" + global + statement + "/n";//喵喵喵
}

void function_definition::compile(mips& mp)
{
  p_t->compile(mp);
  mp.add_frame(mp.stack_name);
  
  mp.mpcode.push_back(code);

}

#endif
