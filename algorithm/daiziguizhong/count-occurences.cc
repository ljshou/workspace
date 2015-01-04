/**
 * @file count-occurences.cc
 * @brief count the occurences of numbers
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-31
 */

#include <iostream>
#include <vector>
using namespace std;

void Count(vector<int> & vec)
{
    const int n = vec.size();
    if(n == 0) return;
    for(auto& x : vec)
        x *= n;
    for(auto x : vec) {
        ++ vec[x/n - 1];
    }
    for(auto x : vec) {
        cout << x % n << " ";
    }
    cout << endl;
}

int main(void)
{
    vector<int> vec{2,2,1,4};
    Count(vec);
    return 0;
}
