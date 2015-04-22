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

bool IsSpecial(string s)
{
    for(int i=1; i<s.size(); ++i) {
        if(s.substr(0, i) >= s.substr(i))
            return false;
    }
    return true;
}

class SpecialStrings
{
        public:
        string findNext(string current)
        {
            if(current == "0") return "1"; 
            for(int i=current.size()-1; i>=0; --i) {
                if(current[i] == '1') continue;
                if(i == 0) return "";
                current[i] = '1';
                for(int j=i+1; j<current.size(); ++j) {
                    current[j] = '0';
                    if(!IsSpecial(current)) current[j] = '1';
                }
                return current;
            }
            return "";
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arg0 = "01"; string Arg1 = ""; verify_case(0, Arg1, findNext(Arg0)); }
//	void test_case_1() { string Arg0 = "00101"; string Arg1 = "00111"; verify_case(1, Arg1, findNext(Arg0)); }
//	void test_case_2() { string Arg0 = "0010111"; string Arg1 = "0011011"; verify_case(2, Arg1, findNext(Arg0)); }
//	void test_case_3() { string Arg0 = "000010001001011"; string Arg1 = "000010001001101"; verify_case(3, Arg1, findNext(Arg0)); }
//	void test_case_4() { string Arg0 = "01101111011110111"; string Arg1 = "01101111011111111"; verify_case(4, Arg1, findNext(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        SpecialStrings ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
