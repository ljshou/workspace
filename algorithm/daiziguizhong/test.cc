/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>
using namespace std;

class Key {
public:
    bool operator<(const Key &rhs) {
        return true;
    }
};

int main(void)
{
    ofstream out("test.out");
    out << "hello world" << endl;
    out.close();
    map<vector<int>, int> m;
    vector<int> a{1}, b{1,2};
    cout << (a < b) << endl;
    return 0;
}
