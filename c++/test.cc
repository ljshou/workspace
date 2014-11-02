/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-25
 */

#include <bits/stdc++.h>
using namespace std;

void Endian() 
{
  union A{
    int num;
    char c;
  };
  A a;
  a.num = 1;
  if(a.c == 1) cout << "little endian" << endl; 
  else cout << "big endian" << endl;
}


int main(int argc, char *argv[])
{
  cout << strlen("\0") << endl;
  cout << sizeof("\0") << endl;
  cout << sizeof(void (*)()) << endl;

  Endian();

  return 0;
}
