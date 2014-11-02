/**
 * @file max-multiphy.cc
 * @brief max multiphy of a vector
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-26
 */

#include <iostream>
#include <vector>
using namespace std;

double MaxMultiply(double *a, int n)
{
  double result(a[0]);
  vector<double> max_vec(n), min_vec(n);
  max_vec[0] = a[0];
  min_vec[0] = a[0];
  
  for(int i=1; i<n; ++i)
  {
      max_vec[i] = max(a[i], max(a[i]*min_vec[i-1], a[i]*max_vec[i-1]));
      min_vec[i] = min(a[i], min(a[i]*min_vec[i-1], a[i]*max_vec[i-1]));
      result = max(result, max_vec[i]);
  }
  return result;
}

int main(void)
{
  double a[]={-2.5, 4, 0, 3, 0.5, 8, -1};

  cout << MaxMultiply(a, sizeof(a)/sizeof(double)) << endl;

  return 0;
}

