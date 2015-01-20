/**
 * @file itoa.cc
 * @brief integer to string
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-20
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * version 1
 * no minimum number bug
 */
string Itoa(int num, int radix = 10)
{
    string str;
    if(radix < 2 || radix > 16) return str;
    bool negative = false;
    if(radix == 10 && num < 0) negative = true;

    enum { kMaxDigits = 35};
    str.reserve(kMaxDigits); //preallocate space

    do {
        //str += abs(num % radix) + '0';
        str += "0123456789ABCDEF"[abs(num % radix)];
        num /= radix;
    }while(num != 0);
    if(negative) str += '-';

    reverse(str.begin(), str.end());
    cout << str << endl;
    return str;
}

/**
 * version 2
 * no minimum number bug
 */
string Itoa2(int num, int radix = 10)
{
    string str;
    if(radix < 2 || radix > 16) return str;
    bool negative = false;
    if(radix == 10 && num < 0) negative = true;

    enum { kMaxDigits = 35};
    str.reserve(kMaxDigits); //preallocate space

    do {
        str += "FEDCBA9876543210123456789ABCDEF"[15 + num % radix];
        num /= radix;
    }while(num != 0);
    if(negative) str += '-';

    reverse(str.begin(), str.end());
    cout << str << endl;
    return str;
}

void Test()
{
    assert(Itoa(0, 10) == "0");
    assert(Itoa(-0, 10) == "0");
    assert(Itoa(123,10) == "123");
    assert(Itoa(1230, 10) == "1230");
    assert(Itoa(-1230, 10) == "-1230");
    assert(Itoa(INT_MIN, 10) == "-2147483648");

    assert(Itoa2(0, 10) == "0");
    assert(Itoa2(-0, 10) == "0");
    assert(Itoa2(123,10) == "123");
    assert(Itoa2(1230, 10) == "1230");
    assert(Itoa2(-1230, 10) == "-1230");
    assert(Itoa2(INT_MIN, 10) == "-2147483648");
}

int main(void)
{
    Test();
    return 0;
}
