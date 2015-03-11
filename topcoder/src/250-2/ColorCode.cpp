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


class ColorCode
{
        public:
        long long getOhms(vector <string> code)
        {
            map<string, pair<int, long long> > hash;
                hash["black"] =   make_pair(0,             1);
                hash["brown"] =   make_pair(1,            10);
                hash["red"] =     make_pair(2,           100);
                hash["orange"] =  make_pair(3,         1000);
                hash["yellow"] =  make_pair(4,        10000);
                hash["green"] =   make_pair(5,       100000);
                hash["blue"] =    make_pair(6,     1000000);
                hash["violet"] =  make_pair(7,    10000000);
                hash["grey"] =    make_pair(8,   100000000);
                hash["white"] =   make_pair(9, 1000000000);

                int x = hash[code[0]].first, y = hash[code[1]].first;
                long long mul = hash[code[2]].second;
                return (10*x+y)*mul;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = { "yellow", "violet", "red" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4700LL; verify_case(0, Arg1, getOhms(Arg0)); }
//	void test_case_1() { string Arr0[] = { "orange", "red", "blue" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 32000000LL; verify_case(1, Arg1, getOhms(Arg0)); }
//	void test_case_2() { string Arr0[] = { "white", "white", "white" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 99000000000LL; verify_case(2, Arg1, getOhms(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        ColorCode ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
