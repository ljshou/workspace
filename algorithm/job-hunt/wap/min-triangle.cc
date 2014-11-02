/**
 * @file min-triangle.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-07
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> P;

bool compare_y(const P &lhs, const P &rhs)
{
  return lhs.second < rhs.second;
}

double centimeter(const vector<P> & a, int i, int j, int k);
double Enumerate(const vector<P> & a);
double MinTriangle(P *a, int n)
{
  if(n <= 1) return INT_MAX;
  sort(a, a+n);

  int mid = n/2;
  double x = a[mid].first;
  double d = min(MinTriangle(a, mid), MinTriangle(a+mid, n-mid));

  sort(a, a+n, compare_y);
  vector<P> b;
  for(int i=0; i<n; ++i)
  {
    if(fabs(a[i].first - x) > d/2) continue; 
    b.push_back(a[i]);
  }
  d = min(d, Enumerate(b));
  return d;
}

inline double centimeter(const vector<P> & a, int i, int j, int k)
{
  assert(!a.empty());
  double d(0);
  double dx = a[i].first - a[j].first;
  double dy = a[i].second - a[j].second;
  d += sqrt(dx*dx + dy*dy);

  dx = a[i].first - a[k].first;
  dy = a[i].second - a[k].second;
  d += sqrt(dx*dx + dy*dy);

  dx = a[j].first - a[k].first;
  dy = a[j].second - a[k].second;
  d += sqrt(dx*dx + dy*dy);
  return d;
}

double Enumerate(const vector<P> & a)
{
  if(a.size() < 2) return INT_MAX;
  double d = INT_MAX;
  for(int i=0; i<a.size(); ++i)
    for(int j=i+1; j<a.size(); ++j)
      for(int k=j+1; k<a.size(); ++k)
    {
      d = min(d, centimeter(a, i, j, k));
    }

  return d;
}

int main(void)
{
  const int n = 10;
  vector<P> a(n);
  srand(time(NULL));

  for(int i=0; i<n; ++i) {
    a[i] = make_pair(rand()%10000, rand()%10000);
  }
  clock_t start = clock();
  cout << MinTriangle(&a[0], n) << endl; 
  clock_t end = clock();
  cout << "clocks: " << end - start << endl;

  start = clock();
  cout << Enumerate(a) << endl;
  end = clock();
  cout << "clocks: " << end - start << endl;

  return 0;
}
