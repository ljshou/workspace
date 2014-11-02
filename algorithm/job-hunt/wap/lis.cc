/**
 * @file lis.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-07
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> alls;

void dfs(int i, string &path, string &a, vector<int> &f, long long &res);
void output(string &a, int len, vector<int> &f)
{
  string path;
  long long res(0); 
  for(int i=0; i<f.size(); ++i)
  {
    if(f[i] == len) {
      path.push_back(a[i]);
      dfs(i, path, a, f, res); 
      path.erase(path.end()-1);
    }
  }
  cout << "res: " << res << endl;
}

void dfs(int i, string &path, string &a, vector<int> &f, long long &res)
{
  if(i == 0 || f[i] == 1) {
    //copy(path.rbegin(), path.rend(), ostream_iterator<char>(cout, ""));
    //cout << endl;
    alls.push_back(path);

    string temp = path;
    reverse(temp.begin(), temp.end());
    res = max(res, atoll(temp.c_str()));
    return;
  }

  for(int j=0; j<i; ++j) {
    if(a[j] < a[i] && f[j] == f[i]-1)
    {
      path.push_back(a[j]);
      dfs(j, path, a, f, res); 
      path.erase(path.end()-1);
    }
  }
}

int lis2(string &a)
{
  if(a.size() < 2) return a.size();
  vector<int> f(a.size(), 1);

  for(int i=1; i<a.size(); ++i) {
    for(int k=0; k<i; ++k) {
      if(a[k] < a[i]) {
        f[i] = max(f[i], f[k] +1);
      }
    }
  }
  int len = *max_element(f.begin(), f.end());
  output(a, len, f);

  sort(alls.begin(), alls.end());
  for(auto x : alls) {
    copy(x.rbegin(), x.rend(), ostream_iterator<char>(cout, ""));
    cout << endl;
  }
  alls.clear();

  return len;
}

int main(void)
{
  string a;
  cin >> a;

  cout << lis2(a) << endl;
  return 0;
}
