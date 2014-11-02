/**
 * @file smile.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-11
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int helper(int cur, int n, vector<int> &path)
{
  if(cur == n){
    copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
  }
  if(cur > n){
    path.push_back(cur - n);
    copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    path.pop_back();
    return cur - n;
  }
  
  int res(0xffff), time(0);
  path.push_back(1);
  for(int i=1; i<=(n-cur)/cur+1; ++i)
  {
    time = i + 1; // one copy and i's paste
    path.push_back(i);
    res = min(res, time + helper(cur*(i+1), n, path));
    path.pop_back();
  }
  return res;
}

int smile(int n)
{
  vector<int> path;
  return helper(1, n, path); 
}

int main(void)
{
  cout << smile(4) << endl;
  return 0;
}
