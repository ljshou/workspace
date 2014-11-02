// copyright @ L.J.SHOU Mar.2rd, 2014
// a distance maximizing problem
// O(N)
#include <iostream>
#include <vector>
using namespace std;

int MaxDistance(int a[], int n)
{
  if(n < 2) return -1;
  
  vector<int> LMin(n), RMax(n);
  //LMin[i]----min value in range[0-i]
  LMin[0] = a[0];
  for(int i=1; i<n; ++i)
    LMin[i] = min(LMin[i-1], a[i]);

  //RMax[i]----max value in range[i-n-1]
  RMax[n-1] = a[n-1];
  for(int i=n-2; i>=0; --i)
    RMax[i] = max(RMax[i+1], a[i]);

  int i=0, j=0, maxDiff=-1;
  while(i<n && j<n){
    if(LMin[i] < RMax[j]){
	  maxDiff = max(maxDiff, j-i);
	  j++;
	}
	else
	  i++;
  }

  return maxDiff;
}

int main(void)
{
  int a[]={4,3,5,2,1,3,2,3};
  cout << MaxDistance(a, sizeof(a)/sizeof(int)) << endl;
}
