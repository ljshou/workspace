#include <iostream>
using namespace std;

const int MaxQueueSize=1000;
struct Queue
{
  int queue[MaxQueueSize];
	int front, rear;
};

int MinCost(int c[], int n, int m)
{
  struct Queue q;
	q.front = q.rear = 0;
	int *f = new int[n];
	for(int i=0; i<n; ++i)
	{
	  //delete obsolete elements
		while(q.front != q.rear && q.queue[q.front + 1] < i-m)
		  q.front = (q.front + 1) % MaxQueueSize;
		//compute f[i]
		if(i < m) f[i] = c[i];
		else f[i] = c[i] + f[q.queue[q.front + 1]];
		//insert
		while(q.front != q.rear && f[q.queue[q.rear]] >= f[i])
		  q.rear = (q.rear - 1) % MaxQueueSize;
		q.rear = (q.rear + 1) % MaxQueueSize;
		q.queue[q.rear] = i;
	}
	cout << "f: ";
	for(int i=0; i<n; ++i)
	  cout << f[i] << " ";
	cout << endl;
	int min_cost(0x7FFFFF);
	for(int i=n-1; i>m-1; --i)
	  min_cost = min(min_cost, f[i]);
	delete [] f;
	return min_cost;
}

int main()
{
  int c[]={1,2,5,6,2};
	cout << "Min_cost: " << MinCost(c, sizeof(c)/sizeof(int), 3) << endl;
  return 0;
}
