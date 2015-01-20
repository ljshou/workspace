/**
 * @file interleaving-string.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-19
 */

#include <bits/stdc++.h>
using namespace std;

bool InterleavingString(const string &a, const string &b, const string &c)
{
    const int m = a.size(), n = b.size();
    if(m + n != c.size())
        return false;
    vector<vector<bool> > f(m+1, vector<bool>(n+1, false));
    //initialization
    f[0][0] = true;
    for(int i=1; i<=m; ++i) 
        f[i][0] = f[i-1][0] && a[i-1] == c[i-1]; 
    for(int i=1; i<=n; ++i) 
        f[0][i] = f[0][i-1] && b[i-1] == c[i-1]; 

    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            f[i][j] = (f[i-1][j] && a[i-1] == c[i+j-1]) 
                    ||(f[i][j-1] && b[j-1] == c[i+j-1]);
        }
    }
    return f[m][n];
}

bool InterleavingString2(const string &a, const string &b, const string &c)
{
    const int m = a.size(), n = b.size();
    if(m + n != c.size())
        return false;
    vector<bool> f(n+1, false);
    //initialization
    f[0] = true;
    for(int i=1; i<=n; ++i)
        f[i] = f[i-1] && (b[i-1] == c[i-1]);

    for(int i=1; i<=m; ++i) {
        f[0] = f[0] && (a[i-1] == c[i-1]); 
        for(int j=1; j<=n; ++j) {
            f[j] = (f[j] && (a[i-1] == c[i+j-1])) 
                || (f[j-1] && (b[j-1] == c[i+j-1]));
        }
    }
    return f[n];
}


void Test()
{
    assert(InterleavingString("ef", "gh", "egfh") == true);
    assert(InterleavingString("ef", "gh", "ehgf") == false);
    assert(InterleavingString2("ef", "gh", "egfh") == true);
    assert(InterleavingString2("ef", "gh", "ehgf") == false);
}

int main(void)
{
    Test();
    return 0;
}
