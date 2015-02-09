/**
 * @file min-distance.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-20
 */
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int x_=0, int y_=0):
        x(x_), y(y_) {}
};

double distance(const Point &lhs, const Point &rhs)
{
    double x= lhs.x - rhs.x;
    double y= lhs.y - rhs.y;
    return sqrt(x*x + y*y);
}

double MinDistance(vector<Point> &points)
{
    const int n = points.size();
    if(n == 0) return 0.0;

    vector<vector<double> > f(n, vector<double>(n, 0.0));
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            if(j-i > 1) {
                f[i][j] = f[i][j-1] + distance(points[j-1], points[j]);
            }
            else {
                f[i][j] = f[0][i] + distance(points[0], points[j]); 
                for(int k=1; k<i; ++k)
                    f[i][j] = min(f[i][j], f[k][i] + distance(points[k], points[j]));
            }
        }
    }
    return f[n-1][n-1];
}

void Test()
{
    vector<Point> points{{0, 0}, {30, 40}, {31, 0}};
    cout << MinDistance(points) << endl;
}

int main(void)
{
    Test();
    return 0;
}
