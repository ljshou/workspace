/* copyright @ L.J.SHOU
 Description:
   find the medium of two sorted array of equal length
*/
#include <iostream>
#include <cassert>
using namespace std;

int BinarySearch(int *a, int n)
{
  int left(0), right(n-1), mid;
  assert(n >=2);
  //loop invariant: a[left]<=0, a[right]>=0
  while(left < right-1)
  {
    mid = left + (right-left)/2;
	if(a[mid] == 0)
	  return mid;
	else if(a[mid] < 0)
	  left = mid;
	else
	  right = mid;
  }
  return left;
}

int Medium(int *a, int *b, int n)
{
  if(a[0] >= b[n-1]) return b[n-1];
  if(b[0] >= a[n-1]) return a[n-1];
  int *f = new int[n];
  int k;
  for(int i=0; i<n; ++i)
    f[i] = a[i] - b[n-i-1];
  k = BinarySearch(f, n);
  delete [] f;
  return max(a[k], b[n-k-2]);
}

int main(void)
{
  int a[]={1,2,3,4,7,10,11,22,};
  int b[]={3,4,5,6,7,8,9,10,};
  assert(sizeof(a) == sizeof(b));
  cout << "Medium: " << Medium(a, b, sizeof(a)/sizeof(int)) << endl;
  return 0;
}
