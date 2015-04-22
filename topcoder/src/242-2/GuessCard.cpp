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


class GuessCard
{
        public:
        int whichRow(int n, int m, vector <int> columns)
        {
            if(columns.empty()) return -1;

            vector<vector<int> > vec(m, vector<int>(n, 0));
            auto vec2 = vec;
            For(i, m) For(j, n) vec[i][j] = i*n + j;
            vector<int> col(m), col2(m);
            //initialization
            For(i, m) col[i] = vec[i][columns[0]];
            sort(col.begin(), col.end());

            for(auto index : columns) {
                vector<int> tmp;
                For(i, m) col2[i] = vec[i][index];
                sort(col2.begin(), col2.end());
                set_intersection(col.begin(), col.end(), col2.begin(), col2.end(), back_inserter(tmp));
                col.swap(tmp);

                int k = 0;
                For(j, n) For(i, m) {
                    int x = k / n;
                    int y = k % n;
                    vec2[x][y] = vec[i][j];
                    ++k;
                }
                vec.swap(vec2);
            }

            if(col.size() == 1) {
                For(i, m) if(vec2[i][columns.back()] == col[0]) return i;
            }

            return -1;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arg0 = 3; int Arg1 = 7; int Arr2[] = {2, 1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, whichRow(Arg0, Arg1, Arg2)); }
//	void test_case_1() { int Arg0 = 3; int Arg1 = 7; int Arr2[] = {2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, whichRow(Arg0, Arg1, Arg2)); }
//	void test_case_2() { int Arg0 = 1; int Arg1 = 10; int Arr2[] = {0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(2, Arg3, whichRow(Arg0, Arg1, Arg2)); }
//	void test_case_3() { int Arg0 = 10; int Arg1 = 1; int Arr2[] = {4, 4, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, whichRow(Arg0, Arg1, Arg2)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        GuessCard ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
