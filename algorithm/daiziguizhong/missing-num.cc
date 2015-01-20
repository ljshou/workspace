/**
 * @file missing-num.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-31
 */

#include <iostream>
#include <vector>
using namespace std;

int MissingNumer(vector<int> &vec)
{
    if(vec.empty()) return 1;
    for(int i=0; i<vec.size(); ++i) {
        while(vec[i] > 0 && vec[i] <= vec.size()) {
            if(vec[i] == i+1) break;
            if(vec[i] == vec[vec[i]-1]) break; // in case of swaping infinitely
            swap(vec[i], vec[vec[i]-1]);
        }
    }
    for(int i=0; i<vec.size(); ++i) {
        if(vec[i] != i+1) 
            return i+1;
    }
    return vec.size() + 1;
}

int main(void)
{
    vector<int> vec{3,4,3,1};
    cout << MissingNumer(vec) << endl;
    return 0;
}
