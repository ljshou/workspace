// copyright @ L.J.SHOU Mar.11, 2014
// jossef circle
#include <iostream>
#include <vector>
using namespace std;

int JosefCircle(int m, int n)
{
  vector<int> f(n+1, 0);

  for(int i=2; i<=n; ++i)
    f[i] = (f[i-1] + m) % i;

  return f[n];
}

int main(void)
{
  cout << JosefCircle(4, 7) << endl;

  return 0;
}
