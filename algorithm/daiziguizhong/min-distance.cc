/**
 * @file min-distance.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-20
 */
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int x_=0, int y_=0):
        x(x_), y(y_) {}
};

double distance(const Point &lhs, const Point &rhs)
{
    double x= lhs.x - rhs.x;
    double y= lhs.y - rhs.y;
    return sqrt(x*x + y*y);
}

double MinDistance(vector<Point> &points)
{
    const int n = points.size();
    if(n == 0) return 0.0;

    vector<vector<double> > f(n, vector<double>(n, 0.0));
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            if(j-i > 1) {
                f[i][j] = f[i][j-1] + distance(points[j-1], points[j]);
            }
            else {
                f[i][j] = f[0][i] + distance(points[0], points[j]); 
                for(int k=1; k<i; ++k)
                    f[i][j] = min(f[i][j], f[k][i] + distance(points[k], points[j]));
            }
        }
    }
    return f[n-1][n-1];
=======
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
}

int main(void)
{
    Test();
    return 0;
}
