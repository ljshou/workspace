/**
 * @file count-ones.cc
 * @brief count how many ones exist in an integer
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-01
 */

#include <bits/stdc++.h>
using namespace std;

int CountOnes(int x)
{
  if(x == 0) return 0;
  int len(0);
  while(x) {
    x = x & (x-1);
    ++len;
  }
  return len;
}

int main(void)
{
  int num(0);
  cout << "please input an integer: " << endl;
  cin >> num;
  cout << CountOnes(num) << endl;
  return 0;
}
