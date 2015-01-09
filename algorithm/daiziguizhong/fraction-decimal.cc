/**
 * @file fraction-decimal.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-07
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

string fractionToDecimal(int x,  int   y) {
    string res;
    if(y == 0) return res;

    //deal with negative number
    if(x * y < 0) res += '-';
    x = abs(x), y = abs(y);

    res += ('0' + x / y); 
    if(x % y == 0) return res;
    x %= y; x *= 10;
    res += ".";

    string str;
    unordered_map<int, int> hash;
    int i(0);
    while(x % y != 0) {
        auto it = hash.find(x);
        if(it != hash.end()) {
            str.insert(it->second + str.begin(), '(');
            str.insert(str.end(), ')');
            break;
        }
        hash[x] = i++;
        str += '0' + x / y;
        x %= y; x *= 10;
    }
    if(x % y == 0) 
        str += '0' + x / y;
    //cout << res + str << endl;
    return res + str; 
}

void Test()
{
    assert("3" == fractionToDecimal(3,1));
    assert("0.1" == fractionToDecimal(1,10));
    assert("-0.1" == fractionToDecimal(1,-10));
    assert("0.(3)" == fractionToDecimal(1,3));
    assert("0.(6)" == fractionToDecimal(2,3));
    assert("0.(6)" == fractionToDecimal(2,3));
    assert("0.(142857)" == fractionToDecimal(1,7));
    assert("0.(003)" == fractionToDecimal(1,333));
}

int main(void)
{
    Test();
    return 0;
}
