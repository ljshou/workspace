/**
 * @file 3051.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-22
 */

#include <iostream>
using namespace std;

#define For(i,n) for(int i=0;i<(n);++i)

char f[1000][80];
bool visited[1000][80];

int m,n;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

int global;

void dfs(const int x, const int y, int & ret)
{
  if(x >= m || x < 0 || y >= n || y < 0 || f[x][y] != '*') return;
  if(visited[x][y] == true) return;
  visited[x][y] = true;
  ++ret;
  For(i,4)
  {
    int cx = x + dx[i];
    int cy = y + dy[i];
    dfs(cx,cy,ret);
  }
}

int maxArea()
{
  int ret=0;
  For(i,m)
  {
    For(j,n)
    {
      if(f[i][j] == '*') 
      {
        ret = 0;
        dfs(i,j,ret);
        global = max(global,ret);
      }

    }
  }
  return global;
}

int main(void)
{
  while(cin >> n >> m)
  {
    For(i,m)
      For(j,n)
        cin >> f[i][j];

    cout << maxArea() << endl;
  }
  return 0;
}
