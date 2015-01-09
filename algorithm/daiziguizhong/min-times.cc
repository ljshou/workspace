/**
 * @file min-times.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-05
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief m eggs to test n floors
 */
int MinTimes(int n, int m) 
{
    if(m < 1 || n < 1) return 0;
    vector<vector<int> > f(m+1, vector<int>(n+1, n));
    //initialization
    for(int i=0; i<=n; ++i) f[1][i] = i;
    for(int i=0; i<=m; ++i) f[i][0] = 0, f[i][1] = 1;

    for(int i=2; i<=m; ++i) {
        for(int j=2; j<=n; ++j) {
            for(int k=1; k<=j; ++k) {
                f[i][j] = min(f[i][j], 1 + max(f[i-1][k-1], f[i][j-k]));
            }
        }
    }
    return f[m][n];
}

int main(void)
{
    cout << MinTimes(100, 2) << endl;
    return 0;
}
