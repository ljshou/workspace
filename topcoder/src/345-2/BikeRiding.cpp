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


class BikeRiding
{
public:
    int countRoutes(vector <string> paths, vector <int> startPoints, int endPoint, int threhold)
    {
        n = paths.size();
        visited.assign(n, false);
        circle.assign(n, false);
        memo.assign(n, -1);
        int res = 0;
        for(auto x : startPoints) { 
            res += dfs(x, paths, endPoint);
        }

        For(i, n) {
            if((memo[i] > 0 && circle[i]) || memo[i] > threhold)
                return -1;
        }
        return res > threhold ? -1 : res;
    }

    int dfs(int cur, vector<string> &paths, int endPoint)
    {
        if(memo[cur] != -1) return memo[cur];
        if(visited[cur]) {
            circle[cur] = true;
            return 0;
        }
        visited[cur] = true;

        int res = 0;
        if(cur == endPoint) res = 1;
        For(j, paths[cur].size()) {
            if(paths[cur][j] == '1') {
                res += dfs(j, paths, endPoint);
            }
        }

        visited[cur] = false;
        return memo[cur] = res;
    }
private:    
    int n;
    vector<bool> visited, circle;
    vector<int> memo;

    // BEGIN CUT HERE
//public:
//    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//private:
//    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//    void test_case_0() { string Arr0[] = {"011" ,"001", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 5; int Arg4 = 3; verify_case(0, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
//    void test_case_1() { string Arr0[] = {"01000",
//        "00100",
//        "00010",
//        "01001",
//        "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 10; int Arg4 = -1; verify_case(1, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
//    void test_case_2() { string Arr0[] = {"000111000000000","000111000000000","000111000000000",
//        "000000111000000","000000111000000","000000111000000",
//        "000000000111000","000000000111000","000000000111000",
//        "000000000000111","000000000000111","000000000000111",
//        "000000000000001","000000000000001","000000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; int Arg3 = 1000; int Arg4 = 243; verify_case(2, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
//    void test_case_3() { string Arr0[] = {"010", "100", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 10; int Arg4 = 0; verify_case(3, Arg4, countRoutes(Arg0, Arg1, Arg2, Arg3)); }
//
    // END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//    BikeRiding ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
