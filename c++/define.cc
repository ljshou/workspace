/**
 * @file define.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-29
 */
#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
  int a=5, b=0;
  cout << MAX(++a, b+10) << endl;
  cout << "a: " << a << endl;
  return 0;
}

