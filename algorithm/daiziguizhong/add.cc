/**
 * @file add.cc
 * @brief add two numbers
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-17
 */

#include <iostream>
#include <cassert>
using namespace std;

int Sum(int a, int b)
{
    if(b == 0) return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return Sum(sum, carry);
}

void Test()
{
    assert(Sum(0, 6) == 6);
    assert(Sum(1, 6) == 7);
    assert(Sum(-1, 6) == 5);
    assert(Sum(18, 6) == 24);
}

int main(void)
{
    Test();
    return 0;
}
