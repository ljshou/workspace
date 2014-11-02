/* graph algorithms implemented by L.J. in Nov.12, 2013 */
#ifndef GRAPH_H_
#define GRAPH_H_
struct Edge;
struct Vertex;
typedef Vertex* Graph;

Graph CreateGraph(Graph graph, int n);
Graph DeleteGraph(Graph graph);
bool InsertEdge(Graph g, int i, int j);
bool Exist(Graph g, int i, int j);
int  Edges(Graph graph);
int  Vertices(Graph graph);
bool DeleteEdge(Graph g, int i, int j);
int Degree(Graph g, int i);
int InDegree(Graph g, int i);
int OutDegree(Graph g , int i);

void DFS(Graph g, int n);
void DFSVisit(Graph g, int i);
void DFSVisitStack(Graph g, int i);
#endif
