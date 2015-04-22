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


class ChatTranscript
{
        public:
        int howMany(vector <string> transcript, string name)
        {
            int cnt = 0;
            for(auto line : transcript) {
                int i=0; 
                for(; i<line.size(); ++i) 
                    if(line[i] == ' ' || line[i] == ':') break;
                if(i && i != line.size() && line[i] == ':' && 
                   name == line.substr(0, i)) ++cnt;
            }
            return cnt;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = {
//"Bob: Hello Tim.",
//"Tim: Hello Bob.",
//"Bob: How are ya Tim?",
//"Frank: Stop chatting!"
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob"; int Arg2 = 2; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
//	void test_case_1() { string Arr0[] = {
//"Bob: This is a long",
//"sentence that takes 2 lines.",
//"Tim: Yes it is.",
//"Bob : I am not Bob.",
//"Frank: No you aren't!",
//" Bob: Neither am I."
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob"; int Arg2 = 1; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
//	void test_case_2() { string Arr0[] = {
//"Crazy1010: !@LK%#L%K @#L%K @#L%K@#L%K2kl53k2",
//"Bob: You are crazy.",
//"Crazy1010 Yup #@LK%$L!K%LK%!K% !K afmas,"
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Crazy1010"; int Arg2 = 1; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
//	void test_case_3() { string Arr0[] = {
//"A:A:A:A:A:A:A:A:A",
//"b:b:b:b:b:b:b:b:b"
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "B"; int Arg2 = 0; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
//	void test_case_4() { string Arr0[] = {"A:A:A:A:A:A:A:A:A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; int Arg2 = 1; verify_case(4, Arg2, howMany(Arg0, Arg1)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        ChatTranscript ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
