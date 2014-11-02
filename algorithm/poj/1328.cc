/**
 * @file 1328.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-29
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define For(i, n) for(int i=0; i<(n); ++i)

typedef pair<double, double> point;
point vec[1000];
int n, d;
int index = 0;

bool compare(const point &lhs, const point &rhs)
{
  //以岛屿为圆心，d为半径画圆，右边的交点
  return lhs.second < rhs.second;
}

int Solve() 
{
  int count = 0;
  point cur = vec[0];
  ++count;
  For(i, n) {
	if(vec[i].first - cur.second > 1e-10) {
	  cur = vec[i];
	  ++count;
	}
  }
  return count;
}

int main(void)
{
  bool flag = false;
  int x, y;
  double offset;
  while((cin >> n >> d) && (n || d)) {
	flag = false; //clear previous status
	++ index;
	For(i, n) {
	  cin >> x >> y;
	  if(y > d) {
		flag = true;
	  }
	  offset = sqrt(d*d - y*y);
	  vec[i].first  = x - offset;
	  vec[i].second = x + offset;
	}
	if(flag) {
	  cout << "Case " << index << ": " << -1 << endl;
	}
	else {
	  sort(vec, vec+n, compare);
	  cout << "Case " << index << ": " << Solve() << endl;
	}
  }
  return 0;
}
