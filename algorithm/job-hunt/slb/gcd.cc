/**
 * @file gcd.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-10
 */

#include <iostream>
using namespace std;

int gcd(int m, int n)
{
  if(n == 0) return m;
  return gcd(n, m%n);
}

int main(void)
{
  int m, n;
  while(cin >> m >> n) {
    cout << gcd(m, n) << endl;
  }
  return 0;
}
