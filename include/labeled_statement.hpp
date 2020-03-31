#ifndef labeled_statement_h
#define labeled_statement_h

#include "ast.hpp"

// labeled_statement
// 	: IDENTIFIER ':' statement
// 	| CASE constant_expression ':' statement
// 	| DEFAULT ':' statement
// 	;

class labeled_statement : public statement{
public:
  labeled_statement(int _type, treeptr _one):type(_type),one(_one){};
  labeled_statement(int _type, treeptr _one, treeptr _two):type(_type),one(_one),two(_two){};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  ~labeled_statement(){
    delete one;
    delete two;
  };
private:
  int type;
  treeptr one = NULL;
  treeptr two = NULL;
  string cname = "labeled_statement";
};

// void labeled_statement::compile(mips& mp)const{
//   debug(cname);
//   string case_number;
//   mips another_mp;
//   string case_label = "Label " + to_string(labelcounter);
//   string end_label;
//   switch_content info;
//
//   switch(type)
//   {
//     case 0:
//     NotImplemented();//goto statement
//     break;
//
//     case 1:
//     //get switch finish label
//     //end_label = mp.switch_info[0].case_num;
//     //end_label = mp.switch_info[0].label;
//
//     mp.add_label(case_label);
//     one->compile(another_mp);//obtain case number(in $2)
//     case_number = another_mp.info.result;
//     two->compile(mp);//evaluate statement
//
//     //mp.b(end_label);
//     mp.nop();
//
//     //store info for this case
//     info.case_num = case_number;
//     info.label = case_label;
//     mp.switch_info.push_back(info);
//
//     labelcounter++;
//
//     case 2:
//     mp.add_label(case_label);
//     one->compile(mp);//evaluate statement
//     mp.b(end_label);
//     mp.nop();
//
//     //store info for this case
//     info.case_num = "default";
//     info.label = case_label;
//     mp.switch_info.push_back(info);
//
//     labelcounter++;
//
//   }
// }

// void labeled_statement::translate(string& pyout) const{
//   debug(cname);
//   NotImplemented();
// }

//no tranlation to python required?

#endif
