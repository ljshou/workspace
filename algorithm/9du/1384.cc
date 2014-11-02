/**
 * @file 1384.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-28
 */

#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

int a[1000][1000];
int m, n;

bool SearchInMatrix(int target)
{
  int i(0), j(n-1);
  while(i < m && j >= 0)
  {
    if(a[i][j] < target) {
      ++i;
    }
    else if(a[i][j] > target) {
      --j;
    }
    else {
      return true;
    }
  }
  return false;
}

int main(void)
{
  int target;

  //while(cin >> m >> n) {
  while(scanf("%d %d", &m, &n) != EOF) {
    assert(1 <= m && m <= 1000 && 1 <= n && n <= 1000);
    //cin >> target;
    scanf("%d", &target);
    assert(1 <= target <= 1000000);
    for(int i=0; i<m; ++i)
      for(int j=0; j<n; ++j)
        //cin >> a[i][j];
        scanf("%d", &a[i][j]);
    if(SearchInMatrix(target))
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
