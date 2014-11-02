#include <iostream>
using namespace std;
const int MaxQueueSize = 10000;
struct Queue
{
  int queue[MaxQueueSize]; 
	int front, rear;
};

int MaxArea(int a[], int n)
{
  struct Queue q;
	q.front = q.rear = 0;
	int *left = new int[n];
	int *right = new int[n];

  for(int i=0; i<n; ++i)
	{
	  left[i] = i;
		while(q.front != q.rear && a[q.queue[q.rear]] > a[i])
		{
		  right[q.queue[q.rear]] = i;
			left[i] = left[q.queue[q.rear]];
			q.rear = (q.rear - 1) % MaxQueueSize;
		}
		if(a[q.queue[q.rear]] == a[i])  left[i] = left[q.queue[q.rear]];
		q.rear = (q.rear + 1) % MaxQueueSize;
		q.queue[q.rear] = i;
	}
	while(q.front != q.rear)
	{
	  right[q.queue[q.rear]] = n;
		q.rear = (q.rear - 1) % MaxQueueSize;
	}
	//compute Max area
	int amax(0);
	for(int i=0; i<n; ++i)
	  amax = max(amax, (right[i]-left[i])*a[i]);

	delete [] left;
	delete [] right;
	return amax;
}

int main()
{
	int height[]={5,8,4,4,8,4};
	for(int i=0; i<sizeof(height)/sizeof(int); ++i)
	  cout << height[i] << " ";
	cout << endl;
	cout << "max area is " << MaxArea(height, sizeof(height)/sizeof(int)) << endl;
  return 0;
}
