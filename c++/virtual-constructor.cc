/**
 * @file virtual-constructor.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-28
 */

#include <bits/stdc++.h>
using namespace std;

class Base {
public:
  Base() {
    print(); //which print() is invoked??
  }
  virtual void print() const { 
    cout << "printing Base" << endl;
  }
private:
};

class Derived : public Base {
public:
  Derived() {
    print();
  }
  virtual void print() const { 
    cout << "printing Derived" << endl;
  }
};

int main(void)
{
  Derived d;
  return 0;
}
