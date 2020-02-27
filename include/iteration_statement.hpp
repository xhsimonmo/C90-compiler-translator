#ifndef iteration_statement_h
#define iteration_statement_h
#include "ast.hpp"


// iteration_statement
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
private:
	int type;
	treeptr yi = NULL;
	treeptr er = NULL;
	treeptr san = NULL;
	treeptr si = NULL;
};

void iteration_statement::translate(string& pyout){
	switch (type) {
		string ones, twos, threes, fours;
		case 0:
		yi -> translate(ones);
		er -> translate(twos);
		pyout = "while (" + ones + "):" + '\n' + indent(twos) + '\n';
		break;
		default:
		NotImplemented();
		break;
	}

}


#endif
