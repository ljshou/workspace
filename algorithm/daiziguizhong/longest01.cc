/**
 * @file longest01.cc
 * @brief a string consisting only of 0 and 1s.
 * return the longest sub-string which contains
 * exactly same number of 0s and 1s
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-12-30
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <cassert>
using namespace std;

struct Range
{
    int left_index;
    int right_index;
    Range(int l=0, int r=0):
        left_index(l), right_index(r) {}
};
/**
 * @brief a string consisting only of 0 and 1s.
 * @return longest sub-string which contains exactly
 * same number of 0s and 1s
 */
string Longest01(const string &str)
{
    if(str.empty()) return "";
    string res;
    vector<int> f(str.size());
    f[0] = str[0] == '0' ? -1 : 1;
    for(int i=1; i<str.size(); ++i)
        f[i] = f[i-1] + (str[i] == '0' ? -1 : 1);

    unordered_map<int, Range> ex;
    for(int i=0; i<f.size(); ++i) {
        auto it = ex.find(f[i]);
        if(it != ex.end()) {
            it->second.left_index = min(it->second.left_index, i);
            it->second.right_index = max(it->second.right_index, i);
        }
        else {
            if(f[i] == 0) {
                ex[f[i]] = Range(-1, i);
            }
            else {
                ex[f[i]] = Range(i, i);
            }
        }
    }
    int left(0), right(0);
    for(auto x : ex) {
        left = x.second.left_index;
        right = x.second.right_index;
        if(right - left > res.size())
            res = str.substr(left+1, right-left);
    }
    cout << "substr: " << res << endl;
    return res;
}

int main(void)
{
    cout << Longest01("01011") << endl;
    assert("" == Longest01(""));
    assert("" == Longest01("0"));
    assert("01" == Longest01("01"));
    assert("1010" == Longest01("11010"));
    return 0;
}
