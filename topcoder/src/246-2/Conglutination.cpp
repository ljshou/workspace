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


class Conglutination
{
        public:
        string split(string conglutination, int expectation)
        {
            const int n = conglutination.size();
            for(int i=1; i<n; ++i) {
                string A = conglutination.substr(0, i);
                string B = conglutination.substr(i);
                if(atol(A.c_str()) + atol(B.c_str()) == expectation) return A + "+" + B;
            }
            return "";
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arg0 = "22"; int Arg1 = 4; string Arg2 = "2+2"; verify_case(0, Arg2, split(Arg0, Arg1)); }
//	void test_case_1() { string Arg0 = "536"; int Arg1 = 41; string Arg2 = "5+36"; verify_case(1, Arg2, split(Arg0, Arg1)); }
//	void test_case_2() { string Arg0 = "123456000789"; int Arg1 = 1235349; string Arg2 = "1234560+00789"; verify_case(2, Arg2, split(Arg0, Arg1)); }
//	void test_case_3() { string Arg0 = "123456789"; int Arg1 = 4245; string Arg2 = ""; verify_case(3, Arg2, split(Arg0, Arg1)); }
//	void test_case_4() { string Arg0 = "112"; int Arg1 = 13; string Arg2 = "1+12"; verify_case(4, Arg2, split(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        Conglutination ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
