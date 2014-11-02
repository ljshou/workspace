//copyright @ L.J.SHOU Dec.2rd, 2013
//given interger m and n, array x[n], find the integer i
//such that x[i]+...+x[i+m] is nearest zero
#include <iostream>
using namespace std;

int MNearZero(int *a, int n, int m)
{
  int * sum = new int [n+1];
  sum[0] = 0;
  for(int i=1; i<n+1; ++i)
    sum[i] = sum[i-1] + a[i-1];
    //sum[i] = sum[i-1] + a[i];//Error

  int k(0), min(abs(sum[m+1]-sum[0]));

  for(int i=1; i<n-m; ++i)
  {
    if(abs(sum[i+m+1]-sum[i]) < min)
	{
	  min = abs(sum[i+m+1] - sum[i]);
	  k = i;
	}
  }
  delete [] sum;
  return k;
}

int main(void)
{
  int a[]={0,1,2,-3};
  cout << MNearZero(a, sizeof(a)/sizeof(int), 2) << endl;
  return 0;
}
