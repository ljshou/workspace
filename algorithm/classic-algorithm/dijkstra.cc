/**
 * @file dijkstra.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-19
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX_V=100000;
const int INF = 1000000000;
typedef pair<int, int> P; //first 是距离， second 是节点编号

struct edge {
  int to;
  int weight;
  edge(int t=0, int w=0): to(t), weight(w) {}
};

int E, V;
vector<edge> G[MAX_V];
int d[MAX_V];

/**
 * find the shortest path from vertex 0 to other nodes
 * edge ---- adjacent matrix
 */
void Dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  // Initialize Source
  fill(d, d+V, INF);
  d[s] = 0;
  q.push(P(0, s));

  while(!q.empty()) {
    P p = q.top(); q.pop();
    int u = p.second;
    if(d[u] < p.first) continue; //p is obsolete

    //relax all u's adjacent nodes
    for(int i=0; i<G[u].size(); ++i) {
      edge e = G[u][i];
      //relax
      if(d[e.to] > d[u] + e.weight) {
        d[e.to] = d[u] + e.weight;
        q.push(P(d[e.to], e.to));
      }
    }
  }

  //distance vector
  copy(d, d+V, ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main(void)
{
  scanf("%d%d", &V, &E);
  int s, t, w;
  for(int i=0; i<E; ++i) {
    scanf("%d%d%d", &s, &t, &w);
    G[s].push_back(edge(t, w));
  }
  Dijkstra(0);
  return 0;
}




