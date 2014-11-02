// copyright @ L.J.SHOU Oct.15, 2013
// select the kth smallest number implemented 
// algorithm complexity: average  O(n) ************/
// type: 5
#include <iostream>
#include <cassert>
using namespace std;

int partition(int *a, int l, int r)
{
  int x = a[r];
  int i, j;

  for(i=j=l; j<r; ++j)
    if(a[j]<x)
	  swap(a[i++], a[j]);
  swap(a[i], a[r]);

  return i;
}

int partition_rand(int *a, int l, int r)
{
  int i = rand()%(r-l+1)+l;
  swap(a[i], a[r]);
  return partition(a, l, r); 
}

int select_rand(int *a, int l, int r, int i)
{
  assert(l <= r);
  int q, k;
  if(l==r) return a[l];
  q = partition_rand(a, l, r);
  k = q-l+1;
  if(i==k) return a[q];
  else if(i<k) return select_rand(a, l, q-1, i);
  else     return select_rand(a, q+1, r, i-k);
}

int main()
{
  int k(5);
  int a[]={10,9,8,7,6,18,8,0,-1,9};
  for(size_t i=0; i<sizeof(a)/sizeof(int); ++i)
    cout << a[i] << " ";
  cout << endl;
	/*
  for(size_t i=1; i<=10; ++i)
    cout << "the  " << i << "th smallest number is: " << select_rand(a, 0, 9, i) << endl;
	*/
  cout << "the  " << k << "th smallest number is: " << select_rand(a, 0, sizeof(a)/sizeof(int)-1, k) << endl;
	cout << "************Curent Array: *****************" << endl;
	for(int i=0; i<sizeof(a)/sizeof(int); ++i)
	  cout << a[i] << " ";
	cout << endl;
  return 0;
}
