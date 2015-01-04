/**
 * @file minimum-common.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-31
 */

#include <iostream>
#include <vector>
using namespace std;

int MinimumCommon(int n)
{
    int res = 1;
    vector<int> a(n);
    for(int i=0; i<n; ++i) a[i] = i+1;
    for(int i=0; i<a.size(); ++i)  {
        res *= a[i];
        for(int j=i+1; j<a.size(); ++j) 
            if(a[j] % a[i] == 0) a[j] /= a[i];
    }
    return res;
}

int main(void)
{
    int n;
    cin >> n;
    cout << MinimumCommon(n) << endl;
    return 0;
}
