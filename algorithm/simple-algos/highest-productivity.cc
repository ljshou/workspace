#include <iostream>
#include <algorithm>
using namespace std;

const int N=10;
const int M=10;

struct node
{
  int cost; 
  int bonus;
  int deadline;
}work[N];

bool cmp(node lhs, node rhs)
{
  return (lhs.deadline < rhs.deadline);
}

int s[M] = {0}; 

void ZeroOnePack(int cost, int V, int weight)
{
  for(int v=V; v>=cost; --v)
  {
    s[v] = max(s[v], s[v-cost] + weight);
  }
  for(int v=0; v<M; ++v)
    cout << s[v] << " ";
  cout << endl;
}


int main()
{
  int n, i, j, last, ret;
  while(cin >> n)
  {
    ret = -1;
    memset(s, 0, sizeof(s)); // set s[n] to 0s
    for(i=0; i<n; ++i)
	{
	  work[i].cost = rand() % N;
	  work[i].bonus = rand() % N;
	  work[i].deadline = rand() % M;
	}

	sort(work, work+n, cmp); //sort work[n] by deadline
	last = work[n-1].deadline;

	for(i=0; i<n; ++i)
	{ 
	  cout << "cost:" << work[i].cost << " bonus:" 
	       << work[i].bonus << " deadline:" << work[i].deadline << endl;
	  ZeroOnePack(work[i].cost, work[i].deadline, work[i].bonus);
	}

	for(i=0; i<last; ++i)
	{
	  if(s[i] > ret)
	    ret = s[i];
	}
	cout << "Optimal Bonus: " << ret << endl;
  }
  return 0;
}
