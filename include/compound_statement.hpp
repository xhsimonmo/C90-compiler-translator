#ifndef compound_statement_h
#define compound_statement_h

#include <iostream>
#include <vector>



using namespace std;

// compound_statement
// 	: '{' '}'
// 	| '{' statement_list '}'
// 	| '{' declaration_list '}'
// 	| '{' declaration_list statement_list '}'
// 	;

class compound_statement : public statement
{
public:
  compound_statement(int _type):type(_type);
  compound_statement(int _type, treeptr _list):type(_type), left(_list);
  compound_statement(int _type, treeptr dec_list, treeptr sta_list):type(_type), left(dec_list),right(sta_list);
  ~compound_statement(){
    delete left;
    delete right;
  }
private:
  int type;
  treeptr left;//either statement_list or declaration_list
  treeptr right;//statement_list in type 3
};


void compound_statement::translate(string& pyout){
  switch (type) {
    case 0:
    break;//do nothing?
    case 1:
    left->translate(pyout);
    break;
    case 2:
    left->translate(pyout);
    break
    case 3:
    string ds, ss;
    pyout = left->translate(ds) + '/n' + right->translate(ss);;
    break;

  }
}

#endif
