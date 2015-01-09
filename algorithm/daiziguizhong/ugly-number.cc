/**
 * @file ugly-number.cc
 * @brief ugly number
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-06
 */


#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int Min(int x1, int x2, int x3)
{
    return min(x1, min(x2, x3));
}

int UglyNumber(int n)
{
    if(n < 1) return 1;
    vector<int> f(n);
    f[0] = 1;
    int next_ugly_index = 1;
    auto p3 = f.begin();
    auto p5 = f.begin();
    auto p7 = f.begin();
    while(next_ugly_index < n) {
        f[next_ugly_index] = Min(*p3 * 3, *p5 * 5, *p7 * 7);
        while(*p3 * 3 <= f[next_ugly_index]) ++p3;
        while(*p5 * 5 <= f[next_ugly_index]) ++p5;
        while(*p7 * 7 <= f[next_ugly_index]) ++p7;
        ++next_ugly_index;
    }
    return f[n-1];
}

void Test()
{
    assert(UglyNumber(1) == 1);
    assert(UglyNumber(2) == 3);
    assert(UglyNumber(3) == 5);
    assert(UglyNumber(4) == 7);
    assert(UglyNumber(5) == 9);
    assert(UglyNumber(6) == 15);
    assert(UglyNumber(7) == 21);
    assert(UglyNumber(8) == 25);
    assert(UglyNumber(9) == 27);
    assert(UglyNumber(10) == 35);
    assert(UglyNumber(11) == 45);
    assert(UglyNumber(12) == 49);
    assert(UglyNumber(13) == 63);
}

int main(void)
{
    Test();
    return 0;
}
