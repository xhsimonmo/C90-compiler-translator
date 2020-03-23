#ifndef ast_declaration_list
#define ast_declaration_list

#include "ast.hpp"


// declaration_list
// 	: declaration                      {$$ = $1; std::cerr << "declaration list 1" << std::endl;}
// 	| declaration_list declaration     {$$ = new declaration_list($1, $2); std::cerr << "declaration list 2" << std::endl;}
// 	;


class declaration_list : public astnode{
public:
  declaration_list(treeptr o, treeptr t){p_o = o; p_t = t;}
  ~declaration_list(){delete p_o; delete p_t;}
  //void translate(string& pyout);
 virtual void translate(string& pyout)const override;
virtual void compile(mips& mp) const override;
private:
  treeptr p_o;
  treeptr p_t;
  string cname = "declaration_list";
};

// void declaration_list::compile(mips& mp)const{
//   p_o -> compile(mp);
//   mips another_mp;
//   p_t ->compile(another_mp);
// }

//  void declaration_list::translate(string& pyout)const{
//   debug(cname);
//   string l;
//   string r;
//
//   p_o->translate(l);
//   p_t->translate(r);
//   pyout = l + "\n" + r;
// }

#endif
