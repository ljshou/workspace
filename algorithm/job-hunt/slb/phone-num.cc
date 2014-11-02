/**
 * @file phone-num.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-11
 */

#include <bits/stdc++.h>
using namespace std;

bool Prefix(string &s, string &t)
{
  if(s.empty()) return false;
  int i(0), j(0);
  for(; i<s.size() && j<t.size() && s[i] == t[j]; ++i, ++j);
  return i == s.size();
}

bool Valid(vector<string> vec)
{
  if(vec.empty()) return true;
  sort(vec.begin(), vec.end());

  for(int i=0; i<vec.size()-1;++i)
  {
    if(Prefix(vec[i], vec[i+1]))
      return false;
  }
  return true;
}


int main(void)
{
  int t, n;
  vector<string> vec;
  cin >> t;
  for(int i=0; i<t; ++i)
  {
    cin >> n;
    vec.resize(n);
    for(int j=0; j<n; ++j) {
      cin >> vec[j];
    }
    if(Valid(vec)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
