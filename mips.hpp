class mips{
private:
  vector <string> mpcode;
  vector<int>reg;
  vector<string>stack;

  //variable format
  struct stack_content
  {
    string name;
    int value;
  };

  //stack frame for function calls
  vector<stack_content>func_stack;
  vector<stack_content>func_variables;

public:
  //make function call
  void function_call(int ret_addr, vector<stack_content>func_variables)
  {
    stack_content s1 = {"return address", ret_addr};
    fun_stack.push_back(s1);//add return address
    for (int i = 0; i < func_variables.size(); i++)
    {
      func_stack.push_back(func_variables[i]);//add function variables
    }
  }

  void add(string rd, string rs, string rt)
  {
    string mp = "add " + rd + "," + rs + "," + rt;
    mpcode.push_back(mp);
  }
  void addi(string rt, string rs, string imm)
  {
    string mp = "addi " + rt + "," + rs + "," + imm;
    mpcode.push_back(mp);
  }

};
