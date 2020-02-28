#ifndef ast_function_defintion
#define ast_function_defintion

#include "ast.hpp"

class function_defintion : public expression{
public:
  function_defintion(treeptr o, treeptr t, treeptr f){p_o = o; p_t = t; p_f = f;}
  ~function_defintion(){delete p_one; delete p_three; delete p_five};
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

  p_t->py(declarator);
  p_f->py(statement;

  pyout = "def" + declarator + ":/n" + statement + "/n";//喵喵喵
}

#endif
