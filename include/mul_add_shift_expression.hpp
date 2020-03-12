#ifndef mul_add_shift_h
#define mul_add_shift_h

#include "ast.hpp"

// multiplicative_expression
// 	: cast_expression {$$ = $1}
// 	| multiplicative_expression '*' cast_expression  {$$ = new multiplicative_expression(1,$1, $3);}
// 	| multiplicative_expression '/' cast_expression  {$$ = new multiplicative_expression(2,$1, $3);}
// 	| multiplicative_expression '%' cast_expression  {$$ = new multiplicative_expression(3,$1, $3);}
// 	;

class multiplicative_expression : public expression{
  public:
    //multiplicative_expression(int _type, treeptr _cast):type(_type),cast(_cast){};
    multiplicative_expression(int _type, treeptr _mul, treeptr _cast):type(_type),mul(_mul),cast(_cast){};
    virtual void translate(string& pyout)const override;
    ~multiplicative_expression(){
      delete mul;
      delete cast;
    }
  private:
    int type;
    treeptr mul;
    treeptr cast;
    string cname = "multiplicative_expression";
};

// void multiplicative_expression::translate(string& pyout) const
// {
//   debug(cname);
//   string ls, rs;
//   mul -> translate(ls);
//   cast -> translate(rs);
//   switch(type){
//     // case 0:
//     // cast->translate(pyout);
//     // break;
//
//     case 1:
//     pyout = ls + "*" + rs + "/n";
//     break;
//
//     case 2:
//     pyout = ls + "/" + rs + "/n";
//     break;
//
//     case 3:
//     pyout = ls + "%" + rs + "/n";
//     break;
//
//   }
// }


/////////////////////////////////////additive_expression///////////////////////////////////////////////////

// additive_expression
// 	: multiplicative_expression  {$$ = $1}
// 	| additive_expression '+' multiplicative_expression  {$$ = new additive_expression(1, $1, $3);}
// 	| additive_expression '-' multiplicative_expression  {$$ = new additive_expression(2, $1, $3);}
// 	;
class additive_expression : public expression{
  public:
    //additive_expression(int _type, treeptr _cast):type(_type),mul(_cast){};
    additive_expression(int _type, treeptr _add, treeptr _mul):type(_type),add(_add),mul(_mul){};
    virtual void translate(string& pyout)const override;
    ~additive_expression(){
      delete mul;
      delete add;
    };
  private:
    int type;
    treeptr add, mul;
    string cname = "additive_expression";
};

// void additive_expression::translate(string& pyout) const
// {
//   debug(cname);
//   string ls, rs;
//   add -> translate(ls);
//   mul -> translate(rs);
//   switch(type){
//     // case 0:
//     // mul->translate(pyout);
//     // break;
//
//     case 1:
//     pyout = ls + "+" + rs+"/n";
//     break;
//
//     case 2:
//     pyout = ls + "-" + rs+"/n";
//     break;
//   }
// }

/////////////////////////////////////bitwise_shift_expression///////////////////////////////////////////////////

// shift_expression
// 	: additive_expression  {$$ = $1}
// 	| shift_expression LEFT_OP additive_expression {$$ = new shift_expression(1,$1,$3)}
// 	| shift_expression RIGHT_OP additive_expression {$$ = new shift_expression(2,$1,$3)}
// 	;

class shift_expression : public expression{
  public:
    //shift_expression(int _type, treeptr _cast):type(_type),mul(_cast){};
    shift_expression(int _type, treeptr _shift, treeptr _add):type(_type),l(_shift),r(_add){};
    virtual void translate(string& pyout)const override;
    ~shift_expression(){
      delete l;
      delete r;
    };
  private:
    int type;
    treeptr l = NULL;
    treeptr r = NULL;
    string cname = "shift_expression";
};

// void shift_expression::translate(string& pyout) const
// {
//   debug(cname);
//   string ls, rs;
//   l -> translate(ls);
//   r -> translate(rs);
//   switch(type){
//     // case 0:
//     // mul->translate(pyout);
//     // break;
//
//     case 1:
//     pyout = ls + "<<" + rs+"/n";
//     break;
//
//     case 2:
//     pyout = ls + ">>" + rs+"/n";
//     break;
//   }
// }

#endif
