/**
 * @file floyd-warshall.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-01
 */

#include <iostream>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)
const int MAX_V = 1e2 + 10;
const int MAX_E = 1e3 + 10;
const int INF = 0xffffff;
struct Edge {
    int from, to, cost;   
};

int V, E;
Edge es[MAX_E];
int d[MAX_V][MAX_V];

void FloydWarshall()
{
    For(i, V) {
        For(j, V)
            d[i][j] = INF;
        d[i][i] = 0;
    }

    For(i, E) {
        Edge e = es[i];
        d[e.from][e.to] = min(d[e.from][e.to], e.cost);
        d[e.to][e.from] = min(d[e.to][e.from], e.cost); //undirected graph
    }

    For(k, V) {
        For(i, V) {
            For(j, V) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    For(i, V) {
        For(j, V) {
            cout << d[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(void)
{
    cin >> V >> E;
    For(i, E) {
        cin >> es[i].from >> es[i].to >> es[i].cost;
        --es[i].from, --es[i].to;
    }
    FloydWarshall();
    return 0;
}
