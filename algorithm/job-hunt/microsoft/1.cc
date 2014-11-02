/**
 * @file 1.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-18
 */

#include <iostream>
#include <vector>
using namespace std;

int Solve(vector<int> &f, int m)
{
  const int n = f.size();
  if(n == 0 || m >= n) return 100;
  vector<int> g(n+1);
  g[0] = f[0]-1;
  for(int i=1; i<n; ++i)
    g[i] = f[i] - f[i-1] - 1;
  g[n] = 100 - f[n-1];

  vector<int> sum(n+2, 0);
  sum[0] = 0;
  for(int i=1; i<=n+1; ++i) {
    sum[i] = sum[i-1] + g[i-1];
  }

  int res = 0;
  ++m;
  for(int i=0; i<sum.size()-m; ++i) {
    res = max(res, sum[i+m] - sum[i]);
  }
  return res + m - 1;
}


int main(void)
{
  int num, n, m;
  vector<int> f;
  cin >> num;
  for(int i=0; i<num; ++i) {
    cin >> n >> m;
    f.resize(n);
    for(int j=0; j<n; ++j) {
      cin >> f[j];
    }
    cout << Solve(f, m) << endl;
  }
  return 0;
}

