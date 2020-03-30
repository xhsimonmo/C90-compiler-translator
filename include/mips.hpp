#ifndef mips_hpp
#define mips_hpp

//#include "ast.hpp"
#include "function_parameter.hpp"
#include <string>
#include <vector>
#include<iostream>
using std::string;
using std::vector;
using std::to_string;

extern bool end_frame;
extern int current_frame;//indicate current frame index;
extern bool in_frame;//whether in frame or not; if false it's global
extern int labelcounter;//make unique label by number
// extern int frame_counter;//make unique number for frame: as the stack index!
// //remember the locations of each variable (offset relative to the frame pointer, which is a register)

extern int result_count;
extern int arg_overflow; //record the number of argumnets exceed obove 4
struct stack_content
{
  string name;//variable name: i
  int address;//variable (relative)locations: add 0, 4(0/4+fp)
  string type;
};
//collection of stack vector for each frame(two-dimension);
extern vector<vector<stack_content>>stack_collection;
extern vector<vector<string>> mpcode_collection;//store generated mips code
extern vector<int> arg_count_collection;//this is the counter of arguments callee function

extern vector<stack_content> enum_var; // store enum object, actually just like global variable
extern bool in_enum;

struct array_struct
{
  string name;
  string size;
  vector<int>array_add;//store array initializer address;
};

extern vector<vector<array_struct>> array_collection;//store array info for each frame(index = frame index)
extern int array_index;//current array index in current frame


//contain the case number and its corresponding statement label
struct switch_content
{
  string case_num;//in case it needs to store default
  string label;
};

inline int result_offset(){
  int offset = result_count + (-4)*stack_collection[current_frame].size();
  return offset;
}

inline void initilise_arg(bool b);

//////////////////////////mips class///////////////////////
class mips{
public:
  //bool registers[32];

  //store temporary result
  struct temp_result
  {
    string func_name; // name of variable
    string result; //store number passed from primary expression
    string func_type;
    //note: var_index need to be negative
    int var_index;//store previous results' index(in stack vector)
    int result_index;//use for statement expression result index
    string array_name;
    int array_init_counter;//count initializer

    string break_jump_label;
    string continue_jump_label;
  };

  temp_result info;

  int enum_count;
  mips()//initialisation
  {
    enum_count = 0;
    info.array_init_counter = 0;
    //registers[32] = { 0 }; // TODO something not right about indent
    // labelcounter = 0;
  }

  string add_prefix(string name){
    string prefix = "\t.set noreorder\n\t.text\n\t.align 2\n\t.globl " + name + '\n' + name + ":";
    return prefix;
  }

  //add new frame for function
  void add_frame()//string func_name, vector<string>mips_code)
  {
    in_frame = true;
    //std::cerr << "size of mips code collection: " << mpcode_collection.size() <<'\n';
    //std::cerr << "add frame enter" << '\n';
    //indicate the current frame index; it should be the same index for mips_code
    // current_frame = stack_collection.size();
    //std::cerr << "size of current frame in addframe is : " << current_frame <<'\n';
    //everytime start a new frame, add a stack(vector) for it
    // vector<stack_content> frame_stack; //with reference to FP at the top, variables arguments has positive address, local have negative
    // stack_collection.push_back(frame_stack);
    arg_count_collection.push_back(0);//initially the number of arguments in callee functions; index same as current_frame

    //make an array stac for each frame
    vector<array_struct>array_stack;
    array_collection.push_back(array_stack);//0 index of array_collection is global arrays

    result_count = 0;
    nop();
    end_frame = true;//hasn't met finish_frame yet

  }
  //frame ended
  void finish_frame()
  {

    in_frame = false;
    comment("////////ending current frame//////");
    move(29,30);//move sp up to same location as fp
    lw(31, 8, 29);
    lw(30, 4, 29);//4=8-4
    string imm = "12";
    addiu(29, 29, imm);
    j(31);
    nop();

    auto it = mpcode_collection[current_frame].begin();
    //info.var_index = info.var_index + 4;//TODO probably not necessary, but in case
    int memory_allocate = stack_collection[current_frame].size() + arg_count_collection[current_frame] + -1*result_count+ 4; // 4 is compulsory but nor necessary,just to be safe
    std::cerr << " ////////////////current max arg count: " << arg_count_collection[current_frame] <<'\n';
    memory_allocate = -4*memory_allocate;
    string str_memory_allocate = to_string(memory_allocate);
    string function_header = "addiu $29,$29,"+str_memory_allocate;
    int where_to_insert_sp_move_down = 5;
    mpcode_collection[current_frame].insert(it+where_to_insert_sp_move_down, function_header);//add function header back
    initilise_arg(true);;//release the argument registers; actually not necessay, let it be there
    result_count=0;//set it back
    end_frame = false;
  }


