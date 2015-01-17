/**
 * @file 1111.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-15
 */

#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int DividedByOnes(int a)
{
    assert(a > 0);
    if(a == 0) return -1;
    long long ret  = 1;
    int ans = 1;
    bool hash[a];
    fill_n(hash, a, false);

    while(ret % a != 0) {
        if(hash[ret]) return -1;
        hash[ret] = true;
        ret = ret*10 + 1;
        ret %= a;
        ++ ans;
    }
    return ans;
}

void Test()
{
    assert(DividedByOnes(37) == 3);
    assert(DividedByOnes(4049) == 2024);
}

int main(void)
{
    Test();
   return 0;
}
