/**
 * @file financial-management.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-21
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
#define For(i, n) for(int i = 0; i < (n); ++ i)
int main(void)
{
  double sum = 0.0, x;
  For(i, 12) {
    cin >> x;
    sum += x;
  }
  cout << fixed << setprecision(2) << "$" << sum/12 << endl;
  return 0;
}
