class mips{
private:
  vector <string> mpcode;
  vector<int>reg;
  vector<string>stack;
public:
  void add(string rd, string rs, string rt)
  {
    string mp = "add " + rd + "," + rs + "," + rt;
    mpcode.push_back(mp);
  }
  void addi()
  {
    
  }

};
