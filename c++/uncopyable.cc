/**
 * @file uncopyable.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-30
 */

#include <iostream>
using namespace std;

class A {
public:
  void print() {
  }
private:
  A(const A &rhs); //只有声明
  A& operator=(const A &rhs);
};

class Uncopyable {
public:
  Uncopyable() {}
  ~Uncopyable() {}
private:
  Uncopyable(const Uncopyable&);
  Uncopyable& operator=(const Uncopyable&);
};

class B : private Uncopyable {
};

int main(void)
{
  B b;
  throw b;

  return 0;
}


