/**
 * @file convex-hull.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-10
 */

#include <bits/stdc++.h>
using namespace std;

struct point
{
  point(double x0=0, double x1=0): x(x0), y(x1) {}
  double x, y;
};
point operator-(const point &lhs, const point &rhs) {
  return point(lhs.x-rhs.x, lhs.y-rhs.y);
}
double Det(const point &lhs, const point &rhs) {
  return lhs.x*rhs.y - lhs.y*rhs.x;
}
double CrossProduct(const point &p0, const point &p1, const point &p2)
{
  return Det(p1-p0, p2-p0);
}
double Distance(const point &p1, const point &p2)
{
  double x = p2.x - p1.x;
  double y = p2.y - p1.y;
  return sqrt(x*x + y*y);
}

//point with the minimum y coordinate
point p0;

bool compare_y(const point &lhs, const point &rhs) 
{
  if(lhs.y != rhs.y)
    return lhs.y < rhs.y;
  else 
    return lhs.x < rhs.x;
}

bool cmp(const point &p1, const point &p2)
{
  double cross = CrossProduct(p0, p1, p2);
  if(cross > 0) 
    return true;
  else if(abs(cross) < 1e-10 && Distance(p0, p1) < Distance(p0, p2)) 
    return true;
  else
    return false;
}

vector<point> ConvexHull(vector<point> &vec)
{
  if(vec.size() < 3) return vec;

  //find the min point with lowest y coordinates
  auto it = min_element(vec.begin(), vec.end(), compare_y);
  if(it != vec.begin()) iter_swap(it, vec.begin());
  p0 = vec[0];

  sort(vec.begin()+1, vec.end(), cmp);

  vector<point> res(vec.size());
  int top = 0;

  for(int i=0; i<vec.size(); ++i)
  {
    while(top > 2 && Det(res[top-1] - res[top-2], vec[i] - res[top-1]) <= 0)
      --top;
    res[top++] = vec[i];
  }
  res.resize(top);
  return res;
}

int main(void)
{
  int n;
  vector<point> vec;
  double x, y;
  while(cin >> n, n) {
    vec.resize(n);
    for(int i=0; i<n; ++i)
    {
      cin >> x >> y;
      vec[i].x = x;
      vec[i].y = y;
    }
    auto res = ConvexHull(vec);
    for(auto p : res)
      cout << p.x << " " << p.y << endl;
  }
  return 0;
}
