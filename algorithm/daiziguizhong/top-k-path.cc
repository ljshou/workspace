/**
 * @file top-k-path.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-09
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void topk(vector<int> &a, vector<int> &b, vector<int> &res, int k, int value)
{
    int i(0), j(0);
    for(int p=0; p<k; ++p) {
        res[p] += value;
        if(a[i] > b[j])  res[p] += a[i++];
        else res[p] += b[j++];
    }
}

void TopKPath(const vector<vector<int> > &a, int k)
{
    if(a.empty() || a.front().empty() || k <= 0) return;
    const int m = a.size(), n = a.front().size();
    vector<vector<vector<int> > > f(m+1, vector<vector<int> >(n+1, vector<int>(k, 0)));
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            topk(f[i-1][j], f[i][j-1], f[i][j], k, a[i-1][j-1]);
        }
    }
    for(int i=0; i<k; ++i)
        cout << f[m][n][i] << " ";
    cout << endl;
}

void Test()
{
    vector<vector<int> > vec{{0,1,2}, {2,1,1}, {1,1,1}};
    TopKPath(vec, 3);
}

int main(void)
{
    Test();
    return 0;
}
