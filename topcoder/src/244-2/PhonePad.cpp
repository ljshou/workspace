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


class PhonePad
{
        public:
        int fingerMovement(string phoneNumber)
        {
            int layout[10][2] = {{3,1},
                                 {0,0},{0,1},{0,2},
                                 {1,0},{1,1},{1,2},
                                 {2,0},{2,1},{2,2}};
            int prev = 5, dist = 0;
            for(auto c : phoneNumber) {
                int x = c - '0';
                dist += abs(layout[x][0] - layout[prev][0]);
                dist += abs(layout[x][1] - layout[prev][1]);
                prev = x;
            }
            return dist;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arg0 = "911"; int Arg1 = 6; verify_case(0, Arg1, fingerMovement(Arg0)); }
//	void test_case_1() { string Arg0 = "5555555"; int Arg1 = 0; verify_case(1, Arg1, fingerMovement(Arg0)); }
//	void test_case_2() { string Arg0 = "8606335540"; int Arg1 = 16; verify_case(2, Arg1, fingerMovement(Arg0)); }
//	void test_case_3() { string Arg0 = "8606574276"; int Arg1 = 21; verify_case(3, Arg1, fingerMovement(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        PhonePad ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
