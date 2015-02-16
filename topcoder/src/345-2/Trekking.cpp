//// BEGIN CUT HERE

// END CUT HERE
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

#define PB push_back
#define MP make_pair

#define For(i, n) for(int i=0;i<(n);++i)
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


class Trekking
{
        public:
        int findCamps(string trail, vector <string> plans)
        {
            int count = INT_MAX;
            const int n = trail.size();
            int step = 0;
            bool flag = true;
            For(i, plans.size()) {
                flag = true;
                step = 0;
                For(j, n) {
                    if(plans[i][j] == 'C') {
                        if(trail[j] == '^') {
                            flag = false;
                            break;
                        }
                        ++step;
                    }
                }
                if(flag) count = min(count, step);
            }
            return count == INT_MAX ? -1 : count;
        }
};
