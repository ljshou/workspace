/**
 * @file brother-number.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-15
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;

template<class InputIterator>
bool NextPermutation(InputIterator begin, InputIterator end)
{
    if(begin+1 >= end) return false;
    auto i = end - 1;
    auto j = i;
    --i;
    while(i != begin && !(*i < *j)) {
        --i, --j;
    }
    if(!(*i < *j)) {
        reverse(begin, end);
        return false;
    }
    auto k = end - 1;
    while(!(*k > *i)) --k;
    iter_swap(i, k);
    reverse(j, end);
    return true;
}

int BrotherNumber(int n)
{
    if(n <= 0) return 0;
    string num  = to_string(n);
    NextPermutation(num.begin(), num.end());
    return atoi(num.c_str());
}

void Test()
{
    assert(BrotherNumber(38276) == 38627);
}

int main(void)
{
    Test();
    return 0;
}

