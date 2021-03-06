#ifndef ast_function_definition
#define ast_function_definition

#include "ast.hpp"


// function_definition
// 	: declaration_specifiers declarator compound_statement                   {std::cout << "function definition 1" << std::endl;$$ = new function_definition($1, $2, $3);}
//   | declarator compound_statement                                          {std::cout << "function definition 2" << std::endl;$$ = new function_definition($1, $2);}
// 	;

class function_definition : public definition{
public:
  function_definition(treeptr o, treeptr t, treeptr f){p_o = o; p_t = t; p_f = f;}
  function_definition(treeptr o, treeptr t){p_o = o; p_t = t;}
  ~function_definition(){delete p_o; delete p_t; delete p_f;}
 virtual void translate(string& pyout)const override;
 virtual void compile(mips& mp)const override;
 // inline void function_definition::compile(mips& mp);

private:
  treeptr p_o = NULL;
  treeptr p_t = NULL;
  treeptr p_f = NULL;
  string cname = "function_definition";
};

// void function_definition::compile(mips& mp)const
// {
//   // declarator;
//   if(p_f == NULL){ // only two parts
//       p_o->compile(mp);//compiler type specifier part; doesn't do anything yet? then add label, which is only known until compile direc_declarator
//       string declarator = mp.info.func_name;
//       declarator = declarator + ":";
//       stack_collection[current_frame].push_back(declarator);
//
//       //start function
//       mp.add_frame();
//
//       //compound statement
//       p_t->compile(mp);
//
//       //finish function
//       mp.finish_frame();
//   }
//   else{
//     p_o -> compile(mp);// type_specifier
//     p_t-> compile(mp);
//     //add label
//     string declarator = mp.info.func_name;
//     declarator = declarator + ":";
//     stack_collection[current_frame].push_back(declarator);
//
//     //start function
//     mp.add_frame();
//
//     //compound statement
//     p_f->compile(mp);
//
//     //finish function
//     mp.finish_frame();
//
//   }
//
// }

//  void function_definition::translate(string& pyout) const{
//   debug(cname);
//   string specify;
//   string declarator;
//   string statement;
//   string global;
//   if(p_f == NULL){
//     p_o->translate(declarator);
//     p_t->translate(statement);
//     for (int i = 0; i < global_variables.size(); i++)
//     {
//       global = global + "global " + global_variables[i] + "\n";
//     }
//     indentation++;
//     pyout = "def " + declarator + ":\n" + indent(global) + indent(statement) + "\n";
//     indentation--;
//   }
//   else{
//     p_o->translate(specify);
//     p_t->translate(declarator);
//     p_f->translate(statement);
//     for (int i = 0; i < global_variables.size(); i++)
//     {
//       global = global + "global " + global_variables[i] + "\n";
//     }
//     indentation++;
//     pyout = "def " + declarator + ":\n" + indent(global) + indent(statement) + "\n";
//     indentation--;
//   }
// }



#endif
