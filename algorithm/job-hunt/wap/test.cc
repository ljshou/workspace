/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-08
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> P;

double Enumerate(vector<P> & a);
double MinTriangle(P *a, int n)
{
  assert(a != NULL);
  if(n <= 2) return INT_MAX;
  sort(a, a+n); //do not forget
  int mid = n /2;
  double x = a[mid].first;
  double res = min(MinTriangle(a, mid), MinTriangle(a+mid, n-mid));

  vector<P> b;
  for(int i=0; i<n; ++i)
  {
    if(fabs(a[i].first - x) > res/2) continue;
    b.push_back(a[i]);
  }
  res = min(res, Enumerate(b));
  return res;
}

double Enumerate(vector<P> & a)
{
  const int n = a.size();
  if(n <= 2) return INT_MAX;
  double d(INT_MAX);
  double c(0);

  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j)
      for(int k=j+1; k<n; ++k)
    {
      double dx = a[i].first - a[j].first;
      double dy = a[i].second - a[j].second;
      c = sqrt(dx*dx + dy*dy);

      dx = a[i].first - a[k].first;
      dy = a[i].second - a[k].second;
      c += sqrt(dx*dx + dy*dy);

      dx = a[j].first - a[k].first;
      dy = a[j].second - a[k].second;
      c += sqrt(dx*dx + dy*dy);

      d = min(d, c);
    }

  return d;
}

int main(void)
{
  const int n = 1000;
  vector<P> a(n);
  srand(time(NULL));

  for(int i=0; i<n; ++i) {
    a[i] = make_pair(rand()%10000, rand()%10000);
  }
  cout << MinTriangle(&a[0], n) << " " << Enumerate(a) << endl;

  return 0;

}
