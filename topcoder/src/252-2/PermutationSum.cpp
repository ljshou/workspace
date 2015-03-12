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

vector<int> Int2Vec(int n)
{
    vector<int> res;
    while(n) {
        res.push_back(n%10);
        n /= 10;
    }
    return res;
}

int Vec2Int(vector<int> vec)
{
    int res(0);
    for(auto x : vec) {
        res = res*10 + x;
    }
    return res;
}


class PermutationSum
{
        public:
        int add(int n)
        {
            int res = 0;
            auto vec = Int2Vec(n);
            sort(vec.begin(), vec.end());
            do {
                res += Vec2Int(vec);
            }while(next_permutation(vec.begin(), vec.end()));
            return res;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arg0 = 157; int Arg1 = 2886; verify_case(0, Arg1, add(Arg0)); }
//	void test_case_1() { int Arg0 = 313; int Arg1 = 777; verify_case(1, Arg1, add(Arg0)); }
//	void test_case_2() { int Arg0 = 1234; int Arg1 = 66660; verify_case(2, Arg1, add(Arg0)); }
//	void test_case_3() { int Arg0 = 5; int Arg1 = 5; verify_case(3, Arg1, add(Arg0)); }
//	void test_case_4() { int Arg0 = 54321; int Arg1 = 3999960; verify_case(4, Arg1, add(Arg0)); }
//	void test_case_5() { int Arg0 = 99999; int Arg1 = 99999; verify_case(5, Arg1, add(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        PermutationSum ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
