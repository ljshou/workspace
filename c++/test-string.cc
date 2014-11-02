/**
 * @file test-string.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-21
 */

#include <bits/stdc++.h>
using namespace std;

void ChangeString(const char* str)
{
  //str[0] = 'a';
}

int main(void)
{
  string str("hello");
  string s = str;
  queue q;
  cout << (int*)str.c_str() << endl;
  cout << (int*)s.c_str() << endl;
  cout << (int*)&s[0] << endl;
  //ChangeString(s.c_str());
  cout << s << endl;
  return 0;
}
