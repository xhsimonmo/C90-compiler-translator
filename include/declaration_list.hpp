#ifndef ast_declaration_list
#define ast_declaration_list

#include "ast.hpp"


// declaration_list
// 	/*: declaration_specifiers declarator declaration_list compound_statement  喵喵喵*/
// 	: declaration_specifiers declarator compound_statement                   {$$ = new declaration_list($1, $2, $3);}
// 	/*| declarator declaration_list compound_statement                      喵喵喵*/
// 	| declarator compound_statement                                          {$$ = new declaration_list($1, $2);}
// 	;

class declaration_list : public definition{
public:
  declaration_list(treeptr o, treeptr t){p_o = o; p_t = t;}
  ~declaration_list(){delete p_o; delete p_t;}
  //void translate(string& pyout);
 inline void translate(string& pyout, vector<string> global_variables);
private:
  treeptr p_o;
  treeptr p_t;
  string cname = "declaration_list";
};

 void declaration_list::translate(string& pyout, vector<string> global_variables){
  debug(cname);
  string l;
  string r;

  p_o->translate(l);
  p_t->translate(r);
  pyout = l + "\n" + r;
}

#endif
