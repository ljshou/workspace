// copyright @ L.J.SHOU Dec.23, 2013
// Test of smart pointer using counting reference

#include "smart-pointer.h"
#include <iostream>
using namespace std;

int main(void)
{
  SHOU::SmartPointer sp(new int(10));
  SHOU::SmartPointer *sp2 = new SHOU::SmartPointer(sp);

  cout << *sp << endl;
  *(*sp2) = 1;
  cout << *(*sp2) << endl;
  delete sp2;
  cout << *sp << endl;

  return 0;
}
