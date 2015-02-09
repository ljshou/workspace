/**
 * @file kruskal.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-30
 */

#include <iostream>
using std::cout;
using std::endl;
using std::sort;

#define For(i, n) for(int i=0; i<(n); ++i)

const int MAX_V = 1000;
const int MAX_E = 10000;

struct Edge {
    int u, v;
    int cost;
};

struct cmp {
    bool operator()(const Edge &lhs, const Edge &rhs) const {
        return lhs.cost < rhs.cost;
    }
};

Edge es[MAX_E];
int parent[MAX_V];
int rank[MAX_V];
int V, E;

void UnionInit(int V)
{
    For(i, V) {
        parent[i] = i;
        rank[i] = 1;
    }
}

int FindParent(int u)
{
    //path compression
    if(parent[u] == u)
        return u;
    return parent[u] = FindParent(parent[u]);
}

bool Same(int u, int v)
{
    return FindParent(u) == FindParent(v);
}

//union by rank
void Union(int u, int v)
{
    u = FindParent(u);
    v = FindParent(v);
    if(u == v) return;
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else {
        parent[v] = u;
        if(rank[u] == rank[v]) ++ rank[u];
    }
}

int Kruskal()
{
    sort(es, es+E, cmp());
    UnionInit(V);

    int weight = 0;
    For(i, E) {
        if(!Same(es[i].u, es[i].v)) {
            Union(es[i].u, es[i].v);
            weight += es[i].cost;
        }
    }
    return weight;
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
     //  4       
     V = 4;
     E = 5;
     es[0].u = 0;
     es[0].v = 1;
     es[0].cost = 10;

     es[1].u = 0;
     es[1].v = 2;
     es[1].cost = 6;

     es[2].u = 0;
     es[2].v = 3;
     es[2].cost = 5;

     es[3].u = 1;
     es[3].v = 3;
     es[3].cost = 15;

     es[4].u = 3;
     es[4].v = 2;
     es[4].cost = 4;

     cout << Kruskal() << endl;
}

int main(void)
{
    Test();
    return 0;
}
