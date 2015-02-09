/**
 * @file is-lucky.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-30
 */

#include <iostream>
#include <cassert>
using namespace std;

bool isLucky(int n)
{
    assert(n > 0);
    int count = 2;
    int next_position = n;
    while(count <= next_position) {
        if(next_position % count == 0)
            return false;
        next_position -= next_position / count;
        ++ count;
    }
    return true;
}

void Test()
{
    for(int i=1; i<20; ++i)
        if(isLucky(i)) 
            cout << i << " ";
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
