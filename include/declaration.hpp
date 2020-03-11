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
   virtual void translate(string& pyout)const {debug(cname);};
   virtual void translate(string& pyout, vector<string> global_variables)const {
     debug(cname);
     if(lt == NULL)
     {
       std::cout << "lt == NULL" << '\n';
       spec-> translate(pyout);
     }// actually we dont need to care about this for python?
     else{
       //omit declaration specifier(int, double) for python translation
       std::cout << "lt != NULL" << '\n';

       lt->translate(pyout);
     }
     global_variables.push_back(pyout);
   };
  ~declaration(){
    delete spec;
    delete lt;
  }
private:
  treeptr spec = NULL;
  treeptr lt = NULL;
  string cname = "declaration";
};


// void declaration::translate(string& pyout, vector<string> global_variables)
// {
//   debug(cname);
//   if(lt == NULL)
//   {
//     spec-> translate(pyout);
//   }// actually we dont need to care about this for python?
//   else{
//     //omit declaration specifier(int, double) for python translation
//     lt->translate(pyout);
//   }
//   global_variables.push_back(pyout);
// }
//
//  void declaration::translate(string& pyout){
//   debug(cname);
// };


#endif
