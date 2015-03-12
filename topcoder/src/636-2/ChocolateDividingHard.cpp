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


class ChocolateDividingHard
{
        public:
        int findBest(vector <string> chocolate)
        {
                $CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"95998",
"21945",
"23451",
"99798",
"74083"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
	void test_case_1() { string Arr0[] = {
"12942",
"23456",
"99798",
"98998",
"67675"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, findBest(Arg0)); }
	void test_case_2() { string Arr0[] = {
"129420",
"234560",
"997980",
"989980",
"676760"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, findBest(Arg0)); }
	void test_case_3() { string Arr0[] = {"75356291270936062","61879202375922897","36129319478450361","06320615547656937","45254744307868843","14920689266495048","71727226106159490","91771159776736563","94812939088509638","56115984810304444","76317596217857418","59753883189643338"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(3, Arg1, findBest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ChocolateDividingHard ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
