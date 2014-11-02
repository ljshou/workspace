// copyright @ L.J.SHOU Mar.10, 2014
// find 1st single number
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void FirstSingleNumber(const string& str)
{
  if(str.empty()) return;
  unordered_map<char, int> char_set;

  for(int i=0; i<str.size(); ++i)
    ++ char_set[str[i]];

  for(int i=0; i<str.size(); ++i)
  {
	// char_set[i] will automatically insert i if i not existed
	// value is set by default constructor
    if(char_set[str[i]] == 1)
	{
	  cout << str[i] << endl;
	  return;
	}
  }
}


int main(void)
{
  string str("abaccdeff");

  FirstSingleNumber(str);

  return 0;
}

