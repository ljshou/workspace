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
#include <unordered_set>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

class NumberGameAgain
{
        public:
        long long solve(int k, vector<long long> table)
        {
            sort(table.begin(), table.end());

            set<LL> hash;
            int len = 0;
            LL count = 0;
            bool flag = true;
            for(auto x : table) {
                len = 0;
                flag = true;
                for(LL i=x; i>1; i/=2, ++len) {
                    if(hash.find(i) != hash.end()) {
                        flag = false;
                        break;
                    }
                }
                if(flag) count += ((LL)1<<(k-len)) - 1;
                hash.insert(x);
            }
            return ((LL)1<<k)-2 - count;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arg0 = 3; long Arr1[] = {2,4,6}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, solve(Arg0, Arg1)); }
//	void test_case_1() { int Arg0 = 5; long Arr1[] = {2,3}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, solve(Arg0, Arg1)); }
//	void test_case_2() { int Arg0 = 5; long Arr1[] = {}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 30LL; verify_case(2, Arg2, solve(Arg0, Arg1)); }
//	void test_case_3() { int Arg0 = 40; long Arr1[] = {2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 549755748288LL; verify_case(3, Arg2, solve(Arg0, Arg1)); }
//	void test_case_4() { int Arg0 = 40; long Arr1[] = {}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1099511627774LL; verify_case(4, Arg2, solve(Arg0, Arg1)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        NumberGameAgain ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
