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


class SyllableCounter
{
        public:
        int countSyllables(string word)
        {
            bool flag[256] = {false};
            flag['A'] = flag['E'] = flag['I'] = flag['O'] = flag['U'] = true; 
            int count = 0;
            For(i, word.size()) {
                if(flag[word[i]]) {
                    if(i == 0 || (i && !flag[word[i-1]])) ++count;
                }
            }
            return count;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arg0 = "VOLUME"; int Arg1 = 3; verify_case(0, Arg1, countSyllables(Arg0)); }
//	void test_case_1() { string Arg0 = "TELEVISION"; int Arg1 = 4; verify_case(1, Arg1, countSyllables(Arg0)); }
//	void test_case_2() { string Arg0 = "BOOKKEEEEEEEEEEEEPER"; int Arg1 = 3; verify_case(2, Arg1, countSyllables(Arg0)); }
//	void test_case_3() { string Arg0 = "SLKJSGLKAKHDGHELHDGILKLHDGOLOOOOOL"; int Arg1 = 5; verify_case(3, Arg1, countSyllables(Arg0)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        SyllableCounter ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
