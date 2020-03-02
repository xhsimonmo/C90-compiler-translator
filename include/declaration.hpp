#ifndef declaration_h
#define declaration_h

#inclide "ast.hpp"

// declaration
// 	: declaration_specifiers ';'  {$$ = new declaration($1);}
// 	| declaration_specifiers init_declarator_list ';'  {$$ = new declaration($1, $2);}
// 	;

class declaration : public astnode{
public:
  declaration(treeptr _spec):spec(_spec){};
  declaration(treeptr _spec, treeptr _list):spec(_spec),list(_list){};
  virtual translate(string& pyout);
  ~declaration(){
    delete spec;
    delete list;
  }
private:
  treeptr spec = NULL;
  treeptr list = NULL;
};


void declaration::translate(string& pyout)
{
  if(list == NULL)
  {
    spec-> translate(pyout);
  }// actually we dont need to care about this for python?
  else{
    //omit declaration specifier(int, double) for python translation
    list->translate(pyout);
  }
}


#endif
