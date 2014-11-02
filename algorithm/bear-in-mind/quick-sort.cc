// copyright @ L.J.SHOU Dec.09, 2013
// three versions of quick-sort
// type num 9
#include <cstring> 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N=10000;

void QuickSort1(int *a, int left, int right)
{//loop invariant: 
 //a[0..i-1]<x  a[i..j-1]>=x
  if(left >= right) return;
  int x = a[right];//pivot
  int i, j;
  for(i=j=left; j<right; ++j)
    if(a[j] < x) swap(a[i++], a[j]);
  swap(a[i], a[right]);

  QuickSort1(a, left, i-1);
  QuickSort1(a, i+1, right);
}

void QuickSort2(int *a, int left, int right)
{//loop invariant:
 //a[0..i-1]<=x  a[j+1..right]>=x
  if(left >= right) return;
  int x = a[right]; //pivot
  int i(left), j(right-1);
  while(i <= j)
  {
    while(a[i] < x) i++;// pivot as sentinel
	while(a[j] > x && j >= left) j--; //no sentinel
	if(i > j) break; // must
	swap(a[i++], a[j--]);
  }
  swap(a[right], a[i]);

  QuickSort2(a, left, i-1);
  QuickSort2(a, i+1, right);
}

void QuickSort3(int *a, int left, int right)
{ 
  if(left >= right) return;
  int x = a[right]; //pivot
  int i, j, k;
  i = k = left;
  j = right-1;
  while(k <= j)
  {
    if(a[k] < x)
	  swap(a[i++], a[k++]);
	else if(a[k] > x)
	  swap(a[j--], a[k]);
	else
	  k++;
  }
  swap(a[right], a[++j]);

  QuickSort3(a, left, i-1);
  QuickSort3(a, j+1, right);
}

void Print(int *a, int n)
{
  for(size_t i=0; i<n; ++i)
    cout << a[i] << " ";
  cout << endl;
}

void Randomize(int *a, int n)
{
  for(int i=0; i<n; ++i)
    a[i] = rand() % 1000000;
}

int Partition(int *a, int left, int right)
{
  int i, j;
  int x = a[right]; //pivot
  for(i=j=left; j<right; ++j)
  {
    if(a[j] < x) swap(a[i++], a[j]);
  }
  swap(a[right], a[i]);
  return i;
}


//Iterative version of QuickSort 
void QuickSortIter(int *a, int n) 
{
  assert(a != nullptr && n >= 0);
  if(n < 2) return;
  stack<pair<int, int> > s;
  s.push(make_pair(0, n-1));
  int left(0), right(0);
  int mid(0);

  while(!s.empty()) {
    left = s.top().first;
    right = s.top().second;
    s.pop();
    if(left >= right) continue;
    mid = Partition(a, left, right);
    s.push(make_pair(left, mid-1));
    s.push(make_pair(mid+1, right));
  }
}


//bool Test(void (*quick_sort)(int *a, int, int))
void Test()
{
  srand(time(0));
  int *a(NULL), *b(NULL), n;
  for(int i=0; i<N; ++i)
  {
    n = rand() % 10000;
    a = new int[n];
    b = new int[n];
    Randomize(a, n);
    memcpy(b, a, sizeof(int)*n);
    QuickSortIter(a, n);
    //QuickSort3(a, 0, n-1);
    sort(b, b+n);
    for(int i=0; i<n; ++i)
    {
      if(a[i]-b[i]) 
	  {
	    cout << "error" << endl;
		break;
	  }
    }
    delete [] a;
    delete [] b;
  }
}


int main(void)
{
  Test(); 
  return 0;
}
