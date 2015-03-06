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


class RobotOnMoonEasy
{
        public:
        string isSafeCommand(vector <string> board, string S)
        {
            int x = -1, y = -1;
            //find start place
            For(i, board.size()) {
                For(j, board[i].size()) {
                    if(board[i][j] == 'S') x = i, y = j;
                }
            }
            if(x == -1 || y == -1) return "Dead";
            const int m = board.size(), n = board.front().size();
            for(auto c : S) {
                switch(c) {
                case 'U':
                    --x;
                    if(x < 0) return "Dead";
                    if(board[x][y] == '#') ++x;
                    break;
                case 'D':
                    ++x;
                    if(x >= m) return "Dead";
                    if(board[x][y] == '#') --x;
                    break;
                case 'L':
                    --y;
                    if(y < 0) return "Dead";
                    if(board[x][y] == '#') ++y;
                    break;
                case 'R':
                    ++y;
                    if(y >= n) return "Dead";
                    if(board[x][y] == '#') --y;
                }
            }
            return "Alive";
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = {".....",
// ".###.",
// "..S#.",
// "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Alive"; verify_case(0, Arg2, isSafeCommand(Arg0, Arg1)); }
//	void test_case_1() { string Arr0[] = {".....",
// ".###.",
// "..S..",
// "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Dead"; verify_case(1, Arg2, isSafeCommand(Arg0, Arg1)); }
//	void test_case_2() { string Arr0[] = {".....",
// ".###.",
// "..S..",
// "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURU"; string Arg2 = "Alive"; verify_case(2, Arg2, isSafeCommand(Arg0, Arg1)); }
//	void test_case_3() { string Arr0[] = {"#####",
// "#...#",
// "#.S.#",
// "#...#",
// "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Alive"; verify_case(3, Arg2, isSafeCommand(Arg0, Arg1)); }
//	void test_case_4() { string Arr0[] = {"#####",
// "#...#",
// "#.S.#",
// "#...#",
// "#.###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Dead"; verify_case(4, Arg2, isSafeCommand(Arg0, Arg1)); }
//	void test_case_5() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "R"; string Arg2 = "Dead"; verify_case(5, Arg2, isSafeCommand(Arg0, Arg1)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        RobotOnMoonEasy ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
