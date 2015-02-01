/**
 * @file prim.cc
 * @brief prim's algorithm to compute
 * Minimum spanning tree.
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-30
 */

#include <iostream>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)
const int MAX_V = 1000;

int V;
bool used[MAX_V];
int cost[MAX_V][MAX_V];
int min_cost[MAX_V];

int Prim()
{
    fill_n(used, V, false);
    fill_n(min_cost, V, INT_MAX);
    min_cost[0] = 0;
    int res = 0;

    while(true) {
        int v = -1;
        For(u, V) {
            if(!used[u] && (v == -1 || min_cost[u] < min_cost[v]))
                v = u;
        }
        if(v == -1) break;
        used[v] = true;
        res += min_cost[v];

        For(u, V) {
            if(cost[v][u] == -1) continue; 
            min_cost[u] = min(min_cost[u], cost[v][u]);
        }
    }
    return res;
}

void Test()
{
     // Let us create following weighted graph
     //     10
     //  0-------1
     //  |  \    |
     // 6|  5\   |15
     //  |     \ |
     //  2-------3
     //       4       
     V = 4;
     int c[4][4] = {{0,10,6,5}, 
                    {10,0,-1,15}, 
                    {6,-1,0,4}, 
                    {5,15,4,0}};
     For(i, V) {
        For(j, V) {
            cost[i][j] = c[i][j];
        }
     }

     cout << Prim() << endl;
}

int main(void)
{
    Test();
    return 0;
}
