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

bool IsVowel(char c)
{
    c = tolower(c);
    return c == 'a' 
        || c == 'e'
        || c == 'i'
        || c == 'o'
        || c == 'u';
}

class SMS
{
        public:
        string compress(string originalMessage)
        {
            string res;
            bool left = false, right = false;
            For(i, originalMessage.size()) {
                char c = originalMessage[i];    
                if(c == ' ') {
                    left = false;
                    res.push_back(c);
                }
                else if(IsVowel(c)) {
                    if(!left) res.push_back(c);
                    else {
                        right = false;
                        for(int j=i+1; j<originalMessage.size() && originalMessage[j] != ' '; ++j)
                            if(!IsVowel(originalMessage[j])) {
                               right = true; break;
                            }
                        if(!right) res.push_back(c);
                    }
                }
                else {
                    left = true;
                    res.push_back(c);
                }
            }
            return res;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arg0 = "Lets meet tomorrow"; string Arg1 = "Lts mt tmrrw"; verify_case(0, Arg1, compress(Arg0)); }
//	void test_case_1() { string Arg0 = "Please come to my party"; string Arg1 = "Plse cme to my prty"; verify_case(1, Arg1, compress(Arg0)); }
//	void test_case_2() { string Arg0 = " I  like your   style "; string Arg1 = " I  lke yr   style "; verify_case(2, Arg1, compress(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        SMS ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
