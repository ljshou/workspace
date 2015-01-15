/**
 * @file get-max.cc
 * @brief compute larger number of two numbers
 * without using if
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-14
 */
#include <iostream>
#include <cassert>
using namespace std;

/**
 * @brief flip a bit
 */
int flip(int a)
{
    return a ^ 0x1;
}

/**
 * @return sign of number
 * @retval 1: positive 
 * @retval 0: negative
 */
int sign(int a)
{
    return flip((a >> 31) & 0x1);
}

int Max(int a, int b)
{
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(a - b);

    //如果a,b符号不同 
    int use_sign_a = sa ^ sb;
    int use_sign_c = flip(sa ^ sb);
    int k = use_sign_a * sa + use_sign_c * sc;
    return a*k + b*flip(k);
}

void Test()
{
    assert(Max(2, -1) == 2);
    assert(Max(1, 2) == 2);
    assert(Max(1, 0) == 1);
}

int main(void)
{
    Test();
    return 0;
}
