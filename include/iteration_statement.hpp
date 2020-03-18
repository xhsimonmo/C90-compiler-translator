#ifndef iteration_statement_h
#define iteration_statement_h
#include "ast.hpp"

// 	: WHILE '(' expression ')' statement
// 	| DO statement WHILE '(' expression ')' ';'
// 	| FOR '(' expression_statement expression_statement ')' statement
// 	| FOR '(' expression_statement expression_statement expression ')' statement
// 	;

class iteration_statement : public statement{
public:
	iteration_statement(int _type, treeptr _yi, treeptr _er):type(_type), yi(_yi),er(_er){};
	iteration_statement(int _type, treeptr _yi, treeptr _er, treeptr _san):type(_type), yi(_yi),er(_er),san(_san){};
	iteration_statement(int _type, treeptr _yi, treeptr _er, treeptr _san, treeptr _si):type(_type), yi(_yi),er(_er),san(_san),si(_si){};
	~iteration_statement(){
		delete yi;
		delete er;
		delete san;
		delete si;
	}
	virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
	int type;
	treeptr yi = NULL;
	treeptr er = NULL;
	treeptr san = NULL;
	treeptr si = NULL;
	string cname = "iteration_statement";
};

// void iteration_statement::translate(string& pyout)const{
// 	debug(cname);
// 	string ones, twos, threes, fours;
// 	switch (type) {
// 		case 0:
// 		yi -> translate(ones);
// 		er -> translate(twos);
// 		pyout = "while (" + ones + "):" + '\n' + indent(twos) + '\n';
// 		break;
// 		default:
// 		NotImplemented();
// 		break;
// 	}
//
// }


// void iteration_statement::compile(mips& mp)const{
//
// 	string condition = "condition" + to_string(labelcounter);
// 	labelcounter++;
// 	mips cond_expr;
//
// 	string statement = "statement" + to_string(labelcounter);
// 	labelcounter++;
// 	mips state_expr;
//
// 	string for_s1 = "for_state" + to_string(labelcounter);
// 	labelcounter++;
// 	mips for_state1;//san
//
// 	string for_s2 = "for_state" + to_string(labelcounter);
// 	labelcounter++;
// 	mips for_state2;//si
//
//
// 	switch(type)
// 	{
// 		case 0:
// 		b(condition);
// 		nop();
//
// 		add_label(statement);
// 		er->compile(state_expr);//get statement
//
// 		add_label(condition);
// 		yi->compile(cond_expr);//get conidtion expression
// 		lw(2, cond_expr.temp_result.result_index, 30);//store expression result in r2
// 		bne(2, 0, statement);//if true go to statement
// 		nop();
//
// 		case 1://same as case 0, but condition and statement are reversed.
// 		b(statement);
// 		nop();
//
// 		add_label(condition);
// 		yi->compile(cond_expr);
//
// 		add_label(statement);
// 		er->compile(state_expr);
// 		lw(2, state_expr.temp_result.result_index, 30);//store expression result in r2
// 		bne(2, 0, condition);//if true go to statement
// 		nop();
//
// 		case 2:
// 		yi->compile(cond_expr);//make init part
// 		b();
// 		nop();
//
// 		//for loop statement branch
// 		add_label(for_s1);
// 		san->compile(for_state1);
//
// 		//for loop condition!!!not statement
// 		add_label(statement);
// 		er->compile(state_expr);//get statement
// 		lw(2, cond_expr.temp_result.result_index, 30);//store expression result in r2
// 		bne(2, 0, for_s1);//if true go to statement
// 		nop();
//
// 		case 3:
// 		yi->compile(cond_expr);//make init part
// 		b();
// 		nop();
//
// 		//for loop statement branch
// 		add_label(for_s2);
// 		si->compile(for_state2);
// 		//iteration expression
// 		san->compile(for_state1);
//
// 		//for loop condition!!!not statement
// 		add_label(statement);
// 		er->compile(state_expr);//get statement
// 		lw(2, cond_expr.temp_result.result_index, 30);//store expression result in r2
// 		bne(2, 0, for_s2);//if true go to statement
// 		nop();
// 	}
//
// }


#endif
