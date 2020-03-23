#ifndef declaration_h
#define declaration_h

#include "ast.hpp"

// declaration
// 	: declaration_specifiers ';'  {$$ = new declaration($1); std::cout << "declaration 0 " << std::endl;}
// 	| declaration_specifiers init_declarator_list ';'  {$$ = new declaration($1, $2);std::cout << "declaration 1 " << std::endl;}
// 	;


class declaration : public astnode{
public:
  declaration(treeptr _spec):spec(_spec){};
  declaration(treeptr _spec, treeptr _list):spec(_spec),lt(_list){};
  virtual void translate(string& pyout)const override;
 virtual void compile(mips& mp) const override;
private:
  treeptr spec = NULL;
  treeptr lt = NULL;
  string cname = "declaration";
};
// 
// void declaration::compile(mips& mp)const
// {
//   if(lt == NULL)
//    {
//      spec -> compile(mp);
//    }
//    else{
//      spec -> compile(mp);
//      mips another_mp;
//      list->compile(another_mp);
//    }
// }

// void declaration::translate(string& pyout) const
// {
//   string s_spec, s_list;
//   debug(cname);
//   if(lt == NULL)
//   {
//     spec -> translate(pyout);
//   }
//   else{
//     //omit declaration specifier(int, double) for python translation
//     spec-> translate(s_spec);
//     lt-> translate(s_list);
//     pyout = s_spec + s_list;
//   }
// }



#endif
