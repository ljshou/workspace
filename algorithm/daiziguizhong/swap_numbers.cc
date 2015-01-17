/**
 * @file swap_numbers.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-16
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void Swap(int i, int j, vector<int> &vec)
{
    assert(!vec.empty());
    assert(i >= 0 && i < vec.size());
    assert(j >= 0 && j < vec.size());
    if(i == j) return;

    if(vec[i] == 0 || vec[j] == 0) {
        cout << "swap " << vec[i] << ", " << vec[j] << endl;
    }
    else {
        cout << "swap " << 0 << ", " << vec[j] << endl;
        cout << "swap " << 0 << ", " << vec[i] << endl;
        cout << "swap " << 0 << ", " << vec[j] << endl;
    }
    swap(vec[i], vec[j]);
}

void SwapVecs(vector<int> &src, vector<int> &dest)
{
    if(src.empty()) return;
    int hash[dest.size()];
    for(int i=0; i<dest.size(); ++i) {
        hash[dest[i]] = i;
    }

    for(int i=0; i<src.size(); ++i) {
        while(hash[src[i]] != i) {
            Swap(i, hash[src[i]], src);
        }
    }
}

void Test()
{
    vector<int> src{0,1,2,3}, dest{3,0,2,1};
    SwapVecs(src, dest);
}

int main(void)
{
    Test();
    return 0;
}
