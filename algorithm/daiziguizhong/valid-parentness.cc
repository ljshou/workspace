/**
 * @file valid-parentness.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-19
 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool Valid(int i, int left_count, const string &str)
{
    if(i >= str.size())
        return left_count == 0;
    if(str[i] == '(') {
        ++left_count;
    }
    else if(str[i] == ')') {
        if(left_count == 0) return false;
        --left_count;
    }
    //else do nothing
    
    return Valid(i+1, left_count, str);
}

void Test()
{
    assert(true == Valid(0, 0, "()"));
    assert(false == Valid(0, 0, ")("));
    assert(false == Valid(0, 0, "(abcd(e)"));
    assert(true == Valid(0, 0, "(a)(e)"));
}

int main(void)
{
    Test();
    return 0;
}
