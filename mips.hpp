class mips{
private:
  string stack_name;
  vector <string> mpcode;//store generated mips code
  vector<stack_content>stack;
  bool registers[32];

  //remember the locations of each variable (offset relative to the frame pointer, which is a register)
  struct stack_content
  {
    string name;//variable name: i
    int address;//variable (relative)locations: add 0, 4(0/4+fp)
  };

  //stack frame for function calls
  vector<stack_content>func_stack;
  vector<stack_content>func_variables;

  struct function_content
  {
    int ret_add;//SP return address
    string ret_label;

  }

public:
  mips()//initialisation
  {
    registers[32] = {0};
  }

  //add new frame for function definition
  void add_frame(string func_name)
  {


  }
  //frame ended
  void finish_frame()
  {

  }

  //find a variable's position in stack
  void find_variable(string var_name, int var_add)
  {
    bool find = false;
    while(find == false)
    {
      for (int i = 0; i < stack.size(); i++)
      {
        if(stack[i].name == var_name)
        {
          find = true;
          var_add = stack[i].address;
        }
      }
    }
  }


  //make function call
  void function_call(string func_name; int ret_addr, vector<stack_content>func_variables)
  {
    string s = func_name + ":";
    mpcode.push_back(s);
    stack_content s1 = {"return address", ret_addr};
    fun_stack.push_back(s1);//add return address
    for (int i = 0; i < func_variables.size(); i++)
    {
      func_stack.push_back(func_variables[i]);//add function variables
    }
  }

  void li(int rd, int imm)
  {
    string mp = "li " + to_string(rd) + "," + to_string(imm);
    mpcode.push_back(mp);
  }//TODO: imm might be string? unsure

  //store a word to memory
  void sw(int rd, int offset, int base_reg)
  {
    string mp = "sw " + to_string(rd) + "," + offset + "(" + to_string(base_reg) + ")";
    mpcode.push_back(mp);
  }

  void lw(int rd, int offset, int base_reg)
  {
    tring mp = "lw " + to_string(rd) + "," + offset + "(" + to_string(base_reg) + ")";
    mpcode.push_back(mp);
  }

  void add(int rd, int rs, int rt)
  {
    string mp = "add " + to_string(rd) + "," + to_string(rs) + "," + to_string(rt);
    mpcode.push_back(mp);
  }
  void addi(int rt, int rs, int imm)
  {
    string mp = "addi " + to_string(rt) + "," + to_string(rs) + "," + to_string(imm);//TODO: imm might be string? unsure
    mpcode.push_back(mp);
  }
  void

};
