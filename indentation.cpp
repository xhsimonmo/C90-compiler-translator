#include<iostream>
#include<string>

using namespace std;

bool in_scope = true;
int left_bracket = 0;
int right_bracket = 0;

int indentation = 0;

void add_indentation(string pyout)
{
  string delimiter = "/n";


}





int count_ind(int indentation, string temp_py)
{
  int left = 0;
  int right = 0;
  include_brackets(temp_py, left, right)

  if (left == right)
  {
    in_scope = false;
  }
  else{
    in_scope = true;
    indentation = left - right;
  }
  return indentation;
}

void include_brackets(string temp, int& left, int& right)
{
  for (int i = 0; i < temp.size(); i++)
  {
    if (temp[i] == '{')
    {
      left++;
    }
    else if(temp[i] == '}')
    {
      right++;
    }
  }
}
