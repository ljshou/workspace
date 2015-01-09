/**
 * @file vector-as-key.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-05
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

class Key {
    typedef vector<int>::iterator Iterator;
public:
    Key(Iterator s, Iterator t):
        begin(s), end(t) {}
    bool operator<(const Key &rhs) const {
        return lexicographical_compare(begin, end, rhs.begin, rhs.end);
    }
private:
    vector<int>::iterator begin, end;
};

void Test() 
{
    map<Key, int> m;
    vector<int> vec{1,2,3,4,5};
    assert(0 == m.size());

    m[Key(vec.begin(), vec.end())] = 0;
    assert(1 == m.size());

    m[Key(vec.begin()+1, vec.end())] = 0;
    assert(2 == m.size());

    auto vec2 = vec;
    assert(m.find(Key(vec2.begin(), vec2.end())) != m.end());
    m[Key(vec2.begin(), vec2.end())] = 0;
    assert(2 == m.size());

    m[Key(vec2.begin()+1, vec2.end())] = 0;
    assert(2 == m.size());
}

int main(void)
{
    Test();
    return 0;
}
