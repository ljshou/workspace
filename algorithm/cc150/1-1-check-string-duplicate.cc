// copyright @ L.J.SHOU Dec.03, 2013
// check whether there are duplicated chars
// in a given string
#include <iostream>
#include <bitset>
#include <algorithm>
#include <string>
using namespace std;

bool CheckDuplicate(string str)
{
  if(str.size() > 256)
    return true;

  bitset<256> bit;
  int val;

  for(int i=0; i<str.size(); ++i)
  {
    val = str[i];
	if(bit[val]) return true;
	else bit[val] = 1;
  }
  return false;
}

bool CheckDuplicate2(string str)
{
  if(str.size() > 256) return true;
  if(str.size() == 0)  return false;
  sort(str.begin(), str.end());
  int pre(str[0]);
  for(int i=1; i<str.size(); ++i)
  {
    if(str[i] == pre)
	  return true;
	else
	  pre = str[i];
  }
  return false;
}

int main(void)
{
  string str("abbd");
  cout << str << ": " << CheckDuplicate2(str) << endl;
  str = string("a");
  cout << str << ": " << CheckDuplicate2(str) << endl;
  return 0;
}
