/**
 * @file spfa.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-01
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)
const int MAX_V = 1e5 + 10;
const int MAX_E = 1e6 + 10;
const int INF = 0xffffff;
struct Edge {
    int to, cost;
    Edge(int t=0, int c=0):
        to(t), cost(c) {}
};
int V, E;
vector<Edge> G[MAX_V];
int d[MAX_V];
bool used[MAX_V];

int SPFA(int s, int t) 
{
    fill_n(d, V, INF);
    fill_n(used, V, false);
    d[s] = 0;
    queue<int> q;

    q.push(s); used[s] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop(); used[u] = false;
        For(i, G[u].size()) {
            Edge e = G[u][i];
            if(d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost;
                if(used[e.to] == false) {
                    q.push(e.to); 
                    used[e.to] = true;
                }
            }
        }
    }
    return d[t];
}

int main(void)
{
    int u, v, c, s, t;
    cin >> V >> E >> s >> t;
    --s, --t;
    For(i, E) {
        cin >> u >> v >> c;
        --u, --v;
        G[u].push_back(Edge(v, c));
        G[v].push_back(Edge(u, c)); //undirected
    }
    cout << SPFA(s, t) << endl;
    return 0;    
}
