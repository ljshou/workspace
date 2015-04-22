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
    return c == 'a' 
        || c == 'e'
        || c == 'i'
        || c == 'o'
        || c == 'u';
}

bool Pronounce(const string &str)
{
    bool Hash[256] = {false};
    int v_count = 0, c_count = 0;

    For(i, str.size()) {
        char c = tolower(str[i]);
        if(IsVowel(c)) {
           c_count = 0;
           if(Hash[c] == false) ++v_count;
           Hash[c] = true;
           if(v_count >= 2) return false;
        }
        else {
            fill_n(Hash, 256, false);
            v_count = 0;
            if(++c_count >= 3) 
                return false;
        }
    }
    return true;
}

class Pronunciation
{
        public:
        string canPronounce(vector <string> words)
        {
            For(i, words.size()) {
                if(Pronounce(words[i]) == false) 
                    return words[i];
            }
            return "";
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = {"All","of","these","are","not","difficult"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(0, Arg1, canPronounce(Arg0)); }
//	void test_case_1() { string Arr0[] = {"The","word","REALLY","is","really","hard"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "REALLY"; verify_case(1, Arg1, canPronounce(Arg0)); }
//	void test_case_2() { string Arr0[] = {"TRiCKy"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "TRiCKy"; verify_case(2, Arg1, canPronounce(Arg0)); }
//	void test_case_3() { string Arr0[] = {"irresistable","prerogative","uttermost","importance"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(3, Arg1, canPronounce(Arg0)); }
//	void test_case_4() { string Arr0[] = {"Aa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(4, Arg1, canPronounce(Arg0)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        Pronunciation ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
