/**
 * @file find-path.cc
 * @brief find a path between two nodes in a directed graph
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-08-12
 */

#include <bits/stdc++.h>
using namespace std;

const int MaxV = 10000;
const int MaxE = 10000;

int d[MaxV];
vector<int> edge[MaxV];
int V, E; //# of vertices and edges

enum State {
  Unvisited,
  Visited,
  Visiting
};
State visited[MaxV]; 

bool ExistedPath(int s, int t)
{
  assert(s >= 0 && s < V);
  assert(t >= 0 && t < V);
  if(s == t) return true;

  for(int i=0; i<V; ++i) visited[i] = Unvisited;
  visited[s] = Visiting;
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    s = q.front(); q.pop();
    //visited s's adjacent vertices
    for(auto v : edge[s]) {
      if(visited[v] == Unvisited) {
        visited[v] = Visiting;
        q.push(v);
        if(v == t) return true;
      }
    }
    visited[s] = Visited;
  }
  return false;
}

int main(void)
{
  int u, v;
  scanf("%d%d", &V, &E);
  for(int i=0; i<E; ++i) {
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
  }
  int s(0), t(0);
  scanf("%d%d", &s, &t);
  cout << ExistedPath(s, t) << endl;

  return 0;
}


