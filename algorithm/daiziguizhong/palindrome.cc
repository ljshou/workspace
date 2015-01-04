/**
 * @file palindrome.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-31
 */

#include <iostream>
#include <string>
using namespace std;

int Length(int i, int j, const string &str)
{
    while(i >=0 && j < str.size() && str[i] == str[j]) {
        --i, ++j;
    }
    return j - i - 1;
}

int Palindrome(const string &str) 
{
    if(str.empty()) return 0;
    int len(0);
    for(int i=0; i<str.size()-1; ++i) {
        len = max(len, Length(i, i+1, str));
        len = max(len, Length(i, i, str));
    }
    return len;
}

int main(void)
{
    cout << Palindrome("abcbae") << endl;
    return 0;
}
