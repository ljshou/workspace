/**
 * @file dijkstra.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-01
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)
const int MAX_V = 1003;
const int MAX_E = 10005;
const int INF = 10000;
struct Edge {
    int to, cost;
    Edge(int t=0, int c=0):
    to(t), cost(c) {}
};

int V, E;
vector<Edge> G[MAX_V];
int d[MAX_V];
bool used[MAX_V];

int Dijkstra(int s, int t)
{
    cout << "s: " << s << " t: " << t << endl;
    fill_n(d, V, INF);
    fill_n(used, V, false);
    d[s] = 0;
    while(true) {
        int v = -1;
        For(i, V) {
            if(!used[i] && (v == -1 || d[i] < d[v]))
                v = i;
        }
        if(v == -1) break;
        cout << "v: " << v << endl;
        used[v] = true;
        //relax
        For(i, G[v].size()) {
            Edge e = G[v][i];
            d[e.to] = min(d[e.to], d[v] + e.cost);
        }
    }
    return d[t];
}

int main(void)
{
    int u, v, cost, s, t;
    cin >> V >> E >> s >> t;
    For(i, E) {
        cin >> u >> v >> cost;
        G[u-1].push_back(Edge(v-1, cost));
        G[v-1].push_back(Edge(u-1, cost));
    }
    cout << Dijkstra(s-1, t-1) << endl;
    return 0;
}
