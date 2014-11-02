/**
 * @file permutation.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-06
 */

#include <bits/stdc++.h>
using namespace std;

void printPermutation(vector<int> &a)
{
  if(a.empty()) return;
  sort(a.begin(), a.end());
  do {
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }while(next_permutation(a.begin(), a.end())); 
}

int main(void)
{
  vector<int> a{3,2,1};
  printPermutation(a);
  return 0;
}

