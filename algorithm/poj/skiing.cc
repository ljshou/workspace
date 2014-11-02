/**
 * @file skiing.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-21
 */

#include <iostream>
#include <climits>
using namespace std;

#define For(i, n) for(int i = 0; i < (n); ++ i)
int m, n;
int vec[100][100];
int f[100][100];

int DFS(int x, int y)
{
  if(f[x][y] != INT_MAX) 
    return f[x][y];
  int res = 0;
  if(x > 0 && vec[x][y] > vec[x-1][y])
    res = max(res, DFS(x-1, y));
  if(y > 0 && vec[x][y] > vec[x][y-1])
    res = max(res, DFS(x, y-1));
  if(x+1 < m && vec[x][y] > vec[x+1][y])
    res = max(res, DFS(x+1, y));
  if(y+1 < n && vec[x][y] > vec[x][y+1])
    res = max(res, DFS(x, y+1));
  return f[x][y] = 1 + res;
}

int Solve() 
{
  fill_n(&f[0][0], 100*100, INT_MAX);
  int res = 0;
  For(i, m) 
    For(j, n)
      res = max(res, DFS(i, j));

  return res;
}

int main(void)
{
  while(cin >> m >> n) {
    For(i, m)
      For(j, n) 
        cin >> vec[i][j];
    cout << Solve() << endl;
  }
  return 0;
}
