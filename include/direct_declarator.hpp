#ifndef direct_declarator_h
#define direct_declarator_h
#include"ast.hpp"

// direct_declarator
// 	: IDENTIFIER   {$$ = new direct_declarator(0,*$1);}
// 	| '(' declarator ')'  {$$ = new direct_declarator(1,$2);}
// 	| direct_declarator '[' constant_expression ']'  {$$ = new direct_declarator(2,$1,$3);}  array declaration
// 	| direct_declarator '[' ']'   {$$ = new direct_declarator(3,$1);}   array declaration
// 	| direct_declarator '(' parameter_type_list ')'  {$$ = new direct_declarator(4,$1,$3);}  function declaration
// 	| direct_declarator '(' identifier_list ')'  {$$ = new direct_declarator(5,$1,$3);} function declaration
// 	| direct_declarator '(' ')'   {$$ = new direct_declarator(6,$1);} function declaration C90 page 67
// 	;

class direct_declarator : public astnode{
public:
  direct_declarator(int _type,string _id):type(_type),id(_id){};
  direct_declarator(int _type, treeptr _one):type(_type),one(_one){};
  direct_declarator(int _type, treeptr _one, treeptr _two):type(_type),one(_one),two(_two){};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp)const override;
  ~direct_declarator(){
    delete one;
    delete two;
  }
private:
  string id;
  int type;
  treeptr one = NULL;
  treeptr two = NULL;
  string cname = "direct_declarator";
};

// void direct_declarator::compile(mips& mp)const
// {
      // mips another_mp;
//   switch(type)
//   {
//     case 0:
//     mp.info.func_name = id;
//     break;
//
//     case 1:
//     one->compile(mp);
//     break;
//
//     case 2:
//     std::cerr << "array !" << '\n';
//     break;
//
//     case 3:
//     NotImplemented();// no Implement for array[]
//     break;
//     case 4:
//     one->compile(mp); // eg:  f()
//     //mips another_mp;
//     two->compile(another_mp);//parameter!
//     break;
//
//     case 5:
//     NotImplemented(); //never reach, KR style.
//     break;
//
//     case 6:
//     one->compile(mp);
//     break;
//   }
// }

// void direct_declarator::compile(mips& mp)const
// {
//   mips another_mp;
//   switch(type)
//   {
//     case 0:
//     mp.info.func_name = id;
//     break;
//
//     case 1:
//     one->compile(mp);
//     break;
//
//     case 2:
//     //it uses const expression so size is constant
//     two->compile(mp);//this should store result to $2
//     one->compile(another_mp);//this should fill in the array name;
//     string array_name = another_mp.info.array_name;
//     //create a new array
//     array_struct a;
//     a.name = array_name;
//     array_collection[current_frame].push_back(a);
//     break;
//
//     case 3:
//     NotImplemented();// no Implement for array[]
//     break;
//     case 4:
//     one->compile(mp); // eg:  f()
//     two->compile(another_mp);//parameter!
//     break;
//
//     case 5:
//     NotImplemented(); //never reach, KR style.
//     break;
//
//     case 6:
//     one->compile(mp);
//     break;
//   }
// }



#endif
