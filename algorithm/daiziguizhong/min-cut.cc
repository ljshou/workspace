/**
 * @file min-cut.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-04
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

int MinCut(const string &str)
{
    if(str.size() < 2) return 0;
    const int n = str.size();
    vector<vector<bool> > flag(n, vector<bool>(n, false));
    for(int i=n-1; i>=0; --i) {
        flag[i][i] = true;
        for(int j=i+1; j<n; ++j) {
            flag[i][j] = (j == i+1 || flag[i+1][j-1]) && (str[i] == str[j]);
        }
    }
    
    vector<int> g(n+1, 0);
    g[0] = -1;
    for(int i=1; i<=n; ++i)  {
        g[i] = i-1;
        for(int j=i-1; j>=0; --j)
            if(flag[j][i-1]) g[i] =  min(g[i], 1 + g[j]);
    }
    return g[n];
}

int main(void)
{
    assert(0 == MinCut(""));
    assert(0 == MinCut("a"));
    assert(0 == MinCut("aa"));
    assert(2 == MinCut("abc"));
    assert(3 == MinCut("ababbbabbababa"));
    return 0;
}
