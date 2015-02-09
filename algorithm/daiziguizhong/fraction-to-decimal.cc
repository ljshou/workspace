/**
 * @file fraction-to-decimal.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-04
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int n, int d)
{
    long long numerator = n, denominator = d;
    string res;
    if(numerator == 0) return "0";
    if(numerator * denominator < 0) 
        res += "-";
    numerator = abs(numerator);
    denominator = abs(denominator);

    long long remainder = 0;
    res += to_string(numerator / denominator);
    remainder = numerator % denominator;
    if(remainder == 0) return res;

    res += ".";

    unordered_map<int, int> hash;
    int i = res.size();
    while(remainder) {
        if(hash.find(remainder) != hash.end()) break;
        hash[remainder] = i ++;
        res += to_string(remainder * 10 / denominator);
        remainder = remainder * 10 % denominator;
    }
    if(remainder != 0) {
        res.insert(res.begin()+hash[remainder], '(');
        res.push_back(')');
    }
    return res;
}

int main(void)
{
    cout << fractionToDecimal(-1, INT_MIN) << endl;
    return 0;
}
