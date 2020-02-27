#ifndef selection_statement_h
#define selection_statement_h

// selection_statement
// 	: IF '(' expression ')' statement
// 	| IF '(' expression ')' statement ELSE statement
// 	| SWITCH '(' expression ')' statement //no translation for switch
// 	;

class selection_statement : public statement
{
public:
  selection_statement(int _type, treeptr a, treeptr b ):type(_type),expre_ptr(a),ifsta(b){
  };
  selection_statement(int _type, treeptr a, treeptr b, treeptr c ):type(_type),expre_ptr(a),ifsta(b),elsesta(c){
  };
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
};


void selection_statement::translate(string& pyout)
{
  string expres, ifs,elses;
  expre_ptr -> translate(expres);
  ifsta -> translate(ifs);
  switch (type) {
    case 0:
    pyout = "if(" + expres + "):" + '\n'  ;
    break;
    case 1:
    break;
    case 2:
    NotImplemented();
    break;
  }
}




#endif
