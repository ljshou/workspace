/**
 * @file 1510.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-28
 */

#include <bits/stdc++.h>
using namespace std;
char s[1000000];

void ConvertString(const char* str)
{
  if(str == NULL) return;
  string res;
  int i=0;
  bool flag(false);
  while(str[i] != 0)
  {
    if(str[i] == ' ') {
      res.append("%20");
    }
    else {
      res += str[i];
    }
    ++ i;
  }
  cout << res << endl;
}

int main(void)
{
  gets(s);
  ConvertString(s);
  return 0;
}


