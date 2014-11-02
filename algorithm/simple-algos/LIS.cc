/* longest increasing subsequence of N-length array */
/* O(n^2) and O(nlgn) */
/* implemented by L.J. in Oct. 29, 2013 */
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int LIS(int array[], int length) //O(n^2)
{
  int L[length], longest(1); //L[i] means the longest sub-seq among those ending with element array[i]
  int sub[length][length];
  L[0] = 1;
  sub[0][0] = array[0];
  for(size_t i=1; i<length; ++i)
  {
    L[i] = 1;
	int k(i);
    for(size_t j=0; j<i; ++j) //pick array[i+1]
	  if(array[j] < array[i] && L[j]+1 > L[i]){
		  L[i] = L[j]+1;
		  k = j;
	  }
	if(k == i) sub[i][0] = array[i];
	else{
	  memcpy(&sub[i][0], &sub[k][0], L[k]*sizeof(int)); //dest, src, copy memory
	  sub[i][L[i]-1] = array[i];
	}
  }
  int k=0;
  for(size_t i=0; i<length; ++i){
	if(L[i] > longest){
	  longest = L[i];
      k = i;
	}
  }
  return longest;
}

int bsearch(int a[], int l, int r, int x)
{
  if(l > r) return r;
  else if(l==r && a[l] >= x) return l-1;
  else if(l==r && a[l] < x) return l;
  int mid = (l+r)/2;
  if(a[mid] >= x) return bsearch(a,l,mid-1,x);
  else if(a[mid] < x) return bsearch(a,mid+1,r,x);
}

int LIS_improved(int array[], int length) //O(nlg(n))
{
  int L[length], nMaxLIS(1), opt;
  int maxV[length+1];
  for(int i = 0; i <= length; ++i )
  {
  	maxV[i]=0;
  }
  for(size_t i=0; i<length; ++i){
    L[i] = 1;
  }
  maxV[1] = array[0];
  maxV[0] = -10000;
  for(size_t i=1; i<length; ++i)
  {
	int j;
    j = bsearch(maxV, 0, nMaxLIS, array[i]);
	L[i] = j+1; 

    if(nMaxLIS < L[i]){
	  opt = i;
	  nMaxLIS = L[i];
	  maxV[nMaxLIS] = array[i];
	}
	else if(maxV[j]<array[i] && array[i]<maxV[j+1])
	  maxV[j+1] = array[i];
  }

  for(size_t i=1; i<=nMaxLIS; ++i)
    cout << maxV[i] << " ";
  cout << endl;
    
  return nMaxLIS; 
}

int LIS_new(int *a, const int n)
{
  int dp[n];
  fill(dp, dp+n, INT_MAX);
  for(int i=0; i<n; ++i)
    *lower_bound(dp, dp+n, a[i]) = a[i];
  return lower_bound(dp, dp+n, INT_MAX) - dp; 
}

int LIS2(int *a, const int n)
{
  int dp[n];
  fill(dp, dp+n, INT_MAX);
  int left, right;
  for(int i=0; i<n; ++i)
  {
    left = 0; right = i;
    while(left < right)
    {
      int mid = left + (right-left)/2;
      if(dp[mid] < a[i]) left = mid+1;
      else right = mid;
    }
    dp[left] = a[i];
  }
  return lower_bound(dp, dp+n, INT_MAX) - dp;
}


int main()
{
  int a[20];
  srand(time(0));
  cout << "**********TEST********************" << endl;
  for(size_t j=0; j<20; ++j)
  {
    for(size_t i=0; i<sizeof(a)/sizeof(int); ++i)
      a[i] = rand()%100;

    cout << "(" << j+1 << ")" << " O(n^2) and O(nlgn): " << LIS(a,sizeof(a)/sizeof(int)) << " " 
	       << LIS_improved(a,sizeof(a)/sizeof(int)) << " " 
         << LIS_new(a, sizeof(a)/sizeof(int)) << " "
         << LIS2(a, sizeof(a)/sizeof(int)) << endl;
  }
  cout << "**********TEST********************" << endl;

  return 0;
}
