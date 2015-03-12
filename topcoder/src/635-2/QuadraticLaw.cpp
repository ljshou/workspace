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


class QuadraticLaw
{
        public:
        long long getTime(long long d)
        {
            LL left(1), right(d);
            LL mid(0), res(0);
            while(left <= right) {
                mid = left + (right-left)/2;
                if(mid+1 <= d/mid) {
                    res = max(res, mid);
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }
            return res;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 0LL; verify_case(0, Arg1, getTime(Arg0)); }
//	void test_case_1() { long long Arg0 = 2LL; long long Arg1 = 1LL; verify_case(1, Arg1, getTime(Arg0)); }
//	void test_case_2() { long long Arg0 = 5LL; long long Arg1 = 1LL; verify_case(2, Arg1, getTime(Arg0)); }
//	void test_case_3() { long long Arg0 = 6LL; long long Arg1 = 2LL; verify_case(3, Arg1, getTime(Arg0)); }
//	void test_case_4() { long long Arg0 = 7LL; long long Arg1 = 2LL; verify_case(4, Arg1, getTime(Arg0)); }
//	void test_case_5() { long long Arg0 = 1482LL; long long Arg1 = 38LL; verify_case(5, Arg1, getTime(Arg0)); }
//	void test_case_6() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 999999999LL; verify_case(6, Arg1, getTime(Arg0)); }
//	void test_case_7() { long long Arg0 = 31958809614643170LL; long long Arg1 = 178770270LL; verify_case(7, Arg1, getTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        QuadraticLaw ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
