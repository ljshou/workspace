/**
 * @file 3.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-18
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

int e[101][101];
int visit[101][101];
vector<int> f;
vector<int> path;
int n, m;
int parent[101];

void BFS(int x, int y) {
  fill_n(parent, 101, 0);
  queue<int> q;
  q.push(x);
  
  vector<bool> V(n+1, false);
  V[x] = true;
  bool found = false;
  while(!q.empty() && !found) {
    x = q.front(); q.pop();
    //neighbor
    for(int i=1; i<=n; ++i) {
      if(e[x][y] !=0) {
        parent[y] = x;
        found = true;
        break;
      }
      if(e[x][i] != 0) {
        if(V[i] == true) continue;
        parent[i] = x;
        V[i] = true;
        q.push(i);
      }
    }
  }

  path.clear();
  //gen path
  int city = y;
  while(city != x) {
    path.push_back(city);
    city = parent[city];
  }
  path.push_back(x);
  reverse(path.begin(), path.end());
}

bool Valid(int index)
{
  for(int i=0; i+1<path.size(); ++i) {
    if(++visit[path[i]][path[i+1]] > 2) return false;
  }
  unordered_set<int> flag(path.begin(), path.end());
  for(int i=index+1; i<m; ++i)
    if(flag.find(f[i]) != flag.end()) {
      return false;
    }
  return true;
}

void Solve() 
{
  if(n < 2 || m == 0) {
    cout << "YES" << endl;
    return;
  }
  BFS(1, f[0]);
  if(!Valid(0)) {
    cout << "NO" << endl;
    return; 
  }
  for(int i=1; i<m; ++i) {
    BFS(f[i-1], f[i]);
    if(!Valid(i)) {
      cout << "NO" << endl;
      return; 
    }
  }
  cout << "YES" << endl;
}

int main(void)
{
  int num;
  int a, b;
  cin >> num;
  for(int i=0; i<num; ++i) {
    fill_n(&e[0][0], 101*101, 0);
    fill_n(&visit[0][0], 101*101, 0);
    cin >> n;
    for(int j=0; j<n-1; ++j) {
      cin >> a >> b;
      e[a][b] = e[b][a] = 1;
    }
    cin >> m;
    f.resize(m);
    for(int k=0; k<m; ++k) {
      cin >> f[k];
    }
    Solve();
  }
  return 0;
}

