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
#include <unordered_map>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


class ReportAccess
{
        public:
        vector <string> whoCanSee(vector <string> userNames, vector <string> allowedData, vector <string> reportData)
        {
            //revertd indexing
            unordered_map<string, vector<int> > Hash;
            For(i, allowedData.size()) {
                stringstream ss;
                ss << allowedData[i];
                string s;
                while(ss >> s) Hash[s].push_back(i);
            }

            vector<int> vec = Hash[reportData[0]];
            for(int i=1; i<reportData.size(); ++i) {
                vector<int> vec1 = vec;
                vector<int> &vec2 = Hash[reportData[i]];
                auto it = set_intersection(vec1.begin(), vec1.end(), 
                                           vec2.begin(), vec2.end(), vec.begin());
                vec.erase(it, vec.end());
            }
            vec.erase(unique(vec.begin(), vec.end()), vec.end());
            vector<string> res;
            for(auto i : vec) res.push_back(userNames[i]);
            sort(res.begin(), res.end());
            return res;

        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
//	void test_case_0() { string Arr0[] = {"joe", "nick", "ted"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"clients products", "products orders", "clients orders"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"clients", "products"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"joe" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, whoCanSee(Arg0, Arg1, Arg2)); }
//	void test_case_1() { string Arr0[] = {"kathy", "john", "dan", "steve", "cheryl", "tony"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"users data", "data orders", "users permissions", "system users controls", "default", "admin users"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"users"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"dan", "kathy", "steve", "tony" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, whoCanSee(Arg0, Arg1, Arg2)); }
//	void test_case_2() { string Arr0[] = {"jim", "scott", "barbara"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"users order products", "products shipping", "tracking products orders"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"admin"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, whoCanSee(Arg0, Arg1, Arg2)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        ReportAccess ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
