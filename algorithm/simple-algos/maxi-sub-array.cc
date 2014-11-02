/**
 * @file maxi-sub-array.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-09-02
 */

#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int MaxSubArray(vector<int> &num, int m)
{
  const int n = num.size();
  vector<int> f(m+1, 0), g(m+1, 0);
  for(int i=1; i<=n; ++i) {
    for(int j=m; j>0; --j) {
      f[j] = max(f[j], g[j-1]) + num[i-1];
      g[j] = max(f[j], g[j]);
    }
  }
  return g[m];
}

int main(void)
{
  int m, n;
  vector<int> num;
  while(scanf("%d%d", &m, &n) != EOF) {
    num.resize(n);
    for(size_t i=0; i<n; ++i) {
      scanf("%d", &num[i]);
    }
    printf("%d\n", MaxSubArray(num, m));
  }
  return 0;
}
