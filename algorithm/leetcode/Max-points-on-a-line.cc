/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty()) return 0;
        unordered_map<double, int> count; //<tangent, count>
        int sameCnt(0), verticalCnt(0);
        int res(0);
        for(auto p1 : points) {
            count.clear();
            sameCnt = verticalCnt = 0;
            
            for(auto p2 : points) {
                if(abs(p1.x - p2.x) < 1e-10) {
                    if(abs(p1.y - p2.y) < 1e-10) ++sameCnt;
                    else {
                        ++verticalCnt;
                    }
                }
                else {
                    double tang = static_cast<double>(p2.y - p1.y) / (p2.x - p1.x);
                    ++count[tang];
                }
            }
            for(auto x : count) {
                res = max(res, x.second + sameCnt);
            }
            res = max(res, verticalCnt + sameCnt);
        }
        return res;
    }
};
