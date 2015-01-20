/**
 * @file longest-equal-increasing.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-19
 */

#include <bits/stdc++.h>
using namespace std;

int LEI(vector<int> &vec)
{
    const int n = vec.size();
    if(n < 2) return n;
    sort(vec.begin(), vec.end());

    int res(2);
    //L[i][j]---stores LEI with vec[i], vec[j]as the first
    //and second element
    int L[n][n];

    for(int i=0; i<n; ++i)
        L[i][n-1] = 2;

    for(int j=n-2; j>=0; --j) {
        //search for i, j
        int i(j-1), k(j+1);
        while(i >= 0 && j <= n-1) {
            if(vec[i] + vec[k] > 2*vec[j]) {
                L[i][j] = 2;
                --i;
            }
            else if(vec[i] + vec[k] < 2*vec[j]) {
                ++k;
            }
            else {
                L[i][j] = L[j][k] + 1;
                res = max(res, L[i][j]);
                --i, ++k;
            }
        }
        while(i >= 0) {
            L[i][j] = 2;
            --i;
        }
    }
    return res;
}


void Test()
{
    vector<int> vec{1,2,4,6};
    cout << LEI(vec) << endl;
}

int main(void)
{
    Test();
    return 0;
}
