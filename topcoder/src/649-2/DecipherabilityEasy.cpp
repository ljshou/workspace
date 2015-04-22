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


class DecipherabilityEasy
{
        public:
        string check(string s, string t)
        {
            if(s.size() != t.size() + 1) return "Impossible";
            const int m = s.size(), n = t.size();
            int i(0), j(0);
            bool flag = false;
            for(; j<n; ++j, ++i) {
                if(s[i] != t[j]) {
                    if(flag) return "Impossible";
                    flag = true;
                    --j;
                } 
            }
            return "Possible";
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arg0 = "sunuke"; string Arg1 = "snuke"; string Arg2 = "Possible"; verify_case(0, Arg2, check(Arg0, Arg1)); }
//	void test_case_1() { string Arg0 = "snuke"; string Arg1 = "skue"; string Arg2 = "Impossible"; verify_case(1, Arg2, check(Arg0, Arg1)); }
//	void test_case_2() { string Arg0 = "snuke"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(2, Arg2, check(Arg0, Arg1)); }
//	void test_case_3() { string Arg0 = "snukent"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(3, Arg2, check(Arg0, Arg1)); }
//	void test_case_4() { string Arg0 = "aaaaa"; string Arg1 = "aaaa"; string Arg2 = "Possible"; verify_case(4, Arg2, check(Arg0, Arg1)); }
//	void test_case_5() { string Arg0 = "aaaaa"; string Arg1 = "aaa"; string Arg2 = "Impossible"; verify_case(5, Arg2, check(Arg0, Arg1)); }
//	void test_case_6() { string Arg0 = "topcoder"; string Arg1 = "tpcoder"; string Arg2 = "Possible"; verify_case(6, Arg2, check(Arg0, Arg1)); }
//	void test_case_7() { string Arg0 = "singleroundmatch"; string Arg1 = "singeroundmatc"; string Arg2 = "Impossible"; verify_case(7, Arg2, check(Arg0, Arg1)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        DecipherabilityEasy ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
