/**
 * @file 1363.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-31
 */

#include <iostream>
#include <stack>
using namespace std;
int n;
int f[1000+10];

void solve()
{
  stack<int> s;
  int i(1), j(1);
  bool flag = true;
  while(j <= n) {
	if(i == f[j]) {
	  ++i, ++j;
	}
	else if(!s.empty() && s.top() == f[j]) {
	  s.pop();
	  ++j;
	}
	else if(i <= n) s.push(i++);
	else {
	  flag = false;
	  break;
	}
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main(void)
{
  while((cin >> n) && n) {
	while((cin >> f[1]) && f[1]) {
	  for(int i=2; i<=n; ++i) {
		cin >> f[i];
	  }
	  //solve
	  solve();
	}
	cout << endl;
  }
  return 0;
}
