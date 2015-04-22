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

int ShortestPath(int x, int y, vector<string> board)
{
    if(board[x][y] == '#') return 0xfffff; 
    const int n = board.front().size();
    bool visited[3][55] = {false};
    queue<int> cur, next;
    cur.push(x*n + y);
    visited[x][y] = true;
    int step = 1;
    while(!cur.empty()) {
        x = cur.front() / n;
        y = cur.front() % n;
        cur.pop();

        if(y == n-1) return step;

        if(x-1>=0 && !visited[x-1][y] && board[x-1][y] == '.') {
            visited[x-1][y] = true;
            next.push((x-1)*n + y);
        }
        if(x+1<2 && !visited[x+1][y] && board[x+1][y] == '.') {
            visited[x+1][y] = true;
            next.push((x+1)*n + y);
        }
        if(y+1<n && !visited[x][y+1] && board[x][y+1] == '.') {
            visited[x][y+1] = true;
            next.push((x)*n + y+1);
        }
        if(cur.empty()) {
            cur.swap(next);
            ++step;
        }
    }
    return step;
}

class PathGameDiv2
{
        public:
        int calc(vector <string> board)
        {
            const int n = board.front().size();
            int path = 0xfffff;
            path = min(path, ShortestPath(0, 0, board));
            path = min(path, ShortestPath(1, 0, board));
            int cnt = 0;
            for(auto str : board) {
                for(auto c : str) {
                    if(c == '.') ++ cnt;
                }
            }
            return cnt - path;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = {"#...."
//,"...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, calc(Arg0)); }
//	void test_case_1() { string Arr0[] = {"#"
//,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, calc(Arg0)); }
//	void test_case_2() { string Arr0[] = {"."
//,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, calc(Arg0)); }
//	void test_case_3() { string Arr0[] = {"....#.##.....#..........."
//,"..#......#.......#..#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, calc(Arg0)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        PathGameDiv2 ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
