/**
 * @file lambda.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-06
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  double rate = 0.1;
  auto price = [&](double total)->double{return rate * total;};
  cout << price(10) << endl;
  return 0;
}
