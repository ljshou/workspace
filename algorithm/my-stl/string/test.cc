/**
 * @file test.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-09
 */
#include <iostream>
using namespace std;
int main(void)
{
  string s("lj");
  string s2 = s;
  cout << (void*)s.c_str() << endl;
  cout << (void*)s2.c_str() << endl;
  return 0;
}
