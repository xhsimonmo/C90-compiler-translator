#ifndef ast_initializer
#define ast_initializer

#include "ast.hpp"

// initializer
// 	: assignment_expression                  {$$ = $1;}
// 	| '{' initializer_list '}'               {$$ = new initializer(0, $2);}
// 	| '{' initializer_list ',' '}'           {$$ = new initializer(1, $2);}
// 	;

class initializer : public astnode{
public:
  initializer(int type_in, treeptr o){type_in = type; p = o;}
  ~initializer(){delete p;}
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
private:
  int type;
  treeptr p;
  string cname = "initializer";
};

// void initializer::translate(string& pyout) const{
//     debug(cname);
//     NotImplemented();
//   }

// void initializer::compile(mips& mp) const
// {
//   switch(type)
//   {
//     // array_collection[current_frame][array_index].array_add
//     case 0:
//     p->compile(mp);//this should store all identifier address in mp;
//     int size = stoi(mp.info.result);//size of the array
//     int element[size];
//     //allocate space for array elements
//     for(int i = 0; i < size(); i++)
//     {
//       mp.sw(0, offset, 30);//TODO:offset???
//       element[i] = offset;
//       offset = offset + 4;
//     }
//     //TODO: unsure about numbers: li instead of lw?
//     //it's the last array in frame
//     int index = array_collection[current_frame].size()-1;
//     for(int i = 0; i < array_collection[current_frame][index].array_add.size(); i++)
//     {
//       mp.lw(2, array_collection[current_frame][index].array_add[i], 30);
//       mp.nop();
//       mp.sw(2, element[i], 30);
//     }
//     case 1:
//     //same as above
//     p->compile(mp);//this should store all identifier address in mp;
//     int size = stoi(mp.info.result);//size of the array
//     int element[size];
//     //allocate space for array elements
//     for(int i = 0; i < size(); i++)
//     {
//       mp.sw(0, offset, 30);//TODO:offset???
//       element[i] = offset;
//       offset = offset + 4;
//     }
//     //TODO: unsure about numbers: li instead of lw?
//     //it's the last array in frame
//     int index = array_collection[current_frame].size()-1;
//     for(int i = 0; i < array_collection[current_frame][index].array_add.size(); i++)
//     {
//       mp.lw(2, array_collection[current_frame][index].array_add[i], 30);
//       mp.nop();
//       mp.sw(2, element[i], 30);
//     }
//   }
//
//
// }


#endif
