/**
 * @file remove-erase.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-18
 */
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  vector<int> vec{1,2,1,3,4,5,2,1,1};
  copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  //lambda
  auto badValue = [](int x) {return x == 1;};
  vec.erase(std::remove_if(vec.begin(), vec.end(), badValue), vec.end());

  copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}
