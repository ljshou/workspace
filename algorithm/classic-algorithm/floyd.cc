/**
 * @file floyd.cc
 * @brief Floyd-Warshall
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-19
 */

#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MAX_V = 10000;
const int MAX_E = 10000;

struct edge {
  int from, to;
  int weight;
};

edge es[MAX_E];
int V, E;
int d[MAX_V][MAX_V];

void Solve() {
  for(int i=0; i<V; ++i) {
    for(int j=0; j<V; ++j) {
      d[i][j] = INF;
    }
    d[i][i] = 0;
  }
  for(int i=0; i<E; ++i) {
    int u = es[i].from;
    int v = es[i].to;
    d[u][v] = es[i].weight;
  }

  for(int k=0; k<V; ++k) 
    for(int i=0; i<V; ++i)
      for(int j=0; j<V; ++j) 
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

  //print distance
  for(int i=0; i<V; ++i) {
    for(int j=0; j<V; ++j) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }
}

int main(void)
{
  scanf("%d%d", &V, &E);
  int s, t, w;
  for(int i=0; i<E; ++i) {
    scanf("%d%d%d", &s, &t, &w);
    es[i].from = s;
    es[i].to = t;
    es[i].weight = w;
  }
  Solve();
  return 0;
}
