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


class Elections
{
        public:
        int visit(vector <string> likelihoods)
        {
            double res = 1; 
            double index = 0;
            For(i, likelihoods.size()) {
                double tmp = 0;
                for(auto c : likelihoods[i]) {
                    if(c == '1') ++ tmp; 
                }
                tmp /= likelihoods[i].size();
                if(tmp < res-1e-10) {
                    res = tmp;
                    index = i;
                }
            }
            return index;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = {"1222","1122","1222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, visit(Arg0)); }
//	void test_case_1() { string Arr0[] = {"1222111122","2222222111","11111222221222222222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, visit(Arg0)); }
//	void test_case_2() { string Arr0[] = {"111","112","121","122","211","212","221","222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(2, Arg1, visit(Arg0)); }
//	void test_case_3() { string Arr0[] = {"1122","1221","1212","2112","2121","2211"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, visit(Arg0)); }
//	void test_case_4() { string Arr0[] = {"11112222111121","1211221212121","112111222","11122222222111","112121222","1212122211112"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, visit(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        Elections ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
