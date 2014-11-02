/**
 * @file mem_ptr.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-26
 */

#include <bits/stdc++.h>
using namespace std;

class A {
public:
  A(int x=0): val(x) {}
  void print() { cout << val << " "; }
private:
  int val;
};

int main(void)
{
  vector<A*> vec;
  for(int i=0; i<5; ++i)
    vec.push_back(new A(i));

  //for_each(vec.begin(), vec.end(), mem_fun_ref(&A::print));
  for_each(vec.begin(), vec.end(), mem_fun(&A::print));

  for(auto x : vec) {
    delete x;
    x = nullptr;
  }

  return 0;
}
