/**
 * @file generate-sequence.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-24
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int UglyNumber(int n) 
{
    if(n <= 0) return 0;
    vector<int> f(n, 0);
    f[0] = 1;
    int next_index = 1;
    auto p2 = f.begin();
    auto p5 = f.begin();

    while(next_index < n) {
        f[next_index] = min(*p2*2, *p5*5);
        while(*p2 * 2 <= f[next_index]) ++p2;
        while(*p5 * 5 <= f[next_index]) ++p5;
        ++next_index;
    }
    return f.back();
}

void Test()
{
    assert(UglyNumber(1) == 1);
    assert(UglyNumber(2) == 2);
    assert(UglyNumber(3) == 4);
    assert(UglyNumber(4) == 5);
    assert(UglyNumber(5) == 8);
}

int main(void)
{
    Test();
    return 0;
}
