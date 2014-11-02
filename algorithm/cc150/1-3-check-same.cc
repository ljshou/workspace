// copyright @ L.J.SHOU Dec.03, 2013
// Email: shoulinjun@hotmail.com
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

bool CheckSame(string lhs, string rhs)
{
  if(lhs.size() != rhs.size())
    return false;

  sort(lhs.begin(), lhs.end());
  sort(rhs.begin(), rhs.end());

  return (lhs == rhs);
}

bool CheckSame2(string lhs, string rhs)
{
  if(lhs.size() != rhs.size())
    return false;
  
  bitset<256> bit;
  for(int i=0; i<lhs.size(); ++i)
    bit[lhs[i]] = 1;

  for(int i=0; i<rhs.size(); ++i)
    if(bit[rhs[i]] == 0)
	  return false;

  return true;
}

int main(void)
{
  string str1("shou");
  string str2("auhs");
  cout << CheckSame(str1, str2) << endl;
  cout << CheckSame2(str1, str2) << endl;
  return 0;
}
