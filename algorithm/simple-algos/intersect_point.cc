/**
 * @file intersect_point.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-16
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = 3.14159126;

/**
 * points on a circle
 */
struct Point{
  friend ostream& operator<<(ostream& out, const Point &p) {
    cout << p.x << " " << p.y;
  }
  Point(double theta=0) : theta(0) {
    x = cos(theta / 180 * PI);
    y = sin(theta / 180 * PI);
    if(theta > 90 && theta < 270) x = -x;
    if(theta > 180 && theta < 360) y = -y;
  }
  Point(double x_, double y_)
    : x(x_), y(y_) {
      compute_theta();
    }
  void compute_theta();

  double x, y;
  double theta;
};

/* theta belongs to [0, 360) */
void Point::compute_theta() 
{
  if(x != 0) {
    /* convert PI to 180 */
    theta = atan(y/x) * 180 / PI;
    if(x > 0) {
      theta += (y >= 0) ? 0 : 360;
    }
    else {
      theta += 180; 
    }
  }
  else {
    theta = (y > 0) ? 90 : 270;
  }
}

/**
 * 比较点在极坐标系中的角度的大小
 */
bool compare(const Point &lhs, const Point &rhs)
{
  return lhs.theta < rhs.theta;
}

struct Segment
{
  friend ostream& operator<<(ostream& out, const Segment &s) {
    out << "begin: " << s.begin << " end: " << s.end;
  }
  Segment(const Point begin_=Point(), const Point end_=Point())
    : begin(begin_), end(end_) {
  }

  Point begin, end;
};

bool compare_seg(const Segment &lhs, const Segment &rhs)
{
  return compare(lhs.begin, rhs.begin);
}

int IntersectedPoints(vector<Segment> &lines)
{
  int num(0);
  // sort by begin point's theta
  sort(lines.begin(), lines.end(), compare_seg);
  copy(lines.begin(), lines.end(), ostream_iterator<Segment>(cout, " "));
  cout << endl;

  for(int i=0; i<lines.size(); ++i)
  {
    for(int j=i+1; j<lines.size(); ++j)
    {
      if(lines[j].begin.theta <= lines[i].end.theta)
        ++ num;
    }
  }
  return num;
}

int main(void)
{
  vector<Segment> lines;

  lines.push_back(Segment(Point(0, -1), Point(0, 1)));
  lines.push_back(Segment(Point(-1, 0), Point(1, 0)));

  cout << IntersectedPoints(lines) << endl;

  return 0;
}
