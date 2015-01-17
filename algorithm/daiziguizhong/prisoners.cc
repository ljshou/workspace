/**
 * @file prisoners.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-17
 */

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
    Edge(int u_=0, int v_=0):
        u(u_), v(v_) {}
};

struct Node {
    int visited;
    int start, end;
    Node(int v=0, int s=-1, int e=-1):
        visited(v), start(s), end(e) {}
};

bool dfs(int node_index, int time, const vector<vector<int> > &graph,
         vector<Node> &node, vector<int> &res)
{
    node[node_index].visited = 1;
    node[node_index].start = ++time;
    //all neighbors
    for(auto v : graph[node_index]) {
        if(node[v].visited == 1) { 
            //circle detected
            return false;
        }
        else if(node[v].visited == 0) {
            //not visited
            if(!dfs(v, time, graph, node, res)) 
                return false;
        }
    }
    node[node_index].visited = 2;
    node[node_index].end = ++time;
    res.push_back(node_index);

    return true;
}

bool Prisoners(int n, const vector<Edge> &vec)
{
    if(n <= 0 || vec.empty()) {
        for(int i=0; i<n; ++i) 
            cout << i << " ";
        cout << endl;
        return true;
    }
    //build a graph
    vector<vector<int> > graph(n);
    for(auto e : vec) {
        graph[e.u].push_back(e.v);
    }
    
    //0 unvisited, 1 visiting, 2 visited
    vector<Node> node(n);
    vector<int> res;
    int time = 0;
    //topological sort
    for(int i=0; i<n; ++i) {
        if(node[i].visited == 0) 
            if(!dfs(i, time, graph, node, res)) 
                return false;
    }

    cout << "Prisoners should stand in:" << endl;
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //print nodes
    return true;
}

void Test()
{
    int n = 4;
    vector<Edge> vec{{2,3}, {0,2}, {2,0}, {3,1}, {3,0}, {1,0}};
    Prisoners(n, vec);
}

int main(void)
{
    Test();
    return 0;
}
