/**
 * @file missle.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-11
 */
#include <bits/stdc++.h>
using namespace std;

int Lis(vector<int> &vec)
{
  if(vec.empty()) return 0;
  vector<int> f(vec.size(), INT_MAX);
  for(int i=0; i<vec.size(); ++i)
    *upper_bound(f.begin(), f.end(), vec[i]) = vec[i];
  return lower_bound(f.begin(), f.end(), INT_MAX) - f.begin();
}

int main(void)
{
  int k;
  cin >> k;
  vector<int> vec(k);
  for(int i=0; i<k; ++i)
    cin >> vec[i];
  reverse(vec.begin(), vec.end());
  cout << Lis(vec) << endl;
  return 0;
}

