/* binary search implemented by L.J. in Oct. 20, 2013 */
/* type num: 5 */
#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearchRecursive(int *a, int l, int r, int x)
{
  if(l > r) return -1;
  int mid = l+(r-l)/2; //better than (l+r)/2 
  if(x == a[mid]) return mid;
  else if(x < a[mid]) return BinarySearchRecursive(a, l, mid-1, x);
  else return BinarySearchRecursive(a, mid+1, r, x); 
}

int BinarySearchVersionOne(int *a, int l, int r, int x)
{//search for x, if not, return -1
  int mid;
  while(l <= r)
  {
    mid = l + (r - l) / 2; 
	if(x < a[mid]) r = mid-1;
	else if(x > a[mid]) l = mid+1;
	else return mid;
  }
  return -1;
}

int BinarySearchVersionTwo(int *a, int n, int x)
{//if x exists, return the first x occurs
   int left(0), right(n-1), mid;
   while(left <= right) {
     mid = left + (right-left)/2;
	 if(x == a[mid])
	 {
	   if(left == right) return mid;
	   else right = mid;
	 }
	 else if(x < a[mid]) right = mid-1;
	 else left = mid+1;
   }
   return -1;
}

// return the first element which >= x
int LowerBound(int *a, int n, int x)
{
  int left(0), right(n-1), mid;
  
  while(left <= right){
    mid = left + ((right - left) >> 1);
    if(a[mid] < x){
        left = mid + 1;
    }
    else{
        right = mid - 1;
    }
  }

  return left;
}

// return first element which > x
int UpperBound(int *a, int n, int x)
{
  int left(0), right(n-1), mid;

  while(left <= right){
      mid = left + ((right - left) >> 1);
      if(a[mid] <= x){
          left = mid + 1;
      }
      else{
          right = mid - 1;
      }
  }

  return left;
}

int main()
{
  int a[]={1,2,2,2,3,3,3,3,4,5,6,7};
  int n = sizeof(a) / sizeof(int);
  cout << "lower bound: " << LowerBound(a, n, 8) << endl;
  cout << "stl lower_bound: " << lower_bound(a, a+n, 8) - a << endl;
  cout << "upper bound: " << UpperBound(a, n, 8) << endl;
  cout << "stl upper_bound: " << upper_bound(a, a+n, 8) - a << endl;
  return 0;
}
