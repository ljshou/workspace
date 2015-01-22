/**
 * @file count-majority.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-22
 */

#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

void ClearLevel(map<int, int> &hash)
{
    for(auto x : hash) {
        if(--x.second == 0)
            hash.erase(x.first);
    }
}

/**
 * return numbers that occur more then n/m times
 */
vector<int> CountMajority(const vector<int> &vec, int m)
{
    map<int, int> hash;
    for(auto x : vec) {
        ++ hash[x];
        //消去一层，类似于俄罗斯方块
        if(hash.size() == m) ClearLevel(hash);
    }

    //re-check the remaining numbers in hash
    for(auto &x : hash) { 
        x.second = 0;
    }
    for(auto x : vec) {
        ++hash[x];
    }

    vector<int> res;
    for(auto x : hash) { 
        if(x.second >= vec.size()/m)
            res.push_back(x.first);
    }
    return res;
}

void Test()
{
    vector<int> vec{4,3,3,2,1,2,3,4,4,7};
    auto res = CountMajority(vec, 5);
    for(auto x : res) 
        cout << x << " ";
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
