#ifndef external_declaration_h
#define external_declaration_h
#include "ast.hpp"
// external_declaration
// 	: function_definition        {$$ = new external_declaration($1);std::cout << "external declaration 1" << std::endl;}
// 	| declaration                {$$ =  new external_declaration($1);std::cout << "external declaration 2" << std::endl;}/*global variable???*/
// 	;

class external_declaration: public astnode{
public:
  external_declaration(int _type,treeptr _ptr){type = _type;ptr = _ptr;}
  ~external_declaration(){
    delete ptr;
  }
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp)const override;
private:
  int type;
  treeptr ptr = NULL;
  string cname = "external_declaration";
};

// void external_declaration :: translate(string& pyout)const{
//   debug(cname);
//   switch (type) {
//     case 0:
//     ptr -> translate(pyout);
//     break;
//     case 1 :
//     ptr -> translate(pyout);
//     string pyout_truncate = pyout;
//     string::size_type pos = pyout.find("=");
//     pyout_truncate = pyout_truncate.substr (0,pos-1);
//     global_variables.push_back(pyout_truncate);
//     break;
//   }
// }

// void external_declaration::compile(mips& mp)const
// {
//   debug(cname);
//   //don't do anything yet
// };

#endif
