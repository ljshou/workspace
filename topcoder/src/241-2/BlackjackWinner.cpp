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


class BlackjackWinner
{
        public:
        int winnings(int bet, int dealer, int dealerBlackjack, int player, int blackjack)
        {
            if(dealerBlackjack && blackjack) return 0;
            if(dealerBlackjack) return -bet;
            if(blackjack) return 1.5*bet;

            if(player > 21) return -bet;
            if(dealer > 21 || player > dealer) return bet;
            if(player < dealer) return -bet;
            return 0;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 0; int Arg3 = 21; int Arg4 = 0; int Arg5 = 10; verify_case(0, Arg5, winnings(Arg0, Arg1, Arg2, Arg3, Arg4)); }
//	void test_case_1() { int Arg0 = 26; int Arg1 = 21; int Arg2 = 1; int Arg3 = 21; int Arg4 = 0; int Arg5 = -26; verify_case(1, Arg5, winnings(Arg0, Arg1, Arg2, Arg3, Arg4)); }
//	void test_case_2() { int Arg0 = 100; int Arg1 = 25; int Arg2 = 0; int Arg3 = 21; int Arg4 = 1; int Arg5 = 150; verify_case(2, Arg5, winnings(Arg0, Arg1, Arg2, Arg3, Arg4)); }
//	void test_case_3() { int Arg0 = 78; int Arg1 = 22; int Arg2 = 0; int Arg3 = 23; int Arg4 = 0; int Arg5 = -78; verify_case(3, Arg5, winnings(Arg0, Arg1, Arg2, Arg3, Arg4)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        BlackjackWinner ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
