/**
 * @file palindrome-integer.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-03
 */


#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    int d = 1;
    while(x/d >= 10) d*= 10;
    while(x > 0) {
        int q = x / d;
        int r = x % 10;
        if(q != r) return false;
        x = x%d / 10;
        d /= 100;
    }
    return true;
}

void Test()
{
    assert(isPalindrome(1000000001) == true);
}

int main(void)
{
    Test();
    return 0;
}
