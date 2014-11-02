/**
 * @file smart-pointer.cc
 * @brief tesing class SmartPointer 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-14
 */

#include "smart-pointer.h"
#include <iostream>
using namespace std;

int main(void)
{
  SmartPointer<int> p0(2);
  cout << *p0 << endl;

  SmartPointer<int> p1(p0);
  cout << *p1 << endl;

  SmartPointer<int> p2 = p1;
  cout << *p2 << endl;

  return 0;
}
