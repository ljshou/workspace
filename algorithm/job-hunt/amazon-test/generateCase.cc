/**
 * @file generateCase.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-09-24
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  srand(time(0));
  vector<int> f;
  int m, n;

  for(int i=0; i<200; ++i) {
    m = rand() % 8 + 3;
    n = rand() % 4 + 3;
    f.resize(m*n, 0);
    int start = rand() % (m * n);
    f[start] = 1;
    int end = rand() % (m * n);
    while(end == start) {
      end = rand() % (m * n);
    }
    f[end] = 2;

    cout << m << " " << n << endl;
    for(auto x : f)
      cout << x << " ";
    cout << endl;
    cout << rand() % 3 + 4 << endl;
  }

  return 0;
}

