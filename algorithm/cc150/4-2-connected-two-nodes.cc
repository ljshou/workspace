/* copyright @ L.J.SHOU Jan.20, 2014
** tell whether there exists a path between two nodes
*/
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool ConnectedTwoNodes(vector<vector<int> > &graph, int s, int t)
{ // BFS
  assert( s >= 0 && s < graph.size());
  assert( t >= 0 && t < graph.size());
  if(s == t) return true;
  queue<int> q;
  vector<bool> visited(graph.size(), false);

  q.push(s);
  visited[s] = true;
  while(!q.empty())
  {
    int node = q.front(); q.pop();
	for(int i=0; i<graph[node].size(); ++i)
	  if(!visited[ graph[node][i] ]){
	    if(graph[node][i] == t) return true;
		visited[ graph[node][i] ] = true;
		q.push(graph[node][i]);
	  }
	visited[node] = true;
  }

  return false;
}

/* adjacent list
* 1 -> 3
* 2 -> 3
* NULL
* 1 -> 2
*/
int main(void)
{
  vector<vector<int> > graph;
  vector<int> path;

  path.push_back(1); path.push_back(3);
  graph.push_back(path);
  path[0] = 2;
  graph.push_back(path);
  graph.push_back(vector<int>());
  path[0] = 1; path[1] = 2;
  graph.push_back(path);

  cout << "adjacent list: " << endl;
  for(int i=0; i<graph.size(); ++i)
  {
    for(int j=0; j<graph[i].size(); ++j)
	  cout << graph[i][j] << " -> ";
	cout << "NULL" << endl;
  }
  cout << ConnectedTwoNodes(graph, 0, 0) << endl;
  cout << ConnectedTwoNodes(graph, 1, 0) << endl;
  cout << ConnectedTwoNodes(graph, 2, 0) << endl;
  cout << ConnectedTwoNodes(graph, 3, 0) << endl;

  return 0;
}
