#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <climits>
#include <bitset>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

struct Rect {
    Rect(int x0_, int y0_, int x1_, int y1_):
        x0(x0_), y0(y0_), x1(x1_), y1(y1_) {
            if(x0 > x1 || y0 > y1)
                x0 = x1 = y0 = y1 = 0;
    }
    int area() const {
        return (x1 - x0) * (y1 - y0);
    }
    
    int x0, y0, x1, y1;
};

Rect Intersect(const Rect &a, const Rect &b)
{
    return Rect(max(a.x0,b.x0), max(a.y0,b.y0), 
                min(a.x1,b.x1), min(a.y1,b.y1));
}


class BoxUnion
{
        public:
        int area(vector <string> rectangles)
        {
            int res = 0, x0, x1, y0, y1;
            const int n = rectangles.size();
            vector<Rect> vec;
            For(i, n) {
                sscanf(rectangles[i].c_str(), "%d%d%d%d", &x0, &y0, &x1, &y1);
                vec.push_back(Rect(x0, y0, x1, y1));
                res += vec.back().area();
            }
            for(int i=0; i<n; ++i) 
                for(int j=i+1; j<n; ++j)
                    res -= Intersect(vec[i], vec[j]).area();
            for(int i=0; i<n; ++i) 
                for(int j=i+1; j<n; ++j)
                    for(int k=j+1; k<n; ++k)
                        res += Intersect(Intersect(vec[i], vec[j]), vec[k]).area();
            return res;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = { "200 300 203 304" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, area(Arg0)); }
//	void test_case_1() { string Arr0[] = { "0 0 10 10",
//  "20 20 30 30" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 200; verify_case(1, Arg1, area(Arg0)); }
//	void test_case_2() { string Arr0[] = { "0 500 20000 501",
//  "500 0 501 20000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39999; verify_case(2, Arg1, area(Arg0)); }
//	void test_case_3() { string Arr0[] = { "4 6 18 24",
//  "7 2 12 19",
//  "0 0 100 100" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10000; verify_case(3, Arg1, area(Arg0)); }
//	void test_case_4() { string Arr0[] = { "1 3 5 6",
//  "3 1 7 5",
//  "4 4 9 7" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 35; verify_case(4, Arg1, area(Arg0)); }
//	void test_case_5() { string Arr0[] = { "0 0 20000 20000",
//  "0 0 20000 20000",
//  "0 0 20000 20000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 400000000; verify_case(5, Arg1, area(Arg0)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        BoxUnion ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
