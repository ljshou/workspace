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

inline int MAX(int i, int j, int k, int l)
{
    return max(i, max(j, max(k, l)));
}

class Flush
{
        public:
        double size(vector <int> suits, int number)
        {
            double f[14][14][14][14] = {0};
            LL sum = accumulate(suits.begin(), suits.end(), 0);
            f[0][0][0][0] = 1;
            For(i, suits[0]+1) {
                For(j, suits[1]+1) {
                    For(k, suits[2]+1) {
                        For(l, suits[3]+1) {
                            if(i) f[i][j][k][l] += f[i-1][j][k][l] * (suits[0]-i+1) / (sum-i-j-k-l+1);
                            if(j) f[i][j][k][l] += f[i][j-1][k][l] * (suits[1]-j+1) / (sum-i-j-k-l+1);
                            if(k) f[i][j][k][l] += f[i][j][k-1][l] * (suits[2]-k+1) / (sum-i-j-k-l+1);
                            if(l) f[i][j][k][l] += f[i][j][k][l-1] * (suits[3]-l+1) / (sum-i-j-k-l+1);
                        }
                    }
                }
            }
            double res = 0;
            For(i, suits[0]+1) {
                For(j, suits[1]+1) {
                    For(k, suits[2]+1) {
                        For(l, suits[3]+1) {
                            if(i+j+k+l == number)
                                res += MAX(i,j,k,l) * f[i][j][k][l];
                        }
                    }
                }
            }
            return res;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arr0[] = {2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.1428571428571428; verify_case(0, Arg2, size(Arg0, Arg1)); }
//	void test_case_1() { int Arr0[] = {1,4,7,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; double Arg2 = 10.0; verify_case(1, Arg2, size(Arg0, Arg1)); }
//	void test_case_2() { int Arr0[] = {13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; double Arg2 = 13.0; verify_case(2, Arg2, size(Arg0, Arg1)); }
//	void test_case_3() { int Arr0[] = {13, 13, 13, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; double Arg2 = 8.351195960938014; verify_case(3, Arg2, size(Arg0, Arg1)); }
//	void test_case_4() { int Arr0[] = {13,13,13,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; double Arg2 = 0.0; verify_case(4, Arg2, size(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        Flush ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
