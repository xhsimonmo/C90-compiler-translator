#ifndef mips_hpp
#define mips_hpp

//#include "ast.hpp"
#include "function_parameter.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::to_string;

extern int current_frame;//indicate current frame index;
extern int labelcounter;//make unique label by number
// extern int frame_counter;//make unique number for frame: as the stack index!
// //remember the locations of each variable (offset relative to the frame pointer, which is a register)

struct stack_content
{
  string name;//variable name: i
  int address;//variable (relative)locations: add 0, 4(0/4+fp)
};
//collection of stack vector for each frame(two-dimension);
extern vector<vector<stack_content>>stack_collection;
extern vector<vector<string>> mpcode_collection;//store generated mips code
extern vector<int> arg_count_collection;//this is the counter of arguments callee function
//extern vector<string>mpcode;//final mips code collection

//extern vector<vector<array_struct>> array_collection;//store array info for each frame(index = frame index)
//extern int array_index;//current array index in current frame
inline void initilise_arg(bool b);
class mips{
public:
  bool registers[32];

  //store temporary result
  struct temp_result
  {
    string func_name; // name of variable
    string result; //TODO shouldn't it be stored in $2 as return value?
    string func_type;
    //note: var_index need to be negative
    int var_index;//store previous results' index(in stack vector)
    int result_index;//use for statement expression result index

  };

  temp_result info;

  struct array_struct
  {
    string name;
    string size;
    vector<int>array_add;//store array initializer address;
  };

  mips()//initialisation
  {
    //registers[32] = { 0 }; // TODO something not right about indent
    labelcounter = 0;
  }

  //add new frame for function
  void add_frame()//string func_name, vector<string>mips_code)
  {
    //indicate the current frame index; it should be the same index for mips_code
    current_frame = stack_collection.size();
    //everytime start a new frame, add a stack(vector) for it
    vector<stack_content> frame_stack; //with reference to FP at the top, variables arguments has positive address, local have negative
    stack_collection.push_back(frame_stack);
    arg_count_collection.push_back(0);//initially the number of arguments in callee functions; index same as current_frame

    //make an array stac for each frame
    vector<array_struct>array_stack;
    //array_collection.push_back(array_stack);
    //array_index = 0;//everytime meet array declaration, +1

    //define this in function_definition
   //make a new vector for mips code when start a new frame_stack
    // vector<string>mips_code;
    // mpcode_collection[current_frame]_collection.push_back(mips_code);
    initilise_arg(true);//all argument available at the beginning
    string imm = "-12";
    addiu(29,29,imm);
    sw(30, 4,29);
    sw(31,8,29);
    // this instruction is added at the end_frame: addiu(29,29,offset)
    move(29,30);

    //frame counter +1
    //frame_counter++;
  }
  //frame ended
  void finish_frame()
  {
    move(29,30);//move sp up to same location as fp
    lw(31, 8, 29);
    lw(30, 4, 29);//4=8-4
    string imm = "12";
    addiu(29, 29, imm);
    j(31);
    nop();

    auto it = mpcode_collection[current_frame].begin();
    //info.var_index = info.var_index + 4;//TODO probably not necessary, but in case
    int memory_allocate = stack_collection[current_frame].size() + arg_count_collection[current_frame] + 4; // 4 is compulsory but nor necessary,just to be safe
    memory_allocate = -4*memory_allocate;
    string str_memory_allocate = to_string(memory_allocate);
    string function_header = "addiu $29,$29,"+str_memory_allocate;
    mpcode_collection[current_frame].insert(it+3, function_header);//add function header back
    initilise_arg(true);;//release the argument registers; actually not necessay, let it be there
    //current_frame--;
  }


  //find a variable's position in stack
  int find_variable(string var_name, vector<stack_content>variables)
  {
    bool find = false;
    int var_add;
    while(find == false) // infinite loop?if not find
    {
      for (int i = 0; i < variables.size(); i++)
      {
        if(variables[i].name == var_name)
        {
          find = true;
          var_add = variables[i].address;
          return var_add;
        }
      }
    }
    return -1;//not a variable declared before,in this case, could be a name of function, address can't be -1 anyway
  }


  //make function call
  void function_call(string func_name, vector<string> func_param, int ret_add)
  {
    //load function parameter from stack first;
    for(int i = 0; i < func_param.size(); i++)
    {
      int r = 4;//register for arguments
      lw(r, find_variable(func_param[i], stack_collection[current_frame]), 30);
      r++;//change register for next argument
    }

    jal(func_name);
    nop();
    //return value
    sw(2, 4, 29);//TODO:sp???
  }


  void add_label(string label)
  {
    string mp = label + ":";
    mpcode_collection[current_frame].push_back(mp);
  }

  void nop()
  {
    string nop = "nop";
    mpcode_collection[current_frame].push_back(nop);
  }

  void move(int rd, int rs)
  {
    string mp = "move $" + to_string(rd) + ",$" + to_string(rs) ;
    mpcode_collection[current_frame].push_back(mp);
  }

  void jal(string label)
  {
    string mp = "jal " + label;
    mpcode_collection[current_frame].push_back(mp);
  }

  void li(int rd, string imm)
  {
    string mp = "li $" + to_string(rd) + "," + imm;
    mpcode_collection[current_frame].push_back(mp);
  }//TODO: imm might be string? unsure

  //store a word to memory
  void sw(int rd, int offset, int base_reg)
  {
    string mp = "sw $" + to_string(rd) + "," + to_string(offset) + "($" + to_string(base_reg) + ")";
    mpcode_collection[current_frame].push_back(mp);
  }

