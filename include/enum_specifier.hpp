#ifndef enum_specifier_h
#define enum_specifier_h

#include"ast.hpp"
// enum_specifier
// 	: ENUM '{' enumerator_list '}'     {$$ = new enum_specifier(0,$3); std::cerr << "enum_specifier 0" << std::endl;}
// 	| ENUM IDENTIFIER '{' enumerator_list '}'    {$$ = new enum_specifier(1,$2,$4); std::cerr << "enum_specifier 1" << std::endl;}
// 	| ENUM IDENTIFIER        {$$ = new enum_specifier(2,$2); std::cerr << "enum_specifier 2" << std::endl;}
// 	;

class enum_specifier : public astnode{
public:
  enum_specifier(int type_in, treeptr o){type = type_in; ptr = o;}
  enum_specifier(int type_in, string name, treeptr o){type = type_in; enum_name = name; ptr = o;}
  enum_specifier(int type_in, string name){type = type_in; enum_name = name;}
  ~enum_specifier(){delete ptr;}
  //virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr ptr = NULL;
  string enum_name;
  string cname = "enum_specifier";
};

// void enum_specifier :: compile(mips& mp)const
// {
//   mp.enum_count = 0;
//   debug(cname);
//   switch (type) {
//     case 0:
//     ptr ->compile(mp);
//     break;
//     case 1:
//     ptr ->compile(mp);
//     mp.info.func_name = enum_name;//what to do with this name, in doubt
//     break;
//     case 2:
//     mp.info.func_name = enum_name;//don't do anything,just a declaration, what about implementation
//     break;
//   }
// }

//////////////////////////////////enumerator_list ////////////////////////////////////////////////////////////////////
// enumerator_list
// 	: enumerator   {$$ = $1; std::cerr << "enumerator_list 0" << std::endl;}
// 	| enumerator_list ',' enumerator    {$$ = new enumerator_list($1,$3); std::cerr << "enumerator_list 1" << std::endl;}
// 	;

class enumerator_list : public astnode{
public:
  enumerator_list(treeptr l, treeptr r){left = l; right = r;}
  ~enumerator_list(){delete left; delete right;}
  //virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr left = NULL;
  treeptr right = NULL;
  string cname = " enumerator_list";
};

// void enumerator_list :: compile(mips& mp)const
// {
//   left -> compile(mp);
//   //mips another_mp;
//   right -> compile(mp);
// }


//////////////////////////////////enumerator ////////////////////////////////////////////////////////////////////
// enumerator
// 	: IDENTIFIER     {$$ = new enumerator_list($1); std::cerr << "enumerator 0" << std::endl;}
// 	| IDENTIFIER '=' constant_expression     {$$ = new enumerator_list($1,$3); std::cerr << "enumerator 0" << std::endl;}
// 	;

class enumerator: public astnode{
public:
  enumerator(string name){id = name;}
  enumerator(string name, treeptr r){id = name; ptr = r;}
  ~enumerator(){delete ptr;}
  //virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr ptr = NULL;
  string id;
  string cname = "enumerator";
};

// void enumerator :: compile(mips& mp)const
// { // special case of use for enum, address field used to store the value
//   if(ptr == NULL){
//     stack_content tmp = {id, mp.enum_count, "int"};
//     enum_var.push_back(tmp);
//     mp.enum_count++;
//   }
//   else{
//     ptr -> compile(mp);
//     mp.enum_count = std::stoi(mp.info.result);
//     stack_content tmp = {id, mp.enum_count, "int"};
//     enum_var.push_back(tmp);
//     mp.enum_count++;
//   }
// }

#endif