  //find a variable's position in stack
  int find_variable(string var_name, vector<stack_content>variables)
  {
    int var_add = -1;
      for (int i = 0; i < variables.size(); i++)
      {
        if(variables[i].name == var_name)
        {

          var_add = variables[i].address;
           return var_add;
        }
      }
      // if(var_add != -1)//indeed find a var
      // {
      //   return var_add; // temparory method to return the most recent va declared
      // }
      for(int j = 0; j < enum_var.size();j++)
      {
        if(enum_var[j].name == var_name){
          return -3;
        }
      }

    return -1;//not a variable declared before,in this case, could be a name of function, address can't be -1 anyway
  }

  string find_variable_type(string var_name, vector<stack_content>variables)
  {
    string var_type;
      for (int i = 0; i < variables.size(); i++)
      {
        if(variables[i].name == var_name)
        {
          var_type = variables[i].type;
          //std::cerr << "get type:" <<var_type << '\n';
          return var_type;
        }

    }
    return "int";//not a variable declared before,in this case, could be a name of function, address can't be -1 anyway
  }

  int find_array(string name, bool global)
  {
    bool find = false;
    int index;
    for(int i = 0; i < array_collection[current_frame+1].size(); i++)
    {
      if(name == array_collection[current_frame+1][i].name)
      {
        index = i;
        find = true;
      }
    }
    if(find == false)//if can't find in frame arrays, then it should be global
    {
      global = true;
      for(int i = 0; i < array_collection[0].size(); i++)
      {
        if(name == array_collection[0][i].name)
        {
          index = i;
        }
      }
    }
    return index;
  }

  //requires initialisation everytime before use
  vector<switch_content>switch_info;


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
  void comment(string name)
  {
    string nop = "#" + name;
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

  void sllv(int rd, int rt, int rs) // SLL rd <- rt<<rs
  {
    string mp = "sllv $" + to_string(rd) + ",$" + to_string(rt) + ",$" + to_string(rs);
    mpcode_collection[current_frame].push_back(mp);
  }

  void srav(int rd, int rt, int rs) // SLL rd <- rt>>rs
  {
    string mp = "srav $" + to_string(rd) + ",$" + to_string(rt) + ",$" + to_string(rs);
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

  void sge(int rd, int rs, int rt)
  {
    string mp = "sge $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }

  void sle(int rd, int rs, int rt)
  {
    string mp = "sle $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }
  void sne(int rd, int rs, int rt)
  {
    string mp = "sne $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode_collection[current_frame].push_back(mp);
  }
  void seq(int rd, int rs, int rt)
  {
    string mp = "seq $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
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

  void _word(string name){

  }

};

extern bool arg_reg[4];//to register the availability of $4 - $7 registers in argument
// extern int arg_overflow; //record the number of argumnets exceed obove 4
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
    mp.sw(2,caller_arg_count*4 ,29);//SP at the bottom, store things up
  }
  caller_arg_count++;
}

inline void sizeof_process(mips& mp){
  string rvalue = mp.info.func_type;
  int size;
  if(rvalue == "char"){
    size = 1;
  }else if(rvalue == "short"){
    size = 2;
  }else if(rvalue == "int"){
    size = 4;
  }else if(rvalue == "long"){
    size = 8;
  }else if(rvalue == "float"){
    size = 4;
  }else if(rvalue == "double"){
    size = 8;
  }else if(rvalue == "signed"){
    size = 4;
  }else if(rvalue == "unsigned"){
    size = 4;
  }
  // else if(rvalue == ""){
  //   size =
  // }
  mp.li(2,to_string(size));
  result_count = result_count - 4;
  mp.sw(2,result_offset(),30);
}

#endif
