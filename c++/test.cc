/**
 * @file test.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.com
 * @version 0.1.00
 * @date 2014-12-12
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void)
{
    multimap<int, int> hash;
    hash.insert(make_pair(1, 2));
    hash.insert(make_pair(1, 1));
    for(auto p : hash) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
