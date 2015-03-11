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

int Fact(int n)
{
    if(n == 0) return 1;
    int res = 1;
    for(int i=2; i<=n; ++i)
        res *= i;
    return res;
}

class ColorfulBricks
{
        public:
        int countLayouts(string bricks)
        {
            sort(bricks.begin(), bricks.end());
            bricks.erase(unique(bricks.begin(), bricks.end()), bricks.end());
            int n = bricks.size();
            if(n > 2) return 0;
            return Fact(n);
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arg0 = "ABAB"; int Arg1 = 2; verify_case(0, Arg1, countLayouts(Arg0)); }
//	void test_case_1() { string Arg0 = "AAA"; int Arg1 = 1; verify_case(1, Arg1, countLayouts(Arg0)); }
//	void test_case_2() { string Arg0 = "WXYZ"; int Arg1 = 0; verify_case(2, Arg1, countLayouts(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        ColorfulBricks ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
