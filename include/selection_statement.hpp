#ifndef selection_statement_h
#define selection_statement_h
#include "ast.hpp"

// selection_statement
// 	: IF '(' expression ')' statement    {$$ = new selection_statement(0, $3, $5);std::cerr << "selection_statement 0" << std::endl;}
// 	| IF '(' expression ')' statement ELSE statement   {$$ = new selection_statement(1, $3, $5, $7);std::cerr << "selection_statement 1" << std::endl;}
// 	| SWITCH '(' expression ')' statement    {$$ = new selection_statement(2, $3, $5);std::cerr << "selection_statement 2" << std::endl;}
// 	;

class selection_statement : public statement
{
public:
  selection_statement(int _type, treeptr a, treeptr b ):type(_type),expre_ptr(a),ifsta(b){
  };
  selection_statement(int _type, treeptr a, treeptr b, treeptr c ):type(_type),expre_ptr(a),ifsta(b),elsesta(c){
  };
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  ~selection_statement(){
    delete expre_ptr;
    delete ifsta;
    delete elsesta;
  }

private:
  int type;
  treeptr expre_ptr = NULL;
  treeptr ifsta = NULL;
  treeptr elsesta = NULL;
  string cname = "selection_statement";
};


// void selection_statement::translate(string& pyout) const
// {
//   debug(cname);
//   string expres, ifs,elses;
//   expre_ptr -> translate(expres);
//   ifsta -> translate(ifs);
//   switch (type) {
//     case 0:
//     //indentation++;
//     pyout = "if " + expres + ":" + '\n' + indent(ifs) ;
//     break;
//     case 1:
//     elsesta->translate(elses);
//     pyout = "if " + expres + ":" + '\n' + indent(ifs) + "else:" + '\n'+ indent(elses) + '\n';
//     break;
//     case 2: //no required to translate switch
//     NotImplemented();
//     break;
//   }
// }

// void selection_statement::compile(mips& mp)const
// {
//   string below_if = "Selection" + to_string(labelcounter);//make label
//   labelcounter++;
//   mips expre_mp;
//   expre_ptr->compile(expre_mp);
//
//   string else_label = "Selection" + to_string(labelcounter);//label when else start
//   labelcounter++;
//
//   mp.switch(type)
//   {
//     case 0:
//     mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
//     beq(2, 0, below_if);//if false, skip if statement, jump to the content below if statement;
//     nop();
//     //then make the if statement(if is true)
//     mips sta_mp;
//     ifsta->compile(sta_mp);
//     add_label(below_if);
//     break;
//
//     case 1:
//     mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
//     beq(2, 0, else_label);//if false f=go to else
//     nop();
//     //then make the if statement(if is true)
//     mips sta_mp;
//     ifsta->compile(sta_mp);
//     b(below_if);
//
//     //else statement
//     add_label(else_label);
//     mips s_mp;
//     s_mp->compile(s_mp);
//     add_label(below_if);
//     break;
//
//     case 2:
//     //switch statement
//     mp.lw(2, expre_mp.info.result_index, 30);//store expression result in r2
//     beq(2, 0, below_if);//if false, skip if statement, jump to the content below if statement;
//     nop();
//     //then make the if statement(if is true)
//     mips sta_mp;
//     ifsta->compile(sta_mp);
//     add_label(below_if);
//     break;
//
//   }




#endif
