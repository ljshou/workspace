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


class ComputationalComplexity
{
        public:
        int fastestAlgo(vector <int> constant, vector <int> power, vector <int> logPower, int N)
        {
            auto cmplex = [&](const int i) {
                return constant[i] * pow(N, power[i]) * pow(log(N), logPower[i]); 
            };
            auto cmp = [&](int i, int j) {
                return cmplex(i) < cmplex(j);
            };
            int index = 0;
            For(i, constant.size()) {
                if(cmp(i, index)) index = i;
            }
            return index;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arr0[] = {5, 50, 45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 400; int Arg4 = 2; verify_case(0, Arg4, fastestAlgo(Arg0, Arg1, Arg2, Arg3)); }
//	void test_case_1() { int Arr0[] = {5, 50, 45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; int Arg4 = 0; verify_case(1, Arg4, fastestAlgo(Arg0, Arg1, Arg2, Arg3)); }
//	void test_case_2() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000; int Arg4 = 0; verify_case(2, Arg4, fastestAlgo(Arg0, Arg1, Arg2, Arg3)); }
//	void test_case_3() { int Arr0[] = {32, 33, 58, 93, 8, 27, 43, 69, 95, 77,
// 57, 73, 87, 87, 50, 92, 67, 20, 2, 46,
// 73, 48, 25, 90, 48, 18, 28, 26, 20, 33,
// 59, 48, 69, 4, 19, 13, 10, 78, 55, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 0, 1, 4, 0, 3, 5, 4, 3, 3,
// 0, 5, 0, 5, 5, 3, 0, 4, 1, 1,
// 4, 0, 2, 4, 0, 0, 3, 2, 0, 0,
// 4, 3, 5, 0, 2, 4, 3, 4, 3, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 2, 0, 4, 5, 2, 3, 4, 5,
// 0, 0, 1, 4, 2, 5, 2, 4, 5, 0,
// 5, 4, 3, 0, 4, 1, 1, 3, 3, 0,
// 1, 5, 2, 1, 1, 4, 0, 0, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000; int Arg4 = 33; verify_case(3, Arg4, fastestAlgo(Arg0, Arg1, Arg2, Arg3)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//jint main()
//j{
//j        ComputationalComplexity ___test;
//j        ___test.run_test(-1);
//j        return 0;
//j}
// END CUT HERE
