/**
 * @file bellman-ford.cc
 * @brief Bellman-Ford
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-19
 */

#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
const int MAX_V = 100000;
const int MAX_E = 100000;

struct edge {
  int from, to;
  int weight;
};
edge es[MAX_E]; //边
int d[MAX_V]; //距离
int V, E;

void ShortestPath(int s) {
  for(int i=0; i<V; ++i) d[i] = INF;
  d[s] = 0;

  int u, v, w;
  for(int i=0; i+1<=V; ++i) 
  {
    for(int j=0; j<E; ++j) {
      u = es[j].from; 
      v = es[j].to;
      w = es[j].weight;
      //Relax
      d[v] = min(d[v], d[u] + w);
    }
  }

  copy(d, d+V, ostream_iterator<int>(cout, " "));
  cout << endl;
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
  ShortestPath(0);

  return 0;
}
