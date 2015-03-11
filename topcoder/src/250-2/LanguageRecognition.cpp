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

bool IsLetter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

double Error(string lhs, string rhs)
{
    int freq[2][26] = {0};
    int cnt[2] = {0};
    for(auto c : lhs) {
        if(IsLetter(c)) {
            c = tolower(c);
            ++freq[0][c-'a'];
            ++cnt[0];
        }
    }
    for(auto c : rhs) {
        if(IsLetter(c)) {
            c = tolower(c);
            ++freq[1][c-'a'];
            ++cnt[1];
        }
    }
    double res = 0;
    For(i, 26) {
        double x = (double)freq[0][i]/cnt[0] - (double)freq[1][i]/cnt[1];
        res += x*x;
    }
    return res;
}

class LanguageRecognition
{
        public:
        int whichLanguage(vector <string> languages, string text)
        {
            double error = 0xffff;
            int index = 0;
            For(i, languages.size()) {
                double tmp = Error(languages[i], text);
                if(fabs(tmp - error) < 1e-10) continue;
                if(tmp < error) {
                    error = tmp;
                    index = i;
                }
            }
            return index;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = {"This is an English sentence.",
// "Dieser ist ein Deutscher Satz.",
// "C'est une phrase Francaise.",
// "Dit is een Nederlandse zin."
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "In welke taal is deze zin geschreven?"; int Arg2 = 3; verify_case(0, Arg2, whichLanguage(Arg0, Arg1)); }
//	void test_case_1() { string Arr0[] = {"aaaaa","bbbb","ccc","dd","e"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "xxx"; int Arg2 = 0; verify_case(1, Arg2, whichLanguage(Arg0, Arg1)); }
//	void test_case_2() { string Arr0[] = {"AABB","AaBb","A? B!","ab!@#$%"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ab"; int Arg2 = 0; verify_case(2, Arg2, whichLanguage(Arg0, Arg1)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        LanguageRecognition ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
