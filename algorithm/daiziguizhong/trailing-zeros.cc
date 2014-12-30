/**
 * @file trailing-zeros.cc
 * @brief determine trailing zeros of n!
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */

#include <iostream>
#include <cassert>
using namespace std;

int TrailingZeros(int n)
{
    assert(n >= 0);
    int count(0);
    while(n) {
        n /= 5;
        count += n;
    }
    return count;
}

int main(void)
{
    assert(2 == TrailingZeros(10));
    assert(4 == TrailingZeros(22));
    return 0;
}
