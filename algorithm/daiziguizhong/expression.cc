/**
 * @file expression.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-20
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * 没有检查括号是否匹配
 */
int Eval(int first, int last, const string &str)
{
    if(first >= last) return 0;

    int plus = -1, sgn = 1, mul = -1, num = 0;
    int left_count = 0; //记录未匹配的坐括号
    int left = -1, right = -1;

    for(int i=first; i<last; ++i) {
        if(str[i] == '(') {
            ++left_count;
            if(left_count == 1) left = i;
        }
        else if(str[i] == ')') {
            --left_count;
            if(left_count == 0) right = i;
        }

        //not in a pair of parentness
        if(left_count == 0) {
            switch(str[i]) {
            case '+':
                plus = i;
                sgn = 1;
                break;
            case '-':
                plus = i;
                sgn = -1;
                break;
            case '*':
                mul = i;
                break;
            }
        }
        if(isdigit(str[i]))
            num = num*10 + str[i] - '0';
    }
    if(plus != -1) return Eval(first, plus, str) + sgn * Eval(plus+1, last, str);
    if(mul != -1) return Eval(first, mul, str) * Eval(mul+1, last, str);
    if(left != -1) return Eval(left+1, right+1, str); 
    return num;
}

int Eval(const string &str)
{
    return Eval(0, str.size(), str);
}

void Test()
{
    assert(Eval("") == 0);
    assert(Eval("1+2+3*5") == 18);
    assert(Eval("(1+2)+(3*5)") == 18);
    assert(Eval("(1+2+3*5)") == 18);
    assert(Eval("2*(2+3*5)") == 34);
    assert(Eval("2*((2+3)*5)") == 50);
    assert(Eval("2*((2-3)*5)") == -10);
}

int main(void)
{
    Test();
    return 0;
}
