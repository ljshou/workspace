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

vector<int> Merge(const vector<int> &lhs, const vector<int> &rhs)
{
    vector<int> res;
    const int m = lhs.size(), n = rhs.size();
    int i(0), j(0);
    while(i < m && j < n) {
        if(lhs[i] < rhs[j]) res.push_back(lhs[i++]);
        else if(lhs[i] > rhs[j]) res.push_back(rhs[j++]);
        else {
            res.push_back(lhs[i]);
            ++i, ++j;
        }
    }
    if(i < m) res.insert(res.end(), lhs.begin()+i, lhs.end());
    if(j < n) res.insert(res.end(), rhs.begin()+j, rhs.end());
    return res;
}

class Party
{
        public:
        double averageNames(int n, vector <int> personA, vector <int> personB)
        {
            vector<vector<int> > vec(n);
            For(i, n) vec[i].push_back(i);
            For(i, personA.size()) {
                int x = personA[i];
                int y = personB[i];
                //merge
                vector<int> tmp; 
                set_union(vec[x].begin(), vec[x].end(), vec[y].begin(), vec[y].end(), back_inserter(tmp));
                vec[x] = vec[y] = tmp;
            }
            double res = 0;
            For(i, n) res += vec[i].size() - 1;
            return res / n;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { int Arg0 = 4; int Arr1[] = {0,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 2.25; verify_case(0, Arg3, averageNames(Arg0, Arg1, Arg2)); }
//	void test_case_1() { int Arg0 = 5; int Arr1[] = {0,0,0,0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,3,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 4.0; verify_case(1, Arg3, averageNames(Arg0, Arg1, Arg2)); }
//	void test_case_2() { int Arg0 = 100; int Arr1[] = {52,19,52,19}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {19,52,19,52}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.02; verify_case(2, Arg3, averageNames(Arg0, Arg1, Arg2)); }
//	void test_case_3() { int Arg0 = 25; int Arr1[] = {14, 14, 16, 4, 14, 16, 2, 16, 8, 15, 17, 17, 3, 3, 19, 17, 20, 4, 24, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {16, 2, 23, 16, 11, 8, 5, 19, 15, 20, 19, 18, 14, 12, 22, 9, 0, 7, 23, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 4.44; verify_case(3, Arg3, averageNames(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        Party ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
