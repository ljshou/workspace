//copyright @ L.J.SHOU Dec.1st, 2013
//compute the max sum of sub-array
#include <iostream>
using namespace std;

double SubSum(double *a, int l, int r)
{//O(nlgn)
  cout << "SubSum called" << endl;
  if(l > r)
    return 0;
  if(l == r)
    return max(a[l], 0.0);
  int mid = l + (r - l)/2;
  double lsum(0), lmax_sum(0);
  for(int i=mid; i>=l; --i)
  {
    lsum += a[i];
	lmax_sum = max(lmax_sum, lsum);
  }

  double rsum(0), rmax_sum(0);
  for(int i=mid+1; i<=r; ++i)
  {
    rsum += a[i];
	rmax_sum = max(rmax_sum, rsum);
  }
  return max(lmax_sum+rmax_sum, max(SubSum(a, l, mid), SubSum(a, mid+1, r)));
}

double SubSum2(double *a, int l, int r)
{//O(n)
  double sum(0), max_sum(0);
  for(int i=l; i<=r; ++i) 
  {
    sum = max(0.0, sum+a[i]); 
	max_sum = max(max_sum, sum);
  }
  return max_sum;
}

int main(void)
{
  double a[]={31,-41,59,26,-53,58,97,-93,-23,84};
  cout << SubSum2(a, 0, sizeof(a)/sizeof(double)-1) << endl;
  return 0;
}
