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


class TravellingByTrain
{
        public:
        string earliestArrival(vector <string> timeTable)
        {
            int day = 1;
            string tmp = "09:00";
            for(auto time : timeTable) {
                vector<string> vec;
                stringstream ss;
                ss << time;
                string s;
                while(ss >> s) vec.push_back(s);
                
                int day0;
                string tmp0;
                For(i, vec.size()) {
                    int day1 = day;
                    string s1 = vec[i].substr(0, 5);
                    string s2 = vec[i].substr(6, 5);
                    if(s1 < tmp) ++day1;
                    if(s2 <= s1) ++day1;
                    if(i == 0 || day1 < day0 || (day1 == day0 && s2 < tmp0)) {
                        day0 = day1;
                        tmp0 = s2;
                    }
                }

                day = day0;
                tmp = tmp0;
            }
            return tmp + ", day " + to_string(day);
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = {"10:00-13:00 12:00-15:00","11:00-16:00 14:00-19:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "19:00, day 1"; verify_case(0, Arg1, earliestArrival(Arg0)); }
//	void test_case_1() { string Arr0[] = {"09:00-13:57","13:56-17:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "17:00, day 2"; verify_case(1, Arg1, earliestArrival(Arg0)); }
//	void test_case_2() { string Arr0[] = {"10:00-08:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "08:00, day 2"; verify_case(2, Arg1, earliestArrival(Arg0)); }
//	void test_case_3() { string Arr0[] = {"09:10-11:00 09:05-10:05","10:10-12:00 11:00-11:05","17:00-08:00","09:00-08:00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "08:00, day 3"; verify_case(3, Arg1, earliestArrival(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        TravellingByTrain ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
