/**
 * @file partition.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-04
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cassert>
using namespace std;

bool Partition(const string &str, const unordered_set<string> &s)
{
    if(str.empty()) return true;
    vector<int> f(str.size()+1, false);
    f[0] = true;
    for(int i=1; i<=str.size(); ++i) {
        for(int j=i-1; j>=0; --j) {
            if(f[j] && s.find(str.substr(j, i-j)) != s.end()) {
                f[i] = true;
                break;
            }
        }
    }
    return f[str.size()];
}

int main(void)
{
    unordered_set<string> s{"hello", "world"};
    assert(true == Partition("hellohelloworld", s));
    return 0;
}
