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
  virtual void compile(mips& mp) const override;
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

void multiplicative_expression::compile(mips& mp)const
{
  mips another_mp;
  int l_index;
  int r_index;

  switch (type) {

  case 1://"*"
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  cast->compile(another_mp);
  r_index = result_offset();
  //mp.move(3, 2);
  mul->compile(mp);
  l_index = result_offset();
  lw(2,r_index,30);
  lw(2,l_index,30)
  mp.nop();

  mp.mult(2, 3);
  mp.mflo(2);
  result_count = result_count -4;
  mp.sw(2, result_offset(), 30);//load to a's stack position
  break;

  case 2:
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  cast->compile(another_mp);
  mp.move(3, 2);
  mul->compile(mp);
  mp.nop();
  mp.div(2, 3);
  mp.mflo(2);
  // mp.sw(2, mp.info.var_index, 30);//load to a's stack position
  break;

  case 3:
  // mp.lw(2, mp.info.var_index, 30);
  // mp.lw(3, another_mp.info.var_index, 30);
  cast->compile(another_mp);
  mp.move(3, 2);
  mul->compile(mp);
  mp.nop();
  mp.div(2, 3);
  mp.mfhi(2);
  // mp.sw(2, mp.info.var_index, 30);//load to a's stack position
  break;
}
}



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
  virtual void compile(mips& mp) const override;
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

// void additive_expression::compile(mips& mp)
// {
//   add->compile(mp);
//   mips another_mp;
//   mul->compile(another_mp);
//
//   case 1://"+"
//   lw(2, mp.temp_result.var_index, 30);
//   lw(3, another_mp.temp_result.var_index, 30);
//   nop();
//   add(2, 2, 3);
//   sw(2, sp+4, 30);
//   mp.temp_result.var_index = sp + 4;
//   break;
//
//   case 2://"-"
//   lw(2, mp.temp_result.var_index, 30);
//   lw(3, another_mp.temp_result.var_index, 30);
//   nop();
//   sub(2, 2, 3);
//   sw(2, sp+4, 30);
//   mp.temp_result.var_index = sp + 4;
//   break;
//
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
  virtual void compile(mips& mp) const override;
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

// void shift_expression::compile(mips& mp)
// {
//   l->compile(mp);
//   mips another_mp;
//   r->compile(another_mp);
//
//   case 1://"<<"
//   lw(2, mp.temp_result.var_index, 30);
//   lw(3, another_mp.temp_result.var_index, 30);
//   nop();
//   sll(2, 2, 3);
//   sw(2, sp+4, 30);
//   mp.temp_result.var_index = sp + 4;
//   break;
//
//   case 2://">>"
//   lw(2, mp.temp_result.var_index, 30);
//   lw(3, another_mp.temp_result.var_index, 30);
//   nop();
//   sra(2, 2, 3);
//   sw(2, sp+4, 30);
//   mp.var_index = sp + 4;
//   break;
//
// }

#endif
