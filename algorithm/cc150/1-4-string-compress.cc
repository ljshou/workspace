// copyright @ L.J.SHOU Dec.03, 2013
// string compression
#include <iostream>
#include <string>
using namespace std;

string StringCompression(string str)
{
  string str_new;
  int i(0), j(0);

  while(i < str.size())
  {
    j = i+1;
	while(j < str.size() && str[j] == str[i])
	  ++j;
	str_new.push_back(str[i]);
	str_new.push_back('0'+j-i);
	i = j;
  }

  if(str_new.size() < str.size())
    return str_new;
  else
    return str;
}

int main(void)
{
  string str("aabccccaaa");
  cout << StringCompression(str) << endl;
  return 0;
}
