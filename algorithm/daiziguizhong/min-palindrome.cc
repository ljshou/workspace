/**
 * @file min-palindrome.cc
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
    const int n = str.size();
    if(n < 2) return 0;
    vector<vector<int> > f(n, vector<int>(n, 0));
    //initialization
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            f[i][j] = j - i;
        }
    }
    
    for(int i=n-1; i>=0; --i) {
        for(int j=i+1; j<n; ++j) {
            f[i][j] = min(f[i][j], 1+f[i+1][j]);
            f[i][j] = min(f[i][j], 1+f[i][j-1]);
            if(str[i] == str[j]) {
                f[i][j] = min(f[i][j], i+1==j? 0 : f[i+1][j-1]);
            }
        }
    }
    return f[0][n-1];
}

int main(void)
{
    assert(0 == MinCut("a"));
    assert(0 == MinCut("aba"));
    assert(2 == MinCut("abc"));
    assert(1 == MinCut("abaa"));
    return 0;
}