  void lw(int rd, int offset, int base_reg)
  {
    string mp = "lw $" + to_string(rd) + "," + to_string(offset) + "($" + to_string(base_reg) + ")";
    mpcode_collection[current_frame].push_back(mp);
    nop();
  }

  //TODO: do we need to consider addu???
  void add(int rd, int rs, int rt)
  {
    string mp = "add $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }
  void addi(int rt, int rs, string imm)
  {
    string mp = "addi $" + to_string(rt) + ",$" + to_string(rs) + "," + imm;//TODO: imm might be string? unsure
    mpcode_collection[current_frame].push_back(mp);
  }

  void addiu(int rt, int rs, string imm)
  {
    string mp = "addiu $" + to_string(rt) + ",$" + to_string(rs) + "," + imm;//TODO: imm might be string? unsure
    mpcode_collection[current_frame].push_back(mp);
  }

  void addu(int rd, int rs, int rt)
  {
    string mp = "addu $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void _and(int rd, int rs, int rt)
  {
    string mp = "and $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void andi(int rt, int rs, string imm)
  {
    string mp = "addiu $" + to_string(rt) + ",$" + to_string(rs) + "," + imm;//TODO: imm might be string? unsure
    mpcode_collection[current_frame].push_back(mp);
  }

  void sub(int rd, int rs, int rt)
  {
    string mp = "sub $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void subu(int rd, int rs, int rt)
  {
    string mp = "subu $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  // void beq(int rs, int rt, int offset)
  // {
  //   string mp = "beq $" + to_string(rs) + ",$" + to_string(rt) + "," + to_string(offset);//TODO: imm might be string? unsure
  //   mpcode_collection[current_frame].push_back(mp);
  // }
  void beq(int rs, int rt, string offset)
  {
    string mp = "beq $" + to_string(rs) + ",$" + to_string(rt) + "," + offset;//TODO: imm might be string? unsure
    mpcode_collection[current_frame].push_back(mp);
  }


  // maybe add BLTZ and BLEZ if needed later

  // void bne(int rs, int rt, int offset)
  // {
  //   string mp = "bne $" + to_string(rs) + ",$" + to_string(rt) + "," + to_string(offset);//TODO: imm might be string? unsure
  //   mpcode_collection[current_frame].push_back(mp);
  // }
  void bne(int rs, int rt, string offset)
  {
    string mp = "bne $" + to_string(rs) + ",$" + to_string(rt) + "," + offset;//TODO: imm might be string? unsure
    mpcode_collection[current_frame].push_back(mp);
  }

  void sll(int rd, int rt, int sa) // SLL rd <- rt<<sa
  {
    string mp = "sll $" + to_string(rd) + ",$" + to_string(rt) + "," + to_string(sa);
    mpcode_collection[current_frame].push_back(mp);
  }

  void sra(int rd, int rt, int sa) // arithmetic shift; signed extend
  {
    string mp = "sra $" + to_string(rd) + ",$" + to_string(rt) + "," + to_string(sa);
    mpcode_collection[current_frame].push_back(mp);
  }

  void srl(int rd, int rt, int sa) // logical unsign shift
  {
    string mp = "srl $" + to_string(rd) + ",$" + to_string(rt) + "," + to_string(sa);
    mpcode_collection[current_frame].push_back(mp);
  }

  void sltu(int rd, int rs, int rt)
  {
    string mp = "sltu $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void slt(int rd, int rs, int rt)
  {
    string mp = "slt $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void slti(int rt, int rs, string imm) // imm as signed
  {
    string mp = "slti $" + to_string(rt) + ",$" + to_string(rs) + "," + imm;
    mpcode_collection[current_frame].push_back(mp);
  }

  void mult(int rs, int rt)
  {
    string mp = "mult $" + to_string(rs) + ",$" + to_string(rt); // TODO do i need to use MFLO here?
    mpcode_collection[current_frame].push_back(mp);
  }

  void multu(int rs, int rt)
  {
    string mp = "multu $" + to_string(rs) + ",$" + to_string(rt); // TODO do i need to use MFLO here?
    mpcode_collection[current_frame].push_back(mp);
  }

  void div(int rs, int rt) // for div: rs/rt ; quotient -> LO; remainder -> HI TODO maybe add MFLO later
  {
    string mp = "div $" + to_string(rs) + ",$" + to_string(rt); // TODO do i need to use MFLO here?
    mpcode_collection[current_frame].push_back(mp);
  }

  void divu(int rs, int rt)
  {
    string mp = "divu $" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void mflo(int rd)
  {
    string mp = "mflo $" + to_string(rd);
    mpcode_collection[current_frame].push_back(mp);
  }

  void mfhi(int rd)
  {
    string mp = "mfhi $" + to_string(rd);
    mpcode_collection[current_frame].push_back(mp);
  }

  void _xor(int rd, int rs, int rt)
  {
    string mp = "xor $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void _or(int rd, int rs, int rt)
  {
    string mp = "or $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void nor(int rd, int rs, int rt)
  {
    string mp = "nor $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void b(string label)
  {
    string mp = "b " + label;
    mpcode_collection[current_frame].push_back(mp);
  }

  void j(int rd)
  {
    string mp = "j $" + to_string(rd);
    mpcode_collection[current_frame].push_back(mp);
  }

};

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

// extern vector<int> arg_count_collection;//this is the counter of arguments callee function

inline void callee_value_process(mips& mp){

  if(caller_arg_count < 4){
    //mp.lw(2,variable_index,30);
    mp.move((caller_arg_count+4),2); //directly load const to reg 2
  }
  else{
    //mp.lw(2,variable_index,30);
    mp.sw(2,caller_arg_count*4,29);//SP at the bottom, store things up
  }
  caller_arg_count++;
}

#endif
