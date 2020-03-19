#ifndef parameter_declaration_h
#define parameter_declaration_h

#include "ast.hpp"

// parameter_declaration
// 	: declaration_specifiers declarator             {$$ = new parameter_declaration(0, $1, $2)}
// 	| declaration_specifiers abstract_declarator    {$$ = new parameter_declaration(1, $1, $2)}
// 	| declaration_specifiers/*喵喵喵*/                   {$$ = new parameter_declaration(2, $1)}
// 	;

class parameter_declaration : public astnode{
public:
  parameter_declaration(int type_in, treeptr o, treeptr t){type = type_in; left = o; right = t;}
  parameter_declaration(int type_in, treeptr o){type = type_in; left = o;}
  ~parameter_declaration(){delete left; delete right;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr left = NULL;
  treeptr right = NULL;
  string cname = "parameter_declaration";
};

// void parameter_declaration :: compile(mips& mp) const{
//   if(right == NULL){
//     left -> compile(mp); // e,g int
//   }
//   else{
//     left -> compile(mp); // e,g int
//     mips another_mp; // the get the name of declarator
//     right -> compile(another_mp);
//     string variable_name = another_mp.info.func_name;//get name of variable, like a;
//     int availability = arg_check();
//     int arg_reg = availability + 4;
//     if(arg_reg >= 4){
//       mp.sw(arg_reg, ((arg_reg-4)*4+12) , 30);//point upwards add 12 because we have ra and sp stored in beginning
//       stack_collection[current_frame].push_back(variable_name, ((arg_reg-4)*4+12));
//     }
//     else{ //case when more than 4 arguments
//         stack_collection[current_frame].push_back(variable_name, (12+16+4*arg_overflow));
//         arg_overflow++;
//     }
//   }
// }

// void parameter_declaration::translate(string& pyout) const{
//   debug(cname);
//   string yi;
//   string er;
//   left -> translate(yi);
//   right -> translate(er);
//   switch(type)
//   {
//     case 0:
//     pyout = er;
//     break;
//     case 1:
//     NotImplemented();
//     break;
//     case 2:
//     NotImplemented();
//     break;
//   }
// }

#endif
