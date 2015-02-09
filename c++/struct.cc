/**
 * @file struct.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-21
 */

#include <iostream>
using namespace std;

struct A{
    char c;
    char *p;
};

int main(void)
{
    cout << sizeof(A) << endl;
    return 0;
}
