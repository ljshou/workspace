/**
 * @file lcm.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-05
 * HDU 1108
 */

#include <iostream>
#include <cassert>
using namespace std;

int gcd(int a, int b) 
{
    while(b != 0) {
        int tmp = a % b;
        a = b; 
        b = tmp;
    }
    return a;
}

int lcm(int a, int b)
{
    if(a == 0 || b == 0) return 0;
    return a*b/gcd(a, b);
}

void Test()
{
    assert(2 == gcd(4,2));
    assert(1 == gcd(4,3));
    assert(2 == gcd(4,6));

    assert(2 == lcm(1,2));
    assert(6 == lcm(3,2));
    assert(4 == lcm(4,2));
}

int main(void)
{
    Test();
    return 0;
}
