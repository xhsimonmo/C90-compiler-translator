#ifndef primary_expression_h
#define primary_expression_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class primary_expression : public expression{
public:
  ~primary_expression(){
    delete expre_ptr;
  };
  primary_expression(int type, string _element):element(_element){};
  primary_expression(int type, treeptr _ptr):expre_ptr(_ptr){};

  void translate();//translate to Python
private:
  int type;
  string element;//either IDENTIFIER, CONSTANT, OR STRING_LITERAL
  treeptr expre_ptr;//the case (expression)
};

void primary_expression::translate(string& pyout)
{
  switch(type){
    case 0:
      pyout = element;
      break;

    case 1://constant representation in c different from python
      pyout = element;
      break;

    case 2:
      pyout = element;
      break;

    case 3:
      expre_ptr->translate(pyout);//for "(" expression ")"
      break;
  }

}

// string c2pyconstant(string cconst)
// {
//
// }
#endif
