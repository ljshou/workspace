#include <iostream>
using namespace std;

const int MaxQueueSize = 10000;
struct Queue
{
  int queue[MaxQueueSize];
	int front, rear;
};

void MaxOfLatestK(int *a, int n, int k)
{
  int *f = new int[n];
	struct Queue q;
	q.front = q.rear = 0;
	for(int i=0; i<n; ++i)
	{
	  while(q.front != q.rear && a[q.queue[q.rear]] <= a[i])
		  q.rear = (q.rear - 1) % MaxQueueSize;
		while(q.front != q.rear && q.queue[(q.front+1)%MaxQueueSize] < i-k+1)
		  q.front = (q.front + 1) % MaxQueueSize;
		q.rear = (q.rear + 1) % MaxQueueSize;
		q.queue[q.rear] = i;
		f[i] = a[q.queue[q.front+1]];
	}
	for(int i=0; i<n; ++i)
	  cout << f[i] << " ";
	cout << endl;
	delete [] f;
	return;
}

int main()
{
  int a[]={4,3,5,7,9,1,2,6,5};
	MaxOfLatestK(a, sizeof(a)/sizeof(int), 3);
	return 0;
}
