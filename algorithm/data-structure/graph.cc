// copyright @ L.J.SHOU Jan.13, 2014
// graph based on adjacent list representation
#include "graph.h"
#include <ctime>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef char ElementType;
typedef Vertex* Graph;

enum Color{WHITE, GRAY, BLACK};

struct Edge
{
  int vertex;
  int weight;
  Edge *next;
};

struct Vertex
{
  Color color;
  ElementType element;
  int start, finish;
  Edge *next;//head of adjacent list
};

Graph Create(Graph graph, int n)
{
  graph = new Vertex[n]; 
  for(int i=0; i<n; ++i)
  {
    graph[i].color = WHITE;
    graph[i].element = i + 'a';
	graph[i].start = 0;
	graph[i].finish = 0;
	graph[i].next = NULL;
  }
  return graph;
}

// Reset Graph
void Clear(Graph graph, int n)
{
  for(int i=0; i<n; ++i)
  {
    graph[i].color = WHITE;
	graph[i].start = 0;
	graph[i].finish = 0;
  }
}

Graph DeleteGraph(Graph graph, int n)
{
  for(int i=0; i<n; ++i)
  {
    Edge* head(graph[i].next), *next(NULL);
	while(head)
	{
	  next = head->next;
	  delete head;
	  head = next;
	}
  }
  delete [] graph;
  return NULL;
}

// return the outdegree of vertex i
int OutDegree(Graph g, int i)
{ 
  int num(0);

  Edge* link(g[i].next);
  while(link)
  {
    link = link->next;
	++ num;
  }

  return num;
}

// test whether edge(i, j) exists
bool Exist(Graph g, int i, int j)
{
  Edge *link(g[i].next); 

  while(link && link->vertex != j)
    link = link->next;

  if(link == NULL)
    return false;
  else
    return true;
}

bool InsertEdge(Graph g, int i, int j)
{
  if(Exist(g, i, j)){
    cout << "edge (" << i << "," << j << ") already existed" << endl;
    return false;
  }

  Edge *edge(NULL);
  edge = new struct Edge;
  edge->vertex = j;
  edge->next = g[i].next;
  g[i].next = edge;

  return true;
}

bool DeleteEdge(Graph g, int i, int j)
{
  if(!Exist(g, i, j)){
    cout << "edge (" << i << "," << j << ") doesn't exist" << endl;
    return false;
  }

  Edge *cur(g[i].next), *pre(cur);

  while(cur && cur->vertex != j)
  {
    pre = cur;
    cur = cur->next;
  }

  if(pre == NULL)
  { // delete head edge
    g[i].next = cur->next;
	delete cur;
  }
  else
  {
    pre->next = cur->next;
	delete cur;
  }
  return true;
}

// print adjacent list
void OutPut(Graph g, int n)
{
  Edge *edge(NULL);
  for(int i=0; i<n; ++i)
  {
	cout << g[i].element << "->";
    edge = g[i].next;
	while(edge)
	{
	  cout << g[edge->vertex].element << "->";
	  edge = edge->next;
	}
	cout << "NULL" << endl;
  }
}

void DFS(Graph graph, int n)
{
  cout << "DFS: " << endl;;
  Clear(graph, n);
  for(int i=0; i<n; ++i)
  {
    if(graph[i].color == WHITE)
	  DFSVisit(graph, i);
  }
  cout << endl;

  cout << "DFS_stack: " << endl;
  Clear(graph, n);
  for(int i=0; i<n; ++i)
  {
    if(graph[i].color == WHITE)
	  DFSVisitStack(graph, i);
  }
  cout << endl;
}

// recursive DFS
void DFSVisit(Graph graph, int i)
{
  static int time(0);
  Edge *link(graph[i].next);

  cout << graph[i].element << " ";
  graph[i].color = GRAY;
  graph[i].start = ++time;

  while(link)
  { 
    if(graph[link->vertex].color == WHITE)
	  DFSVisit(graph, link->vertex);
	link = link->next;
  }

  graph[i].finish = ++time;
  graph[i].color = BLACK;
}

// non-recursive DFS
void DFSVisitStack(Graph g, int i)
{
  static int time(0);
  struct Edge* edge;
  int vertex;
  stack<int> s;

  //visit vertex i
  cout << g[i].element << " ";
  g[i].color = GRAY;
  g[i].start = ++time;
  s.push(i);

  while(!s.empty())
  {
    vertex = s.top();
	edge = g[vertex].next;
	while(edge)
	{
	  if(g[edge->vertex].color == WHITE)
	  {
		s.push(edge->vertex);
		cout << g[edge->vertex].element << " ";
		g[edge->vertex].start = ++time;
		g[edge->vertex].color = GRAY;
		break;
	  }
	  edge = edge->next;
	}
	//vertex's neigbours have been visited
	if(edge == NULL){ 
	  s.pop();
	  g[vertex].color = BLACK;
	  g[vertex].finish = ++time;
	}
  }
}

/////////////////////////////////////////////////////////////
// search all vertices that can be rearched from Source s ///
// compute the distances from source s //////////////////////
/////////////////////////////////////////////////////////////
void BFS(Graph g, int n, int s)
{ 
  queue<int> q;
  Edge *edge(NULL);
  int vertex;

  //visit source vertex
  Clear(g, n);
  cout << "BFS: " << endl;;
  cout << g[s].element << " ";
  g[s].color = GRAY;
  q.push(s);

  while(!q.empty())
  { 
    //dequeue
	vertex = q.front();
	q.pop();

    //all the adjacent vertices
	edge = g[vertex].next;
    while(edge) 
    {
      if(g[edge->vertex].color == WHITE){
	     g[edge->vertex].color = GRAY;
	     cout << g[edge->vertex].element << " ";
		 //enqueue
		 q.push(edge->vertex);
	  }
      edge = edge->next;
    }
    g[vertex].color = BLACK;
  }//end of while

  cout << endl;
}


int main()
{
  Graph graph;
  int num_vertices = 8;

  graph = Create(graph, num_vertices);

  InsertEdge(graph,0,1);
  InsertEdge(graph,1,2);
  InsertEdge(graph,2,3);
  InsertEdge(graph,3,2);
  InsertEdge(graph,4,0);
  InsertEdge(graph,1,5);
  InsertEdge(graph,2,6);
  InsertEdge(graph,3,7);
  InsertEdge(graph,1,4);
  InsertEdge(graph,4,5);
  InsertEdge(graph,5,6);
  InsertEdge(graph,6,7);
  InsertEdge(graph,7,7);
  InsertEdge(graph,6,5);

  OutPut(graph, num_vertices);
  DFS(graph, num_vertices);
  BFS(graph, num_vertices, 0);

  graph = DeleteGraph(graph, num_vertices);

  return 0;
}
