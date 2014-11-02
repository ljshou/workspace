/**
 * @file lambda.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-07
 */
#include <bits/stdc++.h>
using namespace std;

struct Int {
  Int(int x=0): val(x) {}
  int val;
};

int main(void)
{
  vector<Int> vec{4,1,6,2,9,10,3,5};
  sort(vec.begin(), vec.end(), [](const Int &lhs, const Int &rhs) {return lhs.val < rhs.val;});

  for(auto x : vec) {
    cout << x.val << " ";
  }
  cout << endl;
  return 0;
}

