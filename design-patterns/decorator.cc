/**
 * @file decorator.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-05
 */

#include "decorator.h"

int main(void)
{
  Person *xc = new Person("菜鸟");
  cout << "第一种装束:" << endl;

  TShirts *x = new TShirts();
  Shoe *y = new Shoe();
  BigTrouser *z = new BigTrouser();
  x->Decorate(xc);
  y->Decorate(x);
  z->Decorate(y);
  z->Show();

  cout << endl <<  "第二种装束:" << endl;
  y->Decorate(xc);
  z->Decorate(y);
  x->Decorate(z);
  x->Show();
  cout << endl;

  delete xc;
  delete x;
  delete y;
  delete z;

  return 0;
}
