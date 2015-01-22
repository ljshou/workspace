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
    int i(0), j = str.find_first_of(delim);
    while(j != string::npos) {
        if(i != j) vec.push_back(atoi(str.substr(i, j-i).c_str()));
        i = j+1;
        j = str.find_first_of(delim, i);
    }
    if(i != j) vec.push_back(atoi(str.substr(i, j-i).c_str()));

    if(!vec.empty()) {
        int k = vec.size()-1;
        for(; k>=0 && vec[k] == 0; --k);
        vec.erase(vec.begin()+k+1, vec.end());
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
    assert(Compare("1", "1.0") == false);
    assert(Compare("1.1", "1.0") == false);
    assert(Compare("1.1", "1.1.2") == true);
    assert(Compare("20.1", "1.1.2") == false);
}

int main(void)
{
    Test();
    return 0;
}
