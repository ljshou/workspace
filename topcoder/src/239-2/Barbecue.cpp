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

struct Vote {
    int voted, votes, index;
    Vote(int vd=0, int vt=0, int i=0):
        voted(vd), votes(vt), index(i) {}
    bool operator<(const Vote &rhs) const {
        if(voted != rhs.voted) return voted < rhs.voted;
        if(votes != rhs.votes) return votes < rhs.votes;
        return index > rhs.index;
    }
};

class Barbecue
{
        public:
        int eliminate(int n, vector <int> voter, vector <int> excluded)
        {
            vector<Vote> vec(n);
            For(i, n) vec[i].index = i;
            For(i, voter.size()) {
                ++ vec[excluded[i]].voted;
                ++ vec[voter[i]].votes;
            }
            return max_element(vec.begin(), vec.end()) - vec.begin();
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); } //	private: //	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); } //	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, eliminate(Arg0, Arg1, Arg2)); }
//	void test_case_1() { int Arg0 = 3; int Arr1[] = {0,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, eliminate(Arg0, Arg1, Arg2)); }
//	void test_case_2() { int Arg0 = 2; int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, eliminate(Arg0, Arg1, Arg2)); }
//	void test_case_3() { int Arg0 = 20; int Arr1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,5,
//6,7,8,9,10,11,12,13,14,15,16,17,18,19,19,19,19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
//0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, eliminate(Arg0, Arg1, Arg2)); }
//	void test_case_4() { int Arg0 = 5; int Arr1[] = {4,3,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,3,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(4, Arg3, eliminate(Arg0, Arg1, Arg2)); }
//	void test_case_5() { int Arg0 = 10; int Arr1[] = {4,5,6,7,8,9,0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,6,7,8,9,0,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(5, Arg3, eliminate(Arg0, Arg1, Arg2)); }
//	void test_case_6() { int Arg0 = 7; int Arr1[] = {1,2,3,4,5,6,0,2,3,4,5,6,0,1,3,4,5,6,0,1,2,
// 4,5,6,0,1,2,3,5,6,0,1,2,3,4,6,0,1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,
// 3,3,3,4,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(6, Arg3, eliminate(Arg0, Arg1, Arg2)); }
//	void test_case_7() { int Arg0 = 5; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(7, Arg3, eliminate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        Barbecue ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
