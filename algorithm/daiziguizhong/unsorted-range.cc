/**
 * @file unsorted-range.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-15
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Range {
    int left, right;
    Range(int l=0, int r=0):
        left(l), right(r) {}
};

Range UnsortedRange(const vector<int> &vec)
{
    if(vec.size() < 2) return Range();
    int left=1, right=vec.size()-2;
    for(; left<vec.size() && vec[left] >= vec[left-1]; ++left);
    if(left == vec.size()) return Range();
    for(; right>=0 && vec[right] <= vec[right+1]; --right);

    //[0, left), [left, right], (right, n-1)
    int min_val = vec[left], max_val = vec[right];
    for(int i = left; i <= right; ++ i) {
        min_val = min(min_val, vec[i]);
        max_val = max(max_val, vec[i]);
    }

    //shrink left
    while(left>0 && vec[left-1] > min_val) --left;
    //shrink right
    while(right<vec.size()-1 && vec[right+1] < max_val) ++right;

    cout << left << "\t" << right << endl;
    return Range(left, right);
}

void Test()
{
    vector<int> vec{1,2,5,6,3,4};
    UnsortedRange(vec);
}


int main(void)
{
    Test();
    return 0;
}
