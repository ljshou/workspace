/**
 * @file bind.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-14
 */

#include <bits/stdc++.h>
using namespace std;

int my_divide(int a, int b)
{
  return a / b;
}

int main(void)
{
  using namespace placeholders;

  auto f = bind(my_divide, _2, _1);
  cout << f(10, 2) << endl;
  return 0;
}
