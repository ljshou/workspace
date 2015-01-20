/**
 * @file stable-0-1.cc
 * @brief put negative number before
 * positive numbers with changing the relative order 
 * in each group
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-19
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator Iterator;

int CountNegative(Iterator first, Iterator last)
{
    int count(0);
    for(auto it = first; it != last; ++ it)
        if(*it < 0) ++ count;
    return count;
}

void StableSort01(Iterator first, Iterator last)
{
    if(first == last) return;
    int negative_count = CountNegative(first, last);
    if(negative_count == 0) return;

    auto i = find_if(first, last, [](int x){ return x > 0;});
    auto j = find_if(first+negative_count, last, [](int x){ return x < 0;});
    if(i != last && j != last) {
        cout << *i << " " << *j << endl;
        iter_swap(i, j);
        *i *= -1; //change sign
        *j *= -1;
    }

    StableSort01(first, first + negative_count);
    StableSort01(first + negative_count, last);
}

void Test()
{
    vector<int> vec{-1,1,3,-2,2};
    StableSort01(vec.begin(), vec.end());
    int negative_count = CountNegative(vec.begin(), vec.end());
    for(int i=0; i<negative_count; ++i)
        if(vec[i] > 0) vec[i] *= -1;
    for(int i=negative_count; i<vec.size(); ++i)
        if(vec[i] < 0) vec[i] *= -1;

    for(auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
