/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-28
 */

#include <bits/stdc++.h>
using namespace std;

void MaxHeapify(int *a, int n, int i)
{
  int left(2*i+1), right(2*i+2);
  int largest(i);
  if(left < n && a[left] > a[largest]) {
    largest = left;
  }
  if(right < n && a[right] > a[largest]) {
    largest = right;
  }
  if(i != largest) {
    swap(a[i], a[largest]);
    MaxHeapify(a, n, largest);
  }
}

void BuildHeap(int *a, int n)
{
  for(int i=n/2; i>=0; --i)
    MaxHeapify(a, n, i);
}

void HeapSort(int *a, int n) 
{
  BuildHeap(a, n);
  for(int i=n-1; i>0; --i) {
    swap(a[0], a[i]);
    MaxHeapify(a, i, 0);
  }
}

int Partition(int *a, int left, int right)
{
  int i, j;
  int x = a[right]; //pivot
  for(i=j=left; j<right; ++j) {
    if(a[j] < x) {
      swap(a[i++], a[j]);
    }
  }
  swap(a[i], a[right]);
  return i;
}

void QuickSort(int *a, int left, int right) 
{ 
  if(right - left < 1) return;
  int p = Partition(a, left, right);
  QuickSort(a, left, p-1);
  QuickSort(a, p+1, right);
}


int main(void)
{
  int a[] = {3, 4,5,1,8,2,0};
  const int n = sizeof(a)/sizeof(int);
  QuickSort(a, 0, n-1); 
  for(int i=0; i<n; ++i) 
    cout << a[i] << " ";
  cout << endl;

  return 0;
}
