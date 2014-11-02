// copyright @ L.J.SHOU Dec.10, 2013
// heap
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;

void PercolateDown(int *a, int heap_size, int i)
{
  int child, x;
  x = a[i];
  while((i<<1)+1 < heap_size)
  { // has at least one child
    child = (i<<1) + 1;
	if(child+1 < heap_size)
	{ // right child exists
	  if(a[child+1] > a[child])
	    child++;
	}
	if(x >= a[child]) break;
	a[i] = a[child];
	i = child;
  }
  a[i] = x;
}

void PercolateDown2(int *a, int left, int right)
{
  // pre: heap(l+1, r)
  // post:heap(l, r)
  int x(0), child(0);
  x = a[left];
  while((left<<1)+1 <= right)
  {
    child = (left<<1)+1;
	if(child+1 <= right)
	{
	  if(a[child+1] > a[child])
	    ++ child;
	}
	if(x >= a[child]) break;
	a[left] = a[child];
	left = child;
  }
  a[left] = x;
}

void BuildMaxHeap(int *a, int n)
{
  for(int i=n/2; i>=0; --i)
    PercolateDown2(a, i, n-1);
}

void HeapSort(int *a, int n)
{
  BuildMaxHeap(a, n);
  for(int i=n-1; i>0; --i)
  {
    swap(a[0], a[i]);
	PercolateDown(a, i, 0);
  }
}

void Print(int *a, int n)
{
  for(int i=0; i<n; ++i)
    cout << a[i] << " ";
  cout << endl;
}

int main(void)
{
  int *a(NULL), n;
  cout << "Please input n:" << endl;
  cin >> n;
  a = new int[n];
  srand(time(0));
  for(int i=0; i<n; ++i) 
    a[i] = rand() % 1000000;

  time_t start = clock();
  //HeapSort(a, n);
  sort_heap(a, a+n);
  time_t finish = clock();
  cout << "Heap Sort takes: " 
       << static_cast<double>(finish - start)/CLOCKS_PER_SEC
	   << " seconds" << endl;
 // Print(a, n);
  delete [] a;
  return 0;
}

