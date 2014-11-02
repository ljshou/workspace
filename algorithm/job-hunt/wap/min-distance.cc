/**
 * @file min-distance.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-06-06
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> P;

bool compare_y(P p1, P p2)
{
  return p1.second < p2.second;
}

double MinDistance(P *a, int n)
{
  if(n <= 1) return INT_MAX;
  int mid = n / 2;
  double x = a[mid].first;
  double d = min(MinDistance(a, mid), MinDistance(a+mid, n-mid));

  sort(a, a+n, compare_y);
  vector<P> b;
  for(int i=0; i<n; ++i)
  {
    if(abs(a[i].first - x) > d) continue;
    for(int j=b.size()-1; j>=0; --j)
    {
      double dx = a[i].first - b[j].first;
      double dy = a[i].second - b[j].second;
      if(dy >= d) break;
      d  = min(d, sqrt(dx*dx+dy*dy));
    }
    b.push_back(a[i]);
  }
  return d;
}

double Enumerate(P *a, int n)
{
  if(n <= 1) return INT_MAX;
  double d(INT_MAX);
  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j)
    {
      double dx = a[i].first - a[j].first;
      double dy = a[i].second - a[j].second;
      d = min(d, sqrt(dx*dx + dy*dy));
    }
  return d;
}

int main(void)
{
  const int n = 10;
  P points[n];

  srand(time(NULL));
  for(int i=0; i<n; ++i)
    points[i] = make_pair(rand()%100, rand()%100);

  sort(points, points+n);
  cout << MinDistance(points, n) << endl;
  cout << Enumerate(points, n) << endl;
  return 0;
}
