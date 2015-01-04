/**
 * @file delete-chars.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-31
 */

#include <iostream>
#include <cstring>
using namespace std;

enum State {
    ONE = 0,
    TWO
};

/* delete 'b' and "ac" */
void DeleteChars(char *str)
{
    if(str == nullptr) return;
    const int n = strlen(str);
    int j(0), i(0), state = ONE;
    for(i=0;  i<n; ++i) {
        if(state == ONE) {
            if(str[i] != 'b' && str[i] != 'a')
                str[j++] = str[i];
        }
        else {
            if(str[i] != 'c') {
                str[j++] = 'a';
                if(str[i] != 'a' && str[i] != 'b') {
                    str[j++] = str[i];
                }
            }
        }
        state = (str[i] == 'a' ? TWO : ONE);
        if(j > 1 && str[j-2] == 'a' && str[j-1] == 'c') j-=2;
    }
    if(state == TWO) {
        str[j++] = 'a';
    }
    str[j] = 0;
    char *p = str;
    while(*p) {
        cout << *p << " ";
        ++p;
    }
    cout << endl;
}

int main(void)
{
    char str[] = "aacaccbz";
    DeleteChars(str);
    return 0;
}
