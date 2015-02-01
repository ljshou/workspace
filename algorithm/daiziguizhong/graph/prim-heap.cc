/**
 * @file prim-heap.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-01
 */

#include <iostream>
#include <numeric>
#include <queue>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)
struct Edge {
    int to, cost;
    Edge(int to_=0, int cost_=0):
        to(to_), cost(cost_) {}
};
typedef pair<int, int> P; //distance, u 

const int MAX_V = 100003;
const int INF = 10000;
int V, E;
vector<Edge> G[MAX_V];
int d[MAX_V];
bool used[MAX_V];

int Prim()
{
    fill_n(d, V, INF);    
    fill_n(used, V, false);    
    d[0] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(make_pair(0, 0));

    int res(0);
    while(!q.empty()) {
        P p = q.top(); q.pop();
        int v = p.second;
        if(d[v] < p.first || used[v]) continue; //obsolete
        res += d[v];
        used[v] = true;
        cout << d[v] << endl;

        For(i, G[v].size()) {
            Edge e = G[v][i];
            if(d[e.to] > e.cost) {
                d[e.to] = e.cost;
                q.push(make_pair(e.cost, e.to));
            }
        }
    }
    cout << accumulate(d, d+V, 0) << endl;
    return res;
}

int main(void)
{
    cin >> V >> E;
    int u, v, cost;
    For(i, E) {
        cin >> u >> v >> cost;
        G[u-1].push_back(Edge(v-1, cost));
        G[v-1].push_back(Edge(u-1, cost)); //undirected graph
    }
    cout << Prim() << endl;
    return 0;
}
