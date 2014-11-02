/**
 * @file biparte.cc
 * @brief determine whether a graph is a biparte
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-19
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1000000;

vector<int> G[MAX_V]; // graph
int V; // # of vertices
int color[MAX_V]; //顶点的颜色

//将顶点染成 1 或者 -1
bool dfs(int v, int c) {
  color[v] = c;
  for(auto x : G[v]) {
    if(color[x] == c) return false; //adjacent nodes share same color
    if(color[x] == 0 && !dfs(x, -1*c)) return false;
  }
  return true;
}

//图可以是不连通的
void IsBiparte() {
  for(int i=0; i<V; ++i) {
    if(color[i] == 0) {
      if(!dfs(i, 1)) {
        cout << "No!" << endl;
        return;
      }
    }
  }
  cout << "Yes" << endl;
}

int main(void)
{
  int s, t, E;
  scanf("%d%d", &V, &E);
  for(int i=0; i<E; ++i) {
    scanf("%d%d", &s, &t);
    G[s].push_back(t);
    G[t].push_back(s); //无向图
  }
  IsBiparte();
  return 0;
}
