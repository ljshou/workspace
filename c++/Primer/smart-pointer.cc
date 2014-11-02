/**
 * @file smart-pointer.cc
 * @brief test file for smart-pointer class 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-18
 */
#include "smart-pointer.h"
#include <iostream>
using namespace std;

int main(void)
{
    int *pInt = new int(10);
    HasPtr object(pInt);    
    cout << *object << endl;

    const HasPtr object2(object);
    cout << *object2 << endl;

    HasPtr object3 = object;
    *object3 = 3;
    cout << *object3 << endl;

    return 0;
}
