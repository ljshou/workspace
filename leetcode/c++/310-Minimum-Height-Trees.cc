#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <set>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    	// build undirected graph
    	vector<set<int>> graph(n);
    	for (auto edge : edges)
    	{
    		graph[edge.first].insert(edge.second);
    		graph[edge.second].insert(edge.first);
    	}
    	vector<int> leaves;
    	for(int i=0; i<n; ++i) {
    		if(graph[i].size() == 1) leaves.push_back(i);
    	}
    	int m = n;
    	while(m > 2) {
    		for(auto from : leaves) {
    			int to = graph[from]
    		}
    	}

    	return leaves;
    }
};

int main(void)
{
	Solution s;
	vector<pair<int, int>> edges{{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
	auto roots = s.findMinHeightTrees(6, edges);
	copy(roots.begin(), roots.end(), ostream_iterator<int>(cout, " "));
	cout << endl; 
	// for(auto edge : edges)
	// {
	// 	cout << edge.first << "\t" << edge.second << endl;
	// }
	return 0;
}