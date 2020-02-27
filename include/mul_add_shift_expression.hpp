#ifndef mul_add_shift_h
#define mul_add_shift_h

#include "ast.hpp"
class multiplicative_expression : public expression{
  public:
    //multiplicative_expression(int _type, treeptr _cast):type(_type),cast(_cast){};
    multiplicative_expression(int _type, treeptr _mul, treeptr _cast):type(_type),mul(_mul),cast(_cast){};
    ~multiplicative_expression(){
      delete mul;
      delete cast;
    };
  private:
    int type;
    treeptr mul, cast;
};

void multiplicative_expression::translate(string& pyout)
{
  string ls, rs;
  l -> translate(ls);
  r -> translate(rs);
  switch(type){
    // case 0:
    // cast->translate(pyout);
    // break;

    case 1:
    pyout = mul -> translate(ls) + "*" + cast -> translate(rs)+'/n';
    break;

    case 2:
    pyout = mul -> translate(ls) + "/" + cast -> translate(rs)+'/n';
    break;

    case 3:
    pyout = mul -> translate(ls) + "%" + cast -> translate(rs)+'/n';
    break;

  }
}


/////////////////////////////////////additive_expression///////////////////////////////////////////////////

class additive_expression : public expression{
  public:
    //additive_expression(int _type, treeptr _cast):type(_type),mul(_cast){};
    additive_expression(int _type, treeptr _add, treeptr _mul):type(_type),add(_add),mul(_mul){};
    ~additive_expression(){
      delete l, r;
    };
  private:
    int type;
    treeptr add, mul;
};

void additive_expression:: translate(string& pyout)
{
  string ls, rs;
  l -> translate(ls);
  r -> translate(rs);
  switch(type){
    // case 0:
    // mul->translate(pyout);
    // break;

    case 1:
    pyout = ls + "+" + rs+'/n';
    break;

    case 2:
    pyout = ls + "_" + rs+'/n';
    break;
  }
}

/////////////////////////////////////bitwise_shift_expression///////////////////////////////////////////////////

// shift_expression
// 	: additive_expression
// 	| shift_expression LEFT_OP additive_expression
// 	| shift_expression RIGHT_OP additive_expression

class shift_expression : public expression{
  public:
    //shift_expression(int _type, treeptr _cast):type(_type),mul(_cast){};
    shift_expression(int _type, treeptr _shift, treeptr _add):type(_type),l(_shift),r(_add){};
    ~additive_expression(){
      delete l, r;
    };
  private:
    int type;
    treeptr l, r;
};

void shift_expression:: translate(string& pyout)
{
  string ls, rs;
  l -> translate(ls);
  r -> translate(rs);
  switch(type){
    // case 0:
    // mul->translate(pyout);
    // break;

    case 1:
    pyout = ls + "<<" + rs+'/n';
    break;

    case 2:
    pyout = ls + ">>" + rs+'/n';
    break;
  }
}

#endif
