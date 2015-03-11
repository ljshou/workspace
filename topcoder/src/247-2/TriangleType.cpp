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
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


class TriangleType
{
        public:
        string type(int a, int b, int c)
        {
            if(a > b) swap(a, b);
            if(a > c) swap(a, c);
            if(b > c) swap(b, c);
            // a <= b <= c
            if(a + b <= c) return "IMPOSSIBLE";
            int s = a*a + b*b;
            if(s == c*c) return "RIGHT";
            else if(s < c*c) return "OBTUSE";
            else return "ACUTE";
        }
        
// BEGIN CUT HERE
	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 5; string Arg3 = "RIGHT"; verify_case(0, Arg3, type(Arg0, Arg1, Arg2)); }
//	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 4; string Arg3 = "ACUTE"; verify_case(1, Arg3, type(Arg0, Arg1, Arg2)); }
//	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 6; string Arg3 = "OBTUSE"; verify_case(2, Arg3, type(Arg0, Arg1, Arg2)); }
//	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 3; string Arg3 = "IMPOSSIBLE"; verify_case(3, Arg3, type(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        TriangleType ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
