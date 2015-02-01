/**
 * @file is-biparte.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-22
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

const int MAX_V = 10000;
vector<int> G[MAX_V]; //edges
int color[MAX_V];
int V; //# of nodes

bool dfs(int i, int c)
{
    color[i] = c;
    for(auto v : G[i]) {
        if(color[v] == 0) {
            if(!dfs(v, -1*c))
                return false;
        }
        else if(color[v] == c) {
            return false;
        }
    }
    return true;
}

bool IsBiparte()
{
    fill_n(color, V, 0);
    for(int i=0; i<V; ++i) {
        if(color[i] == 0) {
            if(!dfs(i, 1)) 
                return false;
        }
    }
    return true;
}

void Test()
{
    V = 5;
    vector<pair<int, int> > edges{{1,2},{1,3},{1,4},{2,3},{3,4}};
    for(auto e : edges) {
        //undirected graph
        G[e.first].push_back(e.second);
        G[e.second].push_back(e.first);
    }
    cout << IsBiparte() << endl;
}

int main(void)
{
    Test();
    return 0;
}
