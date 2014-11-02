// compare different quick-sort and insertion-sort
/*
* for all equal elements, insert use O(n), while insert-sort1 O(n^2)
* 
*/
#include <cstdlib>
#include <iostream>
using namespace std;

void InsertSort(int *a, int length)
{
  int x, i, j;
  for(i=1; i<length; ++i)
  {
    x = a[i];
	for(j=i; j > 0 && a[j-1] > x; --j)
	  a[j] = a[j-1];
    a[j] = x;
  }
}

void QuickSort1(int *a, int left, int right)
{ // work badly for all equal elements O(n2)
  if(left >= right) return;
  int x = a[right], i, j;
  for(i=j=left; j<right; ++j)
    if(a[j] < x)
	  swap(a[i++], a[j]);
  swap(a[i], a[right]);

  QuickSort1(a, left, i-1);
  QuickSort1(a, i+1, right);
}

void QuickSort2(int *a, int left, int right)
{ // work fine for all equal elements O(nlgn)
  if(left >= right) return;
  int x = a[right];//pivot
  int i(left), j(right-1);
  while(i <= j)
  {
    while(a[i] < x) i++;
    while(a[j] > x && j >= left) j--;
	if(i > j) break;//vital
	swap(a[i++], a[j--]);
  }
  swap(a[right], a[i]);

  QuickSort2(a, left, i-1);
  QuickSort2(a, i+1, right);
}

void Print(int *a, int n)
{
  for(size_t i=0; i<n; ++i)
    cout << a[i] << " "; 
  cout << endl;
}

void Randomize(int *a, int n)
{
  for(size_t i=0; i<n; ++i)
    a[i] = rand()%1000000;
}

int main(void)
{
  unsigned int n;
  time_t start, finish;
  cout << "This is a test for quick-sort and insert-sort" << endl;
  cout << "Please input n: " << endl;
  cin >> n; 
  int *a = new int[n];


  //Randomize(a, n);
  start = clock();
  InsertSort(a, n);
  finish = clock();

  cout << "insert Sort takes: " 
       << static_cast<double>(finish - start)/CLOCKS_PER_SEC
	   << " seconds" << endl;

  Randomize(a, n);
  start = clock();
  QuickSort2(a, 0, n-1);
  finish = clock();

  cout << "Quick Sort2 takes: " 
       << static_cast<double>(finish - start)/CLOCKS_PER_SEC
	   << " seconds" << endl;
  //Print(a, n);

  Randomize(a, n);
  start = clock();
  QuickSort1(a, 0, n-1);
  finish = clock();

  cout << "Quick Sort1 takes: " 
       << static_cast<double>(finish - start)/CLOCKS_PER_SEC
	   << " seconds" << endl;

  delete [] a;
  return 0;
}
