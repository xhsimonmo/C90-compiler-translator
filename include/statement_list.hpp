#ifndef statement_list_h
#define statement_list_h

#include "ast.hpp"

// statement_list
// 	: statement    {$$ = $1; std::cerr << "statement_list 0" << std::endl;}
// 	| statement_list statement   {$$ = new statement_list($1,$2); std::cerr << "statement_list 1" << std::endl;}
// 	;

class statement_list : public statement{
public:
  statement_list(treeptr list, treeptr _statement):l(list),r(_statement){};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  ~statement_list(){
    delete l;
    delete r;
  }
private:
  treeptr l, r;
  string cname = "statement_list";
};

// void statement_list::compile(mips& mp)const{
//   l -> compile(mp);
//   mips another_mp;
//   r -> compile (another_mp);
// }

// void statement_list::translate(string& pyout) const
// {
//   debug(cname);
//   string ls, rs;
//   l -> translate(ls);
//   r -> translate(rs);
//   pyout = ls +'\n' + rs + '\n';
// }

#endif
