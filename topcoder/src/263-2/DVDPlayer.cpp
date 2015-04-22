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


class DVDPlayer
{
        public:
        vector <string> findMovies(vector <string> moviesWatched)
        {
            vector<string> res;
            if(moviesWatched.empty()) return res;
            map<string, string> hashing; //album, case
            for(auto movie : moviesWatched) hashing[movie] = movie;

            string cur = moviesWatched[0];
            hashing[cur] = ""; //playing
            for(int i=1; i<moviesWatched.size(); ++i) {
                swap(hashing[cur], hashing[moviesWatched[i]]);
                cur = moviesWatched[i];
            }
            for(auto p : hashing) 
                if(!p.second.empty() && p.first != p.second) 
                    res.push_back(p.first + " is inside " + p.second + "'s case");
            return res;
        }
        
// BEGIN CUT HERE
//	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
//	private:
//	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
//	void test_case_0() { string Arr0[] = {"citizenkane", "casablanca", "thegodfather"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"casablanca is inside thegodfather's case", "citizenkane is inside casablanca's case" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findMovies(Arg0)); }
//	void test_case_1() { string Arr0[] = {"starwars", "empirestrikesback", "returnofthejedi",
// "empirestrikesback", "returnofthejedi",
// "phantommenace", "starwars"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"empirestrikesback is inside returnofthejedi's case", "phantommenace is inside empirestrikesback's case", "returnofthejedi is inside phantommenace's case" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findMovies(Arg0)); }
//	void test_case_2() { string Arr0[] = {"a", "x", "a", "y", "a", "z", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findMovies(Arg0)); }
//
// END CUT HERE

};

// BEGIN CUT HERE
//int main()
//{
//        DVDPlayer ___test;
//        ___test.run_test(-1);
//        return 0;
//}
// END CUT HERE
