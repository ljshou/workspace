/**
 * @file test2.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-09-24
 */

#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, int step, vector<vector<int> > &matrix, vector<vector<bool> > &visited, int &count, bool flag)
{
  const int m = matrix.size(), n = matrix.front().size();
  if(x < 0 || x >= m || y < 0 || y >= n) return;
  if(visited[x][y]) return;

  if(matrix[x][y] == 2) flag = true;
  if(step == 1) {
    if(flag) ++count;
    return;
  }
  visited[x][y] = true;
  //if(matrix[x][y] == 2) flag = true;

  dfs(x-1, y-1, step-1, matrix, visited, count, flag);
  dfs(x-1, y, step-1, matrix, visited, count, flag);
  dfs(x-1, y+1, step-1, matrix, visited, count, flag);
  dfs(x, y-1, step-1, matrix, visited, count, flag);
  dfs(x, y+1, step-1, matrix, visited, count, flag);
  dfs(x+1, y-1, step-1, matrix, visited, count, flag);
  dfs(x+1, y, step-1, matrix, visited, count, flag);
  dfs(x+1, y+1, step-1, matrix, visited, count, flag);

  //if(matrix[x][y] == 2) flag = false;
  visited[x][y] = false;
}

void ComputePath(int x, int y, int step, vector<vector<int> > &matrix)
{
  if(matrix.empty() || matrix.front().empty()) return;
  const int m = matrix.size(), n = matrix.front().size();
  vector<vector<bool> > visited(m, vector<bool>(n, false));
  int count(0);
  bool flag(false);
  dfs(x, y, step, matrix, visited, count, flag);
  cout << count << endl;
}

int main(void)
{
  int n, m;
  while(cin >> n >> m) {
    vector<vector<int> >  matrix(n, vector<int>(m,0));
    int x(0), y(0), step(0);
    for(int i=0; i<n; ++i)
    {
      for(int j=0; j<m; ++j)
      {
        cin >> matrix[i][j];
        if(matrix[i][j] == 1) {
          x = i;
          y = j;
        }
        //cout << matrix[i][j] << " ";
      }
      //cout << endl;
    }
    cin >> step;

    ComputePath(x, y, step, matrix);
  }

  return 0;
}
