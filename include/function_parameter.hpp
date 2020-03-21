// #ifndef function_parameter_h
// #define function_parameter_h
//
// #include "mips.hpp"
// #include <vector>
// using std::vector;
//
// extern bool arg_reg[4];//to register the availability of $4 - $7 registers in argument
// extern int arg_overflow; //record the number of argumnets exceed obove 4
// extern int caller_arg_count;//used to record the arguments of callee functions
// inline int arg_check(){
//   for(int i = 0 ; i < 4; i++)
//   {
//     if(arg_reg[i] == true)
//     {
//       arg_reg[i] = false;
//       return i; //find one available reg
//     }
//   }
//   return -1;//more than four arguments
// }
//
// inline void initilise_arg(bool b){
//   for(int i = 0; i < 4; i++)
//   {
//     arg_reg[i] = b;
//   }
//   arg_overflow = 0;//reset it
// }
//
// extern vector<int> arg_count_collection;//this is the counter of arguments callee function
//
// inline void callee_value_process(mips& mp)const{
//
//   if(caller_arg_count < 4){
//     //mp.lw(2,variable_index,30);
//     mp.move((caller_arg_count+4),2); //directly load const to reg 2
//   }
//   else{
//     //mp.lw(2,variable_index,30);
//     mp.sw(2,caller_arg_count*4,29);//SP at the bottom, store things up
//   }
//   caller_arg_count++;
// }
//
// #endif
