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


class IdentifyingWood
{
        public:
        string check(string s, string t)
        {
            const int m = s.size(), n = t.size();
            if(n > m) return "Nope.";
            int f[11][11] = {0};
            for(int i=1; i<=m; ++i) {
                for(int j=1; j<=n; ++j) {
                    if(s[i-1] == t[j-1]) f[i][j] = f[i-1][j-1] + 1;
                    else f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
            }
            if(f[m][n] == n) return "Yep, it's wood.";
            else return "Nope.";
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arg0 = "absdefgh"; string Arg1 = "asdf"; string Arg2 = "Yep, it's wood."; verify_case(0, Arg2, check(Arg0, Arg1)); }
//	void test_case_1() { string Arg0 = "oxoxoxox"; string Arg1 = "ooxxoo"; string Arg2 = "Nope."; verify_case(1, Arg2, check(Arg0, Arg1)); }
//	void test_case_2() { string Arg0 = "oxoxoxox"; string Arg1 = "xxx"; string Arg2 = "Yep, it's wood."; verify_case(2, Arg2, check(Arg0, Arg1)); }
//	void test_case_3() { string Arg0 = "qwerty"; string Arg1 = "qwerty"; string Arg2 = "Yep, it's wood."; verify_case(3, Arg2, check(Arg0, Arg1)); }
//	void test_case_4() { string Arg0 = "string"; string Arg1 = "longstring"; string Arg2 = "Nope."; verify_case(4, Arg2, check(Arg0, Arg1)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        IdentifyingWood ___test;
//        ___test.run_test(-1);
//        return 0;
//}
//// END CUT HERE
