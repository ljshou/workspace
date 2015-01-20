/**
 * @file min-sub-array-sum.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-19
 */
#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
using namespace std;

int MinLen(const vector<int> &vec, int S)
{
    if(vec.empty()) return INT_MAX;
    int front(0), back(0);
    int sum(0), len(INT_MAX);
    for(; back<vec.size(); ++back) {
        while(front < vec.size() && sum + vec[front] <= S) {
            sum += vec[front++];
        }
        if(front < vec.size()) len = min(len, front-back+1);
        sum -= vec[back];
    }
    return len;
}

void Test()
{
    vector<int> vec{5,1,3,5,10,7,4,9,2,8};
    assert(MinLen(vec, 10) == 2);
    assert(MinLen(vec, 1) == 1);
    assert(MinLen(vec, 15) == 2);
}

int main(void)
{
    Test();
    return 0;
}
