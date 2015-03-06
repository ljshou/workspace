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


class DifferentStrings
{
        public:
        int minimize(string A, string B)
        {
                $CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "koder"; string Arg1 = "topcoder"; int Arg2 = 1; verify_case(0, Arg2, minimize(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "hello"; string Arg1 = "xello"; int Arg2 = 1; verify_case(1, Arg2, minimize(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abc"; string Arg1 = "topabcoder"; int Arg2 = 0; verify_case(2, Arg2, minimize(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "adaabc"; string Arg1 = "aababbc"; int Arg2 = 2; verify_case(3, Arg2, minimize(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "giorgi"; string Arg1 = "igroig"; int Arg2 = 6; verify_case(4, Arg2, minimize(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        DifferentStrings ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
