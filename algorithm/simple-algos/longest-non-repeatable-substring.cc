//copyright @ L.J.SHOU Feb.16, 2014
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LongestSubString(string str)
{
  int len = str.size();
  if(len < 2) return len;

  /* hash table */
  vector<int> hash(26, -1);
  int s(0), t(0), longest(0);
  hash[str[0] - 'a'] = 0;

  for(t=1; t<len; ++t)
  {
    if(hash[str[t]-'a'] == -1 || hash[str[t]-'a'] < s)
	{
	  hash[str[t]-'a'] = t;
	}
	else /* 重复 */
	{
	  longest = max(longest, t-s); 
	  s = hash[str[t]-'a'] + 1;
	  hash[str[t] - 'a'] = t;
	}
  }
  longest = max(longest, t-s);

  return longest;
}

int main(void)
{
  string str;

  cin >> str;
  cout << LongestSubString(str) << endl;

  return 0;
}
