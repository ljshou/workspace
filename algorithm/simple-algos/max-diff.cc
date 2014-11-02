// copyright @ L.J.SHOU Mar.3rd, 2014
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

int MaxDiff(int a[], int n)
{
  if(n < 2) return 0;
  vector<int> max_left(n, 0), min_left(n, 0);
  vector<int> max_right(n, 0), min_right(n, 0);

  int res1 = a[0], res2 = a[0];
  int sum1 = 0, sum2 = 0;
  for(int i=0; i<n; ++i)
  {
    if(sum1 < 0) sum1 = a[i];
	else sum1 += a[i];
	
    if(sum2 > 0) sum2 = a[i];
	else sum2 += a[i];

	res1 = max(res1, sum1);
	res2 = min(res2, sum2);

	max_left[i] = res1;
	min_left[i] = res2;
  }
  
  res1 = a[n-1]; res2 = a[n-1];
  sum1 = 0; sum2 = 0;
  for(int i=n-1; i>=0; --i)
  {
    if(sum1 < 0) sum1 = a[i];
	else sum1 += a[i];
	
    if(sum2 > 0) sum2 = a[i];
	else sum2 += a[i];

	res1 = max(res1, sum1);
	res2 = min(res2, sum2);

	max_right[i] = res1;
	min_right[i] = res2;
  }

  copy(max_left.begin(), max_left.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  copy(min_left.begin(), min_left.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  int result = abs(a[1] - a[0]);
  for(int i=1; i<n; ++i)
  {
	int diff = abs(max_right[i] - min_left[i-1]);
	result = max(result, diff);
	diff = abs(max_left[i-1] - min_right[i]);
	result = max(result, diff);
  }

  return result;
}

int main(void)
{
  int a[]={1,-2,3,5,-1};

  cout << MaxDiff(a, sizeof(a)/sizeof(int)) << endl;

  return 0;
}
