/**
 * @file new-nothrow.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-21
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int *p = new(nothrow) int[INT_MAX];
  if(p == NULL) {
    cerr << __FILE__ << " " << __LINE__  
         << " Unable to allocate memory" << endl;
  }
  delete p;
  return 0;
}
