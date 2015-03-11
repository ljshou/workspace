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

int gcd(int x, int y)
{
    if(x == 0) return y;
    return gcd(y%x, x);
}

class FracCount
{
        public:
        int position(int numerator, int denominator)
        {
            int count = 0;
            for(int i=2; i<denominator; ++i) {
                for(int j=1; j<i; ++j) {
                    if(gcd(i, j) == 1) ++count;
                }
            }
            for(int j=1; j<=numerator; ++j)
                if(gcd(j, denominator) == 1) ++count;
            return count;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, position(Arg0, Arg1)); }
//	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 11; verify_case(1, Arg2, position(Arg0, Arg1)); }
//	void test_case_2() { int Arg0 = 999; int Arg1 = 1000; int Arg2 = 304191; verify_case(2, Arg2, position(Arg0, Arg1)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        FracCount ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
