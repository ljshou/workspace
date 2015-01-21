/**
 * @file compare-edition.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-21
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

vector<int> Split(const string &str, const char delim) 
{
    vector<int> vec;
    auto i = str.begin(), j = str.begin();
    while(j != str.end()) {
        j = find_if(i, str.end(), [&](const char c){return c == delim;});
        if(i != j)
            vec.push_back(atoi(str.substr().c_str()));
        i = j+1;
    }
    return vec;
}

bool Compare(const string &lhs, const string &rhs)
{
    auto vec1 = Split(lhs, '.');
    auto vec2 = Split(rhs, '.');
    return lexicographical_compare(vec1.begin(), vec1.end(), 
                                   vec2.begin(), vec2.end());
}

void Test()
{
    assert(Compare("1", "1.0") == true);
    assert(Compare("1.1", "1.0") == false);
    assert(Compare("1.1", "1.1.2") == true);
    assert(Compare("20.1", "1.1.2") == false);
}

int main(void)
{
    Test();
    return 0;
}
