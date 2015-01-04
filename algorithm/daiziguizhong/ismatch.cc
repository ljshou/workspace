/**
 * @file ismatch.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-31
 */


#include <iostream>
#include <stack>
#include <string>
#include <cassert>
using namespace std;

void helper(string::const_iterator begin, string::const_iterator end, stack<char> & s)
{
    if(begin == end) return;
    if(*begin == '(') {
        s.push('(');
    }
    else if(*begin == ')') {
        if(s.empty()) {
            s.push(')');
            return;
        }
        s.pop();
    }
    helper(begin+1, end, s);
}

bool IsMatch(const string &str)
{
    stack<char> s;
    helper(str.begin(), str.end(), s);
    return s.empty();
}

int main(void)
{
    assert(IsMatch("()") == true);
    assert(IsMatch(")(") == false);
    assert(IsMatch("(abcd(e)") == false);
    assert(IsMatch("(a)(b)") == true);
    return 0;
}
