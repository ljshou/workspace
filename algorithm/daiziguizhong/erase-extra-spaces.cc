/**
 * @file erase-extra-spaces.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-09
 */

#include <iostream>
#include <string>
using namespace std;

void Remove(string &str)
{
    if(str.empty()) return;
    int trail = str.size();
    while(trail > 0 && str[trail - 1 ] == ' ') --trail;
    if(trail == 0) {
        str = "";
        return;
    }
    int pnt = 0;
    for(int i=0; i<trail; ++i) {
        if(str[i] != ' ' || (pnt && str[pnt-1] != ' '))
            str[pnt++] = str[i];
    }
    str.erase(str.begin()+pnt, str.end());
}

int main(void)
{
    string str("   I   am a boy       .  ");
    Remove(str);
    cout << str << endl;
    return 0;
}
