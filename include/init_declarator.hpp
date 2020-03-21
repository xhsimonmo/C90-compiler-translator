#ifndef init_declarator_h
#define init_declarator_h
#include"ast.hpp"
init_declarator
	// : declarator   {$$ = new init_declarator($1); std::cerr << "init_declarator 0 " << std::endl;}
	// | declarator '=' initializer   {$$ = new init_declarator($1,$3);  std::cerr << "init_declarator 1" << std::endl;}
	// ;

class init_declarator : public astnode{
public:
  init_declarator(treeptr _one, treeptr _two):one(_one),two(_two){};
  init_declarator(treeptr _one):one(_one){};
  virtual void translate(string& pyout)const override;
  virtual void compile(mips& mp) const override;
  ~init_declarator(){
    delete one;
    delete two;
  }
private:
  treeptr one = NULL;
  treeptr two = NULL;
  string cname = "init_declarator";
};

// void init_declarator::compile(mips& mp)const{
//   if(two == NULL)
//    {
//      left -> compile(mp);
//      string init_name = mp.info.func_name;
//      int offset = -4 * (stack_collection[current_frame].size());
//      stack_collection[current_frame].push_back(init_name,offset);
//    }
//    else{
//      left -> compile(mp);
//      string init_name = mp.info.func_name;
//      int offset = -4 * (stack_collection[current_frame].size());
//      stack_collection[current_frame].push_back(init_name,offset);
//      right -> compile(mp);
//      mp.sw(2,offset,30);
//    }
// }

// void init_declarator::translate(string& pyout) const{
//   debug(cname);
//   string s1, s2;
//   if(two == NULL){
//       one-> translate(s1);
//       pyout = s1 + "= 0";// + '\n';
//   }
//   else{
//     one-> translate(s1);
//     two -> translate(s2);
//     pyout = s1 + '=' + s2;// + '\n';
//   }
// }


#endif
