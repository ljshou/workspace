/**
 * @file cars.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-09
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int Fact(int n) {
    if(n == 0) return 1;
    int res = 1;
    for(int i=2; i<=n; ++i) 
        res *= i;
    return res;
}

int Comb(int n, int k) {
    return Fact(n) / Fact(n-k) / Fact(k);
}

int Compute(int n, int k)
{
    if(n <= 0) return 0;
    vector<vector<int> >  f(n+1, vector<int>(n+1, 0));
    f[0][0] = 1;
    for(int i=1; i<=n; ++i) {
        for(int k=1; k<=i; ++k) {
            for(int j=0; j<i; ++j)
                f[i][k] += f[j][k-1] * Comb(i-1, i-j-1) * Fact(i-j-1);
        }
    }
    cout << f[n][k] << endl;
    return f[n][k];
}

void Test()
{
    assert(1 == Compute(1, 1));
    assert(1 == Compute(2, 1));
    assert(1 == Compute(2, 2));
    assert(2 == Compute(3, 1));
    assert(3 == Compute(3, 2));
    assert(1 == Compute(3, 3));
    assert(6 == Compute(4, 1));
    assert(11 == Compute(4, 2));
    assert(6 == Compute(4, 3));
    assert(1 == Compute(4, 4));
}

int main(void)
{
    Test();
    return 0;
}
