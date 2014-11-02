#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;


/*
 * Complete the function below.
 */
int calcMaxVertex(vector < int > numbers) {
  if(0 == numbers.size()) return 0;
  sort(numbers.begin(), numbers.end());
  int n = numbers.size();
  vector<int> target(n, 0);
  int left = 0, right = n -1;

  for(int i = 0; i < n; ++i)
  {
    if(i & 0x1) target[left++] = numbers[i];
    else target[right--] = numbers[i];
  }
  for(int i = n - 1; i > 0; --i)
  {
    for(int j = 0; j < i; ++j)
    {
      target[j] += target[j+1];
    }
  }
  return target[0];
}

void dfs(vector<vector<int> > &citys, vector<vector<int> > &flag,
         int s_x, int s_y, int k, int &path, bool cover)
{
  int row = citys.size();
  int col = citys[0].size();

  if(s_x < 0 || s_x >= row || s_y < 0 || s_y >= col)
    return;
  if(1 == flag[s_x][s_y])
    return;
  if(2 == citys[s_x][s_y])
    cover = true;
  //cout << s_x << " " << s_y << " " << k << endl;
  --k;
  if(0 == k)
  {
    if(cover) ++path;
    //cout << "*" << path << endl;
    return;
  }
  flag[s_x][s_y] = 1;

  dfs(citys, flag, s_x - 1, s_y, k, path, cover);
  dfs(citys, flag, s_x + 1, s_y, k, path, cover);
  dfs(citys, flag, s_x, s_y - 1, k, path, cover);
  dfs(citys, flag, s_x, s_y + 1, k, path, cover);

  dfs(citys, flag, s_x - 1, s_y - 1, k, path, cover);
  dfs(citys, flag, s_x - 1, s_y + 1, k, path, cover);
  dfs(citys, flag, s_x + 1, s_y - 1, k, path, cover);
  dfs(citys, flag, s_x + 1, s_y + 1, k, path, cover);


  flag[s_x][s_y] = 0;
}


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, m, k;

  while(cin >> n >> m) {
    vector<vector<int> > citys;
    vector<int> col(m, 0);
    citys.assign(n, col);
    vector<vector<int> > flag;
    flag.assign(n, col);
    int startx, starty;
    for(int i = 0; i < n; ++i)
    {
      for(int j = 0; j < m; ++j)
      {
        scanf("%d", &citys[i][j]);
        if(1 == citys[i][j])
        {
          startx = i;
          starty = j;
        }
      }
    }
    scanf("%d", &k);

    int ret = 0;
    bool cover = false;
    dfs(citys, flag, startx, starty, k, ret, cover);
    printf("%d\n", ret);
  }

  return 0;
}
