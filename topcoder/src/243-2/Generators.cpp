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


class Generators
{
        public:
        vector <int> find(int p)
        {
            vector<int> res;
            int hash[1000] = {0};

            for(int i=2; i<p; ++i) {
                fill_n(hash, 1000, 0);
                for(int j=1; j<p; ++j) hash[j] = 1;
                int a = 1;
                ++hash[1];
                bool flag = true;
                For(j, p-2) {
                    a = (a * i) % p;
                    ++hash[a];
                    if(hash[a] != 2) {
                        flag = false;
                        break;
                    }
                }
                if(flag) res.push_back(i);
            }

            return res;
        }
        
// BEGIN CUT HERE
//j	public:
//j	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//j	private:
//j	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//j	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
//j	void test_case_0() { int Arg0 = 3; int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, find(Arg0)); }
//j	void test_case_1() { int Arg0 = 5; int Arr1[] = {2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, find(Arg0)); }
//j	void test_case_2() { int Arg0 = 13; int Arr1[] = {2, 6, 7, 11 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, find(Arg0)); }
//j	void test_case_3() { int Arg0 = 19; int Arr1[] = {2, 3, 10, 13, 14, 15 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, find(Arg0)); }
//j	void test_case_4() { int Arg0 = 337; int Arr1[] = {10, 15, 19, 20, 22, 23, 29, 31, 33, 34, 44, 45, 46, 51, 53, 60, 61, 67, 68, 70, 71, 73, 80, 83, 87, 89, 90, 93, 99, 101, 106, 109, 114, 116, 118, 120, 124, 130, 132, 134, 139, 143, 151, 152, 154, 160, 161, 166, 171, 176, 177, 183, 185, 186, 194, 198, 203, 205, 207, 213, 217, 219, 221, 223, 228, 231, 236, 238, 244, 247, 248, 250, 254, 257, 264, 266, 267, 269, 270, 276, 277, 284, 286, 291, 292, 293, 303, 304, 306, 308, 314, 315, 317, 318, 322, 327 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        Generators ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
