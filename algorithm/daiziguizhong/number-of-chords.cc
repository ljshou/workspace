/**
 * @file number-of-chords.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-16
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/**
 * @brief n pairs of node
 * all point number: 2*n
 */
int NumberOfChords(int n)
{
    if(n <= 0) return 1;
    vector<int> f(n+1, 0);
    f[0] = f[1] = 1;
    for(int i=2; i<=n; ++i) {
        for(int j=0; j<i; ++j) {
            f[i] += f[j] * f[i-1-j];
        }
    }
    return f[n];
}

void Test()
{
    assert(NumberOfChords(1) == 1);
    assert(NumberOfChords(2) == 2);
    assert(NumberOfChords(3) == 5);
}

int main(void)
{
    Test();
    return 0;
}
    


