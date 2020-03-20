#ifndef function_parameter_h
#define function_parameter_h

#include "mips.hpp"

extern bool arg_reg[4];//to register the availability of $4 - $7 registers in argument
extern int arg_overflow; //record the number of argumnets exceed obove 4
extern int caller_arg_count;//used to record the arguments of callee functions
inline int arg_check(){
  for(int i = 0 ; i < 4; i++)
  {
    if(arg_reg[i] == true)
    {
      arg_reg[i] = false;
      return i; //find one available reg
    }
  }
  return -1;//more than four arguments
}

inline void initilise_arg(bool b){
  for(int i = 0; i < 4; i++)
  {
    arg_reg[i] = b;
  }
  arg_overflow = 0;//reset it
}

extern vector<int> arg_count;//this is the counter of arguments callee function

inline callee_value_process(mips& mp)const{
  if(mp.info.result.empty()) // the primary_expression returned is a varibae
  {
    int variable_index = find_variable(mp.info.func_name, stack_collection[current_frame]);
    if(caller_arg_count < 4){
      mp.lw(2,variable_index,30);
      mp.li((caller_arg_count+4),mp.info.result); //directly load const to reg 2
    }
    else{
      mp.lw(2,variable_index,30);
      mp.sw(2,caller_arg_count*4,29);
    }
  }
  else{
    if(caller_arg_count < 4){
      mp.li((caller_arg_count+4),mp.info.result); //directly load const to reg 2
    }
    else{ //arguments greater than 4
      mp.li(2,mp.info.result);
      mp.sw(2,caller_arg_count*4,29);
    }
  }
  caller_arg_count++;
}

#endif
