/**
 * @file min-distance.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-30
 */

#include <iostream>
#include <cassert>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)

const int MAX_V = 10000;
const int MAX_E = 10000;
int V;

int cost[MAX_V][MAX_V];
bool used[MAX_V]; 
int d[MAX_V]; //distance

void dijkstra(int s)
{
    assert(s < V);
    fill_n(used, V, false);
    fill_n(d, V, INT_MAX);
    d[s] = 0;

    while(true)
    {
        int v = -1;
        for(int u = 0; u < V; ++ u) {
            if(!used[u] && (v == -1 || d[u] < d[v])) {
                v = u;
            }
        }
        if(v == -1) break;
        used[v] = true;

        for(int u=0; u<V; ++u) {
            if(cost[v][u] != -1) //reachable
                d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }

    // for(int u=0; u<V; ++u)
    //     cout << d[u] << " ";
    // cout << endl;
}

void Test()
{
    string str;
    cin >> V;
    for(int i=0; i<V; ++i) {
        cost[i][i] = 0;
        for(int j=0; j<i; ++j) {
            cin >> str; 
            if(str[0] != 'x')
                cost[i][j] = cost[j][i] = atoi(str.c_str());
            else
                cost[i][j] = cost[j][i] = -1;
        }
    }

    dijkstra(0);
    cout << *max_element(d, d+V) << endl;
}

int main(void)
{
    Test();
    return 0;
}
