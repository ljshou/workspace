/**
 * @file max-product.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-04
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int MaxProduct(int n)
{
    if(n < 2) return 0;
    vector<int> f(n+1, 0);
    for(int i=2; i<=n; ++i) {
        for(int j=1; j<i; ++j) {
            f[i] = max(f[i], max(j*(i-j), f[j] * (i-j)));
        }
    }
    return f[n];
}

int main(void)
{
    assert(1 == MaxProduct(2));
    assert(2 == MaxProduct(3));
    assert(4 == MaxProduct(4));
    assert(6 == MaxProduct(5));
    return 0;
}
