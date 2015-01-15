/**
 * @file convert-english-sentence.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-15
 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string Convert2String100(int num)
{
    assert(num >= 0 && num < 1000);
    string teens[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", 
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty",
        "Sixty", "Seventy", "Eighty", "Ninty"};
    string digits[] = {"One", "Two", "Three", "Four", "Five", "Six",
        "Seven", "Eight", "Nine"};

    string str;
    //deal with hundred
    if(num >= 100) {
        str += digits[num / 100 - 1] + " Hundred";
        num %= 100;
    }
    //deal with decimals
    if(num >= 11 && num <= 19) {
        return str + " " + teens[num - 11];
    }
    else if(num == 10 || num >= 20) {
        str += " " + tens[num/10 - 1];
        num %= 10;
    }
    //deal with digits
    if(num > 0 && num < 10)
        str += " " + digits[num - 1];
    return str; 
}

string Convert2String(int num)
{
    if(num == 0) return "";
    else if(num < 0) return "-" + Convert2String(-num);

    string big[] = {"", " Thousand", " Million"};

    string str;
    int count = 0;
    while(num > 0) {
        if(num % 1000 != 0) {
            str = Convert2String100(num % 1000) + big[count] + ", " + str;
        }
        num /= 1000;
        ++count;
    }
    cout << str << endl;
    return str;
}

void Test()
{
    Convert2String(23111222);
    //assert(Convert2String(123) == "One Hundred Twenty Three");
}

int main(void)
{
    Test();
    return 0;
}
