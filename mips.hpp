class mips{
private:
  string stack_name;
  vector <string> mpcode;//store generated mips code
  bool registers[32];

  //store temporary result
  struct temp_result
  {
    string func_name;
    string result; //TODO shouldn't it be stored in $2 as return value?
    string func_type;
    int var_index;//store previous results' index(in stack vector)
  };

  temp_result info;

  //remember the locations of each variable (offset relative to the frame pointer, which is a register)
  struct stack_content
  {
    string name;//variable name: i
    int address;//variable (relative)locations: add 0, 4(0/4+fp)
  };

  //main variable storage
  vector<stack_content>stack;

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
    registers[32] = { 0 }; // TODO something not right about indent
  }

  //add new frame for function
  void add_frame(string func_name)
  {
    //move down stack pointer by 8
    addi(29, 29, -8);//TODO: if pass-in parameter is used, -8; if not then -24????????????
    //move frame pointer
    sw(30, 4, 29);//4=8-4 //TODO MIPS format for sw not correct?
    addi(30, 29, 0);//move fp, sp

  }
  //frame ended
  void finish_frame()
  {
    addi(29, 30, 0);//move sp, fp
    lw(30, 4, 29);//4=8-4
    addi(29, 29, 8);
    j(31);
    nop();
  }

  //find a variable's position in stack
  int find_variable(string var_name)
  {
    bool find = false;
    int var_add;
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
    return var_add;
  }


  //make function call
  void function_call(string func_name, vector<string> func_param, int ret_add)
  {
    //load function parameter from stack first;
    for(int i = 0; i < func_param.size(); i++)
    {
      int r = 4;//register for arguments
      lw(r, find_variable(func_param), 30);
      r++;//change register for next argument
    }

    jal(func_name);
    nop();
    //return value
    sw(2, 4, sp);//TODO:sp???
  }

};


  void nop()
  {
    string nop = "nop";
    mpcode.push_back(nop);
  }
  void move(int rd, int rs)
  {
    string mp = "move $" + to_string(rd) + ",$" + to_string(rs) ;
    mpcode.push_back(mp);
  }

  void jal(string label)
  {
    string mp = "jal " + label;
    mpcode.push_back(mp);
  }

  void li(int rd, string imm)
  {
    string mp = "li $" + to_string(rd) + "," + to_string(imm);
    mpcode.push_back(mp);
  }//TODO: imm might be string? unsure

  //store a word to memory
  void sw(int rd, int offset, int base_reg)
  {
    string mp = "sw $" + to_string(rd) + "," + offset + "($" + to_string(base_reg) + ")";
    mpcode.push_back(mp);
  }

  void lw(int rd, int offset, int base_reg)
  {
    string mp = "lw $" + to_string(rd) + "," + offset + "($" + to_string(base_reg) + ")";
    mpcode.push_back(mp);
    nop();
  }

  //TODO: do we need to consider addu???
  void add(int rd, int rs, int rt)
  {
    string mp = "add $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }
  void addi(int rt, int rs, int imm)
  {
    string mp = "addi $" + to_string(rt) + ",$" + to_string(rs) + "," + to_string(imm);//TODO: imm might be string? unsure
    mpcode.push_back(mp);
  }

  void addiu(int rt, int rs, int imm)
  {
    string mp = "addiu $" + to_string(rt) + ",$" + to_string(rs) + "," + to_string(imm);//TODO: imm might be string? unsure
    mpcode.push_back(mp);
  }

  void addu(int rd, int rs, int rt)
  {
    string mp = "addu $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

  void and(int rd, int rs, int rt)
  {
    string mp = "and $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

  void andi(int rt, int rs, int imm)
  {
    string mp = "addiu $" + to_string(rt) + ",$" + to_string(rs) + "," + to_string(imm);//TODO: imm might be string? unsure
    mpcode.push_back(mp);
  }

  void sub(int rd, int rs, int rt)
  {
    string mp = "sub $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

  void subu(int rd, int rs, int rt)
  {
    string mp = "subu $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

  void beq(int rs, int rt, int offset)
  {
    string mp = "beq $" + to_string(rs) + ",$" + to_string(rt) + "," + to_string(offset);//TODO: imm might be string? unsure
    mpcode.push_back(mp);
  }
  // maybe add BLTZ and BLEZ if needed later

  void bne(int rs, int rt, int offset)
  {
    string mp = "bne $" + to_string(rs) + ",$" + to_string(rt) + "," + to_string(offset);//TODO: imm might be string? unsure
    mpcode.push_back(mp);
  }

  void sll(int rd, int rt, int sa) // SLL rd <- rt<<sa
  {
    string mp = "sll $" + to_string(rd) + ",$" + to_string(rt) + "," + to_string(sa);
    mpcode.push_back(mp);
  }

  void sra(int rd, int rt, int sa) // arithmetic shift; signed extend
  {
    string mp = "sra $" + to_string(rd) + ",$" + to_string(rt) + "," + to_string(sa);
    mpcode.push_back(mp);
  }

  void srl(int rd, int rt, int sa) // logical unsign shift
  {
    string mp = "srl $" + to_string(rd) + ",$" + to_string(rt) + "," + to_string(sa);
    mpcode.push_back(mp);
  }

  void sltu(int rd, int rs, int rt)
  {
    string mp = "sltu $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

  void slt(int rd, int rs, int rt)
  {
    string mp = "slt $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

  void slti(int rt, int rs, int imm) // imm as signed
  {
    string mp = "slti $" + to_string(rt) + ",$" + to_string(rs) + "," + to_string(imm);
    mpcode.push_back(mp);
  }

  void mult(int rs, int rt)
  {
    string mp = "mult $" + to_string(rs) + ",$" + to_string(rt); // TODO do i need to use MFLO here?
    mpcode.push_back(mp);
  }

  void multu(int rs, int rt)
  {
    string mp = "multu $" + to_string(rs) + ",$" + to_string(rt); // TODO do i need to use MFLO here?
    mpcode.push_back(mp);
  }

  void div(int rs, int rt) // for div: rs/rt ; quotient -> LO; remainder -> HI TODO maybe add MFLO later
  {
    string mp = "div $" + to_string(rs) + ",$" + to_string(rt); // TODO do i need to use MFLO here?
    mpcode.push_back(mp);
  }

  void divu(int rs, int rt)
  {
    string mp = "divu $" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

  void mflo(int rd)
  {
    string mp = "mflo $" + to_string(rd);
    mpcode.push_back(mp);
  }

  void mfhi(int rd)
  {
    string mp = "mfhi $" + to_string(rd);
    mpcode.push_back(mp);
  }

  void xor(int rd, int rs, int rt)
  {
    string mp = "xor $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

  void or(int rd, int rs, int rt)
  {
    string mp = "or $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

  void nor(int rd, int rs, int rt)
  {
    string mp = "nor $" + to_string(rd) + ",$" + to_string(rs) + ",$" + to_string(rt);
    mpcode.push_back(mp);
  }

//};
