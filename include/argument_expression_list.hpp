#ifndef ast_argument_expression_list
#define ast_argument_expression_list

#include "ast.hpp"


class argument_expression_list : public expression{
public:
  argument_expression_list(int type_in, treeptr o, treeptr t){type = type_in; left = o; right = t;}
  ~argument_expression_list(){delete left; delete right;}
  void translate(string& pyout);
private:
  int type;
  treeptr left;
  treeptr right;
};

void argument_expression_list::translate(string& pyout){
    NotImplemented();
}

#endif
