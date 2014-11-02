/**
 * @file convex-hull.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-10
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

struct point
{
  point(int x0=0, int x1=0): x(x0), y(x1) {}
  int x, y;
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
  int x = p2.x - p1.x;
  int y = p2.y - p1.y;
  return sqrt((double)x*x + y*y);
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
  else if(abs(cross) < 1e-15 && Distance(p0, p1) < Distance(p0, p2)) 
    return true;
  else
    return false;
}

vector<point> res;
void ConvexHull(vector<point> &vec)
{
  if(vec.size() < 3) res = vec;

  //find the min point with lowest y coordinates
  vector<point>::iterator it = min_element(vec.begin(), vec.end(), compare_y);
  if(it != vec.begin()) iter_swap(it, vec.begin());
  p0 = vec[0];

  sort(vec.begin()+1, vec.end(), cmp);

  res.resize(vec.size());
  int top = 0;

  for(int i=0; i<vec.size(); ++i)
  {
    while(top > 2 && Det(res[top-1] - res[top-2], vec[i] - res[top-1]) <= 0)
      --top;
    res[top++] = vec[i];
  }
  res.resize(top);
  for(int i=0; i<top; ++i)
    cout << res[i].x << " " << res[i].y << endl;
}

double solve(vector<point> &vec) 
{
  ConvexHull(vec);
  int n = res.size();
  if(n < 2) {
    return 0;
  }
  if(n == 2) {
    return Distance(res[0], res[1]);
  }
  double len(0);
  for(int i=1; i<n; ++i)
    len += Distance(res[i], res[i-1]);
  len += Distance(res[0], res[n-1]);
  return len;
}

int main(void)
{
  int n;
  vector<point> vec;
  int x, y;
  while(cin >> n && n != 0) {
    vec.resize(n);
    for(int i=0; i<n; ++i)
    {
      cin >> x >> y;
      vec[i].x = x;
      vec[i].y = y;
    }
    printf("%.2lf\n", solve(vec));
  }
  return 0;
}
