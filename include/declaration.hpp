#ifndef declaration_h
#define declaration_h

#include "ast.hpp"

// declaration
// 	: declaration_specifiers ';'  {$$ = new declaration($1);}
// 	| declaration_specifiers init_declarator_list ';'  {$$ = new declaration($1, $2);}
// 	;

class declaration : public astnode{
public:
  declaration(treeptr _spec):spec(_spec){};
  declaration(treeptr _spec, treeptr _list):spec(_spec),lt(_list){};
  virtual void translate(string& pyout, vector<string> global_variables);
  ~declaration(){
    delete spec;
    delete lt;
  }
private:
  treeptr spec = NULL;
  treeptr lt = NULL;
};


void declaration::translate(string& pyout, vector<string> global_variables)
{
  if(lt == NULL)
  {
    spec-> translate(pyout);
  }// actually we dont need to care about this for python?
  else{
    //omit declaration specifier(int, double) for python translation
    lt->translate(pyout);
  }
  global_variables.push_back(pyout);
}


#endif
