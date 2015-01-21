/**
 * @file cut-rope.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-21
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int MaxProduct(int n)
{
    if(n <= 0) return 0;
    vector<int> f(n+1, 1);
    for(int i=3; i<=n; ++i) {
        for(int j=1; j<i; ++j) {
            f[i] = max(f[i], f[j] * (i-j));
            f[i] = max(f[i], j*(i-j));
        }
    }
    return f[n];
}

void Test()
{
    assert(MaxProduct(1) == 1);
    assert(MaxProduct(2) == 1);
    assert(MaxProduct(3) == 2);
    assert(MaxProduct(4) == 4);
    assert(MaxProduct(5) == 6);
}

int main(void)
{
    Test();
    return 0;
}
