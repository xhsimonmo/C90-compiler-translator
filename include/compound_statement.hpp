#ifndef compound_statement_h
#define compound_statement_h

#include "ast.hpp"

// compound_statement
// 	: '{' '}'    {$$ = new compound_statement(0); std::cout << "compound_statement 0" << std::endl;}
// 	| '{' statement_list '}'   {$$ = new compound_statement(1, $2); std::cout << "compound_statement 1" << std::endl;}
// 	| '{' declaration_list '}'   {$$ = new compound_statement(2, $2); std::cout << "compound_statement 2" << std::endl;}
// 	| '{' declaration_list statement_list /*declaration list need to be in front of statement in c language"*/ '}'    {$$ = new compound_statement(3, $2, $3); std::cout << "compound_statement 3" << std::endl;}
// 	;

class compound_statement : public statement
{
public:
  compound_statement(int _type):type(_type){};
  compound_statement(int _type, treeptr _list):type(_type), left(_list){};
  compound_statement(int _type, treeptr dec_list, treeptr sta_list):type(_type), left(dec_list),right(sta_list){};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp)const override;
  ~compound_statement(){
    delete left;
    delete right;
  }
private:
  int type;
  treeptr left = NULL;//either statement_list or declaration_list
  treeptr right = NULL;//statement_list in type 3
  string cname = "compound_statement";
};

void compound_statement::compile(mips& mp)const{
  debug(name);
  //dont do things yet;
}



// void compound_statement::translate(string& pyout) const{
//   debug(cname);
//   string ds, ss;
//   switch (type) {
//     case 0:
//     break;//do nothing?
//     case 1:
//     // indentation++; //encounter "{"
//     std::cerr << "compound_statement type 1 " << '\n';
//     left->translate(pyout);
//     // indentation--; //exit with "}"
//     break;
//     case 2:
//     // indentation++; //encounter "{"
//     left->translate(pyout);
//     // indentation--; //exit with "}"
//     break;
//     case 3:
//     // indentation++;
//     left->translate(ds);
//     right->translate(ss);
//     // indentation--;
//     pyout = ds + '\n' + ss;
//     break;
//
//   }
// }

#endif
