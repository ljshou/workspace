/**
 * @file jossef.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-21
 */

#include <iostream>
#include <algorithm>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)

int f[14] = {0};
int Jossef(int k)
{
  int people[14] = {0};
  int m = k + 1, n = 2*k;
  for(int i=1; i<=k; ++i) {
    people[i] = (people[i-1] + m - 1) % (n - i + 1);
    if (people[i]  < k) {
      i = 0;
      ++m;
    }
  }
  f[k] = m;
  return m;
}

int main(void)
{
  int k;
  while(cin >> k && k != 0) {
    if(f[k] != 0) cout << f[k] << endl;
    else cout << Jossef(k) << endl;
  }
  return 0;
}
