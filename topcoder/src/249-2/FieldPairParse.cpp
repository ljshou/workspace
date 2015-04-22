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


class FieldPairParse
{
        public:
        vector <int> getPairs(vector <string> data)
        {
            const int m = data.size(), n = data[0].size();
            vector<int> f(n, false);
            For(i, m) {
                For(j, n) {
                    if(data[i][j] == 'X')
                        f[j] = true;
                }
            }
            //adjacent 0s
            vector<int> res;
            int cnt = 0;
            for(auto x : f) {
                if(x == true) {
                    if(cnt) res.push_back(cnt);
                    cnt = 0;
                }
                else {
                    ++cnt;
                }
            }
            if(cnt) res.push_back(cnt);
            if(res.size() % 2 == 0) return vector<int>();
            else return res;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
//	void test_case_0() { string Arr0[] = {
//"XXXXX    XXXXX",
//"XXXX    XXXXX "
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getPairs(Arg0)); }
//	void test_case_1() { string Arr0[] = {
//"XXXXXXXXXX     XXXXXXXXXXX",
//"XXXXXXXXXXXXXXXXX    XXXXX"
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getPairs(Arg0)); }
//	void test_case_2() { string Arr0[] = {
//"X X X",
//"X X X"
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getPairs(Arg0)); }
//	void test_case_3() { string Arr0[] = {
//"XXXX      X  X           X X   X",
//"XX       XXX XX   X   X   X XXX "
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 1, 3, 3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getPairs(Arg0)); }
//	void test_case_4() { string Arr0[] = {"XXXX      X  X           X X   X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 2, 11, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getPairs(Arg0)); }
//	void test_case_5() { string Arr0[] = {"XXX XXX XXX XXX XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getPairs(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        FieldPairParse ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
