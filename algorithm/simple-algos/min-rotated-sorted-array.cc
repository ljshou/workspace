//copyright @ L.J.SHOU Dec.2rd, 2013
//a[N] is sorted array, now rotated it.
//try to find the minimum element O(lgN)
#include <iostream>
using namespace std;
int Min(int *a, int n)
{
  int left(0), right(n-1), mid(0);
  while(left <= right)
  {//loop invariant: [left, right] contains the minimum
    mid = left + (right-left)/2;
    if(a[mid] < a[right])
      right = mid;
    else if(a[mid] > a[right])
      left = mid + 1;
    else
      return a[mid];
  }
  return a[mid];
}

int main(void)
{ 
  int a[]={3,4,5,6,7,2};
  cout << "mid: " << Min(a, sizeof(a)/sizeof(int)) << endl;
  return 0;
}
