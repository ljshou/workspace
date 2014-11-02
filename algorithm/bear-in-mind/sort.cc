/**
 * @file sort.cc
 * @brief sort
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-13
 */

#include <iostream>
#include <cstdlib>
using namespace std;

/** 
 * version 1: QuickSort
 * works not very well for almost sorted arrays
 */
void QuickSort(int *a, int left, int right)
{
  if(left >= right) return;
  int rand_index = left + rand() % (right - left);
  swap(a[rand_index], a[right]);

  int x = a[right]; //pivot
  int i, j;
  for(i=j=left; j<right; ++j)
  {
    if(a[j] < x){
      swap(a[i++], a[j]);
    }
  }
  swap(a[i], a[right]);

  QuickSort(a, left, i-1);
  QuickSort(a, i+1, right);
}

/**
 * version 2: QuickSort
 * works pretty well for almost sorted arrays
 */
void QuickSort2(int *a, int left, int right)
{
  if(left >= right) return;
  int x = a[left + (right-left >> 1)];
  int i(left), j(right);

  while(i <= j)
  {
    while(a[i] < x) ++i;
    while(a[j] > x) --j;
    if(i <= j){
      swap(a[i++], a[j--]);
    }
  }

  QuickSort2(a, left, i-1);
  QuickSort2(a, i, right);
}

void QuickSort3(int *a, int left, int right)
{
  if(left >= right) return;
  int x = a[right]; //pivot
  int i(left), j(right-1);

  while(i <= j)
  {
    while(a[i] < x) ++i; //a[right] as sentinel
    while(j >= left && a[j] > x) --j;
    if(i <= j){
      swap(a[i++], a[j--]);
    }
  }
  swap(a[right], a[i]);
  QuickSort3(a, left, i-1);
  QuickSort3(a, i+1, right);
}

/**
 * bubble sort O(N^2)
 * stable 
 */
void BubbleSort(int *a, int n)
{
  for(int i=1; i<n; ++i)
  {
    for(int j=0; j<n-i; ++j)
    {
      if(a[j] > a[j+1])
        swap(a[j], a[j+1]);
    }
  }
}

/**
 * insert sort O(N^2)
 * not stable
 */
void InsertSort(int *a, int n)
{
  int x, i, j;
  for(i=1; i<n; ++i)
  {
    x = a[i];
    for(j=i; j>0 && a[j-1] > x; --j)
      a[j] = a[j-1];
    a[j] = x;
  }
}

/**
 * Percolate down for HeapSort
 * recursive version
 */
void PercDown(int *a, int heapSize, int i)
{
  int left = 2*i + 1;
  int right = 2*i + 2, largest(i);

  if(left < heapSize && a[left] > a[largest])
    largest = left;
  if(right < heapSize && a[right] > a[largest])
    largest = right;

  if(largest != i)
  {
    swap(a[i], a[largest]);
    PercDown(a, heapSize, largest);
  }
}

/**
 * Percolate down for HeapSort
 * iterative version
 */
void PercDown2(int *a, int heapSize, int i)
{
  int child = 2*i + 1, x = a[i];

  while(child < heapSize)
  {
    if(child+1 < heapSize && a[child+1] > a[child])
      ++ child;

    if(a[child] <= x)
      break;

    a[i] = a[child];
    i = child;
    child = 2*i + 1;
  }

  a[i] = x;
}

void BuildHeap(int*a, int n)
{
  for(int i=n/2; i>=0; --i)
    PercDown2(a, n, i);
}

/**
 * HeapSort worst case: O(NlgN)
 * not stable
 */
void HeapSort(int *a, int n)
{
  BuildHeap(a, n);

  for(int i=n-1; i>0; --i)
  {
    swap(a[0], a[i]);
    PercDown2(a, i, 0);
  }
}

/**
 * shellSort 
 */
void ShellSort(int *a, int n)
{
  int gap;
  for(gap = n/2; gap>0; gap/=2)
  {
    for(int j=gap; j<n; ++j)
    {
      if(a[j] < a[j-gap])
      {
        int x = a[j];
        int k = j - gap;
        while(k>=0 && a[k] > x)
        {
          a[k+gap] = a[k];
          k -= gap;
        }
        a[k+gap] = x;
      }
    }
  }
}

int main(void)
{
  int a[20];

  srand(time(0));
  for(int i=0; i<20; ++i)
    a[i] = rand() % 30;
  //QuickSort3(a, 0, 19);
  ShellSort(a, 20);

  for(int i=0; i<20; ++i)
    cout << a[i] << " ";
  cout << endl;

  return 0;
}

