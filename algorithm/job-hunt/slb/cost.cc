/**
 * @file cost.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-11
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int n;
  int num;
  double count(0);
  cin >> n;
  for(int i=0; i<n; ++i)
  {
    cin >> num;
    count += (num + 69) / 70 * 0.1;
  }
  printf("%.1lf\n", count);
  return 0;
}
