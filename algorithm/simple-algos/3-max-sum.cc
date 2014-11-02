// copyright @ L.J.SHOU Feb.19, 2014
// maximum sum of sub-array O(N)
#include <iostream>
#include <cassert>
using namespace std;

int MaxSum(int a[], int n)
{
  assert(n >= 0);
  if(n == 0) return 0;
  int result(0), sum(0);

  for(int i=0; i<n; ++i)
  {
    if(sum < 0){
	  sum = a[i];
	}
	else{
	  sum += a[i];
	}
	result = max(result, sum);
  }

  return result;
}

int main(void)
{
  int a[]={1,-2,3,10,-4,7,2,-5};

  cout << MaxSum(a, sizeof(a)/sizeof(int)) << endl;

  return 0;
}
