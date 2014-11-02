//copyright @ L.J.SHOU Dec.2rd, 2013
//find the subvector with the sum closest to zero
#include <iostream>
#include <cmath>
using namespace std;

double NearZeroSum(double *a, int n)
{
  double *sum = new double[n+1];//cumulative sum
  double opt;
  sum[0] = 0;

  for(int i=1; i<n+1; ++i)
    sum[i] = sum[i-1]+a[i];
  sort(sum, sum+n+1);

  opt = abs(sum[0]);
  for(int i=1; i<n+1; ++i)
    opt = min(opt, abs(sum[i]-sum[i-1]));

  delete [] sum;
  return opt;
}

int main(void)
{
  double a[]={-1,2,-1};
  cout << NearZeroSum(a, sizeof(a)/sizeof(double)) << endl;
  return 0;
}
